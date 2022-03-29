//
//  Date.hpp
//  CourseworkInProgramming26
//
//  Created by Сергей Насыбуллин on 26.03.2022.
//

/**
 * @file
 * Используется:
 *      - Input
 *      - Processing
 *      - ModelBirth
 */

#ifndef Date_hpp
#define Date_hpp

#include <stdio.h>

#include <iostream>
#include <string>


using namespace std;

/**
 * @brief Представление даты. В формате: дд.мм.гггг
 */
struct Data {
    
    // MARK: - Свойства
public:
    static const char sep = '.';
    
private:
    /// day День. Целое число от 1 до 31
    int day;
    /// month Месяц. Целое число от 1 до 12
    int month;
    /// year Год. Целое число от 0 до 9999
    int year;
    
    
    // MARK: - Инициализаторы
public:
    
    Data() { }
    
    Data(int _day, int _month, int _year) {
        day = _day;
        month = _month;
        year = _year;
    }
    
    /**
     * @warning Передавать нужно массив string[3] в которых будет числа и только они.
     */
    // ошибки скорее всего в input
    Data(string data[3]) {
        day = stoi(*(data));
        month = stoi(*(data + 1));
        year = stoi(*(data + 2));
    }
    
    /**
     * @warning Передавать нужно массив string в виде числа
     */
    Data(string day, string month, string year) {
        this->day = stoi(day);
        this->month = stoi(month);
        this->year = stoi(year);
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
