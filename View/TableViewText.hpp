//
//  TableViewText.hpp
//  CourseworkInProgramming26
//
//  Created by Сергей Насыбуллин on 22.04.2022.
//

#ifndef TableViewText_hpp
#define TableViewText_hpp

#include <stdio.h>

#include <fstream>
#include "string"
#include "Birth.hpp"


/// Отображения меню
class Table {
private:
    const char sep = '|';
    
    string textTabel[2][8] = {
        {"Номер", "Дата рожд", "Район", "ФИО", "Дата рожд", "Пол", "Пол", "Пол" },
        {"роддома", "ребенка", "", "матери", "матери", "1 реб.", "2 реб.", "3 реб."}
    };
    
public:
    
    /// Печать шапки таблицы
    void printTable(ostream &out);
    
    /// Печать строчки таблицы
    void addToTable(ostream &out, Birth birth);
    
    
};

#endif /* TableViewText_hpp */
