#include <iostream>

using namespace std;

class Node{
    public:
        int data;
        Node* next;

    Node(int value){
        this -> data = value;
        this -> next  = nullptr;
    }

    Node(){
        this -> data = 0;
        this -> next  = nullptr;
    }

    ~Node(){
        cout << "Memory of " << data << " is freed " << endl;
    }
};

class SLL{
    public:
        Node* Head;

    SLL(){
        this -> Head = nullptr;
    }

    void insertAtHead(int value){
        Node* newNode = new Node(value);

        newNode -> next = this -> Head;
        Head = newNode;
    }

    void insertAtTail(int value){
        Node* newNode = new Node(value);

        if(this -> Head == nullptr){
            this -> Head = newNode;
            return;
        }

        Node* temp = this -> Head;
        while(temp -> next != nullptr){
            temp = temp -> next;
        }

        temp -> next = newNode;
        return;
    }

    void insert(int pos,int value){
        Node* newNode = new Node(value);

        if (pos == 1 || Head == nullptr){
            newNode -> next = Head;
            Head = newNode;
            cout << "Inserted " << value << " at " << pos << endl;
            return;
        }

        Node* prev = Head;

        int index = 1;
        while(index < pos - 1 && prev -> next != nullptr){
            index++;
            prev = prev -> next;
        }

        newNode -> next = prev -> next;
        prev -> next = newNode;

        if(index < pos - 1 ){
            cout << "Inserted " << value << " at End Position" << endl;
        } else {
            cout << "Inserted " << value << " at " << pos << endl;
        }
        
        return;
    }

    void deleteHead(){
        if(this -> Head == nullptr){
            cout << "Empty List" << endl;
        }

        Node* temp = this -> Head;
        Head = Head -> next;

        delete temp;
    }

    void deleteNode(int pos){
        if(this -> Head == nullptr){
            cout << "Empty List" << endl;
            return;
        }

        Node* prev = Head;
        Node* curr = Head;
        int index  = 1;

        if( pos == 1){
            Head = Head -> next;
            delete prev;
        }

        while(index < pos && curr != nullptr){
            index++;
            prev = curr;
            curr = curr -> next;
        }

        if(index < pos){
           cout << "Invalid Position" << endl;
           return;
        }

        prev -> next = curr -> next;
        delete curr;
        cout << "Node at position " << pos << " deleted" << endl;

       return;
    }

    void length(){
        int length = 0;

        Node* temp = Head;
        while(temp != nullptr){
            length++;
            temp = temp -> next;
        }

        cout << "Length of list is " << length << endl;
    }

    void print(){
        Node* temp = this -> Head;

        while(temp != nullptr){
            cout << temp -> data << " ";
            temp = temp -> next;
        }
        cout << endl;
    }
};

int main(){
    SLL myList;

    myList.insertAtHead(3);
    myList.insertAtHead(2);
    myList.insertAtHead(1);
    myList.insertAtTail(4);
    myList.insertAtTail(5); 
    myList.deleteHead(); 
    myList.insert(5,9);
    myList.deleteNode(5);
    myList.print();
    myList.length();

    return 0;
}