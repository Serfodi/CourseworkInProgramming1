//
//  ViewTextBirthrate.hpp
//  CourseworkInProgramming26
//
//  Created by Сергей Насыбуллин on 20.04.2022.
//

#ifndef ViewTextBirthrate_hpp
#define ViewTextBirthrate_hpp

#include <stdio.h>



class ViewTextBirthrate {
    
    void mouth(int mouthMax, int mouthMin, int numberMax, int numberMin) {
        cout << "Максимальное кол-во рождений: " << text.textData[mouthMax-1] << endl
        << "Что составило: " << numberMax << endl;
        cout << "Минимальное кол-во рождений: " << text.textData[mouthMin-1] << endl
        << "Что составило: " << numberMin << endl;
    }

    void mouthEqule(int number) {
        cout << "В каждом месецы было одинаковое кол-во рождений." << endl
        << "Что составило: " << number;
    }
    
}


#endif /* ViewTextBirthrate_hpp */
