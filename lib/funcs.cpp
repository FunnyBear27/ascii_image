#include "../include/funcs.h"
#include "../include/pngclass.h"

void check_ext(std::string& file){
	std::string ext = file.substr(file.length() -4);		
	if (".png" != ext) {
		throw std::invalid_argument("We can not work with this extention (yet)");
	}
}

void print_vector(std::vector<short> a){
	for (short i: a) {
		if (i < 16) 
			std::cout << "0";
		std::cout << std::hex << i << " ";
	}
}

void png_process(std::string& file_name, std::vector<short>& data){
	std::ifstream my_file;
	my_file.open(file_name);

	if (my_file.is_open()) {
		while (my_file) {
			data.push_back(my_file.get());
		}
	}
	else{
		throw std::invalid_argument("something wrong with the file. Check the filename");
	}
}

void read_image(std::string file_name, std::vector<short> &data) {
  check_ext(file_name);
  png_process(file_name, data);
}

void print(const Image& img){
	const std::vector<short>& data {img.getData()};
	for (short el: data) {
		if (el < 16){
			std::cout << 0;
		}
		std::cout << std::hex << el << " ";
	}
}


