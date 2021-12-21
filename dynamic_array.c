# include<stdio.h>
# include<stdlib.h>
class dynamic_Array{
    int * ar;
    int sz;
    int top;

    public:
    dynamic_Array(int size){
        sz=size;
        ar=(int*)malloc(size*sizeof(int));
        top=-1;
    }
    void push_back(int ele){
        printf("pushing\n");
        top++;
        if(top<sz)
        ar[top]=ele;
    }
    void pop_back(){
        printf("poppping\n");
        if(top>0)
        top--;
        else printf("underflow\n");
    }
    void increase(int nsz){
        
        
        sz=nsz;
        ar=(int*)realloc(ar,nsz*sizeof(int));


    }
    void erase(){
        free(ar);    
    }
    int size(){
        return sz;
    }
    void insert(int index,int val){
        if(top+1<sz){
            int i;
            for( i=top+1;i>index;i--)
            ar[i]=ar[i-1];

            ar[i]=val;
        }
        else{
             int len=sz;
             int nlen=sz+1;
             increase(nlen);
             int i;
             for(i=top+1;i>index;i--)
             ar[i]=ar[i-1];
             ar[i]=val;
        }
       
        
    }
    void print(){
        for(int i=0;i<=top;i++)
        printf("%d ",ar[i]);
        printf("\n");
    }

};
int main()
{
    dynamic_Array ob1(4);
    ob1.push_back(2);
    ob1.push_back(3);
    ob1.push_back(4);
    ob1.push_back(6);
    ob1.print();
    ob1.pop_back();
    ob1.print();
    ob1.increase(10);
    ob1.push_back(6);
    ob1.push_back(6);
    ob1.push_back(6);
    ob1.push_back(6);
    ob1.print();
    int len=ob1.size();
    printf("len is %d \n",len);
    ob1.insert(3,50);
    ob1.print();


    
}