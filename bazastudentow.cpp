#include <iostream>
#include <cstring>
#include <string>
#include <stdio.h>
#include <fstream>
#include <conio.h>
#include <algorithm>
#include <cctype> // duze litery touppercase keycode 
#include <iterator>

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





int main(){



fstream plik;   

plik.open( "studenci.txt", ios::out | ios::app);

Osoba uczniowie[20]{};

int liczbStudentow; // ograniczenie w dodawaniu 



cout << "Ilu studentow chcesz dodac?   ----   (nie wiecej niz 20!)" << endl;
cin >> liczbStudentow;

if(liczbStudentow > 20){
    cout << "nie wiecej niz 20 w bazie danych, komputer wybuchnie" << endl;
    cout << "podaj ile poprawnie dodac" << endl;
    cin >> liczbStudentow;
}

for(int i = 0; i < liczbStudentow; i++){
    cout << "podaj imie i nazwisko " << i+1 << " ucznia: " ;
    cin >> uczniowie[i].imie;
    cin >> uczniowie[i].nazwisko;
}

cout << endl;

for(int i = 0; i < liczbStudentow; i++){
    cout << "podaj numer albumu " << uczniowie[i].imie <<" "<< uczniowie[i].nazwisko <<" ";
    cin >> uczniowie[i].nrAlbumu;
}

cout << endl;

for(int i = 0; i < liczbStudentow; i++){
    cout << "podaj wiek " << uczniowie[i].imie <<" "<< uczniowie[i].nazwisko <<" ";
    cin >> uczniowie[i].wiek;
}

cout << endl;

for(int i = 0; i < liczbStudentow; i++){
    cout << "podaj srednia ocen: " << uczniowie[i].imie <<" "<< uczniowie[i].nazwisko <<" ";
    cin >> uczniowie[i].srOcen;
}

cout << endl;

for(int i = 0; i < liczbStudentow; i++){
plik << uczniowie[i].imie <<" "<< uczniowie[i].nazwisko <<" ma lat "<< uczniowie[i].wiek <<" numer albumu: "<< uczniowie[i].nrAlbumu <<" oraz średnia ocen to: "<< uczniowie[i].srOcen << endl;
} 

for(int i = 0; i < liczbStudentow; i++){
cout << uczniowie[i].imie <<" "<< uczniowie[i].nazwisko <<" ma lat "<< uczniowie[i].wiek <<" numer albumu: "<< uczniowie[i].nrAlbumu <<" oraz średnia ocen to: "<< uczniowie[i].srOcen << endl;
} 

cout << endl;

cout << "Wprowadziles dane studentow do bazdy danych!" << endl;

cout << endl;

cout << "          MENU LISTY UCZNIOW:       " << endl;
cout << "-------------------------------------------" << endl;
cout << "..(K).. - Zapis aktualnego stanu.." << endl;
cout << "..(L).. - Listowanie Listy alfabetycznie.." << endl;
cout << "..(U).. - Usuniecie studenta ze sr.ocen 2.5.." << endl;
cout << "..(D).. - Dodanie nowego studenta i jego cech(imie,nazwisko,wiek,srOcen,nrAlbumu) nie wiecej niz 20 uczniow.." << endl;
cout << "..(X).. - Wyjscie z programu.." << endl;
cout << "-------------------------------------------" << endl;
cout << "Podaj znak(w ramce) do wywołania danej metody na liscie studentow/uczniow.."<<endl;

cout << endl;

char key = getch();
int value = key;
int nowe;


while(value != KEY_X){
    switch(getch()){
        case KEY_L : //listowanie + duza litera calych imion i nazwisk

for(int i = 0; i < liczbStudentow; i++){
cout <<"Przed sortowaniem: "<< uczniowie[i].imie <<" "<< uczniowie[i].nazwisko <<" ma lat "<< uczniowie[i].wiek <<" numer albumu: "<< uczniowie[i].nrAlbumu <<" oraz średnia ocen to: "<< uczniowie[i].srOcen << endl;
} 

cout << endl;

sort(uczniowie,uczniowie+20); // odwrote zwrocenie dla lepszej przykladnosci i zwrocenia uwagi na alfabetycznosc :)

cout << endl;


for(int i = 0; i < liczbStudentow; i++){   
cout <<"Po sortowaniu: "<< uczniowie[i].imie <<" "<< uczniowie[i].nazwisko <<" ma lat "<< uczniowie[i].wiek <<" numer albumu: "<< uczniowie[i].nrAlbumu <<" oraz średnia ocen to: "<< uczniowie[i].srOcen << endl;
} 

cout << endl;

        cout << "Nazwiska zostały wylistowane" << endl;

        break;
    



        case KEY_D : //dodawanie ucznia > 20 uczniow w grupie/ na liscie

        cout << "Dodaj nowego ucznia/uczniow, ale nie moze byc wiecej niz 20 na liscie studentow" << endl;
        cout << "Ile osob?" << endl;
        cin >> nowe;

        cout << endl;
      
        cout << endl;

        for(int i = 0; i < nowe; i++){  
        cout << "Podaj imie i nazwisko " << i+1 << " nowo dodanego ucznia: ";
        cin >> uczniowie[i].imie;
        cin >> uczniowie[i].nazwisko;
        cout << "Podaj nr.albumu: ";
        cin >> uczniowie[i].nrAlbumu;
        cout << "Podaj wiek: ";
        cin >> uczniowie[i].wiek;
        cout << "Podaj sr.ocen: ";
        cin >> uczniowie[i].srOcen;
}

        cout << endl;

        cout << "Aktualnie dodales do listy: " << endl;
        cout << endl;

        for(int i = 0; i < nowe; i++){
        plik << uczniowie[i].imie <<" "<< uczniowie[i].nazwisko <<" ma lat "<< uczniowie[i].wiek <<" numer albumu: "<< uczniowie[i].nrAlbumu <<" oraz średnia ocen to: "<< uczniowie[i].srOcen << endl;
        } 

        for(int i = 0; i < nowe; i++){
        cout << uczniowie[i].imie <<" "<< uczniowie[i].nazwisko <<" ma lat "<< uczniowie[i].wiek <<" numer albumu: "<< uczniowie[i].nrAlbumu <<" oraz średnia ocen to: "<< uczniowie[i].srOcen << endl;
        } 

        cout<<endl;

        break;




        case KEY_U : //usuniecie z srocen 2.5 (opcjonalnie - konkretny)




        cout<<endl;




        break;






        case KEY_K : //zapis aktualnego stanu(opcjonalnie - pokazanie all listy uczniow)

       cout << "Aktualna lista studentow wyglada nastepujaco: " << endl;
       cout << endl;

       for(int i = 0; i < liczbStudentow + nowe; i++){   
       cout << uczniowie[i].imie <<" "<< uczniowie[i].nazwisko <<" ma lat "<< uczniowie[i].wiek <<" numer albumu: "<< uczniowie[i].nrAlbumu <<" oraz średnia ocen to: "<< uczniowie[i].srOcen << endl;
       } 

        cout<<endl;
        break;
        




        default: //wyjscie
        cout << "Aktualnie skorzystales z dziennika studentow, milego dnia :)" << endl;
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












