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
using namespace std;

struct zmogus {
    string vardas;
    string pavarde;
    vector<int> nd;
    int egz;
    float vid;
    float med;
};
void processLine(const string& line, vector<zmogus>& grupe);
void inputStudentData(vector<zmogus>& grupe);
void processFileData(vector<zmogus>& grupe);
void printStudentData(const vector<zmogus>& grupe, int choice);
void calculateMedian(vector<int>& nd, float& med);
void calculateAverage(const vector<int>& nd, float& vid);
void sortByVardas(vector<zmogus>& grupe);
void generateRandomGrades(int ndskaicius, vector<int>& nd);
vector<int> inputHomeworkScores();
