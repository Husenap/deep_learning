#include <algorithm>
#include <armadillo>
#include <cmath>
#include <iostream>

#include "IDXLoader.h"

int main() {
	const std::string ramp = " .;-*+=%#@";

	dl::IDXLoader imagesFile("data/images.idx3-ubyte");
	imagesFile.PrintInfo();

	int numImages = imagesFile.Dimensions()[0];
	int numPixels = imagesFile.Dimensions()[1] * imagesFile.Dimensions()[2];

	std::vector<float> data;
	data.resize(imagesFile.Data().size());

	std::transform(imagesFile.Data().begin(), imagesFile.Data().end(), data.begin(), [](unsigned char c) -> float {
		return ((float)c) / 255.f;
	});

	arma::fmat testData(data.data(), numPixels, numImages);
	arma::inplace_trans(testData);

	/*
	dl::IDXLoader labelsFile("data/labels.idx1-ubyte");
	labelsFile.PrintInfo();

	for (int i = 8000; i < 8020; ++i) {
		
		printf("%d:\n", labelsFile.Data()[i]);

		for (int row = 0; row < imagesFile.Dimensions()[1]; ++row) {
			for (int col = 0; col < imagesFile.Dimensions()[2]; ++col) {
				int pixel = row * imagesFile.Dimensions()[2] + col;

				float f = testData(i, pixel);
				unsigned char a = (unsigned char)(f*255.f);

				size_t gray = std::min(a / (255 / ramp.size()), ramp.size() - 1);
				printf("%c%c", ramp[gray], ramp[gray]);
			}
			printf("\n");
		}

	}
	*/

	/*
	int singleImageSize = imagesFile.Dimensions()[1] * imagesFile.Dimensions()[2];

	for (int i = 8000; i < 8020; ++i) {
		int offset = i * singleImageSize;

		printf("%d:\n", labelsFile.Data()[i]);

		for (int row = 0; row < imagesFile.Dimensions()[1]; ++row) {
			for (int mode = 0; mode < 2; ++mode) {
				for (int col = 0; col < imagesFile.Dimensions()[2]; ++col) {
					int pixel = row * imagesFile.Dimensions()[2] + col;

					unsigned char a = imagesFile.Data()[pixel + offset];

					if (mode == 0) {
						size_t gray = std::min(a / (255 / ramp.size()), ramp.size() - 1);
						printf("%c%c", ramp[gray], ramp[gray]);
					} else {
						if (a == 0) {
							printf("  ");
						} else {
							printf("%02x", a);
						}
					}
				}
			}
			printf("\n");
		}
		printf("\n");
	}
	*/

	system("pause");

	return 0;
}