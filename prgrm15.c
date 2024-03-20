#include<stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node *rlink,*llink;
};
typedef struct node *NODE;
NODE createnode(int val){
    NODE new=(NODE )malloc(sizeof(NODE));
    if(new==NULL){
        printf("memory allocation failed\n");
    }
    new->data=val;
    new->rlink=new->llink=NULL;
    return new;
}
NODE insertnode(NODE root,int val){
    NODE new=createnode(val);
    if(root==NULL){
        return new;
    }
    if(val<root->data)
        root->llink=insertnode(root->llink,val);
    else
     root->rlink=insertnode(root->rlink,val);
    return root;
}
void inorder(NODE root){
    if(root!=NULL){
      inorder(root->llink);
      printf("%d\n",root->data);
      inorder(root->rlink);
    }
}
void postorder(NODE root){
    if(root!=NULL){
        postorder(root->llink);
        postorder(root->rlink);
        printf("%d\n",root->data);
    }
}
void preorder(NODE root){
    if(root!=NULL){
        printf("%d\n",root->data);
        preorder(root->llink);
        preorder(root->rlink);
    }
}
struct node *search(struct node *root,int key){
    if(root==NULL||root->data==key)
     return root;
    if(root->data<key)
     return search(root->rlink,key);
    return search(root->llink,key);
}
struct node  *minVal(struct node *node){
    struct node *curr=node;
    while(curr && curr->llink!=NULL)
     curr=curr->llink;
    return curr;
}
void freenode(NODE root){
    if(root!=NULL){
        free(root->rlink);
        free(root->llink);
        free(root);
    }
}
struct node *deletenode(struct node *root,int key){
    if(root==NULL)
    return root;
    if(key<root->data)
    root->llink=deletenode(root->llink,key);
    else if(key>root->data)
    root->rlink=deletenode(root->rlink,key);
    else{
        if(root->llink==NULL){
            struct node *temp=root->rlink;
            freenode(root);
            return temp;
        }
        else if(root->rlink==NULL){
            struct node *temp=root->llink;
            freenode(root);
            return temp;
        }
        struct node *temp=minVal(root->rlink);
        root->data=temp->data;
        root->rlink=deletenode(root->rlink,temp->data);
    }
    return root;
}

void main(){
    int ch,key,val;
    NODE *curr;
    NODE root=NULL;
    printf("\n 1.Insert\n 2.Inorder\n 3.Postorder\n 4.Preorder\n 5.Deletebykey\n ");
    while(1){
        printf("Enter your choice:");
        scanf("%d",&ch);
        switch(ch){
            case 1:printf("Enter val:");
                  scanf("%d",&val);
                  root=insertnode(root,val);
                  break;
            case 2:inorder(root);
                   break;
            case 3:postorder(root);
                   break;
            case 4:preorder(root);
                   break;
            case 5:printf("Enter key to delete\n");
                   scanf("%d",&key);
                   if(search(root,key)!=NULL){
                    root=deletenode(root,key);
                    printf("Node with %d data deleted\n",key);
                   }
                   else{
                    printf("Node of %d not found\n",key);
                   }
                   break;
            default:printf("Invalid\n");
                    break;
        }
    }
}
