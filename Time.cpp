//
// Created by Alessandro Falcari on 06/12/25.
//

#include "Time.h"

#include <string>

Time::Time() {
    hour = minute = second = 0;
}
Time::Time(int hour_, int minute_, int second_) {
    hour = hour_;
    minute = minute_;
    second = second_;
}
Time::Time(Time &time_) {
    hour = time_.hour;
    minute = time_.minute;
    second = time_.second;
}
std::string Time::toString(int number_) const { return std::to_string(number_); } //per comodità

std::string Time::show(bool parametro_) const {
    int hour_ = hour;
    if (parametro_) {
        return toString(hour_) + ":" + toString(minute) + ":" + toString(second);
    } else {
        std::string suffix_;
        hour_ = getHour();
        if (hour_ <= 12) suffix_ = "AM";
        else {
            hour_ -= 12;
            suffix_ = "PM";
        }
        return toString(hour_) + suffix_ + ":" +
                toString(this->getMinute()) + ":" +
                toString(this->getSecond());
    }
}

int Time::getHour() const { return hour; }
int Time::getMinute() const { return minute; }
int Time::getSecond() const { return second; }

bool Time::operator>(const Time &time_) const {
    if (this-> getHour() > time_.getHour()) return true;
    if (this-> getHour() < time_.getHour()) return false;
    if (this-> getMinute() > time_.getMinute()) return true;
    if (this-> getMinute() < time_.getMinute()) return false;
    if (this-> getSecond() > time_.getSecond()) return true;
    if (this-> getSecond() < time_.getSecond()) return false;
    return false;
}
bool Time::operator<(const Time &time_) const {
    return (time_ > *this) && !(*this == time_);
}
bool Time::operator==(const Time &time_) const {
    return hour == time_.getHour() && minute == time_.getMinute() && second == time_.getSecond();
}
int Time::operator-(const Time &time_) const {
    //prima verifico uguaglianza
    if (*this == time_) return 0; //essendo uguali ritorno 0
    //converto
    int t1_ = hour * 3600 + minute * 60 + second;
    int t2_ = time_.getHour() * 3600 + time_.getMinute() * 60 + time_.getSecond();

    return std::abs(t1_ - t2_);
}
Time operator+(const Time &time_, int seconds_) {
    // prima converto in secondi totali
    int t1_ = time_.getHour() * 3600 +
              time_.getMinute() * 60 +
              time_.getSecond();

    // aggiungo i secondi da sommare
    t1_ += seconds_;
    // range [0, 86400) 24h in sostanza
    t1_ = (t1_ % 86400 + 86400) % 86400;
    // riconverto in h/m/s
    int hour = t1_ / 3600;
    t1_ %= 3600;
    int minute = t1_ / 60;
    int second = t1_ % 60;
    return {hour, minute, second}; //è uguale a scrivere return Time(hour, minute, second)
}

