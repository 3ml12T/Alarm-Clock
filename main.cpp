#include <iostream>
#include <stdlib.h>
#include <iomanip>
#include <unistd.h>
#include <ctime>
using namespace std;
//creating an Alarm class 
class Alarm {
    //Models the time (and repetition) of the alarm
    int m, h, wd;
    string day;

    public:
    Alarm (int min, int hour, int wday);

    void print(){
        dayEval(wd);
        cout << day << " " << h << ":" << m << endl;
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
};

Alarm::Alarm(int hour, int min, int wday){
    m = min;
    h = hour;
    wd = wday;
}

//current function not incrementing time (is it because time is fixed at what time the program starts?)
bool timeCheck(int hour, int min){
    bool check = false;
    time_t t = time(0);
    tm* now = localtime(&t);
    int curHour = (now->tm_hour);
    int curMin = (now->tm_min);
    cout << "Current time is " << curHour << ":" << curMin << endl;
    while ((hour != curHour) || (min != curMin)){
        cout << "Current time is " << curHour << ":" << curMin << endl;
        sleep (60);
        cout << (now->tm_hour) << ":" << (now->tm_min) << endl;
    }

    return check = true;   
}

int main (){
    int hour = 0;
    int min = 57;
    Alarm wakeUp(hour, min, 1);
    wakeUp.print();
    bool check = timeCheck(hour, min);
    cout << check << endl;
    return 0;
}
