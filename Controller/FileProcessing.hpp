//
//  FileProcess.hpp
//  CourseworkInProgramming26
//
//  Created by Сергей Насыбуллин on 26.03.2022.
//

/**
 * @file Работа с файлом. Открытия файла, открытия бинарного, чтения и запись бинарного файла.
 *  Логика ввода тут
 */


// MARK: - Подключенные файла


#ifndef FileProces_hpp
#define FileProces_hpp

#include <stdio.h>
#include <fstream>

// Supporting
#include "ClassError.hpp"





// MARK: - Внешние определения



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
    
    /// Заполняет City из файла
    ///
    /// @param fromResource деректива где хранятся город и регионы этого города
    ///
    void initCity(string fromResource, City &city) {
        
        readFile(fromResource+"/City.txt");
        while (!read.eof()) city = City(readText());
        read.close();
        
        readFile(fromResource + "/" + city.getName() + ".txt");
        while (!read.eof()) city.append(Region(readText()));
        read.close();
        
    }
    
    /// Чтения из файла Brith и запись в бинарный файл
    ///
    /// @param fromResource Полный путь для файла где находятся данные о рождении
    ///
    void initBirth(string fromResource){
        readFile(fromResource);
        while (!read.eof()) {
            Birth birth = Birth(readText());
            writeBinaryFile(to_string(birth.number) + ".txt");
            writeBinaryData(birth);
            file.close();
        }
        read.close();
    }
    
    
    /// Чтения из бинарного файла  по индексу
    template<class Type>
    Type operator [](int index) {
        file.seekg(index * sizeof(Birth), ios::beg);
        return readBinaryData<Type>();
    }
    
    
    template<class Type>
    Type get(string resource, int index) {
        readBinaryFile(resource);
        file.seekg(index * sizeof(Birth), ios::beg);
        return readBinaryData<Type>();
        file.close();
    }
    
    
    void fileProcessing(Processing &processing, DataModel &dataModel) {
        file.open("res.txt", ios::out);
        
        int count = 1;
        string *numbers = nullptr;
        
        for (int i = 0; i<count; i++) {
            
            string url = numbers[i] + ".txt";
            read.open(url, ios::binary);
            
            Birth birth;
            while ( read.read((char*)&birth, sizeof(Birth)) )
                if ( processing.processing(dataModel, birth) )
                    file << birth.description();
            
            read.close();
        }
        file.close();
    }
    
    
    // MARK: - Методы
private:
    
    
    string getURL() {
        return "";
    }
    
    
    // MARK: - Работа с файлами
    
    
    
    
    // MARK: Открытия файлов
    
    /// Открывает обычный файла для чтения
    void readFile(string resource) {
        read.open(resource);
        if (!read.is_open()) { throw ErrorFile::errorOpen; }
    }
    /// Открывает поток write для записи. ios::App
    void writeFile(string resource) {
        write.open(resource, ios::app);
        if (!write.is_open()) { throw ErrorFile::errorOpen; }
    }
    
    /// Открывает бинарный файл для записи
    void writeBinaryFile(string resource) {
        file.open(resource, ios::binary | ios::app | ios::out);
        if (!file.is_open()) { throw ErrorFile::errorOpen; }
    }
    /// Открывает бинарный файл для чтения
    void readBinaryFile(string resource) {
        file.open(resource, ios::binary | ios::in);
        if (!file.is_open()) { throw ErrorFile::errorOpen; }
    }
    
    
    
    // MARK: Чтения и запись
    
    /// Читает текст из ifstream текущего файла
    string readText() {
        string text;
        getline(read, text);
        return text;
    }
    
    /// Запись в поток write
    template<class Type>
    void writeData(Type data) {
        if (!write.is_open()) { throw ErrorFile::errorOpen; }
        write.write((char*)&data, sizeof(Type));
    }
    
    /// Записывает в текущего бинарного файла
    template<class Type>
    void writeBinaryData(Type data) {
        if (!file.is_open()) { throw ErrorFile::errorOpen; }
        file.write((char*)&data, sizeof(Type));
    }
    
    /// Чтение из текущего бинарного файла
    template<class Type>
    Type readBinaryData() {
        if (!file.is_open()) { throw ErrorFile::errorOpen; }
        Type data;
        file.read((char*)&data, sizeof(Type));
        return data;
    }
    
};


#endif /* FileProcess_hpp */
