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
#include "Output.hpp"

// Controller
#include "Input.hpp"
#include "Processing.hpp"
#include "List.hpp"

// Supporting
#include "FileProces.hpp"
#include "ClassError.hpp"


// MARK: - main

/// хз куда и как засунуть поэтому тут. Нужен для работы Sex
string Sex::sexText[3] = {"м", "ж", "0"};


using namespace std;


int main() {
    
    setlocale(LC_CTYPE,"Russian");
    
    Input input;
    Output output;
    
    List list;
    Processing processing;
    FileProces file;
    
    // MARK: - Обработка файла
    
    
    try {
        file.openFileRead("/Users/serfodi/Xcode/C++/FileDataInfo_2");
    } catch (ErrorFile) {
        output.errorOpenFile();
    }
        
    string text = file.readText();
    while (text != "") {
        list.append(Birth(text));
        text = file.readText();
    }
    
    
    // MARK: -  Mеню
    
    try {
        
        output.processingOutput();
        processing.choiceProcessing = input.choiceProcessingCast(input.number());
        
            
        if (processing.choiceProcessing != delet) {
            
            output.areaOutput();
            processing.area = input.areaCast(input.number());
            
            output.menuInput(processing.area);
            
            switch (processing.area) {
                case hospital:
                    processing.numberInput = input.number();
                    break;
                case city:
                case region:
                    processing.areaTextInput = input.text();
                    break;
            }
            
            switch (processing.choiceProcessing) {
                case viewData:
                    
                    output.dataFormatOutput();
                    processing.dataFormat = input.dataFormatCast(input.number());
                    
                    
                    output.dataFormatInput(processing.dataFormat);
                    processing.dataInput = input.dataCast(input.text(), processing.dataFormat);
                    
                    break;
                    
                case histogram:
                case birthrate:
                    
                    output.birthrateOutput();
                    processing.birthrat = input.birthrateCast(input.number());
                    
                    break;
                case delet: break;
            }
            
        } else {
            
            output.deletOutputFIO();
            processing.fIOInput = input.text();
            
            output.deletOutputData();
            processing.dataInput = input.dataCast(input.text(), day);
            
        }
    
    } catch (ErrorInput) {
        
        output.errorInputText();
        
    } catch (invalid_argument) {
        
        output.errorInputText();
        
    }
    
    // MARK: - Обработка
    
    processing.processing(list);
    
    return 0;
}


