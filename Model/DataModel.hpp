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
    /// Все роддомы которые были в файле
    vector<int> numbers = {1,2,3,4,5,6,7,8,9,10,11,12};
    /// Ввод адреса
    string areaText;
    
};

#endif /* DataModel_hpp */

