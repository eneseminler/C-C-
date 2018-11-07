/***************************************************************************
**                               SAKARYA �N�VERS�TES�
**                     B�LG�SAYAR VE B�L���M B�L�MLER� FAK�LTES�
**                        B�LG�SAYAR M�HEND�SL��� B�L�M�
**                       NESNEYE DAYALI PROGRAMLAMA DERS�
**                             2015-2016 G�Z D�NEM�
**                           
**                      �DEV NUMARASI: 1.�DEV
**                      ��RENC� ADI: ENES EM�NLER
**                      ��RENC� NUMARASI: b151210071
**                      DERS�N ALINDI�I GRUP: A GRUBU
*****************************************************************************/

#include <iostream>													
#include <clocale>													//Dile �zel karakterler i�in k�t�phane.
#include <string>													//De�i�kenlerle �al���rken kullanaca��m�z k�t�phane.
#include <iomanip>													//De�erler aras� bo�luk b�rakma kodu i�in gerekli k�t�phane.
using namespace std;
int main()
{
	setlocale(LC_ALL, "turkish");										  	//T�rk�e karakterler i�in gerekli olan kod.

	long int ksay�s� = 0, tsay�s� = 0, a, b, n, �arp�m;				        //��lem i�inde kullan�lacak de�i�kenleri tan�mlad�k.
	long int toplam, geneltoplam = 0, aratoplam, fakt�riyel;			    	//��lem i�inde kullan�lacak fonksiyonlar� tan�mlad�k.
		
	while (!(ksay�s� > 5 && ksay�s� < 10) || !(tsay�s�>1 && tsay�s� < 9))   //�stedi�imiz de�erleri elde edene kadar tekrar etmesi i�in while d�ng�s� kulland�m.
	{
		cout << "k de�erini giriniz <k 5'ten b�y�k ve 10'dan k���k olmal�> :";
			cin >> ksay�s�;
			
		cout << "t de�erini giriniz <t 1'den b�y�k ve 9'dan k���k olmal�> :";
			cin >> tsay�s�;

		if (ksay�s� < 5 || ksay�s�>9)
			cout << "\t Yanl�� k de�eri girdiniz. \n";

		if (tsay�s� < 1 || tsay�s�>8)
			cout << "\t Yanl�� t de�eri girdiniz. \n";
	}

			cout << setw(3) << "Fakt�riyel" << setw(15) << "�arp�m" << "\t\t" << "Aratoplam" << endl; //Tablonun ba�l�klar�n� ekrana d�zenli �ekilde yazd�r�yorum.
	
	for (n = 1; n <= ksay�s�; n++)							//For d�ng�s� ile 1'den k de�erine kadar olan say�lar� hesaplad�m.
	
	{
		fakt�riyel = 1;										//i�leme girmeden �nce Fakt�riyel i�in bir ilk de�er atad�m.

			for (a = 1; a <= n; a++)						//For d�ng�s� ile fakt�riyeli hesaplanacak say�lar� olu�turdum.
	
			{

				fakt�riyel = fakt�riyel*a;					//Fakt�riyel i�lemini tan�mlad�k.D�ng� i�inde �al��mas�n� sa�lad�m.
			}

				�arp�m = 1;
			
				for (b = n; b <= tsay�s�; b++)				//For d�ng�s� ile i�leme girecek say�lar� olu�turdum.

				{
					�arp�m = �arp�m * 2 * b;				//�arp�m i�lemini tan�tt�m.
				}


		
		toplam = 0;
		aratoplam = fakt�riyel + �arp�m;					//Tabloda kar��m�za ��kan her say� i�in yapt���m�z aratoplam� g�sterdim.	
		geneltoplam += aratoplam;				   		 //T�m aratoplamlar� toplay�p t�m yapt���m�z i�lemin sonucunu tan�tt�m.
		 
		//Setw() de�erler ya da kelimeler aras�nda ekranda bo�luklar� ayarlamak amac�yla kulland�m.

		cout << setw(10) << fakt�riyel;
		cout << setw(5) << "+";
		cout << setw(11) << �arp�m;
		cout << "\t=";
		cout << "\t" << aratoplam << endl;


	}

		cout << endl << "Toplam=" << geneltoplam << endl; //��lem sonucu.


		system("pause");
	return 0;
}