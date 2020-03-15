#include <iostream>
#include <stdlib.h>
#include <iomanip>
#include <unistd.h>
#include <ctime>
using namespace std;
//creating an Alarm class 

struct alarmTime{
    int wday;
    int hour;
    int min;
    int sec;
};

class Alarm {
    //Models the time (and repetition) of the alarm
    public: 

    string day;

    Alarm (alarmTime ringTime);

    void print(){ //error in this function because ringTime undeclared
        dayEval(ringTime.wday);
        cout << day << " " << ringTime.hour << ":" << ringTime.min << ":" << ringTime.sec << endl;
    }

    void dayEval(int wday){
        switch (wday)
        {
        case 0:
            day = "Sunday";
            break;
        
        case 1:
            day = "Monday";
            break;
        
        case 2: 
            day = "Tuesday";
            break;
        
        case 3: 
            day = "Wednesday";
            break;

        case 4: 
            day = "Thursday";
            break;

        case 5:
            day = "Friday";
            break;

        case 6:
            day = "Saturday";
            break;
        }
    }

    alarmTime curTime(){
        time_t t = time(0);
        tm* now = localtime(&t);
        alarmTime current;
        current.hour = (now->tm_hour);
        current.min = (now->tm_min);
        current.wday = (now->tm_wday);
        current.sec = (now->tm_sec);
        return current;
    }

    bool timeCheck(alarmTime ringTime){
        bool check = false;
        alarmTime  currentTime;
        currentTime = curTime();

        while ((currentTime.hour != ringTime.hour) || (currentTime.min != ringTime.min) || currentTime.sec != ringTime.sec){
            sleep(60);
            currentTime = curTime();
        }

        return check = true;   
    }
};

/*Alarm::Alarm(alarmTime ringTime, int wday){
    wd = wday;
}*/

int main (){
    alarmTime wakeTime;
    int min, hour, wday, sec;
    cin >> wday;
    cin >> hour;
    cin >> min;
    cin >> sec;

    wakeTime.wday = wday;
    wakeTime.hour = hour;
    wakeTime.min = min;
    wakeTime.sec = sec;

    Alarm wakeUp(wakeTime);

    wakeUp.print();

    if (wakeUp.timeCheck(wakeTime)){
        cout << "AHHHH" << endl;
    }

    return 0;
}
