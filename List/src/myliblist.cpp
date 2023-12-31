#include "pch.h"

void processFileData(list<zmogus>& grupe) {

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
void processLine(const string& line, list<zmogus>& grupe) {
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
void calculateMedian(list<int>& nd, float& med) {
    nd.sort();

    if (nd.size() % 2 == 0) {
        auto it1 = nd.begin();
        std::advance(it1, nd.size() / 2 - 1);
        int mid1 = *it1;

        auto it2 = nd.begin();
        std::advance(it2, nd.size() / 2);
        int mid2 = *it2;

        med = (mid1 + mid2) / 2.0;
    }
    else {
        auto it = nd.begin();
        std::advance(it, nd.size() / 2);
        med = *it;
    }
}
void calculateAverage(const list<int>& nd, float& vid) {
    float nd_sum = 0;
    for (int k : nd) {
        nd_sum += k;
    }
    vid = (nd_sum / nd.size());
}
void inputStudentData(list<zmogus>& grupe) {
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
void printStudentData(const list<zmogus>& grupe, int choice) {
    cout << std::left << setw(15) << "Vardas" << setw(15) << "Pavarde" << setw(10) << "Galutinis (";

    if (choice == 1) {
        cout << setw(10) << std::left << "vid.)";
    }
    else if (choice == 2) {
        cout << setw(10) << std::left << "med.)";
    }

    cout << setw(15) << "Address" << endl;

    cout << std::setfill('-') << std::setw(60) << "-" << std::setfill(' ') << std::endl;

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

        // Get the address of the object and convert it to a string
        uintptr_t address = reinterpret_cast<uintptr_t>(&a);
        cout << " 0x" << std::hex << address << std::dec;

        cout << endl;
    }
}
void generateRandomGrades(int ndskaicius, std::list<int>& nd) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 10);

    for (int i = 0; i < ndskaicius; i++) {
        int k = dis(gen);
        std::cout << k << " ";
        nd.push_back(k);
    }
}
void printStudentDataToFile(const list<zmogus>& grupe, int choice, ofstream& outputFile) {
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
    int numStudents[] = { 1000, 10000, 100000, 1000000, 10000000 };
    int numHomeworks = 4;
    string filenames[] = { "students_1000.txt", "students_10000.txt", "students_100000.txt",
                          "students_1000000.txt", "students_10000000.txt" };

    cout << "Pasirinkite pagal ka surusiuoti duomenis (v - vardas, p - pavarde, g - galutinis): ";
    string rusiavimoKriterijus;
    cin >> rusiavimoKriterijus;

    cout << "Pasirinkite strategija (1 - Strategija 1, 2 - Strategija 2, 3 - Strategija 3): ";
    int strategija;
    cin >> strategija;
    cout << '\n';

    for (int i = 0; i < 5; i++) {

        ifstream fileCheck(filenames[i]);
        if (fileCheck.good()) {
            cout << "File " << filenames[i] << " already exists. Skipping generation." << endl;
        }
        else {
            auto start = chrono::high_resolution_clock::now();
            generateStudentFile(numStudents[i], numHomeworks, filenames[i]);
            auto end = std::chrono::high_resolution_clock::now();
            chrono::duration<double> duration = end - start;
            cout << "Failo kurimo laikas (" << filenames[i] << "): " << duration.count() << " sekundes" << endl;
        }

        calculateGalutinisForFile(filenames[i], rusiavimoKriterijus, strategija);
    }
}
void generateStudentFile(int numStudents, int numHomeworks, const std::string& filename) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> examDist(1, 10);
    uniform_int_distribution<> ndDist(1, 10);

    ofstream outputFile(filename);

    if (outputFile.is_open()) {
        outputFile << std::left << std::setw(22) << "Vardas" << std::setw(22) << "Pavarde";

        for (int i = 1; i <= numHomeworks; ++i) {
            outputFile << std::setw(10) << "ND" + std::to_string(i);
        }

        outputFile << std::setw(10) << " Egzaminas\n";

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
void calculateGalutinisForFile(const string& filename, string rusiavimoKriterijus, int strategija) {

    ifstream inputFile(filename);

    if (inputFile.is_open()) {
        auto startRead = chrono::high_resolution_clock::now();
        string line;
        list<zmogus> students;

        while (getline(inputFile, line)) {
            istringstream iss(line);
            zmogus student;
            iss >> student.vardas >> student.pavarde;

            int grade;

            if (iss >> grade) {
                student.egz = grade;
                while (iss >> grade) {
                    student.nd.push_back(grade);
                }
            }
            else {
                student.egz = 0;
            }

            calculateGalutinis(student);

            students.push_back(student);
        }

        inputFile.close();
        auto endRead = std::chrono::high_resolution_clock::now();

        chrono::duration<double> durationRead = endRead - startRead;
        cout << "Failo (" << filename << ") nuskaitymo laikas: " << durationRead.count() << " sekundes" << std::endl;

        /*string sortingCriteria;

        cout << "Pasirinkite pagal ka surusiuoti duomenis (vardas/pavarde/galutinis): ";
        cin >> sortingCriteria;*/

        auto startSort = std::chrono::high_resolution_clock::now();

        if (rusiavimoKriterijus == "v") {
            students.sort([](const zmogus& a, const zmogus& b) {
                return rikiavimas(a, b);
                });
        }
        else if (rusiavimoKriterijus == "p") {
            students.sort([](const zmogus& a, const zmogus& b) {
                return rikiavimaspav(a, b);
                });
        }
        else if (rusiavimoKriterijus == "g") {
            students.sort(compareStudents);
        }
        else {
            cout << "Netinkamas rusiavimo kriterijus. Naudojamas numatytasis (galutinis)." << endl;
            students.sort(compareStudents);
        }
        auto endSort = std::chrono::high_resolution_clock::now();

        std::chrono::duration<double> durationSort = endSort - startSort;
        std::cout << "Failo (" << filename << ") rusiavimo laikas : " << durationSort.count() << " sekundes" << std::endl;

        /*std::cout << "Choose an option (1 - Strategija 1, 2 - Strategija 2): ";
        int option;
        std::cin >> option;*/

        if (strategija == 1) {

            list<zmogus> kietiakaiStudents;
            list<zmogus> vargsiukaiStudents;
            
            auto startDivision = std::chrono::high_resolution_clock::now();

            for (const auto& student : students) {
                if (student.galutinis >= 5) {
                    kietiakaiStudents.push_back(student);
                }
                else {
                    vargsiukaiStudents.push_back(student);
                }
            }

            auto endDivision = std::chrono::high_resolution_clock::now();
            std::chrono::duration<double> durationDivision = endDivision - startDivision;
            std::cout << "Division time: " << durationDivision.count() << " sekundes" << std::endl;

            ofstream kietiakai("kietiakai_" + filename);
            ofstream vargsiukai("vargsiukai_" + filename);

            kietiakai << std::left << std::setw(20) << "Vardas" << std::setw(20) << "Pavarde" << std::setw(10) << "Galutinis\n";
            vargsiukai << std::left << std::setw(20) << "Vardas" << std::setw(20) << "Pavarde" << std::setw(10) << "Galutinis\n";

            auto startWriteKietiakai = std::chrono::high_resolution_clock::now();
            for (const auto& student : kietiakaiStudents) {
                kietiakai << std::left << std::setw(20) << student.vardas << std::setw(20) << student.pavarde << std::setw(10) << student.galutinis << "\n";
            }
            auto endWriteKietiakai = std::chrono::high_resolution_clock::now();
            std::chrono::duration<double> durationWriteKietiakai = endWriteKietiakai - startWriteKietiakai;
            kietiakai.close();

            std::cout << "Irasimo i faila (kietiakai): " << durationWriteKietiakai.count() << " sekundes" << std::endl;

            auto startWriteVargsiukai = std::chrono::high_resolution_clock::now();
            for (const auto& student : vargsiukaiStudents) {
                vargsiukai << std::left << std::setw(20) << student.vardas << std::setw(20) << student.pavarde << std::setw(10) << student.galutinis << "\n";
            }
            auto endWriteVargsiukai = std::chrono::high_resolution_clock::now();
            std::chrono::duration<double> durationWriteVargsiukai = endWriteVargsiukai - startWriteVargsiukai;    

            vargsiukai.close();
            std::cout << "Irasimo i faila (vargsiukai): " << durationWriteVargsiukai.count() << " sekundes" << std::endl;
            
            double totalTime = durationRead.count() + durationSort.count() + durationDivision.count() + durationWriteKietiakai.count() + durationWriteVargsiukai.count();
            std::cout << "Bendras failo apdorojimo laikas: " << totalTime << " sekundes" << std::endl;
            std::cout << '\n';
        }

        else if (strategija == 2) {

            list<zmogus> vargsiukai;

            auto startDivision = std::chrono::high_resolution_clock::now();

            for (auto it = students.begin(); it != students.end(); ) {
                if (it->galutinis < 5) {
                    vargsiukai.push_back(*it);
                    it = students.erase(it);
                }
                else {
                    ++it;
                }
            }

            auto endDivision = std::chrono::high_resolution_clock::now();
            std::chrono::duration<double> durationDivision = endDivision - startDivision;
            std::cout << "Division time: " << durationDivision.count() << " sekundes" << std::endl;

            ofstream studentsFile("students_" + filename);
            ofstream vargsiukaiFile("vargsiukai2_" + filename);

            studentsFile << std::left << std::setw(20) << "Vardas" << std::setw(20) << "Pavarde" << std::setw(10) << "Galutinis\n";
            vargsiukaiFile << std::left << std::setw(20) << "Vardas" << std::setw(20) << "Pavarde" << std::setw(10) << "Galutinis\n";

            auto startStudent = std::chrono::high_resolution_clock::now();

            for (const auto& student : students) {
                studentsFile << std::left << std::setw(20) << student.vardas << std::setw(20) << student.pavarde << std::setw(10) << student.galutinis << "\n";
            }

            auto endStudent = chrono::high_resolution_clock::now();


            chrono::duration<double> durationStudent = endStudent - startStudent;
            cout << "Irasimo i faila (Student): " << durationStudent.count() << " sekundes" << endl;

            auto startVargsiukai = chrono::high_resolution_clock::now();

            for (const auto& student : vargsiukai) {
                vargsiukaiFile << left << setw(20) << student.vardas << setw(20) << student.pavarde << setw(10) << student.galutinis << "\n";
            }

            auto endVargsiukai = chrono::high_resolution_clock::now();

            chrono::duration<double> durationVargsiukai = endVargsiukai - startVargsiukai;
            cout << "Irasimo i faila (vargsiukai): " << durationVargsiukai.count() << " sekundes" << endl;

            studentsFile.close();
            vargsiukaiFile.close();

            double totalTime = durationRead.count() + durationSort.count() + durationDivision.count() + durationStudent.count() + durationVargsiukai.count();
            cout << "Bendras failo apdorojimo laikas: " << totalTime << " sekundes" << endl;
            cout << '\n';
        }
        else if (strategija == 3){

            //list<zmogus> vargsiukai;
            

            auto startDivision = std::chrono::high_resolution_clock::now();

            auto partitionIt = std::partition(students.begin(), students.end(), [](const zmogus& student) {
                return student.galutinis < 5;
                });
            
            list<zmogus> vargsiukai(partitionIt, students.end());
            students.erase(partitionIt, students.end());

            /*
            auto newEnd = remove_if(students.begin(), students.end(), [](const zmogus& student) {
                return student.galutinis < 5;
                });

            copy_if(students.begin(), newEnd, back_inserter(vargsiukai), [](const zmogus& student) {
                return student.galutinis < 5;
                });

            students.erase(newEnd, students.end());
            */

            auto endDivision = std::chrono::high_resolution_clock::now();
            std::chrono::duration<double> durationDivision = endDivision - startDivision;
            std::cout << "Division time: " << durationDivision.count() << " sekundes" << std::endl;

            ofstream studentsFile("students_" + filename);
            ofstream vargsiukaiFile("vargsiukai2_" + filename);

            studentsFile << std::left << std::setw(20) << "Vardas" << std::setw(20) << "Pavarde" << std::setw(10) << "Galutinis\n";
            vargsiukaiFile << std::left << std::setw(20) << "Vardas" << std::setw(20) << "Pavarde" << std::setw(10) << "Galutinis\n";

            auto startStudent = std::chrono::high_resolution_clock::now();

            for (const auto& student : students) {
                studentsFile << std::left << std::setw(20) << student.vardas << std::setw(20) << student.pavarde << std::setw(10) << student.galutinis << "\n";
            }

            auto endStudent = chrono::high_resolution_clock::now();


            chrono::duration<double> durationStudent = endStudent - startStudent;
            cout << "Irasimo i faila (Student): " << durationStudent.count() << " sekundes" << endl;

            auto startVargsiukai = chrono::high_resolution_clock::now();

            for (const auto& student : vargsiukai) {
                vargsiukaiFile << left << setw(20) << student.vardas << setw(20) << student.pavarde << setw(10) << student.galutinis << "\n";
            }

            auto endVargsiukai = chrono::high_resolution_clock::now();

            chrono::duration<double> durationVargsiukai = endVargsiukai - startVargsiukai;
            cout << "Irasimo i faila (vargsiukai): " << durationVargsiukai.count() << " sekundes" << endl;

            studentsFile.close();
            vargsiukaiFile.close();

            double totalTime = durationRead.count() + durationSort.count() + durationDivision.count() + durationStudent.count() + durationVargsiukai.count();
            cout << "Bendras failo apdorojimo laikas: " << totalTime << " sekundes" << endl;
            cout << '\n';
        }

        else {
            std::cerr << "Ivestas netinkamas pasirinkimas: " << filename << std::endl;
        }
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
    return a.galutinis > b.galutinis;
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
