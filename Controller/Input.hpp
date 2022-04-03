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

#include "Birth.hpp"
#include "ChoiceMenu.hpp"
#include "ClassError.hpp"
#include "ExtensionString.hpp"
#include "Date.hpp"


using namespace std;

// Содержит логику обработки и формирования данных.
/**
 * @brief Отвечает за ввод данных их обработку из консоли или из файла.
 */
class Input {
    
    // MARK:  - input
public:
    
    // Числовые
    
    /// Ввод с клавиатуры  целого числа int
    int number() {
        string textNumber = text();
        int number;
//        cin >> number;
        number = stoi(textNumber);
        return number;
    }
    
    // Символьные
    
    /// Ввод с клавиатуры текста string
    string text() {
        string text;
//        clearInputEnter();
        getline(cin, text);
        return text;
    }
    
    
    // Дата
    
    /**
     * @brief Приводит строчку к Data
     * @param dataText  Строка в формате "дд.мм.гггг" или "дд.мм.гггг - дд.мм.гггг"
     * @param format Формат преобразования к одной дате или двум
     * @return Массив из одной или двух дат
     * @throws ErrorInput::incorrectData
     */
    Data *dataCast (string dataText, DataFormat format) {
        if (dataText == "") { throw ErrorInput::incorrectData; }
        Data *data = new Data[format+1]; // Вопрос на засыпку: где выделать память?
        switch (format) {
            case day:
                data[0] = Data(dataText);
                break;
            case interval:
                string *components = new string[format + 1];
                components = ExtensionString::componentsSeparatedBy(dataText, '-', format + 1);
                for (int i=0; i < format + 1 ; i++) {
                    data[i] = Data(*(components + i));
                }
                delete [] components;
                break;
        }
        return data;
    }
    
    
    // // MARK:  Вспомогательные private.
//private:
    
    /// Удаляет из буфера "Enter"
    void clearInputEnter() {
        cin.get();
        
//        char non;
//        (cin >> non).ignore();
    }
    
    
    
    // MARK: - cast to enum ChoiceMenu
public:
    
    template <typename T>
    T cast(int number) {
        return static_cast<T>(number-1);
    }
    
    
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
    
    
    
};


#endif /* Input_hpp */
