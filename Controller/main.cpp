//
//  main.cpp
//  CourseworkInProgramming26
//
//  Created by Сергей Насыбуллин on 26.03.2022.
//

#include <iostream>

#include "Output.hpp"

#include "Input.hpp"
#include "Processing.hpp"
#include "FileProces.hpp"
#include "List.hpp"

#include "ModelBirth.hpp"

#include "ClassError.hpp"


// MARK: - main

List *List::first = 0;


using namespace std;
int main() {
    
    Output output;
    Input input;
    Processing processing;
    static FileProces file;
    
    
    // MARK: - Обработка файла
    
    file.openFileRead("/Users/serfodi/Xcode/C++/FileDataInfo");
    
    
    string text = file.readText();
    while (text != "") {
        new List(input.createBirth(text));
        text = file.readText();
    }
    
    
    // MARK: -  Mеню
    
    output.processing();
    processing.choiceProcessing = input.choiceProcessingCast(input.number());
    
    switch (processing.choiceProcessing) {
        case viewData:
            
            output.area();
            processing.area = input.areaCast(input.number());
            
            output.menuInput(processing.area);
            processing.areaText = input.text();
            
            output.dataFormat();
            processing.dataFormat = input.dataFormatCast(input.number());
            
            output.dataFormatInput(processing.dataFormat);
            
            try {
            processing.data = input.data(input.text(), processing.dataFormat);
            }
            catch (ErrorInput){
                cout << "хаха лох";
            }
                
            break;
        case histogram:
        case birthrate:
            
            output.area();
            processing.area = input.areaCast(input.number());
            
            output.menuInput(processing.area);
            processing.areaText = input.text();
            
            output.birthrate();
            processing.birthrat = input.birthrateCast(input.number());
            
            break;
        case delet:
            
            output.delet();
            
//            output.menuInput();
            
            break;
    }
    
    
    cout << processing.data;
    
    
    // MARK: - Обработка
    
    
    
    
    // MARK: - Вывод результата
    
    // вывод итоговой таблицы на экан и в файл
    
    
    
    return 0;
}
