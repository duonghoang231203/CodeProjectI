#include <iostream>
#include <string>
#include <vector>
#include <sstream>

#define MAX_NODES 100

struct TNode {
    std::string name;
    TNode* firstChild;
    TNode* nextSibling;
    TNode(const std::string& n) : name(n), firstChild(NULL), nextSibling(NULL) {}
};

std::vector<TNode*> node(MAX_NODES);
int k = 0;

TNode* makeNewNode(const std::string& in) {
    TNode* nNode = new TNode(in);
    return nNode;
}

int checkNode(const std::string& in) {
    for (int i = 0; i < k; i++) {
        if (node[i]->name == in) {
            return i;
        }
    }
    return -1;
}

void insertNewNode(const std::string& p, const std::string& c) {
    TNode* parent = NULL;
    TNode* child = NULL;

    int nump = checkNode(p);
    int numc = checkNode(c);
    if (nump != -1) {
        parent = node[nump];
    } else {
        parent = makeNewNode(p);
        node[k] = parent;
        k++;
    }
    if (numc != -1) {
        child = node[numc];
    } else {
        child = makeNewNode(c);
        node[k] = child;
        k++;
    }

    if (parent->firstChild == NULL) {
        parent->firstChild = child;
    } else {
        TNode* t = parent->firstChild;
        while (t->nextSibling != NULL) {
            t = t->nextSibling;
        }
        t->nextSibling = child;
    }
}

TNode* findNode(const std::string& in) {
    for (int i = 0; i < k; i++) {
        if (node[i]->name == in) {
            return node[i];
        }
    }
    return NULL;
}

int countnode(TNode* h) {
    TNode* p = h->firstChild;
    if (p == NULL) return 1;
    int count = 0;

    while (p != NULL) {
        count += countnode(p);
        p = p->nextSibling;
    }
    return count + 1;
}

int generation(TNode* h) {
    if (h == NULL) return 0;
    int count = 0;
    TNode* p = h->firstChild;
    while (p != NULL) {
        int k = generation(p);
        if (count < k) count = k;
        p = p->nextSibling;
    }
    return count + 1;
}

int countD(const std::string& in) {
    int num = 0;
    TNode* root = findNode(in);
    num = countnode(root) - 1;
    return num;
}

int countN(const std::string& in) {
    int num = 0;
    TNode* root = findNode(in);
    num = generation(root) - 1;
    return num;
}

int main() {
    std::vector<std::string> childName(MAX_NODES);
    std::vector<std::string> parentName(MAX_NODES);
    int i = 1;
    std::string in;
    std::getline(std::cin, in);
    if (in[in.length() - 1] == '\n') in.erase(in.length() - 1);
    std::istringstream iss(in);
    iss >> childName[0] >> parentName[0];
    node[k] = makeNewNode(parentName[0]);
    TNode* p = makeNewNode(childName[0]);
    node[k]->firstChild = p;
    k++;
    node[k] = p;
    k++;

    while (true) {
        std::getline(std::cin, in);
        if (in[0] == '*') {
            break;
        }

        if (in[in.length() - 1] == '\n') in.erase(in.length() - 1);
        std::istringstream iss(in);
        iss >> childName[i] >> parentName[i];

        insertNewNode(parentName[i], childName[i]);
        i++;
    }

    while (true) {
        std::getline(std::cin, in);
        if (in[0] == '*') {
            break;
        }

        if (in[in.length() - 1] == '\n') in.erase(in.length() - 1);
        std::istringstream iss(in);
        iss >> childName[i] >> parentName[i];

        if (childName[i][0] == 'd') {
            std::cout << countD(parentName[i]) << std::endl;
        } else {
            std::cout << countN(parentName[i]) << std::endl;
        }
        i++;
    }

    // Clean up memory by deleting nodes
    for (int i = 0; i < k; i++) {
        delete node[i];
    }

    return 0;
}

