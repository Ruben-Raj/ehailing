#include <iostream>
#include <iomanip>
#include <string>
#include <limits>
using namespace std;

void clearInputBuffer() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

double getPositiveNumber(const string& prompt) {
    double value;
    while (true) {
        cout << prompt;
        cin >> value;
        if (cin.fail() || value <= 0) {
            cout << "Invalid input! Please enter a positive number: ";
            clearInputBuffer();
        }
        else {
            clearInputBuffer();
            return value;
        }
    }
}

int getChoiceInRange(const string& prompt, int minVal, int maxVal) {
    int choice;
    while (true) {
        cout << prompt;
        cin >> choice;
        if (cin.fail() || choice < minVal || choice > maxVal) {
            cout << "Invalid choice! Please enter a number between "
                << minVal << " and " << maxVal << ": ";
            clearInputBuffer();
        }
        else {
            clearInputBuffer();
            return choice;
        }
    }
}

int main() {
    cout << "================================================" << endl;
    cout << "        WELCOME TO GRAB RIDE-HAILING" << endl;
    cout << "================================================" << endl;
    cout << endl;

    cout << "Please select a ride type:" << endl;
    cout << "1. Standard (JustGrab) - Nearest car or taxi" << endl;
    cout << "2. Standard | 6 seats - Alza, Cruz & Others" << endl;
    cout << "3. Standard | Plus - Vios, City & Others" << endl;
    cout << "4. Standard | Taxi - Metered budget taxi" << endl;
    cout << "5. Premium - Camry, Accord & Others" << endl;
    cout << "6. Premium | Exec 6 - Such as Vellfire" << endl;
    cout << endl;

    int rideChoice = getChoiceInRange("Enter your choice (1-6): ", 1, 6);

    string rideType, carModel, estimatedTime;
    double baseFare, perKmRate, perMinuteRate;

    switch (rideChoice) {
    case 1:
        rideType = "Standard (JustGrab)";
        carModel = "Nearest car or taxi";
        estimatedTime = "7 mins away";
        baseFare = 3.00;
        perKmRate = 1.20;
        perMinuteRate = 0.30;
        break;
    case 2:
        rideType = "Standard | 6 seats";
        carModel = "Alza, Cruz & Others";
        estimatedTime = "5 mins away";
        baseFare = 4.00;
        perKmRate = 1.50;
        perMinuteRate = 0.35;
        break;
    case 3:
        rideType = "Standard | Plus";
        carModel = "Vios, City & Others";
        estimatedTime = "8 mins away";
        baseFare = 3.50;
        perKmRate = 1.30;
        perMinuteRate = 0.32;
        break;
    case 4:
        rideType = "Standard | Taxi";
        carModel = "Metered budget taxi";
        estimatedTime = "7 mins away";
        baseFare = 2.50;
        perKmRate = 1.10;
        perMinuteRate = 0.28;
        break;
    case 5:
        rideType = "Premium";
        carModel = "Camry, Accord & Others";
        estimatedTime = "9 mins away";
        baseFare = 6.00;
        perKmRate = 2.00;
        perMinuteRate = 0.50;
        break;
    case 6:
        rideType = "Premium | Exec 6";
        carModel = "Such as Vellfire";
        estimatedTime = "9 mins away";
        baseFare = 8.00;
        perKmRate = 2.50;
        perMinuteRate = 0.60;
        break;
    }

    double distance = getPositiveNumber("Enter trip distance (km): ");
    double tripTime = getPositiveNumber("Enter estimated trip time (minutes): ");

    double distanceFee = distance * perKmRate;
    double timeFee = tripTime * perMinuteRate;
    double totalFare = baseFare + distanceFee + timeFee;

    cout << endl;
    cout << "================================================" << endl;
    cout << "             RIDE CONFIRMATION" << endl;
    cout << "================================================" << endl;
    cout << "Ride Type: " << rideType << endl;
    cout << "Car Model: " << carModel << endl;
    cout << "Est. Arrival: " << estimatedTime << endl;
    cout << "Trip Distance: " << distance << " km" << endl;
    cout << "Est. Trip Time: " << tripTime << " minutes" << endl;
    cout << "----------------------------------------" << endl;
    cout << "Base Fare: RM" << fixed << setprecision(2) << baseFare << endl;
    cout << "Distance Fee: RM" << distanceFee << endl;
    cout << "Time Fee: RM" << timeFee << endl;
    cout << "----------------------------------------" << endl;
    cout << "TOTAL FARE: RM" << totalFare << endl;
    cout << "================================================" << endl;

    char confirm;
    cout << endl;
    cout << "Confirm booking? (Y/N): ";
    cin >> confirm;
    clearInputBuffer();

    if (toupper(confirm) == 'Y') {
        cout << endl;
        cout << "Booking confirmed! Your driver is on the way." << endl;
        cout << endl;
        cout << "Not in the mood to chat? Try a Quiet Ride." << endl;
        cout << endl;
        cout << "Payment Method: [Cash] [Offers]" << endl;
        cout << endl;
        cout << "Book " << rideType << endl;
        cout << endl;
        cout << "Thank you for choosing Grab!" << endl;
    }
    else {
        cout << endl;
        cout << "Booking cancelled. Thank you for considering Grab!" << endl;
    }

    return 0;
}