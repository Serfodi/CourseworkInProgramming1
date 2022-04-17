//
//  main.cpp
//  CourseworkInProgramming26
//
//  Created by Сергей Насыбуллин on 26.03.2022.
//


// Model
#include "DataModel.hpp"
#include "Country.hpp"

// Controller
#include "Menu.hpp"
#include "Processing.hpp"
#include "FileProcessing.hpp"

// Supporting
#include "ClassError.hpp"


using namespace std;



int main() {
    
    // model Data
    DataModel dataModel;
    
    // controllers
    City city;
    Menu menu;
    
    FileProcessing file;
    
    // MARK: - Обработка файла
    
    try {
        file.initCity("/Users/serfodi/Data/City", city);
        file.initBirth("/Users/serfodi/Test/FileDataInfo_1.txt");
    } catch(...) {
        cout << "Ошибка файла";
    }
    
    
    
    // MARK: -  Mеню
    
    try {
        menu.openMenu(dataModel, city);
    } catch (ErrorInput) {
        cout << "Ошибка ввода";
    } catch (invalid_argument) {
        cout << "Ошибка выхода";
    }
    
    
    
    // MARK: - Обработка
    
    try {
                
        switch (dataModel.choiceProcessing) {
            case viewData: case histogram: case birthrate: case delet:
                ViewData viewData;
                file.fileProcessing(viewData, dataModel);
                break;
        }
        
    } catch(...) {
        cout << "Ошибка обработки";
    }
    
    
    return 0;
}


