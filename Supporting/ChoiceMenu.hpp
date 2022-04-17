//
//  ChoiceMenu.hpp
//  CourseworkInProgramming26
//
//  Created by Сергей Насыбуллин on 26.03.2022.
//

/**
 * @file Содержит перечисления меню.
 */

#ifndef ChoiceMenu_hpp
#define ChoiceMenu_hpp

//#include <stdio.h>


/// Выбор обработки
enum ChoiceProcessing {
    /// Просмотр данных за день или интервал
    viewData,
    /// Вывод гистограммы рождаемости по месяцам года и кривой  рождаемости за год
    histogram,
    /// Определение месяцев максимальной и минимальной рождаемости
    birthrate,
    /// Удаления по фамилии и дате рождения
    delet,
    
};

/// Местность
enum Area {
    /// По заданному Роддому
    hospital,
    /// По району
    region,
    /// По городу
    city,
    
};

/// Формат даты
enum DataFormat {
    /// День: дд.мм.гггг
    day,
    /// Интервал: дд.мм.гггг - дд.мм.гггг
    interval,
    
};

/// Критерии отбора
enum Attribute {
    /// Общей рождаемости
    general,
    /// Только мальчиков
    boys,
    /// Только девочек
    girls,
    /// Многодетных родителей
    multiple,
    
};


#endif /* ChoiceMenu_hpp */
