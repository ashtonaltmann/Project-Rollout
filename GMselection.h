#ifndef _IntArray_H_
#define _IntArray_H_
#include"../react.h"
#include <iostream>
#include <fstream>

class Selection {
    //char* _global_mem;
    //char fname[sizeof("/home/users/binsto1/SD/proj/memory.txt")];
    //char lname[sizeof("/home/users/binsto1/SD/proj/mapLibrary.txt")];
public:
    Selection();
    ~Selection() { delete _global_mem; }

    void read_stream(istream &f, char array[], int max_size);
    void read_file(const char fname[], char array[], int max_size);
    void search(const char index);
    void map_select();
    void gamemode_select();
    void start();
    //void put_in_global_mem(int index_offset, int text_offset) const;
    //void get_from_global_mem(int index_offset, int text_offset);
    //void clear();
};

#endif  // _IntArray_H_