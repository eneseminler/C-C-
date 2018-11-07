/**        
* @file  VeriYap�lari3.odev
* @description Sayi.txt dosyas�nda yazan say�lar� okur, b�ler, kuyruk yap�s� olu�turur, ard�ndan bu kuyruklar toplan�p belirli bir d�zende �kili arama a�ac�na ekler. 
* @course  1.��retim C Grubu  
* @assignment  3.�dev  
* @date    07.12.2016
* @author  Enes Eminler enes.eminler@ogr.sakarya.edu.tr   
*/ 

#include <fstream>		   //Dosyalama i�lemleri i�in k�t�phane
#include <iostream>        
#include <string>          //String komutlar� i�in gereken k�t�phane
#include <clocale>       //T�rk�e karakterler i�in k�t�phane

#include "Kuyruk.cpp" 		//Di�er kaynak kodlar�n� dahil ediyoruz
#include "AramaAgac.cpp"
#include "islem.cpp"

using namespace std;

int main()
{
	setlocale(LC_ALL, "turkish");    //T�rk�e karakter i�in komut
	
	AramaAgac *agac = new AramaAgac();       //��lemler s�ras�nda kullan�lacak �kiliAramaA�ac�, Kuyruk ve ��lem nesneleri olu�turuluyor
	bagliKuyruk *Kuyruk = new bagliKuyruk();
	islem *islemNesne = new islem();

	ifstream Dosyaoku("sayilar.txt");	//Sayilar.txt e a��l�yor (Yaln�zca okumak i�in)
	while (true) { 		//Her sat�r i�in i�lem yap�lacak yani her say� i�in. Son sat�ra gelince d�ng� sonlanacak
						//Her say�y� bu d�ng� i�inde ele al�p, par�alay�p, ekleyip, daha sonra silece�iz. Fazladan haf�za kullan�lmayacak.
		string a;	
		Dosyaoku >> a;		//Sat�r sat�r okuma
	
		for (int i = 0; i < a.size(); i++)			//Rakam adedi kadar d�ng�
		{
			int rakam = a - '0';
			Kuyruk->Ekle(rakam);	//��lem s�n�f�na B�lme i�lemi i�in say�y� tek tek yolluyoruz, int olarak geri d�n�� yap�yor
		}											//�nt olarak geri d�nen say� Kuyru�a ekleniyor.

		int toplam = 0;
		while (Kuyruk->uzunluk() != 0)				//Kuyru�un eleman� bitene kadar d�ng�
		{
			toplam = toplam + Kuyruk->ToplaKuyruk();//Toplama fonksiyonu elemanlar� silerek ilerleyip verilerini d�nd�r�r.
		}											//Bu sayede elemanlar bitene kadar toplay�p genel toplam� elde ederiz.

		agac->Ekle(toplam);		//Elde edilen toplam A�aca eklenir

		if (Dosyaoku.eof()) {	//E�er dosyan�n sonu geldiyse d�ng�den ��kartan kontrol
			Dosyaoku.close();
			break;
		}

	}

	cout << "Inorder :"; 			//Inorder Preorder Postorder ekrana bast�r�l�yor
	agac->Inorder();
	cout << endl << "Preorder :";
	agac->Preorder();
	cout << endl << "Postorder :";
	agac->Postorder();
	cout << endl << endl;

	delete agac, Kuyruk, islemNesne;	//T�m olu�an nesneler temizleniyor
	//remove("Sayi.txt");				//Okunan txt dosyas� siliniyor
	return 0;							//Program sonu
}