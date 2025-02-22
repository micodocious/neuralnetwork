#include <iostream>

using namespace std;

int getInt(int low, int high) {
    int input;
    while (true) {
        cin >> input;
        if (input >= low && input <= high){ 

            return input;
        }
        else {
            cout << "That number is out of bounds: Try again: ";
        }
    }
}

void printRange(int low, int high) {
    cout << "The integers between " << low << " and " << high << " are:\n";
    for (int i = low; i <= high; i++) {
        cout << i << " ";
    }
    cout << endl;
}

float printAvg(int low, int high) {
    int sum = 0;
    int count = 0;

    for (int i = low; i <= high; i++) {
        sum += i;
        count++;
    }

    float average = 1.0 * sum/count;
    return average;
    //cout << "The average of numbers between " << low << " and " << high << " is: " << average << endl;
}

void printBox(int height, int width) {
    // Print the top border
    for (int i = 0; i < width; i++) {
        cout << "*";
    }
    cout << endl;

    // Print the hollow middle part
    for (int i = 1; i < height - 1; i++) {
        cout << "*";
        for (int j = 1; j < width - 1; j++) {
            cout << " ";
        }
        cout << "*" << endl;
    }

    // Print the bottom border if height > 1
    if (height > 1) {
        for (int i = 0; i < width; i++) {
            cout << "*";
        }
        cout << endl;
    }
}

void printWedge(int height) {
    // Print the wedge with the given height
    for (int i = 1; i <= height; i++) {
        for (int j = 1; j <= (i * 2); j++) {
            cout << "*";
        }
        cout << endl;
    }
}

int main() {
    cout << "Enter a box height (between 3 and 10): ";
    int height = getInt(3, 10);

    cout << "Enter a box width (between 6 and 20): ";
    int width = getInt(6, 20);

    printRange(height, width);
    cout << "and average of numbers between " << height << " and " << width << " is: " << printAvg(height, width) << endl;

    printBox(height, width);

    printWedge(height);

    return 0;
}