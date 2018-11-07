/**        
* @file  VeriYapılari3.odev
* @description Sayi.txt dosyasında yazan sayıları okur, böler, kuyruk yapısı oluşturur, ardından bu kuyruklar toplanıp belirli bir düzende İkili arama ağacına ekler. 
* @course  1.Öğretim C Grubu  
* @assignment  3.Ödev  
* @date    07.12.2016
* @author Enes Eminler enes.eminler@ogr.sakarya.edu.tr      
*/ 
#ifndef BAGLIKUYRUK_HPP
#define BAGLIKUYRUK_HPP

#include <fstream>	
#include <iostream>
#include <string>
using namespace std;

class dugum
{
public:
	int veri;
	dugum *sonraki;
};

class bagliKuyruk
{
private:
	dugum *ilk;
	dugum *son;
	int kapasite;
public:
	bagliKuyruk()
	{
		kapasite = 0;
		ilk = NULL;
		son = NULL;
	}
	int ToplaKuyruk() {				//Toplama işlemi yapan fonksiyon
			//Sayıları en baştan silerek ele alır, verileri geri döndürür ve toplama yapılır. Aynı anda kuyruk temizlenir
		int toplama = 0;			//Toplamı tutacak değişken
		toplama = ilk->veri;		//Kuyruktaki ilk elemanın değerini atıyoruz
		dugum *silinecek = ilk; 	//2 Satırda ilk eleman silinir.
		ilk = ilk->sonraki;
		if (bosMu()) {}
		else {
			delete silinecek;
		}
		kapasite--;				//Kuyruğun kapasitesi düşürülür
		return toplama;			//İlk sayının verisi geri döndürülür.
	}
	bool bosMu()
	{
		return ilk == NULL;
	}
	void Ekle(int a)
	{
		dugum *yenidugum = new dugum();
		yenidugum->veri = a;
		yenidugum->sonraki = NULL;
		if (bosMu())
		{
			ilk = yenidugum;
			son = yenidugum;
		}
		else
		{
			son->sonraki = yenidugum;
			son = yenidugum;
		}
		kapasite++;
	}
	int uzunluk()
	{
		return kapasite;
	}

};
#endif