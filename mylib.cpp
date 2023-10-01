#include "zmogus.h"

void processLine(const string& line, vector<zmogus>& grupe) {
    istringstream ss(line);
    zmogus laikinas;

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
        return;
    }

    calculateAverage(laikinas.nd, laikinas.vid);

    calculateMedian(laikinas.nd, laikinas.med);

    grupe.push_back(laikinas);
    laikinas.nd.clear();
}
void inputStudentData(vector<zmogus>& grupe) {
    int zmoniu_sk;
    cout << "Iveskite mokiniu skaiciu: ";
    cin >> zmoniu_sk;

    for (int j = 0; j < zmoniu_sk; j++) {
        zmogus laikinas;

        cout << "Iveskite varda ir pavarde " << endl;
        cin >> laikinas.vardas >> laikinas.pavarde;

        int ndskaicius = -1;
        cout << "Iveskite kiek namu darbu turi zmogus (jei nenorite ivesti, palikite tuscia ir spauskite Enter): ";
        cin.ignore();
        string nInput;
        getline(cin, nInput);
        if (!nInput.empty()) {
            istringstream iss(nInput);
            iss >> ndskaicius;
        }

        if (ndskaicius == -1) {
            cout << "Ar sugeneruoti namu darbu ir egzamino pazymius? (1 - Taip, 0 - Ne): ";
            int generate;
            cin >> generate;
            if (generate) {
                cout << "Ar norite pasirinkti namu darbu skaiciu? (1 - Taip, 0 - Ne): ";
                int chooseN;
                cin >> chooseN;
                if (chooseN) {
                    cout << "Iveskite namu darbu skaiciu: ";
                    cin >> ndskaicius;
                }
                else {
                    ndskaicius = rand() % 10 + 1;
                }
                cout << "Sugeneruotas namu darbu kiekis: " << ndskaicius << endl;
                cout << "Sugeneruoti namu darbu pazymiai: ";
                generateRandomGrades(ndskaicius, laikinas.nd);

                cout << endl;

                laikinas.egz = rand() % 10 + 1;
                cout << "Sugeneruotas egzamino pazymys: " << laikinas.egz << endl;
            }
            else {
                cout << "Iveskite namu darbu pazymius (atskirkite ivertinimus tarpais baigti - spauskite Enter): ";
                int k;
                while (cin >> k) {
                    if (cin.peek() == '\n') {
                        cin.ignore(); // Ignore the newline character
                        break;
                    }
                    laikinas.nd.push_back(k);
                }

                ndskaicius = laikinas.nd.size();
                cout << "Iveskite egzamino bala " << endl;
                cin >> laikinas.egz;
            }
        }
        else {
            for (int i = 0; i < ndskaicius; i++) {
                int k;
                cout << "Iveskite " << i + 1 << " pazymi " << endl;
                cin >> k;
                laikinas.nd.push_back(k);
            }
            cout << "Iveskite egzamino bala " << endl;
            cin >> laikinas.egz;
        }

        calculateAverage(laikinas.nd, laikinas.vid);

        calculateMedian(laikinas.nd, laikinas.med);

        grupe.push_back(laikinas);
        laikinas.nd.clear();
    }
}
void processFileData(vector<zmogus>& grupe) {
    try {
        string fileName;
        cout << "Irasykite failo pavadinima (iskaitant ir failo tipa): ";
        cin.ignore();
        getline(cin, fileName);

        ifstream input(fileName);

        if (!input.is_open()) {
            throw invalid_argument("Netinkamas failo pavadinimas arba failas neegzistuoja.");
        }

        string line;
        while (getline(input, line)) {
            processLine(line, grupe);
        }

        input.close(); 
    }
    catch (const invalid_argument& e) {
        cerr << "Netinkamas argumentas: " << e.what() << endl;
    }
    catch (const exception& e) {
        cerr << "Atsirado klaida: " << e.what() << endl;
    }
}
void printStudentData(const vector<zmogus>& grupe, int choice) {
    cout << std::left << setw(15) << "Vardas" << setw(15) << "Pavarde" << setw(10) << "Galutinis (";

    if (choice == 1) {
        cout << std::left << "vid.)";
    }
    else if (choice == 2) {
        cout << std::left << "med.)";
    }

    cout << endl;

    for (const auto& a : grupe) {
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
}
void calculateMedian(vector<int>& nd, float& med) {
    sort(nd.begin(), nd.end());

    if (nd.size() % 2 == 0) {
        int mid1 = nd[nd.size() / 2 - 1];
        int mid2 = nd[nd.size() / 2];
        med = (mid1 + mid2) / 2.0;
    }
    else {
        med = nd[nd.size() / 2];
    }
}
void calculateAverage(const vector<int>& nd, float& vid) {
    float nd_sum = 0;
    for (int k : nd) {
        nd_sum += k;
    }
    vid = (nd_sum / nd.size());
}
void sortByVardas(vector<zmogus>& grupe) {
    sort(grupe.begin(), grupe.end(), [](const zmogus& a, const zmogus& b) {
        return a.vardas < b.vardas;
        });
}
void generateRandomGrades(int ndskaicius, vector<int>& nd) {
    for (int i = 0; i < ndskaicius; i++) {
        int k = rand() % 10 + 1;
        cout << k << " ";
        nd.push_back(k);
    }
}
