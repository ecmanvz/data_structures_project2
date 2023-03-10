/**
* @file AVL.cpp
* @description AVL aðacý kullanarak sayýlar bulma
* @author Ecem
*/


#include "AVL.hpp"

Node* AVL::AraVeEkle(Node *altDugum, int* yeni, int uzunluk, int toplam){
	if(altDugum == NULL) altDugum = new Node(yeni, uzunluk, toplam);
	
	else if(toplam <= altDugum->toplam){

		altDugum->sol = AraVeEkle(altDugum->sol,yeni,uzunluk, toplam);
		
		if(Yukseklik(altDugum->sol) == Yukseklik(altDugum->sag)+2){
			if(altDugum->sol !=NULL)
				SeviyeUp(altDugum->sol);
			
			if(altDugum->sag !=NULL)
				SeviyeDown(altDugum->sag);
			altDugum->sayiSil(1);
			
			if(toplam < altDugum->sol->toplam)
				altDugum = SolCocukIleDegistir(altDugum);
				
			
			else{
				altDugum->sol = SagCocukIleDegistir(altDugum->sol);
				altDugum = SolCocukIleDegistir(altDugum);
			}			
		}
	}
	
	else if(toplam > altDugum->toplam){

		altDugum->sag = AraVeEkle(altDugum->sag, yeni, uzunluk, toplam);
		
		if(Yukseklik(altDugum->sag) == Yukseklik(altDugum->sol)+2){
			if(altDugum->sag !=NULL)
				SeviyeUp(altDugum->sag);
			
			if(altDugum->sol !=NULL)
				SeviyeDown(altDugum->sol);
			altDugum->sayiSil(1);
			
			
			if(toplam > altDugum->sag->toplam)
				altDugum = SagCocukIleDegistir(altDugum);
			else{
				altDugum->sag = SolCocukIleDegistir(altDugum->sag);
				altDugum = SagCocukIleDegistir(altDugum);
				
			}	
		}
	}
	
	else;
	
	
	altDugum->yukseklik = Yukseklik(altDugum);
	return altDugum;
}

Node* AVL::SolCocukIleDegistir(Node* altDugum){
	Node* tmp = altDugum->sol;

	altDugum->sol = tmp->sag;
	tmp->sag = altDugum;
	
	altDugum->yukseklik = Yukseklik(altDugum);
	tmp->yukseklik = 1+max(Yukseklik(tmp->sol),altDugum->yukseklik);
	return tmp;
	
}

void AVL::SeviyeUp(Node* dugum){
	dugum->sayiSil(0);
	if(dugum->sol != NULL)
		SeviyeUp(dugum->sol);
	if(dugum->sag != NULL)
		SeviyeUp(dugum->sag);
	
	
}

void AVL::SeviyeDown(Node* dugum){
	dugum->sayiSil(1);
	if(dugum->sol != NULL)
		SeviyeDown(dugum->sol);
	if(dugum->sag != NULL)
		SeviyeDown(dugum->sag);
	
}


Node* AVL::SagCocukIleDegistir(Node* altDugum){
	Node* tmp = altDugum->sag;
	altDugum->sag = tmp->sol;
	tmp->sol = altDugum;
	
	altDugum->yukseklik = Yukseklik(altDugum);
	tmp->yukseklik = 1+max(Yukseklik(tmp->sag),altDugum->yukseklik);
	return tmp;
}

bool AVL::DugumSil(Node *&altDugum){
	Node *silinecekDugum = altDugum;
	
	if(altDugum->sag == NULL) altDugum=altDugum->sol;
	else if(altDugum->sol == NULL) altDugum = altDugum->sag;
	else{
		silinecekDugum = altDugum->sol;
		Node *ebeveynDugum = altDugum;
		while(silinecekDugum->sag != NULL){
			ebeveynDugum = silinecekDugum;
			silinecekDugum = silinecekDugum->sag;
		}
		altDugum->sayilar = silinecekDugum->sayilar;
		if(ebeveynDugum == altDugum) altDugum->sol = silinecekDugum->sol;
		else ebeveynDugum->sag = silinecekDugum->sol;
	}
	delete silinecekDugum;
	return true;
}

int AVL::Yukseklik(Node *altDugum){
	if(altDugum == NULL) return -1;
	return 1+max(Yukseklik(altDugum->sol),Yukseklik(altDugum->sag));
}

AVL::AVL(){
	kok=NULL;
}

bool AVL::Bosmu()const{
	return kok == NULL;
}
void AVL::Ekle(int* yeni, int uzunluk, int toplam){
	kok = AraVeEkle(kok,yeni,uzunluk,toplam);
}

int AVL::Yukseklik(){
	return Yukseklik(kok);
}

void AVL::Temizle(){
	while(!Bosmu()) DugumSil(kok);
}

AVL::~AVL(){
	Temizle();
}

void AVL::preorder(){
	preorder(kok);
}

void AVL::preorder(Node* altDugum){
	if(altDugum != NULL){
		cout<<*altDugum<<endl;
		preorder(altDugum->sol);
		preorder(altDugum->sag);
	}
}
