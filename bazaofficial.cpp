#include <iostream>
#include <string>
#include <stdio.h>
#include <vector>
#include <conio.h>
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

void dodawanieAll(int liczbaMax){

    vector <Osoba> studenci(20);
    int i;

for(i = 1; i < liczbaMax + 1; i++){
    cout << "podaj imie " << i << " studenta:"<< endl;
    cin >> studenci[i].imie;

    cout << "podaj nazwisko " << i << " studenta:"<< endl;
    cin >> studenci[i].nazwisko;

    cout << "podaj numer albumu " << i << " studenta:"<< endl;
    cin >> studenci[i].nrAlbumu;

    cout << "podaj srednia ocen " << i << " studenta:"<< endl;
    cin >> studenci[i].srOcen;

    cout << "podaj wiek " << i << " studenta:"<< endl;
    cin >> studenci[i].wiek;

    cout << "Twoi studenci: " << endl;
    cout << endl;

}
for(int i = 1; i < liczbaMax + 1; i++){   
cout <<"Studenci: "<< studenci[i].imie <<" "<< studenci[i].nazwisko <<" ma lat "<< studenci[i].wiek <<" numer albumu: "<< studenci[i].nrAlbumu <<" oraz srednia ocen to: "<< studenci[i].srOcen << endl;
}
}

int main(){

vector <Osoba> studenci(20);
int liczbaMax;

ograniczenie(liczbaMax);
dodawanieAll(liczbaMax);


char key = getch();
int value = key;
int nowe;

while(value != KEY_X){
    switch(getch()){
        case KEY_L : //listowanie + duza litera calych imion i nazwisk

        break;

        case KEY_D : //dodawanie ucznia > 20 uczniow w grupie/ na liscie

        break;

        case KEY_U : //usuniecie studenta ze srocen 2.5 lub mniej

        break;

        case KEY_K : //zapis aktualnego stanu

        break;
        
        default: //wyjscie
    }
}

key = getch();
value = key;



    return 0;
}