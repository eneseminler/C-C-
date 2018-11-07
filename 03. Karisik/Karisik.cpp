/****************************************************************************
**                                SAKARYA ÜNÝVERSÝTESÝ
**                        BÝLGÝSAYAR VE BÝLÝÞÝM BÝLÝMLERÝ FAKÜLTESÝ
**                            BÝLGÝSAYAR MÜHENDÝSLÝÐÝ BÖLÜMÜ
**                              PROGRAMLAMAYA GÝRÝÞÝ DERSÝ
**
**                           ÖDEV NUMARASI…...: 3. ve 4. Ödev
**                           ÖÐRENCÝ ADI......: Enes Eminler
**                           ÖÐRENCÝ NUMARASI.: b151210071
**                           DERS GRUBU.......: A grubu
****************************************************************************/

#include <iostream>
#include <string>
#include <clocale>                        //Türkçe karakter için kütüphane

using namespace std;

int ÖzYine(int x);                        //1.seçenekteki Özyineleme fonksiyonu tanýtýmý 
double alan(struct dikdörtgen);			  //2.seçenekteki dikdörtgenin alanýný hesaplamak için fonksiyonun tanýtýmý
int nokta(struct dikdörtgen, int, int, int ,int);   //2.seçenekteki noktanýn alanýn içinde olup olmadýðýný kontrol için fonksiyon tanýtýmý
void BuyukKucuk(char*);					  //3.seçenekteki harf deðiþimi için fonksiyon tanýtýmý
void yerdegistir(char **dizia, char **dizib);		      //4.seçenekteki yer deðiþtirme için fonksiyon tanýtýmý

struct dikdörtgen                         //Dikdörtgen yapýsý
{
	int en, boy;
};


          
int main() {

	setlocale(LC_ALL, "turkish");       //Türkçe karakterleri kullanabilmemiz için komut

	int islem = 0;   
	int Alan;								//Alan fonksiyonunda alan hesaplanýrken kullanýlan deðiþken
	char kelime[10];                        //Harfleri büyük küçük deðiþtirelecek kelimenin deðiþkeni//Menü seçeneði için deðiþken
	char *dizi1 = "C++";                    //Yeri deðiþtirilecek birinci dizi
	char *dizi2 = "Programlama";            //Yeri deðiþtirilecek ikinci dizi

	do									//Döngü baþlangýcý
	{
		cout << "\n1-Özyinelemeli/Yinelemeli Fonksiyon" << endl;
		cout << "2-Dikdörtgen Yapýsý" << endl;
		cout << "3-Büyük-Küçük harf deðiþimi" << endl;
		cout << "4-Ýki karakter dizisinin yer deðiþimi" << endl;
		cout << "5-Programdan Çýkýþ" << endl;
		cout << "\nLütfen bir iþlem seçiniz:";
		cin >> islem;
		cout << endl;

		if ((islem > 5) || (islem < 1))								//Menüde olmayan deðer girilmesine karþý önlem
		{
			cout << "Lütfen 1 ile 5 arasýnda bir deðer giriniz:";
			cin >> islem;
			cout << endl;
		}

		switch (islem)
		{
		case 1:         //Özyineleme iþleminin kullanýldýðý seçenek
			int N;							 //Özyinelemede kullanýlacak deðer

			cout << "N deðerini giriniz:";
			cin >> N;
			cout << "Özyineli F(" << N << ") = " << ÖzYine(N) << endl;

			break;
		case 2:			//Alan,nokta iþleminin kullanýldýðý seçenek

			int x, y;								//Dikdörtgenin baþlayacaðý köþe koordinatlarýnýn adlarý
			cout << "Dikdörtgenin köþe koordinatlarýný giriniz:" << endl << "X:";
				cin >> x;
			cout << "Y:";
				cin >> y;

			dikdörtgen Dikdörtgen;       //Alaný hesaplanacak dikdörtgenin deðiþkeni
			cout << endl << "Dikdörtgenin en ve boy bilgilerini giriniz." << endl << "En:"; 
				cin >> Dikdörtgen.en;
			cout << "Boy:";
				cin >> Dikdörtgen.boy;

			long int x1, y1;
			cout << "\nNokta koordinatlarýný giriniz:" << endl << "Birinci nokta:";
				cin >> x1;
			cout << "Ýkinci nokta";
				cin >> y1;

			cout << "\nDikdörtgenin alaný:" << alan(Dikdörtgen) << endl;  //Alaný hesaplansýn diye fonksiyonu Dikdörtgen için çaðýrdým
			
			cout << "Belirttiðiniz dikdörtgen içinde mi?: ";
			nokta(Dikdörtgen, x,y, x1, y1);    //Nokta alanýn içinde mi diye noktalar ve dikdörtgen için fonksiyonu çaðýrdým

			break;
		case 3:	   		//Harflerin deðiþim iþleminin yapýldýðý seçenek

			cout << "Söz dizisini giriniz<En fazla 10 harf>: ";
				cin >> kelime;
	
			BuyukKucuk(kelime);           //kelimemizin harflerinin yeri deðiþmesi için fonksiyonu çaðýrdým

			break;
		case 4:        //Deðiþtirme iþleminin kullanýldýðý seçenek

			cout << "Ýlk dizi            :" << dizi1 << endl;
			cout << "Ýkinci dizi         :" << dizi2 << endl;

			yerdegistir(&dizi1, &dizi2);		//Dizilerin yer deðiþtirmesi için fonksiyonu çaðýrdým

			cout << "\nÝlk dizi            :" << dizi1 << endl;
			cout << "Ýkinci dizi         :" << dizi2 << endl;

			break;
		case 5:          //Çýkýþ iþleminin yapýldýðý seçenek

			return 0;						//5. seçenek seçildiðinde kapanmasý için return 0;
		}

	} while (islem <= 100000);				//Döngü sonu

	return 0;
}	   				 //Program sonu


int ÖzYine(int x)	 //Özyineleme fonksiyonu
{
	{
		if (x == 0)
			return 1;
		else if (x == 1)
			return 2;
		else if (x > 1)
			return 2 * ÖzYine(x - 1) - 2 * (x - 1)*ÖzYine(x - 2);
	}
	return x;
};

double alan(dikdörtgen A)    //Dikdörtgenin alanýný hesaplayan program
{
	int Alan;

	Alan = A.en*A.boy;

	return Alan;
};

int nokta(dikdörtgen Bir, int a,int b, int a1, int b1)   //Nokta dikdörtgenin içinde mi diye kontrol eden fonksiyon
{

	{
		if (!(a1 <= a + Bir.en && a1 >= a) && !(b1 <= b + Bir.boy && b1 >= b))

			cout << "0" << endl;

		else

			cout << "1" << endl;
	}
	return 1;
};

void BuyukKucuk(char *harf)		//Küçük harfi büyük, büyük harfi küçük yapan fonksiyon
{
	cout << "Dizinin birinci hali: " << harf << endl;
	for (int i = 0; i < 10; i++)
		
		if (harf[i] >= 65 && harf[i] <= 90)
		{
			harf[i] += 32;
		}
		else if (harf[i] >= 97 && harf[i] <= 122)
		{
			harf[i] -= 32;
		}
		else if (harf[i] == 32)
		{
			harf[i] = 32;
		}
		
		cout << "Dizinin ikinci hali: " << harf << endl;
		
}

void yerdegistir(char **dizia, char **dizib)   //Dizilerin yerlerini deðiþtiren fonksiyon
{
	char *kopyadizi;						//Diziler deðiþtirilirken kullanýlacak kopya deðiþken

	kopyadizi = *dizia;
	*dizia = *dizib;
	*dizib= kopyadizi;
};
