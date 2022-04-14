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
#include "MaternityHospital.hpp"

// view
#include "Output.hpp"
#include "Table.hpp"
#include "Histogram.hpp"

// Controller
#include "FileProces.hpp"

// Supporting
#include "ChoiceMenu.hpp"


/// Обработка массива
class Processing {
private:
    // view
    Table tabel;
    Output output;
    Histogram histog;
    
public:
    
    // enum
    ChoiceProcessing choiceProcessing;
    Area area;
    DataFormat dataFormat;
    Birthrate birthrat;
    
    // data
    City hospital;
    
    string fIOInput;
    Data *dataInput;
    
    
    Processing () { }
    
    // MARK: - Методы
    
    
    void processing(Hospital hospital) {
        switch (choiceProcessing) {
            case viewData:
                viewDataProcessing(hospital);
                break;
            case histogram:
                histogramProcessing(hospital);
                break;
            case birthrate:
                birthrateProcessing(hospital);
                break;
            case delet:
                deletProcessing();
                break;
        }
    }
    
    /*
     Нужен для отладки
     
    /// Передает информацию
    string description() {
        string s;
        s += "choiceProcessing: " + to_string(choiceProcessing) + "\n";
        s += "area: " + to_string(area) + "\n";
        s += "dataFormat: "  + to_string(dataFormat) + "\n";
        s += "birthrat: "  + to_string(birthrat) + "\n";
        s += "areaText: " + areaTextInput + "\n";
        s += "fIO: " + fIOInput + "\n";
        s += "data: ";
        for (int i = 0; i <= dataFormat; i++)
            s += dataInput[i].description() + " - ";
        return s;
    }
    */
    
private:
    /// Просмотр данных за любой день (или за любой временной интервал)
    void viewDataProcessing(Hospital hospital);
    
    /// Вывод гистограммы рождаемости по месяцам года и кривой  рождаемости за год
    void histogramProcessing(Hospital hospital);
    
    /// Определение месяцев максимальной и минимальной рождаемости по заданному Роддому, по району, по городу
    void birthrateProcessing(Hospital hospital);
    
    /// Удаление записей о родах (поиск по фамилии матери и по дате ее рождения).
    void deletProcessing();
    
};


#endif /* Processing_hpp */
