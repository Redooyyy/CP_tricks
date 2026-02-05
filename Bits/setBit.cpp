#include <bits/stdc++.h>
using namespace std;

void printBinary(int num) {
  for (int i = 10; i >= 0; i--) {
    cout << ((num >> i) & 1);
  }
  cout << endl;
}

// is set or unset
bool isSet(int num, int indx) { return ((1 << indx) & num) != 0; }
// change unsetToSet
void changeToSet(int &num, int indx) { num = ((1 << indx) | num); }
//
void changeToUnset(int &num, int indx) {
  // num = ((1 << indx) ^ num);
  // or
  num = ~(1 << indx) & num;
}

void toggleBit(int &num, int indx) {
  if (isSet(num, indx)) {
    changeToUnset(num, indx);
  } else {
    changeToSet(num, indx);
  }
}

// interface
void showOptions(int num) {
  cout << "------------------------------------" << endl;
  cout << "-----Welcome to Bit PlayGround------" << endl;
  cout << "Binary form of " << num << "===> ";
  printBinary(num);
  cout << " 1. Print Binary\n2.Toggle Bit\n3.Insert another number\n4.Print "
          "Decimal\n5.Exit\n";
  cout << "------------------------------------" << endl;
  cout << "Option ==> ";
}
void mySpace() { cout << endl; }
void exit() { cout << "Thanks for using\nJust for timepass -_- REO" << endl; }
void my_switch(bool &onGo, int &num);

int main() {
  cout << "Enter a Number: ";
  int num;
  cin >> num;
  mySpace();
  showOptions(num);
  bool onGo = true;
  while (onGo) {
    my_switch(onGo, num);
  }
}

void my_switch(bool &onGo, int &num) {
  int op;
  cin >> op;
  switch (op) {
  case 1:
    printBinary(num);
    mySpace();
    showOptions(num);
    break;
  case 2:
    cout << "Enter index" << endl;
    int i;
    cin >> i;
    toggleBit(num, i);
    cout << "New Binary number is : ";
    printBinary(num);
    mySpace();
    showOptions(num);
    break;
  case 3:
    cout << "Enter New Number" << endl;
    int s;
    cin >> s;
    num = s;
    mySpace();
    showOptions(num);
    break;
  case 4:
    cout << num << endl;
    mySpace();
    showOptions(num);
    break;
  case 5: {
    exit();
    onGo = false;
  }
  default:
    cout << "\nInvalid Option Please Try again -_-" << endl;
    showOptions(num);
    break;
  }
}
