#include <iostream>
#include <string>
#include <stdio.h>
#include <fstream>

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

//3) Następnie program umożliwi wybór następujących funkcji poprzez naciśnięcieodpowiedniego przycisku na klawiaturze:

//<L> wylistowanie nazwisk, imion i wieku wszystkich studentów ​w porządku alfabetycznymoraz zamiana wszystkich liter na duże;

//<D> dodanie nowego studenta (ale nie więcej niż 20) oraz wprowadzenie wszystkich cech go
//opisujących; sprawdzone zostanie czy imię studenta znajduje się na predefiniowanej liściedopuszczalnych imion (zbiór ze słownikiem imion jako stała);

//<U> usunięcie studenta ze średnią ocen poniżej 2,5;

//<K> zakończenie programu i zapisanie bazy studentów do pliku.











