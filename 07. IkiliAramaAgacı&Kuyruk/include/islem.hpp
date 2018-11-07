/**        
* @file  VeriYapılari3.odev
* @description Sayi.txt dosyasında yazan sayıları okur, böler, kuyruk yapısı oluşturur, ardından bu kuyruklar toplanıp belirli bir düzende İkili arama ağacına ekler. 
* @course  1.Öğretim C Grubu  
* @assignment  3.Ödev  
* @date    07.12.2016
* @author  Enes Eminler enes.eminler@ogr.sakarya.edu.tr      
*/
#ifndef ISLEM_HPP
#define ISLEM_HPP

#include <iostream>
#include <string>	//Stringlerle çalışırken ihtiyacımız olan kütüphane
#include "Kuyruk.hpp"


class islem 
{

private:
	bagliKuyruk *liste;	//Kuyruk nesnesi oluşturuluyor

	public:
		int Bolum(char a){		//Bölme fonksiyonu
			
		
			//Sayılar rakam rakam yollanır, inte çevrilip geri yollanır.
					int rakam = a - '0';
					
				//	cout << "Sayi" << ": " << rakam << endl; //Kontrol amaçlı ekrana yazdırılır
			
					return rakam; //Sayı geri yollanır
		}



};




#endif
