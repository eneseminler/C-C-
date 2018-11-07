#ifndef SEMBOL_HPP
#define SEMBOL_HPP



template <typename Nesne>
class Sembol{
	private:
	Nesne *elemanlar;
	int sembolsayisi;
	char sembol;
	public:
	Sembol()
	{
		sembolsayisi=0;
		elemanlar= NULL;
		
	}
	Sembol(const Sembol &sag){
		sembolsayisi=0;
		elemanlar = new Nesne[sag->length()];
		for(int i=0; i<sag.size(); i++){
			insert(i,sag.at(i));
		}
	}
	void ata(const Nesne& yeni)//en sona ekler
	{
		elemanlar[sembolsayisi] = yeni;
		sembolsayisi++;
	}
	int uzunluk() const{
		return sembolsayisi;
	}
	
	
	
	~Sembol()
	{
		delete [] elemanlar;
	}
	
	
};

#endif