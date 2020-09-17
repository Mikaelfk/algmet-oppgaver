#include <iostream>
using namespace std;

void bytt(int & tall1, int & tall2);
void display(const int arr[], const int n);
void permuter(int arr[], const int i, const int n);
bool rettPerm(int arr[], int n);
void roterVenstre(int arr[], const int i, const int n);


const int N = 10;
/**
 *  Bytter om to referanseoverf�rte variables innhold.
 *
 *  @param   tall1  -  Verdien som skal byttes med 'tall2' (referanseoverf�rt)
 *  @param   tall2  -  Verdien som skal byttes med 'tall1' (referanseoverf�rt)
 */
void bytt(int & tall1, int & tall2) {
    int temp = tall1;           //  Midlertidig (temporary) unnalagring.
    tall1 = tall2;
    tall2 = temp;
}


/**
 *  Skriver ut HELE arrayen 'arr' sitt innhold.
 *
 *  @param   arr  -  Arrayen som f�r hele sitt innhold skrevet ut
 *  @param   n    -  Antall elementer i arrayen (siste indeks brukt er n-1)
 */
void display(const int arr[], const int n) {
    for (int i = 0;  i < n;  i++)
        cout << ' ' << arr[i];
    cout << '\n';
}


/**
 *  Genererer rekursivt ALLE mulige permutasjoner av innholdet i 'arr'.
 *
 *  @param   arr  -  Arrayen som skal permuteres
 *  @param   i    -  Indeksen som ALLE ETTERF�LGENDE verdier skal flyttes til
 *  @param   n    -  Antall elementer i arrayen (siste indeks brukt er n-1)
 *  @see     bytt(...)
 *  @see     display()
 *  @see     roterVenstre(...)
 */
void permuter(int arr[], const int i, const int n) {
    if (i == n-1 && arr[i]-arr[i-1] != 1  &&  arr[i-1]-arr[i] != 1) {
        //  N�dd en ny permutasjon:
        display(arr, n);                //  Skriver ut arrayens innhold.
    }
    else {                              //  Skal permutere:
        if (i == 0  ||  (arr[i]-arr[i-1] != 1  &&  arr[i-1]-arr[i] != 1))
        permuter(arr, i+1, n);          //  Beholder n�v�rende nr.'i'.
                                            //    Permuterer resten.
        for (int t = i+1;  t < n;  t++) {
            bytt(arr[i], arr[t]);       //  Bytter nr.'i' etter tur med
                                            //    ALLE de andre etterf�lgende.
            if (i == 0  ||  (arr[i]-arr[i-1] != 1  &&  arr[i-1]-arr[i] != 1))
            permuter(arr, i+1, n);      //  For hver av ombyttene: permuterer
            //bytt(arr[t], arr[i]);
        }                               //     resten av de etterf�lgende.
        roterVenstre(arr, i, n);        //  Gjenoppretter opprinnelig array!!!
    }
}


bool rettPerm(int arr[], int n) {
    for(int i = 0; i < n; i++) {
        if(i == 0) {
            if((arr[i] + 1) == arr[i+1]) {
                return false;
            }
        } else if(i == n-1) {
            if((arr[i] - 1) == arr[i-1]) {
                return false;
            }
        } else {
            if ((arr[i] + 1) == arr[i + 1] || (arr[i] - 1) == arr[i - 1]) {
                return false;
           }
        }
    }
    return true;
}

/**
 *  Venstreroterer en array innhold.
 *
 *  @param   arr  -  Arrayen som f�r (deler av) sitt innhold venstrerotert
 *  @param   i    -  Laveste indeks som skal venstreroteres
 *  @param   n    -  'n-1' er h�yeste indeks som venstreroteres
 */
void roterVenstre(int arr[], const int i, const int n) {
    int venstreVerdi = arr[i];            //  Tar vare p� f�rste.
    for (int k = i + 1; k < n; k++)       //  Roterer (flytter alle ned
        arr[k - 1] = arr[k];                //     ETT hakk/indeks).
    arr[n - 1] = venstreVerdi;              //  Legger f�rste inn bakerst.
}


int main() {
    int array[N];                    //  Array som skal permuteres.

    for (int i = 0; i < N; i++)      //  Fyller array med: 1, 2, 3, ..., N
        array[i] = i + 1;

    permuter(array, 0, N);           //  Lager (og skriver) permutasjoner av
    //    ALLE arrayelementene.
    cout << '\n';
    display(array, N);       //  Skriver array etter at ferdig
    //    (for � vise at origisnal er gjenopprettet).

    cout << "\n\n";
    return 0;
}