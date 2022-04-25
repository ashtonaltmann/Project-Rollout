#include <iostream> 
#include <string>
#include <fstream>
#include"../show_mem.h"
using namespace std;

struct Pixel {
    unsigned char red;
    unsigned char green;
    unsigned char blue;
};

struct Info {
    string tile;
    bool hz;
    string type1;
};

class map {
protected:
    int grid_x;
    int grid_y;
    int png_x; /// 504px ///
    int png_y; /// 816px ///
    int y_offset = 12; /// 12px ///
    int tile_length = 24; /// 24px ///
    Pixel** image;
    Info** identity;
public:
    map() {
        png_x = 504;
        png_y = 816;
    };

    ~map() {
        for (int i=0; i<png_y; i++) { 
            delete [] image[i];
        }
        delete [] image; 
    };

/// Setup Function ///
    void setUp() {
        if(png_y * 1.0 / png_x < 1.531 && png_y * 1.0 / png_x > 1.431) { 
            grid_x = 27;
            grid_y = 39;
        } else {
            grid_x = 21;
            grid_y = 33;
        }
        tile_length = png_x/grid_x;
        y_offset = tile_length/2;
    }

/// FetchMap Function ///
    void fetchMap() {
        int width;
        int height;
        _get_image_dimensions("test2.ppm", width, height);
        png_x = width;
        png_y = height;

        image = new Pixel*[height];
        for (int i=0; i<height; i++) {
            image[i] = new Pixel[width];
        }

        identity = new Info*[height];
        for (int i=0; i<height; i++) {
            identity[i] = new Info[width];
        }

        _read_image("test2.ppm", reinterpret_cast<char **>(image), width, height);


        setUp(); /// Gets Tile Grid Dimensions ///
    }

/// Check Funtion ///
    string check(int r, int g, int b) {
        ifstream h("rgbIndex.txt");

        int cnt = 0;
        int x, y, z;

        do {
            h >> x >> y >> z;
            cnt++;
        }
        while(!(r == x && g == y && b == z) && cnt < 23);

        if (x == 36 && y == 96 && z == 148) { 
            string str = "grass";
            return str;
        } else if (  (x == 210 && y == 159 && z == 239) || (x == 237 && y == 83 && z == 253) || (x == 255 && y == 185 && z == 118) || (x == 232 && y == 141 && z == 80) || (x == 167 && y == 54 && z == 59)  ) { 
            string str = "wall";
            return str;
        } else if ( (x == 156 && y == 68 && z == 78) || (x == 158 && y == 70 && z == 80) ) { 
            string str = "red spawn";
            return str;
        } else if ( (x == 54 && y == 101 && z == 132) || (x == 52 && y == 99 && z == 130) ) { 
            string str = "blue spawn";
            return str;
        } else if ( (x == 46 && y == 160 && z == 228) || (x == 31 && y == 151 && z == 223) ) { 
            string str = "water";
            return str;
        } else if (x == 105 && y == 96 && z == 96) { 
            string str = "rope fence";
            return str;
        } else if (  (x == 189 && y == 107 && z == 61) || (x == 160 && y == 92 && z == 47) || (x == 225 && y == 153 && z == 117) ) { 
            string str = "fence";
            return str;
        } else if (  (x == 95 && y == 68 && z == 84) || (x == 91 && y == 65 && z == 80) || (x == 82 && y == 37 && z == 16) || (x == 91 && y == 57 && z == 63) ) { 
            string str = "empty";
            return str;
        } else if (x == 62 && y == 26 && z == 7) { 
            string str = "center";
            return str;
        } else {
            string str = "error";
            return str;
        }
    }
/// Shrink Function ///
    char shrink(string tile) {
        if (tile == "grass") {
            char ch = 'G';
            return ch;
        } else if (tile == "wall") {
            char ch = 'W';
            return ch;
        } else if (tile == "red spawn") {
            char ch = 'R';
            return ch;
        } else if (tile == "blue spawn") {
            char ch = 'B';
            return ch;
        } else if (tile == "water") {
            char ch = 'A';
            return ch;
        } else if (tile == "rope fence") {
            char ch = 'P';
            return ch;
        } else if (tile == "fence") {
            char ch = 'F';
            return ch;
        } else if (tile == "empty") {
            char ch = '.';
            return ch;
        } else if (tile == "center") {
            char ch = 'C';
            return ch;
        } else {
            char ch = 'X';
            return ch;
        }
    }
/// PrintTileIdentity Function  ///
    void printTileIdentity() {
        string timesave;
        ofstream f("Hard_Rock_Mine.txt");
        for (int i = 8 + y_offset; i < grid_y * 24; i += 24) {
            for (int j = 10; j < grid_x * 24; j += 24) {

                timesave = identity[i][j].tile = check(image[i][j].red, image[i][j].green, image[i][j].blue);
                f << shrink(timesave) << " ";

                cout << shrink(timesave) << endl;
                cout << timesave << endl;

            }

            f << endl;
        }
        f.close();
    }
};

int main() {

    map m;
    m.fetchMap();
    m.printTileIdentity();

    return 0;
}

    // g++ -g -Wall rollout.cpp ../react.o -lcurl
    // ./a.out