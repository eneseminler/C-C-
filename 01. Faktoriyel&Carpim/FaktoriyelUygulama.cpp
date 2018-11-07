/***************************************************************************
**                               SAKARYA ÜNÝVERSÝTESÝ
**                     BÝLGÝSAYAR VE BÝLÝÞÝM BÝLÝMLERÝ FAKÜLTESÝ
**                        BÝLGÝSAYAR MÜHENDÝSLÝÐÝ BÖLÜMÜ
**                       NESNEYE DAYALI PROGRAMLAMA DERSÝ
**                             2015-2016 GÜZ DÖNEMÝ
**                           
**                      ÖDEV NUMARASI: 1.ÖDEV
**                      ÖÐRENCÝ ADI: ENES EMÝNLER
**                      ÖÐRENCÝ NUMARASI: b151210071
**                      DERSÝN ALINDIÐI GRUP: A GRUBU
*****************************************************************************/

#include <iostream>													
#include <clocale>													//Dile özel karakterler için kütüphane.
#include <string>													//Deðiþkenlerle çalýþýrken kullanacaðýmýz kütüphane.
#include <iomanip>													//Deðerler arasý boþluk býrakma kodu için gerekli kütüphane.
using namespace std;
int main()
{
	setlocale(LC_ALL, "turkish");										  	//Türkçe karakterler için gerekli olan kod.

	long int ksayýsý = 0, tsayýsý = 0, a, b, n, çarpým;				        //Ýþlem içinde kullanýlacak deðiþkenleri tanýmladýk.
	long int toplam, geneltoplam = 0, aratoplam, faktöriyel;			    	//Ýþlem içinde kullanýlacak fonksiyonlarý tanýmladýk.
		
	while (!(ksayýsý > 5 && ksayýsý < 10) || !(tsayýsý>1 && tsayýsý < 9))   //Ýstediðimiz deðerleri elde edene kadar tekrar etmesi için while döngüsü kullandým.
	{
		cout << "k deðerini giriniz <k 5'ten büyük ve 10'dan küçük olmalý> :";
			cin >> ksayýsý;
			
		cout << "t deðerini giriniz <t 1'den büyük ve 9'dan küçük olmalý> :";
			cin >> tsayýsý;

		if (ksayýsý < 5 || ksayýsý>9)
			cout << "\t Yanlýþ k deðeri girdiniz. \n";

		if (tsayýsý < 1 || tsayýsý>8)
			cout << "\t Yanlýþ t deðeri girdiniz. \n";
	}

			cout << setw(3) << "Faktöriyel" << setw(15) << "Çarpým" << "\t\t" << "Aratoplam" << endl; //Tablonun baþlýklarýný ekrana düzenli þekilde yazdýrýyorum.
	
	for (n = 1; n <= ksayýsý; n++)							//For döngüsü ile 1'den k deðerine kadar olan sayýlarý hesapladým.
	
	{
		faktöriyel = 1;										//iþleme girmeden önce Faktöriyel için bir ilk deðer atadým.

			for (a = 1; a <= n; a++)						//For döngüsü ile faktöriyeli hesaplanacak sayýlarý oluþturdum.
	
			{

				faktöriyel = faktöriyel*a;					//Faktöriyel iþlemini tanýmladýk.Döngü içinde çalýþmasýný saðladým.
			}

				çarpým = 1;
			
				for (b = n; b <= tsayýsý; b++)				//For döngüsü ile iþleme girecek sayýlarý oluþturdum.

				{
					çarpým = çarpým * 2 * b;				//Çarpým iþlemini tanýttým.
				}


		
		toplam = 0;
		aratoplam = faktöriyel + çarpým;					//Tabloda karþýmýza çýkan her sayý için yaptýðýmýz aratoplamý gösterdim.	
		geneltoplam += aratoplam;				   		 //Tüm aratoplamlarý toplayýp tüm yaptýðýmýz iþlemin sonucunu tanýttým.
		 
		//Setw() deðerler ya da kelimeler arasýnda ekranda boþluklarý ayarlamak amacýyla kullandým.

		cout << setw(10) << faktöriyel;
		cout << setw(5) << "+";
		cout << setw(11) << çarpým;
		cout << "\t=";
		cout << "\t" << aratoplam << endl;


	}

		cout << endl << "Toplam=" << geneltoplam << endl; //Ýþlem sonucu.


		system("pause");
	return 0;
}