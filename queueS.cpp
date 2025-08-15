//queue using 2 stack.

#include<bits/stdc++.h>
using namespace std;

class Queue
{
public:
    stack<int> s1, s2;
    Queue()
    {
    }

    void push(int x)
    { // o(n)
        while (!s1.empty())
        {
            s2.push(s1.top());
            s1.pop();
        }
        s1.push(x);
        while (!s2.empty())
        {
            s1.push(s2.top());
            s2.pop();
        }
    }

    int pop()//o(1)
    {
        int x = s1.top();
        s1.pop();
        return x;
    }

    int peek()//o(1)
    {
        return s1.top();
    }

    bool empty()//o(1)
    {
        return s1.size() == 0;
    }
};
int main(){
    return 0;
}