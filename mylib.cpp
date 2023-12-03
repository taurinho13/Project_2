#include "zmogus.h"

void processFileData(vector<zmogus>& grupe) {

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
                while (true) {
                    try {
                        cout << "Iveskite namu darbu pazymius (atskirkite ivertinimus tarpais baigti - spauskite Enter): ";
                        int k;

                        while (cin >> k) {
                            if (k < 0 || k > 10) {
                                throw out_of_range("Invalid input. Please enter a number between 0 and 10.");
                            }
                            laikinas.nd.push_back(k);

                            if (cin.peek() == '\n') {
                                cin.ignore(); // Ignore the newline character
                                break;
                            }
                        }

                        break; // Exit the loop if all inputs were valid
                    }
                    catch (const out_of_range& e) {
                        cerr << e.what() << endl;
                        laikinas.nd.clear(); // Clear the vector if an error occurred
                    }
                    catch (const exception& e) {
                        cerr << "An exception occurred: " << e.what() << endl;
                    }
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
            cout << fixed << galutinis << setprecision(2);
        }
        else if (choice == 2) {
            float galutinis = a.med * 0.4 + a.egz * 0.6;
            cout << fixed << galutinis << setprecision(2);
        }
        cout << endl;
    }
}
void generateRandomGrades(int ndskaicius, vector<int>& nd) {
    for (int i = 0; i < ndskaicius; i++) {
        int k = rand() % 10 + 1;
        cout << k << " ";
        nd.push_back(k);
    }
}
bool rikiavimas(const zmogus& a, const zmogus& b) {
    size_t i = 0, j = 0;
    while (i < a.vardas.size() && j < b.vardas.size()) {
        if (isdigit(a.vardas[i]) && isdigit(b.vardas[j])) {
            int numA = 0, numB = 0;
            while (i < a.vardas.size() && isdigit(a.vardas[i])) {
                numA = numA * 10 + (a.vardas[i] - '0');
                i++;
            }
            while (j < b.vardas.size() && isdigit(b.vardas[j])) {
                numB = numB * 10 + (b.vardas[j] - '0');
                j++;
            }
            if (numA != numB)
                return numA < numB;
        }
        else {
            if (a.vardas[i] != b.vardas[j])
                return a.vardas[i] < b.vardas[j];
            i++;
            j++;
        }
    }
    return a.vardas.size() < b.vardas.size();

}
void printStudentDataToFile(const vector<zmogus>& grupe, int choice, ofstream& outputFile) {
    outputFile << std::left << setw(15) << "Vardas" << setw(15) << "Pavarde" << setw(10) << "Galutinis (";

    if (choice == 1) {
        outputFile << std::left << "vid.)";
    }
    else if (choice == 2) {
        outputFile << std::left << "med.)";
    }

    outputFile << endl;

    for (const auto& a : grupe) {
        outputFile << std::left << setw(15) << a.vardas << setw(15) << a.pavarde << setw(20);

        if (choice == 1) {
            float galutinis = a.vid * 0.4 + a.egz * 0.6;
            outputFile << fixed << galutinis << setprecision(2);
        }
        else if (choice == 2) {
            float galutinis = a.med * 0.4 + a.egz * 0.6;
            outputFile << fixed << galutinis << setprecision(2);
        }
        outputFile << endl;
    }
}
void generateStudentFilesAutomatically() {
    srand(time(0));

    int numStudents[] = { 1000, 10000, 100000, 1000000, 10000000 };
    int numHomeworks = 4;
    string filenames[] = { "students_1000.txt", "students_10000.txt", "students_100000.txt",
                          "students_1000000.txt", "students_10000000.txt" };

    cout << "Pasirinkite pagal ka surusiuoti duomenis (v - vardas, p - pavarde, g - galutinis): ";
    string rusiavimoKriterijus;
    cin >> rusiavimoKriterijus;
    cout << '\n';

    for (int i = 0; i < 5; i++) {

        ifstream fileCheck(filenames[i]);
        if (fileCheck.good()) {
            cout << "File " << filenames[i] << " failas jau egzistuoja. Kurimas praleidziamas" << endl;
        }
        else {
            auto start = std::chrono::high_resolution_clock::now();
            generateStudentFile(numStudents[i], numHomeworks, filenames[i]);
            auto end = std::chrono::high_resolution_clock::now();
            std::chrono::duration<double> duration = end - start;
            std::cout << "Failo kurimo laikas (" << filenames[i] << "): " << duration.count() << " sekundes" << std::endl;
        }

        calculateGalutinisForFile(filenames[i], rusiavimoKriterijus);
    }
}
void generateStudentFile(int numStudents, int numHomeworks, const std::string& filename) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> examDist(1, 10);
    std::uniform_int_distribution<> ndDist(1, 10);

    std::ofstream outputFile(filename);

    if (outputFile.is_open()) {
        outputFile << std::left << std::setw(22) << "Vardas" << std::setw(22) << "Pavarde";

        for (int i = 1; i <= numHomeworks; ++i) {
            outputFile << std::setw(10) << "ND" + std::to_string(i);
        }

        outputFile << std::setw(10) << "Egzaminas\n";

        for (int i = 0; i < 94; ++i) {
            outputFile << "-";
        }
        outputFile << "\n";
        for (int i = 1; i <= numStudents; ++i) {
            std::stringstream studentData;
            studentData << std::left << std::setw(22) << ("Vardenis" + std::to_string(i));
            studentData << std::left << std::setw(22) << ("Pavardenis" + std::to_string(i));

            for (int j = 0; j < numHomeworks; ++j) {
                studentData << std::setw(10) << ndDist(gen);
            }

            studentData << std::setw(11) << examDist(gen) << std::endl;
            outputFile << studentData.str();
        }

        outputFile.close();
        std::cout << "Sukurtas: " << filename << std::endl;
    }
    else {
        std::cerr << "Nepavyko atidaryti failo: " << filename << std::endl;
    }
}
void calculateGalutinisForFile(const std::string& filename, string rusiavimoKriterijus) {

    ifstream inputFile(filename);

    if (inputFile.is_open()) {
        auto startRead = std::chrono::high_resolution_clock::now();
        string line;
        vector<zmogus> students;

        while (std::getline(inputFile, line)) {
            std::istringstream iss(line);
            zmogus student;
            iss >> student.vardas >> student.pavarde;

            int grade;

            if (!student.nd.empty()) {
                student.egz = student.nd.back();
                student.nd.pop_back();  // Remove the last element from nd since it's now assigned to egz
            }
            else {
                student.egz = 0;  // If no nd grades are present, set egz to 0
            }

            calculateGalutinis(student);

            students.push_back(student);
        }

        inputFile.close();
        auto endRead = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> durationRead = endRead - startRead;
        std::cout << "Failo (" << filename << ") nuskaitymo laikas: " << durationRead.count() << " sekundes" << std::endl;

        auto startSort = std::chrono::high_resolution_clock::now();
        
        if (rusiavimoKriterijus == "v") {
            std::sort(students.begin(), students.end(), [](const zmogus& a, const zmogus& b) {
                return rikiavimas(a, b);
                });
        }
        else if (rusiavimoKriterijus == "p") {
            std::sort(students.begin(), students.end(), [](const zmogus& a, const zmogus& b) {
                return rikiavimaspav(a, b);
                });
        }
        else if (rusiavimoKriterijus == "g") {
            std::sort(students.begin(), students.end(), compareStudents);
        }
        else {
            cout << "Invalid sorting criteria. Using default (galutinis)." << endl;
            std::sort(students.begin(), students.end(), compareStudents);
        }

        auto endSort = std::chrono::high_resolution_clock::now();

        std::chrono::duration<double> durationSort = endSort - startSort;
        std::cout << "Failo (" << filename << ") rusiavimo laikas : " << durationSort.count() << " sekundes" << std::endl;
        
        vector<zmogus> kietiakaiStudents;
        vector<zmogus> vargsiukaiStudents;

        auto startDivide = std::chrono::high_resolution_clock::now();
        for (const zmogus& student : students) {
            if (student.galutinis >= 5) {
                kietiakaiStudents.push_back(student);
            }
            else {
                vargsiukaiStudents.push_back(student);
            }
        }
        auto endDivide = std::chrono::high_resolution_clock::now();

        std::chrono::duration<double> durationDivide = endDivide - startDivide;
        std::cout << "Padalijimo laikas: " << durationDivide.count() << " seconds" << std::endl;

        std::ofstream kietiakai("kietiakai_" + filename);
        kietiakai << std::left << std::setw(20) << "Vardas" << std::setw(20) << "Pavarde" << std::setw(10) << "Galutinis\n";
        auto startWriteOver5 = std::chrono::high_resolution_clock::now();
        for (const zmogus& student : kietiakaiStudents) {
            kietiakai << std::left << std::setw(20) << student.vardas << std::setw(20) << student.pavarde << std::setw(10) << student.galutinis << "\n";
        }
        auto endWriteOver5 = std::chrono::high_resolution_clock::now();
        kietiakai.close();

        std::chrono::duration<double> durationWriteOver5 = endWriteOver5 - startWriteOver5;
        std::cout << "Irasimo i faila (kietiakai): " << durationWriteOver5.count() << " seconds" << std::endl;

        std::ofstream vargsiukai("vargsiukai_" + filename);
        vargsiukai << std::left << std::setw(20) << "Vardas" << std::setw(20) << "Pavarde" << std::setw(10) << "Galutinis\n";
        auto startWriteUnder5 = std::chrono::high_resolution_clock::now();
        for (const zmogus& student : vargsiukaiStudents) {
            vargsiukai << std::left << std::setw(20) << student.vardas << std::setw(20) << student.pavarde << std::setw(10) << student.galutinis << "\n";
        }
        auto endWriteUnder5 = std::chrono::high_resolution_clock::now();
        vargsiukai.close();

        std::chrono::duration<double> durationWriteUnder5 = endWriteUnder5 - startWriteUnder5;
        std::cout << "Irasimo i faila (vargsiukai): " << durationWriteUnder5.count() << " seconds" << std::endl;


        double totalTime = durationRead.count() + durationSort.count() + durationDivide.count() + durationWriteOver5.count() + durationWriteUnder5.count();
        std::cout << "Bendras failo apdorojimo laikas: " << totalTime << " seconds" << std::endl;
        cout << '\n';
    }
    else {
        std::cerr << "Nepavyko atidaryti failo: " << filename << std::endl;
    }
}
void calculateGalutinis(zmogus& student) {
    if (student.nd.size() > 0) {
        float sum = std::accumulate(student.nd.begin(), student.nd.end(), 0.0);
        student.vid = (sum / static_cast<float>(student.nd.size()));
        student.galutinis = student.vid * 0.4 + student.egz * 0.6;
    }
    else {
        student.vid = 0.0;
        student.galutinis = student.egz * 0.6;
    }
}
bool compareStudents(const zmogus& a, const zmogus& b) {
    if (a.galutinis == b.galutinis) {
        return rikiavimas(a, b);
    }
    return a.galutinis < b.galutinis;
}
bool rikiavimaspav(const zmogus& a, const zmogus& b) {
    size_t i = 0, j = 0;
    while (i < a.pavarde.size() && j < b.pavarde.size()) {
        if (isdigit(a.pavarde[i]) && isdigit(b.pavarde[j])) {
            int numA = 0, numB = 0;
            while (i < a.pavarde.size() && isdigit(a.pavarde[i])) {
                numA = numA * 10 + (a.vardas[i] - '0');
                i++;
            }
            while (j < b.pavarde.size() && isdigit(b.pavarde[j])) {
                numB = numB * 10 + (b.pavarde[j] - '0');
                j++;
            }
            if (numA != numB)
                return numA < numB;
        }
        else {
            if (a.pavarde[i] != b.pavarde[j])
                return a.pavarde[i] < b.pavarde[j];
            i++;
            j++;
        }
    }
    return a.pavarde.size() < b.pavarde.size();

}
