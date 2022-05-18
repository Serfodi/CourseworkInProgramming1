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

#include <cstdlib>

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
    DataModel dataModel;
    Menu menu;
    
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
                    file.processing(processing, city.getNumbers(dataModel.area, dataModel.areaText));
                    TableViewText view = {processing, dataModel};
                    file.output(view);
                    view.output(cout);
                    
                    break;
                }
                case histogram: {
                    
                    HistogramProcessing processing = { dataModel };
                    file.processing(processing, city.getNumbers(dataModel.area, dataModel.areaText));
                    HistogramViewText view = { processing, dataModel };
                    file.output(view);
                    view.output(cout);
                    
                    break;
                    
                }
                case birthrate: {
                    
                    BirthrateProcessing processing = { dataModel };
                    file.processing(processing, city.getNumbers(dataModel.area, dataModel.areaText));
                    BirthrateViewText view = { processing, dataModel };
                    file.output(view);
                    view.output(cout);
                    
                    break;
                }
                case removeBirth: {
                    
                    DeleteProcessing processing = { dataModel };
                    file.processing(processing, city.getNumbers(Area::city));
                    DeleteViewText view = { dataModel };
                    file.output(view);
                    view.output(cout);
                    
                    file.removeBirth(processing);
                    file.removeHospitalFile(city);
                    file.initHospital();
                    
                    break;
                }
            }
            
            
            cout << "Продолжить? 1 0 : ";
            getline(cin, is);
            
        }
        
        
        
    }
    catch(string n) {
        cout << n << endl;
    }
    catch (out_of_range) {
        cout << endl << "Ошибка выход за приделы!" << endl;
    }
    catch (invalid_argument) {
        cout << endl << "Ошибка ввода данных!" << endl;
    }
    catch(...) {
        cout << endl << "Неизвестная ошибка!" << endl;
    }
    
    
    file.removeHospitalFile(city);
    
    
    return 0;
}


