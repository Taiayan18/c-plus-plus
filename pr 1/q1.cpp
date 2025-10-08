#include <iostream>
using namespace std;

class time {
public:

 int totalsec;
    void setSeconds(int seconds) {
        totalsec = seconds;
    }

    void convertToHMS() {
        int hours, minutes, seconds;
        hours = totalsec / 3600;
        minutes = (totalsec % 3600) / 60;
        seconds = totalsec % 60;

        cout << "HH:MM:SS => " << hours << ":" << (minutes < 10 ? "0" : "") << minutes << ":" << (seconds < 10 ? "0" : "") << seconds << endl;
    }
};

int main() {
    time t1;
    int seconds;

    cout << "Enter total seconds: ";
    cin >> seconds;

    t1.setSeconds(seconds);
    t1.convertToHMS();

    return 0;
}