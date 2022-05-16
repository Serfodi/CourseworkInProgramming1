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
    
    Birthrate birthrate;
    
    string textData[12] = {
        "Январь", "Февраль", "Март", "Апрель", "Май", "Июнь", "Июль", "Август", "Сентябрь", "Октяборь", "Нояборь", "Декабарь"
    };
    
public:
    
    
    BirthrateViewText(const Birthrate &birthrate, const DataModel &dataModel) {
        this -> birthrate = birthrate;
        this -> dataModel = dataModel;
    }
    
    
    void output(ostream &out) override {
        if (birthrate.min == birthrate.max) {
            
            out <<
            "Статистика по городу" << dataModel.areaText + "." << endl <<
            "Искать по: " << attributeText() << endl <<
            "В каждом месяцы было одинаковое кол-во рождений." << endl <<
            "Что составило: " << max(birthrate.min, birthrate.max) << endl;
            
        } else {
            
            out <<
            "Статистика по городу" << dataModel.areaText + "." << endl <<
            "Искать по: " << attributeText() << endl <<
            "Максимальное кол-во рождений: " << textData[birthrate.indexMax -1 ] << endl
            << "Что составило: " << birthrate.max << endl;
            out << "Минимальное кол-во рождений: " << textData[birthrate.indexMin -1] << endl
            << "Что составило: " << birthrate.min << endl;
            
        }
    }
    
    
private:
    /// Выводит текст по attribute
    string attributeText() {
        switch (dataModel.attribute) {
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
