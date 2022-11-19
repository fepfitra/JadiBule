#include <iostream>
#include <fstream>
using namespace std;
string baris;
int indeks;
ofstream OFLASHCARD;
ifstream IFLASHCARD;
struct rogerSumatera {
	int urutan;
	string vocab;
	string arti;
};
rogerSumatera kosakata[100000];
void mainMenuTop() {
	cout << "=====\t\tWelcome to JADI BULE !\t\t=====\n\n";
	cout << "Option\t:\n";
	cout << "1-ADD Vocabulary\n";
	cout << "2-DELETE Vocabulary\n";
	cout << "3-SEARCH Vocabulary\n";
	cout << "4-REVIEW Vocabulary\n";
	cout << "5-TEST Vocabulary\n";
}
void mainMenuBottom() {
	cout << "Choose any option by inputting the number \n";
	cout << "Your choice : ";
}
void buffer() {
	for (int i=0; i<10; i++) {
		cout << "\n";
	}
}
void clearScreen() {
	for (int i=0; i<50; i++) {
		cout << "\n";
	}
}

void menuADD() {
	cout << "Input format : {vocabulary}${meaning}\n";
	cout << "Example : Real$Nyata\n";
	buffer();
	OFLASHCARD.open("kartu1.txt",ios::out | ios::trunc);
	cout << "Enter the input : ";
		
}
void DELETE() {
}
void SEARCH() {
}
void REVIEW() {
}
void TEST() {
}

int main() {
	

	OFLASHCARD.open("kartu1.txt");
	mainMenuTop();
	buffer();
	mainMenuBottom();
	int choice;
	cin >> choice;
	switch (choice) {
		case 1 : clearScreen(); menuADD(); goto tambah; break;
		case 2 : clearScreen(); DELETE(); break;
		case 3 : clearScreen(); SEARCH(); break;
		case 4 : clearScreen(); REVIEW(); break;
		case 5 : clearScreen(); TEST(); break;
		default : clearScreen(); break;
	}
	tambah :
		getline(cin, baris);
		int panjang=baris.length();
		for (int i=0; i<panjang; i++) {
			if (baris[i]=='$') {
				kosakata[indeks].vocab=baris.substr(0,i);
				kosakata[indeks].arti=baris.substr(i+1, panjang-i-1);
				kosakata[indeks].urutan=indeks+1;
				indeks++;
			}
		}	
}
	
	
	
	
