/****************************************************************************
**                                SAKARYA �N�VERS�TES�
**                        B�LG�SAYAR VE B�L���M B�L�MLER� FAK�LTES�
**                            B�LG�SAYAR M�HEND�SL��� B�L�M�
**                              PROGRAMLAMAYA G�R��� DERS�
**
**                           �DEV NUMARASI�...: 3. ve 4. �dev
**                           ��RENC� ADI......: Enes Eminler
**                           ��RENC� NUMARASI.: b151210071
**                           DERS GRUBU.......: A grubu
****************************************************************************/

#include <iostream>
#include <string>
#include <clocale>                        //T�rk�e karakter i�in k�t�phane

using namespace std;

int �zYine(int x);                        //1.se�enekteki �zyineleme fonksiyonu tan�t�m� 
double alan(struct dikd�rtgen);			  //2.se�enekteki dikd�rtgenin alan�n� hesaplamak i�in fonksiyonun tan�t�m�
int nokta(struct dikd�rtgen, int, int, int ,int);   //2.se�enekteki noktan�n alan�n i�inde olup olmad���n� kontrol i�in fonksiyon tan�t�m�
void BuyukKucuk(char*);					  //3.se�enekteki harf de�i�imi i�in fonksiyon tan�t�m�
void yerdegistir(char **dizia, char **dizib);		      //4.se�enekteki yer de�i�tirme i�in fonksiyon tan�t�m�

struct dikd�rtgen                         //Dikd�rtgen yap�s�
{
	int en, boy;
};


          
int main() {

	setlocale(LC_ALL, "turkish");       //T�rk�e karakterleri kullanabilmemiz i�in komut

	int islem = 0;   
	int Alan;								//Alan fonksiyonunda alan hesaplan�rken kullan�lan de�i�ken
	char kelime[10];                        //Harfleri b�y�k k���k de�i�tirelecek kelimenin de�i�keni//Men� se�ene�i i�in de�i�ken
	char *dizi1 = "C++";                    //Yeri de�i�tirilecek birinci dizi
	char *dizi2 = "Programlama";            //Yeri de�i�tirilecek ikinci dizi

	do									//D�ng� ba�lang�c�
	{
		cout << "\n1-�zyinelemeli/Yinelemeli Fonksiyon" << endl;
		cout << "2-Dikd�rtgen Yap�s�" << endl;
		cout << "3-B�y�k-K���k harf de�i�imi" << endl;
		cout << "4-�ki karakter dizisinin yer de�i�imi" << endl;
		cout << "5-Programdan ��k��" << endl;
		cout << "\nL�tfen bir i�lem se�iniz:";
		cin >> islem;
		cout << endl;

		if ((islem > 5) || (islem < 1))								//Men�de olmayan de�er girilmesine kar�� �nlem
		{
			cout << "L�tfen 1 ile 5 aras�nda bir de�er giriniz:";
			cin >> islem;
			cout << endl;
		}

		switch (islem)
		{
		case 1:         //�zyineleme i�leminin kullan�ld��� se�enek
			int N;							 //�zyinelemede kullan�lacak de�er

			cout << "N de�erini giriniz:";
			cin >> N;
			cout << "�zyineli F(" << N << ") = " << �zYine(N) << endl;

			break;
		case 2:			//Alan,nokta i�leminin kullan�ld��� se�enek

			int x, y;								//Dikd�rtgenin ba�layaca�� k��e koordinatlar�n�n adlar�
			cout << "Dikd�rtgenin k��e koordinatlar�n� giriniz:" << endl << "X:";
				cin >> x;
			cout << "Y:";
				cin >> y;

			dikd�rtgen Dikd�rtgen;       //Alan� hesaplanacak dikd�rtgenin de�i�keni
			cout << endl << "Dikd�rtgenin en ve boy bilgilerini giriniz." << endl << "En:"; 
				cin >> Dikd�rtgen.en;
			cout << "Boy:";
				cin >> Dikd�rtgen.boy;

			long int x1, y1;
			cout << "\nNokta koordinatlar�n� giriniz:" << endl << "Birinci nokta:";
				cin >> x1;
			cout << "�kinci nokta";
				cin >> y1;

			cout << "\nDikd�rtgenin alan�:" << alan(Dikd�rtgen) << endl;  //Alan� hesaplans�n diye fonksiyonu Dikd�rtgen i�in �a��rd�m
			
			cout << "Belirtti�iniz dikd�rtgen i�inde mi?: ";
			nokta(Dikd�rtgen, x,y, x1, y1);    //Nokta alan�n i�inde mi diye noktalar ve dikd�rtgen i�in fonksiyonu �a��rd�m

			break;
		case 3:	   		//Harflerin de�i�im i�leminin yap�ld��� se�enek

			cout << "S�z dizisini giriniz<En fazla 10 harf>: ";
				cin >> kelime;
	
			BuyukKucuk(kelime);           //kelimemizin harflerinin yeri de�i�mesi i�in fonksiyonu �a��rd�m

			break;
		case 4:        //De�i�tirme i�leminin kullan�ld��� se�enek

			cout << "�lk dizi            :" << dizi1 << endl;
			cout << "�kinci dizi         :" << dizi2 << endl;

			yerdegistir(&dizi1, &dizi2);		//Dizilerin yer de�i�tirmesi i�in fonksiyonu �a��rd�m

			cout << "\n�lk dizi            :" << dizi1 << endl;
			cout << "�kinci dizi         :" << dizi2 << endl;

			break;
		case 5:          //��k�� i�leminin yap�ld��� se�enek

			return 0;						//5. se�enek se�ildi�inde kapanmas� i�in return 0;
		}

	} while (islem <= 100000);				//D�ng� sonu

	return 0;
}	   				 //Program sonu


int �zYine(int x)	 //�zyineleme fonksiyonu
{
	{
		if (x == 0)
			return 1;
		else if (x == 1)
			return 2;
		else if (x > 1)
			return 2 * �zYine(x - 1) - 2 * (x - 1)*�zYine(x - 2);
	}
	return x;
};

double alan(dikd�rtgen A)    //Dikd�rtgenin alan�n� hesaplayan program
{
	int Alan;

	Alan = A.en*A.boy;

	return Alan;
};

int nokta(dikd�rtgen Bir, int a,int b, int a1, int b1)   //Nokta dikd�rtgenin i�inde mi diye kontrol eden fonksiyon
{

	{
		if (!(a1 <= a + Bir.en && a1 >= a) && !(b1 <= b + Bir.boy && b1 >= b))

			cout << "0" << endl;

		else

			cout << "1" << endl;
	}
	return 1;
};

void BuyukKucuk(char *harf)		//K���k harfi b�y�k, b�y�k harfi k���k yapan fonksiyon
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

void yerdegistir(char **dizia, char **dizib)   //Dizilerin yerlerini de�i�tiren fonksiyon
{
	char *kopyadizi;						//Diziler de�i�tirilirken kullan�lacak kopya de�i�ken

	kopyadizi = *dizia;
	*dizia = *dizib;
	*dizib= kopyadizi;
};
