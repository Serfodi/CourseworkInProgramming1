//
//  Menu.hpp
//  CourseworkInProgramming26
//
//  Created by Сергей Насыбуллин on 14.04.2022.
//

#ifndef Menu_hpp
#define Menu_hpp

#include <stdio.h>

// View
#include "Output.hpp"

// Controller
#include "Input.hpp"
#include "DataModel.hpp"
#include "ChoiceMenu.hpp"


class Menu {
private:
    // Ввод / вывод данных в консоль
    Input input;
    Output output;
    
public:
    
    // MARK:  Методы
    
    /// Меню выбора обработки
    void openMenu(DataModel &dataModel) {
        output.processingOutput();
        dataModel.choiceProcessing = input.choiceProcessingCast(input.number());
        
        if (dataModel.choiceProcessing != delet) {
            menuArea(dataModel);
            switch (dataModel.choiceProcessing) {
                case viewData:
                    menuDataFormat(dataModel);
                    break;
                case histogram: case birthrate:
                    menuAttributeBirthrate(dataModel);
                    break;
            }
        } else {
            menuDelete(dataModel);
        }
    }
    
private:
    /// Меню выбора места поиска
    void menuArea(DataModel &dataModel) {
        output.areaOutput();
        dataModel.area = input.areaCast(input.number());
        output.menuInput(dataModel.area);
        switch (dataModel.area) {
            case hospital:
                dataModel.number = input.number();
                break;
            case city: case region:
                dataModel.region = input.text();
                break;
        }
        
    }
    
    /// Меню выбора дата
    void menuDataFormat(DataModel &dataModel) {
        output.dataFormatOutput();
        dataModel.dataFormat = input.dataFormatCast(input.number());
        output.dataFormatInput(dataModel.dataFormat);
        dataModel.dataInput = input.dataCast(input.text(), dataModel.dataFormat);
    }
    
    void menuAttributeBirthrate(DataModel &dataModel) {
        output.birthrateOutput();
        dataModel.birthrate = input.birthrateCast(input.number());
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
