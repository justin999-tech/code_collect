#include <iostream>
#include <cassert>  //assert()
using namespace std;

class SinglyLinkList{
private:
    struct Node{
        int val;
        Node *next;
        Node(int v) : val(v) , next(nullptr){}
    };

    Node *head;
    Node *tail;
    size_t length;

    Node* getNode(size_t index)const{
        if(index>=length)
            return nullptr;
        Node* cur=head;
        for(int i=0; i<index; ++i)
            cur=cur->next;
        return cur;
    }

public:
    SinglyLinkList():head(nullptr),tail(nullptr),length(0){}

    //prohibit shallow copy 
    SinglyLinkList(const SinglyLinkList&) = delete; //delete is "prohibition"
    /*
        ❌
        SinglyLinkList a;
        SinglyLinkList b = a; 
    */
    SinglyLinkList& operator=(const SinglyLinkList&) = delete;
    /*
        ❌
        SinglyLinkList a;
        b = a; 
    */
    /*  💭不能上面一下禁止拷貝，這邊又拷貝(只能擇一)
        SinglyLinkList(const SinglyLinkList& other){    //deep copy
        head = tail = nullptr;
        length = 0;
        Node* cur = other.head;
        while(cur){
            push_back(cur->val);
            cur = cur->next;
        }
    }
    */
    ~SinglyLinkList(){
        Node* cur = head;
        while(cur){
            Node* nxt = cur->next;
            delete cur;
            cur = nxt;
        }
    }

    size_t size() const {return length;}
    bool empty() const {return length == 0;}

    //尾端加入
    void push_back(int val){
        Node* n = new Node(val);
        if(!head)
            head=tail=n;
        else{
            tail->next=n;
            tail=n;
        }
        ++length;
    }

    //頭端加入
    void push_front(int val){
        Node* n=new Node(val);
        if(!head)
            head=tail=n;
        else{
            n->next=head;
            head=n;
            if(!tail)tail=n;
        }
        ++length;
    }

    //尾端移除
    int pop_back(){
    int removal;
    /*
    the reason why we use removedVal as parameter:
        int x;
        list.pop_back(x);
        cout<<"刪掉的值是:"<< x << endl;
    */
    if(!head)
        throw std::runtime_error("This Link-List is already empty !");
    if(length==1){
        removal = head->val;
        delete head;
        head = tail = nullptr;
        length = 0;
        return removal;
    }

    //走到倒數第2個
    Node* prev = head;
    while(prev->next!=tail)
        prev=prev->next;
    removal=tail->val;
    delete tail;
    tail=prev;
    tail->next=nullptr;
    --length;
    return removal; 
    }

    //頭端移除
    int pop_front(){
        int removal;
        if(!head)
            throw std::runtime_error("This Link-List is already empty !");
        if(length==1){
        removal = head->val;
        delete head;
        head = tail = nullptr;
        length = 0;
        return removal;
        }

        Node* oldhead = head;
        removal=oldhead->val;
        head=head->next;
        delete oldhead;
        --length;
        return removal; 
    }

    //取得index的值
    int get(size_t index)const{
        Node* n=getNode(index);
        if(!n)
            throw std::out_of_range("Index is out of range !");
        return n->val;
    }

    //改變index的值，用bool檢查是否成功
    bool set(size_t index,int val){
       Node* n=getNode(index);
       if(!n)   return false;
       n->val=val;
       return true;
    }

    //在index位置插入，後面平移，用bool檢查是否成功
    bool insert(size_t index, int val){
        if(index>length) return false;
        if(index==0){push_front(val); return true;}
        if(index==length){push_back(val); return true;}
        Node* prev=getNode(index-1);
        Node* insert_node= new Node(val);
        insert_node->next=prev->next;
        prev->next=insert_node;
        ++length;
        return true;
    }

    //移除index位置，用bool檢查是否成功
    bool remove(size_t index){
        if(index>=length) return false;
        if(index==0){pop_front(); return true;}
        if(index==length-1){pop_back(); return true;}
        Node* prev=getNode(index-1);
        assert(prev&&prev->next);
        Node* target_node= prev->next;
        prev->next=target_node->next;
        delete target_node;
        --length;
        return true;
    }

    //走訪
    void traverse()const{
        const Node* cur=head;
        cout<<"[";
        while(cur){
            cout<<cur->val;
            if(cur->next)
                cout<<"->";
            cur=cur->next;
        }
        cout<<"] (size="<<length<<")\n";
    }

};


int main() {
    SinglyLinkList list;

    cout << "== 建立與 push_back / push_front ==\n";
    list.push_back(10);   // [10]
    list.push_back(20);   // [10->20]
    list.push_front(5);   // [5->10->20]
    list.traverse();

    cout << "\n== insert 測試 ==\n";
    list.insert(1, 7);    // [5->7->10->20]
    list.insert(4, 30);   // [5->7->10->20->30]
    list.traverse();

    cout << "\n== get / set 測試 ==\n";
    cout << "get(0) = " << list.get(0) << "\n"; // 5
    cout << "get(2) = " << list.get(2) << "\n"; // 10 → 你後面 set 成 11
    bool ok = list.set(2, 11);
    cout << "set(2,11): " << (ok ? "OK" : "FAIL") << "\n";
    list.traverse(); // [5->7->11->20->30]

    cout << "\n== remove 中間/頭/尾 ==\n";
    ok = list.remove(1);   // 移除 7 ：[5->11->20->30]
    cout << "remove(1): " << (ok ? "OK" : "FAIL") << "\n";
    list.traverse();

    ok = list.remove(0);   // 移除頭 5 ：[11->20->30]
    cout << "remove(0): " << (ok ? "OK" : "FAIL") << "\n";
    list.traverse();

    ok = list.remove(list.size() - 1); // 移除尾 30 ：[11->20]
    cout << "remove(last): " << (ok ? "OK" : "FAIL") << "\n";
    list.traverse();

    cout << "\n== pop_front / pop_back(回傳被刪值)==\n";
    int v1 = list.pop_front(); // 移除 11 -> [20]
    cout << "pop_front() = " << v1 << "\n";
    list.traverse();

    int v2 = list.pop_back();  // 移除 20 -> []
    cout << "pop_back()  = " << v2 << "\n";
    list.traverse();

    // ---------------------------
    // 這裡開始三個 throw 的測試
    // ---------------------------

    cout << "\n== 邊界：對空串列 pop_back 會丟例外 ==\n";
    try {
        list.pop_back();   // 空 → runtime_error
        cout << "  (unexpected) no exception\n";
    } catch (const std::exception& e) {
        cout << "  caught: " << e.what() << "\n";
    }

    cout << "\n== 邊界：對空串列 pop_front 也要丟例外 ==\n";
    try {
        list.pop_front();  // 空 → runtime_error
        cout << "  (unexpected) no exception\n";
    } catch (const std::exception& e) {
        cout << "  caught: " << e.what() << "\n";
    }

    cout << "\n== 邊界:get 越界要丟 out_of_range ==\n";
    // 先放些資料，再做越界存取
    list.push_back(42);    // [42]
    list.push_back(99);    // [42->99]
    list.traverse();

    try {
        cout << "  get(0) = " << list.get(0) << "\n"; // OK: 42
        cout << "  get(5) = " << list.get(5) << "\n"; // 越界 → out_of_range
        cout << "  (unexpected) no exception\n"; //因為上面那面直接跳到下面那行了，所以不會印這行
    } catch (const std::exception& e) {
        cout << "  caught: " << e.what() << "\n";
    }

    cout << "\nAll tests done.\n";
    return 0;
}




