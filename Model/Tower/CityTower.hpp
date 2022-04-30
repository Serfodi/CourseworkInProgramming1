//
//  CityTower.hpp
//  CourseworkInProgramming26
//
//  Created by Сергей Насыбуллин on 25.04.2022.
//

#ifndef CityTower_hpp
#define CityTower_hpp


/// Город
class City: public Tower {
    
    
    
    // MARK: Свойства
private:
    
    /// Регионы в городе
    vector<Region> regions;
    
    
    // MARK: Конструкторы
public:
    
    City () {}
    
    
    
    // MARK: Перегрузки
    
    /// Сравнения имён
    bool operator == (City second){ return name == second.name; }
    
    /// Доступ к regions по индексу
    Region operator [] (int index) { return regions[index]; }
    
    
    
    // MARK: Методы
    
    /// Устанавливает имя
    void setName(string name) {
        this -> name = name;
    }
    
    /// Возвращает имя
    const string getName() const {
        return name;
    }
    
    /// Добавляет новый элемент в конец regions
    void append(Region newElement) {
        regions.push_back(newElement);
    }
    
    /**
     * Вывод региона по слову. Как в словарике
     *
     * @return Указатель на Region. Если не нашел то вернут nullptr.
     */
    const Region* find(string region) const {
        for (int i = 0; i < region.size(); i++)
            if (regions[i].name == region)
                return &regions[i];
        return nullptr;
    }
    
    /**
     * Обработка выдачи номера роддомов
     *
     * Логика выдачи по area
     *
     * @param area Место поиска
     * @param areaText Адрес поиска
     *
     * @return Вектор массив string номеров роддомов
     */
    vector<int> getAll(Area area, string areaText, vector<int> numbers) const {
        switch (area) {
            case city:
                return binaryAnd(numbers, allNumbers());
            case region:
                return binaryAnd(numbers, find(areaText) -> allNumbers());
            case hospital:
                return vector<int>(1, stoi(areaText));
        }
    }
    
    
    /// Возвращает номера роддомов
    const vector<int> allNumbers() const override {
        vector<int> numbers;
        for (int i=0; i < regions.size(); i++) {
            for (int j=0; j < regions[i].numbers.size(); j++) {
                numbers.push_back(regions[i].numbers[j]);
            }
        }
        return numbers;
    }
    
private:
    
    vector<int> binaryAnd (vector<int> one, vector<int> two) const {
        if (one == two) return one;
        vector<int> numbers;
        for (int i=0; i<one.size(); i++) {
            for (int j=0; j<two.size(); j++) {
                if (one[i] == two[j]) {
                    numbers.push_back(one[i]);
                }
            }
        }
        return numbers;
    }
    
    
    
};

#endif /* CityTower_hpp */
