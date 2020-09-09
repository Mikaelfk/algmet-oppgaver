#include <iostream>
using namespace std;

struct Node  {
    char ID; //  Nodens ID/key/navn (en bokstav).
    int  nivaa; //  Nodens nivå i treet ift. rotnoden.
    Node* left; //  Peker til venstre subtre, evt nullptr.
    Node* right; //  Peker til høyre subtre, evt nullptr.
    Node() {
        ID = '-';
        nivaa = 0;
        left = right = nullptr;
    }
};


void settNivaa(Node* node);
Node* generate(const int depth, const int probability);
void traverse(Node* node);
void besok(Node* node);
void finnVerdier(Node* node, int& sumNivaa, int& antall);
void skrivForfedre(Node* node);


Node* gRoot = nullptr;
int   gNumber = 65;



Node* generate(const int depth, const int probability) {
    Node* rot = nullptr;                   //  Peker til det som returneres.
    //  NB: Initieres til 'nullptr'!
    if (depth > 0) {                       //  Kan fortsatt legge til et nivå:
        if (rand() % 100 < probability) {  //  Trukket tall i rett intervall:
            rot = new Node;                //  Lager en ny node.
            rot->left = generate(depth-1, probability); //Lager evt v.subtre.
            rot->ID = static_cast <char> (gNumber++);  //  Legger inn egen ID.
            rot->right = generate(depth-1, probability); //Lager evt h.subtre.
        }
    }
    return rot;                     //  Returnerer generert tre eller nullptr.
}

void traverse(Node* node) {
    if (node) {
        traverse(node->left);
        besok(node);
        traverse(node->right);
    }
}

void besok(Node* node) {       //  Viser innholdet i EN node.
    cout << ' ' << node->ID << ":  " << node->nivaa << '\n';
}

void settNivaa(Node* node) {
    if (node) {
        if (node->left) {
            node->left->nivaa = node->nivaa + 1;
        }
        if (node->right) {
            node->right->nivaa = node->nivaa + 1;
        }
        settNivaa(node->left);
        settNivaa(node->right);
    }
}


void finnVerdier(Node* node, int& sumNivaa, int& antall) {
    if(node) {
        sumNivaa += node->nivaa;
        antall++;
        if(node->left) {
            finnVerdier(node->left, sumNivaa, antall);
        }
        if(node->right) {
            finnVerdier(node->right, sumNivaa, antall);
        }
    }
}

void skrivForfedre(Node* node) {
    if(node) {
        if(!node->left && !node->right) {
            Node* q = gRoot;
            cout << endl;
            bool finished = false;
            while(!finished) {
                cout << q->ID;
                if(q != node) {
                    if (q->ID < node->ID) {
                        q = q->right;
                    } else if (q->ID > node->ID) {
                        q = q->left;
                    }
                    cout << " ";
                } else {
                    finished = true;
                }
            }
        }
        skrivForfedre(node->left);
        skrivForfedre(node->right);
    }
}


int main() {
    int sumNiva = 0,
    antall = 0;
    srand(0);

    gRoot = generate(4, 80);      //      80% sjanse for å lage et subtre)

    cout << "\n\nTester oppgave A - Nodene etter at 'nivaa' er satt:\n";
    settNivaa(gRoot);             //  Setter ALLE nodenes nivå.
    traverse(gRoot);

    cout << "\n\nTester oppgave B - Finner nivåer TOTALT og antall noder:\n";
    finnVerdier(gRoot, sumNiva, antall);
    cout << "Totalt nivåer: " << sumNiva << endl << "Totalt antall noder: " << antall << endl;
    cout << "Gjennomsnittlig nivå: " << static_cast<float>(sumNiva) /antall << endl;

    cout << endl;
    skrivForfedre(gRoot);
    return 0;
}