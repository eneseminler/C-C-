#ifndef KART_HPP
#define KART_HPP



template <typename Nesne>
class Kart{
	private:
	Nesne *elemanlar;
	int kartsayisi;
	int kapasite;
	public:
	Kart()
	{
		kartsayisi=0;
		elemanlar= NULL;
	}
	Kart(const Kart &sag){
		kartsayisi=0;
		elemanlar = new Nesne[sag->length()];
		for(int i=0; i<sag.size(); i++){
			insert(i,sag.at(i));
		}
	}
	void add(const Nesne& yeni)//en sona ekler
	{
		elemanlar[kartsayisi] = yeni;
		kartsayisi++;
	}
	int length() const{
		return kartsayisi;
	}
	
	
	
	~Kart()
	{
		delete [] elemanlar;
	}
	
	
};

#endif