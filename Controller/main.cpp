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
        
        file.initCity(city);
        file.initData();
        
        
        
        // MARK: -  Mеню
        
        menu.openMenu(dataModel);
        
        
        //    01.01.0001 - 01.01.9999
        
        // MARK: - Обработка
        
        
        
        // Получения всех номеров госпиталей в заданном area
        
        switch (dataModel.choiceProcessing) {
            case viewData: {
                
                ViewData viewData = { dataModel };
                vector<int> numbers = city.getNumbers(dataModel.area, dataModel.areaText);
                file.fileProcessing(viewData, numbers, isWrite);
                
                TableViewText tabel;
                file.fileOutput(tabel);
                
                break;
            }
            case histogram: {
                
                Histogram histogram = { dataModel };
                vector<int> numbers = city.getNumbers(dataModel.area, dataModel.areaText);
                file.fileProcessing(histogram, numbers);
                
                HistogramViewText view = HistogramViewText(histogram.mouthStat, dataModel.attribute, dataModel.areaText);
                
                file.fileOutput(view);
                view.output(cout);
                
                break;
                
            }
            case birthrate: {
                
                Birthrate birthrate = { dataModel };
                vector<int> numbers = city.getNumbers(dataModel.area, dataModel.areaText);
                file.fileProcessing(birthrate, numbers);
                
                BirthrateViewText view = BirthrateViewText(birthrate.max, birthrate.indexMax, birthrate.min, birthrate.indexMin, dataModel.attribute, dataModel.areaText);
                
                file.fileOutput(view);
                view.output(cout);
                
                break;
            }
            case delet: {
                                
                Delet delet = { dataModel };
                file.fileProcessing(delet, city.getNumbers(Area::city), isDelete);
                
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


