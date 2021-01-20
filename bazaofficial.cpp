#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>
#include <iterator> // wskaznik na okreslony element vectora

using namespace std;

#define KEY_L 76 //- alfabetyczny porzadek
#define KEY_K 75 //- zapis studentow i pliku
#define KEY_U 85 //- usuniecie studenta z 2.5 srocen
#define KEY_D 68 //- dodanie nowego studenta(im,nazw,wiek,sro,nralb)
#define KEY_X 88 //- wyjscie

struct Osoba{

    string imie;
    string nazwisko;
    int nrAlbumu;
    float srOcen;
    int wiek;
    bool operator < (const Osoba &x)const
    {
        return imie>x.imie;
        return nazwisko>x.nazwisko;
    }
};

void ograniczenie(int &liczbaMax){
cout << "Ilu studentow chcesz dodac(nie wiecej niz 20)?" << endl;
cin >> liczbaMax;

if(liczbaMax > 20 ){
    cout << endl;
    cout << "nie moze byc wieksza niz 20!" << endl;
    cout << "popraw sie: " << endl;
    cin >> liczbaMax;
}
}

void dodawanie(int liczbaMax){

    vector <Osoba> studenci(20);
    int i;

for(i = 1; i < liczbaMax + 1; i++){
    cout << "podaj imie " << i << " studenta:"<< endl;
    cin >> studenci[i].imie;
}
}

int main(){

vector <Osoba> studenci(20);
int liczbaMax;

ograniczenie(liczbaMax);
dodawanie(liczbaMax);

    return 0;
}