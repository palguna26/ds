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
void search(NODE root,int key){
    NODE temp = root;
    NODE prev = NULL;
    while(temp != NULL){
        if(temp->data == key){
            if(prev == NULL){
                printf("%d is present as root in the Binary Search Tree\n", key);
                return;
            }
            printf("%d found in Binary Search Tree as child of element %d\n ", key, prev->data);
            return;
        }else{
            prev = temp;
            if(temp->data > key){
                temp = temp->llink;
            }else{
                temp = temp->rlink;
            }
        }
    }
    printf("element %d not found\n", key);
}
int countnode(NODE root){
    if(root==NULL){
    return 0;
    }
    int lcnt=countnode(root->rlink);
    int rcnt=countnode(root->llink);
    return (1+lcnt+rcnt);
}
int depth(NODE root){
    if(root==NULL){
    return 0;}
    else{
    int rheight=depth(root->rlink);
    int lheight=depth(root->llink);
    if(rheight>lheight){
        return (rheight+1);
    }
    else{
    return (lheight+1);
    }
    }
}
void largestnode(NODE root){
    if(root==NULL){
        printf("Node empty\n");
        return;
    }
    NODE temp=root;
    NODE prev=NULL;
    while(temp!=NULL){
        if(temp->rlink==NULL && prev==NULL){
            printf("%d is maximum key value node and it is a parent node\n",temp->data);
            return;
        }
        if(temp->rlink == NULL){
            printf("%d is the node with maximum value with %d being a parent node\n", temp->data,prev->data);
            return;
        }else{
            prev=temp;
            temp = temp->rlink;
        }
    }
}
void main(){
    int ch,count=0,key,height=0,val;
    NODE *curr;
    NODE root=NULL;
    printf("\n 1.Insert\n 2.Inorder\n 3.Postorder\n 4.Preorder\n 5.Search\n 6.Countnoofnodes\n 7.height\n 8.Maximum key value node\n ");
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
            case 5:printf("Enter key\n");
                   scanf("%d",&key);
                   search(root,key);
                   break;
            case 6:count=countnode(root);
                   printf("%d elements are found\n",count);
                   break;
            case 7:height=depth(root);
                   printf("%d is the height of the tree\n",height);
                   break;
            case 8:largestnode(root);
                   break;
            default:printf("Invalid\n");
                    break;
        }
    }
}
