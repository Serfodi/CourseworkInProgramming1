//
//  ModelBirth.hpp
//  CourseworkInProgramming26
//
//  Created by Сергей Насыбуллин on 26.03.2022.
//

/**
 * @file
 * Используется:
 *      - main
 *      - Input
 *      - Processing
 *      - List
 */

#ifndef ModelBirth_hpp
#define ModelBirth_hpp

#include <stdio.h>

#include <iostream>

#include "Date.hpp"


/// Пол ребенка или его отсутствия
enum Sex {
    /// Мальчик
    m,
    /// Девочка
    g,
    /// Нет ребенка
    no
};

/**
 * Модель данных о рождении детей.
 */
struct Birth {
public:
    /// Номер роддома
    int number;
    /// Дата рождения ребенка
    Data dOB;
    /// Район
    std::string region;
    /// Фио матери
    std::string fIO;
    /// Дата рождения матери
    Data dOBMother;
    /// Дети
    Sex children[3];
    
    
    // MARK: - Инициализаторы
    
    Birth() { }
    
    Birth(
          int _number,
          Data _dOB,
          std::string _region,
          std::string _fIO,
          Data _dOBMother,
          Sex _children[3]
          )
    {
        number = _number;
        dOB = _dOB;
        region = _region;
        fIO = _fIO;
        dOBMother = _dOBMother;
        for (int i = 0; i<3; i++) children[i] = _children[i];
    }
    
    
    /// Описание
    std::string description() {
        std::string text;
        text += std::to_string(number) + "\n";
        text += dOB.description() + "\n";
        text += region + "\n";
        text += fIO + "\n";
        text += dOBMother.description() + "\n";
        for (int i = 0; i < 3; i++) text += std::to_string(children[i]) + " ";
        text += "\n";
        return text;
    }
    
};


#endif /* ModelBirth_hpp */
