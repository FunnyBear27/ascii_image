#include "../include/pngclass.h"
#include "../include/pngchunks.h"
#include <iostream>


PNGImage::PNGImage(std::vector<short>& data) : data { data }, file_len {data.size()}{ dropPrefix(); }

void PNGImage::dropPrefix() {
	short swap = 0;
	for (unsigned long int i = 0; i < file_len / 2; i++){
		swap = data[i];
		data[i] = data[file_len - 1 - i];
		data[file_len - 1 - i] = swap;
	}

	std::vector<short> check_prefix{data.end() - 8, data.end()};
	if (check_prefix != PNGVERIFYPREF) {
		throw std::invalid_argument("File is damaged/modified/is not PNG");	
	}
	for (int i = 0; i < 8; i++){
		// std::cout << data[file_len - 1 - i] << "\n";
		data.pop_back();
	}
	// print(*this);
	file_len -= 8;
}

void PNGImage::chunksCreate() {	
	unsigned long int chunk_length{ 0 };

	while (data.size() >= 12){ // INF?
		PNGChunk ch(data);
		chunks.push_back(ch);
		chunks_count++;
		chunk_length = ch.getChunkLen();
		for(unsigned long i = 0; i < chunk_length; i++){
			data.pop_back();
		}
	}
	chunked = true;
}


void PNGImage::dropAncillary(){
	std::vector<PNGChunk>::iterator p_ch_begin = chunks.begin();
	int i { 0 };
	while (true){
		if (!chunks[i].getCritical()){
			chunks.erase(p_ch_begin + i);
			chunks_count -= 1;
		}
		else {
			i += 1;
			if (chunks_count == i){
				break;
			}
		}
	}
}


void PNGImage::unpackChunks() {
	for (int i = 0; i < chunks_count; i++){
		PNGChunk *cur_chunk = &chunks[i];
		std::string type = cur_chunk->getType();
		if (type == "IHDR"){
			
		}	
	}
}


void PNGImage::rgbArray() {
	std::cout << "rgbArray" << std::endl;
}

