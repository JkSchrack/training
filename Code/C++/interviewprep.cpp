#include <iostream>
#include <fstream>
using namespace std;

class Student {
public:
    Student () {
        cout << "\nNew Student Initialized\n";
    }
    string name;
    double gpa;
    string studentNumber;
    string faculty;
};

void power(float x, float y) {
    float value = 1;
    for(float i = 0; i < abs(y); i++) {
        value *= x;
    }
    if ( y < 0) {
        value = 1 / value;
    }
    cout << x << " to the power of " << y << " = " << value << "\n";
}

void palindrome(string words[] ) {
    for (int i = 0; i < words->size(); i++) {
        bool check = true;
        int length = words[i].size() - 1;
        for (int n = 0; n < length/2; n++) {
            if (words[i][n] != words[i][length - n]) {
                check = false;
            }
        }
        if (check) {
            cout << words[i] << " is a palindrome!\n";
        } else {
            cout << words[i] << " is NOT a palindrome!\n";
        }
    }
}

void clockAngle(double hour, double minute){
    double minuteAngles = 360/ 60;
    double hourAngles = 360 / 12;

    double minuteHand = minute * minuteAngles;
    double hourHand = (hour * hourAngles) + (hourAngles * (minute / 60));

    double clockHand = hourHand - minuteHand;
    if (clockHand < 0) {
        clockHand = minuteHand - hourHand;
    }
    cout << "The angle between the clock hands at " << hour << ":" << minute << " is " << clockHand << "\n";
    cout << "Hour hand angle: " << hourHand << " & " << "Minute hand angle: " << minuteHand << "\n";
}

void primeNumbers(int start, int end) {
    while(start < end) {
        bool check = true;
        for (int i = 2; i <= start/2; i++) {
            if (start % i == 0) {
                check = false;
            }
        }
        if (check) {
            cout << start << " is a prime number!\n";
        }
        start++;
    }
}

int twotime(int x){
    return x*2;
}

string reversal(string line){
    string reversed;
    int length = line.length();
    for (int i = length; i >= 0; i--) {
        reversed += line[i];
    }
    return reversed;
}

void fileManipulator(string filename){
    string line;
    string prior;
    int lineCount = 0;
    ifstream file(filename);
    while (getline (file, line)) {
        lineCount++;
        if (lineCount % 2 != 0) {
            prior = line;
        } else {
            cout << reversal(line) << "\n";
            cout << prior << "\n";
        }
    }
    if (lineCount % 2 != 0){
        cout << reversal(line) << "\n";
    }
    file.close();
}

int Fibonacci(int number) {
    cout << number << endl;
    if (number <= 1) return number;

    return Fibonacci(number - 2) + Fibonacci(number - 1);
}

int run() {
    cout << "Power of a Number\n";
    power(2, -3);
    cout << "\n";

    cout << "Palindrome Check\n";
    string words[] = {"tomato", "potato", "radar", "anna", "turkey", "kayak"};
    palindrome(words);
    cout << "\n";

    cout << "Clock Hand Angles\n";
    clockAngle(4, 26);
    cout << "\n";

    Student tony;

    tony.name = "Tony McRoni";
    tony.gpa = 3.5;
    tony.studentNumber = "A0069420";
    tony.faculty = "Applied Science";

    cout << tony.name << " is student " << tony.studentNumber;
    cout << ", enrolled in " << tony.faculty;
    cout << " and has a gpa of " << tony.gpa << "!\n";

    primeNumbers(5, 31);

    cout << "Power of a Number\n";
    power(2, twotime(3));
    cout << "\n";

    fileManipulator("C:\\Users\\Justin\\Downloads\\untitled\\lines.txt");
}
/*
 * DHCP: Dynamic Host Configuration Protocol: Assigns IP addresses to Devices
 *  Configure dhcpd daemon on each switch
 *      Edit dhcpd.conf file
 *      dhcpd.service is listening on NetDev1 bridge interface & NetDev2 Interface
 *
 * DNS: Domain Name Service: Maps Names to IP's
 *  Configure Authoritative Name Server nsd -> nsd.conf
 *      Provides authoritative address resolutions for intnet1.2620.acit domain
 *  Configure Caching Recursive Name Server Configuration unbound -> unbound.conf & dhcpd.conf
 *      Resolve DNS requests originating from 10.0.100.0/24 network
 *      Using nmtui/nmcli
 *
 */

//Queue = (FIFO)First in First Out
//Stack = (LIFO)Last In First Out
//Header File contains Function & Data Type Definitions

//Encapsulation limits external use; Public/Private Variables & Methods
//Abstraction extension of Encapsulation, hides details and only shows a High-Level mechanism
//Inheritance shares common logic; Attributes
//Polymorphism means to process objects differently based on their data type