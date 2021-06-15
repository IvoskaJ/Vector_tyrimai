#include "vector1class.h"
#include <chrono>
#pragma GCC optimize("Ofast")
using namespace std;

int main() {
    time_t t;
    srand((unsigned)time(&t));
    vector<Studentas>* studentas = new vector<Studentas>;
        for (int i = 1000; i <= 10000000; i = i * 10) {
            cout << "pradedamas darbas su " << i << " dydzio failu." << endl;
            workWithGeneratedFile(i);
            cout << "failas uzdaromas, tesiama su 10 kartu didesniu failu." << endl;
        }

    return 0;
}
