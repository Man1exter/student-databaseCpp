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

void menu(){
     cout << "---------------------------------------" << endl;
     cout << "---- U - USUWA STUDENTA ZE SREDNIA <= 2.5" << endl;
     cout << "---- L - LISTUJE NAZWISKA" << endl;
     cout << "---- K - ZAPISUJE AKTUALNY STAN" << endl;
     cout << "---- D - DODAJE NOWEGO STUDENTA" << endl;
     cout << "---- X - WYCHODZI CALKOWICIE Z PETLI" << endl;
     cout << "---- NP. Q - PRZECHODZI DO WYJSCIA" << endl;
     cout << "---------------------------------------" << endl;
 }

void dodawanieAll(int liczbaMax, vector<Osoba>&);
void usuwanie(int liczbaMax, vector<Osoba>&);
void dodawanieNowego(int &liczbaMaxNowych, vector<Osoba>&);

    

int main(){

vector <Osoba> studenci(20);
int liczbaMax;
int liczbaMaxNowych;

ograniczenie(liczbaMax);
dodawanieAll(liczbaMax, studenci);
menu();
int wybor;

char key = getch();
int value = key;
int nowe;

while(value != KEY_X){ // x - wyjscie z petli calkowicie
    switch(getch()){
        case KEY_L : //listowanie + duza litera calych imion i nazwisk

        break;

        case KEY_D : //dodawanie ucznia > 20 uczniow w grupie/ na liscie
        dodawanieNowego(liczbaMaxNowych, studenci);
        break;

        case KEY_U : //usuniecie studenta ze srocen 2.5 lub mniej
        usuwanie(liczbaMax, studenci);
        break;

        case KEY_K : //zapis aktualnego stanu

        break;
        
        default: //wyjscie
        cout << "wychodzisz czy chcesz zobaczyc swoich studentow?  [ 1 - (studenci) / 0 - (wyjscie) ]"  << endl;
        cin >> wybor;

        if(wybor == 0){
            cout << "trzymaj sie, milego dnia" << endl;
            return 0;
        } else {
            cout << "Twoja lista studentow: " << endl;

            for(int i = 1; i < liczbaMax + 1; i++){   
            cout <<"Studenci: "<< studenci[i].imie <<" "<< studenci[i].nazwisko <<" ma lat "<< studenci[i].wiek <<" numer albumu: "<< studenci[i].nrAlbumu <<" oraz srednia ocen to: "<< studenci[i].srOcen << endl;
           }
       }

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

void dodawanieNowego(int &liczbaMaxNowych, vector<Osoba>& studenci){

cout << "Ilu nowych studentow chcesz dodac(nie wiecej niz 20)?" << endl;
cin >> liczbaMaxNowych;

if(liczbaMaxNowych > 20 ){
    cout << endl;
    cout << "nie moze byc wieksza niz 20!" << endl;
    cout << "popraw sie: " << endl;
    cin >> liczbaMaxNowych;
}

int i;

    for(i = 1; i < liczbaMaxNowych + 1; i++){
    cout << "podaj imie " << i << " nowego studenta:"<< endl;
    cin >> studenci[i].imie;

    cout << "podaj nazwisko " << i << " nowego studenta:"<< endl;
    cin >> studenci[i].nazwisko;

    cout << "podaj numer albumu " << i << " nowego studenta:"<< endl;
    cin >> studenci[i].nrAlbumu;

    cout << "podaj srednia ocen " << i << " nowego studenta:"<< endl;
    cin >> studenci[i].srOcen;

    cout << "podaj wiek " << i << " nowego studenta:"<< endl;
    cin >> studenci[i].wiek;

}

    cout << "Twoi nowi studenci: " << endl;
    cout << endl;

    for(int i = 1; i < liczbaMaxNowych + 1; i++){   
    cout <<"Studenci: "<< studenci[i].imie <<" "<< studenci[i].nazwisko <<" ma lat "<< studenci[i].wiek <<" numer albumu: "<< studenci[i].nrAlbumu <<" oraz srednia ocen to: "<< studenci[i].srOcen << endl;

} 
}
