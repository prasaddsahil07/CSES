#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    // int binToDec(string& s) {
    //     int num = 0;
    //     for(auto c: s){
    //         num = num*2+(c-'0'); 
    //     }
    //     return num;
    // }

    // string decToBin(int num, int len) {
    //     string res = "";
    //     while(num > 0){
    //         res = char('0'+(num%2))+res;
    //         num /= 2;
    //     }
    //     while(res.size() < len){
    //         res = '0'+res;
    //     }
    //     return res;
    // }

public:
    vector<string> grayCode(int n) {
        if(n == 1){
            return {"0", "1"};
        }
        vector<string> child = grayCode(n-1);
        vector<string> ans;
        for(auto c: child){
            // string bin = decToBin(c, n-1);
            // string numStr = '0' + bin;
            // int dec = binToDec(numStr);
            ans.push_back('0'+c);
        }
        reverse(child.begin(), child.end());
        for(auto c: child){
            // string bin = decToBin(c, n-1);
            // string numStr = '1' + bin;
            // int dec = binToDec(numStr);
            ans.push_back('1'+c);
        }
        return ans;
    }
};

int main(){
    int n;
    cin>>n;
    Solution s;
    vector<string> res = s.grayCode(n);
    for(auto& r: res)   cout<<r<<" ";
    return 0;
}