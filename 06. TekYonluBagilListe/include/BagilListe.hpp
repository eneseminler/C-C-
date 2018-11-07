#ifndef BAGILLISTE_HPP
#define BAGILLISTE_HPP
#include <iostream>
#include <string>
using namespace std;
#include "dugum.hpp"

class bagilListe                  //Bağıl liste sınıfı
{ 									//Fonksiyonlar .cpp adlı dosyada, burada sadece tanımladım.

private:
	dugum *ListeBasi;             //Private değerler
	int elemansayisi;				//Listenin uzunluğunu tutacak değer

public:
	bagilListe(); 					//Kurucu fonk.
	void listBasDegis(dugum *x);	
	void Ekle(int x);				//ekleme fonk.
	bool bosmu();				
	int Uzunluk();					//Uzunluk get fonk.

	
	string yazdir();					
	bagilListe *operator+(const  bagilListe  b); //Toplama işlemi yapılırken kullanmak için aşırı yükleme
	dugum* basiDondur();				
	dugum* indexiver(int i);			
	bagilListe *turnreverse(bagilListe *a);			//Listeyi ters çeviren fonk.
	friend ostream &operator<<(ostream &output, const bagilListe  &E);  //Ekrana basmak için yazılan friend fonksiyonu
};
#endif