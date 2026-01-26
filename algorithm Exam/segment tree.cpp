#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> A, ST;

//the node value is the sum of its children.

void build(int node, int l,int r){
    //leaf node
    if (l==r){
    ST[node]=A[l];
    return;
    }

    //recursively traverse
    int mid=(l+r)/2;
    build(2*node, l, mid);
    build(2*node+1, mid+1, r);

    //sum
    ST[node]=ST[2*node]+ST[2*node+1];
}

//update the A[idx] by val and reconstruct the segment tree.

void update(int node, int l, int r, int idx, int val){

    //Generally speaking, the node is 1, and we should traval down the tree 
    //through either left node or right node
    if(l==r){
        A[idx] += val;
        ST[node] += val;
        return;
    }

    int mid=(l+r)/2;

    if(l<=idx && idx<=mid)
        update(2*node, l, mid, idx, val);
    else
        update(2*node+1, mid+1, r, idx, val);

    ST[node]=  ST[2*node] + ST[2*node+1];

}

int query(int node , int tl , int tr , int l , int r){
    //if it lies out of range, return 0
    if(r < tl || tr < l){
        return 0;
    }

    //if the node contains the range
    if(l <= tl && tr <= r){
        return ST[node];
    }

    int tm = (tl + tr)/2;

    return query(2*node, tl, tm, l, r) + query(2*node+1, tm+1, tr, l, r);
}

//driver  code
int main(){
    int n = 6;
    A = { 0, 1, 3, 5, -2, 3 };

    
    // Create a segment tree of size 4*n
    ST.resize(4 * n);

    // Build a segment tree
    build(1, 0, n - 1);
    cout << "Sum of values in range 0-4 are: "
         << query(1, 0, n - 1, 0, 4) << "\n";

    // Update the value at idx = 1 by
    // 100 thus becoming 101
    update(1, 0, n - 1, 1, 100);
    cout << "Value at index 1 increased by 100\n";
    cout << "sum of value in range 1-3 are: "
         << query(1, 0, n - 1, 1, 3) << "\n";

    return 0;
}