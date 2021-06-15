#include <iostream>
#include <vector>
#include "newVector.h"
#include <chrono>
#include <random>


using namespace std;
using namespace std::chrono;

int main() {

	auto start = high_resolution_clock::now();
	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stop - start) * 1.0 / 1000000;

	for (int i = 1000; i <= 10000000; i=i * 10) {

		Vektor<int> newVector;
		vector<int> stdVector;

		start = high_resolution_clock::now();

		for (int j = 0; j < i; j++) {
			newVector.push(rand() % 10);
		}

		stop = high_resolution_clock::now();
		duration = duration_cast<microseconds>(stop - start) * 1.0 / 1000000;
		cout << "sukurto vektoriaus uzpildymas " << i << " elementais uztruko: " << duration.count() << endl;

		newVector.clear();

		start = high_resolution_clock::now();

		for (int j = 0; j < i; j++) {
			stdVector.push_back(rand() % 10);
		}
		
		stop = high_resolution_clock::now();
		duration = duration_cast<microseconds>(stop - start) * 1.0 / 1000000;
		cout << "std::vector uzpildymas " << i << " elementais uztruko: " << duration.count() << endl;

		stdVector.clear();
	}

	return 0;

}
