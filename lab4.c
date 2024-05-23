#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct Point {
    int x;
    int y;
} POINT;

double distance(POINT a, POINT b) {
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

void findClosestPair(POINT* points, int size) {
    if (size < 2) {
        printf("Need at least two points to find the closest pair.\n");
        return;
    }

    double minDist = distance(points[0], points[1]);
    int minIndex1 = 0, minIndex2 = 1;

    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            double dist = distance(points[i], points[j]);
            if (dist < minDist) {
                minDist = dist;
                minIndex1 = i;
                minIndex2 = j;
            }
        }
    }

    printf("The closest pair of points are: (%d, %d) and (%d, %d) with a distance of %.2f\n",
        points[minIndex1].x, points[minIndex1].y, points[minIndex2].x, points[minIndex2].y, minDist);
}

struct listNode {
    char data;
    struct listNode* next;
};

void insertAtHead(struct listNode** listHead, char value) {
    struct listNode* newNode = (struct listNode*)malloc(sizeof(struct listNode));
    newNode->data = value;
    newNode->next = *listHead;
    *listHead = newNode;
}

void insertAtTail(struct listNode** listHead, char value) {
    struct listNode* newNode = (struct listNode*)malloc(sizeof(struct listNode));
    newNode->data = value;
    newNode->next = NULL;

    if (*listHead == NULL) {
        *listHead = newNode;
    } else {
        struct listNode* temp = *listHead;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void delete(struct listNode** listHead, char value) {
    struct listNode* temp = *listHead;
    struct listNode* prev = NULL;

    if (temp != NULL && temp->data == value) {
        *listHead = temp->next;
        free(temp);
        return;
    }

    while (temp != NULL && temp->data != value) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) return;

    prev->next = temp->next;
    free(temp);
}

void printList(struct listNode* listHead) {
    while (listHead != NULL) {
        printf("%c -> ", listHead->data);
        listHead = listHead->next;
    }
    printf("NULL\n");
}

struct treeNode {
    int data;
    struct treeNode* leftChild;
    struct treeNode* rightChild;
};

typedef struct treeNode TreeNode;
typedef TreeNode* TreeNodePointer;

int insert(TreeNodePointer* rootPtr, int value) {
    if (*rootPtr == NULL) {
        *rootPtr = (TreeNodePointer)malloc(sizeof(TreeNode));
        (*rootPtr)->data = value;
        (*rootPtr)->leftChild = NULL;
        (*rootPtr)->rightChild = NULL;
        return 1;
    }
    
    if (value < (*rootPtr)->data) {
        return insert(&((*rootPtr)->leftChild), value);
    } else if (value > (*rootPtr)->data) {
        return insert(&((*rootPtr)->rightChild), value);
    } else {
        return 0; 
    }
}

void preorder(TreeNodePointer root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->leftChild);
        preorder(root->rightChild);
    }
}

void inOrder(TreeNodePointer root) {
    if (root != NULL) {
        inOrder(root->leftChild);
        printf("%d ", root->data);
        inOrder(root->rightChild);
    }
}

void postOrder(TreeNodePointer root) {
    if (root != NULL) {
        postOrder(root->leftChild);
        postOrder(root->rightChild);
        printf("%d ", root->data);
    }
}

void outputTree(TreeNodePointer root, int totalSpaces) {
    if (root != NULL) {
        totalSpaces += 5;
        outputTree(root->rightChild, totalSpaces);
        
        printf("\n");
        for (int i = 5; i < totalSpaces; i++) {
            printf(" ");
        }
        printf("%d\n", root->data);
        
        outputTree(root->leftChild, totalSpaces);
    }
}

int main() {
    // Part 1
    int size;
    printf("Enter the number of points: ");
    scanf("%d", &size);

    POINT* points = (POINT*)malloc(size * sizeof(POINT));

    for (int i = 0; i < size; i++) {
        printf("Enter coordinates for point %d (x y): ", i + 1);
        scanf("%d %d", &points[i].x, &points[i].y);
    }

    findClosestPair(points, size);

    free(points);
    
    // Part 2

    struct listNode* myList = NULL;

    insertAtHead(&myList, 'A');
    insertAtHead(&myList, 'B');
    insertAtTail(&myList, 'C');
    printList(myList);

    delete(&myList, 'B');
    printList(myList);

    delete(&myList, 'C');
    printList(myList);

    // Part 3

    TreeNodePointer root = NULL;

    int numbers[] = {50, 30, 20, 40, 70, 60, 80, 90, 10, 25, 35, 45, 55, 65, 75};
    for (int i = 0; i < 15; i++) {
        insert(&root, numbers[i]);
    }

    printf("Preorder traversal:\n");
    preorder(root);
    printf("\nInorder traversal:\n");
    inOrder(root);
    printf("\nPostorder traversal:\n");
    postOrder(root);
    printf("\nTree structure:\n");
    outputTree(root, 0);

    return 0;
}
