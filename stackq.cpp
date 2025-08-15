//stack using 1 queue.

#include<bits/stdc++.h>
using namespace std;


class Stack
{
public:
    Stack()
    {
    }
    queue<int> q;
    void push(int x)
    {
        q.push(x);
        int sz = q.size();
        for (int i = 1; i < sz; i++)
        {
            q.push(q.front());
            q.pop();
        }
    }

    int pop()
    {
        int x = q.front();
        q.pop();
        return x;
    }

    int top()
    {
        return q.front();
    }

    bool empty()
    {
        return q.size() == 0;
    }
};

int main(){

    return 0;
}