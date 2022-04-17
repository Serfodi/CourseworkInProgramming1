//
//  City.hpp
//  CourseworkInProgramming26
//
//  Created by Сергей Насыбуллин on 07.04.2022.
//

#ifndef City_hpp
#define City_hpp

#include <string>

//#include "DataModel.hpp"

// Supporting
#include "ExtensionString.hpp"



struct Region {
    /// Названия Региона
    string name;
    /// Номера роддомов
    string *numbers;
    /// кол-во роддомов
    int count;
    
    /// Создает Регион
    ///
    /// @param numbers Строка типа: 12, 123, 134. раздельная разделителями
    /// @param count кол-во слов раздельная разделителем
    Region (string *numbers, int count) {
        this -> count = count;
        this -> numbers = new string[count];
        this -> numbers = numbers;
    }
    
};

struct City {
    /// Названия Города
    string name;
    /// Регионы в городе
    Region *regions;
    /// кол-во регионов
    int count;
};


/// Класс где хранится города и госпитали для их ассациации
class Hospital {
    ///  Города
    City *cities;
    ///  Кол-во городов
    int count = 0;
    
public:
    Hospital() {}
    
    
    
    
    
};


/*
 
 
 /// Добавляет новый элемент в конец массива
 void append(City newElement) {
 count += 1;
 City *hospitalNew = new City[count];
 for (int i = 0; i<count-1; i++) hospitalNew[i] = hospitals[i];
 delete [] hospitals;
 hospitalNew[count-1] = newElement;
 hospitals = hospitalNew;
 }
 
 */


#endif /* Hospital_hpp */
