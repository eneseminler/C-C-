
#ifndef AramaAgac_HPP
#define AramaAgac_HPP 	
	
#include <cmath>
#include <iostream>
using namespace std;

struct Dugum{
	string veri;
	Dugum *sol;
	Dugum *sag;
	//AramaAgac *sehirler = new AramaAgac(); 
	Dugum(const string& vr,Dugum *sl=NULL,Dugum *sg=NULL){
		veri=vr;
		sol=sl;
		sag=sg;	
	}
};

class AramaAgac{
	private:
		Dugum *root;
		
		void AraveEkle(Dugum *&alt_Dugum, const string &yeni, const string &sehir){
			cout << "Fonksiyon: " << yeni << endl;
			if(alt_Dugum == NULL)
			{	
			alt_Dugum = new Dugum(yeni);
			//alt_Dugum->sehirler->Ekle(sehir);
	        cout << yeni << " " << sehir << endl;
			}
			else if(yeni < alt_Dugum->veri)
			{
			AraveEkle(alt_Dugum->sol,yeni,sehir);
			}
			else if(yeni > alt_Dugum->veri)
			{
			AraveEkle(alt_Dugum->sag,yeni,sehir);
			}
			else
			{
			//alt_Dugum->sehirler->Ekle(sehir);
			return; // Ayný ülke var.
			}
		}
	
		void Inorder(Dugum *alt_Dugum) const{
			if(alt_Dugum != NULL){
				Inorder(alt_Dugum->sol);
				cout<<alt_Dugum->veri<<" ";
				//Inorder(alt_Dugum->sehirler);
				Inorder(alt_Dugum->sag);
			}
		}
		void Preorder(Dugum *alt_Dugum) const{
			if(alt_Dugum != NULL){
				cout<<alt_Dugum->veri<<" ";
				Preorder(alt_Dugum->sehirler);
				Preorder(alt_Dugum->sol);
				Preorder(alt_Dugum->sag);
			}
		}
		void Postorder(Dugum *alt_Dugum) const{
			if(alt_Dugum != NULL){
				Postorder(alt_Dugum->sol);
				Postorder(alt_Dugum->sag);				
				cout<<alt_Dugum->veri<<" ";
				Postorder(alt_Dugum->sehirler);
			}
		}		
		int Yukseklik(Dugum *alt_Dugum){
			if(alt_Dugum == NULL) return -1; // Ortada düðüm yoksa yükseklik anlamsýzdýr. Hata da fýrlatýlabilir.
			return 1+max(Yukseklik(alt_Dugum->sol),Yukseklik(alt_Dugum->sag));
		}
		public:
			AramaAgac(){
				root = NULL;
			}
			bool Bosmu() const{
				return root == NULL;
			}
			void Ekle(const string &yeni,const string &sehir)
			{
				AraveEkle(root,yeni,sehir);
			}
		
			void Inorder() const{
				Inorder(root);
			}
			void Preorder() const{
				Preorder(root);
			}
			void Postorder() const{
				Postorder(root);
			}
			void Temizle(){
				while(!Bosmu()) DugumSil(root);
			}
			int Yukseklik(){
				return Yukseklik(root);
			}
			~AramaAgac(){
				Temizle();
			}		
};

#endif