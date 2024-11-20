#include <iostream>

using namespace std;

class Node{
    public:
    int data;
    Node* prev;
    Node* next;

    Node(int value){
        this -> data = value;
        this -> prev = nullptr;
        this -> next = nullptr;
    }

    Node(){
        this -> data = 0;
        this -> prev = nullptr;
        this -> next = nullptr;
    }

    ~Node(){
        cout << "Memory of " << data << " is deleted" << endl;
    }
};

class DLL{
    public:
    Node* Head;

    DLL(Node* &Head){
        this -> Head = Head;
    }

    DLL(){
        this -> Head = nullptr;
    }

    //Insertion 
    void insert(int value, int pos){
        Node* newNode = new Node(value);

        //Inserting at HEAD
        if(pos == 1 || Head == nullptr){
            newNode -> next = Head;

            if(Head != nullptr){
                Head -> prev = newNode;
            }
            Head = newNode;
            cout << "Inserted " << value << " at position " << "Head" << endl;
            return;
        }

        Node* temp = Head;
        int index = 1;

        //Inserting at POSITION
        while(index < pos - 1 && temp -> next != nullptr){
            index++;
            temp = temp -> next;
        }

        //Adjusting pointers 
        newNode -> next = temp -> next;

        if(temp -> next != nullptr){
            temp -> next -> prev = newNode;
        }

        newNode -> prev = temp;
        temp -> next = newNode;

        if(index < pos - 1){ //Condition to handle pos > length
            cout << "Inserted " << value << " at End position" << endl;
        } else{
            cout << "Inserted " << value << " at position " << pos << endl;
        }

        return;
    }

    void deleteNode(int pos){

        //Condition check for empty list
        if(Head == nullptr){
            cout << "List is EMPTY " << endl;
            return;
        }

        //Deleting HEAD
        if(pos == 1){
            Node* temp = Head;
            Head = Head -> next;
            if(Head != nullptr){
                Head -> next -> prev = nullptr;
            }
            cout << "Head  deleted Succesfully" << endl;
            delete temp;
            return;
        }

        //Deleting Node At given position
        Node* prev = Head;
        Node* curr = Head;
        int index  = 1;

        while(index < pos && curr != nullptr){
            prev = curr;
            curr = curr -> next;
            index++;
        }

        //Condition check for pos > length
        if(curr == nullptr ){
            cout << "Invalid Position" << endl;
            return;
        }

        //Adjusting Pointers
        prev -> next = curr -> next;
        if(curr -> next != nullptr){
            curr -> next -> prev = prev;
        }

        cout << "Deleted Node at position " << pos << " with data " << curr -> data << endl;
        delete curr;
    }

    int length(){
        Node* temp = Head;
        int length = 0;

        while(temp != nullptr){
            length++;
            temp = temp -> next;
        }
        cout << "Length of list is " << length << endl;
        return length;
    }

    void print(){
        Node* temp = Head;

        while(temp != nullptr){
            cout << temp -> data << " " ;
            temp = temp -> next;
        }
        cout << endl;
    }

};

int main(){

    DLL myList;

    myList.insert(1,1);
    myList.insert(2,2);
    myList.insert(3,3);
    myList.insert(5,4);
    myList.insert(6,5);
    myList.insert(4,4);
    myList.insert(1,7);
    myList.deleteNode(8);
    myList.length();
    myList.print();
    
    return 0;
}