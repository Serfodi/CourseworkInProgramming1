//
//  ExtensionString.hpp
//  CourseworkInProgramming26
//
//  Created by Сергей Насыбуллин on 31.03.2022.
//

#ifndef ExtensionString_hpp
#define ExtensionString_hpp

#include <stdio.h>

#include <string>

using namespace std;

/// Расширение для string
class ExtensionString {
public:
    
    
    /**
     * @brief Возвращает массив, содержащий подстроки из получателя, которые были разделены на данный разделитель.
     *
     * @warning Память на массив выделяется внутри.
     *
     * @return string[ size ]
     */
    static string* componentsSeparatedBy(string text, char separatedBy, int count) {
        string *components = new string[count];
        string words;
        int size = 0;
        for (int i = 0; i < text.size(); i++) {
            if (text[i] != separatedBy) {
                words += text[i];
            } else {
                components[size] = words;
                size += 1;
                words = "";
            }
        }
        components[size] = words;
        return components;
    }
    
};

#endif /* ExtensionString_hpp */
