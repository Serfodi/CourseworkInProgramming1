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

#include <stdio.h>

#include "ChoiceMenu.hpp"
#include "ModelBirth.hpp"
#include "List.hpp"
#include "Date.hpp"

class Processing {
    
public:
    ChoiceProcessing choiceProcessing;
    Area area;
    DataFormat dataFormat;
    Birthrate birthrat;
    
    
    string areaText;
    string fIO;
    Data *data;
    
    
    // MARK: - Методы
    
    void processing() {
        switch (choiceProcessing) {
            case viewData:
                viewDataProcessing();
                break;
            case histogram:
                histogramProcessing();
                break;
            case birthrate:
                birthrateProcessing();
                break;
            case delet:
                deletProcessing();
                break;
        }
    }
    
private:
    void viewDataProcessing();
    
    void histogramProcessing();
    
    void birthrateProcessing();
    
    void deletProcessing();
    
};


#endif /* Processing_hpp */
