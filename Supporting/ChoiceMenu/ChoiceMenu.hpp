//
//  ChoiceMenu.hpp
//  CourseworkInProgramming26
//
//  Created by Сергей Насыбуллин on 26.03.2022.
//

#ifndef ChoiceMenu_hpp
#define ChoiceMenu_hpp

#include <stdio.h>


/**
- parameters:
    - viewData: Просмотр данных за день или интервал
    - histogram: Вывод гистограммы рождаемости по месяцам года и кривой  рождаемости за год
    -birthrate: Определение месяцев максимальной и минимальной рождаемости
    -delet: Удаления
 */
enum ChoiceProcessing {
    viewData,
    histogram,
    birthrate,
    delet
};

/**
 Area
 1. По роддому hospital
 2. По району region
 3. По городу city
 */
enum Area {
    hospital,
    region,
    city
};

/**
 DataFormat
 1. День day
 2. Интервал interval
 */
enum DataFormat {
    day,
    interval
};

/**
 Birthrate
 1.Общей; general
 2. Мальчиков; boys
 3. Девочек; girls
 4. Многодетных родов. multiple
 */
enum Birthrate {
    general,
    boys,
    girls,
    multiple,
};


#endif /* ChoiceMenu_hpp */
