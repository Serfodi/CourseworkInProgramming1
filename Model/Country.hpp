//
//  Country.hpp
//  CourseworkInProgramming26
//
//  Created by Сергей Насыбуллин on 07.04.2022.
//

#ifndef Country_hpp
#define Country_hpp

#include <string>


/// Абстрактный класс Страны
class Country {
public:
    /// Имя
    string name;
    /// Кол-во вхождений
    int count;
    
//    /// Возвращает все входящие номера
//    virtual string* allNumbers() = 0;
//    /// Возвращает кол-во всех входящих экземпляров
//    virtual int allCount() = 0;
    
};




// MARK: - Region

/**
 * Регион
 *
 * Входит в состав Города City class
 */
struct Region: Country {
    
    // MARK: Свойства
private:
    
    /// Номера роддомов
    string *numbers;
    
    
    // MARK: Конструкторы
public:

    Region() {}
    
    Region(string nameRegion, string* numbers, int countNumbers) {
        name = nameRegion;
        count = countNumbers;
        this -> numbers = new string[count];
        this -> numbers = numbers;
    }
    
    
    // Перегрузки
    
    string operator [] (int index) { return numbers[index]; }
    
    /// Сравнения имён
    bool operator == (Region second){ return name == second.name; }
    
    
    // Методы
    
    /// Возвращает номера роддомов
    string* const allNumbers() const  { return numbers; }
    
    /// Возвращает кол-во роддомов
    const int allCount() const  { return count; }
    
};




// MARK: - City


/// Город
struct City: Country {
    
    // MARK: Свойства
private:
    
    /// Регионы в городе
    Region *regions;

    
    // MARK: Конструкторы
public:
    
    City () {}
    
    /// Создания по имени
    City(string nameCity) {
        this -> name = nameCity;
        regions = nullptr;
        count = 0;
    }
    
    
    //    Перегрузки
    
    /// Сравнения имён
    bool operator == (City second){ return name == second.name; }
    
    
    // MARK: Методы
    
    /// Добавляет новый элемент в конец regions
    void append(Region newElement) {
        count += 1;
        Region *citiesNew = new Region[count]();
        for (int i = 0; i<count-1; i++) citiesNew[i] = regions[i];
        delete [] regions;
        citiesNew[count-1] = newElement;
        regions = citiesNew;
    }
    
    
    /// Вывод региона по слову. Как в словарике
    const Region findRegion (string region) const {
        for (int i = 0; i < count; i++)
            if (regions[i].name == region)
                return regions[i];
        return Region();
    }
    
    /**
     * Обработка выдачи номера роддомов
     *
     * Логика выдачи по area
     *
     * @param area Место поиска
     * @param areaText Адрес поиска
     * @param[out] forCount передача по адресу кол-во роддомов
     *
     * @return Динамический массив string номеров роддомов
     */
    string * const getAll(Area area, string areaText, int &forCount) const {
        string *numbers = nullptr;
        switch (area) {
            case city:
                forCount = allCount();
                numbers = new string[forCount];
                numbers = allNumbers();
                break;
            case region:
                forCount = findRegion(areaText).allCount();
                numbers = new string[forCount];
                numbers = findRegion(areaText).allNumbers();
                break;
            case hospital:
                forCount = 1;
                numbers = new string[forCount];
                numbers[0] = areaText;
                break;
        }
        return numbers;
    }
    
    /// Возвращает кол-во всех роддомов
    const int allCount() const  {
        int countNumber = 0;
        for (int i=0; i<count; i++) {
            countNumber += regions[i].count;
        }
        return countNumber;
    }
    
    /// Возвращает номера роддомов всех вхождений
    string* const allNumbers() const {
        string *numbers = new string[allCount()];
        int now = 0;
        for (int i=0; i<count; i++) {
            for (int j=0; j < regions[i].count ; j++) {
                numbers[now++] = regions[i][j];
            }
        }
        return numbers;
    }
    
};



#endif /* Hospital_hpp */
