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
#include <fstream>

// Supporting
#include "ClassError.hpp"


using namespace std;


/// Поток чтения.
ifstream readFile;


/// Работа с фалом.
///
/// Открытия файла. Чтение из файла и записи в файл.
class FileProces {
public:
    
//    /// Разделитель
//    ///
//    /// Строка разделена этим разделителем
//    static const char separator = '|';
    
    /**
     * @brief Открывает файл
     * @param resource файл
     * @throws ErrorFile::errorOpen Если не смог открыть
     */
    void openFileRead(string resource) {
        readFile.open(resource);
        if (!readFile.is_open()) { throw ErrorFile::errorOpen; }
    }
    
    /// Читает строчку из потока файла
    string readText() {
        string line;
        getline(readFile, line);
        return line;
    }
    
};


#endif /* FileProcess_hpp */
