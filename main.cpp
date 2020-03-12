#include <iostream>
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

bool timeCheck(int hour, int min){
    int curHour, curMin;
    
    do
    {
        /* code */
    } while (/* condition */);
       
}

int main (){
    Alarm wakeUp(7, 30, 1);
    wakeUp.print();
}
