#include <iostream>
#include <ctime>
#include <windows.h> // for Sleep() and Beep()

using namespace std;

void playAlarmSound() {
    for (int i = 0; i < 5; ++i) {
        Beep(1000, 500); // frequency, duration
        Sleep(500);
    }
}

int main() {
    int alarmHour, alarmMin, alarmSec;
    bool alarmSet = false;

    cout << "===== Digital Clock with Alarm =====\n";

    cout << "Set Alarm Time (HH MM SS): ";
    cin >> alarmHour >> alarmMin >> alarmSec;
    alarmSet = true;

    while (true) {
        time_t now = time(0);
        tm* localTime = localtime(&now);

        int hour = localTime->tm_hour;
        int min = localTime->tm_min;
        int sec = localTime->tm_sec;

        system("cls"); // clear the screen on Windows
        cout << "Current Time: "
             << (hour < 10 ? "0" : "") << hour << ":"
             << (min < 10 ? "0" : "") << min << ":"
             << (sec < 10 ? "0" : "") << sec << endl;

        if (alarmSet && hour == alarmHour && min == alarmMin && sec == alarmSec) {
            cout << "\n=== ALARM RINGING! ===\n";
            playAlarmSound();
            alarmSet = false; // prevent repeated beeping
        }

        Sleep(1000); // wait for 1 second
    }

    return 0;
}

