/**        
* @file  VeriYapýlari3.odev
* @description Sayi.txt dosyasýnda yazan sayýlarý okur, böler, kuyruk yapýsý oluþturur, ardýndan bu kuyruklar toplanýp belirli bir düzende Ýkili arama aðacýna ekler. 
* @course  1.Öðretim C Grubu  
* @assignment  3.Ödev  
* @date    07.12.2016
* @author  Enes Eminler enes.eminler@ogr.sakarya.edu.tr   
*/ 

#include <fstream>		   //Dosyalama iþlemleri için kütüphane
#include <iostream>        
#include <string>          //String komutlarý için gereken kütüphane
#include <clocale>       //Türkçe karakterler için kütüphane

#include "Kuyruk.cpp" 		//Diðer kaynak kodlarýný dahil ediyoruz
#include "AramaAgac.cpp"
#include "islem.cpp"

using namespace std;

int main()
{
	setlocale(LC_ALL, "turkish");    //Türkçe karakter için komut
	
	AramaAgac *agac = new AramaAgac();       //Ýþlemler sýrasýnda kullanýlacak ÝkiliAramaAðacý, Kuyruk ve Ýþlem nesneleri oluþturuluyor
	bagliKuyruk *Kuyruk = new bagliKuyruk();
	islem *islemNesne = new islem();

	ifstream Dosyaoku("sayilar.txt");	//Sayilar.txt e açýlýyor (Yalnýzca okumak için)
	while (true) { 		//Her satýr için iþlem yapýlacak yani her sayý için. Son satýra gelince döngü sonlanacak
						//Her sayýyý bu döngü içinde ele alýp, parçalayýp, ekleyip, daha sonra sileceðiz. Fazladan hafýza kullanýlmayacak.
		string a;	
		Dosyaoku >> a;		//Satýr satýr okuma
	
		for (int i = 0; i < a.size(); i++)			//Rakam adedi kadar döngü
		{
			int rakam = a - '0';
			Kuyruk->Ekle(rakam);	//Ýþlem sýnýfýna Bölme iþlemi için sayýyý tek tek yolluyoruz, int olarak geri dönüþ yapýyor
		}											//Ýnt olarak geri dönen sayý Kuyruða ekleniyor.

		int toplam = 0;
		while (Kuyruk->uzunluk() != 0)				//Kuyruðun elemaný bitene kadar döngü
		{
			toplam = toplam + Kuyruk->ToplaKuyruk();//Toplama fonksiyonu elemanlarý silerek ilerleyip verilerini döndürür.
		}											//Bu sayede elemanlar bitene kadar toplayýp genel toplamý elde ederiz.

		agac->Ekle(toplam);		//Elde edilen toplam Aðaca eklenir

		if (Dosyaoku.eof()) {	//Eðer dosyanýn sonu geldiyse döngüden çýkartan kontrol
			Dosyaoku.close();
			break;
		}

	}

	cout << "Inorder :"; 			//Inorder Preorder Postorder ekrana bastýrýlýyor
	agac->Inorder();
	cout << endl << "Preorder :";
	agac->Preorder();
	cout << endl << "Postorder :";
	agac->Postorder();
	cout << endl << endl;

	delete agac, Kuyruk, islemNesne;	//Tüm oluþan nesneler temizleniyor
	//remove("Sayi.txt");				//Okunan txt dosyasý siliniyor
	return 0;							//Program sonu
}