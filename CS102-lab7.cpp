//
//  main.cpp
//  Lab7
//
//  Created by Daisy Whitfield on 5/6/19.
//  Copyright © 2019 Daisy Whitfield. All rights reserved.
//

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include<vector>
using namespace std;

vector<string> openFile2Vector(ifstream&);
string inputData2Vector(string&, int);
void writeVector2File(ofstream&, vector<string>&);
void displayFileData(ifstream&);

int main(int argc, const char * argv[]) {
    vector<string> filedataVector;
    ifstream filePass;
    ofstream passFile;
    
    filedataVector = openFile2Vector(filePass);
    for(int i = 0; i < 3; i++)
        filedataVector[i] = inputData2Vector(filedataVector[i], i);
    writeVector2File(passFile, filedataVector);
    displayFileData(filePass);
    return 0;
}

vector<string> openFile2Vector(ifstream& inputFile) {
    vector<string> inputFileLines;
    int counter = 0;
    string line;
    
    inputFile.open("/Users/daisywhitfield/Desktop/lab7/Lab7/Lab7/info.txt", ios::in);
    while(!inputFile.is_open() && counter <= 50) {
        inputFile.open("/Users/daisywhitfield/Desktop/lab7/Lab7/Lab7/info.txt", ios::in);
        counter++;
    }
    if(counter == 51) {
        cout << "File failed to open " << 50 << " times.  Please check file." << endl;
        exit(0);
    } else
        while(!inputFile.eof())
            for(int i = 0; i < 3; i++) {
                getline(inputFile, line, '\n' );
                inputFileLines.push_back(line);
            }
    inputFile.close();
    return inputFileLines;
}

void writeVector2File(ofstream& outputFile, vector<string>& writeData) {
    int counter = 0;
    
    outputFile.open("/Users/daisywhitfield/Desktop/lab7/Lab7/Lab7/record.txt", ios::out);
    while(!outputFile.is_open() && counter <= 50) {
        outputFile.open("/Users/daisywhitfield/Desktop/lab7/Lab7/Lab7/record.txt", ios::out);
        counter++;
    }
    if(counter == 51) {
        cout << "File failed to open " << 50 << " times.  Please check file." << endl;
        exit(0);
    } else
        for(int i = 0; i < 3; i++)
            outputFile << writeData[i] << endl;
    outputFile.close();
}

string inputData2Vector(string& vectorItem, int counter) {
    string name = "";
    string courseName = "";
    counter += 1;
    
    vectorItem.replace(17,13, "Course name: ");
    cout << "Student " << counter << ": ";
    getline(cin, name, '\n');
    cout << "Course name: ";
    getline(cin, courseName, '\n');
    vectorItem.insert(30, courseName);
    vectorItem.insert(6, name);
    return vectorItem;
}

void displayFileData(ifstream& finalFile) {
    int counter = 0;
    string line;
        
    finalFile.open("/Users/daisywhitfield/Desktop/lab7/Lab7/Lab7/record.txt", ios::in);
    while(!finalFile.is_open() && counter <= 50) {
        finalFile.open("/Users/daisywhitfield/Desktop/lab7/Lab7/Lab7/record.txt", ios::in);
        counter++;
    }
    if(counter == 51) {
        cout << "File failed to open " << 50 << " times.  Please check file." << endl;
        exit(0);
    } else
        while(!finalFile.eof()) {
            getline(finalFile, line, '\n');
            if(line.length() > 30) {
                cout << "The string has " << line.length() << " characters." << endl;
                if(line.find("518",0) == -1)
                    cout << "ID not found." << endl;
                else
                    cout << "Student ID 518 found." << endl;
            } else
                cout << "End of file." << endl;
        }
}

