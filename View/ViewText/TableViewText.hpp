//
//  TableViewText.hpp
//  CourseworkInProgramming26
//
//  Created by Сергей Насыбуллин on 22.04.2022.
//

#ifndef TableViewText_hpp
#define TableViewText_hpp


/// Отображения меню
class Table: public ViewText {
private:
    /// Разделитель в таблице
    const char sep = '|';
    
    int column = 0;
    
    string textTabel[2][8] = {
        {"Номер", "Дата рожд", "Район", "ФИО", "Дата рожд", "Пол", "Пол", "Пол" },
        {"роддома", "ребенка", "", "матери", "матери", "1 реб.", "2 реб.", "3 реб."}
    };
    
    
public:
    
    Table() {}
    
private:
    /// Печать шапки таблицы
    void printTable(ostream &out) {
        out << "Таблица" << endl;
    }
    
public:
    /// Печать строчки таблицы
    void addToTable(ostream &out, Birth birth) {
        if (column == 0 ) printTable(out);
        
        column += 1;
        
        out << sep
        << setw(6) << birth.number << setw(2) << sep
        << setw(10) << birth.dOB.description() << setw(2) << sep
        << setw(20) << birth.region << setw(2) << sep
        << setw(7) << birth.fIO << setw(2) << sep
        << setw(10) << birth.dOBMother.description() << setw(2) << sep
        << endl;
    }
    
    
    void output(ostream &out) override {}
    
    
    ~Table() {}
    
};

#endif /* TableViewText_hpp */
