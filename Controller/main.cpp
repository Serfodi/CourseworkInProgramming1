//
//  main.cpp
//  CourseworkInProgramming26
//
//  Created by Сергей Насыбуллин on 26.03.2022.
//


#include <iostream>
#include <exception>
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
#include "Сhildren.hpp"
#include "Birth.hpp"
#include "DataModel.hpp"
#include "City.hpp"
#include "Processing.hpp"

// View
#include "Menu.hpp"
#include "ViewText.hpp"

// Controller
#include "FileProcessing.hpp"



int main() {
    
    
    setlocale(LC_ALL, "ru");
    
    
    FileProcessing file;
    City city;
    Menu menu;
    DataModel dataModel;
    
    
    string is = "1";
    
    
    try {
        
        // MARK: - Обработка файла
        
        
        file.initCity(city);
        file.initHospital();
        
        
        
        // MARK: -  Mеню
        
        while (is != "0") {
            
            
            menu.open(dataModel, city);
            
            
            // MARK: - Обработка
            
            
            switch (dataModel.choiceProcessing) {
                case viewBirth: {
                    
                    ViewBirthProcessing processing = { dataModel };
                    vector<int> numbers = city.getNumbers(dataModel.area, dataModel.areaText);
                    file.processing(processing, numbers);
                    TableViewText view = {&processing, dataModel};
                    view.output(cout);
                    file.output(view);
                    break;
                }
                case histogram: {
                    
                    HistogramProcessing processing = { dataModel };
                    vector<int> numbers = city.getNumbers(dataModel.area, dataModel.areaText);
                    file.processing(processing, numbers);
                    HistogramViewText view = { processing, dataModel };
                    file.output(view);
                    view.output(cout);
                    break;
                    
                }
                case birthrate: {
                    
                    BirthrateProcessing processing = { dataModel };
                    vector<int> numbers = city.getNumbers(dataModel.area, dataModel.areaText);
                    file.processing(processing, numbers);
                    BirthrateViewText view = { processing, dataModel };
                    file.output(view);
                    view.output(cout);
                    break;
                }
                case removeBirth: {
                    
                    DeleteProcessing processing = { dataModel };
                    vector<int> numbers = city.getNumbers(Area::city);
                    file.processing(processing, numbers);
                    file.removeBirth(processing);
                    DeleteViewText view = {processing, dataModel };
                    file.output(view);
                    view.output(cout);
                    break;
                }
            }
            cout << "Продолжить? 1 0 : ";
            getline(cin, is);
            menu.clearTab();
        }
    }
    catch(OpenFileError error) {
        cout << error.text << endl;
    }
    catch(...) {
        cout << endl << "Неизвестная ошибка!" << endl;
    }
    
    
    file.removeHospitalFile(city);
    
    
    return 0;
}


