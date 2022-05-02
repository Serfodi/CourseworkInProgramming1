//
//  RegionTower.hpp
//  CourseworkInProgramming26
//
//  Created by Сергей Насыбуллин on 25.04.2022.
//

#ifndef RegionTower_hpp
#define RegionTower_hpp

/**
 * Регион
 *
 * Входит в состав Города City class
 */
struct Region: public Tower {
public:
    
    
    
    // MARK: Свойства
    
    /// Номера роддомов*
    vector<int> numbers;
    
    
    
    // MARK: Конструкторы
    
    Region() {}
    
    Region(string name, vector<int> numbers) {
        this -> name = name;
        this -> numbers = numbers;
    }
    
    
    
    // MARK: Перегрузки
    
    /// Доступ к numbers по индексу
    int operator [] (int index) const { return numbers[index]; }
    
    /// Сравнения имён
    bool operator == (Region second){ return name == second.name; }
    
    /// ввод
    friend ifstream& operator >> (ifstream&, Region&);
    
    
    
    // MARK: Методы
    
    /// Возвращает номера роддомов
    const vector<int> allNumbers() const override { return numbers; }
    
    
    /// Возвращает кол-во роддомов
    long int allCount() const  { return numbers.size(); }
    
    
    /// Устанавливает значения для массива numbers
    /// @param numbers массив из строк чисел.
    void appNumbers(vector<string> numbers) {
        for (int i=0; i < numbers.size(); i++)
            this -> numbers.push_back(stoi(numbers[i]));
    }
  
    
    
};

#endif /* RegionTower_hpp */
