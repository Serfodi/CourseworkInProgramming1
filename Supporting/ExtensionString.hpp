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


#include <string>


using namespace std;


/// Расширение string
class ExtensionString {
public:
    
    /**
     * @brief Возвращает массив, содержащий подстроки из получателя, которые были разделены на данный разделитель.
     *
     * @param text Строка string разделенная separated
     * @param separatedBy Символ с char разделитель по которому будет разбиваться строка
     * @param count Число подстрок int
     *
     * @return Динамический массив String размером 'count'
     *
     * @relatesalso std::string
     *
     * @warning Кол-во подстрок 'count' должно совпадать с кол-во разделителей 'separatedBy' в тексте 'text'.
     *
     * Память на массив выделяется динамически внутри.
     */
    static string* componentsSeparatedBy(string text, char separatedBy, int count) {
//        int count = countWords(text, separatedBy);
        // Как будет лучше? Внутри память выделать или снаружи?
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
    
    /// Считает кол-во слов
    ///
    /// Используется совместно с componentsSeparatedBy
    static int countWords(string text, char separatedBy) {
        int count = 1;
        for (int i=0; i<text.length(); i++)
            if (text[i] == separatedBy)
                count += 1;
        return count;
    }
    
    
};

#endif /* ExtensionString_hpp */
