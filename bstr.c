#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data; 
    struct node *child1; 
    struct node *child2; 
};

struct node* search(struct node *root, int x)
{
    if(root==NULL || root->data==x)
        return root;
    else if(x>root->data) 
        return search(root->child1, x);
    else 
        return search(root->child2,x);
}


struct node* find_minimum(struct node *root)
{
    if(root == NULL)
        return NULL;
    else if(root->child2 != NULL)
        return find_minimum(root->child2); 
    return root;
}


struct node* new_node(int x)
{
    struct node *p;
    p = (struct node*)malloc(sizeof(struct node));
    p->data = x;
    p->child1 = NULL;
    p->child2 = NULL;

    return p;
}

struct node* insert(struct node *root, int x)
{
    
    if(root==NULL)
        return new_node(x);
    else if(x>root->data) 
        root->child1 = insert(root->child1, x);
    else 
        root->child2 = insert(root->child2,x);
    return root;
}


struct node* delete(struct node *root, int x)
{
    
    if(root==NULL)
        return NULL;
    if (x>root->data)
        root->child1 = delete(root->child1, x);
    else if(x<root->data)
        root->child2 = delete(root->child2, x);
    else
    {
        
        if(root->child2==NULL && root->child1==NULL)
        {
            free(root);
            return NULL;
        }

        
        else if(root->child2==NULL || root->child1==NULL)
        {
            struct node *temp;
            if(root->child2==NULL)
                temp = root->child1;
            else
                temp = root->child2;
            free(root);
            return temp;
        }

        
        else
        {
            struct node *temp = find_minimum(root->child1);
            root->data = temp->data;
            root->child1 = delete(root->child1, temp->data);
        }
    }
    return root;
}

void inorder(struct node *root)
{
    if(root!=NULL) 
    {
        inorder(root->child2); 
        printf(" %d ", root->data); 
        inorder(root->child1);
    }
}
void preorder(struct node *root)
{
   if(root!=NULL)
	{
	  printf("\t%d",root->data);
	  preorder(root->child2);
	  preorder(root->child1);
}
}
void postorder(struct node *root)
{
   if(root!=NULL)
	{
	  
	  preorder(root->child1);
	  preorder(root->child2);
	  printf("\t%d",root->data);
	  
}
}

int main()
{
    int i,n,d,r,del,dn,choice;
    
    char ans,y,no;
    printf("enter the no of nodes you want :\n");
    scanf("%d",&n);

    struct node *root=NULL;
    printf("enter the value of root node :");
    scanf("%d",&r);
    root = new_node(r);
    for(i=0;i<n;i++)
{	printf("enter the value of %d node :",i+1);
	scanf("%d",&d);
	insert(root,d);
}
	
    
    printf("the inordered binary tree is :\n");
    inorder(root); 
    printf("\n");
    printf("the preordered binary tree is :\n");
    preorder(root);
    printf("\n");
    printf("the postordered binary tree is :\n");
    postorder(root);
    
	printf("\ndo you want to delete :? {1.true/2.false}:");
	scanf("%d",&choice);
	switch(choice)
		{
			case 1:
				
    				printf("enter how many elements you want to delete :\n");
    				scanf("%d",&dn);
    				for(i=0;i<dn;i++){

	
				printf("enter the elements you want to delete :");
				scanf("%d",&del);
        			root = delete(root, del);		
				}

				inorder(root);
   				printf("\n");
				break;
			case 2:
				printf("terminating!!!!!!!!!!!!!!!");
				break;
		}
		  
    

	
    return 0;
}
