//
//  Sex.hpp
//  CourseworkInProgramming26
//
//  Created by Сергей Насыбуллин on 31.03.2022.
//

/**
 * @file Описания модели Sex и методы обработки.
 */

#ifndef Sex_hpp
#define Sex_hpp

#include <stdio.h>
#include <string>

// Supporting
#include "ClassError.hpp"


using namespace std;


/// Ребенок
enum SexСhild {
    /// Мальчик
    m,
    /// Девочка
    g,
    /// Нет ребенка
    no
};


/// Модель пола ребенка
class Sex {
public:
    
    /// Содержит буквы для ассоциации с полом ребенка
    ///
    /// @see SexСhild
    static string sexText[3];
    
    /**
     * @brief Приводит букву к перечислению Sex
     * @param text  Буква
     * @warning Перед использованием установите параметр "sexText[3]"
     */
    static SexСhild sexCast(string text) {
        int index = -1;
        for (int i=0; i<3; i++) {
            if (text == *(sexText + i)) {
                index = i;
                break;
            }
        }
        return static_cast<SexСhild>(index);
    }
    
    
    
};

#endif /* Sex_hpp */
