//
//  main.cpp
//  CourseworkInProgramming26
//
//  Created by Сергей Насыбуллин on 26.03.2022.
//

#include <iostream>

#include "Output.hpp"
#include "Input.hpp"
#include "ModelBirth.hpp"
#include "FileProc.hpp"
#include "Processing.hpp"
#include "List.hpp"
#include "ClassError.hpp"


// MARK: - main

List *List::first = 0;


using namespace std;
int main() {
    
    Output output;
    Input input;
    Processing processing;
    FileProc file;
    
    
    // MARK: - Обработка файла
    
    file.openFile("/Users/serfodi/Xcode/C++/FileDataInfo");
    
    
    string text = file.getText();
    while (text != "") {
        new List(input.createBirth(text));
        text = file.getText();
    }
    
    List::description();
    
    // MARK: -  Mеню
    
    output.processing();
    processing.choiceProcessing = input.choiceProcessingCast(input.number());
    
    switch (processing.choiceProcessing) {
        case viewData:
            output.area();
            processing.area = input.areaCast(input.number());
            output.dataFormat();
            processing.dataFormat = input.dataFormatCast(input.number());
            break;
        case histogram:
        case birthrate:
            output.area();
            processing.area = input.areaCast(input.number());
            output.birthrate();
            processing.birthrat = input.birthrateCast(input.number());
            break;
        case delet:
            output.delet();
            break;
    }
    
    
    
    // MARK: - Обработка
    
    
    
    
    // MARK: - Вывод результата
    
    // вывод итоговой таблицы на экан и в файл
    
    
    
    return 0;
}
