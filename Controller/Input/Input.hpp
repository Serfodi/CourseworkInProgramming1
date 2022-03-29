//
//  Input.hpp
//  CourseworkInProgramming26
//
//  Created by Сергей Насыбуллин on 26.03.2022.
//

/**
 * @file
 * Используется:
 *      - main
 */

#ifndef Input_hpp
#define Input_hpp

#include <stdio.h>

#include <iostream>
#include <string>

#include "ModelBirth.hpp"
#include "ChoiceMenu.hpp"
#include "ClassError.hpp"
//#include "FileProces.hpp"
#include "Date.hpp"


using namespace std;

/**
 * @brief Отвечает за ввод данных их обработку из консоли или из файла.
 */
// Содержит логику обработки и формирования данных.
class Input {
    
private:
    /// @todo Перенести в класс  file
    static const char sep = '|'; // ХЗ почему но я не могу использовать объявления файла больше одного раза. Ошибка дублирования.
    const string textSex[3] = {"м", "ж", "0"};
    
    
    // MARK: - Методы
public:
    
    /**
     * @brief Создает модель данных Birth из строчки определенного типа
     * @return Экземпляр  структуры Birth
     *
     *
     * @todo Сделать рефакторинг
     *
     */
    // Типа: | Номер роддома |  Дата рожд ребенка | Район | ФИО |  Дата  рожд. матери |  Пол 1 реб. | Пол 2 реб. | Пол 3 реб. |
    Birth createBirth(string withText) {
        Birth birth;
        string *components = componentsSeparatedBy( withText, sep, 8);
        int number = stoi(*(components + 0));
        Data dOB = Data(componentsSeparatedBy(*(components + 1), Data::sep, 3));
        string region = (*(components + 2));
        string fIO = *(components + 3);
        Data dOBMother = Data(componentsSeparatedBy(*(components + 4), Data::sep, 3));
        Sex children[3] = {
            sexCast(*(components + 5)),
            sexCast(*(components + 6)),
            sexCast(*(components + 7))
        };
        birth = Birth(number, dOB, region, fIO, dOBMother, children);
        delete [] components;
        return birth;
    }

    
    // Вспомогательные методы private.
private:
    
    /**
     * @brief Возвращает массив, содержащий подстроки из получателя, которые были разделены на данный разделитель.
     * @return string[ size ]
     */
    string* componentsSeparatedBy(string text, char separatedBy, int size, bool spase = false) {
        string *components = new string[size];
        int count = 0;
        string words;
        for (int i = 0; i < text.size(); i++) {
            if (text[i] != separatedBy) {
                if (text[i] != ' ' || !spase) { words += text[i]; }
            } else {
                components[count] = words;
                count += 1;
                words = "";
            }
        }
        components[count] = words;
        return components;
    }
    
    
    
    // MARK:  input
public:
    
    // Числовые
    
    /// Ввод с клавиатуры  целого числа int
    int number() {
        int number;
        cin >> number;
        return number;
    }
    
    // Символьные
    
    /// Ввод с клавиатуры текста string
    string text() {
        string text;
        getline(cin, text);
        clearInputEnter();
        return text;
    }
    
    // Дата
    
    /**
     * @brief Приводит строчку к Data
     * @param dataText  Строка в формате дд.мм.гггг или дд.мм.гггг - дд.мм.гггг
     * @param format Формат преобразования к одной дате или двум
     * @return Массив из одной или двух дат
     * @throws ErrorInput::incorrectData
     */
    Data *data (string dataText, DataFormat format) {
        Data *data = new Data[format+1];
        
        string *components = componentsSeparatedBy(dataText, '-', format+1, true);
        
        for (int i = 0; i < (format+1); i++) {
            
            if (*(components + i) == "") { throw ErrorInput::incorrectData; }
            
            data[i] = Data( componentsSeparatedBy(*(components + i), Data::sep, 3) );
        }
        
        delete [] components;
        return data;
    }

    
    // Вспомогательные методы private.
private:
    
    /// Удаляет из буфера "Enter"
    void clearInputEnter() {
        char non;
        (cin >> non).ignore();
    }
    
    
    
    // MARK:  cast to enum ChoiceMenu
public:
    
    /**
     * @brief Приводит число к перечислению ChoiceProcessing
     * @param number  Целое число от 1 до 4
     * @throws ErrorInput::outOfIndex
     */
    ChoiceProcessing choiceProcessingCast(int number) {
        if (number > 4 || number < 1) { throw ErrorInput::outOfIndex; }
        return static_cast<ChoiceProcessing>(number-1);
    }
    /**
     * @brief Приводит число к перечислению Area
     * @param number  Целое число от 1 до 3
     * @throws ErrorInput::outOfIndex
     */
    Area areaCast(int number) {
        if (number > 3 || number < 1) { throw ErrorInput::outOfIndex; }
        return static_cast<Area>(number-1);
    }
    /**
     * @brief Приводит число к перечислению DataFormat
     * @param number  Целое число от 1 до 2
     * @throws ErrorInput::outOfIndex
     */
    DataFormat dataFormatCast(int number) {
        if (number > 2 || number < 1) { throw ErrorInput::outOfIndex; }
        return static_cast<DataFormat>(number-1);
    }
    /**
     * @brief Приводит число к перечислению Birthrate
     * @param number  Целое число от 1 до 4
     * @throws ErrorInput::outOfIndex
     */
    Birthrate birthrateCast(int number) {
        if (number > 4 || number < 1) { throw ErrorInput::outOfIndex; }
        return static_cast<Birthrate>(number-1);
    }
    
    /**
     * @brief Приводит букву к перечислению Sex
     * @param text  Буква: "м", "ж", "0"
     * @throws ErrorInput::incorrectData
     */
    Sex sexCast(string text) {
        int index = -1;
        if (text == "м") { index = 0; }
        if (text == "ж") { index = 1; }
        if (text == "0") { index = 2; }
        if (index == -1) { throw ErrorInput::incorrectData; }
        return static_cast<Sex>(index);
    }
    
    
};


#endif /* Input_hpp */
