#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	vector<int> v1 = { 40, 30, 25, 35, 15 };
	vector<int>::iterator pos;
	is_heap(v1.begin(),v1.end())
    ? cout<<"the vector is a heap"
    : cout<<"the vector isn't a heap";
    cout<<endl;

    auto it=is_heap_until(v1.begin(),v1.end());
    cout<<"the heap element in the vector are:"<<endl;
    for(pos=v1.begin(); pos!=it; pos++)
        cout<<*pos<<endl;
	return 0;
}

