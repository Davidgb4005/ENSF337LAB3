/*
* File Name: Lab4Clock.h
* Assignment: Lab 4 Exercise C
* Lab section: Summer
* Completed by: David Burgoin
* Development Date: May 31/2024
*/

#ifndef LAB4_H
#define LAB4_H

// Definition of the Clock class
class Clock {
public:
    // Default constructor
    Clock();

    // Constructor with seconds parameter
    Clock(int user_sec);

    // Constructor with hour, minute, and second parameters
    Clock(int user_hour, int user_min, int user_sec);

    // Increment the time by one second
    void increment();
    
    // Decrement the time by one second
    void decrement();
    
    // Add a specific number of seconds to the current time
    void add_seconds(int user_sec);

    // Getters for the time components
    int get_second() const;
    int get_minute() const;
    int get_hour() const;

    // Setters for the time components
    void set_second(int user_sec);
    void set_minute(int user_min);
    void set_hour(int user_hour);

private:
    // Time components
    int day;
    int hour;
    int min;
    int sec;

    // Helper function to convert hours, minutes, and seconds to total seconds
    long int hms_to_sec();

    // Helper function to convert total seconds to hours, minutes, and seconds
    void sec_to_hms(long int user_sec);

    // Helper function to set the clock to default time (00:00:00)
    void default_setter();
};

#endif
