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
    
    /// Ширина в символах
    int width = 100;
    
    
    string textTabel[2][8] = {
        {"N", "Date of bi-", "Region", "FIO", "Date of bi-", "Sex 1", "Sex 2", "Sex 3" },
        {"", "rth child", "", "mothers", "rth mothers", "chi.", "chi.", "chi."}
    };
    
    
public:
    
    
    Table(int width) {
        this -> width = width;
    }
    
    
    /// Текст, который отображается над содержимым таблицы.
    void tableHeaderViewText (ostream &out) {
        
        TableViewTextCell cell = {textTabel[0]};
        out << cell.description() << endl;
        
        cell = {textTabel[1]};
        out << cell.description() << endl;
        
        cell = {'-'};
        out << cell.description() << endl;
    }
    
    /// Текст, который отображается под содержимым таблицы.
    void tableFooterViewText (ostream &out) {
        
    }
    
    /// Строчка таблицы которая выводится
    void addCell(ostream &out, Birth birth) {
        TableViewTextCell cell = {birth, width};
        out << cell.description() << endl;
    }
    
    
    
    void output(ostream &out) override {}
    
    
private:
    
    
    void widthSpaceLeft(ostream &out, string text, int width) {
        out << left << setw(width) << text;
    }
    
    
    
    
public:
    
    ~Table() {}
    
};

#endif /* TableViewText_hpp */
