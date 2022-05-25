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
public:
    
    // MARK: Методы
    
    
    /// Меню выбора обработки
    void open(DataModel &dataModel, City &city) {
        
        choiceProcessingMenu(dataModel);
        
        if (dataModel.choiceProcessing != removeBirth) menuArea(dataModel, city);
        
        switch (dataModel.choiceProcessing) {
            case viewBirth:
                
                dateFormatMenu(dataModel);
                break;
                
            case histogram: case birthrate:
                
                menuAttributeBirthrate(dataModel);
                break;
                
            case removeBirth:
                
                menuDelete(dataModel);
                break;
        }
    }
    
    
private:
    
    void choiceProcessingMenu(DataModel &dataModel) {
        output(textСP);
        choiceProcessingInput(dataModel);
        clearTab();
    }
    
    void dateFormatMenu(DataModel &dataModel) {
        output(textDataFormat);
        dateFormatInput(dataModel);
        clearTab();
        output(textDataFormatInput[dataModel.dataFormat]);
        dateInput(dataModel);
        clearTab();
    }
    
    void menuArea(DataModel &dataModel, City &city) {
        output(textArea);
        areaInput( dataModel);
        clearTab();
        outCity(dataModel.area, city);
        cout << endl << textAreaInput[dataModel.area];
        areaTextInput(dataModel);
        clearTab();
    }
    
    void menuAttributeBirthrate(DataModel &dataModel) {
        output(textBirthrate);
        attributeInput(dataModel);
        clearTab();
    }
    
    void menuDelete(DataModel &dataModel) {
        output(textDeletInput[0]);
        dataModel.fIOInput = Input::text();
        output(textDeletInput[1]);
        dataModel.dataFormat = day;
        dateInput(dataModel);
        clearTab();
    }
    
public:
    
    void clearTab() {
//        system("cls");
        for (int i = 0; i<30; i++) { cout << endl; }
    }
    
private:
    // MARK: - Ввод
    
    
    void dateInput (DataModel &dataModel) {
        try {
            dataModel.dataInput = Input::dateCast(Input::text(), dataModel.dataFormat);
        }
        catch (DateError error) {
            cout << error.what();
            dateInput(dataModel);
        }
    }
    
    void dateFormatInput (DataModel &dataModel) {
        try {
            dataModel.dataFormat = Input::dataFormatCast(Input::number());
        }
        catch (InputError error) {
            cout << error.what();
            dateFormatInput(dataModel);
        }
    }
    
    void choiceProcessingInput (DataModel &dataModel) {
        try {
            dataModel.choiceProcessing = Input::choiceProcessingCast(Input::number());
        }
        catch (InputError error) {
            cout << error.what();
            choiceProcessingInput(dataModel);
        }
    }
    
    void areaInput(DataModel &dataModel) {
        try {
            dataModel.area = Input::areaCast(Input::number());
        }
        catch (InputError error) {
            cout << error.what();
            areaInput(dataModel);
        }
    }
    
    void areaTextInput (DataModel &dataModel) {
        try {
            dataModel.areaText = Input::text();
        }
        catch (InputError error) {
            cout << error.what();
            areaTextInput(dataModel);
        }
    }
    
    void attributeInput (DataModel &dataModel) {
        try {
            dataModel.attribute = Input::attributeCast(Input::number());
        }
        catch (InputError error) {
            cout << error.what();
            attributeInput(dataModel);
        }
    }
    
    
    
    
    // MARK: -  Вывод текста
    
    
    void outCity (Area area, City &city) {
        switch (area) {
            case Area::city:
                cout << city.getName();
                break;
            case Area::region:
                output(city.getAllRegionName());
                break;
            case Area::hospital:
                output(city.getAllNumberName());
                break;
        }
    }
    
    void output(vector<string> array) {
        for (int i = 0; i < array.size(); i++) {
            cout << array[i];
            if (!(i == array.size()-1))
                cout << endl;
        }
    }
    
    void output (string text) { cout << text; }
    
    
    
    
    
    // MARK: - Текст
    
    
    
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
