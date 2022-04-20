//
//  TextFileMenu.hpp
//  CourseworkInProgramming26
//
//  Created by Сергей Насыбуллин on 26.03.2022.
//

#ifndef TextFileDialogue_hpp
#define TextFileDialogue_hpp

#include <stdio.h>

#include <string>

using namespace std;


/// Структура TextFileDialogue содержит текста
struct TextFileMenu {
public:
    
    
    
    string textData[12] = {
        "Январь", "Февраль", "Март", "Апрель", "Май", "Июнь", "Июль", "Август", "Сентябрь", "Октяборь", "Нояборь", "Декабарь"
    };
    
    
    // MARK: - Text error
    
    const string textErrorInput[1] = {
        "Некорректный ввод."
    };
    
    const string textErrorFileOpen[1] = {
        "Файл ненайден."
    };
    
};


#endif /* TextFileDialogue_hpp */
