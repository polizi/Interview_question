//
// Created by zhangyc on 18-11-14.
//

//时间: O(N)
//空间: O(N)

#include <iostream>
#include <vector>
#include <unordered_map>

std::vector<int> TwoSum(std::vector<int>& nums, int target) {
    std::vector<int> result;
    std::unordered_map<int, int> map;
    for(int i = 0; i < nums.size(); ++i){
        auto got = map.find(target-nums[i]);
        if(got != map.end())
        {
            result.push_back(got->second);
            result.push_back(i);
            return result;
        }
        map[nums[i]] = i;
    }
    return result;
}

int main(void){
    std::vector<int>nums;
    nums.push_back(2);
    nums.push_back(7);
    nums.push_back(11);
    nums.push_back(15);
    nums.push_back(12);
    nums.push_back(1115);
    nums.push_back(102);
    nums.push_back(187);
    nums.push_back(10);
    nums.push_back(41);

    auto res = TwoSum(nums,197);
    for (int i = 0; i < res.size(); ++i) {
        std::cout << res[i] <<std::endl;

    }

    std::unordered_map<std::string,int> mymap = {
            { "Mars", 3000},
            { "Saturn", 60000},
            { "Jupiter", 70000 } };


    mymap.at("Mars") = 3396;
    mymap.at("Saturn") += 272;
    mymap.at("Jupiter") = mymap.at("Saturn") + 9638;

    for (auto it = mymap.begin(); mymap.end() != it; ++it )
        std::cout << " " << it->first << ":" << it->second;
    std::cout << mymap.max_bucket_count() << std::endl;
    std::unordered_map<std::string,double>
            myrecipe,
            mypantry = {{"milk",2.0},{"flour",1.5}};

    std::pair<std::string,double> myshopping ("baking powder",0.3);

    myrecipe.insert (myshopping);                        // copy insertion
    myrecipe.insert (std::make_pair<std::string,double>("eggs",6.0)); // move insertion
    myrecipe.insert (mypantry.begin(), mypantry.end());  // range insertion
    myrecipe.insert ( {{"sugar",0.8},{"salt",0.1}} );    // initializer list insertion

}

