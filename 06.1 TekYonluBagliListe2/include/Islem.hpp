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

bagilListe *bagilListe::operator*(bagilListe b)		//Listeleri toplamaya yarayan operator aşırı yükleme fonk.
{
	
	// bagilListe *carp = new bagilListe;
	// bagilListe *toplam = new bagilListe;
	
	// int uzunluk1 =  this->Uzunluk();
	// int uzunluk2 =  (&b)->Uzunluk();
	// int carpımsayisi= 1;
	
	// for(int i = 0; i<uzunluk1; i++)
	// {
	// if(i=0)
	// { carpım = 1; }
	// else{
		// carpım = carpım*10;
	// }
	// for(int j = 0; j<uzunluk2; j++)
	// {
		
		
	// }
	// }
	 bagilListe *list = new bagilListe;
     bagilListe *toplam = new bagilListe;
	 
	 int eleman1 = this->Uzunluk();					//İlk listenin uzunluğunu alır
	 int eleman2 = (&b)->Uzunluk();					//toplanacak listenin uzunluğu alınır
	 int elemansayisi = 0;
	 int elemansayisi2 = 0;
	 int carpimsayisi=1;

	 if (eleman1 < eleman2)
	 {	elemansayisi = eleman2;
		elemansayisi2 = eleman1;
	}					//duruma göre eleman sayısı fazla olana kadar saymak için atama yapılır
	 else
	 {	 elemansayisi = eleman1;
	elemansayisi2 = eleman2;}
	cout << "elemansayisi" << elemansayisi << endl;

	 dugum *simdiki1 = this->indexiver(eleman1 - 1);	//elemanlarını alıp simdiki1 e atar
	 dugum *simdiki2 = (&b)->indexiver(eleman2 - 1);

	 int artanonceki = 0;
	 int artansimdiki = 0;
	 int rakam1;					//sayılar toplanırken tek tek ele alınacak değerler bu değişkenlere kopyalanır
	 int rakam2;
	 int rakam3;

	 for (int j = 0; j < elemansayisi; j++)		//eleman sayısı kadar sayılacak, o sürece kadar tek tek kontrol edilip sayılar toplanacak
	 {
		 carpimsayisi = 1;
		 rakam2 = simdiki1->rakamNe();			//sayılar başka değişkene atılıp toplanır
		
	
	 for(int i=0 ; i < elemansayisi2; i++ ){
		 
		 rakam1 = simdiki2->rakamNe();
		 
		if(i != 0)
		{ 
		carpimsayisi = carpimsayisi*10; 
		}
		else{
		simdiki2 = (&b)->indexiver(eleman2 - i - 1);
		rakam1 = simdiki2->rakamNe();
		}
	
	
	
		// if(rakam2 == 0)
		// { rakam2 = 1;}
	
		cout << rakam1 << " " << rakam2;
		rakam3 = rakam1 * rakam2 * carpimsayisi;
		cout << "   2.yer   " << i << "    " <<j << " ." << endl;										 /*eğer toplam 10 dan küçükse sıkıntı yoktur atama yapılıp devam edilir
													 10 dan büyükse 1 elde alınır ve 10 eksiği toplamdaki sonraki eleman olarak atanır                                                                                                                                                                                                                                                                 											
													*/
		list->Ekle(rakam3);								
		artanonceki = artansimdiki;
		artansimdiki = 0;
		// if(i>2)
		// {
			// i = i-3;
		// }
		simdiki1 = this->indexiver(eleman1 - j - 2);
		simdiki2 = (&b)->indexiver(eleman2 - i - 2);

		 }
	 }
														
	 if (eleman1 > elemansayisi)
	 {
		 simdiki1 = this->indexiver(eleman1 - elemansayisi - 1);
		 for (int p = eleman1 - elemansayisi - 1; p >= 0; p--)
		 {
			 rakam1 = simdiki1->rakamNe();

			 if (artanonceki != 0)
			 {
				 list->Ekle(rakam1 + artanonceki);
				 artanonceki = 0;
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
			 if (artanonceki != 0)
			 {
				 list->Ekle(rakam2 + artanonceki);
				 artanonceki = 0;
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
		 if (artanonceki != 0)
		 {
			 list->Ekle(artanonceki);
			 artanonceki = 0;
		 }
	 }
	 cout << "3.yer";
	int carpimeleman = list->Uzunluk();
	string toplamtoplam;
	dugum *simdiki3 = list->indexiver(carpimeleman - 1);
	// for(int a = 0; a<carpimeleman; a++)
	// {	
		// int u = simdiki3->rakamNe();
		// int b = atoi(toplamtoplam.c_str());
		// char *intStr = itoa( b +  simdiki3);
		// toplamtoplam = string(intStr);
	// }
	 
	 cout << *list;
	 return list->turnreverse(list);   // liste ters çevrilir
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