#pragma once
#include "StudentasClass.h"
#include <random>
#include <time.h>
#include <iomanip>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <sstream>
#include <chrono>
#include <fstream>

using namespace std::chrono;


void visuDuomenuSkaiciavimas(vector<Studentas>& studentas, int studentuSkaicius, string file) {
	ofstream fr;
	fr.open(file);
	fr << left << setw(20) << "Vardas" << "Pavarde" << right << setw(35) << "galutinis (vid.)" << right << setw(35) << "mediana(med.)" << endl;
	for (int i = 0; i < studentuSkaicius; i++) {
		fr << left << setw(20) << studentas.at(i).vardas() << studentas.at(i).pavarde();
		studentas.at(i).galutinis();
		fr << right << setw(30) << studentas.at(i).galbalas();
		studentas.at(i).mediana();
		fr << right << setw(30) << studentas.at(i).median() << endl;
	}
	fr.close();
}

void workWithGeneratedFile(int studentuSkaicius) {

	vector<Studentas> studentas;
	vector<Studentas> dundukas;
	vector<Studentas> malacius;
	string file;
	string studentuSkaiciusFaile = to_string(studentuSkaicius);
	ifstream fd(studentuSkaiciusFaile + "studentu.txt");
	string vardas; string pavarde; string nd; string egz;
	auto start = high_resolution_clock::now();
	fd >> vardas >> pavarde;
	for (int i = 0; i < 10; i++) fd >> nd;
	fd >> egz;
	studentas.resize(studentuSkaicius);
	for (int i = 0; i < studentuSkaicius; i++) {
        int egzaminas;
		fd >> vardas;
		studentas.at(i).setVardas(vardas);
		fd >> pavarde;
		studentas.at(i).setPavarde(pavarde);

		for (int j = 0; j < 10; j++) {
			int temp;
			fd >> temp;
			studentas.at(i).setND(temp);
		}
		fd >> egzaminas;
		studentas.at(i).setEgzaminas(egzaminas);
	}

	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stop - start) * 1.0 / 1000000;

	cout << "studento duomenu is sugeneruoto failo nuskaitymas uztruko: " << duration.count() << endl;

	fd.close();
	start = high_resolution_clock::now();

	for (int i = 0; i < studentas.size(); i++) {
		if (studentas.at(i).galutinis() >= 5) {
			malacius.push_back(studentas.at(i));
		}
		else {
			dundukas.push_back(studentas.at(i));
		}
	}


	stop = high_resolution_clock::now();
	duration = duration_cast<microseconds>(stop - start) * 1.0 / 1000000;

	cout << "studento duomenu is sugeneruoto failo paskirstymas i dvi grupes uztruko: " << duration.count() << endl;

	start = high_resolution_clock::now();

	file = studentuSkaiciusFaile + "dundukai.txt";
	visuDuomenuSkaiciavimas(dundukas, dundukas.size(), file);


	file = studentuSkaiciusFaile + "malaciai.txt";

	visuDuomenuSkaiciavimas(malacius, malacius.size(), file);

	malacius.clear();
	malacius.resize(0);

	stop = high_resolution_clock::now();
	duration = duration_cast<microseconds>(stop - start) * 1.0 / 1000000;

	cout << "Studentu paskirstytu i dvi grupes duomenu failu generavimas uztruko: " << duration.count() << endl;

}
