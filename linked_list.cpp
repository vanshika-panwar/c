# include<iostream>
using namespace std;
class Linked_list{
private:
    int key;
    Linked_list* next;
    Linked_list* head;
    Linked_list* tail;

public:
    Linked_list(){
        key=0;
        next=NULL;
        head=NULL;
        tail=NULL;
    }
    Linked_list(int val){
        key=val;
        next=NULL;
        head=NULL;
        tail=NULL;
    }


    void print(){
        Linked_list * temp=head;
        cout<<"\n";
        while(temp!=NULL){
            cout<<temp->key<<" ";
            temp=temp->next;
        }
        cout<<"\n";
    }


    void push_back(int val){
        if(head==NULL){
            head=new Linked_list(val);
            tail=head;
        }
        else
        {
        Linked_list * temp=head;
        while(temp->next!=NULL)
        temp=temp->next;
        temp->next=new Linked_list(val);
        tail=temp->next;
        }
        

    }


    void  pop_back(){
        if(head==NULL || head->next==NULL){
            head=NULL;
            tail=NULL;
        }
        else
        {
        Linked_list * temp=head;
        while(temp->next!=tail){
            temp=temp->next;
        }
        temp->next=NULL;
        tail=temp;
        }
       
    }


    void erase (int value){
        if(head==tail  ){
            head=NULL;
            tail=NULL;
        }
        else if(head->key==value){
            head=head->next;    
        }else if(tail->key==value){
            pop_back();
        }
        else{
            Linked_list * temp=head;
            while(temp->next->key!=value) temp=temp->next;
            temp->next=temp->next->next;

        }
    }
    void erasenode (Linked_list * node){
        Linked_list * temp=head;
        if(head==tail && head==node) {
            head=NULL;
            tail=NULL;
        }
        else if(head==node)
        head=head->next;
        else if(tail==node){
            pop_back();
        }
        else{
            while(temp->next!=node) temp=temp->next;
            temp->next=temp->next->next;    
        }
    }
    Linked_list * find(int val){
        Linked_list * temp=head;
        while(temp!=NULL){
            if(temp->key==val)
            return temp;
            temp=temp->next;
        }
        return temp;

    }
    void insert(Linked_list* add,int val){           //insert a new node in front of add
    Linked_list * temp=new Linked_list(val);
        if(add==head){
            temp->next=head;
            head=temp;
        }
        else{
            Linked_list *headref=head;
            while(headref->next!=add){
                headref=headref->next;
            }
            temp->next=headref->next;
            headref->next=temp;
            }
            
        }
    int & operator[](Linked_list * node){
        return node->key;
    }
};
int main(){
    Linked_list l;
    l.push_back(1);
    l.push_back(3);
    l.push_back(7);
    l.print();
    l.pop_back();
    l.print();
    l.push_back(10);
    l.push_back(21);
    l.print();
    l.erase(3);
    l.print();
    Linked_list * node=l.find(10);
    if(node)
    l.insert(node,100);
    l.print();
    l.erase(10);
    l.print();
    l.push_back(45);
    l.push_back(50);
    l.print();
    Linked_list *temp=l.find(50);
    l.erasenode(temp);
    l.print();
    cout<<l[temp];





    
}


