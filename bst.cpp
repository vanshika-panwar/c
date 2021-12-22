#include<iostream>
using namespace std;
class bst{
private:

    int data;
    bst* left;
    bst* right;
    
public:
    bst(){
        data=0;
        left=NULL;
        right=NULL;
    }
    bst (int val){
        data=val;
        left=NULL;
        right=NULL;
    }

    void inorder(bst* root){
        if(root){
            inorder(root->left);
            cout<<root->data<<" ";
            inorder(root->right);
        }
    }

    bst* insert(bst * root,int val){
        if(!root){
            bst* node=new bst(val);
            return node;
        }
        else if(val>root->data)
            root->right=insert(root->right,val);
        else
            root->left=insert(root->left,val);
        return root;
    }
    bst* search(bst* root,int val){
        if(root==NULL || root->data==val) 
        return root;
        else if(val<root->data) 
        return search(root->left,val);
        else 
        return search(root->right,val);
    }
    bst* inorder_succ(bst* temp){
        bst * node=temp;
        while(node->left!=NULL)
            node=node->left;
        return node;
    }
    bst* erase(bst*root ,int val){
        if(root->data<val)
            root->right= erase(root->right,val);
        else if(root->data>val)
            root->left= erase(root->left,val);
        else{
            if(root->left==NULL && root->right==NULL)
                return NULL;
            else if(root->left==NULL)
                return root->right;
            else if(root->right==NULL)
                return root->left;
            else
                {
                    bst * temp=inorder_succ(root->right);
                    root->data=temp->data;
                    root->right=erase(root->right,temp->data);
                }
            
        }
        return root;
    }
    int next_greatest(bst* root,int val){      // find the samllest element greater than the value
        bst * target_node=search(root,val);
        bst * res=inorder_succ(target_node->right);
        return res->data;
    }
};
int main(){
    bst *root=NULL;
    root=root->insert(root,8);
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
    root=root->insert(root,6);
    root=root->insert(root,9);


    root->inorder(root);
    if(root->search(root,9))
    cout<<"\n"<<9<<" found\n"<<endl;
    root=root->erase(root,7);
    root->inorder(root);
    cout<<root->next_greatest(root,5);




}