#include <iostream>
#include <fstream>
#include <cmath>
#include <iomanip>
#include <vector>


using namespace std;

struct zmogus {
    string vardas;
    string pavarde;
    vector <int> nd;
    int egz;
    float vid;
};
int main()
{
    zmogus laikinas;
    vector <zmogus> grupe;
    int zmoniu_sk;
    cout << "Iveskite mokiniu skaiciu: " << endl;
    cin >> zmoniu_sk;
    for (int j = 0; j < zmoniu_sk; j++)
    {
        cout << "Iveskite varda ir pavarde " << endl;
        cin >> laikinas.vardas >> laikinas.pavarde;
        cout << "Kiek namu darbu pazymiu turi zmogus? " << endl;
        int n;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            int k;
            cout << "Iveskite " << i + 1 << " pazymi " << endl;
            cin >> k;
            laikinas.nd.push_back(k);
        }
        cout << "Iveskite egzamino bala " << endl;
        cin >> laikinas.egz;
        grupe.push_back(laikinas);
        laikinas.nd.clear();
    }
    for (auto& a : grupe) {
        cout << a.vardas << " " << a.pavarde << " ";
        for (auto& z : a.nd) cout << z << " ";
        cout << a.egz << endl;
    }


}