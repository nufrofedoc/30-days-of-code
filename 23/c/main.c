#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Node{
    struct Node* left;
    struct Node* right;
    int data;
}Node;
Node* newNode(int data){
    Node* node=(Node*)malloc(sizeof(Node));
    node->left=node->right=NULL;
    node->data=data;
    return node;
}

void printGivenLevel(struct Node* root, int level);
int height(struct Node* node);

void levelOrder(Node* root) {
  int h = height(root);
  int i;
  for (i = 1; i <= h; ++i)
    printGivenLevel(root, i);
}

int height(Node* root) {
  if (root == NULL) {
    return 0;
  } else {
    int lheight = height(root->left);
    int rheight = height(root->right);

    if (lheight > rheight)
      return (lheight+1);
    else
      return (rheight+1);
  }
}

void printGivenLevel(Node* root, int level) {
  if (root == NULL)
    return;
  if (level == 1) {
    printf("%d ", root->data);
  } else if (level > 1) {
    printGivenLevel(root->left, level-1);
    printGivenLevel(root->right, level-1);
  }
}

Node* insert(Node* root,int data){
    if(root==NULL)
        return newNode(data);
    else{
        Node* cur;
        if(data<=root->data){
            cur=insert(root->left,data);
            root->left=cur;                
        }
        else{
            cur=insert(root->right,data);
            root->right=cur;
        }
        
    }
    return root;
}
int main(){
    Node* root=NULL;
    int T,data;
    scanf("%d",&T);
    while(T-->0){
        scanf("%d",&data);
        root=insert(root,data);
    }
    levelOrder(root);
    return 0;
    
}
