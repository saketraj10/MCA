#include <iostream>
#include <fstream>

using namespace std;

void createFile(const string& fileName) {
    string fileString;
    ofstream outFile(fileName);

    cout << "Enter some text into the file: ";
    cin.ignore();
    getline(cin, fileString);
    outFile << fileString;
    outFile.close();
}

void convertCase(const string& fileName) {
    ifstream inFile(fileName);
    ofstream outFile("temp.txt");

    char ch;
    cout << "Case conversion ongoing";

    while (inFile.get(ch)) {
        if (islower(ch)) {
            ch = toupper(ch);
            cout << ch;
            outFile << ch;
        } else if (isupper(ch)) {
            ch = tolower(ch);
            cout << ch;
            outFile << ch;
        }
    }

    inFile.close();
    outFile.close();

    remove(fileName.c_str());
    rename("temp.txt", fileName.c_str());
}

void displayContent(const string& fileName) {
    ifstream inFile(fileName);
    char ch;

    while (inFile.get(ch)) {
        cout << ch;
    }

    inFile.close();
}

int countCharA(const string& fileName) {
    ifstream inFile(fileName);
    char ch;
    int count = 0;

    while (inFile.get(ch)) {
        if (tolower(ch) == 'a') {
            count++;
        }
    }

    inFile.close();

    return count;
}

int main() {
    int choice;
    string fileName;

    cout << "Enter the file name: ";
    cin >> fileName;
    createFile(fileName);

    do {
        cout << "\nMenu\n";
        cout << "1. Convert case\n";
        cout << "2. Display content\n";
        cout << "3. Count occurrences of 'a'\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                convertCase(fileName);
                cout << "Case conversion done.\n";
                break;
            case 2:
                cout << "\nFile content:\n";
                displayContent(fileName);
                break;
            case 3:
                cout << "\nNumber of 'a' occurrences: " << countCharA(fileName) << endl;
                break;
            case 4:
                cout << "Exiting the program.\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 4);

    return 0;
}