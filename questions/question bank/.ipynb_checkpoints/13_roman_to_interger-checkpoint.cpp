#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int roman_to_int(string s){
    unordered_map<char, int> value{
        { 'I', 1 },
		{ 'V', 5 },
		{ 'X', 10 },
		{ 'L', 50 },
		{ 'C', 100 },
		{ 'D', 500 },
		{ 'M', 1000 },
    };
    int sum = value[s.back()];
    for(int i = s.length()-2; i>=0; i--){
        if( value[s[i]] < value[s[i+1]] ){
            sum-=value[s[i]];
        }
        else
            sum+=value[s[i]];
    }
    return sum;
}

int main(){
    string st;
    while(cin >> st && st != "0"){
        cout << roman_to_int(st) << endl;
    }
}