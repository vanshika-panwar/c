#include<iostream>
using namespace std;
class Underflow : public exception {
public:
	Underflow(string str) : exception() {
		cerr << str << "\n";
	}
};

struct stack{
private:
    int * ar;
    int sz;
    int top;
public:

	stack() {
		ar = (int*) malloc(10 * sizeof(int));
		sz = 10;
		top = -1;
	}

	void increase(){
		ar = (int*) realloc(ar, sz * 2 * sizeof(int));
	}
	void push(int val){
		top = top + 1;
		if (top < sz) {
			ar[top] = val;
		} else {
			increase();
			ar[top] = val;
		}
	}
	void pop() {
		if (top > 0) {
			top--;
		} else {
			throw Underflow("Underflow!!");
		}
	}
    int peek(){
        return ar[top];
    }
	

	void print() {
		for (int i = 0; i <= top; i++)
			cout << ar[i] << " ";
		cout << "\n";
	}
   
   
};
int main(){
    stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    s.push(6);
    s.pop();
    s.pop();
    s.pop();
    s.print();
    cout<<s.peek();
    
}