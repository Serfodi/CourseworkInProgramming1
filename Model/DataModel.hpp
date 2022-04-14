//
//  DataModel.hpp
//  CourseworkInProgramming26
//
//  Created by Сергей Насыбуллин on 14.04.2022.
//

#ifndef DataModel_hpp
#define DataModel_hpp

#include <stdio.h>

#include "ChoiceMenu.hpp"
#include "Date.hpp"

struct DataModel {
    
    ChoiceProcessing choiceProcessing;
    Area area;
    DataFormat dataFormat;
    Birthrate birthrate;
    
    int number;
    string region;
    string fIOInput;
    Data *dataInput;
    
};

#endif /* DataModel_hpp */
