#include <fstream>		   //Dosyalama i�lemleri i�in k�t�phane
#include <iostream>        
#include <string>          //String komutlar� i�in gereken k�t�phane
#include <clocale>       //T�rk�e karakterler i�in k�t�phane
#include <stdlib.h>
		//Di�er kaynak kodlar�n� dahil ediyoruz
#include "AramaAgac.cpp"


using namespace std;

int main()
{
	setlocale(LC_ALL, "turkish");    //T�rk�e karakter i�in komut
	system("cls");
	AramaAgac *agac = new AramaAgac();       //��lemler s�ras�nda kullan�lacak 
	

	ifstream Dosyaoku("sayilar.txt");	//Sayilar.txt e a��l�yor (Yaln�zca okumak i�in)
	while (true) { 		//Her sat�r i�in i�lem yap�lacak yani her say� i�in. Son sat�ra gelince d�ng� sonlanacak
						//Her say�y� bu d�ng� i�inde ele al�p, par�alay�p, ekleyip, daha sonra silece�iz. Fazladan haf�za kullan�lmayacak.
		string a;	
		Dosyaoku >> a;		//Sat�r sat�r okuma
		int sharp=0;
		cout << a << " - ";
		for (int i = 0; i < a.size(); i++)			//Rakam adedi kadar d�ng�
		{
			if(a[i] == '#')	//��lem s�n�f�na B�lme i�lemi i�in say�y� tek tek yolluyoruz, int olarak geri d�n�� yap�yor
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

		agac->Ekle(b,c);		//Elde edilen toplam A�aca eklenir
		
		if (Dosyaoku.eof()) {	//E�er dosyan�n sonu geldiyse d�ng�den ��kartan kontrol
			Dosyaoku.close();
			break;
		}
	}

	
	 cout << "Inorder :"; 			//Inorder Preorder Postorder ekrana bast�r�l�yor
	 agac->Inorder();
	// cout << endl << "Preorder :";
	// agac->Preorder();
	// cout << endl << "Postorder :";
	// agac->Postorder();
	// cout << endl << endl;

	delete agac;	//T�m olu�an nesneler temizleniyor
	//remove("Sayi.txt");				//Okunan txt dosyas� siliniyor
	return 0;							//Program sonu
}