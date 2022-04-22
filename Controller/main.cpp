//
//  main.cpp
//  CourseworkInProgramming26
//
//  Created by Сергей Насыбуллин on 26.03.2022.
//

#include <iostream>
#include <fstream>
#include <string>

// Supporting
#include "ClassError.hpp"
#include "ExtensionString.hpp"
#include "ChoiceMenu.hpp"

// Model
#include "Date.hpp"
#include "Sex.hpp"
#include "Birth.hpp"
#include "DataModel.hpp"
#include "Country.hpp"

// View
#include "Menu.hpp"
#include "ViewText.hpp"

// Controller
#include "Processing.hpp"
#include "FileProcessing.hpp"


using namespace std;


int main() {
    
    // model Data
    DataModel dataModel;
    City city;
    
    FileProcessing file;
    
    Menu menu;
    
    
    // MARK: - Обработка файла
    
    
    try {
        
        file.initCity("/Users/serfodi/Data/City", city);
        file.initData<Birth>("/Users/serfodi/Test/FileDataInfo_1.txt");
        
    } catch(...) {
        cout << "Ошибка файла";
    }
    
    
    
    // MARK: -  Mеню
    
    try {
        
        menu.openMenu(dataModel);
        
    } catch(...) {
        cout << "Ошибка ввода";
    }
    
    
    
    // MARK: - Обработка
    
    try {
        
        // Получения всех номеров госпиталей в заданном area
        int count = 0;
        int *numbers = city.getAll(dataModel.area, dataModel.areaText, count);
        
        
        switch (dataModel.choiceProcessing) {
            case viewData: {
                ViewData viewData = { dataModel };
                file.fileProcessing<Birth>(viewData, count, numbers, isRead);
                Table tabel;
                file.fileOutput<Birth>(tabel);
                break;
            }
            case histogram: {
                Histogram histogram;
                file.fileProcessing<Birth>(histogram, count, numbers);
                HistogramViewText view = HistogramViewText(histogram.mouthStat);
                file.fileOutput(view);
                view.output(cout);
                break;
            }
            case birthrate: {
                Birthrate birthrate;
                file.fileProcessing<Birth>(birthrate, count, numbers);
                BirthrateViewText view = BirthrateViewText(birthrate.max, birthrate.indexMax, birthrate.min, birthrate.indexMin);
                file.fileOutput(view);
                view.output(cout);
                break;
            }
            default:
                break;
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


