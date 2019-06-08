#pragma once

#include <vector>
#include <string>

namespace dl {

class IDXLoader {
public:
	IDXLoader(const char* filepath);
	~IDXLoader();

	const std::vector<int>& Dimensions() const {
		return mDimensions;
	}
	const std::vector<unsigned char>& Data() const {
		return mData;
	}

	void PrintInfo();

private:
	struct MagicNumber {
		unsigned char _junk1, _junk2;
		unsigned char mDataType;
		unsigned char mNumDimensions;
	};

	static int ReverseInt(int i);

	std::string mFilepath;
	std::vector<int> mDimensions;
	std::vector<unsigned char> mData;
};

}  // namespace dl