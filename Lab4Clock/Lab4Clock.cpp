/*
* File Name: Lab4Clock.cpp
* Assignment: Lab 4 Exercise C
* Lab section: Summer
* Completed by: David Burgoin
* Development Date: May 31/2024
*/

#include "labA2.h"

// Default constructor that initializes the clock to default settings
Clock::Clock() {
    default_setter();
}

// Constructor that initializes the clock with seconds, adjusting to hours, minutes, and seconds
Clock::Clock(int user_sec) {
    if (user_sec >= 0) {
        default_setter();
        sec_to_hms(user_sec);
    } else {
        default_setter();
    }
}

// Constructor that initializes the clock with specified hours, minutes, and seconds
Clock::Clock(int user_hour, int user_min, int user_sec) {
    // Validate the input time values
    if ((-user_hour * (user_hour - 24) >= 0) && 
        (-user_min * (user_min - 60) >= 0) && 
        (-user_sec * (user_sec - 60) >= 0)) {
        hour = user_hour;
        min = user_min;
        sec = user_sec;
    } else {
        default_setter();
    }
}

// Increment the time by one second
void Clock::increment() {
    sec_to_hms(hms_to_sec() + 1);
}   

// Decrement the time by one second
void Clock::decrement() {
    sec_to_hms(hms_to_sec() - 1);
} 

// Add a specific number of seconds to the current time
void Clock::add_seconds(int user_sec) {
    sec_to_hms(hms_to_sec() + user_sec);
}

// Getter for the seconds component of the time
int Clock::get_second() const {
    return sec;
}

// Getter for the minutes component of the time
int Clock::get_minute() const {
    return min;
}

// Getter for the hours component of the time
int Clock::get_hour() const {
    return hour;
}

// Setter for the seconds component, with validation
void Clock::set_second(int user_sec) {
    if (-user_sec * (user_sec - 60) >= 0) {
        sec = user_sec;
    } else {
        // Invalid input, do nothing
    }
}

// Setter for the minutes component, with validation
void Clock::set_minute(int user_min) {
    if (-user_min * (user_min - 60) >= 0) {
        min = user_min;
    } else {
        // Invalid input, do nothing
    }
}

// Setter for the hours component, with validation
void Clock::set_hour(int user_hour) {
    if ((-user_hour * (user_hour - 24)) >= 0) {
        hour = user_hour;
    } else {
        // Invalid input, do nothing
    }
}

// Helper function to convert hours, minutes, and seconds to total seconds
long int Clock::hms_to_sec() {
    return hour * 3600 + min * 60 + sec;
}

// Helper function to convert total seconds to hours, minutes, and seconds
void Clock::sec_to_hms(long int user_sec) {
    // Adjust for negative time
    if ((hms_to_sec() + user_sec) < 0) {
        user_sec += 86400; // Add a full day in seconds
    }
    day = user_sec / (3600 * 24); // Calculate days
    hour = (user_sec / 3600) % 24; // Calculate hours
    min = (user_sec / 60) % 60; // Calculate minutes
    sec = user_sec % 60; // Calculate seconds
}

// Helper function to set the clock to default time (00:00:00)
void Clock::default_setter() {
    day = 0;
    hour = 0;
    min = 0;
    sec = 0;
}
