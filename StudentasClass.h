#pragma once
#include <string>
#include <vector>
#include "newVector.h"

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
		Vektor<double> ND;
	public:
	Studentas() : egzaminas_(0) { }
	Studentas(istream& is);
	double galutinis() {
		double ndSuma = 0;
		double vidurkis;
		for (int i = 0; i < 10; i++) {
			ndSuma = ndSuma + this->ND.get(i);
		}
		int ndRez = ndSuma / 10;
		vidurkis = (this->egzaminas_ * 0.6) + (ndRez * 0.4);
		galBalas_ = vidurkis;
		return galBalas_;
	};

	double mediana() {
		double median = 0;
		this->ND.push(this->egzaminas_);
		bool swapped;
		for (int i = 0; i < 10; i++) {
			swapped = false;
			for (int j = 0; j < this->ND.getSize() - 1; j++) {
				if (this->ND.get(j) > this->ND.get(j + 1)) {
					this->ND.swap(j, j+1);
					swapped = true;
				}
			}
		}

		int pazymiuSkaicius = this->ND.getSize();

		if ((pazymiuSkaicius) % 2 == 0) {
			double firstNumber = this->ND.get(pazymiuSkaicius / 2 - 1);
			double secondNumber = this->ND.get((pazymiuSkaicius / 2));
			median = ((firstNumber + secondNumber) / 2);
		}

		else {
			for (int i = 0; i < pazymiuSkaicius / 2; i++) {
				median = this->ND.get(i + 1);
			}
		}
		mediana_ = median;
		return mediana_;
	}


	int setEgzaminas(int newEgz) {
        this->egzaminas_ = newEgz;
        return this->egzaminas_;
	}

	Vektor<double> setND(double pazymys){
        this->ND.push(pazymys);
        return this->ND;
	}

	inline double galbalas() const { return galBalas_; }
	inline int median() const { return mediana_; }
	//destruktorius

	~Studentas() {
	    this->ND.clear();
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

	Studentas& operator= (Studentas &kitas){
            if(this == &kitas){
             return *this;
            }
            if(this->ND.getSize()>= kitas.ND.getSize()){
                for(int i=0; i<kitas.ND.getSize(); i++){
					this->ND.get(i, kitas.ND.get(i));
                }
                this->egzaminas_=kitas.egzaminas_;
                setVardas(kitas.vardas());
                setPavarde(kitas.pavarde());
                this->mediana_=kitas.mediana_;
                this->galBalas_=kitas.galBalas_;
            }
            else{
                for(int i=0; i<this->ND.getSize(); i++){
					this->ND.get(i, kitas.ND.get(i));
                }
                this->egzaminas_=kitas.egzaminas_;
                this->galBalas_=kitas.galBalas_;
                setVardas(kitas.vardas());
                setPavarde(kitas.pavarde());
                this->mediana_=kitas.mediana_;

            }

	}

};
