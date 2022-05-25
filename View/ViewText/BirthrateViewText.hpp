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
    
    BirthrateProcessing birthrate;
    
    string textData[12] = {
        "Январь", "Февраль", "Март", "Апрель", "Май", "Июнь", "Июль", "Август", "Сентябрь", "Октябрь", "Ноябрь", "Декабрь"
    };
    
public:
    
    BirthrateViewText(const BirthrateProcessing &birthrate, const DataModel &dataModel) : ViewText(dataModel) {
        this -> birthrate = birthrate;
    }
    
    
    void output(ostream &out) override {
        out << endl;
        if (birthrate.min[0] == birthrate.max[0]) {
            out <<
            "Статистика по городу: " << dataModel.areaText + "." << endl <<
            "Искать по: " << attributeText() << endl <<
            "В каждом месяцы было одинаковое кол-во рождений." << endl <<
            "Что составило: " << max(birthrate.min, birthrate.max) << endl;
        } else {
            out <<
            "Статистика по городу: " << dataModel.areaText + "." << endl <<
            "Искать по: " << attributeText() << endl <<
            "Максимальное кол-во рождений в " << textData[birthrate.max[1]] << endl
            << "Что составило: " << birthrate.max[0] << endl;
            out << "Минимальное кол-во рождений: " << textData[birthrate.min[1]] << endl
            << "Что составило: " << birthrate.min[0] << endl;
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
