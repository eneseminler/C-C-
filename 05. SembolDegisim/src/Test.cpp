#include <cstdlib>
#include "Kart.hpp"


int main()
{
	Kart<string> *kartlar = new Kart<string>();
	int sec=0;
	int sayi=0;
	string kart = "kart";
	do{
		system("CLS");
		cout<<"1.Isim Ekle"<<endl;
		cout<<"2.Isim Sil"<<endl;
		cout<<"3.Konumdan Isim Sil"<<endl;
		cout<<"4.Konuma Isim Ekle"<<endl;
		cout<<"5.Konum Bul"<<endl;
		cout<<"6.Isim Sayisi"<<endl;
		cout<<"7.Ilk Isim"<<endl;
		cout<<"8.Son Isim"<<endl;
		cout<<"9.Isimleri Listele"<<endl;
		cout<<"10.Isimleri Temizle"<<endl;
		cout<<"Secim:";
		
		cout<<"kart sayisi girin";
			cin.ignore();
			getline(cin,sayi);
		for(int i=0; i< sayi;i++){
			
		char *intStr = itoa(i);
		string str = string(intStr);
			
		isimler->add(kart+str)
		}
		
		cout << "Kartlar";
		cout << *kartlar << endl;
		cin.ignore();
		cin.get();
			
		cout << "Seçiminiz: "; cin>> sec;
			
		switch(sec){
		case 1:
			cout << "kart çevir 2 tane" << endl;
        break;		
		case 2: 
			cout <<"ters çevir"<<endl; 
		break;	
		}	
	}while(sec != 0);
		delete kartlar;
		
}