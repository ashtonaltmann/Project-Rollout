#include"../react.h"
#include <string>
#include <fstream>
#include<iostream>
using namespace std;

char memory[] = "/home/users/binsto1/SD/proj/memory.txt";

/// Read_Stream Function ///
void read_stream(istream &f, char array[], int max_size) {
  int num_bytes;
  if (f.good()) {
    f.read(array, max_size);
    if (f) {
      cerr << "Warning in read_stream:  did not reach end of stream after " << max_size << " characters.";
      num_bytes = max_size - 1;
    } else {
      num_bytes = f.gcount();
      if (num_bytes >= max_size) num_bytes = max_size - 1;
    }
  } else {
    cerr << "Warning in read_stream: unable to read anything\n";
    num_bytes = 0;
  }
  array[num_bytes] = 0;  // assign null at end //
}

/// Read_File Function ///
void read_file(const char fname[], char array[], int max_size) {
  ifstream f(fname);
  read_stream(f, array, max_size);
  f.close();
}

/// MakeFunky Function ///
string getStr(int from) {
    int len = 0;
    char d = _get_char(from + len);
    while(0 != d) {
      ++len;
      d = _get_char(from + len);
    }
    char str[len];
    for (int i = 0; i < len; i++) {
        str[i] = _get_char(from + i);
    }
    string str1 = static_cast<string>(str);
    return str1;
}



// Dict d = {{"test", 1}, {"test2", 6}, {"test3", 12}};
// cerr << "test{test}" << endl;
    
    // _global_mem1 = new char[10000];
    // read_file(memory, _global_mem1, 10001); // 1)

    // ofstream f(memory);
    // f.write(_global_mem1, 10000);
    // f.close();

void makeFunky(string specs = "", bool img = false) {
    add_yaml("mainScreen.yaml");
    for (int i = 0; i < 47; i++) {
        int iCopy = 0;
        iCopy += i;

        int blue = 114 + iCopy*3;

        if (i == 9) {
            add_yaml("characterSelection.yaml", {{"b", blue}, {"Char", "1_8-Bit.png"}});
        } else if (i == 11) {
            add_yaml("characterSelection.yaml", {{"b", blue}, {"Char", "1_Stu.png"}});
        } else if (i == 16) {
            add_yaml("characterSelection.yaml", {{"b", blue}, {"Char", "1_Rico.png"}});
        } else if (i == 38) {
            add_yaml("characterSelection.yaml", {{"b", blue}, {"Char", "1_Sandy.png"}});
        } else if (i == 44) {
            add_yaml("characterSelection.yaml", {{"b", blue}, {"Char", "1_Ruffs.png"}});
        } else if (i == 45) {
            add_yaml("characterSelection.yaml", {{"b", blue}, {"Char", "1_Belle.png"}});
        } else {
            add_yaml("placeholder.yaml", {{"b", blue}});
        }
    }
    if (img == true) {
        string s = getStr(2000);
        // add_yaml("mainEndScreen.yaml", {{"Brawler", "1_8-Bit.png"}});
        add_yaml("mainEndScreen.yaml", {{"Brawler", s.c_str()}});
    } else {
        add_yaml("mainEndScreen.yaml", {{"Brawler", "Blank.png"}});
    }
    // add_yaml("mainEndScreen.yaml", {{"Brawler", "Blank.png"}});
    
}

/// Main Function ///
int main() {
    _init();

    /// Flashes Title Screen ///
    if (_just_starting()) {
        add_yaml("titleScreen.yaml");
    }
    /// Brings you to the Gamemode Selection Screen ///
    if (_received_event()) {
        if(_event_id_is("nextGG")) {
            add_yaml("GGselection.yaml", {{"header", "GGbanner.png"}, {"r", 102}, {"g", 0}, {"b", 102}});
        } else if(_event_id_is("nextH")) {
            add_yaml("GGselection.yaml");
        } else if(_event_id_is("nextS")) {
            add_yaml("GGselection.yaml");
        } else if(_event_id_is("nextKO")) {
            add_yaml("GGselection.yaml", {{"header", "KObanner.png"}, {"r", 239}, {"g", 159}, {"b", 59}});
        } else if(_event_id_is("nextB")) {
            add_yaml("GGselection.yaml");
        } else if(_event_id_is("nextBB")) {
            add_yaml("GGselection.yaml");
        } else if(_event_id_is("nextHZ")) {
            add_yaml("GGselection.yaml", {{"header", "HZbanner.png"}, {"r", 227}, {"g", 55}, {"b", 82}});
        } else if(_event_id_is("nextMain")) {
            makeFunky();
        } else if(_event_id_is("Brawler9")) {
            _put_raw(2000, "1_8-Bit.png");
            makeFunky("Specs", true);
            ofstream f(memory); // updating global mem
            f.write(_global_mem, 10000);
            f.close();
        } else if(_event_id_is("Brawler2")) {
            makeFunky("Specs");
        } else if(_event_id_is("Brawler3")) {
            makeFunky("Specs");
        } else if(_event_id_is("Brawler4")) {
            makeFunky("Specs");
        } else if(_event_id_is("Brawler5")) {
            makeFunky("Specs");
        } else if(_event_id_is("Brawler6")) {
            makeFunky("Specs");
        }
    }
    _quit();
}



// _global_mem = new char[10000]; // Creating global mem space
// read_file(memory, _global_mem, 10001); // Reading in global mem


// if (img == true) {
//     string s = getStr(2000);
//     add_yaml("mainEndScreen.yaml", {{"Brawler", s.c_str()}});
// }



// string getStr(int from) {
//     int len = 0;
//     char d = _get_char(from + len);
//     while(0 != d) {
//       ++len;
//       d = _get_char(from + len);
//     }
//     char str[len];
//     for (int i = 0; i < len; i++) {
//         str[i] = _get_char(from + len);
//     }
//     string str1 = static_cast<string>(str);
//     return str1;
// }



// Dict d = {{"test", 1}, {"test2", 6}, {"test3", 12}};
// cerr << "test{test}" << endl;
    
    // _global_mem1 = new char[10000];
    // read_file(memory, _global_mem1, 10001); // 1)

    // ofstream f(memory);
    // f.write(_global_mem1, 10000);
    // f.close();


// delete [] _global_mem;

// } else if(_event_id_is("Brawler9")) {
    // _put_raw(2000, "1_8-bit.png");
    // makeFunky(true, "Specs");
    // ofstream f(memory); // updating global mem
    // f.write(_global_mem, 10000);
    // f.close();

// } else if(_event_id_is("Brawler2")) {
//     makeFunky("Specs");
// } else if(_event_id_is("Brawler3")) {
//     makeFunky("Specs");
// } else if(_event_id_is("Brawler4")) {
//     makeFunky("Specs");
// } else if(_event_id_is("Brawler5")) {
//     makeFunky("Specs");
// } else if(_event_id_is("Brawler6")) {
//     makeFunky("Specs");
// -   Text:
//         style:
//           color: black
//           fontSize: 25
//         index: 0

// g++ -g -Wall titleScreen.cpp ../react.o -lcurl

// cd ~/SD/proj; ../bridge.py
// cd ~/SD/experiments; ../bridge.py