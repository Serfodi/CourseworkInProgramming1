//
//  TableViewText.cpp
//  CourseworkInProgramming26
//
//  Created by Сергей Насыбуллин on 22.04.2022.
//

#include "TableViewText.hpp"

void Table::addToTable(ostream &out, Birth birth) {
    
    out << sep
    << setw(6) << birth.number << setw(2) << sep
    << setw(10) << birth.dOB.description() << setw(2) << sep
    << setw(20) << birth.region << setw(2) << sep
    << setw(7) << birth.fIO << setw(2) << sep
    << setw(10) << birth.dOBMother.description() << setw(2) << sep
    << endl;
    
}

void Table::printTable(ostream &out) {
    out << "Таблица" << endl;
}
