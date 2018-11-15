//
// Created by untouch on 18-11-14.
//
#include <iostream>
#include <memory>

//时间: O(n*n)
//空间: O(n*n)
int FindMaxSubString(const std::string& string1, const std::string& string2){
    int retNumber = 0;
    if(string1.empty() or string2.empty())
        return retNumber;
    int dp[string1.size()][string2.size()] = {0};
    for(int i = 0; i < string1.size(); ++i) {
        dp[i][0] = string1.at(i) == string2.at(0) ? 1 : 0;
        retNumber = dp[i][0] > retNumber ? dp[i][0] : retNumber;
    }

    for(int j = 0; j < string2.size(); ++j) {
        dp[0][j] = string2.at(j) == string1.at(0) ? 1 : 0;
        retNumber = dp[0][j] > retNumber ? dp[j][0] : retNumber;
    }

    for(int i = 1; i < string1.size(); ++i){
        for(int j = 1; j < string2.size(); ++j){
            dp[i][j] = string1.at(i) == string2.at(j) ? dp[i-1][j-1] + 1 : 0;
            retNumber = dp[i][j] > retNumber ? dp[i][j] : retNumber;
        }
    }
#define DEBUG
#if defined(DEBUG)
    std::cout << "   ";
    for(int i = 0; i < string2.size(); ++i)
        std::cout << string2.at(i) << "  ";
    std::cout <<std::endl;
    for(int i = 0; i < string1.size(); ++i){
        std::cout << string1.at(i)<<"  ";
        for (int j = 0; j < string2.size(); ++j) {
            std::cout << dp[i][j] << "  ";
        }
        std::cout << std::endl;
    }
#endif

    return retNumber;
}

//时间： O(n*n)
//空间： O(n)
int FindMaxSubStringPlus(const std::string& string1, const std::string& string2){
    int retNumber = 0;
    if(string1.empty() or string2.empty())
        return retNumber;
    int dp[string2.size()] = {0};

    for(int j = 0; j < string2.size(); ++j) {
        dp[j] = string1.at(0) == string2.at(j) ? 1 : 0;
        retNumber = dp[j] > retNumber ? dp[j] : retNumber;
    }

#if defined(DEBUG)
    std::cout << "   ";
    for(int i = 0; i < string2.size(); ++i)
        std::cout << string2.at(i) << "  ";
    std::cout <<std::endl;
    std::cout << string1.at(0) << "  ";
    for(int j = 0; j < string2.size(); ++j)
        std::cout << dp[j] <<"  ";
    std::cout << std::endl;
#endif

    for(int i = 1; i < string1.size(); ++i){
        for(int j = string2.size()-1; j >-1; --j){
            if(0 == j){
                dp[0] = string1.at(i) == string2.at(0) ? 1 : 0;
                retNumber = dp[j] > retNumber ? dp[j] : retNumber;
                continue;
            }
            dp[j] = string1.at(i) == string2.at(j) ? dp[j-1] + 1 : 0;
            retNumber = dp[j] > retNumber ? dp[j] : retNumber;
        }
#if defined(DEBUG)
        std::cout << string1.at(i) << "  ";
        for (int j = 0; j < string2.size(); ++j)
            std::cout << dp[j] << "  ";
        std::cout << std::endl;
#endif
    }

    return retNumber;
}
int main(void){
    std::string string1 = "zhangyoucai@untouch-tech.com";
    std::string string2 = "zhanhe@untouch-tech.com";

    std::cout << FindMaxSubString(string1,string2) << std::endl;
    std::cout << FindMaxSubStringPlus(string1,string2) << std::endl;
    return 0;
}