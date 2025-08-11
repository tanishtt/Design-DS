#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node *prev, *next;
        Node(int val){
            this->data = val;
            prev = nullptr;
            next = nullptr;
        }
        Node(){
            this->data = -1;
            prev = nullptr;
            next = nullptr;
        }
};

class DoublyLinkedList{
    private:
        Node *head;
    public:
    DoublyLinkedList(){
        head = nullptr;
    }
    void insertAtHead(int val){
        Node *newNode = new Node(val);
        newNode->next = head;
        head = newNode;
        return;
    }
    void insertAtTail(int val)
    {
        if(head==nullptr){
            insertAtHead(val);
            return;
        }
        Node *temp = head;
        while(temp->next){
            temp = temp->next;
        }
        Node *newNode = new Node(val);
        temp->next = newNode;
        newNode->prev = temp;
    }
    void insertAtPosition(int val,int pos)
    {
        if(pos==1){
            Node *newNode = new Node(val);
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
            return;
        }
        int p = 0;
        Node*temp=head;
        while(temp&&temp->next){
            p++;
            if(p==pos-1){
                Node *newNode = new Node(val);
                newNode->next = temp->next;
                temp->next->prev = newNode;
                temp->next = newNode;
                newNode->prev = temp;
                return;
            }
            temp = temp->next;
        }
    }
    void deleteHead(){
        if(head==nullptr){
            return;
        }
        Node *toDelete = head;
        head = head->next;
        if(head){
            head->prev = nullptr;
        }
        delete toDelete;
    }
    void deleteTail() {
        if (head == nullptr)
        {
            return;
        }
        if(head->next==nullptr){
            delete head;
            head = nullptr;
            return;
        }
        Node *temp = head;
        while(temp->next&&temp->next->next){
            temp = temp->next;
        }
        Node *toDelete = temp->next;
        temp->next = nullptr;
        delete toDelete;
    }
    void deleteAtPosition(int pos) {}

    void printDoublyLL(){
        Node *temp = head;
        while(temp){
            cout << temp->data << "(" << (temp->prev ? temp->prev->data : -1) << "," << (temp->next ? temp->next->data : -1)<<")  ";
            temp = temp->next;
        }
        cout << "\n";
    }
    void printBackward(){}
    ~DoublyLinkedList(){
        Node *current = head;
        while(current!=nullptr){
            Node *nextNode = current->next;
            delete current;
            current = nextNode;
        }
    }

};

int main(){
    DoublyLinkedList dll;
   // = new DoublyLinkedList();
    dll.insertAtHead(12);
    dll.insertAtHead(1);
    dll.insertAtPosition(3, 2);
    dll.insertAtPosition(4, 3);
    dll.insertAtTail(50);
    dll.printDoublyLL();
    dll.deleteHead();
    dll.printDoublyLL();
    dll.deleteTail();
    dll.printDoublyLL();

    return 0;
}

