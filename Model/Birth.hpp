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
    Date dOB;
    /// Район
    string region;
    /// Фио матери
    string fIO;
    /// Дата рождения матери
    Date dOBMother;
    /// Дети
    SexСhild children;
    
    
    
    // MARK:  Инициализаторы
    
    Birth() {}
    
    Birth (int number, Date dOB, string region, string fIO, Date dOBMother, SexСhild children) {
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
    Birth(string fIO, Date data) {
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
    bool operator != (Birth second) const {
        return !(fIO == second.fIO && dOBMother == second.dOBMother);
    }
    
    /// Сравнивает ФИО и ДатуРожденияМатери
    bool operator == (Birth second) const {
        return (fIO == second.fIO && dOBMother == second.dOBMother);
    }
    
    friend ifstream& operator >> (ifstream &, Birth &);
    
    /// Возвращяет массив строк
    vector<string> getDescription () {
        vector<string> description = {
            ExtensionString::leading(number, 2, ' '),
            dOB.description(),
            region,
            fIO,
            dOBMother.description(),
            SexCast::toString(children[0]),
            SexCast::toString(children[1]),
            SexCast::toString(children[2])
        };
        return description;
    }
    
    
    ~Birth() {}
    
};


/// Ввод Birth
ifstream& operator >> (ifstream &in, Birth &birth) {
    string line;
    
    char sep = '|';
    
    getline(in, line, sep);
    
    if (line == "") { return in; }
    
    birth.number = stoi(line);
    
    getline(in, line, sep);
    birth.dOB = Date(line);
    
    getline(in, birth.region, sep);
    getline(in, birth.fIO, sep);
    
    getline(in, line, sep);
    birth.dOBMother = Date(line);
    
    SexСhild children;
    
    for (int i = 0; i < 2; i++) {
        getline(in, line, sep);
        children.append(SexCast::toSexEnum(line));
    }
    
    getline(in, line);
    children.append(SexCast::toSexEnum(line));
    birth.children = children;
    
    return in;
}

ostream& operator << (ostream &out, const Birth& birth) {
    out
    << birth.number << "|"
    << birth.dOB << "|"
    << birth.region << "|"
    << birth.fIO << "|"
    << birth.dOBMother << "|"
    << SexCast::toStringRus(birth.children[0]) << "|"
    << SexCast::toStringRus(birth.children[1]) << "|"
    << SexCast::toStringRus(birth.children[2]);
    return out;
}


#endif /* ModelBirth_hpp */
