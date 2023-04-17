/*
 * Caleb St.Germain
 * chs0043
 * Project3_StGermain_CHS0043
 */
#include <fstream>
#include <iostream>
#include <cstdlib>

using namespace std;

const int MAX_SIZE = 100;

int readfile(int inputArray[], ifstream& inStream) {
    int index = 0;
    if (inStream.fail()) {
        cout << "\tFailed to open input file \n";
        return -1;
    }
    else {
        inStream >> inputArray[index];
        while (!inStream.eof()) {
            if (index >= MAX_SIZE -1) {
                cout << "\tFile size is too large\n";
                return -1;
            }
            index++;
            inStream >> inputArray[index];
        }
        return index + 1;
    }
}

int sort(int inputArray1[], int inputArray1_size, int inputArray2[],
         int inputArray2_size, int outputArray[]) {
    bool done = false;
    int j = 0;
    int k = 0;
    int outputSize = 0;
    while (!done) {
        if (j < inputArray1_size && k < inputArray2_size) {
            if (inputArray1[j] < inputArray2[k]) {
                if (outputSize > 0) {
                    if (inputArray1[j] != outputArray[outputSize - 1]) {
                        outputArray[outputSize] = inputArray1[j];
                    }
                }
                else {
                    outputArray[outputSize] = inputArray1[j];
                }
                j++;
            }
            else if (inputArray1[j] > inputArray2[k]) {
                if (outputSize > 0) {
                    if (inputArray2[k] != outputArray[outputSize - 1]) {
                        outputArray[outputSize] = inputArray2[k];
                    }
                }
                else {
                    outputArray[outputSize] = inputArray2[k];
                }
                k++;
            }
            else {
                if (outputSize > 0) {
                    if (inputArray1[j] != outputArray[outputSize - 1]) {
                        outputArray[outputSize] = inputArray1[j];
                    }
                }
                else {
                    outputArray[outputSize] = inputArray1[j];
                }
                j++;
                k++;
            }
        }
        else if (j < inputArray1_size) {
            if (outputSize > 0) {
                if (inputArray1[j] != outputArray[outputSize -1]) {
                    outputArray[outputSize] = inputArray1[j];
                }
            }
            else {
                outputArray[outputSize] = inputArray1[j];
            }
            j++;
        }
        else if (k < inputArray2_size) {
            if (outputSize > 0) {
                if (inputArray2[k] != outputArray[outputSize -1]) {
                    outputArray[outputSize] = inputArray2[k];
                }
            }
            else {
                outputArray[outputSize] = inputArray2[k];
            }
            k++;
        }
        else {
            done = true;
            return outputSize;
        }
        outputSize++;
    }
}

void writefile(int outputArray[], int outputArray_size, string file) {
    ofstream outStream;
    //Open/create file
    outStream.open((char*)file.c_str());
    if (outStream.fail()) {
        cout << "Could not write to file";
    }
    else {
        for (int i = 0; i < outputArray_size; i++) {
            outStream << outputArray[i] << endl;
        }
    }
    outStream.close();
}

int main() {
    ifstream inStream;
    int iArray1[MAX_SIZE];
    int iArray1_size;
    int iArray2[MAX_SIZE];
    int iArray2_size;
    string filename;
    int outputArray[MAX_SIZE];
    int outputArray_size;

    //Get first file
    cout << "*** Welcome to Caleb's sorting program ***\n";
    cout << "Enter the first input file name: ";
    cin >> filename;
    inStream.open((char*)filename.c_str());
    iArray1_size = readfile(iArray1, inStream);
    inStream.close();
    if (iArray1_size != -1) {
        cout << "The list of " << iArray1_size << " numbers in file " << filename << " is:\n";
        for (int i = 0; i < iArray1_size; i++) {
            cout << iArray1[i] << endl;
        }
        cout << endl;
    }
    else {
        exit(1);
    }

    cout << "Enter the second input file name: ";
    cin >> filename;
    inStream.open((char*)filename.c_str());
    iArray2_size = readfile(iArray2, inStream);
    inStream.close();
    if (iArray2_size != -1) {
        cout << "The list of " << iArray2_size << " numbers in file " << filename << " is:\n";
        for (int i = 0; i < iArray2_size; i++) {
            cout << iArray2[i] << endl;
        }
        cout << endl;
    }
    else {
        exit(1);
    }

    outputArray_size = sort(iArray1, iArray1_size, iArray2, iArray2_size, outputArray);

    cout << "The sorted list of " << outputArray_size << " numbers is: ";
    for (int i = 0; i < outputArray_size; i++) {
        cout << outputArray[i] << " ";
    }
    cout << endl;
    if (outputArray_size == -1) {
        exit(1);
    }

    string file;
    cout << "Enter the output file name: ";
    cin >> file;
    writefile(outputArray, outputArray_size, file);
    cout << "*** Please check the new file - " << file << " ***\n";
    cout << "*** Goodbye. ***\n";


}

