#include "IDXLoader.h"

#include <algorithm>
#include <fstream>
#include <numeric>

#include <iostream>

namespace dl {

IDXLoader::IDXLoader(const char* filepath) {
	mFilepath = filepath;
	std::ifstream file(filepath);

	if (file.fail()) {
		throw std::runtime_error("Failed to read file");
	}

	MagicNumber magicNumber;
	file.read((char*)&magicNumber, sizeof(magicNumber));

	mDimensions.resize(magicNumber.mNumDimensions);
	file.read((char*)mDimensions.data(), sizeof(mDimensions[0]) * magicNumber.mNumDimensions);
	std::transform(mDimensions.begin(), mDimensions.end(), mDimensions.begin(), ReverseInt);

	int rawSize = std::reduce(mDimensions.begin(), mDimensions.end(), 1, std::multiplies<>{});
	mData.resize(rawSize);
	file.read((char*)mData.data(), sizeof(mData[0]) * rawSize);
}

IDXLoader::~IDXLoader() {
}

void IDXLoader::PrintInfo() {
	std::cout << "============" << std::endl;
	std::cout << "=== Info ===" << std::endl;
	std::cout << "============" << std::endl;
	std::cout << "Filepath: " << mFilepath << std::endl;
	std::cout << "Num Dimensions: " << mDimensions.size() << std::endl;
	for (size_t i = 0; i < mDimensions.size(); ++i) {
		std::cout << "  " << i << ": " << mDimensions[i] << std::endl;
	}
	std::cout << "Raw Data Size: " << mData.size() << std::endl;
	std::cout << std::endl;
}

int IDXLoader::ReverseInt(int i) {
	unsigned char c1, c2, c3, c4;
	c1 = i & 255;
	c2 = (i >> 8) & 255;
	c3 = (i >> 16) & 255;
	c4 = (i >> 24) & 255;
	return ((int)c1 << 24) + ((int)c2 << 16) + ((int)c3 << 8) + c4;
}

}  // namespace dl