//
//  Input.hpp
//  CourseworkInProgramming26
//
//  Created by Сергей Насыбуллин on 26.03.2022.
//

#ifndef Input_hpp
#define Input_hpp

#include <stdio.h>

#include <iostream>
#include <string>

#include "ModelBirth.hpp"
#include "ChoiceMenu.hpp"
#include "ClassError.hpp"
#include "Date.hpp"


/**
 Класс Input отвечает за ввод данных их обработку из консоли или из файла.
 */
using namespace std;
class Input {
private:
    char sep = '|';
public:
    
    // MARK: -  Методы
    
    
    /**
     Создает модель данных Birth на основании строчки.
     Типа: | Номер роддома |  Дата рожд ребенка | Район | ФИО |  Дата  рожд. матери |  Пол 1реб. | Пол 2реб. | Пол 3реб. |
     */
    Birth createBirth(string withText) {
        Birth birth;
        string *components = componentsSeparatedBy(withText, sep, 8);
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
    
    /**
     Разбивает строчку на компоненты по разделителю.
     return string[]
     */
    string* componentsSeparatedBy(string text, char separatedBy, int size) {
        string *components = new string[size];
        int count = 0;
        string words;
        
        for (int i = 0; i < text.size(); i++) {
            
            if (text[i] != separatedBy) {
                words += text[i];
            } else {
                components[count] = words;
                count += 1;
                words = "";
            }
        }
        components[count] = words;
        return components;
    }
    
    // MARK:  input data
    
    // Числовые
    
    int number() {
        int number;
        cin >> number;
        return number;
    }
    
    
    // MARK:  cast to enum ChoiceMenu
    
    ChoiceProcessing choiceProcessingCast(int number) {
        if (number > 4 || number < 1) { throw ErrorInput::outOfIndex; }
        return static_cast<ChoiceProcessing>(number-1);
    }
    Area areaCast(int number) {
        if (number > 3 || number < 1) { throw ErrorInput::outOfIndex; }
        return static_cast<Area>(number-1);
    }
    DataFormat dataFormatCast(int number) {
        if (number > 2 || number < 1) { throw ErrorInput::outOfIndex; }
        return static_cast<DataFormat>(number-1);
    }
    Birthrate birthrateCast(int number) {
        if (number > 4 || number < 1) { throw ErrorInput::outOfIndex; }
        return static_cast<Birthrate>(number-1);
    }
    
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
