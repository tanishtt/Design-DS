// Queue using array.
// Queue using ll.
// Queue using queue.
#include<bits/stdc++.h>
using namespace std;
class Queue{
    int start, end, capacity, currSize;
    int *arr;
public:
    Queue(int capacity){
        start = -1;
        end = -1;
        this->capacity = capacity;
        currSize = 0;
        arr = new int[capacity];
    }
    void push(int x){
        if(currSize==capacity){
            cout << "Overflow queue" << "\n";
            return;
        }
        if(currSize==0){
            start = 0;
            //end = 0;
        }
        end = (end + 1)%capacity;
        arr[end] = x;
        currSize++;
    }
    int pop(){
        if(currSize==0){
            cout << "Sorry Nothing to pop!." << "\n";
            return -1;
        }
        start = (start + 1) % capacity;
        currSize--;
        if(currSize==0){
            start = -1;
            end = -1;
        }
    }
    int top(){
        if(currSize==0){
            cout << "Empty queue." << "\n";
            return -1;
        }
        return arr[start];
    }
    bool isEmpty(){
        return currSize == 0;
    }
    int size(){
        return currSize;
    }
    ~Queue(){
        delete[] arr;
    }
    
};
int main(){
    Queue q(5);
    q.push(3);
    q.push(9);
    q.push(67);
    q.push(78);
    q.push(90);
    q.push(88);
    cout << q.top() << "\n";
    q.pop();
    q.pop();
    cout << q.top()<<"\n";
    q.push(1);
    q.push(2);
    q.pop();
    q.pop();
    q.pop();
    cout << q.top() << "\n";
    q.pop();
    q.pop();
    q.pop();
    q.push(9);
    cout << q.top() << "\n";
    return 0;//3 67 1
    
}