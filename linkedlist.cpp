#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node *next;
    Node(){
        data=-1;
        next = nullptr;
    }
    Node(int data){
        this->data = data;
        this->next = nullptr;
    }
    Node(int data, Node *next){
        this->data = data;
        this->next = next;
    }
};

class LinkedList{
    private:
        Node *head;
    public:
    LinkedList(){
        head = nullptr;
    }
    void insertAtHead(int value){
        Node *newNode = new Node(value);
        newNode->next = head;
        head = newNode;
        return;
    }
    void insertAtTail(int value){
        Node *newNode = new Node(value);
        Node *temp = head;
        if(head==nullptr){
            head = newNode;
            return;
        }
        while(temp->next){
            temp = temp->next;
        }
        temp->next = newNode;
        return;
    }
    void insertAtPosition(int val,int pos)
    {
        if(pos==1){
            Node *newNode = new Node(val);
            newNode->next = head;
            head = newNode;
            return;
        }
        Node *temp = head;
        int p = 0;
        while(temp&&temp->next){
            p++;
            if(p==pos-1){
                Node *newNode = new Node(val);
                newNode->next = temp->next;
                temp->next = newNode;
                return;
            }
            temp = temp->next;
        }
    }
    void printList(){
        Node *temp = head;
        while(temp){
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << "\n";
    }
    int lengthOfLL(){
        Node *temp = head;
        int len = 0;
        while(temp){
            len++;
            temp = temp->next;
        }
        return len;
    }
    bool checkIfPresent(int val){

    }
    void deleteAtHead(){
        if(head==nullptr){
            return;
        }
        Node *temp = head;
        head = head->next;
        delete temp;
    }
    void deleteAtPosition(int pos){
        if(head==nullptr){
            return;
        }
        if(pos==1){
            Node *toDelete = head;
            head = head->next;
            delete toDelete;
            return;
        }
        Node *temp = head;
        int p = 0;
        while(temp->next){
            p++;
            if(p==pos-1){
                Node *toDelete = temp->next;
                temp->next = temp->next->next;
                delete toDelete;
            }
            temp = temp->next;
        }
        return;
    }
    void deleteAValue(int val){

    }
    void deleteAtLast(){
        if(head==nullptr){
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

    void reverse(){}
    ~LinkedList(){
        Node *current = head;
        while(current!=nullptr){
            Node *nextNode = current->next;
            delete current;
            current = nextNode;
        }
    }
};

int main(){
    LinkedList list;
    list.insertAtHead(20);
    list.insertAtHead(40);
    list.insertAtTail(80);
    list.deleteAtLast();
    list.insertAtTail(90);
    list.insertAtHead(120);
    list.insertAtHead(140);
    list.deleteAtPosition(3);
    list.deleteAtPosition(3);
    list.printList();
    list.insertAtPosition(78, 3);
    list.printList();
    list.insertAtPosition(89, 2);
    list.printList();
    list.insertAtPosition(99, 1);
    list.printList();

    return 0;
}
