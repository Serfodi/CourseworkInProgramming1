//
//  Output.hpp
//  CourseworkInProgramming26
//
//  Created by Сергей Насыбуллин on 26.03.2022.
//

/**
 * @file
 */

#ifndef Output_hpp
#define Output_hpp

#include <stdio.h>

#include <iostream>


#include "ChoiceMenu.hpp"
#include "TextFileDialogue.hpp"


/// Класс Output отвечает за вывод в текста консоль.
using namespace std;
class Output {
    
    TextFileDialogue text;
    
public:
    
    /// @brief Выбора обработки.
    ///
    /// 1. Просмотр данных за день или интервал.
    ///
    /// 2. Вывод гистограммы рождаемости по месяцам года и кривой  рождаемости за год.
    ///
    /// 3. Определение месяцев максимальной и минимальной рождаемости (birthrate).
    ///
    /// 4. Удаления.
    void processingOutput() {
        outputArray(text.textСP, 5);
        cout << text.textСP[5];
    }
    
    /// @brief Вывод меню выбора места.
    ///
    /// Вывод:
    ///
    ///     1. По роддому.
    ///
    ///     2. По району.
    ///
    ///     3. По городу.
    ///
    void areaOutput() {
        outputArray(text.textArea, 4);
        cout << text.textArea[4];
    }
    
    /// @brief Вывод меню выбора рождаемости(фильтрации).
    ///
    /// Вывод:
    ///
    ///     1. Общей.
    ///
    ///     2. Мальчиков.
    ///
    ///     3. Девочек.
    ///
    void birthrateOutput() {
        outputArray(text.textBirthrate, 5);
        cout << text.textBirthrate[5];
    }
    
    /// @brief Вывод меню выбора форматы даты.
    ///
    /// Вывод:
    ///
    ///     1. День.
    ///
    ///     2. Интервал.
    void dataFormatOutput() {
        outputArray(text.textDataFormat, 3);
        cout << text.textDataFormat[3];
    }
    
    /// @brief вывод текста для ввода удаления.
    ///
    ///     1. фио
    ///
    ///     2. дата рождения
    void deletOutputFIO() {
        cout << text.textDeletInput[0];
    }
    void deletOutputData() {
        cout << text.textDeletInput[1] << endl;
        cout << text.textDataFormatInput[0];
    }
    
    /// @brief Вывод меню выбора места.
    ///
    void menuInput(Area area) {
        cout << text.textAreaInput[area];
    }
    
    /// @brief Вывод меню выбора места.
    ///
    void dataFormatInput(DataFormat format) {
        cout << text.textDataFormatInput[format];
    }
    
    
    
    
    // MARK: - Supporting methods
    
private:
    void outputArray(const string array[], int size) {
        for (int i = 0; i < size; i++) { cout << array[i] << endl; }
    }
    
    
};


#endif /* Output_hpp */
