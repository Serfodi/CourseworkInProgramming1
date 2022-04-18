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


//
#include "Birth.hpp"

// Supporting
#include "ClassError.hpp"




// MARK: - Внешние определения



using namespace std;

/// Потоки
fstream file;
ifstream read;
ofstream write;


enum Options {
    isRead,
    isDelete,
    isNon
};


/**
 * Работа с файлом
 *
 * Отвечает за чтения и запись. Обработка баз данных
 *
 */
class FileProcessing {
private:
    char sep = '|';
    
public:
    
    
    /**
     * Инициализация базы данных госпиталей
     *
     * @param fromResource пусть к папку Data/City
     * @param city Модель где хранятся данный о госпиталях
     *
     */
    void initCity(string fromResource, City &city) {
        readFile(fromResource+"/City.txt");
        while (!read.eof()) city = City(readText());
        read.close();
        readFile(fromResource + "/" + city.name + ".txt");
        while (!read.eof()) city.append(readRegionFromText(readText()));
        read.close();
    }
    
    
    /**
     * Создает бинарные файлы по номерам для модели Birth
     *
     * Заполнения файлов моделями Birth в бинарном виде
     */
    void initBirth(string fromResource){
        readFile(fromResource);
        while (!read.eof()) {
            Birth birth = readBirthFromText(readText());
            openFileBinary(to_string(birth.number) + ".txt");
            fileData(birth);
            file.close();
        }
        read.close();
    }
    
    
    
    /**
     * Обработка файлов
     *
     * @param processing  Метод обработки
     * @param dataModel  Даные
     * @param city Модель данных
     *
     */
    void fileProcessing(Processing &processing, DataModel &dataModel, City &city, Options options = isNon) {
        
        // Получения всех номеров госпиталей в заданном area
        int count = 0;
        string *numbers = city.getAll(dataModel.area, dataModel.areaText, count);
        
        for (int i = 0; i<count; i++) {
            read.open( numbers[i] + ".txt", ios::binary );
            Birth birth;
            
            // Чтения из файла и запись в протокол
            while ( read.read((char*)&birth, sizeof(Birth)) )
                if ( processing.processing(dataModel, birth))
                    optionsProcessing(birth, options);
                
            read.close();
        }
        delete [] numbers;
    }
    
    
    
    
    
    
    // MARK: - Работа с файлами
private:
    
    
    
    
    
    
    
    // MARK: Открытия файла
    
    
    /// Открывает поток read
    void readFile(string resource) {
        read.open(resource);
        if (!read.is_open()) { throw ErrorFile::errorOpen; }
    }
    
    /// Открывает поток write в режиме: app
    void openWrite(string resource) {
        write.open(resource, ios::app);
        if (!write.is_open()) { throw ErrorFile::errorOpen; }
    }
    
    /// Открывает поток file в режиме: binary,  out, app
    void openFileBinary(string resource) {
        file.open(resource, ios::binary | ios::app | ios::out);
        if (!file.is_open()) { throw ErrorFile::errorOpen; }
    }
    /// Открывает поток file в режиме: binary, in
    void readBinaryFile(string resource) {
        file.open(resource, ios::binary | ios::in);
        if (!file.is_open()) { throw ErrorFile::errorOpen; }
    }
    
    
    
    
    // MARK: Удаления
    
    
    /// Удаления
    void delet(Birth birth) {
        
    }
    
    
    
    // MARK: Вспомогательные методы
    
    
    void optionsProcessing(const Birth &birth, Options options) {
        switch (options) {
            case isRead:
                openFileBinary("res.txt");
                fileData(birth);
                file.close();
                break;
            case isDelete:
                delet(birth);
                break;
            default:
                break;
        }
    }
    
    
    
    // MARK:  Чтения и запись
    
    
    /// Читает строчку из потока read
    string readText() {
        string text;
        getline(read, text);
        return text;
    }
    
    /// Записывает Data в поток write
    template<class Type>
    void writeData(Type data) {
        if (!write.is_open()) { throw ErrorFile::errorOpen; }
        write.write((char*)&data, sizeof(Type));
    }
    
    /// Записывает Data в поток file
    template<class Type>
    void fileData(Type data) {
        if (!file.is_open()) { throw ErrorFile::errorOpen; }
        file.write((char*)&data, sizeof(Type));
    }
    
    
    
    
    /// @brief Приводит строку к Birth
    ///
    /// @param text Строка типа: | Номер роддома |  Дата рожд ребенка | Район | ФИО |  Дата  рожд. матери |  Пол 1 реб. | Пол 2 реб. | Пол 3 реб. |
    /// Разделенная сепаратором
    ///
    /// @see FileProces Data Sex
    ///
    /// @warning Использовать тольк для обработки текста из файла.
    ///
    Birth readBirthFromText (string text) {
        string *components = ExtensionString::componentsSeparatedBy(text, sep , 8);
        int number = stoi(*(components + 0));
        Data dOB = Data(*(components + 1));
        string region = (*(components + 2));
        string fIO = *(components + 3);
        Data dOBMother = Data(*(components + 4));
        SexСhild children;
        for (int i = 0; i < 3; i++)
            children.append(children.sexCast(*(components + i + 5)));
        delete [] components;
        return Birth(number, dOB, region, fIO, dOBMother, children);
    }
    
    
    /**
     *
     *
     *
     */
    Region readRegionFromText(string text) {
        string *components = ExtensionString::componentsSeparatedBy(text, sep, 2);
        string name = components[0];
        int count = ExtensionString::countWords(components[1], ',');
        string *componentsNumber = ExtensionString::componentsSeparatedBy(components[1], ',', count);
        delete [] components;
        return Region(name, componentsNumber, count);
    }
    
    
};


#endif /* FileProcess_hpp */
