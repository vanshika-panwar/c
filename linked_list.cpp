# include<iostream>
using namespace std;
class Linked_list{
private:
    int key;
    Linked_list* next;

public:
    
    Linked_list(int val){
        key=val;
        next=NULL;
    }


    void print(Linked_list* head){
        Linked_list * temp=head;
        cout<<"\n";
        while(temp!=NULL){
            cout<<temp->key<<" ";
            temp=temp->next;
        }
        cout<<"\n";
    }


    Linked_list * push_back(Linked_list * head,Linked_list * tail,int val){
        Linked_list * temp=head;
        while(temp->next!=NULL)
        temp=temp->next;
        temp->next=new Linked_list(val);
        tail=temp->next;
        return tail;

    }


    Linked_list* pop_back(Linked_list*head,Linked_list*tail){
        Linked_list * temp=head;
        while(temp->next!=tail){
            temp=temp->next;
        }
        temp->next=NULL;
        tail=temp;
        return tail;
    }


    void erase (int value,Linked_list* &head,Linked_list* &tail){
        if(head==tail  ){
            head=NULL;
            tail=NULL;
        }
        else if(head->key==value){
            head=head->next;    
        }else if(tail->key==value){
            tail=pop_back(head,tail);
        }
        else{
            Linked_list * temp=head;
            while(temp->next->key!=value) temp=temp->next;
            temp->next=temp->next->next;

        }
    }
    void erasenode (Linked_list * node,Linked_list *&head,Linked_list*&tail){
        Linked_list * temp=head;
        if(head==tail && head==node) {
            head=NULL;
            tail=NULL;
        }
        else if(head==node)
        head=head->next;
        else if(tail==node){
            tail=pop_back(head,tail);
        }
        else{
            while(temp->next!=node) temp=temp->next;
            temp->next=temp->next->next;    
        }
    }
    void insert(Linked_list* add,int val,Linked_list*&head){
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
};
int main(){
    Linked_list * head=new Linked_list(9);
    Linked_list * tail=head;
    tail=head->push_back(head,tail,8);
    tail=head->push_back(head,tail,7);
    tail=head->push_back(head,tail,6);
    tail=head->push_back(head,tail,5);
    head->print(head);
    tail=head->pop_back(head,tail);
    head->print(head);    
    head->erase(7,head,tail);
    head->print(head);  
    head->erasenode(head,head,tail);  
    head->print(head);    
    head->insert(head,100,head);
    head->print(head);    
    head->insert(tail,200,head);
    head->print(head);
}


