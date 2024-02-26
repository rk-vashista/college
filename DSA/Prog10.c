#include <stdio.h>
#include <stdlib.h>

struct BST{
    int data;
    struct BST *lchild;
    struct BST *rchild;
};

typedef struct BST *node;

node getnode()
{
    node temp;
    temp=(node)malloc(sizeof(struct BST));
    temp->lchild=NULL;
    temp->rchild=NULL;
    return temp;
}

void insert(node root, node nn)
{
    if(nn->data<root->data)
    {
        if(root->lchild==NULL)
            root->lchild=nn;
        else
            insert(root->lchild,nn);
    }
    
    if(nn->data>root->data)
    {
        if(root->rchild==NULL)
            root->rchild=nn;
        else
            insert(root->rchild,nn);
    }
}


void preorder(node root)
{
    if(root!=NULL)
    {
        printf("%d \t",root->data);
        preorder(root->lchild);
        preorder(root->rchild);
    }
}

void postorder(node root)
{
    if(root!=NULL)
    {
        postorder(root->lchild);
        postorder(root->rchild);
        printf("%d \t",root->data);
    }
}

void inorder(node root)
{
    if(root!=NULL)
    {
        inorder(root->lchild);
        printf("%d \t",root->data);
        inorder(root->rchild);
    }
}

void search(node root, int key)
{
    if(root==NULL)
    {
        printf("Empty Tree");
        return;
    }
    
    node curr=root;
    while(curr!=NULL)
    {
        if(curr->data==key)
        {
            printf("Key found");
            return;
        }
        else
        {
            if(key<curr->data)
            curr=curr->lchild;
            else
            curr=curr->rchild;
        }
    }
    printf("Key not found");
}


void main()
{
    int ch;
    node root=NULL;
    node nn;
    printf("MENU\n1.Create\n2.Traversal\n3.search\n4.exit\n");
    while(1)
    {
        printf("Enter your choice\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:printf("Enter the number of nodes\n");
                    int n;
                    scanf("%d",&n);
                    for(int i =0;i<n;i++)
                    {
                        nn=getnode();
                        printf("Enter the value of the node\n");
                        int key;
                        scanf("%d",&key);
                        nn->data=key;
                        if(root==NULL)
                            root=nn;
                        else
                            insert(root,nn);
                    }
                    break;
            
            case 2: printf("\nInorder\n");
                    inorder(root);
                    printf("\nPreorder\n");
                    preorder(root);
                    printf("\nPostorder\n");
                    postorder(root);
                    break;
                    
            case 3: printf("enter the value to be searched\n");
                    int key;
                    scanf("%d",&key);
                    search(root,key);
                    break;
            case 4:exit(0);
        }
    }
}