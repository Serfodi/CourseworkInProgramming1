//
//  ViewText.hpp
//  CourseworkInProgramming26
//
//  Created by Сергей Насыбуллин on 20.04.2022.
//

#ifndef ViewText_hpp
#define ViewText_hpp



class ViewText {
public:
    
    DataModel dataModel;
    
    ViewText(const DataModel &dataModel) {
        this -> dataModel = dataModel;
    }
    
    virtual void output(ostream &out) = 0;
    
};

#include "TableViewText.hpp"
#include "HistogramViewText.hpp"
#include "BirthrateViewText.hpp"
#include "DeleteViewText.hpp"

#endif /* ViewText_hpp */
