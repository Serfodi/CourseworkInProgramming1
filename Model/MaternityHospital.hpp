//
//  MaternityHospital.hpp
//  CourseworkInProgramming26
//
//  Created by Сергей Насыбуллин on 07.04.2022.
//

#ifndef MaternityHospital_hpp
#define MaternityHospital_hpp

#include <stdio.h>
#include <string>

// Supporting
#include "ExtensionString.hpp"


/// Модель Района
struct Region {
public:
    
    string name;
    int *number;
    int count;
    
    Region() {}
    
    Region (string text) {
        string *components = ExtensionString::componentsSeparatedBy(text, '/', 2);
        name = components[0];
        count = ExtensionString::countWords(components[1], ',');
        string *componentsNumber = ExtensionString::componentsSeparatedBy(components[1], ',', count);
        number = new int[count];
        for (int i=0; i<count; i++)
            number[i] = stoi(componentsNumber[i]);
    }
    
    /// Для поиска по названию
    ///
    /// @param number Пустой (Нужен для обхода ограничения с++)
    ///
    Region(string name, int number) {
        this -> name = name;
    }
    
    
    
    bool operator == (Region second) {
        return name == second.name;
    }
    
//    ~Region() {
//        delete [] number;
//    }
    
};


/// Модель города
struct City {
public:
    
    string name;
    Region *region;
    int count;
    
    // Конструктор
    
    City() {}
    
    City (string name, Region region) {
        this -> name = name;
        this -> region = new Region(region);
        count = 1;
    }
    
    // Москва=Центральный/1,2,3
    City (string text) {
        string *components = ExtensionString::componentsSeparatedBy(text, '=', 2);
        name = components[0];
        count = ExtensionString::countWords(components[1], '|');
        string *componentsRegion = ExtensionString::componentsSeparatedBy(components[1], '|', count);
        region = new Region[count];
        for (int i=0; i<count; i++)
            region[i] = Region(componentsRegion[i]);
    }
    
    
    // Перегрузка операторов
    
    Region operator[] (int index) {
        return region[index];
    }
    
    bool operator == (Region second) {
        return name == second.name;
    }
     
    
    // Деконструктор
    
    ~City() {
        delete [] region;
    }
    
};


/// Класс где хранится города и госпитали для их ассациации
class Hospital {
    /// Массив госпиталей
    City *hospitals;
    /// Кол-во госпиталей в массиве
    int count = 0;
    
public:
    
    Hospital() {}
    
    
    
    // MARK: Методы
    
    /// Добавляет новый элемент в конец массива
    void append(City newElement) {
        count += 1;
        City *hospitalNew = new City[count];
        for (int i = 0; i<count-1; i++) hospitalNew[i] = hospitals[i];
        delete [] hospitals;
        hospitalNew[count-1] = newElement;
        hospitals = hospitalNew;
    }
    
    
    
    // MARK: Перегрузка операторов
    
    /// Вывод по названию города
    City operator[] (string city) {
        for (int i=0; i<count; i++) {
            if (hospitals[i].name == city){
                return hospitals[i];
            }
        }
        return City("non", Region("non", -1));
    }
    
    /// Вывод по названию региона
    City operator[] (Region region) {
        for (int i=0; i<count; i++) {
            for (int j=0; j<hospitals[i].count; j++) {
                if (hospitals[i].region[j] == region){
                    return hospitals[i];
                }
            }
        }
        return City("non", Region("non", -1));
    }
    
    /// Вывод по названию региона
    City operator[] (int number) {
        for (int i=0; i<count; i++) {
            for (int j=0; j<hospitals[i].count; j++) {
                for (int k=0; k<hospitals[i].region[j].count; k++){
                    if (hospitals[i].region[j].number[k] == number){
                        return hospitals[i];
                    }
                }
            }
        }
        return City("non", Region("non", -1));
    }
    
    
    
    // MARK: Деконструктор
    
    ~Hospital () {
        delete [] hospitals;
    }
    
    
    
};


#endif /* MaternityHospital_hpp */
