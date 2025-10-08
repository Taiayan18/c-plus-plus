#include <iostream>
using namespace std;

class TimeConverter {
public:
int hours, minutes, seconds;
    void setTime(int h, int m, int s) {
        hours = h;
        minutes = m;
        seconds = s;
    }

    int toSeconds() {
        return (hours * 3600) + (minutes * 60) + seconds;
    }

    void display() {
        cout << "Total seconds: " << toSeconds() << endl;
    }
};

int main() {
    TimeConverter t;
    int h, m, s;

    cout << "Enter hours: ";
    cin >> h;

    cout << "Enter minutes: ";
    cin >> m;

    cout << "Enter seconds: ";
    cin >> s;

    t.setTime(h, m, s);
    t.display();

    return 0;
}