/**
* @file Node.cpp
* @description AVL aðacý kullanarak sayýlar bulma
* @course 1.Öðretim A
* @assignment 2.Ödev
* @date 16.08.2022
* @author Ecem AMANVERMEZ
*/

#include "Node.hpp"

Node::Node(int* sayilar, int uzunluk,int toplam, Node *sag, Node *sol) {
	
	
	this->sag = sag;
	this->sol = sol;
	yukseklik = 0;
	
	this->sayilar = sayilar;

	this->uzunluk = uzunluk;
	
	this->toplam = toplam;
	
}


void Node::sayiSil(int konum){
	if(uzunluk>1){
		if(konum == 0){
			cout<<toplam<<": nolu dugum asagi indigi icin dizideki en kucuk "<<sayilar[0]<< " sayisi silinmistir"<<endl;
			sayilar = &sayilar[1];	
		}
			
		else{
			cout<<toplam<<": nolu dugum yukari ciktigi icin dizideki en buyuk "<<sayilar[uzunluk-1]<< " sayisi silinmistir"<<endl;			
		}
			
		uzunluk--;
		

	}
}

ostream& operator<<(ostream &screen,const Node &right)
{
	
	cout << right.toplam << ": ";
	for(int i = 0; i < right.uzunluk; i++){
		cout<<right.sayilar[i]<< " ";
	}
	
	return screen;
}




		

