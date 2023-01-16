#include "../include/pngchunks.h"

PNGChunk::PNGChunk(const std::vector<short>& input) : m_initial_length {input.size()} {
	chunkCreate(input);
	chunkTypeDecypher();
}

unsigned long int PNGChunk::chunkCreate(const std::vector<short>& input){
	std::vector<short> length_bytes{ input.end() - 4, input.end() };
	// std::cout << "---------------------" << std::endl;
	for (short i = 0; i < 4; i++){
		m_chunk_type.push_back(input[m_initial_length - 5 - i]);
	}
	
	if( m_chunk_type[0] < 91 ){
		m_critical = true;	
	}

	for (short i = 0; i < 4; i++){
		m_len += length_bytes[i] * pow(256, i);
	}

	for (unsigned long i = 0; i < m_len; i++){
		m_data.push_back(input[m_initial_length - 9 - i]);
	}

	for (short i = 0; i < 4; i++){
		m_crc.push_back(input[m_initial_length - 9 - m_len - i]);
	}
	
	m_len += 12;

	return 12 + m_len;
}

void PNGChunk::chunkTypeDecypher(){
	m_str_type = "";	
	char char_type;
	for (short elem : m_chunk_type){
		char_type = (char) elem; 
		m_str_type.push_back(char_type);
	}
}

