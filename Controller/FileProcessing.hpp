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


/// Потоки
fstream file;
ifstream read;
ofstream write;


/// Работа с фалом.
///
/// Открытия файла. Чтение из файла и записи в файл.
class FileProcessing {
public:
    
    /// Заполняет Hospital из файла
    static void fillingHospital(string fromResource, Hospital &hospital) {
        openFileRead(fromResource);
        while (!read.eof())
            hospital.append(City(readTextFile()));
        read.close();
    }
    
    /// Чтения из файла Brith и запись в бинарный файл
    static void overwritingBinaryFiles(string fromResource){
        openFileRead(fromResource);
        while (!read.eof()) {
            Birth birth = Birth(readTextFile());
            openBinaryFile(to_string(birth.number) + ".txt");
            writeBinary(birth);
            file.close();
        }
        read.close();
    }
    
    
    /// Создает бинарный файл
    static void readBinaryFile(string resource) {
        file.open(resource, ios::binary | ios::in);
        if (!file.is_open()) { throw ErrorFile::errorOpen; }
    }
    
    
    /// Закрывает текущий файла
    static void closeBinaryFile() {
        file.close();
    }
    
    /// Читает из текущего бинарного файла
    static void readBinary(Birth &data) {
        file.read((char*)&data, sizeof(Birth));
    }
    
    static bool isRead(){
        return !file.eof();
    }
    
    
private:
    
    /// Создает бинарный файл
    static void openBinaryFile(string resource) {
        file.open(resource, ios::binary | ios::app | ios::out);
        if (!file.is_open()) { throw ErrorFile::errorOpen; }
    }
    
    /**
     * @brief Открывает файл для чтения
     * @param resource файл
     * @throws ErrorFile::errorOpen Если не смог открыть
     */
    static void openFileRead(string resource) {
        read.open(resource);
        if (!read.is_open()) { throw ErrorFile::errorOpen; }
    }
    
    /// Читает текст из ifstream текущего файла
    static string readTextFile() {
        string text;
        getline(read, text);
        return text;
    }
    
    
    
    /// Записывает в текущего бинарного файла
    template<class Type>
    static void writeBinary(Type data) {
        if (!file.is_open()) { throw ErrorFile::errorOpen; }
        file.write((char*)&data, sizeof(data));
    }
    
    
};


#endif /* FileProcess_hpp */
