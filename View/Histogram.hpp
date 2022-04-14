//
//  Histogram.hpp
//  CourseworkInProgramming26
//
//  Created by Сергей Насыбуллин on 05.04.2022.
//

#ifndef Histogram_hpp
#define Histogram_hpp

#include <stdio.h>
#include <iomanip>


using namespace std;


/// Вывод гистограммы рождаемости
class Histogram {
    
    /// Поинт вывода
    string bricks ="#";
    
public:
    
    /**
     * Вывод гистограммы рождаемости по месяцам года
     *
     * @param mouth Кол-во рождений в каждом месяце
     */
    void histogram(int mouth[13]) {
        
        // максимальный элимент – это будет высота гистограммы (max + 1)
        int max = 0;
        for (int i = 1; i<13; i++)
            if (max < mouth[i])
                max = mouth[i];
        
        // Вывод строчек
        
        cout << "Вывод гистрограммы рождаемости:" << endl;
        cout << "     |-------------------------" << endl;
        
        for (int i=0; i < (max + 1); i++) {
            int count = (max + 1) - i;
            bool *avail = availability(count, mouth);
            cout << setw(4) << count << " | " << histogramString(count, avail) << endl;
        }
        
        cout << "     |-------------------------" << endl;
        cout << "     | я ф м а м и и а с о н д " << endl;
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
    bool* availability(int count, int mouth[13]) {
        bool *array = new bool[13];
        for (int i=1; i<13; i++)
            array[i] = count <= mouth[i];
        return array;
    }
    
};

#endif /* Histogram_hpp */
