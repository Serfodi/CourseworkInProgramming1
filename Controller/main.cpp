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
#include "ChoiceMenu.hpp"

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
            case viewData: {
                ViewData viewData;
                file.fileProcessing(viewData, dataModel, city, isRead);
                break;
            }
            case histogram: {
                Histogram histogram;
                file.fileProcessing(histogram, dataModel, city);
                break;
            }
            case birthrate: {
                Birthrate birthrate;
                file.fileProcessing(birthrate, dataModel, city);
                break;
            }
            case delet: {
                Delet delet;
                file.fileProcessing(delet, dataModel, city, isDelete);
                break;
            }
        }
        
        
    } catch(...) {
        cout << "Ошибка обработки";
    }
    
    
    
    return 0;
}


