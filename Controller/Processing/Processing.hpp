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

// view
#include "Output.hpp"
#include "Table.hpp"
#include "Histogram.hpp"

// Controller
#include "List.hpp"

// Supporting
#include "ChoiceMenu.hpp"


/// Обработка массива
class Processing {
public:
    
    Table tabel;
    Output output;
    Histogram histog;
    
    ChoiceProcessing choiceProcessing;
    Area area;
    DataFormat dataFormat;
    Birthrate birthrat;
    
    int numberInput;
    string areaTextInput;
    string fIOInput;
    Data *dataInput;
    
    
    Processing () { }
    
    // MARK: - Методы
    
    
    void processing(List &list) {
        switch (choiceProcessing) {
            case viewData:
                viewDataProcessing(list);
                break;
            case histogram:
                histogramProcessing(list);
                break;
            case birthrate:
                birthrateProcessing(list);
                break;
            case delet:
                deletProcessing(list);
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
    void viewDataProcessing(List &list);
    
    /// Вывод гистограммы рождаемости по месяцам года и кривой  рождаемости за год
    void histogramProcessing(List &list);
    
    /// Определение месяцев максимальной и минимальной рождаемости по заданному Роддому, по району, по городу
    void birthrateProcessing(List &list);
    
    /// Удаление записей о родах (поиск по фамилии матери и по дате ее рождения).
    void deletProcessing(List &list);
    
    
    
//    MARK: Test
    
    /// Проверяет входит ли birth в введенную местность
    bool isArea(Birth birth) {
        switch (area) {
            case hospital:
                return numberInput == birth.number;
            case city:
            case region:
                return areaTextInput == birth.region;
        }
    }
    
    /// Проверяет условия поиска
    bool isBirthrate(Birth birth) {
        switch (birthrat) {
            case general:
                return true;
            case girls:
                return false;
            case boys:
                return false;
            case multiple:
                return false;
        }
    }
    
    
};


#endif /* Processing_hpp */
