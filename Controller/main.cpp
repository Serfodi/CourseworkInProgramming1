//
//  main.cpp
//  CourseworkInProgramming26
//
//  Created by Сергей Насыбуллин on 26.03.2022.
//

#include <iostream>
 

// Model

// Controller
#include "Menu.hpp"
#include "Processing.hpp"
#include "FileProcessing.hpp"
#include "ViewText.hpp"

#include "DataModel.hpp"
#include "Country.hpp"
#include "Birth.hpp"

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
        menu.openMenu(dataModel);
    } catch (ErrorInput) {
        cout << "Ошибка ввода";
    } catch (invalid_argument) {
        cout << "Ошибка выхода";
    }
    
    
    
    // MARK: - Обработка
    
    try {
        
        // Получения всех номеров госпиталей в заданном area
        int count = 0;
        int *numbers = city.getAll(dataModel.area, dataModel.areaText, count);
        
        
        switch (dataModel.choiceProcessing) {
            case viewData: {
                ViewData viewData = { dataModel };
                file.fileProcessing(viewData, count, numbers, isRead);
                break;
            }
            default:
                break;
//            case histogram: {
//                Histogram histogram;
//                HistogramView view;
//                file.fileProcessing(histogram, dataModel, city);
//                file.fileOutputHistogram(histogram, view);
//                view.output(cout, histogram);
//                break;
//            }
//            case birthrate: {
//                Birthrate birthrate;
//                file.fileProcessing(birthrate, dataModel, city);
//                break;
//            }
//            case delet: {
//                Delet delet;
//                dataModel.areaText = city.name;
//                file.fileProcessing(delet, dataModel, city, isDelete);
//
//                break;
//            }
        
        }
        
        
    } catch(...) {
        cout << "Ошибка обработки";
    }
    
    
    
    return 0;
}


