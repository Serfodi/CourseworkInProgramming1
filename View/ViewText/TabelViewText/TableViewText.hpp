//
//  TableViewText.hpp
//  CourseworkInProgramming26
//
//  Created by Сергей Насыбуллин on 22.04.2022.
//

#ifndef TableViewText_hpp
#define TableViewText_hpp


#include "TableViewTextCell.hpp"


/// Отображения меню
class Table: public ViewText {
private:
    /// Разделитель в таблице
    static const char sep = '|';
    
    bool ifTabel = false;
    
    /// Ширина в символах
    const int width = 100;
    
    
    
    string textTabel[2][8] = {
        {"N", "Date of bi-", "Region", "FIO", "Date of bi-", "Sex 1", "Sex 2", "Sex 3" },
        {"", "rth child", "", "mothers", "rth mothers", "chi.", "chi.", "chi."}
    };
    
    
    
public:
    
    Table() {}
    
    
private:
    
    /// Печать шапки таблицы
    void printTable(ostream &out) {
        if (ifTabel) return;
        TableViewTextCell cell = {textTabel[0]};
        out << cell.description() << endl;
        cell = {textTabel[1]};
        out << cell.description() << endl;
        cell = {'-'};
        out << cell.description() << endl;
        ifTabel = true;
    }
    
    
public:
    
    /// Печать строчки таблицы
    void addToTable(ostream &out, Birth birth) {
        printTable(out);
        TableViewTextCell cell = {birth, width};
        out << cell.description() << endl;
    }
    
    
    
    
    
    void output(ostream &out) override {}
    
    
    
    ~Table() {}
    
};

#endif /* TableViewText_hpp */
