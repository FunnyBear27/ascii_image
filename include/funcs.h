#include <iostream>
#include <string>
#include <fstream>
#include <ostream>
#include <iomanip>
#include <vector>
#include <math.h>
#ifndef funcs_h
#define funcs_h
class Image;

void read_image(std::string file_name, std::vector<short>& data);
void check_ext(std::string *file);
void png_process(std::string& file_name, std::vector<short>& data);
void print_vector(std::vector<short> a);
void print(const Image& img);
#endif
