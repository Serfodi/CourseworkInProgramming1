//
//  main.cpp
//  CourseworkInProgramming26
//
//  Created by Сергей Насыбуллин on 26.03.2022.
//

// Directives
#include <iostream>

// Model
#include "Birth.hpp"

// View
//#include "Menu.hpp"
#include "Output.hpp"

// Controller
#include "Input.hpp"
#include "List.hpp"
#include "Processing.hpp"

// Supporting
#include "FileProces.hpp"
#include "ClassError.hpp"


// MARK: - main

/// Начало списка
List *List::first = 0;
/// хз куда и как засунуть поэтому тут. Нужен для работы Sex
string Sex::sexText[3] = {"м", "ж", "0"};


using namespace std;


int main() {
    
    Input input;
    Output output;
    
    static Processing processing;
    
    static FileProces file;
    
    
    // MARK: - Обработка файла
    
    file.openFileRead("/Users/serfodi/Xcode/C++/FileDataInfo");
    
    string text = file.readText();
    while (text != "") {
        new List(Birth(text));
        text = file.readText();
    }
    
//    List::description();
    
    // MARK: -  Mеню
    
    // ввод только здесь
    
    output.processingOutput();
    processing.choiceProcessing = input.choiceProcessingCast(input.number());
    
    if (processing.choiceProcessing != delet) {
        
        output.areaOutput();
        processing.area = input.areaCast(input.number());
        
        output.menuInput(processing.area);
        processing.areaText = input.text();
        
        
        switch (processing.choiceProcessing) {
            case viewData:
                
                output.dataFormatOutput();
                processing.dataFormat = input.dataFormatCast(input.number());
                
                
                output.dataFormatInput(processing.dataFormat);
                processing.data = input.dataCast(input.text(), processing.dataFormat);
                
                break;
            case histogram:
            case birthrate:
                processing.birthrat = input.birthrateCast(input.number());
                break;
            case delet: break;
        }
        
    } else {
        
        // ввод для удаления
        
    }
    
    cout << endl << processing.description() << endl;
    
    // MARK: - Обработка
    
    
    processing.processing();
    
    
    
    // MARK: - Вывод результата
    
    // вывод итоговой таблицы на экан и в файл
    
    
    
    return 0;
}


