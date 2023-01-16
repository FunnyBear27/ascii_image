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
		virtual std::vector<short> get_data() const = 0;
};

class PNGImage : public Image{
		std::vector<short> data, rgb_array;
		std::vector<PNGChunk> chunks;
		size_t file_len;
		long long int chunks_count{ 0 };
		bool chunked{ false };
		int *dimensions = new int[2];
		void dropPrefix() override;

	public:
		PNGImage(std::vector<short>& data);
		void rgbArray() override;
		std::vector<short> get_data() const override{ return data; }
		void chunksCreate();
		void dropAncillary();
		void unpackChunks();
		int& get_dimensions() const;	
};

