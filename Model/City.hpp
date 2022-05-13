//
//  City.hpp
//  CourseworkInProgramming26
//
//  Created by Сергей Насыбуллин on 25.04.2022.
//

#ifndef City_hpp
#define City_hpp



using DictionaryRegion = map<string, vector<int>>;


/// Город
class City {
private:
    
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
    vector<int> getNumbers(Area area, string areaText) {
        switch (area) {
            case city:
                return allNumbers();
            case region:
                return regions[areaText];
            case hospital:
                return vector<int>(1, stoi(areaText));
        }
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
        numbers.push_back( stoi(numbersText[i]));
    region[name] = numbers;
    
    return in;
}


#endif /* City_hpp */
