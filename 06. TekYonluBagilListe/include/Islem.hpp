#ifndef ISLEM_HPP
#define ISLEM_HPP
#include <iostream>
#include <string>
using namespace std;
#include "bagilListe.hpp"
#include "sayi.hpp"

//Program boyunca yapılan işlemlerin tutulduğu yer.

void ListEkle(sayi x, bagilListe *&liste)     //Ekleme işini bu fonksiyon yapar
	 {
		string b = x.degerver();
		 for (int i = 0; i < b.size(); i++)
		 {
		char ch = b[i];
		 int rakam = ch - '0';
		 liste->Ekle(rakam);
	 }
	}
void silme(sayi *a,sayi *b, bagilListe *liste1, bagilListe *liste2)
{													//Program bitişinde silme işini yapan fonk.
	delete a;
	delete b;
	delete[]liste1;
	delete[]liste2;
}

bagilListe *bagilListe::operator+(bagilListe b)		//Listeleri toplamaya yarayan operator aşırı yükleme fonk.
{
	bagilListe *list = new bagilListe;

	int eleman1 = this->Uzunluk();					//İlk listenin uzunluğunu alır
	int eleman2 = (&b)->Uzunluk();					//Toplanacak listenin uzunluğu alınır
	int elemansayisi = 0;

	if (eleman1 < eleman2)
		elemansayisi = eleman1;						//Duruma göre eleman sayısı fazla olana kadar saymak için atama yapılır
	else
		elemansayisi = eleman2;

	dugum *simdiki1 = this->indexiver(eleman1 - 1);	//Elemanlarını alıp simdiki1 e atar
	dugum *simdiki2 = (&b)->indexiver(eleman2 - 1);

	int artanOnceki = 0;
	int artanSimdiki = 0;
	int rakam1;					//Sayılar toplanırken tek tek ele alınacak değerler bu değişkenlere kopyalanır
	int rakam2;
	int rakam3;

	for (int i = 0; i < elemansayisi; i++)		//Eleman sayısı kadar sayılacak, o sürece kadar tek tek kontrol edilip sayılar toplanacak
	{
		rakam1 = simdiki1->rakamNe();			//Sayılar başka değişkene atılıp toplanır
		rakam2 = simdiki2->rakamNe();
		rakam3 = rakam1 + rakam2;
													/*Eğer toplam 10 dan küçükse sıkıntı yoktur atama yapılıp devam edilir
													10 dan büyükse 1 elde alınır ve 10 eksiği toplamdaki sonraki eleman olarak atanır											
													*/ 
		if (rakam3 + artanOnceki < 10)
		{
			list->Ekle(rakam3 + artanOnceki);
		}
		else
		{
			artanSimdiki = 1;
			list->Ekle(rakam3 + artanOnceki - 10);
		}
		artanOnceki = artanSimdiki;
		artanSimdiki = 0;
		simdiki1 = this->indexiver(eleman1 - i - 2);
		simdiki2 = (&b)->indexiver(eleman2 - i - 2);
	}
														
	if (eleman1 > elemansayisi)
	{
		simdiki1 = this->indexiver(eleman1 - elemansayisi - 1);
		for (int p = eleman1 - elemansayisi - 1; p >= 0; p--)
		{
			rakam1 = simdiki1->rakamNe();

			if (artanOnceki != 0)
			{
				list->Ekle(rakam1 + artanOnceki);
				artanOnceki = 0;
			}
			else
			{
				list->Ekle(rakam1);
			}
			if (p != 0)
				simdiki1 = this->indexiver(p - 1);

		}
	}
	else if (eleman2 > elemansayisi)
	{
		simdiki2 = (&b)->indexiver(eleman2 - elemansayisi - 1);
		for (int t = eleman2 - elemansayisi - 1; t >= 0; t--)
		{
			rakam2 = simdiki2->rakamNe();
			if (artanOnceki != 0)
			{
				list->Ekle(rakam2 + artanOnceki);
				artanOnceki = 0;
			}
			else
			{
				list->Ekle(rakam2);
			}
			if (t != 0)
				simdiki2 = (&b)->indexiver(t - 1);
		}

	}
	else
	{
		if (artanOnceki != 0)
		{
			list->Ekle(artanOnceki);
			artanOnceki = 0;
		}
	}

	return list->turnreverse(list);   // Liste ters çevrilir
}

bagilListe *bagilListe::turnreverse(bagilListe *b)  //Ters çeviren fonksiyon
{
	bagilListe *yeni = new bagilListe;
	for (int t = b->Uzunluk() - 1; t >= 0; t--)	
	{
		yeni->Ekle(b->indexiver(t)->rakamNe());
	}
	delete[](&b);
	return yeni;
}


#endif