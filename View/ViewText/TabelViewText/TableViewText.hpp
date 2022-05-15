//
//  TableViewText.hpp
//  CourseworkInProgramming26
//
//  Created by Сергей Насыбуллин on 22.04.2022.
//

#ifndef TableViewText_hpp
#define TableViewText_hpp



class Table {
    
public:
    const static int column = 8;
    
    enum Align {
        Left,
        Middle
    };
    
    Align align[column] = {
        Middle,
        Middle,
        Left,
        Left,
        Middle,
        Middle,
        Middle,
        Middle
    };
    
private:
    float layout[column] = {
        0.04,
        0.12,
        0.15,
        0.27,
        0.12,
        0.07,
        0.07,
        0.07
    };
    
public:
    
    int getWidth(int column) {
        return (int)width*layout[column];
    }
    
    /// Ширина в символах
    int width = 100;
    
    char border[3] = {
        '-','|','+'
    };
    
};

#include "TableViewTextCell.hpp"

/// Отображения таблицы
class TableViewText: public ViewText, public Table {
private:
    
    string textTabel[2][column] = {
        {"N", "Date of bi-", "Region", "FIO", "Date of bi-", "Sex 1", "Sex 2", "Sex 3" },
        {"", "rth child", "", "mothers", "rth mothers", "chi.", "chi.", "chi."}
    };
    
    
public:
    
    /// Текст, который отображается над содержимым таблицы.
    void tableHeaderViewText (ostream &out) {
        line(out);
        lineHeader(out, textTabel[0]);
        lineHeader(out, textTabel[1]);
        line(out);
    }
    
    /// Текст, который отображается под содержимым таблицы.
    void tableFooterViewText (ostream &out) {
        line(out);
    }
    
    /// Строчка таблицы которая выводится
    void addCell (ostream &out, Birth birth) {
        TableViewTextCell cell = {out, birth};
    }
    
    
    
    void output(ostream &out) override {}
    
    
private:
    
    /// Вывод шапки
    void lineHeader(ostream &out, string text[column]) {
        for (int i=0; i<column; i++) {
            out << border[1] << ' ' << left << setw(getWidth(i)-1) << text[i];
        }
        out << border[1] << endl;
    }
    
    /// Вывод разделителя
    void line(ostream &out) {
        for (int i=0; i<column; i++) {
            out << border[1] << string(getWidth(i), border[0]);
        }
        out << border[1] << endl;
    }
    
};

#endif /* TableViewText_hpp */
