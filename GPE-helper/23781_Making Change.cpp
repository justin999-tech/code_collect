#include<bits/stdc++.h>
using namespace std;
#define max_val 700 //找零最多195分錢，加上價格最多500分，開到700足夠了
#define INF 1e9
int coins[]={5,10,20,50,100,200};
int main(){
    //preprocessing : client's refund -> complete Knapsack(每種幣值有無限個)
    //shop[i] : i最少由shop[i]個硬幣所組成
    vector<int> shop(max_val+1,INF);
    shop[0]=0;
    for(int c : coins){
        for(int i=c; i<=max_val; i++){ // 因為每個幣值有無限個所以可以從小加到大
            if(shop[i-c]!=INF)
                shop[i]=min(shop[i],shop[i-c]+1);
        }
    }
    //處理輸入並轉成"分錢"
    int count[6];
    double price_in;
    while(cin>>count[0]>>count[1]>>count[2]>>count[3]>>count[4]>>count[5]){
        if(count[0]+count[1]+count[2]+count[3]+count[4]+count[5]==0) break;
        cin>>price_in;
        //因為電腦儲存double一般不會剛好而是很接近EX:0.95->0.94999999
        //並且轉成int的時候電腦會無條件捨去，所以會變成94，+0.5是一種絕妙四捨五入的方法
        int price = (int)(price_in*100+0.5);
        //preprocessing customer's pay -> 0/1 knapsack(每種幣值有有限個)
        vector<int> user(max_val+1,INF);
        user[0]=0;
        for(int i=0; i<6; i++){
            int val=coins[i];
            int num=count[i];
            for(int j=0; j<num; j++){
                for(int k=max_val; k>=val; k--){ //一定要用減的
                    if(user[k-val]!=INF)
                        user[k]=min(user[k],user[k-val]+1);
                }

            }
        }
        //從price開始往上看看會有多少個
        int min_coins = INF;
        for(int i=price; i<=max_val; i++){
            if(user[i]!=INF && shop[i-price]!=INF)
                min_coins=min(min_coins,user[i]+shop[i-price]);
        }
        printf("%3d\n",min_coins);
        
    }
    return 0;
}