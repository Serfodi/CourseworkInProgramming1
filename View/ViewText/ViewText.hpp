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
    
    virtual void output(ostream &out) = 0;
    
};

#include "TableViewText.hpp"
#include "HistogramViewText.hpp"
#include "BirthrateViewText.hpp"

#endif /* ViewText_hpp */
