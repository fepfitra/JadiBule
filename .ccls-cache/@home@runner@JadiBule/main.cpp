
#include <fstream>
#include <iostream>
using namespace std;
string baris;
int indeks = 0;
ofstream OFLASHCARD;
ifstream IFLASHCARD;
struct rogerSumatera {
  int urutan;
  int tingkatHafalan = 0;
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
  std::system("clear");
#endif
}

void menuADD() {
  cout << "Input format : {vocabulary}${meaning}\n";
  cout << "Example : Real$Nyata\n";
  buffer();

  cout << "Enter the input : ";
}
void read() {
  IFLASHCARD.open("kartu1.txt");
  while (getline(IFLASHCARD, baris)) {
    kosakata[indeks].urutan = indeks;
    kosakata[indeks].vocab = baris.substr(0, baris.find("$"));
    kosakata[indeks].arti = baris.substr(baris.find("$") + 1,
                                         baris.find("#") - baris.find("$") - 1);
    kosakata[indeks].tingkatHafalan = stoi(baris.substr(
        baris.find("#") + 1, baris.find("%") - baris.find("#") - 1));
    indeks++;
  }
  IFLASHCARD.close();

  // for (int i = 1; i <= indeks; i++) {
  //   cout << kosakata[i].urutan << ". " << kosakata[i].vocab << " : " <<
  //   kosakata[i].arti << kosakata[i].tingkatHafalan << endl;
  // }
}
void search() {}
void review() {}

string uppercase(string s) {
  for (int i = 0; i < s.length(); i++) {
    s[i] = toupper(s[i]);
  }
  return s;
}
int handleCorrect() {
  cout << "Correct !\n";
  cout << "1. Next\n";
  cout << "2. Back\n";
  buffer();
  mainMenuBottom();
  int pilihan;
  cin >> pilihan;
  return pilihan;
}
int handleWrong() {
  cout << "Wrong !\n";
  cout << "Guess again ?\n";
  cout << "1. Yes\n";
  cout << "2. No\n";
  buffer();
  mainMenuBottom();
  int pilihan;
  cin >> pilihan;
  return pilihan;
}

void pilihTest(int ctx) {
  if (ctx == 1) {
    int random = rand() % indeks + 1;
    clearScreen();
    cout << "========\tEN - ID  \t========\n";
    cout << "========\t" << uppercase(kosakata[random].vocab) << "\t\t========\n";
    cout << "=======================================\n";
    buffer();
    cout << "Your answer : ";
    string input;
    cin >> input;
    if (uppercase(input) == uppercase(kosakata[random].arti)) {
      if (handleCorrect() == 1) {
        pilihTest(ctx);
      }
    } else {
      if (handleWrong() == 1) {
        pilihTest(ctx);
      }
    }
  } else if (ctx == 2) {
    int random = rand() % indeks + 1;
    clearScreen();
    cout << "========\tID - EN  \t========\n";
    cout << "========\t" << uppercase(kosakata[random].arti) << "\t\t========\n";
    cout << "=======================================\n";
    buffer();
    cout << "Your answer : ";
    string input;
    cin >> input;
    if (uppercase(input) == uppercase(kosakata[random].vocab)) {
      if (handleCorrect() == 1) {
        pilihTest(ctx);
      }
    } else {
      if (handleWrong() == 1) {
        pilihTest(ctx);
      }
    }
  }
}

void test() {
  srand(time(0));
  read();
  clearScreen();
  cout << "Test your vocabulary\n";
  cout << "1. EN - ID\n";
  cout << "2. ID - EN\n";
  cout << "3. Back\n";
  buffer();
  mainMenuBottom();
  int pilihan;
  cin >> pilihan;
  if (pilihan == 1) {
    pilihTest(1);
  }
  if (pilihan == 2) {
    pilihTest(2);
  } else {
    cout << "Wrong input\n";
  }
}

void add() {
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
  while (running) {
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
