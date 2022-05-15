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


//using namespace std;


/// Пол ребенка
enum Sex {
    /// Мальчик
    m,
    /// Девочка
    g,
    /// Нет ребенка
    no
};


/// Класс преобразования для Sex
class SexCast {
public:
    
    /// Преобразует Sex в символ. Ассоциация для 'enum Sex'
    static string toString(Sex sex) {
        map<Sex, string> dict = {
            {m, "M"},
            {g, "G"},
            {no, "0"}
        };
        return dict[sex];
    }
    
    /// Преобразует Sex в символ. Ассоциация для 'enum Sex'
    static string toStringRus(Sex sex) {
        map<Sex, string> dict = {
            {m, "м"},
            {g, "ж"},
            {no, "0"}
        };
        return dict[sex];
    }
    
    /// Преобразует символ в Sex. Ассоциация для 'enum Sex'
    static Sex toSexEnum(string sex) {
        map<string, Sex> dict = {
            {"м", m},
            {"ж", g},
            {"0", no}
        };
        return dict[sex];
    }
    
    
    
    
};


/// Модель 3-х детей
class SexСhild {
        
private:
    
    /// Дети
    Sex child[3] = {no, no, no};
    /// Кол-во детей
    int count = 0;
    
public:
    
    SexСhild() {}
    
    // MARK:  Методы
    
    /// Добавляет новый элемент в конец
    void append(Sex newElement) { child[count++] = newElement; }
    
    /**
     * Провекра по признуку
     *
     * @param attribute  Признак по которому будет проверка
     * @param children Объект который проверяется
     */
    const static bool isAttribute(Attribute attribute, SexСhild children)  {
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
    
    
private:
    
    /// Проверка на один пол
    const bool attribute(Sex sex) const {
        bool flag = true;
        for (int i=0; i<count; i++)
            if (child[i] != no)
                flag = child[i] == sex && flag;
        return flag;
    }
    
    /// Проверка на многодетность
    const bool isMultiple() const {
        return count >= 2;
    }
    
    

    // MARK:  Перегрузки
public:
    
    const Sex operator [] (int index) const { return child[index]; }
    
    
    SexСhild& operator = (const SexСhild &second) {
        count = second.count;
        for (int i = 0; i < count; i++)
            child[i] = second.child[i];
        return *this;
    }
    
    
};

#endif /* Sex_hpp */
