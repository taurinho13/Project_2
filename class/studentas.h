#pragma once
#include <iostream>
#include <fstream>
#include <cmath>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <sstream>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <random>
#include <numeric>
#include <list>
#include <cctype>
#include <iterator>

#ifndef ZMOGUS_H
#define ZMOGUS_H

using namespace std;

class zmogus {
private:
    std::string vardas;
    std::string pavarde;
    std::list<int> nd;
    int egz;
    float vidur;
    float median;
    float galutinis;

public:
    zmogus(): egz(0), vidur(0), median(0), galutinis(0) {}
    zmogus(istream& is);
    istream& readzmogus(istream&);
    void clearND() { nd.clear(); }

    void calculateGalutinis(zmogus& student)
    {
      if (student.getPaz().size() > 0) {
        float sum = std::accumulate(student.getPaz().begin(),
                                    student.getPaz().end(), 0.0);
        student.setVid((sum / static_cast<float>(student.getPaz().size())));
        student.setGalutinis(student.getVid() * 0.4 +
                             student.getEgzaminas() * 0.6);
        // std::cout << "Debug: " << student.getVardas() << " " <<
        // student.getPavarde() << " " << student.getVid() << " " <<
        // student.getEgzaminas() << " " << student.getGalutinis() <<
        // std::endl;
      } else {
        student.setVid(0.0);
        student.setGalutinis(student.getEgzaminas() * 0.6);
      }
    }
    

    friend istream& operator>>(istream& is, zmogus& student);
    friend ostream& operator<<(ostream& os, const zmogus& student){
      os << left << setw(20) << student.vardas << setw(20) << student.pavarde
         << fixed << setprecision(2) << setw(20) << student.galutinis;
      return os;
    };

    zmogus(const zmogus& other)
    {
      vardas = other.vardas;
      pavarde = other.pavarde;
      nd = other.nd;
      egz = other.egz;
      vidur = other.vidur;
      median = other.median;
      galutinis = other.galutinis;
    }

     zmogus& operator=(const zmogus& other)
    {
      if (this != &other) {
        vardas = other.vardas;
        pavarde = other.pavarde;
        nd = other.nd;
        egz = other.egz;
        vidur = other.vidur;
        median = other.median;
        galutinis = other.galutinis;
      }
      return *this;
    }
     
     
     ~zmogus() { nd.clear(); }

    void setVardas(const string& v) { vardas = v; }
    void setPavarde(const string& p) { pavarde = p; }
    void setEgzaminas(int egzaminas) { egz = egzaminas; }
    void setVid(float vid) { vidur = vid; }
    void setMed(float med) { median = med; }
    void setGalutinis(float gal) { galutinis = gal; }
    void addPazymys(int paz) { nd.push_back(paz); }


    inline string getVardas() const { return vardas; }
    inline string getPavarde() const { return pavarde; }
    float getVid() const { return vidur; }
    float getMed() const { return median; }
    float getGalutinis() const { return galutinis; }
    int getEgzaminas() const { return egz; }
    const list<int>& getPaz() const { return nd; }

};

void processLine(const std::string& line, std::list<zmogus>& grupe);
void inputStudentData(std::list<zmogus>& grupe);
void processFileData(std::list<zmogus>& grupe);
void printStudentData(const std::list<zmogus>& grupe, int choice);
void generateRandomGrades(zmogus& zmog, int ndskaicius);
bool rikiavimas(const zmogus& a, const zmogus& b);
void printStudentDataToFile(const std::list<zmogus>& grupe, int choice, std::ofstream& outputFile);

void generateStudentFile(int numStudents, int numHomeworks, const std::string& filename);
void generateStudentFilesAutomatically();
void calculateGalutinisForFile(const std::string& filename, std::string rusiavimoKriterijus, int strategija);
bool compareStudents(const zmogus& a, const zmogus& b);
bool rikiavimaspav(const zmogus& a, const zmogus& b);
void calculateMedian(zmogus& laikinas);
void calculateAverage(zmogus& laikinas);
void calculateGalutinis(zmogus& student);

#endif //ZMOGUS_H
