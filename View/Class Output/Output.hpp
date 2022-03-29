//
//  Output.hpp
//  CourseworkInProgramming26
//
//  Created by Сергей Насыбуллин on 26.03.2022.
//

#ifndef Output_hpp
#define Output_hpp

#include <stdio.h>

#include <iostream>

#include "ChoiceMenu.hpp"
#include "TextFileDialogue.hpp"

/**
 Класс Output отвечает за вывод в текста консоль.
 */
using namespace std;
class Output {
    
private:
    
    TextFileDialogue text;
    
public:
    // вывод текста
    void processing() {
        cout << text.textMenu[0] << endl;
        outputArray(text.textСP, 4);
        cout << text.textMenu[1] << " ";
    }
    void area() {
        cout << text.textMenu[0] << endl;
        outputArray(text.textArea, 3);
        cout << text.textMenu[1] << " ";
    }
    void birthrate() {
        cout << text.textMenu[0] << endl;
        outputArray(text.textBirthrate, 4);
        cout << text.textMenu[1] << " ";
    }
    void dataFormat() {
        cout << text.textMenu[0] << endl;
        outputArray(text.textDataFormat, 2);
        cout << text.textMenu[1] << " ";
    }
    
    void menuInput(Area area) {
        cout << text.textMenu[2] << " " << text.textAreaInput[area] << ": ";
    }
    
    void dataFormatInput(DataFormat format) {
        cout << text.textMenu[2] << " " << text.textDataFormatInput[format] << ": ";
    }
    
    void delet() {
        cout << text.textDelet[0] << endl;
    }
    
    
    // MARK: - Supporting methods
    
private:
    void outputArray(const string array[], int size) {
        for (int i = 0; i < size; i++) { cout << array[i] << endl; }
    }
    
    
};


#endif /* Output_hpp */
