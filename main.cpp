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

bool compareByVardas(const zmogus& a, const zmogus& b) {
    return a.vardas < b.vardas;
}
int main() {
    srand(time(0));

    zmogus laikinas;
    vector<zmogus> grupe;
    int zmoniu_sk;

    string dataChoice;
    cout << "Do you want to read data from a file? (yes/no): ";
    cin >> dataChoice;
    cin.ignore();

    if (dataChoice == "yes") {
        string fileName;
        cout << "Enter the file name (including extension): ";
        getline(cin, fileName);

        ifstream input(fileName);

        if (!input.is_open()) {
            cerr << "Failed to open the file." << endl;
            return 1;
        }

        string line;
        getline(input, line);
        while (getline(input, line)) {
            istringstream ss(line);

            ss >> laikinas.vardas >> laikinas.pavarde;

            int k;
            while (ss >> k) {
                if (ss.eof()) {
                    laikinas.egz = k;
                    break;
                }
                laikinas.nd.push_back(k);
            }

            if (laikinas.nd.size() < 1) {
                cerr << "Invalid input format in the file." << endl;
                return 1;
            }
            /*while (ss >> k) {
                laikinas.nd.push_back(k);
            }*/

            /*if (laikinas.nd.size() == 0) {
                cerr << "Invalid input format in the file." << endl;
                return 1;
            }*/

            /*laikinas.egz = laikinas.nd.back();
            laikinas.nd.pop_back();*/

            float nd_sum = 0;
            for (int k : laikinas.nd) {
                nd_sum += k;
            }
            laikinas.vid = (nd_sum / laikinas.nd.size());

            sort(laikinas.nd.begin(), laikinas.nd.end());
            if (laikinas.nd.size() % 2 == 0) {
                int mid1 = laikinas.nd[laikinas.nd.size() / 2 - 1];
                int mid2 = laikinas.nd[laikinas.nd.size() / 2];
                laikinas.med = (mid1 + mid2) / 2.0;
            }
            else {
                laikinas.med = laikinas.nd[laikinas.nd.size() / 2];
            }

            grupe.push_back(laikinas);
            laikinas.nd.clear();
        }

        input.close(); // Close the file

        sort(grupe.begin(), grupe.end(), compareByVardas); // Sort by vardas
    }
    else if (dataChoice != "no") {
        cout << "Invalid choice. Exiting." << endl;
        return 1;
    }
    else {
        cout << "Iveskite mokiniu skaiciu: ";
        cin >> zmoniu_sk;

        for (int j = 0; j < zmoniu_sk; j++) {
            cout << "Iveskite varda ir pavarde " << endl;
            cin >> laikinas.vardas >> laikinas.pavarde;

            int n = -1;
            cout << "Iveskite kiek namu darbu turi zmogus (jei nenorite ivesti, palikite tuscia ir spauskite Enter): ";
            cin.ignore();
            string nInput;
            getline(cin, nInput);
            if (!nInput.empty()) {
                istringstream iss(nInput);
                iss >> n;
            }

            if (n == -1) {
                cout << "Ar sugeneruoti namu darbu ir egzamino pazymius? (1 - Taip, 0 - Ne): ";
                int generate;
                cin >> generate;
                if (generate) {
                    cout << "Ar norite pasirinkti namu darbu skaiciu? (1 - Taip, 0 - Ne): ";
                    int chooseN;
                    cin >> chooseN;
                    if (chooseN) {
                        cout << "Iveskite namu darbu skaiciu: ";
                        cin >> n;
                    }
                    else {
                        n = rand() % 10 + 1;
                    }
                    cout << "Sugeneruotas namu darbu kiekis: " << n << endl;
                    cout << "Sugeneruoti namu darbu pazymiai: ";
                    for (int i = 0; i < n; i++) {
                        int k = rand() % 10 + 1;
                        cout << k << " ";
                        laikinas.nd.push_back(k);
                    }
                    cout << endl;

                    laikinas.egz = rand() % 10 + 1;
                    cout << "Sugeneruotas egzamino pazymys: " << laikinas.egz << endl;
                }
                else {
                    cout << "Iveskite namu darbu pazymius, baigus iveskite -1: " << endl;
                    int k;
                    while (true) {
                        cin >> k;
                        if (k == -1) {
                            break;
                        }
                        laikinas.nd.push_back(k);
                    }
                    n = laikinas.nd.size();
                    cout << "Iveskite egzamino bala " << endl;
                    cin >> laikinas.egz;
                }
            }
            else {
                for (int i = 0; i < n; i++) {
                    int k;
                    cout << "Iveskite " << i + 1 << " pazymi " << endl;
                    cin >> k;
                    laikinas.nd.push_back(k);
                }
                cout << "Iveskite egzamino bala " << endl;
                cin >> laikinas.egz;
            }

            float nd_sum = 0;
            for (int k : laikinas.nd) {
                nd_sum += k;
            }
            laikinas.vid = (nd_sum / n);

            sort(laikinas.nd.begin(), laikinas.nd.end());
            if (n % 2 == 0) {
                int mid1 = laikinas.nd[n / 2 - 1];
                int mid2 = laikinas.nd[n / 2];
                laikinas.med = (mid1 + mid2) / 2.0;
            }
            else {
                laikinas.med = laikinas.nd[n / 2];
            }

            grupe.push_back(laikinas);
            laikinas.nd.clear();
        }
    }

    int choice;
    cout << "Pasirinkite skaiciavimo buda (1 - Vidurkis, 2 - Mediana): ";
    cin >> choice;

    /*string outputFileName = "output.txt";  // Change the filename if needed
    ofstream outputFile(outputFileName);

    if (!outputFile.is_open()) {
        cerr << "Failed to open the output file." << endl;
        return 1;
    }

    outputFile << fixed << setprecision(2);

    outputFile << std::left << setw(15) << "Vardas" << setw(15) << "Pavarde" << setw(10) << "Galutinis (";*/
    cout << fixed << setprecision(2);

    cout << std::left << setw(15) << "Vardas" << setw(15) << "Pavarde" << setw(10) << "Galutinis (";

    if (choice == 1) {
        cout << std::left << "vid.)";
    }
    else if (choice == 2) {
        cout << std::left << "med.)";
    }

    /*outputFile << endl;*/
    cout << endl;

    for (auto& a : grupe) {
        cout << std::left << setw(15) << a.vardas << setw(15) << a.pavarde << setw(20);

        if (choice == 1) {
            float galutinis = a.vid * 0.4 + a.egz * 0.6;
            cout << galutinis;
        }
        else if (choice == 2) {
            float galutinis = a.med * 0.4 + a.egz * 0.6;
            cout << galutinis;
        }
        cout << endl;
    }

    /*outputFile.close(); // Close the output file

    cout << "Output written to " << outputFileName << endl;*/

    return 0;
}
