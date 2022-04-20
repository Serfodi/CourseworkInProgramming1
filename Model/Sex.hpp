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



/// Модель 3-х детей
class SexСhild {
private:
    
    /// Дети
    Sex child[3] = {no, no, no};
    /// Кол-во детей
    int count;
    
public:
    
    SexСhild() { count = 0; }
    
    
    // MARK:  Методы
    
    
    /// Добавляет новый элемент в конец
    void append(Sex newElement) { child[count++] = newElement; }
    
    
    /**
     * Приводит букву к перечислению Sex
     *
     * @param text  Буква
     * @param sexChar Массив обозначений пола
     */
    const static Sex sexCast(string text, const string sexChar[3]) {
        int index = -1;
        for (int i=0; i<3; i++) {
            if (text == sexChar[i] ) {
                index = i;
                break;
            }
        }
        return static_cast<Sex>(index);
    }
    
    
    /**
     * Провекра по признуку
     *
     * @param attribute  Признак по которому будет проверка
     * @param children Объект который проверяется
     */
    const static bool isAttribute(Attribute attribute, SexСhild children) {
        switch (attribute) {
            case general:
                return true;
            case boys:
                return children.attribute(m);
            case girls:
                return children.attribute(g);
            case multiple:
                return children.isMultiple();
        }
    }
    
    
    /// Проверка на один пол
    const bool attribute(Sex sex) const {
        bool flag = false;
        for (int i=0; i<count; i++) flag = child[i] == sex && flag;
        return flag;
    }
    
    /// Проверка на многодетность
    const bool isMultiple() const {
        return count >= 2;
    }
    
    
    
    // MARK:  Перегрузки
    
    
    const Sex operator [] (int index) const { return child[index]; }
    
    SexСhild operator = (SexСhild second) {
        for (int i = 0; i < count; i++)
            child[i] = second.child[i];
        return *this;
    }
    
};

#endif /* Sex_hpp */
