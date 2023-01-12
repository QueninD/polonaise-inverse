#include <iostream>
#include <cstdlib>
using namespace std;

const int TailleMax = 100;
int pile [TailleMax];
int top = -1;

bool PileVide() {
    return top == -1;
}

bool Complet() {
    return top == TailleMax - 1;
}

void push(int item) {
    if (Complet()) {
        cout << "Erreur : Pile Complete" << endl;
        return;
    }
    top++;
    pile[top] = item;
}

int pop() {
    if (PileVide()) {
        cout << "Erreur : Pile vide" << endl;
        return -1;
    }
    int item = pile[top];
    top--;
    return item;
}

bool Verif(char c) {
    return c >= '0' && c <= '9';
}

int Operateur(int op1, int op2, char operation) {
    switch(operation) {
        case '+': return op1 + op2;
        case '-': return op1 - op2;
        case '*': return op1 * op2;
        case '/': 
            if (op2 == 0) {
                cout << "Erreur : Division par 0 impossible" << endl;
                return -1;
            }
            return op1 / op2;
        default: 
            cout << "Erreur : Opération non valide" << endl;
            return -1;
    }
}

int expression(string input) {
    for (unsigned int i = 0; i < input.size(); i++) {
        if (input[i] == ' ') {
            continue;
        }
        if (Verif(input[i])) {
            int calcul = 0;
            while (i < input.size() && Verif(input[i])) {
                calcul = (calcul*10) + (input[i] - '0');
                i++;
            }
            push(calcul);
        } else {
            int op2 = pop();
            int op1 = pop();
            int resultat = Operateur(op1, op2, input[i]);
            push(resultat);
        }
    }
    return pop();
}

int main() {
    cout << "Entrez un calcul qui sera fait par notation polonaise inverse : ";
    string input;
    getline(cin, input);
    int resultat = expression(input);
    cout << "résultat du calcul : " << resultat << endl;
    return 0;
}
