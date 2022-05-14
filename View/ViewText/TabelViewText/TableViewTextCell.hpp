//
//  TableViewTextCell.hpp
//  CourseworkInProgramming26
//
//  Created by Сергей Насыбуллин on 02.05.2022.
//

#ifndef TabelViewTextCell_hpp
#define TabelViewTextCell_hpp

struct TableViewTextCell: public Table {
public:
    
    TableViewTextCell(ostream &out, Birth birth) {
        vector<string> description = birth.getDescription();
        for (int i=0; i<description.size(); i++) {
            out << border[1] << left << setw(getWidth(i)) << (widthSpace(description[i].size(), i, align[i]) + description[i]);
        }
        out << border[1]  << endl;
    }
    
private:
    
    /// Возвращает количество  - смещение влево первого символа строки
    string widthSpace(long int sizeText, int column, Align align) {
        int widthLayout = getWidth(column);
        
        if (sizeText >= widthLayout) return "";
        if (align == Left) return " ";
        
        long int middle = (widthLayout - sizeText) / 2;
        return string(middle, ' ');
    }
    
};



#endif /* TabelViewTextCell_hpp */
