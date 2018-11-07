#include <fstream>		   //Dosyalama iþlemleri için kütüphane
#include <iostream>        
#include <string>          //String komutlarý için gereken kütüphane
#include <clocale>       //Türkçe karakterler için kütüphane
#include <stdlib.h>
		//Diðer kaynak kodlarýný dahil ediyoruz
#include "AramaAgac.cpp"


using namespace std;

int main()
{
	setlocale(LC_ALL, "turkish");    //Türkçe karakter için komut
	system("cls");
	AramaAgac *agac = new AramaAgac();       //Ýþlemler sýrasýnda kullanýlacak 
	

	ifstream Dosyaoku("sayilar.txt");	//Sayilar.txt e açýlýyor (Yalnýzca okumak için)
	while (true) { 		//Her satýr için iþlem yapýlacak yani her sayý için. Son satýra gelince döngü sonlanacak
						//Her sayýyý bu döngü içinde ele alýp, parçalayýp, ekleyip, daha sonra sileceðiz. Fazladan hafýza kullanýlmayacak.
		string a;	
		Dosyaoku >> a;		//Satýr satýr okuma
		int sharp=0;
		cout << a << " - ";
		for (int i = 0; i < a.size(); i++)			//Rakam adedi kadar döngü
		{
			if(a[i] == '#')	//Ýþlem sýnýfýna Bölme iþlemi için sayýyý tek tek yolluyoruz, int olarak geri dönüþ yapýyor
			{
				sharp = i;		
			}
		}	
		cout << sharp << " - " ;
		string b = "          ";
		for(int i = 0; i < sharp; i++)
		{
			b[i] = a[i];
		}
	
		cout << b;
		string c = "       ";
		int j = 0;
		for(int i = sharp+1; i < a.length(); i++)
		{
			c[j] = a[i];
			j++;
		}
		cout << " - " << c << endl;

		agac->Ekle(b,c);		//Elde edilen toplam Aðaca eklenir
		
		if (Dosyaoku.eof()) {	//Eðer dosyanýn sonu geldiyse döngüden çýkartan kontrol
			Dosyaoku.close();
			break;
		}
	}

	
	 cout << "Inorder :"; 			//Inorder Preorder Postorder ekrana bastýrýlýyor
	 agac->Inorder();
	// cout << endl << "Preorder :";
	// agac->Preorder();
	// cout << endl << "Postorder :";
	// agac->Postorder();
	// cout << endl << endl;

	delete agac;	//Tüm oluþan nesneler temizleniyor
	//remove("Sayi.txt");				//Okunan txt dosyasý siliniyor
	return 0;							//Program sonu
}