//
//  City.hpp
//  CourseworkInProgramming26
//
//  Created by Сергей Насыбуллин on 25.04.2022.
//

#ifndef City_hpp
#define City_hpp


/// Словарь для региона
using DictionaryRegion = map<string, vector<int>>;


/// Город
class City {
    
    /// имя
    string name;
    /// Регионы в городе
    DictionaryRegion regions = {};
    
public:
    
    City () {}
    
    /// Возвращает имя города
    const string getName() const { return name; }
    /// Устанавливает имя города
    void setName(string name) { this -> name = name; }
    
    /// Добавляет новый элемент в конец regions
    void append(DictionaryRegion region) {
        DictionaryRegion::iterator it = region.begin();
        regions[it->first] = it->second;
    }
    
    /// Возвращает региона по слову. Как в словарике
    const vector<int> find(string region) { return regions[region]; }
    
    /// Возвращает кол-во регионов в городе
    long int getCount() const { return regions.size(); }
    
    
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
    vector<int> getNumbers(Area area, string areaText = "") {
        switch (area) {
            case city:
                if (areaText == name) {
                    return allNumbers();
                }
            case region:
                return regions[areaText];
            case hospital:
                return vector<int>(1, stoi(areaText));
        }
    }
    
    /// Выдает все регионы в городе
    vector<string> getAllRegionName() {
        vector<string> name;
        DictionaryRegion::iterator reg;
        for (reg = regions.begin(); reg != regions.end(); reg++)
            name.push_back(reg -> first);
        return name;
    }
    
    /// Выдает все номера в городе
    vector<string> getAllNumberName() {
        vector<string> name;
        DictionaryRegion::iterator reg;
        for (reg = regions.begin(); reg != regions.end(); reg++) {
            string text = "";
            for (int i : reg -> second)
                text += to_string(i) + ", ";
            name.push_back(text);
        }
        return name;
    }
    
    
private:
    
    /// Возвращает номера всех роддомов входящие в город
    vector<int> allNumbers() {
        vector<int> numbers;
        DictionaryRegion::iterator it = regions.begin();
        for (int i = 0; it != regions.end(); it++, i++)
            numbers.insert(numbers.end(), (it -> second).begin(), (it -> second).end());
        return numbers;
    }
    
};


ifstream& operator >> (ifstream &in, DictionaryRegion &region) {
    
    string name;
    getline(in, name, '|');
    
    string text;
    getline(in, text);
    
    vector<string> numbersText = ExtensionString::componentsSeparatedBy(text, ',');
    vector<int> numbers;
    for (int i = 0; i<numbersText.size(); i++)
        numbers.push_back(stoi(numbersText[i]));
    region[name] = numbers;
    
    return in;
}


#endif /* City_hpp */
