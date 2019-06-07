#include "NeuralNetwork.h"

#include <cmath>

namespace dl {

NeuralNetwork::NeuralNetwork(int numInputNodes, int numOutputNodes)
	: mNumInputNodes(numInputNodes)
	, mNumOutputNodes(numOutputNodes)
	, mWeights(arma::randu<arma::fmat>(mNumInputNodes, mNumOutputNodes) * 2.f - 1.f) {
}

NeuralNetwork::~NeuralNetwork() {
}

void NeuralNetwork::Train(const arma::fmat& inputData, const arma::fmat& outputData) {
	arma::fmat output = Evaluate(inputData);

	auto error = (outputData - output).eval();
	auto gradient = 0.1f; // SigmoidDerivative(output);
	auto errorGradient = (error * gradient).eval();
	auto adjustment = (inputData.t() * errorGradient).eval();

	mWeights += adjustment;
}

arma::fmat NeuralNetwork::Evaluate(const arma::fmat& inputData) {
	auto sum = (inputData * mWeights);
	return ReLU(sum);
}

arma::fmat NeuralNetwork::Sigmoid(arma::fmat x) {
	auto r = arma::exp(-x);
	return 1.f / (1.f + r);
}

arma::fmat NeuralNetwork::SigmoidDerivative(arma::fmat x) {
	return (x % (1.f - x));
}

arma::fmat NeuralNetwork::ReLU(arma::fmat x) {
	auto y1 = x;
	auto y2 = (arma::exp(x) - 1.f).eval();
	auto y3 = (arma::clamp(arma::sign(x), 0.f, 1.f)).eval();
	auto y4 = (1.f - y3);
	auto y5 = (y1 % y3 + y2 % y4);
	return y5;
}

arma::fmat NeuralNetwork::ReLUDerivative(arma::fmat x) {
	auto y3 = (arma::clamp(arma::sign(x), 0.f, 1.f));
	auto y4 = 1.f - y3;
	auto y7 = arma::exp(x);
	auto y8 = y3 + y7 % y4;
	return y8;
}

}  // namespace dl