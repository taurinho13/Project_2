#include "zmogus.h"

int main() {
    srand(time(0));

    zmogus laikinas;
    vector<zmogus> grupe;
    int zmoniu_sk=0;

    string dataChoice;
    cout << "Ar norite skaityti duomenis is failo (taip/ne): ";
    cin >> dataChoice;
    
    if (dataChoice == "taip") {

        processFileData(grupe);

        auto start = std::chrono::high_resolution_clock::now();

        sort(grupe.begin(), grupe.end(), rikiavimas);

        auto end = std::chrono::high_resolution_clock::now(); // Record the end time
        std::chrono::duration<double> duration = end - start;
        std::cout << "Failo rikiavimo laikas: " << duration.count() << " seconds" << std::endl;

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

        sort(grupe.begin(), grupe.end(), rikiavimas);
        printStudentData(grupe, choice);
    }
    return 0;
};
