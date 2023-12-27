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

using namespace std;

struct zmogus {
    string vardas;
    string pavarde;
    list<int> nd;
    int egz;
    float vid;
    float med;
    float galutinis;
};
void processLine(const string& line, list<zmogus>& grupe);
void inputStudentData(list<zmogus>& grupe);
void processFileData(list<zmogus>& grupe);
void printStudentData(const list<zmogus>& grupe, int choice);
void calculateMedian(list<int>& nd, float& med);
void calculateAverage(const list<int>& nd, float& vid);
void generateRandomGrades(int ndskaicius, list<int>& nd);
bool rikiavimas(const zmogus& a, const zmogus& b);
void printStudentDataToFile(const list<zmogus>& grupe, int choice, ofstream& outputFile);

void generateStudentFile(int numStudents, int numHomeworks, const std::string& filename);
void generateStudentFilesAutomatically();
void calculateGalutinis(zmogus& student);
void calculateGalutinisForFile(const string& filename, string rusiavimoKriterijus, int strategija);
bool compareStudents(const zmogus& a, const zmogus& b);
bool rikiavimaspav(const zmogus& a, const zmogus& b);
