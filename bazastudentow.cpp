#include <iostream>
#include <string>
#include <stdio.h>
#include <fstream>
#include <conio.h>

using namespace std;

struct Osoba{

    string imie;
    string nazwisko;
    int nrAlbumu;
    float srOcen;
    int wiek;
};

int main(){

fstream plik;

plik.open( "studenci.txt", ios::out | ios::app);

Osoba uczniowie[20];

for(int i = 0; i < 20; i++){
    cout << "podaj imie i nazwisko " << i+1 << " ucznia: " ;
    cin >> uczniowie[i].imie;
    cin >> uczniowie[i].nazwisko;
}

cout << endl;

for(int i = 0; i < 20; i++){
    cout << "podaj numer albumu " << uczniowie[i].imie <<" "<< uczniowie[i].nazwisko <<" ";
    cin >> uczniowie[i].nrAlbumu;
}

cout << endl;

for(int i = 0; i < 20; i++){
    cout << "podaj wiek " << uczniowie[i].imie <<" "<< uczniowie[i].nazwisko <<" ";
    cin >> uczniowie[i].wiek;
}

cout << endl;

for(int i = 0; i < 20; i++){
    cout << "podaj srednia ocen: " << uczniowie[i].imie <<" "<< uczniowie[i].nazwisko <<" ";
    cin >> uczniowie[i].srOcen;
}

cout << endl;

for(int i = 0; i < 20; i++){
plik << uczniowie[i].imie <<" "<< uczniowie[i].nazwisko <<" "<< uczniowie[i].wiek <<" "<< uczniowie[i].nrAlbumu <<" "<< uczniowie[i].srOcen << endl;
} 


plik.close();

plik.open( "studenci.txt", ios::in );


if(plik.is_open())
	{
		char wiersz[10000];

		while(plik.getline(wiersz,10000)) 
		{
			cout<< wiersz << endl;
			
		}
        cout << endl;
	}


    return 0;
}

//#define KEY_L - alfabetyczny porzadek
//#define KEY_K - zapis studentow i pliku
//#define KEY_U - usuniecie studenta z 2.5 srocen
//#define KEY_D - dodanie nowego studenta(im,nazw,wiek,sro,nralb)
//#define KEY_X - wyjscie

// char key = getch();
// iny value = key;

//while(value != KEY_X)
// switch(getch())
// case KEY_X:
//break;
// case KEY-L:
//key = getch();
//value = key;

//<L> wylistowanie nazwisk, imion i wieku wszystkich studentów ​w porządku alfabetycznym oraz zamiana wszystkich liter na duże;

//<D> dodanie nowego studenta (ale nie więcej niż 20) oraz wprowadzenie wszystkich cech go
//opisujących; sprawdzone zostanie czy imię studenta znajduje się na predefiniowanej liście dopuszczalnych imion (zbiór ze słownikiem imion jako stała);

//<U> usunięcie studenta ze średnią ocen poniżej 2.5;

//<K> zakończenie programu i zapisanie bazy studentów do pliku.











