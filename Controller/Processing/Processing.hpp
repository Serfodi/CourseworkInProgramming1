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

// Model
#include "Birth.hpp"
#include "Date.hpp"

// Controller
#include "List.hpp"

// Supporting
#include "ChoiceMenu.hpp"


/// Обработка массива
class Processing {
public:
    
    ChoiceProcessing choiceProcessing;
    Area area;
    DataFormat dataFormat;
    Birthrate birthrat;
    
    string areaText;
    string fIO;
    Data *data;
    
    Processing () { }
    
    // MARK: - Методы
    
    
    void processing(List &list) {
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
                deletProcessing(list);
                break;
        }
    }
    
    /// Передает информацию
    string description() {
        string s;
        s += "choiceProcessing: " + to_string(choiceProcessing) + "\n";
        s += "area: " + to_string(area) + "\n";
        s += "dataFormat: "  + to_string(dataFormat) + "\n";
        s += "birthrat: "  + to_string(birthrat) + "\n";
        s += "areaText: " + areaText + "\n";
        s += "fIO: " + fIO + "\n";
        s += "data: ";
        for (int i = 0; i <= dataFormat; i++)
            s += data[i].description() + " - ";
        return s;
    }
    
private:
    void viewDataProcessing();
    
    void histogramProcessing();
    
    void birthrateProcessing();
    
    void deletProcessing(List &list);
    
};


#endif /* Processing_hpp */
