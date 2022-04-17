//
//  DataModel.hpp
//  CourseworkInProgramming26
//
//  Created by Сергей Насыбуллин on 14.04.2022.
//

#ifndef DataModel_hpp
#define DataModel_hpp

#include "ChoiceMenu.hpp"
#include "Date.hpp"
#include "Country.hpp"

struct DataModel {
    
    ChoiceProcessing choiceProcessing;
    Area area;
    DataFormat dataFormat;
    Attribute attribute;
    
    string fIOInput;
    Data *dataInput;
    
    string *number;
    
};

#endif /* DataModel_hpp */
