//
//  main.cpp
//  CourseworkInProgramming26
//
//  Created by Сергей Насыбуллин on 26.03.2022.
//

#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <vector>

using namespace std;

// Supporting
#include "ClassError.hpp"
#include "ExtensionString.hpp"
#include "ChoiceMenu.hpp"

// Model
#include "Date.hpp"
#include "Sex.hpp"
#include "Birth.hpp"
#include "DataModel.hpp"
#include "City.hpp"

// View
#include "Menu.hpp"
#include "ViewText.hpp"

// Controller
#include "Processing.hpp"
#include "FileProcessing.hpp"




int main() {
    
    setlocale(LC_ALL, "ru");
    
    
    // model Data
    DataModel dataModel;
    City city;
    FileProcessing file;
    Menu menu;
    
    
    
    try {
        
        // MARK: - Обработка файла
        
        file.initCity("/Users/serfodi/Data/City", city);
        file.initData<Birth>("/Users/serfodi/Test/FileDataInfo_Rand.txt");
        
        
        
        // MARK: -  Mеню
        
        menu.openMenu(dataModel);
        
        
        //    01.01.0001 - 01.01.9999
        
        // MARK: - Обработка
        
        
        
        // Получения всех номеров госпиталей в заданном area
        vector<int> numbers = city.getNumbers(dataModel.area, dataModel.areaText);
        
        
        switch (dataModel.choiceProcessing) {
            case viewData: {
                
                ViewData viewData = { dataModel };
                file.fileProcessing<Birth>(viewData, numbers, isRead);
                
                Table tabel = { 100 };
                file.fileOutput<Birth>(tabel);
                
                break;
            }
            case histogram: {
                Histogram histogram = { dataModel };
                file.fileProcessing<Birth>(histogram, numbers);
                HistogramViewText view = HistogramViewText(histogram.mouthStat, dataModel.attribute);
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
            case delet: {
                
                
                
                break;
            }
        }
        
        
    }
    catch(string n) {
        cout << "Ошибка файла !!!!!!!!! " << n << endl;
    }
    catch(...) {
        cout << "Ошибка ввода!!!!!" << endl;
    }
    
    file.deleteFileData(city);
    
    return 0;
}


