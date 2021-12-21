# include<stdio.h>
# include<stdlib.h>
struct dynamic_array{
    int * ar;
    int sz;
    int top;
};
typedef struct dynamic_array  array;
void increase(array *ob){
   
    ob->ar=(int*)realloc(ob->ar,ob->sz*2*sizeof(int));
}
void push_back(array *ob,int ele){
    ob->top=ob->top+1;
    if(ob->top<ob->sz)
    ob->ar[ob->top]=ele;
    else increase(ob);
    ob->ar[ob->top]=ele;
}
void pop_back(array *ob){
    if(ob->top>0)
    ob->top--;
    else printf("underflow\n");
}
void erase(array *ob){
    free(ob->ar);    
}
int size(array *ob){
    return ob->sz;
}
void insert(array *ob,int index,int val){
    if(ob->top+1<ob->sz){
        int i;
        for(i=ob->top+1;i>index;i--)
        ob->ar[i]=ob->ar[i-1];
        ob->ar[i]=val;
        }
        else{
             
             increase(ob);
             int i;
             for(i=ob->top+1;i>index;i--)
             ob->ar[i]=ob->ar[i-1];
             ob->ar[i]=val;
        }
       
        
}
void print(array *ob){
    for(int i=0;i<=ob->top;i++)
        printf("%d ",ob->ar[i]);
    printf("\n");
}


int main()
{
    int n;
    printf("enter array size\n");
    scanf("%d",&n);
    struct dynamic_array *obj;
    obj->sz=n;
    obj->ar=(int*)malloc(n*sizeof(int));
    obj->top=-1;
    push_back(obj,2);
    push_back(obj,3);
    push_back(obj,4);
    push_back(obj,6);
    print(obj);
    pop_back(obj);
    pop_back(obj);
    print(obj);
    push_back(obj,7);
    push_back(obj,8);
    push_back(obj,9);
    push_back(obj,10);
    print(obj);
    insert(obj,3,50);
    print(obj);


    
}
