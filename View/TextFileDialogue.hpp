//
//  TextFileDialogue.hpp
//  CourseworkInProgramming26
//
//  Created by Сергей Насыбуллин on 26.03.2022.
//

#ifndef TextFileDialogue_hpp
#define TextFileDialogue_hpp

#include <stdio.h>

#include <iostream>
#include <string>

/**
 Структура TextFileDialogue содержит текста для работы Output.
 */
using namespace std;
struct TextFileDialogue {
public:
    const string textСP[4] = {
        "1. Просмотр данных по времени.",
        "2. Вывод гистограммы рождаемости по месяцам года и кривой  рождаемости за год.",
        "3. Определение месяцев максимальной и минимальной рождаемости.",
        "4. Удаление записей о родах."
    };
    const string textArea[3] = {
        "1. По роддому.",
        "2. По району.",
        "3. По городу."
    };
    const string textAreaInput[3] = {
        "роддом",
        "район",
        "город"
    };
    const string textDataFormat[2] = {
        "1. День.",
        "2. Интервал."
    };
    const string textDataFormatInput[2] = {
        "день. В формате: дд.мм.гггг",
        "интервал. В формате: дд.мм.гггг - дд.мм.гггг"
    };
    
    const string textBirthrate[4] = {
        "1. Общей рождаемости",
        "2. Только мальчиков",
        "3. Только девочек",
        "4. Многодетных родов ( более одного ребенка)"
    };
    
    const string textMenu[3] = {
        "Выберите:",
        "Введите число:",
        "Введите"
    };
    
    const string textDelet[1] = {
        "Введите ФИО и Дату рождения:"
    };
    
    const string textError[1] = {
        "Некорректный ввод."
    };
    
};


#endif /* TextFileDialogue_hpp */
