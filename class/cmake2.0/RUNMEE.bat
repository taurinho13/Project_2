cmake CMakeLists.txt
cmake --install .
cmake --build .
copy src\students_1000.txt Debug\students_1000.txt
copy src\students_10000.txt Debug\students_10000.txt
copy src\students_100000.txt Debug\students_100000.txt
Debug\listcl.exe