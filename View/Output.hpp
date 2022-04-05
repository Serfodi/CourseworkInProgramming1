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

#include "TextFileMenu.hpp"

// supporting
#include "ChoiceMenu.hpp"


using namespace std;

/// Класс Output отвечает за вывод в консоль.
class Output {
    
    TextFileMenu text;
    
public:
    
//    MARK: ChoiceProcessing
    
    /// Выбора обработки.
    void processingOutput() {
        outputArray(text.textСP, 5);
        cout << text.textСP[5];
    }
    
//    MARK: Area
    
    /// Вывод меню выбора места.
    void areaOutput() {
        outputArray(text.textArea, 4);
        cout << text.textArea[4];
    }
    /// Вывод меню выбора места.
    void menuInput(Area area) {
        cout << text.textAreaInput[area];
    }
    
//    MARK: Birthrate
    
    /// Вывод меню выбора рождаемости(фильтрации).
    void birthrateOutput() {
        outputArray(text.textBirthrate, 5);
        cout << text.textBirthrate[5];
    }
    
//    MARK: DataFormat
    
    /// Вывод меню выбора форматы даты.
    void dataFormatOutput() {
        outputArray(text.textDataFormat, 3);
        cout << text.textDataFormat[3];
    }
    /// Вывод меню выбора даты.
    void dataFormatInput(DataFormat format) {
        cout << text.textDataFormatInput[format];
    }
    
//    MARK: Delete
    
    /// Вывод текста для ввода удаления.
    void deletOutputFIO() {
        cout << text.textDeletInput[0];
    }
    void deletOutputData() {
        cout << text.textDeletInput[1] << endl;
        cout << text.textDataFormatInput[0];
    }
    
//    MARK: Min and Max - 3
    
    void mouth(int mouthMax, int mouthMin, int numberMax, int numberMin) {
        cout << "Максимальное кол-во рождений: " << text.textData[mouthMax-1] << endl
        << "Что составило: " << numberMax << endl;
        cout << "Минимальное кол-во рождений: " << text.textData[mouthMin-1] << endl
        << "Что составило: " << numberMin << endl;
    }
    
    void mouthEqule(int number) {
        cout << "В каждом месецы было одинаковое кол-во рождений." << endl
        << "Что составило: " << number;
    }
    
    
//    MARK: ClassError
    
    void errorOpenFile() { cout << text.textErrorFileOpen[1] << endl; }
    
    void errorInputText() { cout << text.textErrorInput[0] << endl; }
    
    
    
    // MARK: - Supporting methods
    
private:
    void outputArray(const string array[], int size) {
        for (int i = 0; i < size; i++) { cout << array[i] << endl; }
    }
    
    
};


#endif /* Output_hpp */
