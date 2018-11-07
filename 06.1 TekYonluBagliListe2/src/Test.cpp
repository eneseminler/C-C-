

#include <iostream>
#include <string>
using namespace std;

#include "Sayi.hpp"
#include "Islem.hpp"

int main()
{	sayi *sayi1 = new sayi;               //Sayı nesnelerini oluşturuyoruz
	sayi *sayi2 = new sayi;
	bagilListe *liste1 = new bagilListe;  //Liste nesnelerini oluşturuyoruz
	bagilListe *liste2 = new bagilListe;
	
	cout << "\nx sayisi: ";
	cin >> *sayi1;						//Sayılarımızı alıyoruz dışarıdan, friend classı var.
	cout << "y sayisi: ";
	cin >> *sayi2;

	ListEkle(*sayi1, liste1);			//Sayıları tek tek bölüp listeye ekliyoruz
	ListEkle(*sayi2, liste2);
	
	cout << "\nx listesi:  ";
	cout << *liste1 << endl;			//Listeleri ekrana basıyoruz
	cout << "y listesi:  ";				//Friend classı var, ostream 
	cout << *liste2 << endl;
	
	bagilListe *k = (*liste1 * *liste2);  //Toplama işlemi yapılıyor, operator aşırı yükleme var +
	cout << "\nx+y toplami=  ";
	cout << *k << endl;						//Ekrana yazdırılıyor
	
	silme(sayi1, sayi2, liste1, liste2);  //Silme fonksiyonu çağırılıyor, tüm bellekte oluşanlar temizleniyor
	
	cin.get();
	cin.ignore();
	return 0;
}