#include "Sayi.hpp"

#include <sstream>

#include "stdio.h"
#include <iostream>
#include <fstream>
#include <sstream>

#include <string>


void sayi::degerekle(string a)        //Değer set fonk.
	{
		degerler=a;
	}
long int sayi::degerver() 					//Değer get fonk.
	{
		long int b = 0;
        b = strtol(degerler);
		return b;
	}

