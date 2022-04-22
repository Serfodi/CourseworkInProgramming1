//
//  Menu.hpp
//  CourseworkInProgramming26
//
//  Created by Сергей Насыбуллин on 14.04.2022.
//

#ifndef Menu_hpp
#define Menu_hpp

// View
#include "OutputMenu.hpp"

// Controller
#include "Input.hpp"

#include "DataModel.hpp"
#include "ChoiceMenu.hpp"


class Menu {
private:
    
    /// Ввод
    Input input;
    /// Вывод
    OutputMenu output;
    
public:
    
    // MARK: Методы
    
    /// Меню выбора обработки
    void openMenu(DataModel &dataModel) {
        output.outMenu(output.textСP, 5);
        dataModel.choiceProcessing = input.choiceProcessingCast(input.number());
        
        if (dataModel.choiceProcessing != delet) menuArea(dataModel);
        
        switch (dataModel.choiceProcessing) {
            case viewData:
                menuDataFormat(dataModel);
                break;
            case histogram: case birthrate:
                menuAttributeBirthrate(dataModel);
                break;
            case delet:
                menuDelete(dataModel);
        }
    }
    
    
private:
    
    /// Меню выбора места поиска
    void menuArea(DataModel &dataModel) {
        output.outMenu(output.textArea, 4);
        dataModel.area = input.areaCast(input.number());
        output.areaForInput(dataModel.area);
        dataModel.areaText = input.text();
    }
    
    /// Меню выбора дата
    void menuDataFormat(DataModel &dataModel) {
        output.outMenu(output.textDataFormat, 3);
        dataModel.dataFormat = input.dataFormatCast(input.number());
        output.dataFormatForInput(dataModel.dataFormat);
        dataModel.dataInput = input.dataCast(input.text(), dataModel.dataFormat);
    }
    
    // Меню выбора критерия Birthrate
    void menuAttributeBirthrate(DataModel &dataModel) {
        output.outMenu(output.textBirthrate, 5);
        dataModel.attribute = input.attributeCast(input.number());
    }
    
    /// Меню удаления
    void menuDelete(DataModel &dataModel) {
        output.deletOutputFIO();
        dataModel.fIOInput = input.text();
        output.deletOutputData();
        dataModel.dataInput = input.dataCast(input.text(), day);
    }
    
};

#endif /* Menu_hpp */
