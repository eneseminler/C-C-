/****************************************************************************
**                                SAKARYA ÜNÝVERSÝTESÝ
**                        BÝLGÝSAYAR VE BÝLÝÞÝM BÝLÝMLERÝ FAKÜLTESÝ
**                            BÝLGÝSAYAR MÜHENDÝSLÝÐÝ BÖLÜMÜ
**                              PROGRAMLAMAYA GÝRÝÞÝ DERSÝ
**
**                           ÖDEV NUMARASI…...: Proje Ödevi
**                           ÖÐRENCÝ ADI......: Enes Eminler
**                           ÖÐRENCÝ NUMARASI.: b151210071
**                           DERS GRUBU.......: A grubu
****************************************************************************/

#include <windows.h>       //cmd için kütüphane
#include <fstream>		   //Dosyalama iþlemleri için kütüphane
#include <iostream>        
#include <string>          //String komutlarý için gereken kütüphane
#include <clocale>         //Türkçe karakterler için kütüphane
#include <iomanip>         //Boþluk býrakma(setw) için kütüphane

using namespace std;

int main()
 {
	setlocale(LC_ALL, "turkish");    //Türkçe karakter için komut
	int secim, i = 1;                //Menüde seçim için kullanýlan deðiþken
	//Hasta.txt te kullanýcaklar
	string Hasta_Adi;       //Hasta Adý deðiþken
	string Hasta_Soyadi;    //Hasta Soyadý deðiþken
	string Tc;              //Hasta Tc için deðiþken(Randevuyla Hastayý birbirine baðlýyor
	string Tel;             //Hasta telefon deðiþken
	string Dogum_Tar;       //Hasta doðum tarihi deðiþkeni
	string Hasta_No;        //Hasta no deðiþken

	//Muayene txt te kullanýlacaklar
	string Tarih;            //Randevu tarihi deðiþken
	string Saat;             //Randevu saati  deðiþken
	string DK_Adi;           //Doktor adý deðiþken
	string Teshis;           //Teþhis deðiþken
	string Ýlaclar;          //Alýnacak ilaçlar deðiþken
	string Tahliller;        //Tahliller deðiþken
	string Randevu_No;       //Randevu no deðiþken

	char cevap;             //Ýþlemler sýrasýnda e/h yapýlýrken kullandýðým deðiþken
	do		//Döngü baþlangýcý(10 seçilene kadar döner)
	{

		cout << "\nNe yapmak istiyorsunuz?" << endl;
		cout << "1)Hasta kaydý" << endl;
		cout << "2)Hasta kaydý güncelleme " << endl;
		cout << "3)Hasta silme" << endl;
		cout << "4)Randevu alma" << endl;
		cout << "5)Randevu silme" << endl;
		cout << "6)Randevu güncelleme" << endl;
		cout << "7)Hasta sorgulama" << endl;
		cout << "8)Hasta listesi alma" << endl;
		cout << "9)Hasta muayene kaydý" << endl;
		cout << "10)Çýkýþ" << endl;
		cout << "Seçiminiz=";
		cin >> secim;

		if (secim > 10 || secim < 1)    //Eðer 1'den küçük ya da 10'dan büyük deðer girilirse diye kontrol
			cout << "\nHatalý seçim, lütfen 1 ile 10 arasýnda bir deðer giriniz.\n";

		switch (secim)      //Menü baþlangýcý
		{
		case 1:            //Hasta kaydý seçeneði
		{
			system("cls");
			ofstream DosyaAc;      
			DosyaAc.open("Hasta.txt", ios::app);
			string TC;                                      //Eklenecek Tc yi kontrol etmek için önce baþka bir deðiþkene atýyorum
			string Hasta_no;                                //Eklenecek Hasta no'yu kontrol etmek için önce baþka bir deðiþkene atýyorum
			do
			{
				cout << "\nEklenecek Hasta TC:"; cin >> TC; //Hasta Tc yi alýyorum
				ifstream DosyaOku("Hasta.txt", ios::app);   // Hasta.txt  Dosyasýný düzenleme modunda açýyorum
				while (!DosyaOku.eof())                     //Dosya sonunu görene kadar devam etmesi için sonsuz döngü baþlangýcý
				{
					DosyaOku >> Tc >> Hasta_Adi >> Hasta_Soyadi >> Hasta_No >> Tel >> Dogum_Tar; //Dosyadan deðerleri okuyorum
					if (TC == Tc)                             //Hasta Tc daha önceki Tc'ler ile eþleþiyor mu diye kontol ediyorum
					{
						cout << "Bu Hasta daha önce eklenmiþ." << endl; break;
					}
					else                                      //Hasta Tc dosyaya daha önce eklenmemiþ ise diðer bilgileri giriyoruz
					{
						Hasta_no = Hasta_No;
						Tc = TC;                              //Kontrol etmek için girdiðimiz deðeri asýl Tc ye atýyorum
						cout << "\nHasta Tc: " << Tc;
						cout << "\nHasta Adý:"; cin >> Hasta_Adi;
						cout << "\nHasta Soyadý:"; cin >> Hasta_Soyadi;
						cout << "\nHasta Kayýt No:"; cin >> Hasta_No;

						if (Hasta_no == Hasta_No)            //Daha önce bu Hasta numarasýna baþka numara girilmiþse kontrol ediyorum
						{
							cout << "Bu numarada baþka bir hasta var.\n";
							cout << "Yeni bir Kayýt no giriniz: "; cin >> Hasta_No;
						}
						cout << "\nHasta Telefon(11 Hane):"; cin >> Tel; cin.ignore();
						cout << "\nHasta Doðum Tarihi(Gün/Ay/Yýl): "; cin >> Dogum_Tar;
						DosyaAc << Tc << ' ' << Hasta_Adi << ' ' << Hasta_Soyadi << ' ' << Hasta_No << ' ' << Tel << ' ' << Dogum_Tar << "\n";
							//Dosyaya deðerleri yazýyorum
						break;
					}
				}                                            //While Döngü sonu
				cout << "Baþka kayýt yapacak mýsýn?(e/h)";   //Baþka bir kayýt yapýlacak mý diye 
				cin >> cevap;
			} while (!(cevap == 'h'));                       //Do While döngü sonu
			cout << "\nDosyaya yazým tamamlandý.";
			break;                                           //Hasta ekleme(Case 1) sonu
		}
		case 2:    //Hasta güncelleme seçeneði
		{
			string TC;                        //Girilen Tc yi dosyadakilerle kontrol etmek için deðiþken
			ifstream DosyaOku;                //Okumak için Dosyaokumayý tanýtýyorum
			ofstream DosyaYaz;                //Yazmak için Dosyayazmayý tanýtýyorum
			DosyaOku.open("Hasta.txt");       //Hasta txt i açýyorum
			DosyaYaz.open("Düzenleme.txt", ios::app); //Düzenleme adýnda yeni bir dosya açýyorum
			cout << "Düzenlenecek Hasta TC:"; cin >> TC;

			while (true)
			{     
				DosyaOku >> Tc >> Hasta_Adi >> Hasta_Soyadi >> Hasta_No >> Tel >> Dogum_Tar;  //Hasta.txt ten bilgileri tek tek alýyorum
				if (DosyaOku.eof())	break;      //Dosya sonuna geldiyse iki kez okumamasý için çýkýþ koydum
				if (TC == Tc)                   //Tc dosyadaki bir Tc ile eþit ise
				{
					system("cls");             //Ekraný temizliyorum
					cout << "\nHasta TC......: " << TC << "\nHasta adý soyadý.....: " << Hasta_Adi << " " << Hasta_Soyadi << "\nHasta No......:" << Hasta_No << "\nTelefon.......: " << Tel << "\nDoðum tarihi..: " << Dogum_Tar << "\n\nYeni Bilgiler;\n";
					//Güncellenecek hastanýn bilgilerini ekrana yazdýrýyorum
					cout << "Hasta TC......: "; cin >> Tc;   cin.ignore();             //Yeni deðerleri istiyorum
					cout << "Hasta adý.....: "; cin >> Hasta_Adi;
					cout << "Hasta soyadý..: "; cin >> Hasta_Soyadi; cin.ignore();
					cout << "Hasta No......: "; cin >> Hasta_No;
					cout << "Telefon.......: "; cin >> Tel; cin.ignore();
					cout << "Doðum tarihi..: "; cin >> Dogum_Tar;

					cout << "\t~~Hasta bilgileri güncellendi!~~\n";

				
					DosyaYaz << Tc << " " << Hasta_Adi << " " << Hasta_Soyadi << " " << Hasta_No << " " << Tel << " " << Dogum_Tar << "\n";
					//Yeni Düzenleme dosyasýna yazýyorum yeni bilgileri
				}
				else //Tc dosyadakilerle uyuþmuyorsa
				{
					system("cls");
					cout << "Hasta aranýyor\n";
				//Tüm diðer deðerleri yeni düzenleme dosyasýna yazdýrýyorum
					DosyaYaz << Tc << " " << Hasta_Adi << " " << Hasta_Soyadi << " " << Hasta_No << " " << Tel << " " << Dogum_Tar << "\n";
					if (DosyaOku.eof())
					{
						cout << "Hasta bulunamadý."; break;
					}
				}
				
			}
			DosyaOku.close();  //Hasta txti kapatýyorum
			DosyaYaz.close();  //Düzenleme txt i kapatýyorum
			


			remove("Hasta.txt");     //Hasta.txt i siliyorum
			rename("Düzenleme.txt", "Hasta.txt"); //Düzenleme dosyasýnýn adýný hasta yapýyorum
			remove("Düzenleme.txt");
			break;

		} //Case sonu
		case 3:  //Hasta silme seçeneði
		{
			system("cls");  //Ekraný temizliyorum
			string TC;          //Kontrol için Tc
		
			ifstream DosyaOku;    //Okuma ve yazma için komutlar
			ofstream DosyaYaz;
			ifstream Dosyaoku;
			ofstream Dosyayaz;
		
			Dosyaoku.open("Muayene.txt");          //Muayene dosyasýný açýyorum //Hasta silinince Randevularý da silinecek
			Dosyayaz.open("Düzen.txt", ios::app);  //Randevularý kopyalamak için yeni dosya
			DosyaOku.open("Hasta.txt");            //Hastalarý okumak için açýyorum
			DosyaYaz.open("Silme.txt", ios::app);  //Silinmeyecek hastalarý kopyalamak için dosya

			cout << "Silinecek hasta TC: "; cin >> TC;  
			while (true)       //Döngü baþlangýcý
			{
				Dosyaoku >> Tc >> Randevu_No >> Tarih >> Saat >> DK_Adi >> Teshis >> Ýlaclar >> Tahliller;
				//Randevu dosyasýndan bilgileri okuyorum
				 
				
				DosyaOku >> Tc >> Hasta_Adi >> Hasta_Soyadi >> Hasta_No >> Tel >> Dogum_Tar;
				if (DosyaOku.eof())	break; //Dosya sonlarýna geldilerse çýksýn diye
				if (Dosyaoku.eof())	break; //Ýki kere yazmamalarý için
				
				if (TC == Tc)        //Eðer silinecek Tc yi bulduysa 
				{ 
					system("cls"); //Ekraný temizleyip tüm bilgilerini yazýyorum
					cout << "\nHasta TC......: " << TC << "\nHasta adý soyadý.....: " << Hasta_Adi << " " << Hasta_Soyadi << "\nHasta No......:" << Hasta_No << "\nTelefon.......: " << Tel << "\nDoðum tarihi..: " << Dogum_Tar;

					cout << "\n\nHasta TC......: " << TC << "\nRandevu No......: " << Randevu_No << "\nRandevu Tarih.....: " << Tarih << "\nRandevu Saati....:" << Saat << "\nDoktor Adý......: " << DK_Adi << "\nTeþhis...: " << Teshis << "\nÝlaçlar..: " << Ýlaclar << "\nTahliller...:" << Tahliller << "\n";

					cout << "\n\nKayýt silindi!\n";

					if (DosyaOku.eof()) break;		//	En son kaydý 2 kere okumamasý-yazmamasý için..
					if (Dosyaoku.eof())	break;

				}
				else
				{
					
					system("cls");
					cout << "Hasta aranýyor\n";
					
					//Eðer Tc ler uyuþmadýysa(Diðer hastalarýn bilgileri) hepsini diðer kopya dosyalara yazýyorum
					DosyaYaz << Tc << " " << Hasta_Adi << " " << Hasta_Soyadi << " " << Hasta_No << " " << Tel << " " << Dogum_Tar << "\n";

					Dosyayaz << Tc << " " << Randevu_No << " " << Tarih << " " << Saat << " " << DK_Adi << " " << Teshis << " " << Ýlaclar << " " << Tahliller << "\n";
					if (DosyaOku.eof())
					{
						cout << "Hasta bulunamadý.\n";
						break;
					}
					
				}
			}
			DosyaOku.close();     //Tüm dosyalarý kapatýyorum
			DosyaYaz.close();
			Dosyaoku.close();
			Dosyayaz.close();

			
			remove("Hasta.txt");             //Orjinal dosyalarý silip kopyalarýn adlarýný deðiþtirdim
			rename("Silme.txt", "Hasta.txt");
			remove("Muayene.txt");
			rename("Düzen.txt", "Muayene.txt");
			
			cout << "\t~~Tüm bilgiler güncellendi!~~\n";
			break;
		} //Case sonu
		case 4:  //Randevu kayýt seçeneði
		{
			system("cls");     //Ekraný temizliyorum
			string TC;
			cout << "Hasta TC:";  cin >> TC; 
			
			ifstream DosyaOku("Hasta.txt"); 
			
			while (!DosyaOku.eof())  //Döngü baþlangýcý
			{
				//Hasta.txt ten bilgileri alýyoruz
				DosyaOku >> Tc >> Hasta_Adi >> Hasta_Soyadi >> Hasta_No >> Tel >> Dogum_Tar;
				if (TC == Tc)  //Aradýðýmýz Tc dosyadakiyle eþit ise bilgileri yazdýrýyorum
				{
					cout << "Hasta Bilgileri\n";
					cout << "TC no: " <<  setw(25) << Tc << endl;
					cout << "Hastanýn Adý Soyadý: " << setw(2) << Hasta_Adi << ' ' << Hasta_Soyadi << endl;
					cout << "Hastanýn No: " << setw(10) << Hasta_No << endl;
					cout << "Hastanýn Telefon: " << setw(14) << Tel << endl;
					cout << "Hasta randevu istiyor mu?(e/h)"; cin >> cevap; cout << endl;
					//Randevu konusunda tekrar soruyorum
					if (cevap == 'e')
					{
						DosyaOku.close();
						ofstream DosyaYaz;
						DosyaYaz.open("Muayene.txt", ios::app); //Muayene dosyasýný açýyorum
						cout << "\nRandevu Bilgileri";                     //Randevu bilgilerini istiyorum
						cout << "\nRandevu no: "; cin >> Randevu_No;
						cout << "\nRandevu Tarihi (Gün/Ay/Yýl olarak) :  "; cin >> Tarih;
						cout << "\nRandevu Saati (<__:__> olarak) : "; cin >> Saat;
						cout << "\nDoktor Adý: "; cin >> DK_Adi;
						cout << "\nTeþhis: ";  cin >> Teshis;  cin.ignore();
						cout << "\nÝlaçlar(',' ile ayýrýnýz.) :"; cin >> Ýlaclar;
						cout << "\nTahliller :"; cin >> Tahliller;   cin.ignore();

						DosyaYaz << Tc << ' ' << Randevu_No << ' ' << Tarih << ' ' << Saat << ' ' << DK_Adi << ' ' << Teshis << ' ' << Ýlaclar << ' ' << Tahliller << "\n";
						//Verileri dosyaya yazýyorum ve ardýndan kapatýyorum
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
					cout << "... \nHasta aranýyor." << endl; //Tek tek kontrol edilirken verilecek ekran çýktýsý
					if (DosyaOku.eof())   //Arandýðý halde dosya sonuna gelmiþ ve bulamamýþsa çýkýyor
					{
						cout << "Hasta bulunamadý.\n";
						break;
					}
				}

			}

			cout << "Ana menüye yönlendiriliyorsunuz...\n";
			break;
		}   //Case 4 sonu
		case 5:      //Randevu silme seçeneði
		{
			
				string TC;
				ifstream DosyaOku;             //Dosya açma komutlarý
				ofstream DosyaYaz;
				DosyaOku.open("Muayene.txt");             //Randevularýn olduðu dosya
				DosyaYaz.open("Düzen.txt", ios::app);     //Randevularýn kopyalanacaðý dosya
				cout << "Silinecek Randevu Hasta TC:"; cin >> TC;

				while (true)  //Döngü baþlangýcý
				{
					DosyaOku >> Tc >> Randevu_No >> Tarih >> Saat >> DK_Adi >> Teshis >> Ýlaclar >> Tahliller;
					//Dosyadan Randevu bilgilerini okuyoruz
					if (DosyaOku.eof())	break;
					if (TC == Tc) //Tc dosyadakiyle uyuþursa verileri ekrana veriyor
					{
						system("cls");
						cout << "\nHasta TC......: " << TC << "\nRandevu No......: " << Randevu_No << "\nRandevu Tarih.....: " << Tarih << "\nRandevu Saati....:" << Saat << "\nDoktor Adý......: " << DK_Adi << "\nTeþhis...: " << Teshis << "\nÝlaçlar..: " << Ýlaclar << "\nTahliller...:" << Tahliller << "\n";

						cout << "\n\t~~Randevu bilgileri güncellendi!~~\n";

					}
					else  //Eþit tc yi bulamazsa Düzen.txt e yazýyor
					{
						DosyaYaz << Tc << " " << Randevu_No << " " << Tarih << " " << Saat << " " << DK_Adi << " " << Teshis << " " << Ýlaclar << " " << Tahliller << "\n";
					}

				}
				cout << "Ana menüye yönlendiriliyorsunuz.\n";
				
				DosyaOku.close(); //Dosyalar kapatýlýyor
				DosyaYaz.close();

				remove("Muayene.txt");    //Asýl dosya silinip yedeðin adý deðiþtiriliyor
				rename("Düzen.txt", "Muayene.txt");
				
				break;
		}//Case sonu
		case 6:   //Randevu düzenleme seçeneði
		{
			string TC;
			
			ifstream DosyaOku;   //Dosyalarý açýyoruz
			ofstream DosyaYaz;
			
			DosyaOku.open("Muayene.txt");
			DosyaYaz.open("Düzen.txt", ios::app); //Düzenlenirken kullanýlacak kopya dosya
			
			cout << "Düzenlenecek Randevu Hasta TC:"; cin >> TC;

			while (true)    //Döngü baþlangýcý
			{
				DosyaOku >> Tc >> Randevu_No >> Tarih >> Saat >> DK_Adi >> Teshis >> Ýlaclar >>Tahliller;
				//Dosyadan bilgileri okuyoruz
				if (DosyaOku.eof())	break; //Eðer dosya sonuna geldiyse iki kere okumasýn diye çýkýþ
				
				if (TC == Tc)
				{
					system("cls");
					cout << "\nHasta TC......: " << TC << "\nRandevu No......: " << Randevu_No << "\nRandevu Tarih.....: " << Tarih << "\nRandevu Saati....:" << Saat << "\nDoktor Adý......: " << DK_Adi << "\nTeþhis...: " << Teshis << "\nÝlaçlar..: " << Ýlaclar << "\nTahliller...:" << Tahliller << "\n";
					//Dosyadan sileceðimiz randevuyu bulup ekrana yazýyoruz
					//Yeni bilgileri istiyoruz
					cout << "\n ~~Yeni Bilgiler~~ \n";
					cout << "Randevu No......: "; cin >> Randevu_No;
					cout << "Randevu Tarih.....: "; cin >> Tarih;
					cout << "Randevu Saati....:"; cin >> Saat;
					cout << "Doktor Adý......: "; cin >> DK_Adi;
					cout << "Teþhis...: "; cin >> Teshis;
					cout << "Ýlaçlar..: "; cin >> Ýlaclar;
					cout << "Tahliller...:"; cin >> Tahliller;
						cout << "\n\t~~Randevu bilgileri güncellendi!~~\n";
	
						DosyaYaz << Tc << " " << Randevu_No << " " << Tarih << " " << Saat << " " << DK_Adi << " " << Teshis << Ýlaclar << Tahliller << "\n";
						//Yeni bilgilerimizi kopya dosyaya(Düzen.txt) yazýyoruz
				}
				else
				{		//Tc'si tutmayan diðer randevularý kopya dosyaya yazýyoruz
					DosyaYaz << Tc << " " << Randevu_No << " " << Tarih << " " << Saat << " " << DK_Adi << " " << Teshis << Ýlaclar << Tahliller << "\n";
				}
			}
			DosyaOku.close();
			DosyaYaz.close();

			remove("Muayene.txt");        //Dosyalarý kapatýp isimlerini deðiþtiriyoruz
			rename("Düzen.txt", "Muayene.txt");
			
			break;
		}  //Case sonu
		case 7:  //Hasta sorgulama seçeneði
		{
			system("cls"); 
			string TC; 
			cout << "Hasta TC:";  cin >> TC;

			ifstream DosyaOku("Hasta.txt");  //Hasta dosyasýný açýyoruz

			while (!DosyaOku.eof())       //Döngü baþlangýcý
			{		
				DosyaOku >> Tc >> Hasta_Adi >> Hasta_Soyadi >> Hasta_No >> Tel >> Dogum_Tar;
				//Dosyadan bilgileri okuyoruz

				if ( TC == Tc)  //Hasta bulunursa ekrana yazdýrýyoruz
				{
					cout << "\n---====Hasta Bilgileri====---\n";
					cout << "\nTC no: " << setw(25) << Tc << endl;
					cout << "Hastanýn Adý Soyadý: " << setw(2) << Hasta_Adi << ' ' << Hasta_Soyadi << endl;
					cout << "Hasta No: " << setw(13) << Hasta_No << endl;
					cout << "Hastanýn Telefon: " << setw(14) << Tel << endl;
					cout << "Doðum Tarihi: " << setw(17) << Dogum_Tar << endl;
					break;
				}
				else  //Hasta bulunana kadar her kontrolde ekrana çýktý veriyoruz arandýðýna dair
				{
					cout << "... \nHasta aranýyor." << endl;  

					if (DosyaOku.eof())  //Eðer tüm veriler okunduðu halde hasta bulunamadýysa hata çýktýsý verip devam ediyor
					{
						
						cout << "Hasta bulunamadý.\n";
					
					}
					
				}
			}	
			cout << "Ana menüye yönlendiriliyorsunuz.\n";  //Ýþlem devamýnda yönlendirildiði yeri yazdým
		}
		break;  //Case sonu
		case 8:   //Hasta listeleme modu
		{
			system("cls");

			ifstream Dosyaoku("Hasta.txt");
			
			while (true) //Döngü baþlangýcý dosya sonuna kadar dönecek
			{
				Dosyaoku >> Tc >> Hasta_Adi >> Hasta_Soyadi >> Hasta_No >> Tel >> Dogum_Tar;
				//Dosyadan bilgileri okuyoruz
				if (Dosyaoku.eof())  //Dosya sonuna geldiyse son satýr iki kere okunmasýn diye çýkýþ
				{
					break;
				}
				cout << "\n---====Hasta Bilgileri====---\n";
				cout << "\nTC no: " << setw(25) << Tc << endl;
				cout << "Hastanýn Adý Soyadý: " << setw(2) << Hasta_Adi << ' ' << Hasta_Soyadi << endl;
				cout << "Hastanýn Telefon: " << setw(14) << Tel << endl;

			}
			Dosyaoku.close(); //Dosya kapatýlýyor
			break;
		} //Case sonu
		case 9: //Randevu arama seçeneði
		{
			system("cls");  //Ekraný temizliyorum 
			string TC; 
			cout << " Hasta TC no giriniz:"; cin >> TC;
			ifstream DosyaAc("Hasta.txt");  //Dosya açýlýyor
			
			while (!DosyaAc.eof())  //Hasta dosyasýnýn sonuna kadar dönüyor
			{
				DosyaAc >> Tc >> Hasta_Adi >> Hasta_Soyadi >> Hasta_No >> Tel >> Dogum_Tar;
				//Dosyadan verileri okuyoruz
				if (TC == Tc)  //Eðer Tc uyuþursa bilgilerini ekrana yazdýrýyoruz
				{  
					cout << "\nHasta Bilgileri\n\n";
					cout << "TC no: " << setw(25) << Tc << endl;
					cout << "Hastanýn Adý Soyadý: " << setw(2)<<  Hasta_Adi << ' ' << Hasta_Soyadi << endl;
					cout << "Hastanýn No: " << setw(10) << Hasta_No << endl;
					cout << "Hastanýn Telefon: "<< setw(14) << Tel << endl;
					cout << "Hasta Doðum Tarihi: " << setw(11) << Dogum_Tar << endl;
					
					DosyaAc.close();  //Hasta dosyasýyla iþimiz bitti kapatýyoruz
					ofstream DosyaYaz; 
					DosyaAc.open("Muayene.txt", ios::in);  //Muayene dosyasýný açýyoruz

					cout << "\n Randevu Bilgileri  \n" << endl;
					
					cout << setw(8) << "      TC       " << setw(6) <<"Randevu No" << setw(11) << "Tarih" << setw(12) << "Saat" << setw(18) << "Doktor Adý" << setw(12) << " Teþhis " << setw(17) << "Ýlaçlar" << setw(18) << "Tahliller" << endl;
					//Ekranda tablo halinde olmasý için baþlýklar
					while (!DosyaAc.eof())  //Döngü baþlangýcý randevu dosyasý için
					{
						//Dosyadan verileri okuyoruz
						DosyaAc >> Tc >> Randevu_No >> Tarih >> Saat >> DK_Adi >> Teshis >> Ýlaclar >> Tahliller;
						if (Tc == TC) //Eðer Hastanýn randevusu varsa ekrana veriliyor
						{
							 
							cout << setw(13) << Tc << setw(7) << Randevu_No << setw(19) << Tarih << setw(9) << Saat << setw(15) << DK_Adi << setw(16) << Teshis << setw(14) << Ýlaclar << setw(17) << Tahliller << endl;
							//Setw ile tablo benzeri bir görünüm elde ediyoruz
						}
					}
					DosyaYaz.close();//Dosya kapanýyor
					break;
				}
				else
				{
					system("cls");   //Her kontrolde ekraný temizleyip çýktý veriyor, ekran kalabalýðý önleniyor
					cout << "...\nRandevu aranýyor." << endl;
					if (DosyaAc.eof())  //Eðer dosya sonuna kadar gidip randevu bulamazsa çýktý verip çýkýþ yapýyor
					{
						cout << "Randevu bulunamadý.\n";
						break;
					}
				}

			}
			cout << "\nAna menüye yönlendiriliyorsunuz.\n";
		}//Case sonu
		break;

		case 10:  //Menü Çýkýþ seçeneði
		{
			return 0; //Çýkýþ
		}
		}
	} while (!(secim > 3000000)); //Menü do while döngüsünün sonu
	return 0; //Program çýkýþ
}
