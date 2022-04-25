#include "GMselection.h"
#include <fstream>
#include<iostream>
#include <string>
#include<stdio.h>
#include<string.h>
using namespace std;

char* _global_mem;

char fname[] = "/home/users/binsto1/SD/proj/memory.txt";
char lname[] = "/home/users/binsto1/SD/proj/mapLibrary.txt";

/// Read_stream Function ///
void read_stream(istream &f, char array[], int max_size) {
  int num_bytes;
  if (f.good()) {
    f.read(array, max_size);
    if (f) {
      cout << "Warning in read_stream:  did not reach end of stream after " << max_size << " characters.";
      num_bytes = max_size - 1;
    } else {
      num_bytes = f.gcount();
      if (num_bytes >= max_size) num_bytes = max_size - 1;
    }
  } else {
    cout << "Warning in read_stream: unable to read anything\n";
    num_bytes = 0;
  }
  array[num_bytes] = 0;  // assign null at end
}

/// Read_file Function ///
void read_file(const char fname[], char array[], int max_size) {
  ifstream f(fname);
  read_stream(f, array, max_size);
  f.close();
}

/// Search Function ///
void search(const char index) {
    int val = 97;
    string line;
    ifstream f(lname);
    while ( getline (f,line) ) {
        if (static_cast<int>(line[0])-48 == static_cast<int>(index)) {
            cout << char(val) << " = ";
            val++;
            cout << line.substr(line.find(static_cast<int>(index)) + 3) << '\n';
        }
    }
    f.close();
}

/// Map_select Function ///
void map_select() {
    char map;
    search(_global_mem[2]);
    cout << "< = previous page" << endl;
    cout << "Select Map: ";

    read_file(fname, _global_mem, 10001);

    cin >> map;

    switch (map) {
        case 'a':
            _global_mem[4] = 'a';
            break;
        case 'b':
            _global_mem[4] = 'b';
            break;
        case 'c':
            _global_mem[4] = 'c';
            break;
        case 'd':
            _global_mem[4] = 'd';
            break;
        case 'e':
            _global_mem[4] = 'e';
            break;
        case 'f':
            _global_mem[4] = 'f';
            break;
        case 'g':
            _global_mem[4] = 'g';
            break;
        case 'h':
            _global_mem[4] = 'h';
            break;
        case 'i':
            _global_mem[4] = 'i';
            break;
        case 'j':
            _global_mem[4] = 'j';
            break;
        case 'k':
            _global_mem[4] = 'k';
            break;
        case 'l':
            _global_mem[4] = 'l';
            break;
        case 'm':
            _global_mem[4] = 'm';
            break;
        case 'n':
            _global_mem[4] = 'n';
            break;
        case '<':
            _global_mem[0]--;
            break;
        default:
            // if the input doesn't match any of the cases
            cout << "Error!";
            break;
    }
    if (map != '<') {
        _global_mem[0]++;
    }
    ofstream f(fname);
    f.write(_global_mem, 10000);
    f.close();

    cout << '\n';
}

/// Gamemode_select Function ///
void gamemode_select() {
    char gm;
    cout << "1 = Gem grab" << endl;
    cout << "2 = Heist" << endl;
    cout << "3 = Siege" << endl;
    cout << "4 = Knockout" << endl;
    cout << "5 = Bounty" << endl;
    cout << "6 = Brawl Ball" << endl;
    cout << "7 = Hot Zone" << endl;
    cout << "Select Gamemode: ";

    _global_mem = new char[10000];
    read_file(fname, _global_mem, 10001);

    cin >> gm;

    switch (gm) {
        case '1':
            _global_mem[2] = 1;
            break;
        case '2':
            _global_mem[2] = 2;
            break;
        case '3':
            _global_mem[2] = 3;
            break;
        case '4':
            _global_mem[2] = 4;
            break;
        case '5':
            _global_mem[2] = 5;
            break;
        case '6':
            _global_mem[2] = 6;
            break;
        case '7':
            _global_mem[2] = 7;
            break;
        default:
            // if the input doesn't match any of the cases
            cout << "Error!";
            break;
    }
    _global_mem[0] = 1;
    ofstream f(fname);
    f.write(_global_mem, 10000);
    f.close();

    cout << '\n';
}

/// Start Function ///
void start() {
    _global_mem = new char[10000];
    _global_mem[0] = 0;
    while (true) {
        if (_global_mem[0] == 0) {
            gamemode_select();
        } else if (_global_mem[0] == 1) {
            map_select();
        } else {
            cout << static_cast<int>(_global_mem[2]) << "," << static_cast<char>(_global_mem[4]) << endl;
            break;
        }
    }
}

/// Main Function ///
int main() {
    start();
    delete _global_mem;
}