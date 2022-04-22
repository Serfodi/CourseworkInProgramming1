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
    
    int maxCount;
    int maxMouth;
    int minCount;
    int minMouth;
    
    string textData[12] = {
        "Январь", "Февраль", "Март", "Апрель", "Май", "Июнь", "Июль", "Август", "Сентябрь", "Октяборь", "Нояборь", "Декабарь"
    };
    
public:
    
    BirthrateViewText(int maxCount, int maxMouth, int minCount, int minMouth) {
        this -> maxCount = maxCount;
        this -> maxMouth = maxMouth;
        this -> minCount = minCount;
        this -> minMouth = minMouth;
    }
    
    void output(ostream &out) override {
        if (maxCount == minCount) {
            out << "В каждом месецы было одинаковое кол-во рождений." << endl
            << "Что составило: " << max(maxCount, minCount);
        } else {
            out << "Максимальное кол-во рождений: " << textData[maxMouth -1 ] << endl
            << "Что составило: " << maxCount << endl;
            out << "Минимальное кол-во рождений: " << textData[minMouth -1] << endl
            << "Что составило: " << minCount << endl;
        }
    }
    
    
    
    ~BirthrateViewText() {}
    
    
};

#endif /* BirthrateViewText_hpp */
