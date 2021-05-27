#include "perceptron.h"

void Perceptron::readFromFile(const std::string& filename) {
    std::ifstream ptn(filename);
    ptn>>perceptron_size;
    perceptron_w.resize(perceptron_size);
    for (int i=0;i<perceptron_size;i++){
        ptn>>perceptron_w[i];
    }
    ptn>>perceptron_b;
}

void Perceptron::readFromConsole() {
    std::cout<<"Perceptron size:"<<std::endl;
    std::cin>>perceptron_size;
    perceptron_w.resize(perceptron_size);
    std::cout<<"Print "<<perceptron_size<<" numbers representing the weights of the perceptron:"<<std::endl;
    for (int i=0;i<perceptron_size;i++){
        std::cin>>perceptron_w[i];
    }
    std::cout<<"Perceptron bias:"<<std::endl;
    std::cin>>perceptron_b;
    std::string s;
    getline(std::cin,s);
}

bool Perceptron::checkVector(const std::vector<int>& x) const {
    return x.size() == perceptron_size;
}

bool Perceptron::predict(const std::vector<bool> &x) const {

    double ceval = 0;
	for (int i=0;i<perceptron_size;i++){
		ceval += x[i] * perceptron_w[i];
	}
	return ceval >= -perceptron_b;
}

int Perceptron::vectorSize() const {
    return perceptron_size;
}

bool Perceptron::complete(const std::vector<int> &x) const {

    double ceval = 0;
    for (int i=0;i<perceptron_size;i++){
        if (x[i] != 2){
            ceval += x[i] * perceptron_w[i];
        } else {
            if (perceptron_w[i] > 0) ceval+=perceptron_w[i];
        }
    }
    return ceval >= -perceptron_b;

}


bool Perceptron::negativeComplete(const std::vector<int> &x) const {
     double ceval = 0;
    for (int i=0;i<perceptron_size;i++){
        if (x[i] != 2){
            ceval += x[i] * perceptron_w[i];
        } else {
            if (perceptron_w[i] < 0) ceval+=perceptron_w[i];
        }
    }
    return ceval < -perceptron_b;
}
