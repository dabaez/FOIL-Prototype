#ifndef IMODELS_H
#define IMODELS_H

#include <vector>
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

class IModel {
	public:
		virtual bool evaluate(std::vector<int>& x) = 0;
		virtual void readFromFile(string filename) = 0;
		virtual void readFromConsole() = 0;
		virtual bool checkVector(vector<int>& x) = 0;
		virtual int vectorSize() = 0;
};

class Perceptron: public IModel{
	
	public:
	
		int perceptron_size;
		vector<double> perceptron_w;
		double perceptron_b;
		
		void readFromFile(string filename){
			ifstream ptn(filename);
			ptn>>perceptron_size;
			perceptron_w.resize(perceptron_size);
			for (int i=0;i<perceptron_size;i++){
				ptn>>perceptron_w[i];
			}
			ptn>>perceptron_b;
		}
		
		void readFromConsole(){
			cout<<"Perceptron size:"<<endl;
			cin>>perceptron_size;
			perceptron_w.resize(perceptron_size);
			cout<<"Print "<<perceptron_size<<" numbers representing the weights of the perceptron:"<<endl;
			for (int i=0;i<perceptron_size;i++){
				cin>>perceptron_w[i];
			}
			cout<<"Perceptron bias:"<<endl;
			cin>>perceptron_b;
			string s;
			getline(cin,s);
		}
		
		bool checkVector(vector<int>& x){
			return x.size() == perceptron_size;
		}
		
		bool evaluate(vector<int> &x){
			double ceval = 0;
			for (int i=0;i<perceptron_size;i++){
				if (x[i] != 2) ceval += x[i] * perceptron_w[i];
				else return false;
			}
			return ceval >= -perceptron_b;
		}
		
		int vectorSize(){
			return perceptron_size;
		}
};

#endif