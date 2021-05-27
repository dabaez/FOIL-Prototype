#include "models.h"

class Perceptron: public IModel{
	
	public:
		void readFromFile(const std::string& filename) override;

		void readFromConsole() override;
	
		bool checkVector(const std::vector<int>& x) const override;
		
		bool predict(const std::vector<bool> &x) const override;

		bool complete(const std::vector<int> &x) const override;
		
        bool negativeComplete(const std::vector<int> &x) const override;
			
		int vectorSize() const override;

    private:
		int perceptron_size;
        std::vector<double> perceptron_w;
		double perceptron_b;
};

