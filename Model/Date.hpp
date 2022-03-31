//
//  Date.hpp
//  CourseworkInProgramming26
//
//  Created by Сергей Насыбуллин on 26.03.2022.
//

/**
 * @file
 * Используется:
 *  -
 */

#ifndef Date_hpp
#define Date_hpp

#include <stdio.h>

//#include <iostream>
#include <string>
#include "ExtensionString.hpp"


using namespace std;


/**
 * @brief Представление даты. В формате: дд.мм.гггг
 */
struct Data {
    
    // MARK: - Свойства
private:

    static const char sep = '.';
    
    /// day День. Целое число от 1 до 31
    int day;
    /// month Месяц. Целое число от 1 до 12
    int month;
    /// year Год. Целое число от 0 до 9999
    int year;
    
    
    // MARK: - Инициализаторы
public:
    
    Data() { }
    
    /// Приводит строчку типа дд.мм.гггг к дате.
    Data(string text) {
        string *components = ExtensionString::componentsSeparatedBy(text, sep, 3);
        day = stoi(*(components));
        month = stoi(*(components + 1));
        year = stoi(*(components + 2));
    }
    
    
    // MARK: - Методы класса
    
    // Перегрузки
    
    void operator = (Data second) {
        day = second.day;
        month = second.month;
        year = second.year;
    }
    
    // Вспомогательные методы
    
    /// Передает информацию
    string description() {
        string s;
        s += to_string(day) + sep;
        s += to_string(month) + sep;
        s += to_string(year);
        return s;
    }
    
};


#endif /* Date_hpp */
