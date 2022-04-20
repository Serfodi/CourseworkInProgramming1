//
//  Output.hpp
//  CourseworkInProgramming26
//
//  Created by Сергей Насыбуллин on 26.03.2022.
//

/**
 * @file Отвечает за вывод
 */

#ifndef Output_hpp
#define Output_hpp

#include <stdio.h>
#include <iostream>


// supporting
#include "ChoiceMenu.hpp"



using namespace std;


/// Класс Output отвечает за вывод в консоль.
class OutputMenu {
public:
    /// Текст для выбора обработки.
    const string textСP[6] = {
        "Выберите обработку:",
        "1. Просмотр данных по времени.",
        "2. Вывод гистограммы рождаемости по месяцам года и кривой  рождаемости за год.",
        "3. Определение месяцев максимальной и минимальной рождаемости.",
        "4. Удаление записей о родах.",
        "Введите число от 1 до 4: "
    };
    /// Текст для выбора места
    const string textArea[5] = {
        "Искать:",
        "1. По роддому.",
        "2. По району.",
        "3. По городу.",
        "Введите число от 1 до 3: "
    };
    /// Текст для выбора форматы даты
    const string textDataFormat[4] = {
        "Выберите день или интервал:",
        "1. День.",
        "2. Интервал.",
        "Введите число 1 или 2: "
    };
    /// Текст для выбора критерий поиска рождаемости
    const string textBirthrate[6] = {
        "Критерии поиска:",
        "1. Общей рождаемости",
        "2. Только мальчиков",
        "3. Только девочек",
        "4. Многодетных родов ( более одного ребенка)",
        "Введите число от 1 до 4: "
    };
    
    /// Текст для просьбы ввода даты.
    const string textDataFormatInput[2] = {
        "Введите день в формате 'дд.мм.гггг': ",
        "Введите интервал в формате 'дд.мм.гггг - дд.мм.гггг': "
    };
    /// Текст для просьбы ввода места.
    const string textAreaInput[3] = {
        "Введите роддом: ",
        "Введите район: ",
        "Введите город: "
    };
    
    const string textDeletInput[2] = {
        "Введите ФИО матери: ",
        "Введите дату рождения матери: "
    };
    
public:
    
    /// Вывод в консоль пункты меню
    void outMenu(const string* const text, int countPoint) const {
        outputArray(text, countPoint);
        cout << text[countPoint];
    }
    
    /// Вывод меню выбора места.
    void areaForInput(Area area) {
        cout << textAreaInput[area];
    }
    
    /// Вывод меню выбора даты.
    void dataFormatForInput(DataFormat format) {
        cout << textDataFormatInput[format];
    }
    
    /// Вывод текста для ввода удаления.
    void deletOutputFIO() {
        cout << textDeletInput[0];
    }
    void deletOutputData() {
        cout << textDeletInput[1] << endl;
        cout << textDataFormatInput[0];
    }
    
private:
    
    void outputArray(const string array[], int size) const {
        for (int i = 0; i < size; i++) { cout << array[i] << endl; }
    }
    
};


#endif /* Output_hpp */
