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
public:

	dynamic_array() {
		ar = (int*) malloc(10 * sizeof(int));
		sz = 10;
		top = -1;
	}

	dynamic_array(int sz) {
		this->sz = sz;
		top = -1;
		ar = (int*) malloc(sz * sizeof(int));
	}

	void increase(){
		ar = (int*) realloc(ar, sz * 2 * sizeof(int));
		size=2*sz;
	}
	void push_back(int ele){
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
	void erase(){
		free(ar);
	}
	int size(){
		return top+1;
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
    void set(int index,int ele){
        ar[index]=ele;
    }
    int get(int index){
        return ar[index];
    }
    int &operator [](int i){
        if(i>=sz)
        throw Underflow("index out of bounds!!");
        else
        return ar[i];
    }
};

int main(){
    dynamic_array obj(10);
    obj.push_back(2);
    obj.push_back(5);
    obj.push_back(6);
    obj.push_back(7);
    obj.push_back(8);
    obj.push_back(9);
    obj.print();
    obj.print();
    obj[2]=100;
    obj.print();
    cout<<obj[100];






}
