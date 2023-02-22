/**
* @file Node.hpp
* @description AVL a�ac� kullanarak say�lar bulma
* @course 1.��retim A
* @assignment 2.�dev
* @date 16.08.2022
* @author Ecem AMANVERMEZ
*/

#ifndef NODE_HPP
#define NODE_HPP

#include <cstddef>

#include <iostream>


using namespace std;

class Node{
	public:
	
		int toplam;
		int* sayilar;
		int uzunluk;
		
		int yukseklik;
		Node *sag;
		Node *sol;
		
		Node(int* sayilar,int uzunluk,int toplam, Node *sag = NULL, Node *sol = NULL);
		
		void sayiSil(int konum);
		
		friend ostream& operator<<(ostream&, const Node&);
	
};

#endif 	