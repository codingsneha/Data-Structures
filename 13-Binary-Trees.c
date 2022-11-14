#include <stdio.h>
#include <malloc.h>

struct Node {
    int data;
    struct Node *left, *right;
} *root = NULL;

typedef struct Node node;
int nodes = 0, count = 0, top = -1;


/*__________________________________*/
/*          CONSTRUCT TREE          */
/*__________________________________*/

node *createNode (int data) {
    node *newNode = (node *) malloc (sizeof(node));
    newNode -> left = newNode -> right = NULL;
    newNode -> data = data;
    nodes++;
    return newNode;
}

void insert(node *root, int data) {
    if (root -> left) root -> right = createNode(data);
    else root -> left = createNode(data);
}



/*__________________________________*/
/*          TRAVERSE  TREE          */
/*__________________________________*/

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

void preorder() {
    if (!root) return;
    node *stack[nodes], *curr;
    push(stack, root);
    while (count) {
        curr = pop(stack);
        if (curr -> right)
            push(stack, curr -> right);
        if (curr -> left)
            push(stack, curr -> left);
    }
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

void postorder() {
    if (!root) return;
    node *stack[nodes], *curr = root, *prev = NULL;
    while (count || curr) {
        if (curr) {
            push(stack, curr);
            curr = curr -> left;
        }
        else {
            curr = stack[top];
            if (curr -> right == NULL || curr -> right == prev) {
                pop(stack);
                prev = curr;
                curr = NULL;
            }
            else curr = curr -> right;
        }
    }
}


/*          COUNT NUMBER OF NODES IN TREE       */
int countNodes(node *root) {
    if (!root) return 0;
    return 1 + countNodes(root -> left) + countNodes(root -> right);
}


/*          COUNT NUMBER OF LEAVES IN TREE       */
int countLeaves(node *root) {
    if (!root) return 0;
    if (!(root -> left) && !(root -> right)) return 1;
    else return countLeaves(root -> left) + countLeaves(root -> right);
}

/*          COUNT NUMBER OF NON-LEAVES IN TREE       */
int countNonLeaves(node *root) {
    if (!root) return 0;
    if (!(root -> left) && !(root -> right)) return 0;
    else return 1 + countNonLeaves(root -> left) + countNonLeaves(root->right);
}

/*          COUNT NUMBER OF FULL NODES IN TREE       */
int countFullNodes(node *root) {
    if (!root) return 0;
    if (!(root -> left) || !(root -> right)) return 0;
    else return 1 + countFullNodes(root -> left) + countFullNodes(root -> right);
}

/*               FIND HEIGHT OF TREE                */
int height(node *root) {
    if (!root) return 0;
    if (!(root -> left) && !(root -> right)) return 1;
    else return (1 + (height(root -> left) > height(root -> right) ? height(root -> left) : height(root -> right)));
}

int main() {
    root = createNode(1);
    insert (root, 2);
    insert (root, 3);
    insert (root -> left, 4);
    insert (root -> left, 5);
    insert (root -> right, 6);
    
    printf ("\n Preorder: ");
    preorder();
    printf ("\n Inorder: ");
    inorder();
    printf ("\n Postorder:");
    postorder();

    printf ("\n\n%d =", countNodes(root));

    printf (" %d L + ", countLeaves(root));

    printf ("%d NL", countNonLeaves(root));

    printf ("\n\nFull Nodes: %d", countFullNodes(root));

    printf ("\n\nHeight of tree: %d", countFullNodes(root));
    return 0;
}