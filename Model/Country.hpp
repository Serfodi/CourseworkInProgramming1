//
//  Country.hpp
//  CourseworkInProgramming26
//
//  Created by Сергей Насыбуллин on 07.04.2022.
//

#ifndef Country_hpp
#define Country_hpp


/// Абстрактный класс Страны
class Country {
public:
    /// Имя
    string name;
    /// Кол-во вхождений
    int count;
    
    ~Country() {}
    
};




// MARK: - Region

/**
 * Регион
 *
 * Входит в состав Города City class
 */
struct Region: Country {
    
    // MARK: Свойства
private:
    
    /// Номера роддомов
    int *numbers;
    
    
    // MARK: Конструкторы
public:

    Region() {}
    
    /**
     * @Warning Выделения памяти должно происходит снаружи
     */
    Region(string nameRegion, int* numbers, int countNumbers) {
        name = nameRegion;
        count = countNumbers;
        this -> numbers = numbers;
    }
    
    
    
    // Перегрузки
    
    /// Доступ к numbers по индексу
    int operator [] (int index) { return numbers[index]; }
    
    /// Сравнения имён
    bool operator == (Region second){ return name == second.name; }
    
    /// ввод
    friend ifstream& operator >> (ifstream&, Region&);
    
    
    
    // Методы
    
    /// Возвращает номера роддомов
    int* const allNumbers() const  { return numbers; }
    
    /// Возвращает кол-во роддомов
    const int allCount() const  { return count; }
    
    /// Устанавливает значения для массива numbers
    void setNumbers(string *numbers) {
        for (int i=0; i<count; i++) {
            this -> numbers[i] = stoi(numbers[i]);
        }
    }
    
    
    ~Region() { }
    
    
};



// MARK: - City


/// Город
struct City: Country {
    
    // MARK: Свойства
private:
    
    /// Регионы в городе
    Region *regions;

    
    // MARK: Конструкторы
public:
    
    City () {}
    
    /// Создания по имени
    City(string nameCity) {
        this -> name = nameCity;
        regions = nullptr;
        count = 0;
    }
    
    
    
    //    Перегрузки
    
    /// Сравнения имён
    bool operator == (City second){ return name == second.name; }
    
    
    
    // MARK: Методы
    
    /// Добавляет новый элемент в конец regions
    void append(Region newElement) {
        count += 1;
        Region *citiesNew = new Region[count]();
        for (int i = 0; i<count-1; i++) citiesNew[i] = regions[i];
        delete [] regions;
        citiesNew[count-1] = newElement;
        regions = citiesNew;
    }
    
    
    /**
     * Вывод региона по слову. Как в словарике
     *
     * @throws ошибка поиска
     */
    const Region findRegion (string region) const {
        for (int i = 0; i < count; i++)
            if (regions[i].name == region)
                return regions[i];
        return Region();
    }
    
    
    /**
     * Обработка выдачи номера роддомов
     *
     * Логика выдачи по area
     *
     * @param area Место поиска
     * @param areaText Адрес поиска
     * @param[out] forCount передача по адресу кол-во роддомов
     *
     * @return Динамический массив string номеров роддомов
     */
    int* getAll(Area area, string areaText, int &forCount) const {
        int *numbers = nullptr;
        switch (area) {
            case city:
                forCount = allCount();
                numbers = allNumbers();
                break;
            case region:
                forCount = findRegion(areaText).allCount();
                numbers = findRegion(areaText).allNumbers();
                break;
            case hospital:
                forCount = 1;
                numbers = new int[forCount];
                numbers[0] = stoi(areaText);
                break;
        }
        return numbers;
    }
    
    
    /// Возвращает кол-во всех роддомов
    const int allCount() const  {
        int countNumber = 0;
        for (int i=0; i<count; i++) {
            countNumber += regions[i].count;
        }
        return countNumber;
    }
    
    
    /// Возвращает номера роддомов всех вхождений
    int* const allNumbers() const {
        int *numbers = new int[allCount()];
        int now = 0;
        for (int i=0; i<count; i++) {
            for (int j=0; j < regions[i].count ; j++) {
                numbers[now++] = regions[i][j];
            }
        }
        return numbers;
    }
    
    
    
    
    ~City() {
        delete [] regions;
    }
    
    
    
};



#endif /* Hospital_hpp */
