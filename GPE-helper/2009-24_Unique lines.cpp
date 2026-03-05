//note
//善用set的去重性
#include<bits/stdc++.h>
using namespace std;
struct Point{
    int x,y;
};
int gcd(int a, int b){
    return (b==0) ? a : gcd(b,a%b) ;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int num;
        cin>>num;
        vector<Point> points;
        for(int i=0; i<num; i++){
            int a,b;
            cin>>a>>b;
            Point tmp;
            tmp.x=a;
            tmp.y=b;
            points.push_back(tmp);
        }
        //ax+by+c=0
        set<tuple<int,int,int>> lines;
        for(int i=0; i<num; i++){
            for(int j=i+1; j<num; j++){ //two point index i,j
                int a=points[i].y-points[j].y;
                int b=points[j].x-points[i].x;
                int c=-(a*points[i].x + b*points[i].y);
                //確保唯一性:a b c要是最簡整數比、第一個非零係數要是正的
                int g=gcd(abs(a),gcd(abs(b),abs(c)));
                a/=g; b/=g; c/=g;
                if((a<0)||(a==0 && b<0)||(a==0 && b==0 && c<0)){ //第一個非零係數要是負的
                    a=-a; b=-b; c=-c;
                }
                lines.insert({a,b,c}); //set有去重性
            }
        }
        cout<<lines.size()<<endl;
    }   
    return 0;
}