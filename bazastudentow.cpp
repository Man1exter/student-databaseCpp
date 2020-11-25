#include <iostream>
#include <string>
#include <stdio.h>
#include <fstream>
#include <conio.h>
#include <algorithm>

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
};


int main(){

fstream plik;

plik.open( "studenci.txt", ios::out | ios::app);

Osoba uczniowie[20]{};

for(int i = 0; i < 5; i++){
    cout << "podaj imie i nazwisko " << i+1 << " ucznia: " ;
    cin >> uczniowie[i].imie;
    cin >> uczniowie[i].nazwisko;
}

cout << endl;

for(int i = 0; i < 5; i++){
    cout << "podaj numer albumu " << uczniowie[i].imie <<" "<< uczniowie[i].nazwisko <<" ";
    cin >> uczniowie[i].nrAlbumu;
}

cout << endl;

for(int i = 0; i < 5; i++){
    cout << "podaj wiek " << uczniowie[i].imie <<" "<< uczniowie[i].nazwisko <<" ";
    cin >> uczniowie[i].wiek;
}

cout << endl;

for(int i = 0; i < 5; i++){
    cout << "podaj srednia ocen: " << uczniowie[i].imie <<" "<< uczniowie[i].nazwisko <<" ";
    cin >> uczniowie[i].srOcen;
}

cout << endl;

for(int i = 0; i < 5; i++){
plik << uczniowie[i].imie <<" "<< uczniowie[i].nazwisko <<" ma lat "<< uczniowie[i].wiek <<" numer albumu: "<< uczniowie[i].nrAlbumu <<" oraz średnia ocen to: "<< uczniowie[i].srOcen << endl;
} 

for(int i = 0; i < 5; i++){
cout << uczniowie[i].imie <<" "<< uczniowie[i].nazwisko <<" ma lat "<< uczniowie[i].wiek <<" numer albumu: "<< uczniowie[i].nrAlbumu <<" oraz średnia ocen to: "<< uczniowie[i].srOcen << endl;
} 

cout << "Wprowadziles dane studentow do bazdy danych!" << endl;

cout << "          MENU LISTY UCZNIOW:       " << endl;
cout << "------------------------------------------" << endl;
cout << "..(K).. - Zapis aktualnego stanu.." << endl;
cout << "..(L).. - Listowanie Listy alfabetycznie.." << endl;
cout << "..(U).. - Usuniecie studenta ze sr.ocen 2.5.." << endl;
cout << "..(D).. - Dodanie nowego studenta i jego cech(imie,nazwisko,wiek,srOcen,nrAlbumu) nie wiecej niz 20 uczniow.." << endl;
cout << "..(X).. - Wyjscie z programu.." << endl;
cout << "------------------------------------------" << endl;
cout << "Podaj znak(w ramce) do wywołania danej metody na liscie studentow/uczniow.."<<endl;

char key = getch();
int value = key;


while(value != KEY_X){
    switch(getch()){
        case KEY_L : //listowanie + duza litera pierwsza

for(int i = 0; i < 5; i++){
cout <<"Przed sortowaniem: "<< uczniowie[i].imie <<" "<< uczniowie[i].nazwisko <<" ma lat "<< uczniowie[i].wiek <<" numer albumu: "<< uczniowie[i].nrAlbumu <<" oraz średnia ocen to: "<< uczniowie[i].srOcen << endl;
} 

cout << endl;

sort(uczniowie,uczniowie+20);


cout << endl;


for(int i = 0; i < 5; i++){
cout <<"Po sortowaniu: "<< uczniowie[i].imie <<" "<< uczniowie[i].nazwisko <<" ma lat "<< uczniowie[i].wiek <<" numer albumu: "<< uczniowie[i].nrAlbumu <<" oraz średnia ocen to: "<< uczniowie[i].srOcen << endl;
} 


        cout << "Nazwiska zostały wylistowane!" << endl;

        break;
    

        case KEY_D : //dodawanie

        cout<<endl;

        break;

        case KEY_U : //usuniecie

        cout<<endl;

        break;

        case KEY_K : //zapis

        cout<<endl;

        break;
        
        default: //wyjscie
        exit(1);
    }
}

key = getch();
value = key;


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












