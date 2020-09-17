

#include <iostream>          //  cout
#include <string>            //  string
#include <cstdlib>           //  (s)rand
using namespace std;


const int N = 9;            ///<  Antall elementer i array som skal sorteres.


void display(const char arr[], const int n);
void shellSort(char arr[], const int n);

/**
 *  Hovedprogrammet:
 */
int main() {
    char array[N+1];               //  Array som skal sorteres.
    //  Bruker indeksene 1-N
    //    da det ligger SENTINEL KEY
    //    (STOPPVERDI) i element nr.0 !!!

    srand(0);                      //  Brukes ifm. tilfeldighet/randomisering.

    array[0] = ' ';                //  Legger inn SENTINEL KEY !!!
    array[1] = 's';
    array[2] = 'u';
    array[3] = 'm';
    array[4] = 'p';
    array[5] = 's';
    array[6] = 'v';
    array[7] = 'a';
    array[8] = 'm';
    array[9] = 'p';
    cout << "\n\nArrayen F�R sortering:\n\t";
    display(array, N+1);           //  Skriver array F�R sortering.


    shellSort(array, N+1);         //  SHELLSORT SORTERER !!!


    cout << "\n\nArrayen ETTER SHELLSORT sortering:\n\t";
    display(array, N+1);           //  Skriver array ETTER sortering.

    cout << "\n\n";
    return 0;
}



/**
 *  Skriver ut HELE arrayen 'arr' sitt innhold.
 *
 *  @param   arr  -  Arrayen som f�r hele sitt innhold skrevet ut
 *  @param   n    -  Antall elementer i arrayen (siste indeks brukt er n-1)
 */
void display(const char arr[], const int n) {
    for (int i = 1;  i < n;  i++)
        cout << arr[i];
    cout << '\n';
}


/**
 *  Sorterer en char-array STIGENDE med SHELLSORT.
 *
 *  @param   arr  -  Arrayen som skal sorteres
 *  @param   n    -  Antall elementer i arrayen 'arr'
 *  @see     skriv(...)
 */
void shellSort(char arr[], const int n) {
    int  i, j, h;                   //  L�kkevariable.
    char verdi;                     //  Verdien/elementet som evt. skal
    //    flyttes bakover i subarrayen.
    for (h = 1;  h <= n/9;  h = (3*h)+1)  ;  //  NB: Tom for-l�kke !!!
    //  Dvs. 'h' = 1, 4, 13, 40, 121, 364, ...
    //  Her: 21/9 = 2,  da blir 'h' lik 4 !!!
    //  Ved 36 elementer eller LITT flere:
    //    36/9 = 4, DA blir h lik 13.
    while (h > 0)  {                //  S� lenge det finnes subarrayer:

        for (i = h+1;  i < n;  i++) {   //  G�r gjennom subarrayene:
            verdi = arr[i];    //  Den som evt. skal flyttes innen subarrayen.
            j = i;             //  Initierer til aktuelt element.

            //  S� lenge er en i subarrayen 'h' plasser
            //    lengre nede/tidligere og denne er st�rre:
            while (j > h  &&  arr[j-h] > verdi) {

                arr[j] = arr[j-h]; // Flytter den opp 'h' plasser.
                j -= h;            // Indeks blir den 'h' plasser lengre nede.

            }

            arr[j] = verdi;        //  Smetter p� plass der 'j' har stanset.

            cout << "H: " << h << " ";
            cout << "I: "<< i << " ";

            for(int k = 1; k < n; k++) {
                if(k == i) {
                    cout << static_cast<char>(arr[k]-32);
                } else if(k == j) {
                    cout << static_cast<char>(arr[k]-32);
                } else {
                    cout << arr[k];
                }
            }
            cout << "\n";
        }
        h /= 3;               //  'h' minskes til en 1/3-del for hver looping.
    }
}

