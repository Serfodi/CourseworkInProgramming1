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
    isRead,
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
    
    /// Файл с результатом
    string res = "res.txt";
    /// Файла с записями Brith
    string dataRes = "dataRes.txt";
    
public:
    
    /// Разделитель между словами
    static const char sep = '|';
    
    
    
    // MARK: Методы
public:
    
    /**
     * Инициализация базы данных номера госпиталей
     *
     * Читает из файла City названия города и записывает его в city.name.
     * Потом проходит в файл где сохранены Регионы  по пути "названияГорода"
     *
     * @param fromResource пусть к папку Data/City
     * @param[out] city  Модель где хранятся данный о госпиталях
     *
     * @warning Указывать путь до папки Data без  '/' в конце.
     */
    void initCity(string fromResource, City &city) {
        
        openRead(fromResource+"/City.txt");
        while (!read.eof()) city.setName(readText(read));
        read.close();
        
        openRead(fromResource + "/" + city.getName() + ".txt");
        while (!read.eof()) city.append(readStruct<Region>(read));
        read.close();
        
    }
    
    
    /**
     * Создает бинарные файлы по номерам для модели Birth
     *
     * Читает из файла и записывает в файла по номерам
     *
     * @param fromResource пусть к папку со всеми записями рождения
     */
    template<class Type>
    void initData(string fromResource) {
        openRead(fromResource);
        Type data = readStruct<Type>(read);
        while (!read.eof()) {
            data = readStruct<Type>(read);
            openFile(to_string(data.number) + ".txt", ios_base::binary | ios::out);
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
     *
     * @bug При чтения слова со знаком: "-" он читает какую-то фигню
     */
    template<class Type>
    void fileProcessing(Processing &processing, const vector<int> &numbers, Options options = isNon) {
        Type type;
        for (int i = 0; i < numbers.size(); i++) {
            openRead(to_string(numbers[i]) + ".txt");
            while ( read.read((char*)&type, sizeof(Type)) )
                if (processing.processing(type))
                    optionsProcessing(type, options);
            read.close();
        }
    }
    
    
    /**
     * Вывод в файл и в консоль
     *
     * Открывает файл "dataRes" и читает из него. Также записывает в "res" в виде Table.
     *
     * @param tableViewText вид вывода
     */
    template<class Type>
    void fileOutput(Table &tableViewText) {
        openFile(dataRes, ios::in);
        openWrite(res);
        Type data;
        while (file.read((char*)&data, sizeof(Type))) {
            tableViewText.addToTable(write, data);
            tableViewText.addToTable(cout, data);
        }
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
        openWrite(res);
        viewText.output(write);
        write.close();
    }
    
    
    
    
    // MARK: - private Работа с файлами
private:
    
    
    
    // MARK: Открытия файла
    
    /**
     * Открывает поток read ifstream
     *
     * @throws ошибка файла
     */
    void openRead(string resource, ios_base::openmode __mode = ios::in) {
        read.open(resource, __mode);
        if (!read.is_open()) { throw "Error:" + resource; }
    }
    
    /**
     * Открывает поток write ofstream
     *
     * @throws ошибка файла
     */
    void openWrite(string resource, ios_base::openmode __mode = ios::out) {
        write.open(resource, __mode);
        if (!write.is_open()) { throw "Error:" + resource; }
    }
    
    /**
     * Открывает поток file fstream
     *
     * @throws ошибка фалйа
     */
    void openFile(string resource, ios_base::openmode __mode) {
        file.open(resource, __mode);
        if (!file.is_open()) { throw "Error:" + resource; }
    }
    
    
    
        
    // MARK: Вспомогательные методы
    
    template<class Type>
    void optionsProcessing(const Type &data, Options options) {
        switch (options) {
            case isRead:
                openFile(dataRes, ios::binary | ios::out);
                writeFileData(data);
                file.close();
                break;
            case isDelete:
                delet(data);
                break;
            default:
                break;
        }
    }
    
        
        
        
    // MARK: Удаления
    
    /// Удаления
    template <class Type>
    void delet(const Type &data) { }
    
    
        
    
    // MARK: Сортировка
    
    /// Сортировка текущего файла
    void sortedBy(bool (*test)(Data, Data) ) { }
    
    
    
    
    // MARK:  Чтения
    
    /// Читает строчку из потока read
    string readText(ifstream &stream) {
        string text;
        getline(stream, text);
        return text;
    }
    
    /// Читает структуру Region из потока
    template <class Type>
    Type readStruct (ifstream &stream) {
        Type data;
        read >> data;
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



/// Ввод Region
ifstream& operator >> (ifstream &in, Region & region) {
    string line;
    getline(in, region.name, FileProcessing::sep);
    getline(in, line);
    vector<string> componentsNumber = ExtensionString::componentsSeparatedBy(line, ',');
    region.appNumbers(componentsNumber);
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
