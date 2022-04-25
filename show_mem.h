#ifndef _SHOW_MEM_H_
#define _SHOW_MEM_H_

// these functions must be used at the start and end of main()
//   (unless the connection to the browser is not being used)
void init(bool _use_cache = false);
void quit(const char *c = 0);
extern char *_global_mem;

// functions for obtaining and writing data into _global_mem
bool _get_bool(int index, bool shared=false);
char _get_char(int index, bool shared=false);
unsigned char _get_unsigned_char(int index, bool shared=false);
unsigned char _get_uchar(int index, bool shared=false);
short _get_short(int index, bool shared=false);
unsigned short _get_unsigned_short(int index, bool shared=false);
int _get_int(int index, bool shared=false);
unsigned int _get_unsigned_int(int index, bool shared=false);
long _get_long(int index, bool shared=false);
long long _get_long_long(int index, bool shared=false);
float _get_float(int index, bool shared=false);
double _get_double(int index, bool shared=false);

void _put_hex(int index, const char *hex_string, bool shared=false);
void _put_raw(int index, const char *raw_string, bool shared=false);
void _put_bool(int index, bool val, bool shared=false);
void _put_char(int index, char val, bool shared=false);
void _put_unsigned_char(int index, unsigned char val, bool shared=false);
void _put_uchar(int index, unsigned char val, bool shared=false);
void _put_short(int index, short val, bool shared=false);
void _put_unsigned_short(int index, unsigned short val, bool shared=false);
void _put_int(int index, int val, bool shared=false);
void _put_unsigned_int(int index, unsigned int val, bool shared=false);
void _put_long(int index, long val, bool shared=false);
void _put_long_long(int index, long long val, bool shared=false);
void _put_float(int index, float val, bool shared=false);
void _put_double(int index, double val, bool shared=false);

void _print_raw(int index, bool shared=false);
void _print_newline();
void _user_input(int index, bool shared=false);

// this function requires fetch.o -lcurl when compiling
void fetch(const char *url, int index = 0, int len = -1);

// these functions assume ppm format images
void _read_image(const char *filename);
void _read_image(const char *filename, char **image, int width, int height);
void _get_image_dimensions(int &width, int &height);
void _get_image_dimensions(const char *filename, int &width, int &height);
void _set_image_dimensions(int width, int height);
void _write_image(const char *filename);
void _write_image(const char *filename, char **image, int width, int height);
void _print_image();

#endif // _SHOW_MEM_H_
