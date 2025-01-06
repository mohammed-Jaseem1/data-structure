#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left;
    struct node *right;
};

struct node* insert(struct node*, int);
struct node* delete(struct node*, int);
struct node* search(struct node*, int);
void display(struct node*);

int main() {
    struct node* start = NULL; 
    int opt, data;
    do {
        printf("\n1.Insert\n2.Delete\n3.Search\n4.Display\n5.Exit\nEnter your choice: ");
        scanf("%d", &opt);
        switch(opt) {
            case 1:
                printf("Enter the data: ");
                scanf("%d", &data);
                start = insert(start, data);
                break;
            case 2:
                printf("Enter the data to be deleted: ");
                scanf("%d", &data);
                start = delete(start, data);
                break;
            case 3:
                printf("Enter the element to be searched: ");
                scanf("%d", &data);
                if (search(start, data) == NULL)
                    printf("Item not found\n");
                else
                    printf("Item found\n");
                break;
            case 4:
                display(start);
                printf("\n");
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid option. Please try again.\n");
        }
    } while(1);
}

// Insert a node at the beginning of the list
struct node* insert(struct node* s, int item) {
    struct node* t = (struct node*)malloc(sizeof(struct node));
    t->data = item;
    t->left = NULL; 
    t->right = s;   

    if (s != NULL) {
        s->left = t;
    }

    return t; 
}

// Delete a node from the list
struct node* delete(struct node* s, int item) {
    if (s == NULL) {
        printf("List is empty\n");
        return NULL;
    }

    struct node *t = search(s, item);
    if (t == NULL) {
        printf("Item not found\n");
        return s;
    }

    // Case 1: Node to be deleted is the only node in the list
    if (t->left == NULL && t->right == NULL) {
        free(t);
        return NULL;
    }

    // Case 2: Node to be deleted has only a right child
    if (t->left == NULL) {
        s = t->right;  // Update the head of the list
        s->left = NULL;
    }
    // Case 3: Node to be deleted has only a left child
    else if (t->right == NULL) {
        if (t == s) {
            s = t->left;  // If the node to delete is the head
        } else {
            t->left->right = NULL;
        }
    }
    // Case 4: Node to be deleted has both left and right children
    else {
        t->left->right = t->right;
        t->right->left = t->left;
    }

    printf("Deleted value: %d\n", t->data);
    free(t);

    return s;
}

// Search for a node in the list
struct node* search(struct node* s, int item) {
    while (s != NULL && s->data != item) {
        s = s->right;
    }
    return s;
}

// Display all nodes in the list
void display(struct node* s) {
    if (s == NULL) {
        printf("The list is empty\n");
        return;
    }
    while (s != NULL) {
        printf("%d\t", s->data);
        s = s->right;
    }
    printf("\n");
}

