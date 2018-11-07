#ifndef DUGUM_HPP
#define DUGUM_HPP

#include <iostream>
#include <string>
using namespace std;

class dugum     //Listenin içinde gezecek düğüm sınıfı
{
private:
	int number;          //Dışarıdan ulaşılamayacak private değerler
	dugum *sonraki;
public:

	void rakamDegis(int a);      //Private değerler için get ve set şeklinde çalışacak fonksiyonlar
	
	int rakamNe();               //sayının get fonk.

	void sonrakiDegis(dugum *x);       //sonraki set fonk.
	
	dugum* sonrakiVer(); 			//sonraki get fonk.
	

};

#endif   