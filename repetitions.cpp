#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin >> s;
    int i = 1;
    int n = s.size();
    int len = 1;
    int maxLen = 0;
    while (i < n)
    {
        if(s[i] != s[i-1]){
            maxLen = max(len, maxLen);
            len = 1;
        }
        else{
            len += 1;
        }
        i++;
    }
    maxLen = max(len, maxLen);
    cout<<maxLen<<endl;
    return 0;
}