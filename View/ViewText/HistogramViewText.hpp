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
private:
    
    HistogramProcessing histogram;
    
    /// Поинт вывода
    string bricks ="#";
    
public:
    
    HistogramViewText(const HistogramProcessing &histogram, const DataModel &dataModel) : ViewText(dataModel) {
        this -> histogram = histogram;
    }
    
    /**
     * Вывод гистограммы рождаемости по месяцам года
     *
     * @param out поток ostream
     */
    void output(ostream &out) override {
        
        // максимальный элемент – это будет высота гистограммы (max + 1)
        int max = 0;
        for (int i = 0; i<12; i++)
            if (max < histogram.mouth[i])
                max = histogram.mouth[i];
        
        // Вывод строчек
        
        // Шапка
        out << "Вывод гистрограммы рождаемости: " << attributeText() << endl;
        out << "По городу: " << dataModel.area << endl;
        out << "     |-------------------------|" << endl;
        for (int i=0; i < (max + 1); i++) {
            int count = (max + 1) - i;
            bool *avail = availability(count, histogram.mouth);
            // Вывод строчки histogramString
            out << setw(4) << count << " | " << histogramString(count, avail) << "|" << endl;
            delete [] avail;
        }
        // Подвал
        out << "     |-------------------------|" << endl;
        out << "     | я ф м а м и и а с о н д |" << endl;
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
    string histogramString(int count, bool availability[12]) {
        string s;
        for (int i=0; i<12; i++) {
            s += availability[i] ? bricks : " ";
            s += " ";
        }
        return s;
    }
    
    /// Просматривает есть ли рождаемость на заданном кол-во
    bool* availability(int count, const int mouth[12]) {
        bool *array = new bool[13];
        for (int i=0; i<12; i++)
            array[i] = count <= mouth[i];
        return array;
    }
    
};

#endif /* HistogramViewText_hpp */
