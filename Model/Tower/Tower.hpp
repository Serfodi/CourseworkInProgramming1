//
//  Tower.hpp
//  CourseworkInProgramming26
//
//  Created by Сергей Насыбуллин on 07.04.2022.
//

#ifndef Tower_hpp
#define Tower_hpp




class Tower {
public:
    
    /// Имя
    string name;
    
    
    /// Возвращяет все номера
    virtual const vector<int> allNumbers() const = 0;
    
};

#include "RegionTower.hpp"
#include "CityTower.hpp"


#endif /* Tower_hpp */
