
#include <fstream>
#include <iostream>
using namespace std;
string baris;
int indeks;
ofstream OFLASHCARD;
ifstream IFLASHCARD;
struct rogerSumatera {
  int urutan;
  int tingkatHafalan=0;
  string vocab;
  string arti;
};
rogerSumatera kosakata[100000];
void mainMenuTop() {
  cout << "=====\t\tWelcome to JADI BULE !\t\t=====\n\n";
  cout << "Option\t:\n";
  cout << "1-ADD Vocabulary\n";
  cout << "2-SEARCH Vocabulary\n";
  cout << "3-REVIEW Vocabulary\n";
  cout << "4-TEST Vocabulary\n";
}
void mainMenuBottom() {
  cout << "Choose any option by inputting the number \n";
  cout << "Your choice : ";
}
void buffer() {
  for (int i = 0; i < 10; i++) {
    cout << "\n";
  }
}
void clearScreen() {
  // for (int i = 0; i < 50; i++) {
  //   cout << "\n";
  // }
  #ifdef WINDOWS
    std::system("cls");
  #else
    // Assume POSIX
    std::system ("clear");
  #endif
}

void menuADD() {
  cout << "Input format : {vocabulary}${meaning}\n";
  cout << "Example : Real$Nyata\n";
  buffer();

  cout << "Enter the input : ";
}
void read(){
  IFLASHCARD.open("kartu1.txt");
  while (getline(IFLASHCARD, baris)) {
    indeks++;
    kosakata[indeks].urutan = indeks;
    kosakata[indeks].vocab = baris.substr(0, baris.find("$"));
    kosakata[indeks].arti = baris.substr(baris.find("$") + 1, baris.find("#")-baris.find("$")-1);
    kosakata[indeks].tingkatHafalan = stoi(baris.substr(baris.find("#") + 1, baris.find("%")-baris.find("#")-1));
    
  }
  IFLASHCARD.close();

  // for (int i = 1; i <= indeks; i++) {
  //   cout << kosakata[i].urutan << ". " << kosakata[i].vocab << " : " << kosakata[i].arti << kosakata[i].tingkatHafalan << endl;
  // }
}
void search() {
  
}
void review() {}
void test() {
  
}
void add(){
  int panjang;
  menuADD();
  OFLASHCARD.open("kartu1.txt", ios::app);
  getline(cin, baris);
  panjang = baris.length();
  for (int i = 0; i < panjang; i++) {
    if (baris[i] == '$') {
      kosakata[indeks].vocab = baris.substr(0, i);
      kosakata[indeks].arti = baris.substr(i + 1, panjang - i - 1);
      kosakata[indeks].urutan = indeks + 1;
      OFLASHCARD << kosakata[indeks].vocab << "$";
      OFLASHCARD << kosakata[indeks].arti << "#";
      OFLASHCARD << kosakata[indeks].tingkatHafalan << "\n";
      indeks++;
    }
  }
  OFLASHCARD.close();
}

int main() {
  bool running = true;
  while(running){
    clearScreen();
    mainMenuTop();
    buffer();
    mainMenuBottom();
    int choice;
    cin >> choice;
    cin.ignore();
    switch (choice) {
    case 1:
      add();
      break;
    case 2:
      read();
      // search();
      break;
    case 3:
      review();
      break;
    case 4:
      test();
      break;
    case 5:
      running = false;
      break;
    default:
      cout << "Invalid input";
    }
  }
}


