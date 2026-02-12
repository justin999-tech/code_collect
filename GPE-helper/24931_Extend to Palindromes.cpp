// #find longest Palindromic Suffix using kmp next array
//Uva 11475
#include<bits/stdc++.h>
using namespace std;
string reverse(string& s){
    string ans; //目前是空字串
    for(int i=s.size()-1; i>=0; i--){
        ans.push_back(s[i]);
    }
    return ans;
}
vector<int> kmp_next(string s) {
    vector<int> next(s.size(), 0);
    int left = 0;
    for (int right = 1; right < s.size(); right++) {
        while (left > 0 && s[left] != s[right]) {
            left = next[left - 1];
        }
        if (s[left] == s[right]) {
            left++;
        }
        next[right] = left;
    }
    return next;
}
int main(){
    string s;
    while(cin>>s){
        string res;
        string s_rev = reverse(s);
        string T = s_rev + '#' + s;
        //find kmp_next[T.size()-1]
        vector<int> next = kmp_next(T);
        string prefix_not_palindromic;
        for(int i=0; i<s.size()-next.back(); i++){
            prefix_not_palindromic.push_back(s[i]);
        }
        string rev = reverse(prefix_not_palindromic);
        res = s+rev;
        cout<<res<<endl;
    }
    return 0;
}