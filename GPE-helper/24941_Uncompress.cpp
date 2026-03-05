// Uva 245
// list is doubly link list so it can perform "erasing element" and "push_front" in O(1)
// but need to it++ O(n)
// vector can also be used in this question but list is more intuitive
#include<bits/stdc++.h>
using namespace std;
list<string> words;
int main(){
    char ch;
    while(cin.get(ch) && ch!='0'){ //cin可以用來移動游標
        //case 1
        if(isalpha(ch)){
            string word="";
            while(isalpha(ch)){
                word+=ch;
                cin.get(ch);
            }
            cin.putback(ch);
            cout<<word;
            words.push_front(word);
        }
        //case 2
        else if(isdigit(ch)){
            int num=0;
            while(isdigit(ch)){
                num=num*10+(ch-'0');
                cin.get(ch);
            }
            cin.putback(ch);
            //find word
            //list 不支援 list[i] 存取
            auto it = words.begin();
            for(int i=0; i<num-1; i++) it++;
            string target = *it;
            cout<<target;
            //move target to the first position
            words.erase(it);
            words.push_front(target);
        }
        //case 3
        else{
            cout<<ch;
        }
    }
    return 0;
}