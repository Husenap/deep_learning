#pragma once

#include <armadillo>

namespace dl {

class NeuralNetwork {
public:
	NeuralNetwork(int numInputNodes, int numOutputNodes);
	~NeuralNetwork();

	void Train(const arma::fmat& inputData, const arma::fmat& outputData);
	arma::fmat Evaluate(const arma::fmat& inputData);

	const arma::fmat& GetWeights() const {
		return mWeights;
	}

private:
	arma::fmat Sigmoid(arma::fmat x);
	arma::fmat SigmoidDerivative(arma::fmat x);
	arma::fmat ReLU(arma::fmat x);
	arma::fmat ReLUDerivative(arma::fmat x);

	int mNumInputNodes;
	int mNumOutputNodes;

	arma::fmat mWeights;
};

}  // namespace dl
