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
#include "HistogramView.hpp"
#include "Table.hpp"

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
        file.initBirth("/Users/serfodi/Test/FileDataInfo_3.txt");
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
                Table tabel;
                file.fileProcessing(viewData, dataModel, city, isRead);
                file.fileOutputTabel(tabel);
                
                break;
            }
            case histogram: {
                Histogram histogram;
                HistogramView view;
                file.fileProcessing(histogram, dataModel, city);
                file.fileOutputHistogram(histogram, view);
                view.output(cout, histogram);
                break;
            }
            case birthrate: {
                Birthrate birthrate;
                file.fileProcessing(birthrate, dataModel, city);
                break;
            }
            case delet: {
                Delet delet;
                dataModel.areaText = city.name;
                file.fileProcessing(delet, dataModel, city, isDelete);
                
                break;
            }
        }
        
        
    } catch(...) {
        cout << "Ошибка обработки";
    }
    
    
    
    return 0;
}


