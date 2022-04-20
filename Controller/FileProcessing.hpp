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

#include "Birth.hpp"

// Supporting
#include "ClassError.hpp"
#include "HistogramView.hpp"
#include "Table.hpp"

using namespace std;


// Потоки

/// Двух-сторонний
fstream file;
/// Чтение
ifstream read;
/// Запись
ofstream write;


/// Выбор опций для обработки
enum Options {
    /// Запись данных в файла
    isRead,
    /// Удаления данных из текущего файла
    isDelete,
    /// Ничего не делать
    isNon
};


/**
 * Работа с файлом
 *
 * Отвечает за чтения и запись. Обработка баз данных
 */
class FileProcessing {
    
    // MARK: Свойства
private:
    
    /// Разделитель между словами
    const char sep = '|';
public:
    
    /// Символ обозначения ребенка
    ///
    /// Массив из 3 элементов обозначающие пол ребенка
    string sexChar[3] = {"м", "ж", "0"};
    
    
    
    // MARK: Методы обработки файлов
    
    
    /**
     * Инициализация базы данных госпиталей
     *
     * Читает из файла City названия города и записывает его в city.name.
     * Потом проходит в файл где хоронятся Регионы  по пути "названияГорода"
     *
     * @param fromResource пусть к папку Data/City
     * @param[out] city  Модель где хранятся данный о госпиталях
     *
     * @warning Указывать путь до папки Data без  '/' в конце.
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
    void initBirth(string fromResource) {
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
     * Получает номера роддомов и читает их проверяя по условию.
     * Выполняет Options если true иначе ни чего не делает.
     *
     * @param[out] processing  Метод обработки, однапроходный алгоритм возврощающий bool
     * @param dataModel  Данные пользователя выведенных с клавиатуры
     * @param city Модель данных
     */
    void fileProcessing(Processing &processing, const DataModel &dataModel, const City &city, Options options = isNon) {
        
        // Получения всех номеров госпиталей в заданном area
        int count = 0;
        string *numbers = city.getAll(dataModel.area, dataModel.areaText, count);
        
        for (int i = 0; i<count; i++) {
            read.open( numbers[i] + ".txt", ios::binary );
            
            // Чтения из файла и обработка
            Birth birth;
            while ( read.read((char*)&birth, sizeof(Birth)) )
                if ( processing.processing(dataModel, birth))
                    optionsProcessing(birth, options);
                
            read.close();
        }
        delete [] numbers;
    }
    
    
    void fileOutputHistogram(Histogram processing, HistogramView &histogramView) {
        openWrite("protocol.txt");
        histogramView.output(write, processing);
        write.close();
    }
    
    void fileOutputTabel(Table &table) {
        openWrite("protocol.txt");
//        openFileBinary("res.txt");
        
        file.open("res.txt", ios::in);
        
        table.printTable(write);
        Birth birth;
        while (file.read((char*)&birth, sizeof(Birth))) {
            table.addToTable(write, birth);
        }
        file.close();
        write.close();
    }
    
    
    // MARK: - private Работа с файлами
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
    void delet(const Birth &birth) {
        
    }
    
    
    
    // MARK: Сортировка
    
    
    /// Сортировка текущего файла
    void sortedBy(bool (*test)(Data, Data) ) {
        
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
            children.append(SexСhild::sexCast( *(components + i + 5), sexChar) );
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

//ifstream& operator >> (ostream &out, Birth &birth) { return }



#endif /* FileProcess_hpp */
