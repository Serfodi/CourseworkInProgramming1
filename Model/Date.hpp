//
//  Date.hpp
//  CourseworkInProgramming26
//
//  Created by Сергей Насыбуллин on 26.03.2022.
//

/**
 * @file Модель даты
 */

#ifndef Date_hpp
#define Date_hpp

#include <stdio.h>


#include <string>
#include "ExtensionString.hpp"


using namespace std;


/// @brief Представление даты. В формате: дд.мм.гггг
struct Data {
    
    // MARK: - Свойства
    
    /// Разделитель даты
    static const char sep = '.';
    
private:
    /// day День. Целое число от 1 до 31
    int day;
    /// month Месяц. Целое число от 1 до 12
    int month;
    /// year Год. Целое число от 0 до 9999
    int year;
    
    
    // MARK: - Инициализатор
public:
    
    Data() { }
    
    /// Приводит строчку типа дд.мм.гггг к дате.
    Data(string text) {
        string *components = ExtensionString::componentsSeparatedBy(text, sep, 3);
        day = stoi(*(components));
        month = stoi(*(components + 1));
        year = stoi(*(components + 2));
    }
    
    Data(int day, int month, int year) {
        this -> day = day;
        this -> month = month;
        this -> year = year;
    }
    
    // MARK: - Методы класса
    
    // Перегрузки
    
    void operator = (Data second) {
        day = second.day;
        month = second.month;
        year = second.year;
    }
    
    bool operator == ( Data two) {
        return (day == two.day && month == two.month && year == two.year);
    }
    
    bool operator > (Data two) {
        if (year == two.year) {
            if (month == two.month) {
                return day > two.day;
            } else {
                return month > two.month;
            }
        }
        return year > two.year;
    }
    
    bool operator >= (Data two) {
        if (year == two.year) {
            if (month == two.month) {
                return day >= two.day;
            } else {
                return month >= two.month;
            }
        }
        return year >= two.year;
    }
    
    bool operator <= (Data two) {
        if (year == two.year) {
            if (month == two.month) {
                return day <= two.day;
            } else {
                return month <= two.month;
            }
        }
        return year <= two.year;
    }
    
    
    // Вспомогательные методы
    
    /// Выдает день из даты
    int getMonth() {
        return month;
    }
    
    /// Передает информацию
    string description() {
        string s;
        s += to_string(day) + sep;
        s += to_string(month) + sep;
        s += to_string(year);
        return s;
    }
    
};

//ostream& operator << (ostream &out, Data data) {
//    return out << data.description();
//}

#endif /* Date_hpp */
