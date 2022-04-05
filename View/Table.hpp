//
//  Table.hpp
//  CourseworkInProgramming26
//
//  Created by Сергей Насыбуллин on 31.03.2022.
//

#ifndef Table_hpp
#define Table_hpp

#include <stdio.h>

#include <iostream>
#include <iomanip>

// Model
#include "Birth.hpp"


using namespace std;

/// Отображения меню
class Table {
private:
    char sep = '|';
    
    string textTabel[2][8] = {
        {"Номер", "Дата рожд", "Район", "ФИО", "Дата рожд", "Пол", "Пол", "Пол" },
        {"роддома", "ребенка", "", "матери", "матери", "1 реб.", "2 реб.", "3 реб."}
    };
    
public:
    
    /// Печать шапки таблицы
    void printTable() {
        
//        cout <<
//        sep << setw(11) << text[0][0] << setw(2) <<
//        sep << setw(18) << text[0][1] << setw(2) <<
//        sep << setw(11) << text[0][2] << setw(10) <<
//        sep << setw(7) << text[0][3] << setw(2) <<
//        sep << setw(18) << text[0][4] << setw(2) <<
//        sep << setw(7) << text[0][5] << setw(2) <<
//        sep << setw(7) << text[0][6] << setw(2) <<
//        sep << setw(7) << text[0][7] << setw(2) <<
//        sep << endl;
        
    }
    
    /// Печать строчки таблицы
    void addToTable(Birth birth) {
        cout << sep
        << setw(6) << birth.number << setw(2) << sep
        << setw(10) << birth.dOB.description() << setw(2) << sep
        << setw(20) << birth.region << setw(2) << sep
        << setw(7) << birth.fIO << setw(2) << sep
        << setw(10) << birth.dOBMother.description() << setw(2) << sep
        << setw(4) << Sex::sexText[birth.children[0]] << setw(2) << sep
        << setw(4) << Sex::sexText[birth.children[1]] << setw(2) << sep
        << setw(4) << Sex::sexText[birth.children[2]] << setw(2) << sep
        << endl;
    }
    
};

#endif /* Menu_hpp */
