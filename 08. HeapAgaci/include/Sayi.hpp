#ifndef SAYI_HPP
#define SAYI_HPP
#include <iostream>
#include <string>
using namespace std;

			
class sayi								//Sayı sınıfı
{										//Hafızasında sadece uzun sayıyı tutar
	private:
	string degerler;
	public:
	void degerekle(string a);       //Değer set fonk.
	long int degerver(); 					//Değer get fonk.


};

#endif