//
//  Processing.hpp
//  CourseworkInProgramming26
//
//  Created by Сергей Насыбуллин on 27.03.2022.
//

/**
 * @file Содержит классы обработки файла
 */

#ifndef Processing_hpp
#define Processing_hpp


/**
 * Метод обработки, однапроходный алгоритм возврощающий bool
 */
class Processing {
public:
    
    DataModel dataModel;
    
    virtual bool processing(const Birth&) = 0;
    
    ~Processing() {}
};



/**
 *
 *
 *
 */
class ViewData: public Processing {
public:
    
    ViewData(DataModel dataModel) {
        this -> dataModel = dataModel;
    }
    
    bool processing(const Birth &birth) override {
        switch (dataModel.dataFormat) {
            case day:
                return  birth.dOB == dataModel.dataInput[0];
            case interval:
                return (birth.dOB >= dataModel.dataInput[0] && birth.dOB <= dataModel.dataInput[1]);
        }
    }
    
    
    ~ViewData() {}
    
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
    
    Histogram(DataModel dataModel) {
        this -> dataModel = dataModel;
    }
    
    bool processing(const Birth &birth) override {
        if ( !SexСhild::isAttribute(dataModel.attribute, birth.children) ) { return false; }
        mouthStat[birth.dOB.getMonth()] += 1;
        return true;
    }
    
    
    ~Histogram() {}
    
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
    
    Birthrate(DataModel dataModel) {
        this -> dataModel = dataModel;
    }
    
    bool processing(const Birth &birth) override {
        
        if (!SexСhild::isAttribute(dataModel.attribute, birth.children)) { return false; }
        
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
    
    bool processing(const Birth &birth) override {
        return ( dataModel.fIOInput == birth.fIO && dataModel.dataInput[0] == birth.dOBMother );
    }
    
};




#endif /* Processing_hpp */
