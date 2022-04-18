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

#include <string>

using namespace std;


/// Пол ребенка
enum Sex {
    /// Мальчик
    m,
    /// Девочка
    g,
    /// Нет ребенка
    no
};


/// Модель пола ребенка
class SexСhild {
private:
    
    string sexText[3] = {"м", "ж", "0"}; // вообще нужно его внешне определять по хорошему
    
    /// Дети
    Sex child[3] = {no, no, no};
    /// Кол-во детей
    int count = 0;
    
    
public:
    
    
    SexСhild() {}
    
    
    
    // MARK: - Методы
    
    
    /// Добавляет новый элемент в конец
    void append(Sex newElement) { child[count++] = newElement; }
    
    
    /**
     * @brief Приводит букву к перечислению Sex
     * @param text  Буква
     * @warning Перед использованием установите параметр "sexText[3]"
     */
    Sex sexCast(string text) {
        int index = -1;
        for (int i=0; i<3; i++) {
            if (text == *(sexText + i)) {
                index = i;
                break;
            }
        }
        return static_cast<Sex>(index);
    }
    
    
    /// Проверка на один пол
    bool attribute(Sex sex) {
        bool flag = false;
        for (int i=0; i<count; i++) flag = child[i] == sex && flag;
        return flag;
    }
    
    
    /// Проверка на многодетность
    bool isMultiple() {
        return count >= 2;
    }
    
//    dataModel.attribute, birth.children
    
    
    
    
    
    // MARK: - Перегрузки
    
    
    Sex operator [] (int index) { return child[index]; }
    
    
    SexСhild operator = (SexСhild second) {
        for (int i = 0; i < count; i++)
            child[i] = second.child[i];
        return *this;
    }
    
    
};

#endif /* Sex_hpp */
