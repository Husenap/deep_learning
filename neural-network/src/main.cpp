#include <armadillo>
#include <chrono>
#include <iostream>

#include <IDXLoader.h>
#include "NeuralNetwork.h"

int main() {
	dl::NeuralNetwork nn(4, 2);

	// clang-format off
	arma::fmat trainingInputData = {
		{0, 0.5f, 0, 0},
		//{0, 0, 0, 1},
		{0, 0.5f, 1, 0},
		{0, 1, 0, 0},

		{1, 0, 0, 0},
		{0, 0, 1, 1},
		{0, 1, 0, 1},
		//{1, 0, 0, 1},

		//{1, 0, 1, 0},
		{1, 1, 0, 0},
		{1, 1, 0, 1},
		//{0, 1, 1, 1},

		{1, .5f, 1, 1},
		{1, 1, 0, 1},
		{1, 2.f, 1, 0},
		//{1, 1, 1, 1},
	};
	arma::fmat trainingOutputData = arma::fmat({{
		{0, 0.5f},
		//{0, 0},
		{0, 0.5f},
		{0, 1},

		{1, 0},
		{0, 0},
		{0, 1},
		//{1, 0},

		//{1, 0},
		{1, 1},
		{1, 1},
		//{0, 1},

		{1, 0.5f},
		{1, 1},
		{1, 2.f},
		//{1, 1},
	}});
	arma::fmat testInputData = {
		{0, 2.f, 1, 1},
		{1, 0, 1, 0},
		{2.f, 0.5f, 0, 2.f},
		{0.5f, 1, 1, 1},
		{0, 0.5f, 0.5f, 1}
	};
	// clang-format on

	std::cout << "Evaluating test data before training" << std::endl << testInputData << std::endl;
	std::cout << nn.Evaluate(testInputData) << std::endl;
	std::cout << "Weights:" << std::endl << arma::round(nn.GetWeights() * 1000.f) / 1000.f << std::endl;

	auto timestampBefore = std::chrono::high_resolution_clock::now();

	for (int i = 0; i < 1000; ++i) {
		nn.Train(trainingInputData, trainingOutputData);
	}

	auto timestampAfter = std::chrono::high_resolution_clock::now();
	long long timeInMS =
		std::chrono::duration_cast<std::chrono::milliseconds>(timestampAfter - timestampBefore).count();
	std::cout << "Trained for " << timeInMS << "ms" << std::endl << std::endl;

	std::cout << "Evaluating test data after training" << std::endl << testInputData << std::endl;
	std::cout << arma::round(nn.Evaluate(testInputData) * 1000.f) / 1000.f << std::endl;
	std::cout << "Weights:" << std::endl << arma::round(nn.GetWeights() * 1000.f) / 1000.f << std::endl;

	return 0;
}