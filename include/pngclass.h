#pragma once
#include "funcs.h"
#include "pngchunks.h"
class PNGChunk;
const std::vector<short> PNGVERIFYPREF { 10, 26, 10, 13, 71, 78, 80, 137 }; 

class Image {
	public:
		virtual void dropPrefix() = 0;
		virtual void rgbArray() = 0;
		virtual ~Image() = default;
		virtual std::vector<short> getData() const = 0;
		//virtual int& getDimensions() const = 0;
};

class PNGImage : public Image{
		std::vector<short> m_data, m_rgb_array;
		std::vector<PNGChunk> m_chunks;
		size_t m_file_len;
		long long int m_chunks_count{ 0 };
		bool m_chunked{ false };
		int m_width{ 0 }, m_height{ 0 };
		short m_bit_depth{ 0 }, m_color_type{ 0 }, m_compression_method{ 0 }, m_filter_method{ 0 }, m_interlace_method{ 0 };
		void dropPrefix() override;

	public:
		PNGImage(std::vector<short>& m_data);
		void rgbArray() override;
		std::vector<short> getData() const override{ return m_data; }
		void chunksCreate();
		void dropAncillary();
		void unpackChunks();
		//int& getDimensions() const override;	
};

