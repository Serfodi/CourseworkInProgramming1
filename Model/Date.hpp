//
//  Date.hpp
//  CourseworkInProgramming26
//
//  Created by Сергей Насыбуллин on 26.03.2022.
//


#ifndef Date_hpp
#define Date_hpp



/// Представление даты. В формате: дд.мм.гггг
struct Date {
    
    // MARK:  Свойства
public:
    
    /// Разделитель даты
    static const char sep = '.';
    
    /// day День. Целое число от 1 до 31
    int day;
    /// month Месяц. Целое число от 1 до 12
    int month;
    /// year Год. Целое число от 0 до 9999
    int year;
    
    
    
    // MARK:  Инициализатор
    
    Date() {}
    
    Date(int day, int month, int year) {
        this -> day = day;
        this -> month = month;
        this -> year = year;
    }
    
    static Date dateCast(string text) {
        vector<string> components = ExtensionString::componentsSeparatedBy(text, sep);
        int day = stoi(components[0]);
        int month = stoi(components[1]);
        int year = stoi(components[2]);
        return Date(day,month,year);
    }
    
    
    // MARK:  Перегрузки
    
    
    Date& operator = (const Date &second) {
        day = second.day;
        month = second.month;
        year = second.year;
        return *this;
    }
    
    const bool operator == ( Date two) const {
        return (day == two.day && month == two.month && year == two.year);
    }
    
    
    /*
     В операторах: >, <, >=, <=, сравниваются сначала год, потом месяц, потом день.
     */
    
    const bool operator >= (Date two) const {
        if (year == two.year) {
            if (month == two.month) {
                return day >= two.day;
            } else {
                return month >= two.month;
            }
        }
        return year >= two.year;
    }
    
    const bool operator <= (Date two) const {
        if (year == two.year) {
            if (month == two.month) {
                return day <= two.day;
            } else {
                return month <= two.month;
            }
        }
        return year <= two.year;
    }
    
    const bool operator > (Date two) const {
        if (year == two.year) {
            if (month == two.month) {
                return day > two.day;
            } else {
                return month > two.month;
            }
        }
        return year > two.year;
    }
    
    const bool operator < (Date two) const {
        if (year == two.year) {
            if (month == two.month) {
                return day < two.day;
            } else {
                return month < two.month;
            }
        }
        return year < two.year;
    }
    
    
    /// Возвращает дату в формате: дд.мм.гггг
    string description() const {
        string s;
        s += ExtensionString::leading(day, 2) + sep;
        s += ExtensionString::leading(month, 2) + sep;
        s += ExtensionString::leading(year, 4);
        return s;
    }
    
};

ostream& operator << (ostream &out, const Date& date) {
    out << ExtensionString::leading(date.day, 2) + Date::sep;
    out << ExtensionString::leading(date.month, 2) + Date::sep;
    out << ExtensionString::leading(date.year, 4);
    return out;
}

#endif /* Date_hpp */
