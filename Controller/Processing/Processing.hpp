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
#include "MaternityHospital.hpp"
#include "DataModel.hpp"
#include "Birth.hpp"

// view
#include "Output.hpp"
#include "Table.hpp"
#include "Histogram.hpp"


// Supporting
#include "ChoiceMenu.hpp"


//typedef void (*Open)(string);
//typedef void (*Read)(Birth);
typedef bool (*Test)();
typedef void (*Close)();

/// Обработка массива
class Processing {
private:
    // view
    Table tabel;
    Output output;
    Histogram histog;
    
    
public:
    
    Processing () { }
    
    // MARK: - Методы
    
    /// Обработка
    ///
    /// @param hospital Госпитали
    /// @param dataModel Модель данных
    /// @param open Открытия файла
    /// @param read Чтения из файла
    /// @param test Проверка чтения
    /// @param close Закрытия файла
    ///
    void processing(Hospital hospital, DataModel dataModel, void (*open)(string), void (*read)(Birth&), Test test, Close close) {
        switch (dataModel.choiceProcessing) {
            case viewData:
                viewDataProcessing(hospital, dataModel, open, read, test, close);
                break;
            case histogram:
//                histogramProcessing(hospital, dataModel, open, read, test, close);
                break;
            case birthrate:
//                birthrateProcessing(hospital, dataModel, open, read, test, close);
                break;
            case delet:
//                deletProcessing(hospital, dataModel, open, read, test, close);
                break;
        }
    }

    
private:

    /// Просмотр данных за любой день (или за любой временной интервал)
    void viewDataProcessing(Hospital hospital, DataModel dataFormat, void (*open)(string), void (*read)(Birth&), Test test, Close close);
    
    /// Вывод гистограммы рождаемости по месяцам года и кривой  рождаемости за год
//    void histogramProcessing(Hospital hospital, DataModel dataFormat, Open open, Read read, Test test, Close close);
    
    /// Определение месяцев максимальной и минимальной рождаемости по заданному Роддому, по району, по городу
//    void birthrateProcessing(Hospital hospital, DataModel dataFormat, Open open, Read read, Test test, Close close);
    
    /// Удаление записей о родах (поиск по фамилии матери и по дате ее рождения).
//    void deletProcessing(Hospital hospital, DataModel dataFormat, Open open, Read read, Test test, Close close);
    
};


#endif /* Processing_hpp */
