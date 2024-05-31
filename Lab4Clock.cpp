


#include <iostream>
#include <iomanip>
#include "labA2.h"
using std::cout;
using std::endl;
using std::setw;
using std::setfill;

    Clock::Clock(){
        default_setter();
    }
    Clock::Clock(int user_sec){
        if (user_sec>0){
        default_setter();
        sec_to_hms(user_sec);
        }
        else
        default_setter();
    }
    Clock::Clock(int user_hour, int user_min, int user_sec){

        if ( (-user_hour * (user_hour-24) >= 0) && (-user_min * (user_min-60) >= 0) && (-user_sec * (user_sec-60) >= 0) ){
        hour = user_hour;
        min = user_min;
        sec = user_sec;
        }
        else
        {
            default_setter();
        }
    }
    void Clock::increment(){
        sec_to_hms(hms_to_sec()+1);

    }   

    void Clock::decrement(){
        sec_to_hms(hms_to_sec()-1);
    } 

    void Clock::add_seconds(int user_sec){
        sec_to_hms(hms_to_sec()+user_sec);
    }

    int Clock::get_second()const{
        return sec;
    }
    int Clock::get_minute()const{
        return min;
    }
    int Clock::get_hour()const{
        return hour;
    }
    void Clock::set_second(int user_sec){
        try
        {
        if (-user_sec * (user_sec-60) >= 0){
            sec = user_sec;
        }
        else
            throw 0; // No error code implemeted
        }
        catch(const int selected_defaults)
        {   
            std::cout << "invalid sec value "<< setw(2) << user_sec << 
            " Expected to show: " << setw(2) << hour << ":" << setw(2) << min << ":" << setw(2) << sec <<"\n";
        }
    }
    void Clock::set_minute(int user_min){
        try
        {
        if (-user_min * (user_min-60) >= 0){
            min = user_min;
        }
        else
            throw 0; // No error code implemeted
        }
        catch(const int selected_defaults)
        {   
            std::cout << "invalid min value "<< setw(2) << user_min << 
            " Expected to show: " << setw(2) << hour << ":" << setw(2) << min << ":" << setw(2) << sec <<"\n";
        }
    }
    void Clock::set_hour(int user_hour){
        try
        {
        if ((-user_hour * (user_hour-24)) >= 0){
            hour = user_hour;
        }
        else
            throw 0; // No error code implemeted
        }
        catch(const int selected_defaults)
        {   
            std::cout << "invalid hour value: "<< setw(2) << user_hour << 
            " Expected to show: " << setw(2) << hour << ":" << setw(2) << min << ":" << setw(2) << sec <<"\n";
        }
    }


    long int Clock::hms_to_sec(){
        return hour*3600+min*60+sec;
    }
    void Clock::sec_to_hms(long int user_sec){
        if ((hms_to_sec() + user_sec)<0){
        user_sec+=86400;
        }
        day = user_sec/(3600*24);
        hour = (user_sec/3600)%24;
        min = (user_sec/60)%60;
        sec = user_sec%60;
    }
    void Clock::default_setter(){
        day = 0;
        hour = 0;
        min = 0;
        sec = 0;
    }
