//
//  Birth.hpp
//  CourseworkInProgramming26
//
//  Created by Сергей Насыбуллин on 26.03.2022.
//

/**
 * @file Описания модели Birth
 */

#ifndef Birth_hpp
#define Birth_hpp



using namespace std;


/// Модель данных о рождении детей.
struct Birth {
    
    // MARK:  Свойства
public:
    
    /// Номер роддома
    int number;
    /// Дата рождения ребенка
    Data dOB;
    /// Район
    string region;
    /// Фио матери
    string fIO;
    /// Дата рождения матери
    Data dOBMother;
    /// Дети
    SexСhild children;
    
    
    
    // MARK:  Инициализаторы
    
    Birth() {}
    
    Birth (int number, Data dOB, string region, string fIO, Data dOBMother, SexСhild children) {
        this -> number = number;
        this -> dOB = dOB;
        this -> region = region;
        this -> fIO = fIO;
        this -> dOBMother = dOBMother;
        this -> children = children;
    }
    
    /**
     * Заполняет только ФИО и Дату рождения матери
     *
     * Используется для поиска
     */
    Birth(string fIO, Data data) {
        this -> fIO = fIO;
        this -> dOBMother = data;
    }
    
    
    
    // MARK:  Перегрузки
    
    
    Birth& operator = (const Birth &second) {
        number = second.number;
        dOB = second.dOB;
        region = second.region;
        fIO = second.fIO;
        dOBMother = second.dOBMother;
        children = second.children;
        return *this;
    }
    
    /// Сравнивает ФИО и ДатуРожденияМатери
    bool operator != (Birth second) const { return !(fIO == second.fIO && dOBMother == second.dOBMother); }
    /// Сравнивает ФИО и ДатуРожденияМатери
    bool operator == (Birth second) const { return (fIO == second.fIO && dOBMother == second.dOBMother); }
    
    friend ifstream& operator >> (ifstream &, Birth &);
    
    
    
    /// Вывод описания
    string description() const {
        std::string text;
        text += std::to_string(number) + "\n";
        text += dOB.description() + "\n";
        text += region + "\n";
        text += fIO + "\n";
        text += dOBMother.description() + "\n";
        for (int i = 0; i < 3; i++) text += std::to_string(children[i]) + " ";
        text += "\n";
        return text;
    }
    
    
    ~Birth() {}
    
};



#endif /* ModelBirth_hpp */
