#include "zmogus.h"

int main() {
    srand(time(0));

    zmogus laikinas;
    vector<zmogus> grupe;
    int zmoniu_sk;
 
    string dataChoice;
    cout << "Ar norite skaityti duomenis is failo (taip/ne): ";
    cin >> dataChoice;

    if (dataChoice == "taip") {
        processFileData(grupe);
    }
    else if (dataChoice != "ne") {
        cout << "Netinkamas pasirinkimas. Exiting." << endl;
        return 1;
    }
    else {
        inputStudentData(grupe);
    }

    sortByVardas(grupe);

    int choice;
    cout << "Pasirinkite skaiciavimo buda (1 - Vidurkis, 2 - Mediana): ";
    cin >> choice;

    cout << fixed << setprecision(2);

    printStudentData(grupe, choice);

    return 0;
};
