#include <iostream>
#include <string>
#include <stdio.h>
#include <vector>
#include <conio.h>
#include <algorithm>
#include <cctype>
#include <fstream>
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

void menu(){
     cout << "---------------------------------------" << endl;
     cout << "---- U - USUWA STUDENTA ZE SREDNIA <= 2.5" << endl;
     cout << "---- L - LISTUJE NAZWISKA" << endl;
     cout << "---- K - ZAPISUJE AKTUALNY STAN I WYCHODZI Z PROGRAMU" << endl;
     cout << "---- D - DODAJE NOWEGO STUDENTA" << endl;
     cout << "---- X - WYCHODZI CALKOWICIE Z PETLI" << endl;
     cout << "---- NP. Q - PRZECHODZI DO WYJSCIA" << endl;
     cout << "---------------------------------------" << endl;
 }

void dodawanieAll(int liczbaMax, vector<Osoba>&);
void usuwanie(int liczbaMax, vector<Osoba>&);
void dodawanieNowego(int liczbaMax,int &liczbaMaxNowych, vector<Osoba>&);
void sortowanieStudentow(int liczbaMax,int liczbaMaxNowych, vector<Osoba>&);
void zapisDoPliku(int liczbaMax, int liczbaMaxNowych,vector<Osoba> studenci);

int main(){

    fstream plikBazy;

vector <Osoba> studenci(5);
int liczbaMax;
int liczbaMaxNowych;
int wybor;

ograniczenie(liczbaMax);
dodawanieAll(liczbaMax, studenci);
menu();

char key = getch();
int value = key;
int nowe;

while(value != KEY_X){ // x - wyjscie z petli calkowicie
    switch(getch()){
        case KEY_L : //listowanie + duza litera calych imion i nazwisk
        sortowanieStudentow(liczbaMax, liczbaMaxNowych, studenci);
        break;

        case KEY_D : //dodawanie ucznia > 20 uczniow w grupie/ na liscie
        dodawanieNowego(liczbaMax,liczbaMaxNowych, studenci);
        break;

        case KEY_U : //usuniecie studenta ze srocen 2.5 lub mniej
        usuwanie(liczbaMax, studenci);
        break;

        case KEY_K : //zapis aktualnego stanu - do pliku + zakonczenie programu
        zapisDoPliku(liczbaMax,liczbaMaxNowych,studenci);
        break;
        
        default: //wyjscie
             cout << "wychodzisz czy chcesz zobaczyc swoich studentow?  [ 1 - (studenci) / 0 - (wyjscie) ]"  << endl;
        cin >> wybor;
         // odczyt z pliku
        if(wybor == 0){
            cout << "trzymaj sie, milego dnia" << endl;
            return 0;
        } else {
            cout << "Twoja lista studentow: " << endl;

            for(int i = 1; i < liczbaMax + liczbaMaxNowych + 1; i++){   
            cout <<"Studenci: "<< studenci[i].imie <<" "<< studenci[i].nazwisko <<" ma lat "<< studenci[i].wiek <<" numer albumu: "<< studenci[i].nrAlbumu <<" oraz srednia ocen to: "<< studenci[i].srOcen << endl;
           }
       }
       plikBazy.open( "base.txt", ios::in );

        if(plikBazy.is_open())
	    {
        cout << "Aktualna lista studentow wyglada nastepujaco: " << endl;
        cout << endl;

		char wiersz[1000];

		while(plikBazy.getline(wiersz,1000)) 
		{
			cout<< wiersz << endl;
			
		}
        cout << endl;
	    }

       plikBazy.close();
       return 0;
    }
}

key = getch();
value = key;

    return 0;
}

void dodawanieAll(int liczbaMax, vector<Osoba>& wygenerowane){

    int i;

    for(i = 1; i < liczbaMax + 1; i++){
    cout << "podaj imie " << i << " studenta:"<< endl;
    cin >> wygenerowane[i].imie;

    cout << "podaj nazwisko " << i << " studenta:"<< endl;
    cin >> wygenerowane[i].nazwisko;

    cout << "podaj numer albumu " << i << " studenta:"<< endl;
    cin >> wygenerowane[i].nrAlbumu;

    cout << "podaj srednia ocen " << i << " studenta:"<< endl;
    cin >> wygenerowane[i].srOcen;

    cout << "podaj wiek " << i << " studenta:"<< endl;
    cin >> wygenerowane[i].wiek;
}

    cout << "Twoi studenci: " << endl;
    cout << endl;

for(int i = 1; i < liczbaMax + 1; i++){   
cout <<"Studenci: "<< wygenerowane[i].imie <<" "<< wygenerowane[i].nazwisko <<" ma lat "<< wygenerowane[i].wiek <<" numer albumu: "<< wygenerowane[i].nrAlbumu <<" oraz srednia ocen to: "<< wygenerowane[i].srOcen << endl;

}
}

void usuwanie(int liczbaMax, vector<Osoba>& studenci){
    int i;

for(int i = 1; i < liczbaMax + 1; i++){   

    if(studenci[i].srOcen <= 2.5){
        cout << "usuniesz studenta ze srednia mniejsza lub rowna 2.5" << endl;

        cout << endl;

        cout <<"Student: "<< studenci[i].imie <<" "<< studenci[i].nazwisko <<" ma lat "<< studenci[i].wiek <<" numer albumu: "<< studenci[i].nrAlbumu <<" oraz srednia ocen to: "<< studenci[i].srOcen << endl;

        cout << endl;
        
        studenci.erase(studenci.begin() + i);

        cout << "student zostal usuniety" << endl;

    } else {
        cout << "nie znaleziono studenta ze srednia ocen mniejsza lub rowna 2.5" << endl;
    }
   }
 }

void dodawanieNowego(int liczbaMax,int &liczbaMaxNowych, vector<Osoba>& dodawanyNowy){

cout << "Ilu nowych studentow chcesz dodac(nie wiecej niz 20)?" << endl;
cin >> liczbaMaxNowych;

if(liczbaMaxNowych > 20 ){
    cout << endl;
    cout << "nie moze byc wieksza niz 20!" << endl;
    cout << "popraw sie: " << endl;
    cin >> liczbaMaxNowych;
}

int i;

    for(i = 1 + liczbaMax; i < liczbaMaxNowych + 1 + liczbaMax; i++){
    cout << "podaj imie " << i - liczbaMax << " nowego studenta:"<< endl;
    cin >> dodawanyNowy[i].imie;

    cout << "podaj nazwisko " << i - liczbaMax << " nowego studenta:"<< endl;
    cin >> dodawanyNowy[i].nazwisko;

    cout << "podaj numer albumu " << i - liczbaMax << " nowego studenta:"<< endl;
    cin >> dodawanyNowy[i].nrAlbumu;

    cout << "podaj srednia ocen " << i - liczbaMax << " nowego studenta:"<< endl;
    cin >> dodawanyNowy[i].srOcen;

    cout << "podaj wiek " << i - liczbaMax << " nowego studenta:"<< endl;
    cin >> dodawanyNowy[i].wiek;

}
    // dodawanyNowy.insert( dodawanyNowy.begin() + 5, dodawanyNowy[i]);

   cout << "nowy student / studenci zostal / zostali dodani do bazy studentow!" << endl;
   cout << "wrociles do petli - menu, po zakonczeniu tego switcha" << endl;
}

void sortowanieStudentow(int liczbaMax, int liczbaMaxNowych, vector<Osoba>& sortowani){

    sort(sortowani.begin(), sortowani.begin());

    cout << endl;
    for(int i = 1; i < liczbaMax + liczbaMaxNowych + 1; i++){   
    cout <<"Studenci po sortowaniu: "<< sortowani[i].imie <<" "<< sortowani[i].nazwisko <<" ma lat "<< sortowani[i].wiek <<" numer albumu: "<< sortowani[i].nrAlbumu <<" oraz srednia ocen to: "<< sortowani[i].srOcen << endl;
    }
    cout << endl;
}

void zapisDoPliku(int liczbaMax, int liczbaMaxNowych, vector<Osoba> studenci){

    fstream plikBazy;
    plikBazy.open( "base.txt", ios::out | ios::app);

    for(int i = 1; i < liczbaMax + liczbaMaxNowych + 1; i++){   
    plikBazy << studenci[i].imie <<" "<< studenci[i].nazwisko <<" ma lat "<< studenci[i].wiek <<" numer albumu: "<< studenci[i].nrAlbumu <<" oraz srednia ocen to: "<< studenci[i].srOcen << endl;
    }

    plikBazy.close();
}
