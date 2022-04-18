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




class Country {
public:
    int count;
    string name;
    
public:
    virtual string* allNumbers() = 0;
    virtual int allCount() = 0;
    
};


struct Region: Country {
private:
    /// Номера роддомов
    string *numbers;
    
    
//     Инициализаторы
public:
    
    Region() {}
    
    Region(string nameRegion, string* numbers, int countNumbers) {
        name = nameRegion;
        count = countNumbers;
        this -> numbers = new string[count];
        this -> numbers = numbers;
    }
    
    
//     Перегрузки
    
    string operator [] (int index) { return numbers[index]; }
    
    bool operator == (Region second){ return name == second.name; }
    
    
//     Методы
    
    /// Возвращает номера роддомов
    string* allNumbers() override { return numbers; }
    
    /// Возвращает кол-во роддомов
    int allCount() override { return count; }
    
};




struct City: Country {
private:
    /// Регионы в городе
    Region *regions;

    
//    Инициализатор
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
    
    
    //    Перегрузки

    bool operator == (City second){ return name == second.name; }

    
    //    Перегрузки

    /// Вывод региона по слову. Как в словарике
    Region findRegion (string region) {
        for (int i = 0; i < count; i++)
            if (regions[i].name == region)
                return regions[i];
        return Region();
    }
    
    string* getAll(Area area, string areaText, int &forCount) {
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
                numbers = new string(areaText);
                break;
        }
        return numbers;
    }
    
    
    
    int allCount() override {
        int countNumber = 0;
        for (int i=0; i<count; i++) {
            countNumber += regions[i].count;
        }
        return countNumber;
    }
    
    
    string* allNumbers() override {
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
