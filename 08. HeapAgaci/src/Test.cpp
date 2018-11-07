#include "HeapTree.hpp"
#include <cstdlib>
#include <fstream>	
#include "Sayi.cpp"
#include <string>
#include <iostream>

int main(){
	
	
	HeapAgac *heapAgac = new HeapAgac();
	ifstream Dosyaoku("Sayilar.txt");	
	
	while (true) { 		

	sayi *k = new sayi();
			
	Dosyaoku >> k->degerekle();	
	cout << k->degerver() << " ";		
		
		
		heapAgaci->Ekle(k);
				
													
		if (Dosyaoku.eof()) {	
			Dosyaoku.close();
			break;
		}

	}
	
	
		cout<<endl<<"En buyuk: "<<endl;

	
		int a;
		
		 a = heapAgaci->EnKucuguCikar();
		 cout << a << endl;
	
		ofstream DosyaAc;      
		DosyaAc.open("sirali.txt", ios::app);
		while(!heapAgaci->Bosmu()){
		DosyaAc << heapAgaci->EnKucuguCikar() << '\n';
		        
	}
	DosyaOku.close();
	DosyaAc.close();
	delete heapAgaci;
	return 0;
}