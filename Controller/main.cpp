//
//  main.cpp
//  CourseworkInProgramming26
//
//  Created by Сергей Насыбуллин on 26.03.2022.
//

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

// Supporting
#include "ClassError.hpp"
#include "ExtensionString.hpp"
#include "ChoiceMenu.hpp"

// Model
#include "Date.hpp"
#include "Sex.hpp"
#include "Birth.hpp"
#include "DataModel.hpp"
#include "Tower.hpp"

// View
#include "Menu.hpp"
#include "ViewText.hpp"

// Controller
#include "Processing.hpp"
#include "FileProcessing.hpp"


using namespace std;


int main() {
    
    setlocale(LC_ALL, "ru");
    
    
    // model Data
    DataModel dataModel;
    City city;
    
    FileProcessing file;
    
    Menu menu;
    
    
    // MARK: - Обработка файла
    
    
    try {
        
        file.initCity("/Users/serfodi/Data/City", city);
        
        file.initData<Birth>("/Users/serfodi/Test/FileDataInfo_2.txt");
        
    } catch(string n) {
        cout << "Ошибка файла !!!!!!!!! " << n << endl;
    }
    
    
    
    // MARK: -  Mеню
    
    try {
        
        menu.openMenu(dataModel);
        
    } catch(...) {
        cout << "Ошибка ввода!!!!!" << endl;
    }
    
    
    
//      31, 12, 9999
    
    
    // MARK: - Обработка
    
    try {
        
        // Получения всех номеров госпиталей в заданном area
        vector<int> numbers = city.getAll(dataModel.area, dataModel.areaText, dataModel.numbers);
        
        
        switch (dataModel.choiceProcessing) {
            case viewData: {
                ViewData viewData = { dataModel };
                file.fileProcessing<Birth>(viewData, numbers, isRead);
                Table tabel;
                file.fileOutput<Birth>(tabel);
                break;
            }
            case histogram: {
                Histogram histogram = { dataModel };
                file.fileProcessing<Birth>(histogram, numbers);
                HistogramViewText view = HistogramViewText(histogram.mouthStat);
                file.fileOutput(view);
                view.output(cout);
                break;
            }
            case birthrate: {
                Birthrate birthrate = { dataModel };
                file.fileProcessing<Birth>(birthrate, numbers);
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


