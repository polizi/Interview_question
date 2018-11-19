//
// Created by untouch on 18-11-17.
//
#include <iostream>
#include <string>


std::string LongestPalindrome(const std::string& s) {
    if(s.size() < 2)
        return s;
    int start = 0;
    int end = 0;
    std::string ret = s.substr(0,1);

    for(int i = 0; i < s.size()-1; ++i){
        if(s[i] == s[i+1]){
            ret = ret.size() < 2 ? s.substr(i,2) : ret;
            start = i-1;
            end = i+2;
            while(start >= 0 && end < s.size() && s[start--] == s[end++]){
                if(ret.size() < (end -start - 1))
                    ret = s.substr(start+1, end-start-1);
            }
        }
        start = i-1;
        end = i+1;
        while(start >= 0 && end < s.size() && s[start--] == s[end++]){
            if(ret.size() < (end -start - 1))
                ret = s.substr(start+1, end-start-1);
        }

    }

    return ret;
}

int main() {
    std::string str = "zhangnahz";
    std::cout << LongestPalindrome(str) <<std::endl;

    return 0;
}
