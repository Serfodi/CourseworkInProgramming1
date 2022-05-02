//
//  HistogramViewText.hpp
//  CourseworkInProgramming26
//
//  Created by Сергей Насыбуллин on 22.04.2022.
//

#ifndef HistogramViewText_hpp
#define HistogramViewText_hpp


/// Вывод гистограммы рождаемости
class HistogramViewText: public ViewText {
    
    int mouthStat[13];
    
    Attribute attribute;
    
    /// Поинт вывода
    string bricks ="#";
    
public:
    
    HistogramViewText(int mouthStat[13], Attribute attribute) {
        this -> attribute = attribute;
        for (int i=0; i<13; i++)
            this -> mouthStat[i] = mouthStat[i];
    }
    
    /**
     * Вывод гистограммы рождаемости по месяцам года
     *
     * @param out поток ostream
     */
    void output(ostream &out) override {
        
        // максимальный элимент – это будет высота гистограммы (max + 1)
        int max = 0;
        for (int i = 1; i<13; i++)
            if (max < mouthStat[i])
                max = mouthStat[i];
        
        // Вывод строчек
        
        // Шапка
        out << "Вывод гистрограммы рождаемости: " << attribute << endl;
        out << "     |-------------------------|" << endl;
        
        for (int i=0; i < (max + 1); i++) {
            int count = (max + 1) - i;
            bool *avail = availability(count, mouthStat);
            
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
    
    
public:  ~HistogramViewText() {}
    
};

#endif /* HistogramViewText_hpp */
