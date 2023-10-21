#include<iostream>
#include <sstream>

using namespace std;

struct Node {
	int id;
	Node* left;
	Node* right;
};

Node* makeNode(int id){
	Node* nNode = new Node;
	nNode->id = id;
	nNode->left = NULL;
	nNode->right = NULL;
	return nNode;
}

Node* findNode(Node* root, int v){
	if(root == NULL || root->id == v){
		return NULL;
	}
	if((root->id > v) && (root->left == NULL)){//chua hieu lam
		return root;
	}
	else if((root->id < v) && (root->right == NULL)){//cung the
		return root;
	}
	else if(v < root->id){
		return findNode(root->left, v);
	} else {
		return findNode(root->right, v);
	}
}

void insertNode(Node* root, int v){
	if(root == NULL) return;
	
	Node* parent = findNode(root, v);
	if(parent == NULL) return;
	if(v < parent->id){
		parent->left = makeNode(v);
	} else {
		parent->right = makeNode(v);
	}
}

void preOrder(Node* root) {
    if (root == NULL) {
        return;
    }
    cout << root->id << " ";
	preOrder(root->left);
	preOrder(root->right);
}

int main() {
    string action;
    int v;
    
    getline(std::cin, action);
    std::istringstream iss(action);
	std::string dummy;
	iss >> dummy >> v;
    Node* root = makeNode(v);

    while (true) {
        getline(cin, action);
        if (action[0] == '#') {
            break;
        }
        sscanf(action.c_str(), "%*s %d", &v);
        insertNode(root, v);
    }

    preOrder(root);

    return 0;
}
