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
    isWrite,
    /// Удаления данных из текущего файла
    isDelete,
    /// Ничего не делать
    isNon
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
    string fileBirthData = "FileBirth";
    /// Файл с результатом
    string delegateFileName = "Result";
    
    /// Путь к записями Brith tmp
    string tmpFileNamePatch = "tmp/";
    /// Пусть к записям роддомов
    string hospitalFileNamePatch = "hospital/";
    
    /// Даты файлов которые были записаны tmp
    vector<Date> dates;
    
    
    string getFileName(string name) { return name + ".txt"; }
    
    
    // MARK: Методы
public:
    
    
    /**
     * Инициализация базы данных номера госпиталей
     *
     * Читает из файла City названия города и записывает его в city.name.
     * Потом проходит в файл где сохранены Регионы  по пути "названияГорода"
     *
     * @param[out] city  Модель где хранятся данный о госпиталях
     *
     * @warning Указывать путь до папки Data без  '/' в конце.
     */
    void initCity(City &city) {
        city.setName(cityFileName);
        openRead(getFileName(cityFileName));
        while (!read.eof()) city.append(readData<DictionaryRegion>(read));
        read.close();
    }
    
    /**
     * Создает бинарные файлы по номерам для модели Birth
     *
     * Читает из файла и записывает в файла по номерам
     */
    void initData() {
        openRead(getFileName(fileBirthData));
        Birth data;
        while (!read.eof()) {
            data = readData<Birth>(read);
            openFile(getFileName(hospitalFileNamePatch + to_string(data.number)), ios_base::binary | ios::out | ios::app);
            writeFileData(data);
            file.close();
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
    void fileProcessing(Processing &processing, const vector<int> &numbers, Options options = isNon) {
        Birth data;
        for (int i = 0; i < numbers.size(); i++) {
            if (openRead(getFileName(hospitalFileNamePatch + to_string(numbers[i])))) {
                while (read.read((char*)&data, sizeof(Birth))) {
                    if (processing.processing(data)) {
                        switch (options) {
                            case isWrite:
                                if (!findDate(dates, data.dOB)) dates.push_back(data.dOB);
                                writeTmpDateFile(data);
                                break;
                            case isDelete:
                                read.close();
                                deletBirth(data);
                                return;
                            case isNon: break;
                        }
                    }
                }
                read.close();
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
        
        sort(dates.begin(), dates.end());
        unionDataFile();
        
        openFile(getFileName(tmpFileNamePatch + "tmp"), ios::in);
        openWrite(delegateFileName);
        
        tableViewText.tableHeaderViewText(write);
        tableViewText.tableHeaderViewText(cout);
        Birth data;
        while (file.read((char*)&data, sizeof(Birth))) {
            tableViewText.addCell(write, data);
            tableViewText.addCell(cout, data);
        }
        tableViewText.tableFooterViewText(write);
        tableViewText.tableFooterViewText(cout);
        
        write.close();
        file.close();
    }
    
    /**
     * Вывод в файл.
     *
     * Открывает файл "res" и записывает в виде viewText
     *
     * @param viewText выид вывода
     */
    void fileOutput(ViewText &viewText) {
        openWrite(delegateFileName, ios::app);
        viewText.output(write);
        write.close();
    }
    
    
    
    
    // MARK:  Delete
    
    
    
    /// Удаляет файла после завершения
    void deleteFileData(City &city) const {
        const vector<int> n = city.getNumbers(Area::city, "Москва");
        for (int i = 0; i<n.size(); i++) {
            remove(( "hospital/" + to_string(n[i]) + ".txt").c_str());
        }
        remove(tmpFileNamePatch.c_str());
        
        for (int i = 0; i<dates.size(); i++) {
            remove(( tmpFileNamePatch + dates[i].description() + ".txt").c_str());
        }
        remove((tmpFileNamePatch + "tmp.txt").c_str());
    }
    
    
    
    
    
    
    // MARK: - Работа с файлами
    
private:
    
    
    
    // MARK: Вспомогательные методы
    
    void writeTmpDateFile (const Birth &data) {
        openFile(getFileName(tmpFileNamePatch + data.dOB.description()), ios::binary | ios::out | ios::app);
        writeFileData(data);
        file.close();
    }
    
    /// Оледенения даных дат в один
    void unionDataFile() {
        openWrite(getFileName(tmpFileNamePatch + "tmp"), ios::app);
        for (int i = 0; i<dates.size(); i++) {
            openRead(getFileName(tmpFileNamePatch + dates[i].description()));
            Birth birth;
            while(!read.eof()) {
                read.read((char*)&birth, sizeof(Birth));
                writeData(birth);
            }
            read.close();
        }
        write.close();
    }
    
    /// Поиск даты
    bool findDate(vector<Date> dates, Date isFind) {
        for (int i = 0; i<dates.size(); i++)
            if (dates[i] == isFind) return true;
        return false;
    }
    
    
        
        
    // MARK: Удаления
    
    /// Удаления
    void deletBirth(const Birth &data) {
        openRead(getFileName(fileBirthData));
        openWrite(getFileName("tmp" + fileBirthData));
        Birth birth;
        while (!read.eof()) {
            birth = readData<Birth>(read);
            if (birth != data) write << birth;
        }
        read.close();
        write.close();
        remove(getFileName(fileBirthData).c_str());
        rename(getFileName("tmp" + fileBirthData).c_str(), getFileName(fileBirthData).c_str());
    }
    
    
    
    
    // MARK: Открытия файла
    
    /// Открывает поток read ifstream
    bool openRead(string resource, ios_base::openmode __mode = ios::in) {
        read.open(resource, __mode);
        return read.is_open();
    }
    
    /// Открывает поток write ofstream
    bool openWrite(string resource, ios_base::openmode __mode = ios::out) {
        write.open(resource, __mode);
        return read.is_open();
    }
    
    /// Открывает поток file fstream
    bool openFile(string resource, ios_base::openmode __mode) {
        file.open(resource, __mode);
        return read.is_open();
    }
    
    
    
    // MARK:  Чтения
    
    
    /// Читает строчку из потока read
    string readText(ifstream &stream) {
        string text;
        getline(stream, text);
        return text;
    }
    
    /// Читает из потока данные оператором >>
    template <class Type>
    const Type readData(ifstream &in) {
        Type data;
        in >> data;
        return data;
    }
    
    
    
    // MARK:  Запись
    
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


#endif /* FileProcess_hpp */
