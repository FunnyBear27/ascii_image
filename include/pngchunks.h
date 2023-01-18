#pragma once
#include "pngclass.h"
#include <vector>

class PNGChunk {
	bool m_critical{0};
	std::string m_str_type;
	std::vector<short> m_chunk_type, m_crc, m_data;
	unsigned long int m_initial_length, m_len { 0 }, m_img_width, m_img_height;
	unsigned long int chunkCreate(const std::vector<short>& input);
	void chunkTypeDecypher();
public:
	PNGChunk (const std::vector<short>& input);
	unsigned long int getChunkLen() const { return m_len; }
	bool getCritical() const { return m_critical; };
	std::string getType() const { return m_str_type; };
	std::vector<short> getData() const { return m_data; }
};
