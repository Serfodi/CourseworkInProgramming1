//
//  TableViewTextCell.hpp
//  CourseworkInProgramming26
//
//  Created by Сергей Насыбуллин on 02.05.2022.
//

#ifndef TabelViewTextCell_hpp
#define TabelViewTextCell_hpp

enum Align {
    leftT,
    middleT
};


struct TableViewTextCell {
private:
    
    string cell;
    
public:
    
    TableViewTextCell(Birth birth,int width) {
        cell += "|";
        cell += widthSpase(to_string(birth.number), 4) + "|";
        cell += widthSpase(birth.dOB.description(), 12, middleT) + "|";
        cell += widthSpase(birth.region, 15) + "|";
        cell += widthSpase(birth.fIO, 27) + "|";
        cell += widthSpase(birth.dOBMother.description(), 12, middleT) + "|";
        for (int i=0; i<3; i++) {
            cell += widthSpase(SexСhild::sexCast(birth.children[i]), 7, middleT) + "|";
        }
    }
    
    TableViewTextCell(string s[8]) {
        cell += "|";
        cell += widthSpase(s[0], 4) + "|";
        cell += widthSpase(s[1], 12) + "|";
        cell += widthSpase(s[2], 15) + "|";
        cell += widthSpase(s[3], 27) + "|";
        cell += widthSpase(s[4], 12) + "|";
        for (int i=0; i<3; i++) {
            cell += widthSpase(s[i+5], 7) + "|";
        }
    }
    
    TableViewTextCell(char s) {
        cell += "|";
        cell += widthSpase(string(4,s), 4) + "|";
        cell += widthSpase(string(12,s), 12) + "|";
        cell += widthSpase(string(15,s), 15) + "|";
        cell += widthSpase(string(27,s), 27) + "|";
        cell += widthSpase(string(12,s), 12) + "|";
        for (int i=0; i<3; i++) {
            cell += widthSpase(string(7,s), 7) + "|";
        }
    }
    
    
    
    string description() const {
        return cell;
    }
    
    
private:
    
    string widthSpase(string text, int width, Align align = Align::leftT) {
        int leftSpase = (width - text.size()) / 2;
        if (align == Align::leftT) leftSpase = 1;
        if (width == text.size()) leftSpase = 0;
        int rightSpase = width - (text.size() + leftSpase);
        string c(leftSpase, ' ');
        c += text;
        c += string(rightSpase, ' ');
        return c;
    }
    
    
    
};



#endif /* TabelViewTextCell_hpp */
