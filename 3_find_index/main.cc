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
}
