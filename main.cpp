#include "zmogus.h"

int main() {
    srand(time(0));

    zmogus laikinas;
    vector<zmogus> grupe;
    int zmoniu_sk;
 
    string dataChoice;
    cout << "Do you want to read data from a file? (yes/no): ";
    cin >> dataChoice;

    if (dataChoice == "yes") {
        processFileData(grupe);
    }
    else if (dataChoice != "no") {
        cout << "Invalid choice. Exiting." << endl;
        return 1;
    }
    else {
        inputStudentData(grupe);
    }

    sort(grupe.begin(), grupe.end(), [](const zmogus& a, const zmogus& b) {
        return a.vardas < b.vardas;
        });

    int choice;
    cout << "Pasirinkite skaiciavimo buda (1 - Vidurkis, 2 - Mediana): ";
    cin >> choice;

    cout << fixed << setprecision(2);

    printStudentData(grupe, choice);

    return 0;
};
