//
//  DataModel.hpp
//  CourseworkInProgramming26
//
//  Created by Сергей Насыбуллин on 14.04.2022.
//

#ifndef DataModel_hpp
#define DataModel_hpp


/// Модель данные пользователя выведенных с клавиатуры
struct DataModel {
    
    /// Выбор обработки
    ChoiceProcessing choiceProcessing;
    /// Выбор зону поиска
    Area area;
    /// Выбор формата даты
    DataFormat dataFormat;
    /// Выбор атрибутов поиска
    Attribute attribute;
    /// Ввод фамилии
    string fIOInput;
    /// Ввод даты
    vector<Data> dataInput;
    /// Ввод адреса
    string areaText;
    
};

#endif /* DataModel_hpp */

