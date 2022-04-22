//
//  Date.hpp
//  CourseworkInProgramming26
//
//  Created by Сергей Насыбуллин on 26.03.2022.
//


#ifndef Date_hpp
#define Date_hpp


using namespace std;


/// Представление даты. В формате: дд.мм.гггг
class Data {
    
    // MARK:  Свойства
public:
    
    /// Разделитель даты
    static const char sep = '.';
    
private:
    /// day День. Целое число от 1 до 31
    int day;
    /// month Месяц. Целое число от 1 до 12
    int month;
    /// year Год. Целое число от 0 до 9999
    int year;
    
    
    
    // MARK:  Инициализатор
public:
    
    Data() { }
    
    /**
     * Приводит строчку типа дд.мм.гггг к дате.
     *
     * @param text Строка типа: "дд.мм.гггг"
     *
     * @throws ошибка выхода за придела даты
     */
    Data(string text) {
        string *components = ExtensionString::componentsSeparatedBy(text, sep, 3);
        day = stoi(*(components));
        month = stoi(*(components + 1));
        year = stoi(*(components + 2));
        delete [] components;
    }
    
    Data(int day, int month, int year) {
        this -> day = day;
        this -> month = month;
        this -> year = year;
    }
    
    
    
    // MARK:  Перегрузки
    
    
    Data operator = (Data second) {
        day = second.day;
        month = second.month;
        year = second.year;
        return *this;
    }
    
    const bool operator == ( Data two) const {
        return (day == two.day && month == two.month && year == two.year);
    }
    
    
    /*
     В операторах: >, <, >=, <=, сравниваются сначала год, потом месяц, потом день.
     */
    
    const bool operator > (Data two) const {
        if (year == two.year) {
            if (month == two.month) {
                return day > two.day;
            } else {
                return month > two.month;
            }
        }
        return year > two.year;
    }
    
    const bool operator >= (Data two) const {
        if (year == two.year) {
            if (month == two.month) {
                return day >= two.day;
            } else {
                return month >= two.month;
            }
        }
        return year >= two.year;
    }
    
    const bool operator <= (Data two) const {
        if (year == two.year) {
            if (month == two.month) {
                return day <= two.day;
            } else {
                return month <= two.month;
            }
        }
        return year <= two.year;
    }
    
    
    // MARK:  Методы
    
    /// setDay
    void setDay(int day) { this -> day = day; }
    
    /// setMonth
    void setMonth(int month) { this -> month = month; }
    
    /// setYear
    void setYear(int year) { this -> year = year; }
    
    /// Возвращает месяц
    const int getMonth() const { return month; }
    
    
    /// Возвращает дату в формате: дд.мм.гггг
    string description() const {
        string s;
        s += to_string(day) + sep;
        s += to_string(month) + sep;
        s += to_string(year);
        return s;
    }
    
    
    ~Data() { }
    
    
};


#endif /* Date_hpp */
