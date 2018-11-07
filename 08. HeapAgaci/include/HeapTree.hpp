#ifndef HEAPTREE_HPP
#define HEAPTREE_HPP
#include "Sayi.hpp"
#include <string>
#include <iostream>
using namespace std;

// Küçükten büyüðe sýralayan (Min Heap Tree)
class HeapTree{
	private:
		long int *elemanlar;
		int dugumSayisi;
		int kapasite;
		
		int SolCocukIndeks(int);
		int SagCocukIndeks(int);
		int EbeveynDugumIndeks(int);
		void HeapYukari(int);
		void HeapAsagi(int);
	public:
		HeapTree(int);
		bool Bosmu();
		void Ekle(sayi a);
		int EnKucuguCikar()throw(string);
		~HeapTree();
};

#endif