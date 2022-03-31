//
//  Output.hpp
//  CourseworkInProgramming26
//
//  Created by Сергей Насыбуллин on 26.03.2022.
//

/**
 * @file
 * Используется:
 *      - main
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
    
    // вывод текста
    void processingOutput() {
        cout << text.textMenu[0] << endl;
        outputArray(text.textСP, 4);
        cout << text.textMenu[1] << " ";
    }
    void areaOutput() {
        cout << text.textMenu[0] << endl;
        outputArray(text.textArea, 3);
        cout << text.textMenu[1] << " ";
    }
    void birthrateOutput() {
        cout << text.textMenu[0] << endl;
        outputArray(text.textBirthrate, 4);
        cout << text.textMenu[1] << " ";
    }
    void dataFormatOutput() {
        cout << text.textMenu[0] << endl;
        outputArray(text.textDataFormat, 2);
        cout << text.textMenu[1] << " ";
    }
    void deletOutput() {
        cout << text.textDelet[0] << endl;
    }
    
    // ввод текста
    void menuInput(Area area) {
        cout << text.textMenu[2] << " " << text.textAreaInput[area] << ": ";
    }
    void dataFormatInput(DataFormat format) {
        cout << text.textMenu[2] << " " << text.textDataFormatInput[format] << ": ";
    }
    
    
    
    // MARK: - Supporting methods
    
private:
    void outputArray(const string array[], int size) {
        for (int i = 0; i < size; i++) { cout << array[i] << endl; }
    }
    
    
};


#endif /* Output_hpp */
