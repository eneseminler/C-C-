/****************************************************************************
**                         SAKARYA ÜNÝVERSÝTESÝ
**               BÝLGÝSAYAR VE BÝLÝÞÝM BÝLÝMLERÝ FAKÜLTESÝ
**                   BÝLGÝSAYAR MÜHENDÝSLÝÐÝ BÖLÜMÜ
**                     Programlamaya Giriþ Dersi
**                       2015-2016 GÜZ DÖNEMÝ
**
**               ÖDEV NUMARASI: 2. Ödev
**               ÖÐRENCÝ ADI: Enes EMÝNLER
**               ÖÐRENCÝ NUMARASI: b151210071
**               DERSÝN ALINDIÐI GRUP: A Grubu
****************************************************************************/
#include <iostream>
#include <clocale>            //Dil tercihi için kütüphane
#include <cstdlib>

void ElemanEkle();            //Eleman eklemek için kullandýðým fonksiyon
void ElemanListele();         //Eleman listelemek için kullandýðým fonksiyon
void ElemanAra();             //Eleman aramak için kullandýðým fonksiyon 
void ElemanSil();             //Eleman silmek için kullandýðým fonksiyon

int ElemanDizi[101];          //Programda kullandýðýmýz diziyi tanýmladýk
int Eleman = 0;               //Dizi Elemanlarý yerine kullanacaðýmýz deðiþken
int ElemanÝndeksi;            //Elemanlarýn dizideki sýrasýný belirlerken kullandýðýmýz deðiþken
int SilinecekEleman;          //Elemaný silerken kullanacaðýmýz deðiþken
int i = 0;

using namespace std;

int main(int argc, char*argv[])
{
	setlocale(LC_ALL, "turkish");          //Türkçe karakter kodu

	int Secenek = 0;            //Menüde girilecek seçeneðin deðiþkeni
	{
		for (i = 0; i <= 101; i++)
		{
			ElemanDizi[i] = -1;
		}
	}
	do                                    //Menünün sürekli dönmesi için do-while döngüsü kullanýyorum 
	{
		cout << endl;
		cout << "1- Eleman Ekle" << endl;	  //Menünün ekran çýktýsýný veriyoruz.
		cout << "2- Eleman Sil" << endl;
		cout << "3- Eleman Ara" << endl;
		cout << "4- Eleman Listele" << endl;
		cout << "5- Çýkýþ" << endl;
		cout << "Seçenek=";
		cin >> Secenek;                   //Menüden seçtiðimiz tercihi giriyoruz


		if (Secenek>5)                         //Seçeneðin 5 ten büyük girilmesine karþý kontrol ettiriyorum.
			cout << "Hatalý seçenek." << endl;


		switch (Secenek)                      //Menüden seçtiðimiz tercihe ilerlemek için Switch-Case kullanýyorum
		{
		case 1:
			ElemanEkle();                     //Eleman ekleme fonksiyonunu çaðýrýyorum
			break;
		case 2:
			ElemanSil();                      //Eleman silme fonksiyonunu çaðýrýyorum
			break;
		case 3:
			ElemanAra();                      //Eleman arama fonksiyonunu çaðýrýyorum
			break;
		case 4:
			ElemanListele();                  //Eleman listeleme fonksiyonunun çaðýrýyorum
			break;
		case 5:
			return 0;                         //Menüden çýkmak istersek diye çýkýþ seçeneði
		}

	} while (Secenek <= 100000);            //Döngünün sonu, menüyü sürekli baþa döndürüyor

	return 0;                             //Program sonu
}

void ElemanEkle()                         //Eleman Ekleme fonksiyonu
{
	do
	{
		cout << "Eklenecek elemaný giriniz:";
		cin >> Eleman;			 		     //Eklenecek elemaný giriyoruz

		if (Eleman < 1)                      //Eleman negatif deðer girildiyse kontrol ediyorum
		{
			cout << "Lütfen pozitif bir sayý giriniz." << endl;
			
		}
	} while (!(Eleman>0));                   //Eleman negatif girilirse baþa dönüyor
	
	ElemanÝndeksi = Eleman % 101;            //Eleman 101'den büyükse mod'unu alýyoruz, o Ýndekse o elemaný atýyoruz

		if (ElemanDizi[ElemanÝndeksi] != -1)  //Eðer ayný indekste eleman varsa diye kontrol ediyoruz
			cout << "Ýlgili indeks dolu, Eleman eklenemedi." << endl;

		else                                 //Ýndeks boþ ise iþlem uygulanýyor
	{
		ElemanDizi[ElemanÝndeksi] = Eleman;						//Diziye eleman atanýyor
			
			cout << "Eklenen Eleman" << "=" << Eleman << endl;
			cout << "Eleman baþarýyla eklenmiþtir." << endl;         //Doðrulamak için ekran çýktýsý
	}
}
void ElemanListele()                     //Eleman listelemek için fonksiyon
{
	int y = 0;
	for (y = 0; y < 101; y++)          //Tüm elemanlarý sýrayla listelemek için for döngüsü kurdum
	{
		if (ElemanDizi[y] != -1)           //Silinen elemanlarý ya da boþ elemanlarý göstermemesi için kontrol ediyorum
			cout << "[" << y << "]" << "=" << ElemanDizi[y] << endl; //Listenin ekran çýktýsý
	}
}

void ElemanSil()                                      //Eleman silme fonksiyonu
{
	
	int Silinecek = 0;
		do
		{
			cout << "Silinecek Elemaný giriniz:";
			cin >> SilinecekEleman;                           //Silinecek elemaný giriyoruz

			if (SilinecekEleman < 1)                      //Eleman negatif deðer girildiyse kontrol ediyorum
			{
				cout << "Lütfen pozitif bir sayý giriniz." << endl;
			}
		}while (!(SilinecekEleman > 0));
	
		Silinecek = SilinecekEleman % 101;

	if (ElemanDizi[Silinecek] == SilinecekEleman)     //Elemanýn dizide olup olmadýðý kontrol ediliyor
	{
		cout << "Eleman baþarýyla silinmiþtir." << endl;
		ElemanDizi[Silinecek] = -1;				      //Silinecek elemana -1 atýyoruz
	}
	else
	{
	cout << "Eleman bulunamadý." << endl;	         //Eleman dizide yoksa ekran çýktýsý
	}

}

void ElemanAra()                                 //Eleman arama fonksiyonu
{
	int ElemanArama = 0;
	cout << "Aranacak Elemaný giriniz:";
	cin >> ElemanArama;                          //Aranacak elemaný giriyoruz
	Eleman = ElemanArama % 101;
	if (ElemanDizi[Eleman] == ElemanArama)       //Elemanýn dizide olup olmadýðý kontrol ediliyor
		cout << "Eleman dizide var." << endl;	 //Eleman dizide yoksa ekran çýktýsý
	else
	{
		cout << "Eleman  bulunamadý." << endl;    //Eleman varsa ekran çýktýsý
	}
}