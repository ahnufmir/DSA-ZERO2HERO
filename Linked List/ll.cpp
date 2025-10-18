#include <iostream>
using namespace std;

class Node
{
private:
public:
int val;
Node *next;
Node(int value){
        val = value;
        next = NULL;
    }
    ~Node();
};

class ll
{
private:
    Node* tail;
    Node* head;
public:
    ll(){
        head = tail = NULL;
    }
    void push_front(int val){
        Node* newNode = new Node(val);
        if (head == NULL)
        {
            head = tail = newNode;
            return;
        }
        else{
            newNode->next = head;
            head = newNode;
        }
        
    }
    void push_back(int val){
        Node *newNode = new 
    }
    void printLL(){
        Node* temp = head;
        while (temp != NULL)
        {
            cout << temp->val << " ";
            temp = temp->next;
        }
        cout << endl;
        
    }
};

int main(){
    ll list;
    list.push_front(1);
    list.push_front(2);
    list.push_front(3);

    list.printLL();
}


