//
//  ExtensionString.hpp
//  CourseworkInProgramming26
//
//  Created by Сергей Насыбуллин on 31.03.2022.
//

/**
 * @file Расширения для string
 */

#ifndef ExtensionString_hpp
#define ExtensionString_hpp


/// Расширение string
class ExtensionString {
public:
    
    /**
     * @brief Возвращает массив, содержащий подстроки из получателя, которые были разделены на данный разделитель.
     *
     * @param text Строка string разделенная separated
     * @param separatedBy Символ с char разделитель по которому будет разбиваться строка
     *
     * @return Вектор String
     */
    static vector<string> componentsSeparatedBy(string text, char separatedBy) {
        vector<string> components;
        string words;
        
        for (int i = 0; i < text.size(); i++) {
            if (text[i] != separatedBy) {
                words += text[i];
            } else {
                components.push_back(words);
                words = "";
            }
        }
        
        components.push_back(words);
        return components;
    }
    
    /**
     * @brief Возвращает строчку, в формате 0…countNumber
     *
     * @param number число
     * @param count кол-во нулей
     */
    static string leading (int number, int count, char leadingChar = '0') {
        string text = to_string(number);
        text = string(count-text.size(), leadingChar) + text;
        return text;
    }
    
};

#endif /* ExtensionString_hpp */
