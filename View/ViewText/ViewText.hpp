//
//  ViewText.hpp
//  CourseworkInProgramming26
//
//  Created by Сергей Насыбуллин on 20.04.2022.
//

#ifndef ViewText_hpp
#define ViewText_hpp

#include <stdio.h>
#include <fstream>


#include "string"
#include "Birth.hpp"
#include "Processing.hpp"


class ViewText {
    
    void output(ostream &out) {}
    
};





/// Вывод гистограммы рождаемости
class HistogramView {
    
    /// Поинт вывода
    string bricks ="#";
    
public:
    
    /**
     * Вывод гистограммы рождаемости по месяцам года
     *
     * @param histogram обарботка Гистограммы
     * @param out поток ostream
     */
    void output(ostream &out, const Histogram &histogram) {
        
        // максимальный элимент – это будет высота гистограммы (max + 1)
        int max = 0;
        for (int i = 1; i<13; i++)
            if (max < histogram.mouthStat[i])
                max = histogram.mouthStat[i];
        
        // Вывод строчек
        
        // Шапка
        out << "Вывод гистрограммы рождаемости:" << endl;
        out << "     |-------------------------|" << endl;
        
        for (int i=0; i < (max + 1); i++) {
            int count = (max + 1) - i;
            bool *avail = availability(count, histogram.mouthStat);
            
            // Вывод строчки histogramString
            out << setw(4) << count << " | " << histogramString(count, avail) << "|" << endl;
            
            delete [] avail;
        }
        
        // Подвал
        out << "     |-------------------------|" << endl;
        out << "     | я ф м а м и и а с о н д |" << endl;
        
    }
    
    
private:
    
    /// Выводит строчку
    ///
    /// Собирает строчку для вывода гистрограмы сверху вниз.
    ///
    /// Формат: месеца года 1 - 12
    ///
    /// кол-во | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10 | 11 | 12 |
    ///
    /// @param count кол-во обозначает слева
    ///
    string histogramString(int count, bool availability[13]) {
        string s;
        for (int i=1; i<13; i++) {
            s += availability[i] ? bricks : " ";
            s += " ";
        }
        return s;
    }
    
    /// Просматривает есть ли рождаемость на заданном кол-во
    bool* availability(int count, const int mouth[13]) {
        bool *array = new bool[13];
        for (int i=1; i<13; i++)
            array[i] = count <= mouth[i];
        return array;
    }
    
};

/*

class ViewTextBirthrate {
    
    string textData[12] = {
        "Январь", "Февраль", "Март", "Апрель", "Май", "Июнь", "Июль", "Август", "Сентябрь", "Октяборь", "Нояборь", "Декабарь"
    };
    
    void mouth(int mouthMax, int mouthMin, int numberMax, int numberMin) {
        cout << "Максимальное кол-во рождений: " << textData[mouthMax-1] << endl
        << "Что составило: " << numberMax << endl;
        cout << "Минимальное кол-во рождений: " << textData[mouthMin-1] << endl
        << "Что составило: " << numberMin << endl;
    }

    void mouthEqule(int number) {
        cout << "В каждом месецы было одинаковое кол-во рождений." << endl
        << "Что составило: " << number;
    }
    
};
*/


#endif /* ViewText_hpp */
