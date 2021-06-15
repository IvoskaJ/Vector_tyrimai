#pragma once
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Zmogus{
    protected:
		Zmogus() {};
    private:
        string vardas_;
        string pavarde_;
    public:
        string setVardas(string newVardas) {
            this->vardas_ = newVardas;
            return vardas_;
        }

        string setPavarde(string newPavarde) {
            this->pavarde_ = newPavarde;
            return this->vardas_;
        }

        inline string vardas() const { return vardas_; }

        inline string pavarde() const { return pavarde_; }

       virtual ~Zmogus(){};

};


class Studentas : public Zmogus {
	private:
		int egzaminas_;
		double galBalas_;
		int mediana_;
		vector<double> ND;
	public:
	Studentas() : egzaminas_(0) { }
	Studentas(istream& is);
	double galutinis() {
		double ndSuma = 0;
		double vidurkis;
		for (int i = 0; i < 10; i++) {
			ndSuma = ndSuma + this->ND.at(i);
		}
		int ndRez = ndSuma / 10;
		vidurkis = (this->egzaminas_ * 0.6) + (ndRez * 0.4);
		galBalas_ = vidurkis;
		return galBalas_;
	};

	double mediana() {
		double median = 0;
		this->ND.resize(10 + 1);
		this->ND.back() = this->egzaminas_;
		int i, j;
		bool swapped;
		for (int i = 0; i < 10; i++) {
			swapped = false;
			for (int j = 0; j < this->ND.size() - 1; j++) {
				if (this->ND.at(j) > this->ND.at(j + 1)) {
					swap(this->ND.at(j), this->ND.at(j + 1));
					swapped = true;
				}
			}
		}

		int pazymiuSkaicius = this->ND.size();

		if ((pazymiuSkaicius) % 2 == 0) {
			double firstNumber = this->ND.at(pazymiuSkaicius / 2 - 1);
			double secondNumber = this->ND.at((pazymiuSkaicius / 2));
			median = ((firstNumber + secondNumber) / 2);
		}

		else {
			for (int i = 0; i < pazymiuSkaicius / 2; i++) {
				median = this->ND.at(i + 1);
			}
		}
		mediana_ = median;
		return mediana_;
	}


	int setEgzaminas(int newEgz) {
        this->egzaminas_ = newEgz;
        return this->egzaminas_;
	}

	vector<double> setND(double pazymys){
        this->ND.push_back(pazymys);
        return this->ND;
	}

	inline double galbalas() const { return galBalas_; }
	inline int median() const { return mediana_; }
	//destruktorius

	~Studentas() {
	    this->ND.clear();
        this->ND.shrink_to_fit();
	}

    //copy operatorius

	Studentas(const Studentas &kitas){
        setVardas(kitas.vardas());
        setPavarde(kitas.pavarde());
        this->ND=kitas.ND;
        this->egzaminas_=kitas.egzaminas_;
        this->galBalas_=kitas.galBalas_;
        this->mediana_=kitas.mediana_;

	}

    //copy assignment operatorius

	Studentas& operator=(const Studentas &kitas){
            if(this == &kitas){
             return *this;
            }
            if(this->ND.size()>= kitas.ND.size()){
                for(int i=0; i<kitas.ND.size(); i++){
                    this->ND.at(i)=kitas.ND.at(i);
                }
                this->egzaminas_=kitas.egzaminas_;
                setVardas(kitas.vardas());
                setPavarde(kitas.pavarde());
                this->mediana_=kitas.mediana_;
                this->galBalas_=kitas.galBalas_;
            }
            else{
                for(int i=0; i<this->ND.size(); i++){
                    this->ND.at(i)=kitas.ND.at(i);
                }
                this->egzaminas_=kitas.egzaminas_;
                this->galBalas_=kitas.galBalas_;
                setVardas(kitas.vardas());
                setPavarde(kitas.pavarde());
                this->mediana_=kitas.mediana_;

            }

	}

};
