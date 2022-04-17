//
//  Country.hpp
//  CourseworkInProgramming26
//
//  Created by Сергей Насыбуллин on 07.04.2022.
//

#ifndef Country_hpp
#define Country_hpp

#include <string>

// Supporting
#include "ExtensionString.hpp"




struct Region {
    /// Названия Региона
    string name;
    /// Номера роддомов
    string *numbers;
    /// кол-во роддомов
    int count;
    
    Region() {}
    
    /// Строка типа: Центральный|1,2,3
    Region (string text) {
        string *components = ExtensionString::componentsSeparatedBy(text, '|', 2);
        name = components[0];
        count = ExtensionString::countWords(components[1], ',');
        string *componentsNumber = ExtensionString::componentsSeparatedBy(components[1], ',', count);
        numbers = new string[count];
        for (int i=0; i<count; i++) numbers[i] = componentsNumber[i];
    }
    
    bool operator == (Region second){ return name == second.name; }
    
    string* getAllNumbers() {
        return numbers;
    }
    
    
};

struct City {
private:
    /// Названия Города
    string name;
    /// Регионы в городе
    Region *regions;
    /// кол-во регионов
    int count;

public:
    City () {}
    
    City(string nameCity) {
        this -> name = nameCity;
        regions = nullptr;
        count = 0;
    }
    
    /// Добавляет новый элемент в конец regions
    void append(Region newElement) {
        count += 1;
        Region *citiesNew = new Region[count]();
        for (int i = 0; i<count-1; i++) citiesNew[i] = regions[i];
        delete [] regions;
        citiesNew[count-1] = newElement;
        regions = citiesNew;
    }
    
    /// Сравнивает имена
    bool operator == (City second){ return name == second.name; }
    
    
    /// Вывод региона по слову. Как в словарике
    Region operator [] (string region) {
        for (int i = 0; i < count; i++)
            if (regions[i].name == region)
                return regions[i];
        return Region();
    }
    
    /// Выдает Регион по индексу
    Region operator[] (int index) {
        return regions[index];
    }
    
    /// Выдает имя Города
    string getName() { return name; }
    /// Выдает кол-во регионов 
    int getCount() { return count; }
    
    
    int getAllNumberCount() {
        int countNumber = 0;
        for (int i=0; i<count; i++) {
            countNumber += regions[i].count;
        }
        return countNumber;
    }
    
    string* getAllNumbers() {
        int countNumbers = getAllNumberCount();
        string *numbers = new string[countNumbers];
        int now = 0;
        for (int i=0; i<count; i++) {
            for (int j=0; j < regions[i].count ; j++) {
                numbers[now++] = regions[i].numbers[j];
            }
        }
        return numbers;
    }
    
    
};



#endif /* Hospital_hpp */
