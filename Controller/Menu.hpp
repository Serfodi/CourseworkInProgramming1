//
//  Menu.hpp
//  CourseworkInProgramming26
//
//  Created by Сергей Насыбуллин on 14.04.2022.
//

#ifndef Menu_hpp
#define Menu_hpp

// View
#include "Output.hpp"

// Controller
#include "Input.hpp"
#include "DataModel.hpp"
#include "ChoiceMenu.hpp"


class Menu {
private:
    
    /// Ввод
    Input input;
    /// Вывод
    Output output;
    
public:
    
    // MARK: Методы
    
    /// Меню выбора обработки
    void openMenu(DataModel &dataModel, City &city) {
        output.processingOutput();
        dataModel.choiceProcessing = input.choiceProcessingCast(input.number());
        
        if (dataModel.choiceProcessing != delet) menuArea(dataModel, city);
        
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
    void menuArea(DataModel &dataModel, City &city) {
        output.areaOutput();
        dataModel.area = input.areaCast(input.number());
        output.menuInput(dataModel.area);
        dataModel.number = input.numbersCase(input.text(), dataModel.area, city);
    }
    
    /// Меню выбора дата
    void menuDataFormat(DataModel &dataModel) {
        output.dataFormatOutput();
        dataModel.dataFormat = input.dataFormatCast(input.number());
        output.dataFormatInput(dataModel.dataFormat);
        dataModel.dataInput = input.dataCast(input.text(), dataModel.dataFormat);
    }
    
    // Меню выбора критерия Birthrate
    void menuAttributeBirthrate(DataModel &dataModel) {
        output.birthrateOutput();
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
