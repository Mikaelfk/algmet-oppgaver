#include <iostream>
using namespace std;

const int N = 10;
const int square = 1;
const int visited = 2;
int brett[N+2][N+2] =
        { { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
          { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0 },
          { 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 1, 0 },
          { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
          { 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0 },
          { 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0 },
          { 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0 },
          { 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0 },
          { 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0 },
          { 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0 },
          { 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0 },
          { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } };


void visitGroup(int x, int y, int & antall) {
    if(brett[x][y] == square) {
        antall++;
        brett[x][y] = visited;
        cout << " (" << x << ',' << y << ')';
        visitGroup(x, y+1, antall);
        visitGroup(x+1, y, antall);
        visitGroup(x, y-1, antall);
    }
}

int main() {
    int antallGrupper = 0, antallIEnGruppen;   //  De to opptellingene.

    for (int i = 1; i <= N; i++)       //  Traverserer HELE brettet,
        for (int j = 1; j <= N; j++)   //  ALT på en og en linje nedover:
            if (brett[i][j] == square) {  //  Funnet "starten" på en gruppe:
                //  Teller opp at funnet en ny gruppe:
                cout << "\nGruppe nr. " << ++antallGrupper
                     << " bestar av ruten(e):\n\t";
                antallIEnGruppen = 0;  //  Nullstiller antallet i gruppen.
                //  Besøker RESTEN av gruppen!!!:
                visitGroup(i, j, antallIEnGruppen);
                //  Skriver referanseoverført variabel:
                cout << "\n\tAntall i gruppen: " << antallIEnGruppen;
            }

    cout << "\n\n";
    return 0;
}
