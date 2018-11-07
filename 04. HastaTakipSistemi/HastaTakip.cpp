/****************************************************************************
**                                SAKARYA �N�VERS�TES�
**                        B�LG�SAYAR VE B�L���M B�L�MLER� FAK�LTES�
**                            B�LG�SAYAR M�HEND�SL��� B�L�M�
**                              PROGRAMLAMAYA G�R��� DERS�
**
**                           �DEV NUMARASI�...: Proje �devi
**                           ��RENC� ADI......: Enes Eminler
**                           ��RENC� NUMARASI.: b151210071
**                           DERS GRUBU.......: A grubu
****************************************************************************/

#include <windows.h>       //cmd i�in k�t�phane
#include <fstream>		   //Dosyalama i�lemleri i�in k�t�phane
#include <iostream>        
#include <string>          //String komutlar� i�in gereken k�t�phane
#include <clocale>         //T�rk�e karakterler i�in k�t�phane
#include <iomanip>         //Bo�luk b�rakma(setw) i�in k�t�phane

using namespace std;

int main()
 {
	setlocale(LC_ALL, "turkish");    //T�rk�e karakter i�in komut
	int secim, i = 1;                //Men�de se�im i�in kullan�lan de�i�ken
	//Hasta.txt te kullan�caklar
	string Hasta_Adi;       //Hasta Ad� de�i�ken
	string Hasta_Soyadi;    //Hasta Soyad� de�i�ken
	string Tc;              //Hasta Tc i�in de�i�ken(Randevuyla Hastay� birbirine ba�l�yor
	string Tel;             //Hasta telefon de�i�ken
	string Dogum_Tar;       //Hasta do�um tarihi de�i�keni
	string Hasta_No;        //Hasta no de�i�ken

	//Muayene txt te kullan�lacaklar
	string Tarih;            //Randevu tarihi de�i�ken
	string Saat;             //Randevu saati  de�i�ken
	string DK_Adi;           //Doktor ad� de�i�ken
	string Teshis;           //Te�his de�i�ken
	string �laclar;          //Al�nacak ila�lar de�i�ken
	string Tahliller;        //Tahliller de�i�ken
	string Randevu_No;       //Randevu no de�i�ken

	char cevap;             //��lemler s�ras�nda e/h yap�l�rken kulland���m de�i�ken
	do		//D�ng� ba�lang�c�(10 se�ilene kadar d�ner)
	{

		cout << "\nNe yapmak istiyorsunuz?" << endl;
		cout << "1)Hasta kayd�" << endl;
		cout << "2)Hasta kayd� g�ncelleme " << endl;
		cout << "3)Hasta silme" << endl;
		cout << "4)Randevu alma" << endl;
		cout << "5)Randevu silme" << endl;
		cout << "6)Randevu g�ncelleme" << endl;
		cout << "7)Hasta sorgulama" << endl;
		cout << "8)Hasta listesi alma" << endl;
		cout << "9)Hasta muayene kayd�" << endl;
		cout << "10)��k��" << endl;
		cout << "Se�iminiz=";
		cin >> secim;

		if (secim > 10 || secim < 1)    //E�er 1'den k���k ya da 10'dan b�y�k de�er girilirse diye kontrol
			cout << "\nHatal� se�im, l�tfen 1 ile 10 aras�nda bir de�er giriniz.\n";

		switch (secim)      //Men� ba�lang�c�
		{
		case 1:            //Hasta kayd� se�ene�i
		{
			system("cls");
			ofstream DosyaAc;      
			DosyaAc.open("Hasta.txt", ios::app);
			string TC;                                      //Eklenecek Tc yi kontrol etmek i�in �nce ba�ka bir de�i�kene at�yorum
			string Hasta_no;                                //Eklenecek Hasta no'yu kontrol etmek i�in �nce ba�ka bir de�i�kene at�yorum
			do
			{
				cout << "\nEklenecek Hasta TC:"; cin >> TC; //Hasta Tc yi al�yorum
				ifstream DosyaOku("Hasta.txt", ios::app);   // Hasta.txt  Dosyas�n� d�zenleme modunda a��yorum
				while (!DosyaOku.eof())                     //Dosya sonunu g�rene kadar devam etmesi i�in sonsuz d�ng� ba�lang�c�
				{
					DosyaOku >> Tc >> Hasta_Adi >> Hasta_Soyadi >> Hasta_No >> Tel >> Dogum_Tar; //Dosyadan de�erleri okuyorum
					if (TC == Tc)                             //Hasta Tc daha �nceki Tc'ler ile e�le�iyor mu diye kontol ediyorum
					{
						cout << "Bu Hasta daha �nce eklenmi�." << endl; break;
					}
					else                                      //Hasta Tc dosyaya daha �nce eklenmemi� ise di�er bilgileri giriyoruz
					{
						Hasta_no = Hasta_No;
						Tc = TC;                              //Kontrol etmek i�in girdi�imiz de�eri as�l Tc ye at�yorum
						cout << "\nHasta Tc: " << Tc;
						cout << "\nHasta Ad�:"; cin >> Hasta_Adi;
						cout << "\nHasta Soyad�:"; cin >> Hasta_Soyadi;
						cout << "\nHasta Kay�t No:"; cin >> Hasta_No;

						if (Hasta_no == Hasta_No)            //Daha �nce bu Hasta numaras�na ba�ka numara girilmi�se kontrol ediyorum
						{
							cout << "Bu numarada ba�ka bir hasta var.\n";
							cout << "Yeni bir Kay�t no giriniz: "; cin >> Hasta_No;
						}
						cout << "\nHasta Telefon(11 Hane):"; cin >> Tel; cin.ignore();
						cout << "\nHasta Do�um Tarihi(G�n/Ay/Y�l): "; cin >> Dogum_Tar;
						DosyaAc << Tc << ' ' << Hasta_Adi << ' ' << Hasta_Soyadi << ' ' << Hasta_No << ' ' << Tel << ' ' << Dogum_Tar << "\n";
							//Dosyaya de�erleri yaz�yorum
						break;
					}
				}                                            //While D�ng� sonu
				cout << "Ba�ka kay�t yapacak m�s�n?(e/h)";   //Ba�ka bir kay�t yap�lacak m� diye 
				cin >> cevap;
			} while (!(cevap == 'h'));                       //Do While d�ng� sonu
			cout << "\nDosyaya yaz�m tamamland�.";
			break;                                           //Hasta ekleme(Case 1) sonu
		}
		case 2:    //Hasta g�ncelleme se�ene�i
		{
			string TC;                        //Girilen Tc yi dosyadakilerle kontrol etmek i�in de�i�ken
			ifstream DosyaOku;                //Okumak i�in Dosyaokumay� tan�t�yorum
			ofstream DosyaYaz;                //Yazmak i�in Dosyayazmay� tan�t�yorum
			DosyaOku.open("Hasta.txt");       //Hasta txt i a��yorum
			DosyaYaz.open("D�zenleme.txt", ios::app); //D�zenleme ad�nda yeni bir dosya a��yorum
			cout << "D�zenlenecek Hasta TC:"; cin >> TC;

			while (true)
			{     
				DosyaOku >> Tc >> Hasta_Adi >> Hasta_Soyadi >> Hasta_No >> Tel >> Dogum_Tar;  //Hasta.txt ten bilgileri tek tek al�yorum
				if (DosyaOku.eof())	break;      //Dosya sonuna geldiyse iki kez okumamas� i�in ��k�� koydum
				if (TC == Tc)                   //Tc dosyadaki bir Tc ile e�it ise
				{
					system("cls");             //Ekran� temizliyorum
					cout << "\nHasta TC......: " << TC << "\nHasta ad� soyad�.....: " << Hasta_Adi << " " << Hasta_Soyadi << "\nHasta No......:" << Hasta_No << "\nTelefon.......: " << Tel << "\nDo�um tarihi..: " << Dogum_Tar << "\n\nYeni Bilgiler;\n";
					//G�ncellenecek hastan�n bilgilerini ekrana yazd�r�yorum
					cout << "Hasta TC......: "; cin >> Tc;   cin.ignore();             //Yeni de�erleri istiyorum
					cout << "Hasta ad�.....: "; cin >> Hasta_Adi;
					cout << "Hasta soyad�..: "; cin >> Hasta_Soyadi; cin.ignore();
					cout << "Hasta No......: "; cin >> Hasta_No;
					cout << "Telefon.......: "; cin >> Tel; cin.ignore();
					cout << "Do�um tarihi..: "; cin >> Dogum_Tar;

					cout << "\t~~Hasta bilgileri g�ncellendi!~~\n";

				
					DosyaYaz << Tc << " " << Hasta_Adi << " " << Hasta_Soyadi << " " << Hasta_No << " " << Tel << " " << Dogum_Tar << "\n";
					//Yeni D�zenleme dosyas�na yaz�yorum yeni bilgileri
				}
				else //Tc dosyadakilerle uyu�muyorsa
				{
					system("cls");
					cout << "Hasta aran�yor\n";
				//T�m di�er de�erleri yeni d�zenleme dosyas�na yazd�r�yorum
					DosyaYaz << Tc << " " << Hasta_Adi << " " << Hasta_Soyadi << " " << Hasta_No << " " << Tel << " " << Dogum_Tar << "\n";
					if (DosyaOku.eof())
					{
						cout << "Hasta bulunamad�."; break;
					}
				}
				
			}
			DosyaOku.close();  //Hasta txti kapat�yorum
			DosyaYaz.close();  //D�zenleme txt i kapat�yorum
			


			remove("Hasta.txt");     //Hasta.txt i siliyorum
			rename("D�zenleme.txt", "Hasta.txt"); //D�zenleme dosyas�n�n ad�n� hasta yap�yorum
			remove("D�zenleme.txt");
			break;

		} //Case sonu
		case 3:  //Hasta silme se�ene�i
		{
			system("cls");  //Ekran� temizliyorum
			string TC;          //Kontrol i�in Tc
		
			ifstream DosyaOku;    //Okuma ve yazma i�in komutlar
			ofstream DosyaYaz;
			ifstream Dosyaoku;
			ofstream Dosyayaz;
		
			Dosyaoku.open("Muayene.txt");          //Muayene dosyas�n� a��yorum //Hasta silinince Randevular� da silinecek
			Dosyayaz.open("D�zen.txt", ios::app);  //Randevular� kopyalamak i�in yeni dosya
			DosyaOku.open("Hasta.txt");            //Hastalar� okumak i�in a��yorum
			DosyaYaz.open("Silme.txt", ios::app);  //Silinmeyecek hastalar� kopyalamak i�in dosya

			cout << "Silinecek hasta TC: "; cin >> TC;  
			while (true)       //D�ng� ba�lang�c�
			{
				Dosyaoku >> Tc >> Randevu_No >> Tarih >> Saat >> DK_Adi >> Teshis >> �laclar >> Tahliller;
				//Randevu dosyas�ndan bilgileri okuyorum
				 
				
				DosyaOku >> Tc >> Hasta_Adi >> Hasta_Soyadi >> Hasta_No >> Tel >> Dogum_Tar;
				if (DosyaOku.eof())	break; //Dosya sonlar�na geldilerse ��ks�n diye
				if (Dosyaoku.eof())	break; //�ki kere yazmamalar� i�in
				
				if (TC == Tc)        //E�er silinecek Tc yi bulduysa 
				{ 
					system("cls"); //Ekran� temizleyip t�m bilgilerini yaz�yorum
					cout << "\nHasta TC......: " << TC << "\nHasta ad� soyad�.....: " << Hasta_Adi << " " << Hasta_Soyadi << "\nHasta No......:" << Hasta_No << "\nTelefon.......: " << Tel << "\nDo�um tarihi..: " << Dogum_Tar;

					cout << "\n\nHasta TC......: " << TC << "\nRandevu No......: " << Randevu_No << "\nRandevu Tarih.....: " << Tarih << "\nRandevu Saati....:" << Saat << "\nDoktor Ad�......: " << DK_Adi << "\nTe�his...: " << Teshis << "\n�la�lar..: " << �laclar << "\nTahliller...:" << Tahliller << "\n";

					cout << "\n\nKay�t silindi!\n";

					if (DosyaOku.eof()) break;		//	En son kayd� 2 kere okumamas�-yazmamas� i�in..
					if (Dosyaoku.eof())	break;

				}
				else
				{
					
					system("cls");
					cout << "Hasta aran�yor\n";
					
					//E�er Tc ler uyu�mad�ysa(Di�er hastalar�n bilgileri) hepsini di�er kopya dosyalara yaz�yorum
					DosyaYaz << Tc << " " << Hasta_Adi << " " << Hasta_Soyadi << " " << Hasta_No << " " << Tel << " " << Dogum_Tar << "\n";

					Dosyayaz << Tc << " " << Randevu_No << " " << Tarih << " " << Saat << " " << DK_Adi << " " << Teshis << " " << �laclar << " " << Tahliller << "\n";
					if (DosyaOku.eof())
					{
						cout << "Hasta bulunamad�.\n";
						break;
					}
					
				}
			}
			DosyaOku.close();     //T�m dosyalar� kapat�yorum
			DosyaYaz.close();
			Dosyaoku.close();
			Dosyayaz.close();

			
			remove("Hasta.txt");             //Orjinal dosyalar� silip kopyalar�n adlar�n� de�i�tirdim
			rename("Silme.txt", "Hasta.txt");
			remove("Muayene.txt");
			rename("D�zen.txt", "Muayene.txt");
			
			cout << "\t~~T�m bilgiler g�ncellendi!~~\n";
			break;
		} //Case sonu
		case 4:  //Randevu kay�t se�ene�i
		{
			system("cls");     //Ekran� temizliyorum
			string TC;
			cout << "Hasta TC:";  cin >> TC; 
			
			ifstream DosyaOku("Hasta.txt"); 
			
			while (!DosyaOku.eof())  //D�ng� ba�lang�c�
			{
				//Hasta.txt ten bilgileri al�yoruz
				DosyaOku >> Tc >> Hasta_Adi >> Hasta_Soyadi >> Hasta_No >> Tel >> Dogum_Tar;
				if (TC == Tc)  //Arad���m�z Tc dosyadakiyle e�it ise bilgileri yazd�r�yorum
				{
					cout << "Hasta Bilgileri\n";
					cout << "TC no: " <<  setw(25) << Tc << endl;
					cout << "Hastan�n Ad� Soyad�: " << setw(2) << Hasta_Adi << ' ' << Hasta_Soyadi << endl;
					cout << "Hastan�n No: " << setw(10) << Hasta_No << endl;
					cout << "Hastan�n Telefon: " << setw(14) << Tel << endl;
					cout << "Hasta randevu istiyor mu?(e/h)"; cin >> cevap; cout << endl;
					//Randevu konusunda tekrar soruyorum
					if (cevap == 'e')
					{
						DosyaOku.close();
						ofstream DosyaYaz;
						DosyaYaz.open("Muayene.txt", ios::app); //Muayene dosyas�n� a��yorum
						cout << "\nRandevu Bilgileri";                     //Randevu bilgilerini istiyorum
						cout << "\nRandevu no: "; cin >> Randevu_No;
						cout << "\nRandevu Tarihi (G�n/Ay/Y�l olarak) :  "; cin >> Tarih;
						cout << "\nRandevu Saati (<__:__> olarak) : "; cin >> Saat;
						cout << "\nDoktor Ad�: "; cin >> DK_Adi;
						cout << "\nTe�his: ";  cin >> Teshis;  cin.ignore();
						cout << "\n�la�lar(',' ile ay�r�n�z.) :"; cin >> �laclar;
						cout << "\nTahliller :"; cin >> Tahliller;   cin.ignore();

						DosyaYaz << Tc << ' ' << Randevu_No << ' ' << Tarih << ' ' << Saat << ' ' << DK_Adi << ' ' << Teshis << ' ' << �laclar << ' ' << Tahliller << "\n";
						//Verileri dosyaya yaz�yorum ve ard�ndan kapat�yorum
						DosyaYaz.close();
						break;
					}
					else
					{
						break;
					}
				}
				else
				{

					system("cls");
					cout << "... \nHasta aran�yor." << endl; //Tek tek kontrol edilirken verilecek ekran ��kt�s�
					if (DosyaOku.eof())   //Arand��� halde dosya sonuna gelmi� ve bulamam��sa ��k�yor
					{
						cout << "Hasta bulunamad�.\n";
						break;
					}
				}

			}

			cout << "Ana men�ye y�nlendiriliyorsunuz...\n";
			break;
		}   //Case 4 sonu
		case 5:      //Randevu silme se�ene�i
		{
			
				string TC;
				ifstream DosyaOku;             //Dosya a�ma komutlar�
				ofstream DosyaYaz;
				DosyaOku.open("Muayene.txt");             //Randevular�n oldu�u dosya
				DosyaYaz.open("D�zen.txt", ios::app);     //Randevular�n kopyalanaca�� dosya
				cout << "Silinecek Randevu Hasta TC:"; cin >> TC;

				while (true)  //D�ng� ba�lang�c�
				{
					DosyaOku >> Tc >> Randevu_No >> Tarih >> Saat >> DK_Adi >> Teshis >> �laclar >> Tahliller;
					//Dosyadan Randevu bilgilerini okuyoruz
					if (DosyaOku.eof())	break;
					if (TC == Tc) //Tc dosyadakiyle uyu�ursa verileri ekrana veriyor
					{
						system("cls");
						cout << "\nHasta TC......: " << TC << "\nRandevu No......: " << Randevu_No << "\nRandevu Tarih.....: " << Tarih << "\nRandevu Saati....:" << Saat << "\nDoktor Ad�......: " << DK_Adi << "\nTe�his...: " << Teshis << "\n�la�lar..: " << �laclar << "\nTahliller...:" << Tahliller << "\n";

						cout << "\n\t~~Randevu bilgileri g�ncellendi!~~\n";

					}
					else  //E�it tc yi bulamazsa D�zen.txt e yaz�yor
					{
						DosyaYaz << Tc << " " << Randevu_No << " " << Tarih << " " << Saat << " " << DK_Adi << " " << Teshis << " " << �laclar << " " << Tahliller << "\n";
					}

				}
				cout << "Ana men�ye y�nlendiriliyorsunuz.\n";
				
				DosyaOku.close(); //Dosyalar kapat�l�yor
				DosyaYaz.close();

				remove("Muayene.txt");    //As�l dosya silinip yede�in ad� de�i�tiriliyor
				rename("D�zen.txt", "Muayene.txt");
				
				break;
		}//Case sonu
		case 6:   //Randevu d�zenleme se�ene�i
		{
			string TC;
			
			ifstream DosyaOku;   //Dosyalar� a��yoruz
			ofstream DosyaYaz;
			
			DosyaOku.open("Muayene.txt");
			DosyaYaz.open("D�zen.txt", ios::app); //D�zenlenirken kullan�lacak kopya dosya
			
			cout << "D�zenlenecek Randevu Hasta TC:"; cin >> TC;

			while (true)    //D�ng� ba�lang�c�
			{
				DosyaOku >> Tc >> Randevu_No >> Tarih >> Saat >> DK_Adi >> Teshis >> �laclar >>Tahliller;
				//Dosyadan bilgileri okuyoruz
				if (DosyaOku.eof())	break; //E�er dosya sonuna geldiyse iki kere okumas�n diye ��k��
				
				if (TC == Tc)
				{
					system("cls");
					cout << "\nHasta TC......: " << TC << "\nRandevu No......: " << Randevu_No << "\nRandevu Tarih.....: " << Tarih << "\nRandevu Saati....:" << Saat << "\nDoktor Ad�......: " << DK_Adi << "\nTe�his...: " << Teshis << "\n�la�lar..: " << �laclar << "\nTahliller...:" << Tahliller << "\n";
					//Dosyadan silece�imiz randevuyu bulup ekrana yaz�yoruz
					//Yeni bilgileri istiyoruz
					cout << "\n ~~Yeni Bilgiler~~ \n";
					cout << "Randevu No......: "; cin >> Randevu_No;
					cout << "Randevu Tarih.....: "; cin >> Tarih;
					cout << "Randevu Saati....:"; cin >> Saat;
					cout << "Doktor Ad�......: "; cin >> DK_Adi;
					cout << "Te�his...: "; cin >> Teshis;
					cout << "�la�lar..: "; cin >> �laclar;
					cout << "Tahliller...:"; cin >> Tahliller;
						cout << "\n\t~~Randevu bilgileri g�ncellendi!~~\n";
	
						DosyaYaz << Tc << " " << Randevu_No << " " << Tarih << " " << Saat << " " << DK_Adi << " " << Teshis << �laclar << Tahliller << "\n";
						//Yeni bilgilerimizi kopya dosyaya(D�zen.txt) yaz�yoruz
				}
				else
				{		//Tc'si tutmayan di�er randevular� kopya dosyaya yaz�yoruz
					DosyaYaz << Tc << " " << Randevu_No << " " << Tarih << " " << Saat << " " << DK_Adi << " " << Teshis << �laclar << Tahliller << "\n";
				}
			}
			DosyaOku.close();
			DosyaYaz.close();

			remove("Muayene.txt");        //Dosyalar� kapat�p isimlerini de�i�tiriyoruz
			rename("D�zen.txt", "Muayene.txt");
			
			break;
		}  //Case sonu
		case 7:  //Hasta sorgulama se�ene�i
		{
			system("cls"); 
			string TC; 
			cout << "Hasta TC:";  cin >> TC;

			ifstream DosyaOku("Hasta.txt");  //Hasta dosyas�n� a��yoruz

			while (!DosyaOku.eof())       //D�ng� ba�lang�c�
			{		
				DosyaOku >> Tc >> Hasta_Adi >> Hasta_Soyadi >> Hasta_No >> Tel >> Dogum_Tar;
				//Dosyadan bilgileri okuyoruz

				if ( TC == Tc)  //Hasta bulunursa ekrana yazd�r�yoruz
				{
					cout << "\n---====Hasta Bilgileri====---\n";
					cout << "\nTC no: " << setw(25) << Tc << endl;
					cout << "Hastan�n Ad� Soyad�: " << setw(2) << Hasta_Adi << ' ' << Hasta_Soyadi << endl;
					cout << "Hasta No: " << setw(13) << Hasta_No << endl;
					cout << "Hastan�n Telefon: " << setw(14) << Tel << endl;
					cout << "Do�um Tarihi: " << setw(17) << Dogum_Tar << endl;
					break;
				}
				else  //Hasta bulunana kadar her kontrolde ekrana ��kt� veriyoruz arand���na dair
				{
					cout << "... \nHasta aran�yor." << endl;  

					if (DosyaOku.eof())  //E�er t�m veriler okundu�u halde hasta bulunamad�ysa hata ��kt�s� verip devam ediyor
					{
						
						cout << "Hasta bulunamad�.\n";
					
					}
					
				}
			}	
			cout << "Ana men�ye y�nlendiriliyorsunuz.\n";  //��lem devam�nda y�nlendirildi�i yeri yazd�m
		}
		break;  //Case sonu
		case 8:   //Hasta listeleme modu
		{
			system("cls");

			ifstream Dosyaoku("Hasta.txt");
			
			while (true) //D�ng� ba�lang�c� dosya sonuna kadar d�necek
			{
				Dosyaoku >> Tc >> Hasta_Adi >> Hasta_Soyadi >> Hasta_No >> Tel >> Dogum_Tar;
				//Dosyadan bilgileri okuyoruz
				if (Dosyaoku.eof())  //Dosya sonuna geldiyse son sat�r iki kere okunmas�n diye ��k��
				{
					break;
				}
				cout << "\n---====Hasta Bilgileri====---\n";
				cout << "\nTC no: " << setw(25) << Tc << endl;
				cout << "Hastan�n Ad� Soyad�: " << setw(2) << Hasta_Adi << ' ' << Hasta_Soyadi << endl;
				cout << "Hastan�n Telefon: " << setw(14) << Tel << endl;

			}
			Dosyaoku.close(); //Dosya kapat�l�yor
			break;
		} //Case sonu
		case 9: //Randevu arama se�ene�i
		{
			system("cls");  //Ekran� temizliyorum 
			string TC; 
			cout << " Hasta TC no giriniz:"; cin >> TC;
			ifstream DosyaAc("Hasta.txt");  //Dosya a��l�yor
			
			while (!DosyaAc.eof())  //Hasta dosyas�n�n sonuna kadar d�n�yor
			{
				DosyaAc >> Tc >> Hasta_Adi >> Hasta_Soyadi >> Hasta_No >> Tel >> Dogum_Tar;
				//Dosyadan verileri okuyoruz
				if (TC == Tc)  //E�er Tc uyu�ursa bilgilerini ekrana yazd�r�yoruz
				{  
					cout << "\nHasta Bilgileri\n\n";
					cout << "TC no: " << setw(25) << Tc << endl;
					cout << "Hastan�n Ad� Soyad�: " << setw(2)<<  Hasta_Adi << ' ' << Hasta_Soyadi << endl;
					cout << "Hastan�n No: " << setw(10) << Hasta_No << endl;
					cout << "Hastan�n Telefon: "<< setw(14) << Tel << endl;
					cout << "Hasta Do�um Tarihi: " << setw(11) << Dogum_Tar << endl;
					
					DosyaAc.close();  //Hasta dosyas�yla i�imiz bitti kapat�yoruz
					ofstream DosyaYaz; 
					DosyaAc.open("Muayene.txt", ios::in);  //Muayene dosyas�n� a��yoruz

					cout << "\n Randevu Bilgileri  \n" << endl;
					
					cout << setw(8) << "      TC       " << setw(6) <<"Randevu No" << setw(11) << "Tarih" << setw(12) << "Saat" << setw(18) << "Doktor Ad�" << setw(12) << " Te�his " << setw(17) << "�la�lar" << setw(18) << "Tahliller" << endl;
					//Ekranda tablo halinde olmas� i�in ba�l�klar
					while (!DosyaAc.eof())  //D�ng� ba�lang�c� randevu dosyas� i�in
					{
						//Dosyadan verileri okuyoruz
						DosyaAc >> Tc >> Randevu_No >> Tarih >> Saat >> DK_Adi >> Teshis >> �laclar >> Tahliller;
						if (Tc == TC) //E�er Hastan�n randevusu varsa ekrana veriliyor
						{
							 
							cout << setw(13) << Tc << setw(7) << Randevu_No << setw(19) << Tarih << setw(9) << Saat << setw(15) << DK_Adi << setw(16) << Teshis << setw(14) << �laclar << setw(17) << Tahliller << endl;
							//Setw ile tablo benzeri bir g�r�n�m elde ediyoruz
						}
					}
					DosyaYaz.close();//Dosya kapan�yor
					break;
				}
				else
				{
					system("cls");   //Her kontrolde ekran� temizleyip ��kt� veriyor, ekran kalabal��� �nleniyor
					cout << "...\nRandevu aran�yor." << endl;
					if (DosyaAc.eof())  //E�er dosya sonuna kadar gidip randevu bulamazsa ��kt� verip ��k�� yap�yor
					{
						cout << "Randevu bulunamad�.\n";
						break;
					}
				}

			}
			cout << "\nAna men�ye y�nlendiriliyorsunuz.\n";
		}//Case sonu
		break;

		case 10:  //Men� ��k�� se�ene�i
		{
			return 0; //��k��
		}
		}
	} while (!(secim > 3000000)); //Men� do while d�ng�s�n�n sonu
	return 0; //Program ��k��
}
