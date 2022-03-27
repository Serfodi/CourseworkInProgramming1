//
//  FileProcess.hpp
//  CourseworkInProgramming26
//
//  Created by Сергей Насыбуллин on 26.03.2022.
//

#ifndef FileProc_hpp
#define FileProc_hpp

#include <stdio.h>

//#include <iostream>
#include <fstream>

//#include "Input.hpp"
#include "ClassError.hpp"


using namespace std;
ofstream writeText;
ifstream readText;

/**
 Класс FileProc отвечает за открытия файла и записи в него.
 */
class FileProc {
public:
    void openFile(string resource) {
        readText.open(resource);
        if (!readText.is_open()) { throw ErrorFile::errorOpen; }
    }
    
    /**
     Считывает по одной строчки из потока ifstream readText
     */
    string getText() {
        if (readText.eof()) {
            return "";
        }
        string line;
        getline(readText, line);
        return line;
    }
    
    
    
};


#endif /* FileProcess_hpp */
