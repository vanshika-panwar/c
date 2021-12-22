# include<stdio.h>
# include<stdlib.h>
struct linked_list{
    int data;
    struct linked_list *next;
};
typedef struct linked_list list;
struct linked_list * getnode(int value){
   list * nod;
   nod = (list*)malloc(sizeof(struct linked_list));
   nod->data=value;
   nod->next=NULL;
   return nod;
}
void print(list* head){
    printf("printing\n");
    list * temp=head;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
       
    }
    printf("\n");
}
list* push_back(int val,list* head,list **tail){
    list * temp=getnode(val);
    if(head==NULL){
            head=temp;
            *tail=temp;
       }
    else
       { 
            list * headref=head;
            while(headref->next!=NULL)
            headref=headref->next;
            headref->next=temp;
            *tail=temp;

       }
    return head;
       
}
       

void pop_back(list**head,list**tail){
    list * temp=*head;
    while(temp->next!=*tail){
        temp=temp->next;
    }
    temp->next=NULL;
    *tail=temp;
}
void erase (int value,list* head,list* tail){
        if(head==tail  ){
            head=NULL;
            tail=NULL;
        }
        else if(head->data==value){
            head=head->next;    
        }else if(tail->data==value){
            pop_back(&head,&tail);
        }
        else{
            list * temp=head;
            while(temp->next->data!=value) temp=temp->next;
            temp->next=temp->next->next;

        }
    }
void erasenode (list * node,list **head,list**tail){
        list * temp=*head;
        if(*head==*tail && *head==node) {
            *head=NULL;
            *tail=NULL;
        }
        else if(*head==node)
        *head=(*head)->next;
        else if(*tail==node){
            pop_back(head,tail);
        }
        else{
            while(temp->next!=node) temp=temp->next;
            temp->next=temp->next->next;    
        }
    }
void insert(list* add,int val,list**head){
    list * temp=getnode(val);
    if(add==*head){
        temp->next=*head;
        *head=temp;
    }
    else{
        list *headref=*head;
        while(headref->next!=add){
            headref=headref->next;
        }
        temp->next=headref->next;
        headref->next=temp;
        }
        
}
int main(){
    list *head;
    head->data=0;
    head->next=NULL;
    list* tail=head;
    head=push_back(1,head,&tail);
    head=push_back(2,head,&tail);
    head=push_back(300,head,&tail);
    head=push_back(4,head,&tail);
    head=push_back(9,head,&tail);
    head=push_back(6,head,&tail);
    head=push_back(8,head,&tail);
    print(head);
    pop_back(&head,&tail);
    pop_back(&head,&tail);
    print(head);
    erase(300,head,tail);
    print(head);
    insert(tail,100,&head);
    insert(head,200,&head);
    print(head);
    erasenode(head,&head,&tail);
    erasenode(tail,&head,&tail);
    print(head);
    head=push_back(500,head,&tail);
    print(head);







    
    






   






}