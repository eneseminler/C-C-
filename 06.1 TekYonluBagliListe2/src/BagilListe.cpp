#include "BagilListe.hpp"


//Bağıl liste sınıfının fonksiyonları

bagilListe::bagilListe()    //Kurucu fonksiyon
{
	elemansayisi = 0;		//Eleman sayısını 0 a ayarlar
}
dugum* bagilListe::basiDondur()
{
	return ListeBasi;			//İlk eleman
}
int bagilListe::Uzunluk()			//Eleman sayısı get fonk. Uzunluğu bu şekilde elde ederiz
{
	return elemansayisi;
}
void bagilListe::listBasDegis(dugum *x)
{
	ListeBasi = x;
}

void bagilListe::Ekle(int a)			//Ekleme fonk.
{

	if (elemansayisi == 0) 				//İlk elemansa buradan ekler
	{
		dugum *bas = new dugum;
		bas->rakamDegis(a);
		bas->sonrakiDegis(NULL);
		ListeBasi = bas;
		elemansayisi++;
	}
	else
	{		//Yeni elemanlar eklenirken önceki pointerı saklarlar, sonraki null yapılır.
		dugum *simdiki = ListeBasi;
		dugum *onceki = ListeBasi;
		for (int i = 0; i < elemansayisi; i++)
		{
			simdiki = simdiki->sonrakiVer();
			if (i > 0)
				onceki = onceki->sonrakiVer();
		}
		simdiki = new dugum;
		simdiki->rakamDegis(a);
		simdiki->sonrakiDegis(NULL);
		onceki->sonrakiDegis(simdiki);
		elemansayisi++;
	}
}

string bagilListe::yazdir()                 //Elemanları tek tek yazdıran fonk.
{
	dugum *simdiki = ListeBasi;
	string sonuc = "";
	for (int i = 0; i < elemansayisi; i++)
	{
		if (i != elemansayisi - 1)
			sonuc += simdiki->rakamNe() + "-";
		else
			sonuc += simdiki->rakamNe();
		simdiki = simdiki->sonrakiVer();
	}
	return sonuc;
}

bool bagilListe::bosmu()					//Liste boş mu diye kontrol
{
	if (elemansayisi == 0)
		return true;
	else
		return false;
}
dugum* bagilListe::indexiver(int i) 		//Liste içinde gezip tüm elemanları veren fonk
{
	dugum *simdiki = ListeBasi;
	for (int y = 0; y < i; y++)
	{
		simdiki = simdiki->sonrakiVer();
	}
	return simdiki;
}


ostream &operator<<(ostream &cikti, const bagilListe  &E)  //Ekrana basmak için friend fonksiyonu
{															//Tüm listeyi bu kod ile rahatça ekrana basabiliriz.
	dugum *simdiki = E.ListeBasi;

	for (int i = 0; i < E.elemansayisi; i++)
	{
		if (i != E.elemansayisi - 1)
			cikti << simdiki->rakamNe() << "-";
		else
			cikti << simdiki->rakamNe();
		simdiki = simdiki->sonrakiVer();
	}

	return cikti;
}
