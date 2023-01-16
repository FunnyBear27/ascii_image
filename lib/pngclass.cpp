#include "../include/pngclass.h"
#include "../include/pngchunks.h"
#include <iostream>


PNGImage::PNGImage(std::vector<short>& data) : m_data { data }, m_file_len {data.size()}{ dropPrefix(); }

void PNGImage::dropPrefix() {
	short swap = 0;
	for (unsigned long int i = 0; i < m_file_len / 2; i++){
		swap = m_data[i];
		m_data[i] = m_data[m_file_len - 1 - i];
		m_data[m_file_len - 1 - i] = swap;
	}

	std::vector<short> check_prefix{m_data.end() - 8, m_data.end()};
	if (check_prefix != PNGVERIFYPREF) {
		throw std::invalid_argument("File is damaged/modified/is not PNG");	
	}
	for (int i = 0; i < 8; i++){
		m_data.pop_back();
	}
	m_file_len -= 8;
}

void PNGImage::chunksCreate() {	
	unsigned long int chunk_length{ 0 };

	while (m_data.size() >= 12){ 
		PNGChunk ch(m_data);
		m_chunks.push_back(ch);
		m_chunks_count++;
		chunk_length = ch.getChunkLen();
		for(unsigned long i = 0; i < chunk_length; i++){
			m_data.pop_back();
		}
	}
	m_chunked = true;
}


void PNGImage::dropAncillary(){
	std::vector<PNGChunk>::iterator p_ch_begin = m_chunks.begin();
	int i { 0 };
	while (true){
		if (!m_chunks[i].getCritical()){
			m_chunks.erase(p_ch_begin + i);
			m_chunks_count -= 1;
		}
		else {
			i += 1;
			if (m_chunks_count == i){
				break;
			}
		}
	}
}


void PNGImage::unpackChunks() {
	for (int i = 0; i < m_chunks_count; i++){
		PNGChunk *cur_chunk = &m_chunks[i];
		std::string type = cur_chunk->getType();
		if (type == "IHDR"){
			
		}	
	}
}


void PNGImage::rgbArray() {
	std::cout << "rgbArray" << std::endl;
}
