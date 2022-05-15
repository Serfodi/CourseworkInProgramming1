//
//  BirthrateViewText.hpp
//  CourseworkInProgramming26
//
//  Created by Сергей Насыбуллин on 22.04.2022.
//

#ifndef BirthrateViewText_hpp
#define BirthrateViewText_hpp


class BirthrateViewText: public ViewText {
private:
    
    Attribute attribute;
    string area;
    
    int maxCount;
    int maxMouth;
    int minCount;
    int minMouth;
    
    string textData[12] = {
        "Январь", "Февраль", "Март", "Апрель", "Май", "Июнь", "Июль", "Август", "Сентябрь", "Октяборь", "Нояборь", "Декабарь"
    };
    
public:
    
    BirthrateViewText(int maxCount, int maxMouth, int minCount, int minMouth, Attribute attribute, string area) {
        this -> maxCount = maxCount;
        this -> maxMouth = maxMouth;
        this -> minCount = minCount;
        this -> minMouth = minMouth;
        this -> attribute = attribute;
        this -> area = area;
    }
    
    void output(ostream &out) override {
        if (maxCount == minCount) {
            
            out <<
            "Статистика по городу" << area + "." << endl <<
            "Искать по: " << attributeText() << endl <<
            "В каждом месяцы было одинаковое кол-во рождений." << endl <<
            "Что составило: " << max(maxCount, minCount);
            
        } else {
            
            out <<
            "Статистика по городу" << area + "." << endl <<
            "Искать по: " << attributeText() << endl <<
            "Максимальное кол-во рождений: " << textData[maxMouth -1 ] << endl
            << "Что составило: " << maxCount << endl;
            out << "Минимальное кол-во рождений: " << textData[minMouth -1] << endl
            << "Что составило: " << minCount << endl;
            
        }
    }
    
    
private:
    /// Выводит текст по attribute
    string attributeText() {
        switch (attribute) {
            case general:
                return "Общая рождаемость.";
            case boys:
                return "Только мальчики.";
            case girls:
                return "Только девочки.";
            case multiple:
                return "Многодетные родители.";
        }
    }
    
    
};

#endif /* BirthrateViewText_hpp */
