//
//  ModelBirth.hpp
//  CourseworkInProgramming26
//
//  Created by Сергей Насыбуллин on 26.03.2022.
//

#ifndef ModelBirth_hpp
#define ModelBirth_hpp

#include <stdio.h>

#include <iostream>

#include "Date.hpp"


enum Sex {
    m,
    g,
    no
};

/**
 
 */
struct Birth {
public:
    int number;
    Data dOB;
    std::string region;
    std::string fIO;
    Data dOBMother;
    Sex children[3];
    
    Birth() { }
    
    Birth(int _number, Data _dOB, std::string _region, std::string _fIO, Data _dOBMother, Sex _children[3]) {
        number = _number;
        dOB = _dOB;
        region = _region;
        fIO = _fIO;
        dOBMother = _dOBMother;
        for (int i = 0; i<3; i++) children[i] = _children[i];
    }
    
    
    std::string description() {
        std::string text;
        text += std::to_string(number) + "\n";
        text += dOB.description() + "\n";
        text += region + "\n";
        text += fIO + "\n";
        text += dOBMother.description() + "\n";
        for (int i = 0; i < 3; i++) text += std::to_string(children[i]) + " ";
        text += "\n";
        return text;
    }
    
};


#endif /* ModelBirth_hpp */
