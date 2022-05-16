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
    
    string is = "да";
    
    try {
        
        
        // MARK: - Обработка файла
        
        
        file.initCity(city);
        file.initHospital();
        
        
        
        // MARK: -  Mеню
        
        while (is != "нет") {
            
            
            
            menu.open(dataModel);
            
            // 01.01.0001 - 31.12.9999
            
            // MARK: - Обработка
            
            
            switch (dataModel.choiceProcessing) {
                case viewData: {
                    
                    ViewData viewData = { dataModel };
                    file.fileProcessing(viewData, city.getNumbers(dataModel.area, dataModel.areaText), Write);
                    
                    TableViewText tabel = { dataModel };
                    file.fileOutput(tabel);
                    
                    file.removeDateTmpFile();
                    
                    break;
                }
                case histogram: {
                    
                    Histogram histogram = { dataModel };
                    file.fileProcessing(histogram, city.getNumbers(dataModel.area, dataModel.areaText));
                    
                    HistogramViewText view = { histogram, dataModel };
                    file.fileOutput(view);
                    view.output(cout);
                    
                    break;
                    
                }
                case birthrate: {
                    
                    Birthrate birthrate = { dataModel };
                    file.fileProcessing(birthrate, city.getNumbers(dataModel.area, dataModel.areaText));
                    
                    BirthrateViewText view = { birthrate, dataModel };
                    file.fileOutput(view);
                    view.output(cout);
                    
                    break;
                }
                case delet: {
                    
                    Delet delet = { dataModel };
                    file.fileProcessing(delet, city.getNumbers(Area::city), Remove);
                    
                    file.removeHospitalFile(city);
                    file.initHospital();
                    
                    break;
                }
            }
            
            cout << "Продолжить? да нет : ";
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


