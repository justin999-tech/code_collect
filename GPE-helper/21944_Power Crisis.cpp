/*
Uva 151
#約瑟夫斯問題(Josephus Problem)
這個問題起源於歷史學家弗拉維奧·約瑟夫斯（Flavius Josephus）。
傳說他和 40 個戰友被羅馬軍隊包圍，他們決定自殺也不願被俘。
大家圍成一個圓圈，從 1 號開始報數，每數到第m個人，那個人就必須自殺，
然後從下一位重新開始報數，直到只剩下最後一個人。約瑟夫斯為了活下來，
快速計算出了最後一個人的位置，並成功躲過了死劫。

問題模型 : n個人圍一圈(編號:0~n-1),每m人淘汰，定義f(n,m)為最後生存下來的人的編號，且f(1,m)=0;
core formula : f(n,m) = ( f(n-1,m) + m ) mod n
EX:f(5,3)淘汰順序2 -> 0 -> 4 -> 1 所以 f(5,3)=3

題型等價 : 此題第一個地區強制先停電所以先去掉，把剩下的編號 2~n 區域平移到 0~n-2 (0-based) , 13->11
*/
#include<bits/stdc++.h>
using namespace std;
int f(int n, int m){
    int current_value = 0; // Firstly set current_value to be f(1,m) which is 0
    // bottom-up method to calculate f(n,m)
    for(int i=2; i<=n; i++){
        current_value = (current_value + m) % i ; // i.e f(i,m)=(f(i-1,m)+m)%i
    }
    return current_value;
}
int main(){
    int n;
    while(cin>>n && n!=0){
        auto start = std::chrono::high_resolution_clock::now();
        // 1 號區域已經先停電了，所以我們處理剩下的 N-1 個區域
        // 我們的目標是讓原本的 13 號區域成為最後一個
        // 原本編號：1, 2, 3, ..., 13, ..., N
        // 移除 1 後：2, 3, ..., 13, ..., N (總數 N-1)
        // 重新編號：0, 1, ..., 11, ..., N-2
        // 所以目標 index 是 11
        n--; 
        int m=1;
        while(true){ //m有可能比n大，沒有特定範圍所以不能用for-loop
            if(f(n,m)==11){
                cout<<m<<endl;
                break;
            }   
            m++;
        }
    auto finish = std::chrono::high_resolution_clock::now();
    printf("Elapsed time in milliseconds: %ld ms\n", std::chrono::duration_cast<std::chrono::milliseconds>(finish-start).count());
    }
    return 0;
}
/*
事實上用Naive approach也會 0ms AC !!
#include <iostream>
#include <vector>

using namespace std;

// 模擬停電過程的函數
int simulate(int n, int m) {
    vector<int> regions;
    for (int i = 1; i <= n; i++) {
        regions.push_back(i);
    }

    // 1. 第一個永遠是區域 1 停電
    regions.erase(regions.begin());

    // 目前指標位置（因為 1 號被刪了，現在 index 0 指向的是原本的 2 號）
    int current_pos = 0;

    // 2. 持續移除區域，直到剩下最後一個
    while (regions.size() > 1) {
        // 計算下一個停電的 index
        // 因為是從「當前位置」開始數 m 個，且包含自己，
        // 所以實際上要往後跳 m-1 步
        current_pos = (current_pos + m - 1) % regions.size();
        
        // 移除該區域
        regions.erase(regions.begin() + current_pos);
    }

    // 返回最後剩下的區域編號
    return regions[0];
}

int main() {
    int N;
    while (cin >> N && N != 0) {
        for (int m = 1; ; m++) {
            if (simulate(N, m) == 13) {
                cout << m << endl;
                break;
            }
        }
    }
    return 0;
}
*/