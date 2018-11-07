#ifndef SAYI_HPP
#define SAYI_HPP
#include <iostream>
#include <string>
using namespace std;
#include "bagilListe.hpp"
			
class sayi								//Sayı sınıfı
{										//Hafızasında sadece uzun sayıyı tutar
	private:
	string degerler;
	public:
	void degerekle(string a);       //Değer set fonk.
	string degerver(); 					//Değer get fonk.
	

	friend istream& operator>>(istream& girdi,sayi& sag)  //Sayıyı dışarıdan alırken kullanmak üzere friend fonksiyonu
	{												
	
			girdi >> sag.degerler;
			return girdi;
			
	};

};

#endif