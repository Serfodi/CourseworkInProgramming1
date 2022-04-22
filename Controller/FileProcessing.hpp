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
#include "ViewText.hpp"
#include "TableViewText.hpp"

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
private:
    /// Файл с результатом
    string res = "res.txt";
    /// Файла с записями Brith
    string dataRes = "dataRes.txt";
    
    
    // MARK: Свойства
public:
    
    /// Разделитель между словами
    static const char sep = '|';
    
    
    
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
        
        openRead(fromResource+"/City.txt");
        while (!read.eof()) city = City(readText());
        read.close();
        
        openRead(fromResource + "/" + city.name + ".txt");
        Region region;
        while (!read.eof()) {
            read >> region;
            city.append(region);
        }
        read.close();
    }
    
    
    
    /**
     * Создает бинарные файлы по номерам для модели Birth
     *
     * Заполнения файлов моделями Birth в бинарном виде
     */
    void initBirth(string fromResource) {
        openRead(fromResource);
        Birth birth;
        while (!read.eof()) {
            read >> birth;
            openFile(to_string(birth.number) + ".txt", ios_base::binary | ios::out);
            writeFileData(birth);
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
     * @param count кол-во роддомов
     * @param numbers номера роддомов
     */
    void fileProcessing(Processing &processing, int count, int *numbers, Options options = isNon) {
        Birth birth;
        for (int i = 0; i<count; i++) {
            openRead(to_string(numbers[i]) + ".txt", ios::binary);
            while ( read.read((char*)&birth, sizeof(Birth)) )
                if ( processing.processing(birth))
                    optionsProcessing(birth, options);
            read.close();
        }
    }
    
    /// Выводит таблицу в файла результата
    void fileTableOutput(Table tableViewText) {
        openFile(dataRes, ios::in);
        openWrite(res);
        Birth birth;
        while (file.read((char*)&birth, sizeof(Birth))) writeData(birth);
        write.close();
        file.close();
    }
    
    ///  Вывод текста в файл
    void fileOutput(ViewText viewText) {
        openWrite(res);
//        viewText
        write.close();
    }
    
    
    
    
    
    
    
    
    // MARK: - private Работа с файлами
private:
    
    
    
    // MARK: Открытия файла
    
    
    /// Открывает поток read
    void openRead(string resource, ios_base::openmode __mode = ios::in) {
        read.open(resource, __mode);
        if (!read.is_open()) { throw ErrorFile::errorOpen; }
    }
    
    /// Открывает поток write в режиме: app
    void openWrite(string resource, ios_base::openmode __mode = ios::out) {
        write.open(resource, __mode);
        if (!write.is_open()) { throw ErrorFile::errorOpen; }
    }
    
    void openFile(string resource, ios_base::openmode __mode) {
        file.open(resource, __mode);
        if (!file.is_open()) { throw ErrorFile::errorOpen; }
    }
    
    
    
        
    // MARK: Вспомогательные методы
    
    
    void optionsProcessing(const Birth &birth, Options options) {
        switch (options) {
            case isRead:
                openFile(dataRes, ios::binary | ios::out);
                writeFileData(birth);
                file.close();
                break;
            case isDelete:
                delet(birth);
                break;
            default:
                break;
        }
    }
    
        
        
        
    // MARK: Удаления
    
    
        
    /// Удаления
    void delet(const Birth &birth) { }
    
    
        
    
    // MARK: Сортировка
    
    
        
    /// Сортировка текущего файла
    void sortedBy(bool (*test)(Data, Data) ) { }
    
    
    
    
    // MARK:  Чтения и запись
    
    
    /// Читает строчку из потока read
    string readText() {
        string text;
        getline(read, text);
        return text;
    }
    
    /// Записывает Data в поток write
    template <class Type>
    void writeData(Type data) {
        if (!write.is_open()) { throw ErrorFile::errorOpen; }
        write.write((char*)&data, sizeof(Type));
    }
    
    /// Записывает Data в поток file
    template <class Type>
    void writeFileData(Type data) {
        if (!file.is_open()) { throw ErrorFile::errorOpen; }
        file.write((char*)&data, sizeof(Type));
    }
    
};



/// Ввод Region
ifstream& operator >> (ifstream &in, Region & region) {
    string line;
    getline(in, region.name, FileProcessing::sep);
    getline(in, line);
    int count = ExtensionString::countWords(line, ',');
    string *componentsNumber = ExtensionString::componentsSeparatedBy(line, ',', count);
    region.setNumbers(componentsNumber);
    delete [] componentsNumber;
    return in;
}



/// Ввод Birth
ifstream& operator >> (ifstream &in, Birth &birth) {
    string line;
    
    getline(in, line, FileProcessing::sep);
    birth.number = stoi(line);
    
    getline(in, line, FileProcessing::sep);
    birth.dOB = Data(line);
    
    getline(in, birth.region, FileProcessing::sep);
    getline(in, birth.fIO, FileProcessing::sep);
    
    getline(in, line, FileProcessing::sep);
    birth.dOBMother = Data(line);
    
    SexСhild children;
    for (int i = 0; i < 2; i++) {
        getline(in, line, FileProcessing::sep);
        children.append(SexСhild::sexCast(line));
    }
    getline(in, line);
    children.append(SexСhild::sexCast(line));
    birth.children = children;
    
    return in;
}




#endif /* FileProcess_hpp */
