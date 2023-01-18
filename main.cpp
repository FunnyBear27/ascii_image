#include "./include/funcs.h"
#include "./include/pngclass.h"

int main(int argc, char** argv){
	std::vector<short> initial_file;
	std::string file_name(argv[2], strlen(argv[2]));
	if (argc < 3) {
		throw std::invalid_argument("Use flag -f and specify a file to work with");
	}
	else if (argc > 3){
		throw std::invalid_argument("Too many arguments passed to a file");
	}
	
	try{
		read_image(file_name, initial_file);
	}
	catch (std::invalid_argument& e){
		std::cerr << e.what() << std::endl;
		return -1;
	}

	PNGImage img(initial_file);
	img.chunksCreate();
	img.dropAncillary();
	img.unpackChunks();
	return 0;
}
