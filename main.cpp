#include <iostream>
#include <fstream>
#include <time.h>
#include <stdlib.h>

using namespace std;

class anagram {
	ifstream plik1;
	ofstream plik2;
	string slowo;
	string pochodna;
	int los1;
	int los2;
		
	public:
		anagram();
		~anagram();
		
		void wyczytanie();
		string zamianaMale(string);
		string zamianaLiter(string);
		int losowanie();
		void zapis();
};

anagram::anagram() {
	plik1.open("we.txt");
	plik2.open("wy.txt");
}

void anagram::wyczytanie() {
	if(plik1.good())
		while(!plik1.eof()) {
			getline(plik1, slowo);
			pochodna = this->zamianaMale(slowo);		
			pochodna = this->zamianaLiter(pochodna);
			this->zapis();
		}
}

string anagram::zamianaMale(string slowo) {
	for(int i=0; i<slowo.length(); i++) {
		if(slowo[i]>64 && slowo[i]<90)
			slowo[i]+=32;
	}
	return slowo;
}

string anagram::zamianaLiter(string slowo) {
	los1 = this->losowanie();
	los2 = this->losowanie();
	swap (slowo[los1], slowo[los2]);		
	return slowo;
}
int anagram::losowanie() {
	int los;
	srand(time(NULL));
	do{
		los = (rand()%slowo.length());	
	}while(los==los1);
	return los;
}

void anagram::zapis() {
	plik2<<slowo<<" "<<pochodna<<"\n";
	cout<<slowo<<" "<<pochodna<<"\n";
}

anagram::~anagram() {
	plik1.close();
	plik2.close();
}

int main(int argc, char** argv) {
	anagram a1;
	a1.wyczytanie();
	return 0;
}
