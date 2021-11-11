// lab11.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
using namespace std;

int getUserInput(string phrase);
void displayVector(vector<int> val1, vector<int> val2, int size, int start);

// prototype of function you will be writing
void displayVectorPointers(int* val1, int* val2, int size, int start);

int main()
{
    cout << "Hello Welcome to the team generation program!\n";
    cout << "Press enter to start the program.\n";
    int teams = getUserInput("Please enter the number of teams: \n");
    int rounds = getUserInput("Please enter the number of rounds: \n");
    int middle = teams / 2;

    vector<string> pairs;
    vector<int> val1;
    vector<int> val2;
    int endValue = 1;
    for (int i = 1; i <= middle; i++) {
        val1.push_back(i);
    }
    for (int i = teams; i > middle; i--) {
        val2.push_back(i);
        endValue = i;
    }

    cout << "Round 0:" << endl;
    //displayVector(val1, val2, middle, 0); // comment out this line

    // Use this code to call the function
    int *p1 = &val1.at(0);
    int *p2 = &val2.at(0);
    displayVectorPointers(p1, p2, middle, 0);

    for (int i = 1; i < rounds; i++) {
        //cout << endValue << " & " << 14 << endl;
        cout << "Round " << i << ":" << endl;
        val1.at(0) = endValue; val2.at(0) = teams;

        for (int j = 1; j < middle; j++) {
            int v1 = val1.at(j) + middle;
            if (v1 > (teams - 1)) { v1 = v1 - (teams - 1); }
            val1.at(j) = v1;

            int v2 = val2.at(j) + middle;
            if (v2 > (teams - 1)) { v2 = v2 - (teams - 1); }
            val2.at(j) = v2;
            endValue = v2;
        }

        //displayVector(val1, val2, middle, 0);
        displayVectorPointers(p1, p2, middle, 0);
    }

    string temp = "";
    cout << "Press any letter to close" << endl;
    cin >> temp;
}

int getUserInput(string phrase) {
    int userInput = 0;
    do {
        cin.clear();
        cin.ignore(200, '\n');
        cout << phrase;
        cin >> userInput;
    } while (cin.fail());
    return userInput;
}

void displayVector(vector<int> val1, vector<int> val2, int size, int start) {
    for (int i = 0; i < size; i++) {
        cout << val1[i] << " & " << val2[i] << endl;
    }
}

void displayVectorPointers(int* val1, int* val2, int size, int start) {
    for (int i = 0; i < size; i++) {
        cout << *val1 << " & " << *val2 << endl;
        val1++;
        val2++;
    }
}

