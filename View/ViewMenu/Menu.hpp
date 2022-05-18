//
//  Menu.hpp
//  CourseworkInProgramming26
//
//  Created by Сергей Насыбуллин on 14.04.2022.
//

#ifndef Menu_hpp
#define Menu_hpp

#include "Input.hpp"

class Menu {
private:
    
    /// Ввод
    Input input;
    
    
public:
    
    // MARK: Методы
    
    /// Меню выбора обработки
    void open(DataModel &dataModel, City &city) {
        
        output(textСP);
        dataModel.choiceProcessing = input.choiceProcessingCast(input.number());
        
        if (dataModel.choiceProcessing != removeBirth) menuArea(dataModel, city);
        switch (dataModel.choiceProcessing) {
            case viewBirth:
                menuDataFormat(dataModel);
                break;
            case histogram: case birthrate:
                menuAttributeBirthrate(dataModel);
                break;
            case removeBirth:
                menuDelete(dataModel);
        }
        
        
    }
    
    
private:
    
    
    /// Меню выбора дата
    void menuDataFormat(DataModel &dataModel) {
        output(textDataFormat);
        dataModel.dataFormat = input.dataFormatCast(input.number());
        cout << textDataFormatInput[dataModel.dataFormat];
        dataModel.dataInput = input.dateCast(input.text(), dataModel.dataFormat);
    }
    
    /// Меню выбора места поиска
    void menuArea(DataModel &dataModel, City &city) {
        output(textArea);
        dataModel.area = input.areaCast(input.number());
        outCity(dataModel.area, city);
        cout << endl << textAreaInput[dataModel.area];
        dataModel.areaText = input.text();
    }
    
    // Меню выбора критерия Birthrate
    void menuAttributeBirthrate(DataModel &dataModel) {
        output(textBirthrate);
        dataModel.attribute = input.attributeCast(input.number());
    }
    
    /// Меню удаления
    void menuDelete(DataModel &dataModel) {
        cout << textDeletInput[0];
        dataModel.fIOInput = input.text();
        cout << textDeletInput[1];
        dataModel.dataInput = input.dateCast(input.text(), day);
    }
    
    
    
    
private:
    
    void outCity (Area area, City &city) {
        switch (area) {
            case Area::city:
                cout << city.getName();
                break;
            case Area::region:
                output(city.getRegionName());
                break;
            case Area::hospital:
                output(city.getNumberName());
                break;
        }
    }
    
    void output(vector<string> array) {
        for (int i = 0; i < array.size(); i++) {
            cout << array[i];
            if (!(i == array.size()-1)) {
                cout << endl;
            }
        }
    }
    
    
    
    /// Текст для выбора обработки.
    const vector<string> textСP = {
        "Выберите обработку:",
        "1. Просмотр данных по времени.",
        "2. Вывод гистограммы рождаемости по месяцам года и кривой  рождаемости за год.",
        "3. Определение месяцев максимальной и минимальной рождаемости.",
        "4. Удаление записей о родах.",
        "Введите число от 1 до 4: "
    };
    /// Текст для выбора места
    const vector<string> textArea = {
        "Искать:",
        "1. По роддому.",
        "2. По району.",
        "3. По городу.",
        "Введите число от 1 до 3: "
    };
    /// Текст для выбора форматы даты
    const vector<string> textDataFormat = {
        "Выберите день или интервал:",
        "1. День.",
        "2. Интервал.",
        "Введите число 1 или 2: "
    };
    /// Текст для выбора критерий поиска рождаемости
    const vector<string> textBirthrate = {
        "Критерии поиска:",
        "1. Общей рождаемости",
        "2. Только мальчиков",
        "3. Только девочек",
        "4. Многодетных родов ( более одного ребенка)",
        "Введите число от 1 до 4: "
    };
    
    /// Текст для просьбы ввода даты.
    const vector<string> textDataFormatInput = {
        "Введите день в формате 'дд.мм.гггг': ",
        "Введите интервал в формате 'дд.мм.гггг - дд.мм.гггг': "
    };
    /// Текст для просьбы ввода места.
    const vector<string> textAreaInput = {
        "Введите роддом: ",
        "Введите район: ",
        "Введите город: "
    };
    
    const vector<string> textDeletInput = {
        "Введите ФИО матери: ",
        "Введите дату рождения матери: "
    };
    
};

#endif /* Menu_hpp */
