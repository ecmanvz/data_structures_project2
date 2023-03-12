/**
* @file Test.cpp
* @description AVL agaci kullanarak sayilar bulma
* @author Ecem 
*/


#include "AVL.hpp"
#include "Radix.hpp"
#include <fstream>
#include <sstream>

void SatirEkle(string satir,AVL& agac){
	
	int* dizi = new int[10000];
	string temp = "";
	int sayi = 0;
	int i=0;
	int Count=0;
	int toplam=0;

	for(; i < satir.length(); i++){
		temp+= satir[i];
		if(satir[i] == ' ' || satir[i+1] == '\0' ){
			stringstream stemp(temp);
			stemp>>sayi;
			dizi[Count] = sayi;
			Count++;
			toplam+=sayi;
			temp="";
			continue;
		}
	}
	//radixsort(dizi, Count);
	Radix *radix = new Radix(dizi,Count);
	dizi = radix->Sort();

	agac.Ekle(dizi,Count,toplam);
}


int main(){
	
		
	AVL *agac = new AVL();
	ifstream file("Sayilar.txt");
	
	if(file.is_open()){
		string line;
		
		while(!file.eof()){
			getline(file, line);
			SatirEkle(line,*agac);
		}
	}
	
	file.close();
	cout<<"Preorder: \n";
	agac->preorder();
	
	delete agac;

	return 0;
	
	
}
