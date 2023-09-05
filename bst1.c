#include<stdio.h>
#include<stdlib.h>
struct node
{   
    int data;
    struct node *leftchild;
    struct node *rightchild;
};
//To create a newnode 
struct create * newnode(int val)
{
    struct node *temp;
    temp=malloc(sizeof(struct node));
    temp->data=val;
    temp->leftchild=NULL;
    temp->rightchild=NULL;
    return temp;
}

struct node* search(struct node* root,int val)
{
    if(root==NULL||root->data==val)
    {
        return root;
    }
    else if(val>root->data)
    {
        return search(root->rightchild,val);
    }
    else if(val<root->data)
    {
        return search(root->leftchild,val);
    }

}
//To insert a element
struct node* insert(struct node* root,int val)
{
    if(root==NULL)
    {
       return  newnode(val);
    }
    else if(val>root->data)
    {
        root->rightchild=insert(root->rightchild,val);
        
    }
    else
    {
     root->leftchild=insert(root->leftchild,val);
    }
    return root;
}

//function to find the minimum value in a node
struct node* find_minimum(struct node * root) {
if (root == NULL)
return NULL;
else if (root ->leftchild != NULL) 
return find_minimum(root ->leftchild); 
return root;
}

struct node* delete(struct node *root,int val)
{
    if(root==NULL)
    {
        return NULL;
    }
    if(val>root->data)
    {
        root->rightchild=delete(root->rightchild,val);
    }
    else if(val<root->data)
    {
        root->leftchild=delete(root->leftchild,val);
    }
    else if (root->leftchild == NULL && root->rightchild == NULL)
          {
           free(root);
           return NULL;
          }
         else if (root ->leftchild == NULL || root ->rightchild == NULL)
          {
           struct node *temp;
           if (root ->leftchild == NULL)
           temp = root ->rightchild;
           else
           temp = root ->leftchild;
           free(root);
           return temp;
         }
     else
    {
    struct node *temp = find_minimum(root ->rightchild);
    root -> data = temp -> data;
    root ->rightchild = delete(root ->rightchild, temp -> data);
    }
  
return root;
}
 
//Inorder
void inorder(struct node *root) {
if (root != NULL) 
  {
 inorder(root ->leftchild); 
 printf(" %d ", root -> data); 
 inorder(root ->rightchild); 
  }
}

int main()
{
    struct node *root;
    root=newnode(25);
    insert(root,15);
    insert(root,40);
    insert(root,5);
    insert(root,30);
    insert(root,50);
    insert(root,60);
    insert(root,70);
    insert(root,85);
    insert(root,90);
   inorder(root);
   printf("\n");

root = delete(root,5);

root = delete(root,70);
inorder(root);
    return 0;
}