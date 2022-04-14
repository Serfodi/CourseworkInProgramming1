//
//  main.cpp
//  CourseworkInProgramming26
//
//  Created by Сергей Насыбуллин on 26.03.2022.
//

// Directives
#include <iostream>


// Model
#include "DataModel.hpp"
#include "MaternityHospital.hpp"

// Controller
#include "Menu.hpp"
#include "Processing.hpp"
#include "FileProcessing.hpp"

// Supporting
#include "ClassError.hpp"


// MARK: - main

/// хз куда и как засунуть поэтому тут. Нужен для работы Sex
string Sex::sexText[3] = {"м", "ж", "0"};


using namespace std;


int main() {
    
    // controller
    Menu menu;
    Processing processing;
    
    // data hospital
    Hospital hospital;
    // model Data
    static DataModel dataModel;
    
    
    // MARK: - Обработка файла
    
    try {
        FileProcessing::fillingHospital("/Users/serfodi/File/MaternityHospital.txt", hospital);
        FileProcessing::overwritingBinaryFiles("/Users/serfodi/File/Test/FileDataInfo_1");
    } catch(...) {
        cout << "Ошибка файла";
    }
    
    
//    FileProcessing::readBinaryFile("/Users/serfodi/File/hospitals/1.txt");
//    if (FileProcessing::isRead()) {
//        Birth birth;
//        FileProcessing::readBinary(birth);
//    }
                                   
    
    // MARK: -  Mеню
    
    try {
        menu.openMenu(dataModel);
    } catch (ErrorInput) {
        cout << "Ошибка  ввода";
    } catch (invalid_argument) {
        cout << "Ошибка выхода";
    }
    
    
    // MARK: - Обработка
    
    // передать итератор в функцию обработки
    
    try {
        processing.processing(hospital, dataModel, FileProcessing::readBinaryFile, FileProcessing::readBinary, FileProcessing::isRead, FileProcessing::closeBinaryFile);
    } catch(...) {
        cout << "Ошибка обработки";
    }
        
    return 0;
}


