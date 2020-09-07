#include <iostream>
using namespace std;

struct Node {
    char ID;
    Node *left, *right;
    bool visited = false;
    Node(char id) {
        ID = id;
        left = right = nullptr;
    };
};

int counter = 0;


Node* buildTree();
int findMax(int a, int b);
void internalNodes(Node* node);
void pointerToNull(Node* node);
void fullNodes(Node* node);
int treeHeight(Node* node);

Node* buildTree() {
/*   Bygger treet:                                     A
                                              /                 \
                                         B                          C
                                    /         \                  /
                                  D             E              F
                              /       \           \          /
                            G           H           I      J
                              \        / \         /        \
                               K      L   M       N          O
*/
    Node*  noder[15];
    for (int i = 0; i < 15; i++)
        noder[i] = new Node(static_cast <char> ('A' + i));

    noder[0]->left = noder[1];  noder[0]->right = noder[2];
    noder[1]->left = noder[3];  noder[1]->right = noder[4];
    noder[2]->left = noder[5];
    noder[3]->left = noder[6];  noder[3]->right = noder[7];
    noder[4]->right = noder[8];
    noder[5]->left = noder[9];
    noder[6]->right = noder[10];
    noder[7]->left = noder[11]; noder[7]->right = noder[12];
    noder[8]->left = noder[13];
    noder[9]->right = noder[14];
    return noder[0];
}

int findMax(int a, int b) {
    if(a>= b) {
        return a;
    } else {
        return b;
    }
}

void internalNodes(Node* node) {
    if (node) {
    internalNodes(node->left);
    internalNodes(node->right);
    if(node->left || node->right) counter++;
    }
}

void pointerToNull(Node* node) {
    if (node) {
        pointerToNull(node->left);
        pointerToNull(node->right);
        if(!node->left) counter++;
        if(!node->right) counter++;
    }
}

void fullNodes(Node* node) {
    if(node) {
        fullNodes(node->left);
        fullNodes(node->right);
        if(node->left && node->right) counter++;
    }
}

int maxHeight = 0;

int treeHeight(Node* node) {
    if (!node) {
        return 0;
    }
    return findMax(treeHeight(node->left), treeHeight(node->right)) + 1;
}

void treeHeight2(Node* node) {
    if(node) {
        counter++;
        treeHeight2(node->left);
        treeHeight2(node->right);
        if(counter > maxHeight) maxHeight = counter;
        counter--;
    }
}


int main() {
    Node *root = buildTree();
    internalNodes(root);
    cout << "Antall interne noder: " << counter << endl;
    counter = 0;

    pointerToNull(root);
    cout << "Antall peker till nullptr: " << counter << endl;
    counter = 0;

    fullNodes(root);
    cout << "Antall fulle noder: " << counter << endl;
    counter = 0;

    cout << "levels: " << treeHeight(root) << endl;
    counter = 0;

    treeHeight2(root);
    cout << "levels 2: " << maxHeight << endl;
    return 0;
}
