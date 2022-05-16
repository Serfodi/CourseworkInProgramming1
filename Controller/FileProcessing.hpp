//
//  FileProcess.hpp
//  CourseworkInProgramming26
//
//  Created by Сергей Насыбуллин on 26.03.2022.
//

/**
 * @file Работа с файлом. Открытия файла, открытия бинарного, чтения и запись бинарного файла.
 */


// MARK: - Подключенные файла


#ifndef FileProces_hpp
#define FileProces_hpp


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
    Write,
    /// Удаления данных из текущего файла
    Remove,
    /// Ничего не делать
    No
};



/**
 * Работа с файлом
 *
 * Отвечает за чтения и запись.
 * Обработка баз данных.
 */
class FileProcessing {
    
    // MARK: Свойства
private:
    
    /// Расположение регионов
    string cityFileName = "Москва";
    /// Расположение записей о рождении
    string birthFileName = "FileBirth";
    /// Файл с результатом
    string resultFileName = "Result";
    /// Расположение временных файлов
    string tmpFileName = "tmp";
    /// Расположение записей роддомов файлов
    string hospitalFileName = "hospital";
    
    /// Даты файлов которые были записаны tmp
    vector<Date> dates;
    
    string getFileName(string name) const { return name + ".txt"; }
    string getFilePatch(string name) const { return name + "/"; }
    
    
    // MARK: Методы
public:
    
    /**
     * Инициализация базы данных номера госпиталей
     *
     * @param[out] city  Модель где хранятся данный о госпиталях
     */
    void initCity(City &city) const {
        city.setName(cityFileName);
        openRead(cityFileName);
        while (!read.eof()) {
            DictionaryRegion dictionaryRegion;
            read >> dictionaryRegion;
            city.append(dictionaryRegion);
        }
        read.close();
    }
    
    
    /// Создает бинарные файлы по номерам для модели Birth
    void initHospital() {
        openRead(birthFileName);
        Birth data;
        while (!read.eof()) {
            read >> data;
            openWrite(getFilePatch(hospitalFileName) + to_string(data.number), ios::binary | ios::app);
            write.write((char*)&data, sizeof(Birth));
            write.close();
        }
        read.close();
    }
    
    
    /**
     * Обработка файлов
     *
     * @param[out] processing  Метод обработки, однапроходный алгоритм возврощающий bool
     * @param numbers адреса
     * @param options опции обработки. Если processing вернул true
     */
    void fileProcessing(Processing &processing, const vector<int> &numbers, Options options = No) {
        Birth data;
        for (int i = 0; i < numbers.size(); i++) {
            if (openFile(getFilePatch(hospitalFileName) + to_string(numbers[i]), ios::in)) {
                while (file.read((char*)&data, sizeof(Birth))) {
                    if (processing.processing(data)) {
                        switch (options) {
                            case Write:
                                if (!binary_search(dates.begin(), dates.end(), data.dOB)) {
                                    dates.push_back(data.dOB);
                                    sort(dates.begin(), dates.end());
                                }
                                openWrite(getFilePatch(tmpFileName) + data.dOB.description(), ios::binary | ios::app);
                                write.write((char*)&data, sizeof(Birth));
                                write.close();
                                break;
                            case Remove:
                                file.close();
                                removeBirth(data);
                                return;
                            case No: break;
                        }
                    }
                }
                file.close();
            }
        }
    }
    
    
    
    // MARK:  Output
    
    
    /**
     * Вывод в файл и в консоль
     *
     * Открывает файл "dataRes" и читает из него. Также записывает в "res" в виде Table.
     *
     * @param tableViewText вид вывода
     */
    void fileOutput(TableViewText &tableViewText) {
        unionDataFile();
        
        openRead(getFilePatch(tmpFileName) + tmpFileName);
        openWrite(resultFileName, ios::app);
        
        tableViewText.tableHeaderViewText(write);
        tableViewText.tableHeaderViewText(cout);
        Birth data;
        while (read.read((char*)&data, sizeof(Birth))) {
            tableViewText.addCell(write, data);
            tableViewText.addCell(cout, data);
        }
        tableViewText.tableFooterViewText(write);
        tableViewText.tableFooterViewText(cout);
        
        write.close();
        read.close();
    }
    
    /**
     * Вывод в файл.
     *
     * Открывает файл "res" и записывает в виде viewText
     *
     * @param viewText выид вывода
     */
    void fileOutput(ViewText &viewText) {
        openWrite(resultFileName, ios::app);
        viewText.output(write);
        write << endl;
        write.close();
    }
    
    
    
    
    // MARK:  Delete
    
    
    
    /// Удаления файлов дат
    void removeDateTmpFile() {
        for (int i = 0; i < dates.size(); i++) {
            remove(getFileName(getFilePatch(tmpFileName) + dates[i].description()).c_str());
        }
        remove(getFileName(getFilePatch(tmpFileName) + tmpFileName).c_str());
        dates.clear();
    }
    
    /// Удаления файлов  госпиталей
    void removeHospitalFile (City &city) const {
        const vector<int> n = city.getNumbers(Area::city, cityFileName);
        for (int i = 0; i<n.size(); i++) {
            remove(getFileName(getFilePatch(hospitalFileName) + to_string(n[i])).c_str());
        }
        remove(tmpFileName.c_str());
    }
    
    
    
    // MARK: - Работа с файлами
    
private:
    
    
    
    // MARK: Вспомогательные методы
    
    
    /// Слияния файлов в дат в один
    void unionDataFile() {
        openWrite(getFilePatch(tmpFileName) + tmpFileName, ios::app | ios::binary);
        for (int i = 0; i<dates.size(); i++) {
            openRead(getFilePatch(tmpFileName) + dates[i].description(), ios::binary);
            Birth birth;
            while(read.read((char*)&birth, sizeof(Birth))) {
                write.write((char*)&birth, sizeof(Birth));
            }
            read.close();
        }
        write.close();
    }
    
    
        
    // MARK: Удаления
    
    /// Удаления
    void removeBirth(const Birth &data) {
        openRead(birthFileName);
        openWrite(tmpFileName + birthFileName);
        Birth birth;
        while (!read.eof()) {
            read >> birth;
            if (birth != data) {
                if (!write.eof()) write << endl;
                write << birth;
            }
            
        }
        read.close();
        write.close();
        remove(birthFileName.c_str());
        rename(getFileName(tmpFileName + birthFileName).c_str(), getFileName(birthFileName).c_str());
    }
    
    
    
    
    // MARK: Открытия файла
    
    /// Открывает поток read ifstream
    void openRead(string resource, ios_base::openmode __mode = ios::in) const {
        read.open(getFileName(resource), __mode);
        if (!read.is_open()) { throw ("Ошибка открытия файла: " + resource); }
    }
    
    /// Открывает поток write ofstream
    void openWrite(string resource, ios_base::openmode __mode = ios::out) const {
        write.open(getFileName(resource), __mode);
        if (!write.is_open()) { throw ("Ошибка открытия файла: " + resource); }
    }
    
    /// Открывает поток file fstream
    bool openFile(string resource, ios_base::openmode __mode) const {
        file.open(getFileName(resource), __mode);
        return file.is_open();
    }
    
};


#endif /* FileProcess_hpp */
