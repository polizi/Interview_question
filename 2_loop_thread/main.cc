//
// Created by zhangyc on 18-11-15.
//
#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

const int TIMES = 50;
static std::mutex s_mutex;
static std::condition_variable s_cv;
static bool flag = true;

void RunChiled(){
    for(int i = 0; i < TIMES; ++i){
        std::unique_lock<std::mutex> unique_lock(s_mutex);
        s_cv.wait(unique_lock, [](){return flag;});
        for(int j =0; j < 10; j++){
            std::cout  << "Chiled Times : " << i << "  Chiled index : " << j << std::endl;
        }
        flag = !flag;
        s_cv.notify_one();
    }
}

int main(void){
    std::thread thread1 = std::thread(RunChiled);
    thread1.detach();

    for(int i = 0; i < TIMES; ++i){
        std::unique_lock<std::mutex>unique_lock(s_mutex);
        s_cv.wait(unique_lock,[](){ return !flag;});
        for (int j = 0; j <100 ; ++j) {
            std::cout <<"Father Times : " << i << "  Father index : " << j << std::endl;
        }
        flag = !flag;
        s_cv.notify_one();
    }

    return 0;
}