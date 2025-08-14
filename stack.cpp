//stack using array.
//stack using ll.
//stack using queue.

// stack using array.
#include<bits/stdc++.h>
using namespace std;


class Stack{
    int top;
    int capacity;
    int *st;
    public:
    Stack(int capacity){
        this->capacity = capacity;
        top = -1;
        st = new int[capacity];
    }
    ~Stack(){
        delete[] st;
    }
    bool push(int x){
        if(top>=capacity-1){
            cout << "Stack Overflow\n";
            return false;
        }
        st[++top] = x;
        return true;
    }
    int pop(){
        if(top<0){
            cout << "Stack Underflow\n";
            return -1;
        }
        return st[top--];
    }
    bool isEmpty(){
        return top < 0;
    }
    int topp(){
        if(top<0){
            cout << "Stack is Empty\n";
            return -1;
        }
        return st[top];
    }
    int size(){
        return top + 1;
    }
};

int main(){
    Stack s(5);
    s.push(2);
    s.push(3);
    s.push(1);
    cout << s.topp()<<"\n";
    s.pop();
    cout << s.topp()<<"\n";
    cout << s.size() << "\n";
    return 0;
}