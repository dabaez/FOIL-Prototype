#pragma once
#include <vector>
#include <string>
#include <iostream>
#include <fstream>

class IModel {
	public:
		virtual bool predict(const std::vector<bool>& x) const = 0;
		virtual bool complete(const std::vector<int>& x) const = 0;
		virtual bool negativeComplete(const std::vector<int>& x) const = 0;
		virtual void readFromFile(const std::string& filename) = 0;
		virtual void readFromConsole() = 0;
		virtual bool checkVector(const std::vector<int>& x) const = 0;
		virtual int vectorSize() const = 0;
};


