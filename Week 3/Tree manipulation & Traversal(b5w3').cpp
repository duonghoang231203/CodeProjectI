#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct TNode {
    int label;
    struct TNode* firstChild;
    struct TNode* nextSibling;
};

struct TNode* makeNewNode(int label) {
    struct TNode* nNode = (struct TNode*)malloc(sizeof(struct TNode));
    nNode->label = label;
    nNode->firstChild = NULL;
	nNode->nextSibling = NULL;
    return nNode;
}

struct TNode* findNodeWithLabel(struct TNode* root, int v) {
    if (root == NULL) {
        return NULL;
    }

    if (root->label == v) {
        return root;
    }

    struct TNode* result = findNodeWithLabel(root->firstChild, v);

    if (result != NULL) {
        return result;
    }

    return findNodeWithLabel(root->nextSibling, v);
}

void insertNewNode(struct TNode* root, int v, struct TNode* nNode) {
    struct TNode* parent = findNodeWithLabel(root, v);

    if (parent != NULL) {
        if (parent->firstChild == NULL) {
            parent->firstChild = nNode;
        } else {
            struct TNode* p = parent->firstChild;
            while (p->nextSibling != NULL) {
                p = p->nextSibling;
            }
            p->nextSibling = nNode;
        }
    }
}

void preOrderTravel(struct TNode* root) {
    if (root == NULL) {
        return;
    }
    printf("%d ", root->label);

    struct TNode* p = root->firstChild;
    while (p != NULL) {
        preOrderTravel(p);
        p = p->nextSibling;
    }
}

void inOrderTravel(struct TNode* root) {
    if (root == NULL) {
        return;
    }
    struct TNode *t = root->firstChild;
    inOrderTravel(t);
    printf("%d ", root->label);
    if (t != NULL) {
    	t = t->nextSibling;
	}
	while(t != NULL) {
		inOrderTravel(t);
		t = t->nextSibling;
	}
    
    
}


void postOrderTravel(struct TNode* root) {
    if (root == NULL) {
        return;
    }

    struct TNode* p = root->firstChild;
    while (p != NULL) {
        postOrderTravel(p);
        p = p->nextSibling;
    }
    printf("%d ", root->label);
}

int main() {
    struct TNode* root = NULL;
    char action[20];
    int u, v;

    while (1) {
        scanf("%s", action);

        if (strcmp(action, "MakeRoot") == 0) {
            scanf("%d", &u);
            root = makeNewNode(u);
        } else if (strcmp(action, "Insert") == 0) {
            scanf("%d %d", &u, &v);
            struct TNode* nNode = makeNewNode(u);
            insertNewNode(root, v, nNode);
        } else if (strcmp(action, "PreOrder") == 0) {
            preOrderTravel(root);
            printf("\n");
        } else if (strcmp(action, "InOrder") == 0) {
            inOrderTravel(root);
            printf("\n");
        } else if (strcmp(action, "PostOrder") == 0) {
            postOrderTravel(root);
            printf("\n");
        } else if (strcmp(action, "*") == 0) {
            break;
        }
    }

    return 0;
}
