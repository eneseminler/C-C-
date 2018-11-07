
#include "Dugum.hpp"

void dugum::rakamDegis(int x)      //Private değerler için get ve set şeklinde çalışacak fonksiyonlar
	{
		number = x;             //sayının set fonk.
	}
int dugum::rakamNe()               //sayının get fonk.
	{
		return number;
	}
void dugum::sonrakiDegis(dugum *x)       //sonraki set fonk.
	{
		sonraki = x;
	}
dugum* dugum::sonrakiVer() 			//sonraki get fonk.
	{
		return sonraki;
	}
