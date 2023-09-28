#include <iostream>
#include <fstream>
#include <cmath>
#include <iomanip>
#include <vector>
#include <algorithm> 
#include <sstream>

using namespace std;

struct zmogus {
    string vardas;
    string pavarde;
    vector<int> nd;
    int egz;
    float vid;
    float med;
};

int main() {
    zmogus laikinas;
    vector<zmogus> grupe;
    int zmoniu_sk;
    cout << "Iveskite mokiniu skaiciu: " << endl;
    cin >> zmoniu_sk;
    for (int j = 0; j < zmoniu_sk; j++) {
        cout << "Iveskite varda ir pavarde " << endl;
        cin >> laikinas.vardas >> laikinas.pavarde;

        int n = -1; // Initialize n with an invalid value
        cout << "Iveskite kiek namu darbu turi zmogus (jei nenorite ivesti, palikite tuscia ir spauskite Enter): ";
        cin.ignore(); // Clear any remaining input from the buffer
        string nInput;
        getline(cin, nInput);
        if (!nInput.empty()) {
            istringstream iss(nInput);
            iss >> n;
        }

        if (n == -1) {
            cout << "Iveskite namu darbu pazymius, baigus iveskite -1: " << endl;
            int k;
            while (true) {
                cin >> k;
                if (k == -1) {
                    break;
                }
                laikinas.nd.push_back(k);
            }
            n = laikinas.nd.size(); // Set n to the size of the vector
        }
        else {
            for (int i = 0; i < n; i++) {
                int k;
                cout << "Iveskite " << i + 1 << " pazymi " << endl;
                cin >> k;
                laikinas.nd.push_back(k);
            }
        }

        cout << "Iveskite egzamino bala " << endl;
        cin >> laikinas.egz;

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
    int choice;
    cout << "Pasirinkite skaiciavimo buda (1 - Vidurkis, 2 - Mediana): ";
    cin >> choice;

    cout << fixed << setprecision(2);

    for (auto& a : grupe) {
        cout << a.vardas << " " << a.pavarde << " ";

        if (choice == 1) {
            float galutinis = a.vid * 0.4 + a.egz * 0.6;
            cout << "Galutinis: " << galutinis;
        }
        else if (choice == 2) {
            float galutinis = a.med * 0.4 + a.egz * 0.6;
            cout << "Galutinis: " << galutinis;
        }
        cout << endl;
    }

    return 0;
}
