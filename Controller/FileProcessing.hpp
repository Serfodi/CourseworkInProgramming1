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
    string birthFileName = "Birth";
    /// Файл с результатом
    string resultFileName = "Result";
    /// Расположение записей роддомов файлов
    string hospitalFileName = "Hospital";
    
    string getFileName(string name) const { return name + ".txt"; }
    string getFilePatch(string name) const { return name + "/"; }
    
    
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
    
    
    
    // MARK:  Processing
    
    
    /**
     * Обработка файлов
     *
     * Чтение из бинарных фалов
     *
     * @param[out] processing  Метод обработки, однапроходный алгоритм возврощающий bool
     * @param numbers адреса
     */
    void processing (Processing &processing, const vector<int> &numbers) {
        Birth data;
        for (int i = 0; i < numbers.size(); i++) {
            if (openFile(getFilePatch(hospitalFileName) + to_string(numbers[i]), ios::in)) {
                while (file.read((char*)&data, sizeof(Birth)))
                    processing.processing(data);
                file.close();
            }
        }
    }
    
    
    
    // MARK:  Output
    
    /**
     * Вывод в файл.
     *
     * Открывает файл "res" и записывает в виде viewText
     *
     * @param viewText вид вывода
     */
    void output(ViewText &viewText) {
        openWrite(resultFileName, ios::app);
        viewText.output(write);
        write << endl;
        write.close();
    }
    
    
    
    // MARK:  Remove
    
    
    /// Удаления записи
    void removeBirth(const DeleteProcessing &processing) {
        bool isEmpty = true;
        remove(birthFileName.c_str());
        openWrite(birthFileName);
        for (Birth i : processing.birthData) {
            if (isEmpty) {
                write << i;
                isEmpty = false;
            } else {
                write << endl << i;
            }
        }
        write.close();
    }
    
    
    /// Удаления файлов  госпиталей
    void removeHospitalFile (City &city) {
        const vector<int> n = city.getNumbers(Area::city, cityFileName);
        for (int i = 0; i<n.size(); i++) {
            remove(getFileName(getFilePatch(hospitalFileName) + to_string(n[i])).c_str());
        }
    }
    
    
    
    // MARK: - Работа с файлами
    
private:
    
        
    
    
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
