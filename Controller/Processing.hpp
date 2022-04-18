//
//  Processing.hpp
//  CourseworkInProgramming26
//
//  Created by Сергей Насыбуллин on 27.03.2022.
//

/**
 * @file
 * Используется:
 *      - main
 */

#ifndef Processing_hpp
#define Processing_hpp

// Model
#include "Country.hpp"
#include "DataModel.hpp"
#include "Birth.hpp"

// view
#include "Output.hpp"
#include "Table.hpp"
#include "Histogram.hpp"


// Supporting
#include "ChoiceMenu.hpp"


/**
 *
 *
 *
 */
class Processing {
public:
    
    
    virtual bool processing(DataModel, Birth) = 0;
    
    
    /// Проверка по признаку
    static bool isAttribute(Attribute attribute, SexСhild children) {
        switch (attribute) {
            case general:
                return true;
            case boys:
                return children.attribute(m);
            case girls:
                return children.attribute(g);
            case multiple:
                return children.isMultiple();
        }
    }
    
    
};



/**
 *
 *
 *
 */
class ViewData: public Processing {
public:
    
    bool processing(DataModel dataModel, Birth birth) override {
        if ( isAttribute(dataModel.attribute, birth.children) ) { return false; }
        switch (dataModel.dataFormat) {
            case day:
                return  birth.dOB == dataModel.dataInput[0];
            case interval:
                return (birth.dOB >= dataModel.dataInput[0] && birth.dOB <= dataModel.dataInput[1]);
        }
    }
    
};



/**
 *
 *
 *
 */
class Histogram: public Processing {
public:
    
    int mouthStat[13] = {
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
    };
    
    bool processing(DataModel dataModel, Birth birth) override {
        if ( !isAttribute(dataModel.attribute, birth.children) ) { return false; }
        mouthStat[birth.dOB.getMonth()] += 1;
        return true;
    }
    
};



/**
 *
 *
 *
 */
class Birthrate: public Processing {
public:
    
    int indexMax, indexMin;
    
    int max = 0;
    int min = -1;
    
    int mouthStat[13] = {
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
    };
    
    bool processing(DataModel dataModel, Birth birth) override {
        
        if (!isAttribute(dataModel.attribute, birth.children)) { return false; }
        
        mouthStat[birth.dOB.getMonth()] += 1;
        
        if ( mouthStat[birth.dOB.getMonth()] > max ) {
            max = mouthStat[birth.dOB.getMonth()];
            indexMax = mouthStat[birth.dOB.getMonth()];
        }
        
        if (min == -1) {
            min = 1;
            indexMin = mouthStat[birth.dOB.getMonth()];
        }
        
        if ( mouthStat[birth.dOB.getMonth()] < min ) {
            min = mouthStat[birth.dOB.getMonth()];
            indexMin = mouthStat[birth.dOB.getMonth()];
        }
        
        return true;
    }
    
    
};


/**
 *
 * Удаления по: фио матери и году рождения матери
 *
 */
class Delet: public Processing {
    
    bool processing(DataModel dataModel, Birth birth) override {
        return ( dataModel.fIOInput == birth.fIO && dataModel.dataInput[0] == birth.dOBMother );
    }
    
};




#endif /* Processing_hpp */
