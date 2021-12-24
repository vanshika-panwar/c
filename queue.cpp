#include<iostream>
using namespace std;
class Underflow : public exception {
public:
	Underflow(string str) : exception() {
		cerr << str << "\n";
	}
};

struct queue{
private:
    int * ar;
    int sz;
    int top;
    int front;
public:

	queue() {
		ar = (int*) malloc(10 * sizeof(int));
		sz = 10;
		top = -1;
        front=-1;
	}

	queue(int sz) {
		this->sz = sz;
		top = -1;
        front=-1;
		ar = (int*) malloc(sz * sizeof(int));
	}

	void increase(){
		ar = (int*) realloc(ar, sz * 2 * sizeof(int));
	}
	void enqueue(int ele){
        if(top==-1)
        front+=1;
		top = top + 1;
		if (top < sz) {
			ar[top] = ele;
		} else {
			increase();
			ar[top] = ele;
		}
	}
	void dequeue() {

		if(front+1>top)
        throw Underflow("queue is already empty");
        else
        front+=1;
	}
    int peek(){
        if(top==-1)
        throw Underflow("queue is empty!");
        else
        return ar[top];
    }
	
	

	void print() {
		for (int i = front; i <= top; i++)
			cout << ar[i] << " ";
		cout << "\n";
	}
    
    
};

int main(){
    queue q;
    q.enqueue(10);
    q.enqueue(11);
    q.enqueue(4);
    q.enqueue(19);
    q.print();
    cout<<q.peek()<<endl;
    q.dequeue();
    q.print();
    q.dequeue();
    q.print();
    cout<<q.peek()<<endl;


}