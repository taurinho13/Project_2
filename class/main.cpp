#include "pch.h"


int main() {
    string choice;
    cout << "Pasirinkite operacija (auto/file): ";
    cin >> choice;

    if (choice == "auto") {
        generateStudentFilesAutomatically();
    }
    else if (choice == "file") {
        srand(time(0));

        zmogus laikinas;
        list<zmogus> grupe;
        int zmoniu_sk = 0;

        string dataChoice;
        cout << "Ar norite skaityti duomenis is failo (taip/ne): ";
        cin >> dataChoice;

        if (dataChoice == "taip") {
            processFileData(grupe);

            grupe.sort([](const zmogus& a, const zmogus& b) {
                return rikiavimas(a, b);
                });
            int choice;
            cout << "Pasirinkite skaiciavimo buda (1 - Vidurkis, 2 - Mediana): ";
            cin >> choice;

            ofstream outputFile("output.txt");
            printStudentDataToFile(grupe, choice, outputFile);
            outputFile.close();
        }
        else {
            inputStudentData(grupe);
            int choice;
            cout << "Pasirinkite skaiciavimo buda (1 - Vidurkis, 2 - Mediana): ";
            cin >> choice;

            grupe.sort([](const zmogus& a, const zmogus& b) {
                return rikiavimas(a, b);
                });
            printStudentData(grupe, choice);
        }
    }
    else {
        cout << "Neteisinga pasirinkimo operacija." << endl;
    }
    return 0;
};
