#include <iostream>
#include"../show_mem.h"

struct Pixel {
    unsigned char red;
    unsigned char green;
    unsigned char blue;
};

int main() {
  int width = 504;
  int height = 816;

  Pixel** image;
  image = new Pixel*[height];
  for (int i=0; i<height; i++) {
    image[i] = new Pixel[width];
  }

  for (int i=0; i<height; i++) {
    for (int j=0; j<width; j++) {
      image[i][j].red = (i/24) + (j/24); //red
      image[i][j].green = i%256; //green
      image[i][j].blue = j%256; //blue
    }
  }
  //image[0][0].red = 255;
  //image[0][1].green = 97;
  //std::cerr << image[0][1].green << "\n";  // should print 'a'
  _write_image("output.ppm", reinterpret_cast<char **>(image), width, height);

  for (int i=0; i<height; i++) { 
    delete [] image[i];
  }
  delete [] image;
}