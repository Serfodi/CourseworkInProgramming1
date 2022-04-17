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


/// Обработка массива
class Processing {
public:
    virtual bool processing(DataModel, Birth) = 0;
    
};


class ViewData: public Processing {

    Table tabel;
    
public:
    ViewData() {
        tabel.printTable();
    }
    
    bool processing(DataModel dataModel, Birth birth) override {
        switch (dataModel.dataFormat) {
            case day:
                if (birth.dOB == dataModel.dataInput[0]) {
                    tabel.addToTable(birth);
                    return true;
                }
            case interval:
                if (birth.dOB >= dataModel.dataInput[0] && birth.dOB <= dataModel.dataInput[1]) {
                    tabel.addToTable(birth);
                    return true;
                }
        }
        return false;
    }
    
};

class Histogram {
    
    HistogramView histogramView;
    
    int mouthStat[13] = {
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
    };
    
    
    
};

class Birthrate {
    
    // view
    Output output;
    
    int max = 0;
    int min = 0;
    
    int mouthStat[13] = {
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
    };
    
    
};



#endif /* Processing_hpp */
