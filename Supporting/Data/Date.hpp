//
//  Date.hpp
//  CourseworkInProgramming26
//
//  Created by Сергей Насыбуллин on 26.03.2022.
//

#ifndef Date_hpp
#define Date_hpp

#include <stdio.h>

#include <iostream>
#include <string>


/**
 Data - содержит  дату в формате дд.мм,гггг:
 int day
 int month
 int y*ear
 */
using namespace std;
struct Data {
public:
    static const char sep = '.';
    
    int day;
    int month;
    int year;
    
    Data() { }
    
    Data(int _day, int _month, int _year) {
        day = _day;
        month = _month;
        year = _year;
    }
    
    Data(string data[]) {
        day = stoi(*(data));
        month = stoi(*(data + 1));
        year = stoi(*(data + 2));
    }
    
    void operator = (Data second) {
        day = second.day;
        month = second.month;
        year = second.year;
    }
    
    string description() {
        string s;
        s += to_string(day) + sep;
        s += to_string(month) + sep;
        s += to_string(year);
        return s;
    }
};


#endif /* Date_hpp */
