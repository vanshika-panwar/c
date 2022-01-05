# include<bits/stdc++.h>
# include<iostream>
using namespace std;
class avl{
private:
    int key;
    avl*left;
    avl*right;
    int h;  
    
public:
    avl(){
        key=0;
        left=NULL;
        right=NULL;
        h=1;
    }
    avl(int v){
        key=v;
        left=NULL;
        right=NULL;
        h=1;
    }
    
    int max(int a,int b)
    {
        if(a>b)
        return a;
        else return b;
    }
    int height(avl* root){
        if(!root)
        return 0;
        else
        return root->h;
    }
    
    void inorder(avl* root){
        if(root){
            inorder(root->left);
            cout<<root->key<<" ";
            
            inorder(root->right);
        }
    }
    void inorder_s(avl* root,vector<int>&res){
        if(root){
            inorder_s(root->left,res);
            res.push_back(root->key);
            inorder_s(root->right,res);
        }
    }
    int inorder_succ(avl* root,avl* node){
       vector<int>res;
       inorder_s(root,res);
       for(int i=0;i<res.size();i++){
           if(res[i]>node->key)
           {
           return res[i];
           break;
           }
       }
       return -1;

    }
    int checkbalance(avl* root){
        if(!root)
        return 0;

        int left_height=height(root->left);
        int right_height=height(root->right);

        return left_height-right_height;
    }
    avl* next_greatest(avl * node){
        if(!node)
        return NULL;
        avl * temp=node;
        while(temp->left!=NULL){
           temp=temp->left;
        }
        return temp;
    }
    avl * left_rotate(avl* root){
        avl * child=root->right;
        avl* left_child=child->left;
        child->left=root;
        root->right=left_child;



        root->h=1+max(height(root->left),height(root->right));
        child->h=1+max(height(child->left),height(child->right));
        return child;
    }
    avl* right_rotate(avl* root){
        avl* child=root->left;
        avl * r_child=child->right;
        child->right=root;
        root->left=r_child;
        return child;
    }
    avl * erase(avl * root,int val){
        if(val>root->key){
            root->right=erase(root->right,val);
        }
        else if(val<root->key){
            root->left=erase(root->left,val);
        } 
        else{
            if(root->left==NULL && root->right==NULL){
                return NULL;
            }
            else if(root->left==NULL){
                return root->right;
            }
            else if(root->right==NULL)
            {
                return root->left;
            }
            else{
                avl* temp=next_greatest(root->right);
                root->key=temp->key;
                root->right=erase(root->right,temp->key);
                return root;
            }

        } 
        root->h=1+max(height(root->left),height(root->right));

        int b=checkbalance(root);
        if(b>1){                                        // left imbalance
            if(val<root->left->key){
                root=right_rotate(root);
            }
            else if(val>root->left->key)
            {
                root->left=left_rotate(root->left);
                root=right_rotate(root);
            }
        }
        else if(b<-1){                                   //right imbalance
            if(val>root->right->key){
                root=left_rotate(root);
            }
            else if(val<root->right->key){      
                root->right=right_rotate(root->right);
                root=left_rotate(root);
            }
        }

        return root;


    }
    avl* insert(avl  * root,int data){
        if(!root){
            root=new  avl(data);
            return root;
        }
        else if(data<root->key){
            root->left=insert(root->left,data);
        }
        else
        {
            root->right=insert(root->right,data);
        }

        root->h=1+max(height(root->left),height(root->right));
        int b=checkbalance(root);
        if(b>1){                                        // left imbalance
            if(data<root->left->key){
                root=right_rotate(root);
            }
            else if(data>root->left->key)
            {
                root->left=left_rotate(root->left);
                root=right_rotate(root);
            }
        }
        else if(b<-1){                                   //right imbalance
            if(data>root->right->key){
                root=left_rotate(root);
            }
            else if(data<root->right->key){      
                root->right=right_rotate(root->right);
                root=left_rotate(root);
            }
        }

        return root;
        
        
    }
    avl* search(avl* root,int val){
        if(root==NULL || root->key==val) 
        return root;
        else if(val<root->key) 
        return search(root->left,val);
        else 
        return search(root->right,val);
    }
    int next_greatest(avl* root,int val){      // find the samllest element greater than the value
        avl * target_node=search(root,val);
        int res=inorder_succ(root,target_node);
        return res;
    }

    
};
int main(){
    avl * root=new avl(8);
    root=root->insert(root,6);
    root=root->insert(root,5);
    root=root->insert(root,14);
    root=root->insert(root,10);
    root=root->insert(root,15);
    root=root->insert(root,4);
    root=root->insert(root,2);
    root=root->insert(root,1);
    root=root->insert(root,7);
    root=root->insert(root,19);
    root=root->insert(root,90);
    root=root->insert(root,3);
    root=root->insert(root,9);


    root->inorder(root);
    if(root->search(root,9))
    cout<<"\n"<<9<<" found\n"<<endl;
    root=root->erase(root,7);
    root->inorder(root);
    cout<<endl<<"next greatest is "<<root->next_greatest(root,19);
    cout<<endl<<"next greatest is "<<root->next_greatest(root,5);


}