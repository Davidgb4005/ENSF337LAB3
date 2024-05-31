// ENSF 337 - Spring 2024 - Exercise B
// lab4String.h
// M. Moussavi

#ifndef LAB3_H
#define LAB3_H

class Clock {
public:
    Clock();

    Clock(int user_sec);

    Clock(int user_hour, int user_min, int user_sec);

    void increment();
    void decrement();
    void add_seconds(int user_sec);
    int get_second()const;
    int get_minute()const;
    int get_hour()const;
    void set_second(int user_sec);
    void set_minute(int user_min);
    void set_hour(int user_hour);

private:
    int day;
    int hour;
    int min;
    int sec;

    long int hms_to_sec();
    void sec_to_hms(long int user_sec);
    void default_setter();
};


#endif /* lab4String_h */
