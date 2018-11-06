#include <iostream>
<<<<<<< HEAD
#include <cstring>
using namespace std;


int main() {
	string s;
	cin >> s;
	cout << strlen(s) << endl;
	return 0;
}
=======
#include <cmath>
#include <iomanip>
#include <sstream>
using namespace std;

std::string to_format(const int number) {
    std::stringstream ss;
    ss << std::setw(2) << std::setfill('0') << number;
    return ss.str();
}

struct Time
{
    int hour, minute, second;
    Time(int initHour, int initMinute, int initSecond)
    {
        // cin >> initHour >> initMinute >> initSecond;
        hour = initHour;
        minute = initMinute;
        second = initSecond;
    }
    void getTimeDifference(Time other)
    {
        int time1 = hour*3600 + minute * 60 + second;
        int time2 = other.hour*3600 + other.minute * 60 + other.second;
        int time_dif = abs(time1 - time2);
        cout << to_format(time_dif/3600) << to_format((time_dif%3600)/60) << to_format(time_dif - (time_dif/3600)*3600 - ((time_dif%3600)/60)*60);
    }
};

int main()
{
    int hour, minute, second;
    cin >> hour >> minute >> second;
    Time time1(hour,minute,second);
    cin >> hour >> minute >> second;
    Time time2(hour,minute,second);
    time1.getTimeDifference(time2);
    return 0;
}
>>>>>>> 4b14f3b9861686129e6fa637493b0b9dfcc7034c
