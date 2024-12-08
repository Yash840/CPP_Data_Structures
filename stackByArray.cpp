#include <iostream>
#include <vector>
using namespace std;

class Stack{
    public:
    vector<int> stack;
    int size  = stack.size()-1;

    Stack(int data){
        stack.push_back(data);
    }

    Stack(){}

    void push(int data){
        stack.insert(stack.begin(),data);

        cout << data << " Pushed" << endl;
    }

    void pop(){
        if(stack.empty()){
            cout << "Stack is empty" << endl;
            return ;
        }

        stack.erase(stack.begin());
        cout << "Popped" << endl;

        return;
    }

    void peek(){
        cout << stack[0] << endl;
    }

    void print(){
        for(int i = 0;i < stack.size();i++){
            cout << stack[i] << endl;
        }
        cout << endl;
    }
};

int main(){
    Stack* st = new Stack();

    st->push(5);
    st->push(4);
    st->push(3);
    st->push(2);
    st->push(1);
    st->pop();
    st->peek();
    st->print();



}