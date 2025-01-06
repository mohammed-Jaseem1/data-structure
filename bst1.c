#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;
    struct node *left;
    struct node *right;
};
struct node *insert(struct node *bst, int data);
void display(struct node *bst);
struct node *search(struct node *bst, int data);
struct node *delete(struct node *bst, int data);
struct node *minValueNode(struct node *node);
int main() {
    struct node *root = NULL;
    int opt, data;
    do {
        printf("\n 1. Insert \n 2. Search \n 3. Delete \n 4. Display \n 5. Exit\n Enter your option: ");
        scanf("%d", &opt);
        switch (opt) {
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                root = insert(root, data);
                break;
            case 2:
                printf("Enter data: ");
                scanf("%d", &data);
                if (search(root, data) == NULL)
                    printf("Not found\n");
                else
                    printf("Found\n");
                break;
            case 3:
                printf("Enter data: ");
                scanf("%d", &data);
                root = delete(root, data);
                break;
            case 4:
            if(root==NULL)
            printf("empty root");
            else                 
                display(root);               
                printf("\n");
                break;
            case 5:
                exit(0);
        }
    } while (1);
   return 0;
}
void display(struct node *bst) {
    if (bst != NULL) {
        display(bst->left);
        printf("%d\t", bst->data);
        display(bst->right);
    }
}
struct node *insert(struct node *bst, int data) {
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    if (bst == NULL) {
        return newNode;  
    }
    struct node *current = bst;
    struct node *parent = NULL;
    while (current != NULL) {
        parent = current;
        if (data < current->data) {
            current = current->left;
        } else if (data > current->data) {
            current = current->right;
        } else {
            printf("Duplicate node detected. Insertion aborted.\n");
            free(newNode);  
            return bst;  
        }
    }
        if (data < parent->data) {
        parent->left = newNode;
    } else {
        parent->right = newNode;
    }
    return bst;
}
struct node *search(struct node *bst, int data) {
    while (bst != NULL) {
        if (data < bst->data) {
            bst = bst->left;
        } else if (data > bst->data) {
            bst = bst->right;
        } else {
            return bst;  
        }
    }
    return NULL;  
}
struct node *minValueNode(struct node *node) {
    struct node *current = node;
    while (current && current->left != NULL) {
        current = current->left;
    }
    return current;
}
struct node *delete(struct node *bst, int data) {
    if (bst == NULL) {
        printf("Node not found.\n");
        return bst;
    }
    if (data < bst->data) {
        bst->left = delete(bst->left, data);
    } else if (data > bst->data) {
        bst->right = delete(bst->right, data);
    } else {    
        if (bst->left == NULL) {
            struct node *temp = bst->right;
            free(bst);
            return temp;
        } else if (bst->right == NULL) {
            struct node *temp = bst->left;
            free(bst);
            return temp;
        }        
        struct node *temp = minValueNode(bst->right);
                bst->data = temp->data;
        bst->right = delete(bst->right, temp->data);
    }
    return bst;
}
