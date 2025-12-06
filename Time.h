//
// Created by Alessandro Falcari on 06/12/25.
//

#ifndef CLASSETEMPO_TIME_H
#define CLASSETEMPO_TIME_H
#include <string>


class Time {
private:
    int hour;
    int minute;
    int second;
public:
    Time(); //def
    Time(int hour_, int minute_, int second_); //paramentri
    Time(Time &time_); //copia
    [[nodiscard]] std::string toString(int number_) const;
    [[nodiscard]] std::string show(bool parametro_) const;
    [[nodiscard]] int getHour() const;
    [[nodiscard]] int getMinute() const;
    [[nodiscard]] int getSecond() const;
    //parte operator
    bool operator>(const Time &time_) const;
    bool operator<(const Time &time_) const;
    bool operator==(const Time &time_) const;
    int operator-(const Time &time_) const;
    friend Time operator+(const Time &time_, int seconds_);
};


#endif //CLASSETEMPO_TIME_H