#include <iostream>
#include <fstream>
#include <regex>

using namespace std;

class wyrazenie {
	ifstream plik1;
	ofstream plik2;
	string wyraz;
	
	public:
		wyrazenie();
		~wyrazenie();
		
		void wypisanie();
		void sprawdzenie(string);
		void zapis(string);
					
};

wyrazenie::wyrazenie() {
	plik1.open("we.txt");
	plik2.open("wy.txt");
}

void wyrazenie::wypisanie() {
	if(plik1.good())
		while(!plik1.eof()) {
			plik1>>wyraz;
			cout<<wyraz;
			this->sprawdzenie(wyraz);
			
		}
}

void wyrazenie::sprawdzenie(string wyraz) {
	regex wzor("[0-9]{2}-[0-9]{3}");
	if(regex_match(wyraz, wzor)) {
		this->zapis(wyraz);
	}
	cout<<"\n";	
}

void wyrazenie::zapis(string wyraz) {
	plik2<<wyraz<<"\n";
	cout<<" "<<wyraz;
}

wyrazenie::~wyrazenie() {
	plik1.close();
	plik2.close();
}

int main(int argc, char** argv) {
	wyrazenie w1;
	w1.wypisanie();
	return 0;
}
