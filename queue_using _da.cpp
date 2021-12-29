#include<iostream>
using namespace std;
class Underflow : public exception {
public:
	Underflow(string str) : exception() {
		cerr << str << "\n";
	}
};
struct dynamic_array{
private:
    int * ar;
    int sz;
    int top;
	int front;
public:

	dynamic_array() {
		ar = (int*) malloc(10 * sizeof(int));
		sz = 10;
		top = -1;
		front=-1;
	}

	dynamic_array(int sz) {
		this->sz = sz;
		top = -1;
		ar = (int*) malloc(sz * sizeof(int));
		front=-1;
	}

	void increase(){
		ar = (int*) realloc(ar, (sz+1 )* sizeof(int));
		sz = sz+1;
	}
	void push_back(int ele){
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
	void pop_back() {
		if (top >= 0) {
			top--;
		} else {
			throw Underflow("Underflow!!");
		}
	}
	void pop_front(){
		for(int i=front;i<top;i++){
			ar[i]=ar[i+1];
		}
		top--;
		sz--;
		
	}
	void erase(){
		free(ar);
	}
	int size(){
		return top + 1;
	}
	int front_ind()
	{   
		return front;
	}
	void insert(int index,int val){
		if(top + 1 < sz){
			int i;
			for(i = top + 1; i > index; i--)
				ar[i] = ar[i-1];
			ar[i]=val;
		} else {
			increase();
			int i;
			for(i = top + 1; i > index; i--)
				ar[i] = ar[i-1];
			ar[i]=val;
		}
	}

	void print() {
		for (int i = 0; i <= top; i++)
			cout << ar[i] << " ";
		cout << "\n";
	}
    
    int &operator [](int i){
        if (i < 0 || i >= sz)
        	throw Underflow("index out of bounds!!");
        else
        	return ar[i];
    }
};

struct queue{
private :
	dynamic_array da;



public:
	queue(){
		da=dynamic_array(1);
	}
	void enqueue(int ele){
		da.push_back(ele);	
	}
	void dequeue() {
		da.pop_front();
		
	}
    int peek(){
		return da[da.size()-1];
    }
	bool isEmpty(){
		return (da.size()==0);
	}
	int front(){
		return  da[da.front_ind()];
	}
	
	
	

	
    
    
};

int main(){
    queue q;
    q.enqueue(10);
    q.enqueue(11);
    q.enqueue(4);
    q.enqueue(19);
	q.enqueue(45);
	q.enqueue(100);
    cout<<q.peek()<<endl;
    q.dequeue();
    q.dequeue();
	q.enqueue(34);
	q.enqueue(8);
    cout<<q.peek()<<endl;
	while(!q.isEmpty()){
		cout<<q.front()<<" ";
		q.dequeue();
	}


}