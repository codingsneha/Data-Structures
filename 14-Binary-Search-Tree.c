#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
} *root =NULL;

typedef struct Node node;
int nodes = 0, count = 0, top = -1;

/*                   CONSTRUCT                  */
node *createNode (int value) {
    node *newNode = (node *) malloc ( sizeof(node) );
    newNode -> left = newNode -> right = NULL;
    newNode -> data = value;
    nodes++;
    return newNode;
}

node *insert(node *root, int value) {
    if (!root) return createNode(value);
    if (value < root -> data) root -> left = insert (root -> left, value);
    else root -> right = insert (root -> right, value);
    return root;
    nodes++;
}

/*              TRAVERSE INORDER                */
void push(node *stack[nodes], node *root) {
    stack[++top] = root;
    count++;
}

node *pop(node *stack[nodes]) {
    node *el = stack[top--];
    printf("%d ", el -> data);
    count--;
    return el;
}

void inorder() {
    if (!root) return;
    node *stack[nodes], *curr = root;
    while(count || curr) {
        if (curr) {
            push(stack, curr);
            curr = curr -> left;
        }
        else
            curr = pop(stack) -> right;
    }
}


/*              SEARCH                */
int search(node *root, int key) {
    if (!root) return 0;
    if (root -> data == key) return 1;
    else if (key < root -> data) return search(root -> left, key);
    else return search(root -> right, key);
}


/*              FIND MAX                */
node* findMax(node *root) {
    node *temp = root;
    while (temp -> right) temp = temp -> right;
    printf ("\n\nMax: %d", temp -> data);
    return temp;
}

/*              FIND MIN                */
node* findMin(node *root) {
    node *temp = root;
    while (temp -> left) temp = temp -> left;
    printf ("\n\nMin: %d", temp -> data);
    return temp;
}


/*                 DELETION                 */
node* inorderSuccesor(node *root) {
    return findMin(root -> right);
}

node* deleteNode(node *root, int key) {
    if (!root) return root;
    if (key < root -> data) root -> left = deleteNode(root -> left, key);
    else if (key > root -> data) root -> right = deleteNode(root -> right, key);
    else {
        if (!(root -> left)) {
            node *temp = root -> right;
            free(root);
            return temp;
        }
        else if (!(root -> right)) {
            node *temp = root -> left;
            free(root);
            return temp;
        }
        node *temp = inorderSuccesor(root);
        root -> data = temp -> data;
        root -> right = deleteNode(root -> right, temp -> data);
    }
    return root;
}

/*______________________________________________*/


int main() {
    root = createNode(7);
    insert(root, 2);
    insert(root, 3);
    insert(root, 5);
    insert(root, 10);
    inorder();
    printf("\n%d", search(root, 7));
    findMax(root);
    findMin(root);
    deleteNode(root, 5);
    printf("\n");
    inorder();
    return 0;
}