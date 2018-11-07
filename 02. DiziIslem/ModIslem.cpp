/****************************************************************************
**                         SAKARYA �N�VERS�TES�
**               B�LG�SAYAR VE B�L���M B�L�MLER� FAK�LTES�
**                   B�LG�SAYAR M�HEND�SL��� B�L�M�
**                     Programlamaya Giri� Dersi
**                       2015-2016 G�Z D�NEM�
**
**               �DEV NUMARASI: 2. �dev
**               ��RENC� ADI: Enes EM�NLER
**               ��RENC� NUMARASI: b151210071
**               DERS�N ALINDI�I GRUP: A Grubu
****************************************************************************/
#include <iostream>
#include <clocale>            //Dil tercihi i�in k�t�phane
#include <cstdlib>

void ElemanEkle();            //Eleman eklemek i�in kulland���m fonksiyon
void ElemanListele();         //Eleman listelemek i�in kulland���m fonksiyon
void ElemanAra();             //Eleman aramak i�in kulland���m fonksiyon 
void ElemanSil();             //Eleman silmek i�in kulland���m fonksiyon

int ElemanDizi[101];          //Programda kulland���m�z diziyi tan�mlad�k
int Eleman = 0;               //Dizi Elemanlar� yerine kullanaca��m�z de�i�ken
int Eleman�ndeksi;            //Elemanlar�n dizideki s�ras�n� belirlerken kulland���m�z de�i�ken
int SilinecekEleman;          //Eleman� silerken kullanaca��m�z de�i�ken
int i = 0;

using namespace std;

int main(int argc, char*argv[])
{
	setlocale(LC_ALL, "turkish");          //T�rk�e karakter kodu

	int Secenek = 0;            //Men�de girilecek se�ene�in de�i�keni
	{
		for (i = 0; i <= 101; i++)
		{
			ElemanDizi[i] = -1;
		}
	}
	do                                    //Men�n�n s�rekli d�nmesi i�in do-while d�ng�s� kullan�yorum 
	{
		cout << endl;
		cout << "1- Eleman Ekle" << endl;	  //Men�n�n ekran ��kt�s�n� veriyoruz.
		cout << "2- Eleman Sil" << endl;
		cout << "3- Eleman Ara" << endl;
		cout << "4- Eleman Listele" << endl;
		cout << "5- ��k��" << endl;
		cout << "Se�enek=";
		cin >> Secenek;                   //Men�den se�ti�imiz tercihi giriyoruz


		if (Secenek>5)                         //Se�ene�in 5 ten b�y�k girilmesine kar�� kontrol ettiriyorum.
			cout << "Hatal� se�enek." << endl;


		switch (Secenek)                      //Men�den se�ti�imiz tercihe ilerlemek i�in Switch-Case kullan�yorum
		{
		case 1:
			ElemanEkle();                     //Eleman ekleme fonksiyonunu �a��r�yorum
			break;
		case 2:
			ElemanSil();                      //Eleman silme fonksiyonunu �a��r�yorum
			break;
		case 3:
			ElemanAra();                      //Eleman arama fonksiyonunu �a��r�yorum
			break;
		case 4:
			ElemanListele();                  //Eleman listeleme fonksiyonunun �a��r�yorum
			break;
		case 5:
			return 0;                         //Men�den ��kmak istersek diye ��k�� se�ene�i
		}

	} while (Secenek <= 100000);            //D�ng�n�n sonu, men�y� s�rekli ba�a d�nd�r�yor

	return 0;                             //Program sonu
}

void ElemanEkle()                         //Eleman Ekleme fonksiyonu
{
	do
	{
		cout << "Eklenecek eleman� giriniz:";
		cin >> Eleman;			 		     //Eklenecek eleman� giriyoruz

		if (Eleman < 1)                      //Eleman negatif de�er girildiyse kontrol ediyorum
		{
			cout << "L�tfen pozitif bir say� giriniz." << endl;
			
		}
	} while (!(Eleman>0));                   //Eleman negatif girilirse ba�a d�n�yor
	
	Eleman�ndeksi = Eleman % 101;            //Eleman 101'den b�y�kse mod'unu al�yoruz, o �ndekse o eleman� at�yoruz

		if (ElemanDizi[Eleman�ndeksi] != -1)  //E�er ayn� indekste eleman varsa diye kontrol ediyoruz
			cout << "�lgili indeks dolu, Eleman eklenemedi." << endl;

		else                                 //�ndeks bo� ise i�lem uygulan�yor
	{
		ElemanDizi[Eleman�ndeksi] = Eleman;						//Diziye eleman atan�yor
			
			cout << "Eklenen Eleman" << "=" << Eleman << endl;
			cout << "Eleman ba�ar�yla eklenmi�tir." << endl;         //Do�rulamak i�in ekran ��kt�s�
	}
}
void ElemanListele()                     //Eleman listelemek i�in fonksiyon
{
	int y = 0;
	for (y = 0; y < 101; y++)          //T�m elemanlar� s�rayla listelemek i�in for d�ng�s� kurdum
	{
		if (ElemanDizi[y] != -1)           //Silinen elemanlar� ya da bo� elemanlar� g�stermemesi i�in kontrol ediyorum
			cout << "[" << y << "]" << "=" << ElemanDizi[y] << endl; //Listenin ekran ��kt�s�
	}
}

void ElemanSil()                                      //Eleman silme fonksiyonu
{
	
	int Silinecek = 0;
		do
		{
			cout << "Silinecek Eleman� giriniz:";
			cin >> SilinecekEleman;                           //Silinecek eleman� giriyoruz

			if (SilinecekEleman < 1)                      //Eleman negatif de�er girildiyse kontrol ediyorum
			{
				cout << "L�tfen pozitif bir say� giriniz." << endl;
			}
		}while (!(SilinecekEleman > 0));
	
		Silinecek = SilinecekEleman % 101;

	if (ElemanDizi[Silinecek] == SilinecekEleman)     //Eleman�n dizide olup olmad��� kontrol ediliyor
	{
		cout << "Eleman ba�ar�yla silinmi�tir." << endl;
		ElemanDizi[Silinecek] = -1;				      //Silinecek elemana -1 at�yoruz
	}
	else
	{
	cout << "Eleman bulunamad�." << endl;	         //Eleman dizide yoksa ekran ��kt�s�
	}

}

void ElemanAra()                                 //Eleman arama fonksiyonu
{
	int ElemanArama = 0;
	cout << "Aranacak Eleman� giriniz:";
	cin >> ElemanArama;                          //Aranacak eleman� giriyoruz
	Eleman = ElemanArama % 101;
	if (ElemanDizi[Eleman] == ElemanArama)       //Eleman�n dizide olup olmad��� kontrol ediliyor
		cout << "Eleman dizide var." << endl;	 //Eleman dizide yoksa ekran ��kt�s�
	else
	{
		cout << "Eleman  bulunamad�." << endl;    //Eleman varsa ekran ��kt�s�
	}
}