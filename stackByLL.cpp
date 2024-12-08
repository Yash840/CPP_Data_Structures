#include <iostream>
using namespace std;

// Basic Node class for LINKED LIST
class Node{
    public:
    int val;
    Node* next = NULL;

    Node(int value){
        this -> val = value;
        this -> next = NULL;
    }

    Node(){
        this -> val = 0;
        this -> next = NULL;
    }
};

// Function to insert new Node at head of linked list
void insertAtHead(Node*& head,int value){
    if(head == NULL){
        Node* newNode = new Node(value);
        head = newNode;
        return;
    }

    Node* newNode = new Node(value);

    newNode -> next = head;
    head = newNode;
    return;
}

// Function to delete head of linked list
void deleteHead(Node* head){
    if(head == NULL){
        return;
    }

    Node* temp = head;
    head = head -> next;

    delete temp;
    return;
}

// Main Stack class
class STACK{
    public:
    Node* top = new Node();

    STACK(Node* head){
        top = head;
    }

    STACK(){
        top = new Node();
    }

    void push(int value){
        insertAtHead(top,value);

        cout << "Value " << value << " pushed in stack" << endl;
    }

    void Multipush(int n){  // Function to push n elements at a time by taking input from user
        int value = 0;
        for(int i = 0;i < n;i++){
            cout << "Enter Value " << i+1 << " : ";
            cin >> value;
            push(value);
        }

        cout << n << " Values pushed successfully" << endl;
    }

    void ManualMultipush(int n,int arr[]){  // Function to push n elements at a time in form of array
        for(int i = 0;i < n;i++){           
            push(arr[i]);
        }

        cout << n << " Values pushed successfully" << endl;
    }

    void pop(){
        cout << top -> val << " Popped" << endl;
        deleteHead(top);   
    }

    void peek(){
        if(top == NULL) return;
        cout << top -> val << endl;
        return;
    }

    void print(){
        Node* temp = top;
        int ht = 0;

        while(temp != NULL){
            cout << temp -> val << endl;
            ht++;
            temp = temp -> next;
        }

        cout << "Stack with HEIGHT " << ht << " printed" << endl;
        return;
    }
};

int main(){

    int arr[4] = {4,3,2,1};
    STACK* st = new STACK();
    st->ManualMultipush(4,arr);
    st->print();
}
