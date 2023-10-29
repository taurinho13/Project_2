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
using namespace std;

struct zmogus {
    string vardas;
    string pavarde;
    vector<int> nd;
    int egz;
    float vid;
    float med;
    float galutinis;
};
void processLine(const string& line, vector<zmogus>& grupe);
void inputStudentData(vector<zmogus>& grupe);
void processFileData(vector<zmogus>& grupe);
void printStudentData(const vector<zmogus>& grupe, int choice);
void calculateMedian(vector<int>& nd, float& med);
void calculateAverage(const vector<int>& nd, float& vid);
void generateRandomGrades(int ndskaicius, vector<int>& nd);
bool rikiavimas(const zmogus& a, const zmogus& b);
void printStudentDataToFile(const vector<zmogus>& grupe, int choice, ofstream& outputFile);
void generateStudentFile(int numStudents, int numHomeworks, const std::string& filename);
void generateStudentFilesAutomatically();
void calculateGalutinis(zmogus& student);
void calculateGalutinisForFile(const std::string& filename);
bool compareStudents(const zmogus& a, const zmogus& b);
bool rikiavimaspav(const zmogus& a, const zmogus& b);
