#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

void modifyTxtFile() {
    // Open the text file for reading
    ifstream inFile("macro2_input_suyo copy 2.txt");
    if (!inFile.is_open()) {
        cout << "Error opening file!" << endl;
        return;
    }

    // Create a string variable to hold the modified contents of the file
    string fileContents;

    // Read the contents of the text file line by line
    string line;
    while (getline(inFile, line)) {
        // Replace the comma in the first column with a space
        line.replace(line.find(','), 1, " ");

        // Add a zero in a new column at the end of the line
        istringstream iss(line);
        int col1;
        double col2;
        iss >> col1 >> col2;
        ostringstream oss;
        oss << col1 << " " << col2 << " 0" << endl;
        fileContents += oss.str();
    }
    inFile.close();

    // Open the text file for writing and write the modified contents
    ofstream outFile("macro2_input_suyo copy 2.txt");
    if (!outFile.is_open()) {
        cout << "Error opening file!" << endl;
        return;
    }
    outFile << fileContents;
    outFile.close();
}

int main(){
    modifyTxtFile();
    return 0;
}