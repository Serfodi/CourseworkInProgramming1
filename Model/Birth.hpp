//
//  Birth.hpp
//  CourseworkInProgramming26
//
//  Created by Сергей Насыбуллин on 26.03.2022.
//

/**
 * @file Описания модели Birth и методы обработки из файла
 */

#ifndef Birth_hpp
#define Birth_hpp

#include <stdio.h>


// Model
#include "Sex.hpp"
#include "Date.hpp"

// Supporting
#include "ExtensionString.hpp"


using namespace std;


/// Модель данных о рождении детей.
struct Birth {
    
    // MARK: - Свойства
public:
    
    /// Номер роддома
    int number;
    /// Дата рождения ребенка
    Data dOB;
    /// Район
    string region;
    /// Фио матери
    string fIO;
    /// Дата рождения матери
    Data dOBMother;
    /// Дети
    SexСhild children[3];
    
    
    // MARK: - Инициализаторы
    
    
    Birth() { }
    
    /// @brief Приводит строку к Birth
    ///
    /// @param text Строка типа: | Номер роддома |  Дата рожд ребенка | Район | ФИО |  Дата  рожд. матери |  Пол 1 реб. | Пол 2 реб. | Пол 3 реб. |
    /// Разделенная сепаратором
    ///
    /// @see FileProces Data Sex
    ///
    /// @warning Использовать тольк для обработки текста из файла.
    ///
    Birth(string text) {
        string *components = ExtensionString::componentsSeparatedBy(text, '|', 8);
        number = stoi(*(components + 0));
        dOB = Data(*(components + 1));
        region = (*(components + 2));
        fIO = *(components + 3);
        dOBMother = Data(*(components + 4));
        for (int i = 0; i < 3; i++)
            children[i] = Sex::sexCast(*(components + i + 5));
        delete [] components;
    }
    
    /// Для поиска
    ///
    /// Заполняет только ФИО и Дату рождения матери
    Birth(string fIO, Data data) {
        number = 0;
        dOB = Data();
        region = "";
        this -> fIO = fIO;
        this -> dOBMother = data;
        for (int i = 0; i < 3; i++)
            children[i] = SexСhild::no;
    }
    
    
    // Перегрузки
    
    Birth operator = (Birth second) {
        number = second.number;
        dOB = second.dOB;
        region = second.region;
        fIO = second.fIO;
        dOBMother = second.dOBMother;
        for (int i = 0; i < 3; i++)
            children[i] = second.children[i];
        return *this;
    }
    
    
    bool operator != (Birth second) {
        return !(fIO == second.fIO && dOBMother == second.dOBMother);
    }
    bool operator == (Birth second) {
        return (fIO == second.fIO && dOBMother == second.dOBMother);
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
