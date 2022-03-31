//
//  FileProcess.hpp
//  CourseworkInProgramming26
//
//  Created by Сергей Насыбуллин on 26.03.2022.
//

/**
 * @file Работа с файлом
 */

#ifndef FileProces_hpp
#define FileProces_hpp

#include <stdio.h>

#include <iostream>
#include <fstream>


#include "ClassError.hpp"


using namespace std;

ofstream writeFile;
ifstream readFile;


/// Открытия файла. Чтение из файла и записи в файл.
class FileProces {
public:
    static const char separator = '|';
    
    /**
     * @brief Открывает файл
     * @param resource Место нахождения файла
     * @throws ErrorFile::errorOpen
     */
    void openFileRead(string resource) {
        readFile.open(resource);
        if (!readFile.is_open()) { throw ErrorFile::errorOpen; }
    }
    
    void openFileWrite() {}
    
    /// Читает строчку из потока файла
    /// @todo eof для провекри возможности чтения
    string readText() {
        string line;
        getline(readFile, line);
        return line;
    }
    
    void writeText(string text) {}
    
};


#endif /* FileProcess_hpp */
