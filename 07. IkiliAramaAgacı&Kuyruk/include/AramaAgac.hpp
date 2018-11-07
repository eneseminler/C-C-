/**        
* @file  VeriYapýlari3.odev
* @description Sayi.txt dosyasýnda yazan sayýlarý okur, böler, kuyruk yapýsý oluþturur, ardýndan bu kuyruklar toplanýp belirli bir düzende Ýkili arama aðacýna ekler. 
* @course  1.Öðretim C Grubu  
* @assignment  3.Ödev  
* @date    07.12.2016
* @author  Enes Eminler enes.eminler@ogr.sakarya.edu.tr    
*/
#ifndef AramaAgac_HPP
#define AramaAgac_HPP 	

#include <cmath>
#include <iostream>
using namespace std;

struct Dugum{
	int veri;
	Dugum *sol;
	Dugum *sag;
	Dugum(const int& vr,Dugum *sl=NULL,Dugum *sg=NULL){
		veri=vr;
		sol=sl;
		sag=sg;
	}
};


class AramaAgac{
	private:
		Dugum *root;
		
		void AraveEkle(Dugum *&alt_Dugum, const int &yeni){
			if(alt_Dugum == NULL) alt_Dugum = new Dugum(yeni);
			else if(yeni < alt_Dugum->veri)
				AraveEkle(alt_Dugum->sol,yeni);
			else if(yeni > alt_Dugum->veri)
				AraveEkle(alt_Dugum->sag,yeni);
			else return; // Ayný eleman var.
		}
		bool AraveSil(Dugum *&alt_Dugum,const int &yeni)
		{			
			if(alt_Dugum == NULL) return false; //Eleman yok
			if(alt_Dugum->veri == yeni)
				return DugumSil(alt_Dugum);
			else if(yeni < alt_Dugum->veri)
				return AraveSil(alt_Dugum->sol,yeni);
			else
				return AraveSil(alt_Dugum->sag,yeni);
		}
		bool DugumSil(Dugum *&alt_Dugum)
		{			
			Dugum *silinecekDugum = alt_Dugum;
			
			if(alt_Dugum->sag == NULL) alt_Dugum = alt_Dugum->sol;
			else if(alt_Dugum->sol == NULL)alt_Dugum = alt_Dugum->sag;
			else{
				silinecekDugum = alt_Dugum->sol;
				Dugum *ebeveynDugum = alt_Dugum;
				while(silinecekDugum->sag != NULL){
					ebeveynDugum=silinecekDugum;
					silinecekDugum=silinecekDugum->sag;
				}
				alt_Dugum->veri = silinecekDugum->veri;
				if(ebeveynDugum == alt_Dugum) alt_Dugum->sol = silinecekDugum->sol;
				else ebeveynDugum->sag = silinecekDugum->sol;
			}
			delete silinecekDugum;
			return true;
		}
		void Inorder(Dugum *alt_Dugum) const{
			if(alt_Dugum != NULL){
				Inorder(alt_Dugum->sol);
				cout<<alt_Dugum->veri<<" ";
				Inorder(alt_Dugum->sag);
			}
		}
		void Preorder(Dugum *alt_Dugum) const{
			if(alt_Dugum != NULL){
				cout<<alt_Dugum->veri<<" ";
				Preorder(alt_Dugum->sol);
				Preorder(alt_Dugum->sag);
			}
		}
		void Postorder(Dugum *alt_Dugum) const{
			if(alt_Dugum != NULL){
				Postorder(alt_Dugum->sol);
				Postorder(alt_Dugum->sag);				
				cout<<alt_Dugum->veri<<" ";
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
			void Ekle(const int &yeni)
			{
				AraveEkle(root,yeni);
			}
			void Sil(const int &veri)
			{
				if(AraveSil(root,veri) == false) {}
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