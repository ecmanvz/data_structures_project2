/**
* @file AVL.hpp
* @description AVL aðacý kullanarak sayýlar bulma
* @course 1.Öðretim A
* @assignment 2.Ödev
* @date 16.08.2022
* @author Ecem AMANVERMEZ
*/


#ifndef AVL_HPP
#define AVL_HPP

#include "Node.hpp"

#include <cmath>

class AVL{
	private: 
		Node *kok;
	
		Node* AraVeEkle(Node* altDugum, int* yeni, int uzunluk, int toplam);
		
		Node* SolCocukIleDegistir(Node* );
									    
		Node* SagCocukIleDegistir(Node* );
		
		void preorder(Node*);
		
		void SeviyeDown(Node*);
		void SeviyeUp(Node*);
		
		
		bool DugumSil(Node*&);
		
		int Yukseklik(Node*);
	
	public:
		AVL();
		
		bool Bosmu()const;
		
		void Ekle(int*, int, int);
		
		int Yukseklik();

		void Temizle();
		
		void preorder();
		
		~AVL();
		
};

#endif