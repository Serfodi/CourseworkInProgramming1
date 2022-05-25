//
//  Input.hpp
//  CourseworkInProgramming26
//
//  Created by Сергей Насыбуллин on 26.03.2022.
//

/**
 * @file Ввод данных с клавиатуры
 * Все что связанно с вводом в консоль
 */

#ifndef Input_hpp
#define Input_hpp


/**
 * Отвечает за ввод данных их обработку из консоли или из файла.
 *
 * Содержит логику обработки и формирования данных из консоли.
 */
class Input {
public:
    
    /**
     * Ввод с клавиатуры  целого числа int
     *
     * @note Преобразуют строчку к int с помощью функции stoi. Из-за того что в буфере при нажатии на enter остается "\0" пришлось использовать этот метод.
     */
    static int number() {
        string textNumber = text();
        int number;
        number = stoi(textNumber);
        return number;
    }
    
    /// Ввод с клавиатуры текста string
    static string text() {
        string text;
        getline(cin, text);
        return text;
    }
    
    
    /**
     * Приводит строчку к Data
     *
     * @param dataText  Строка в формате "дд.мм.гггг" или "дд.мм.гггг - дд.мм.гггг"
     * @param format Формат преобразования к одной дате или интервалу
     *
     * @return массив из одной или двух дат зависит от Data format
     *
     * @throws DateError
     */
    static const vector<Date> dateCast (string dataText, DataFormat format) {
        vector<Date> data(format+1);
        
        if (dataText == "all") {
            vector<Date> data;
            data.push_back(Date(0, 0, 0));
            data.push_back(Date(31, 12, 9999));
            return data;
        }
        
        switch (format) {
            case day:
                data[0] = Date(dataText);
                break;
            case interval:
                vector<string> components = ExtensionString::componentsSeparatedBy(dataText, '-');
                for (int i=0; i < format + 1 ; i++) data[i] = Date(components[i]);
                break;
        }
        return data;
    }

    
    
    // MARK:  Cast to enum ChoiceMenu
    
    /**
     * @brief Приводит число к перечислению ChoiceProcessing
     * @param number  Целое число от 1 до 4
     * @throws ошибка ввода
     */
    static ChoiceProcessing choiceProcessingCast(int number) {
        if (number > 4 || number < 1) { throw InputError("choiceProcessing"); }
        return static_cast<ChoiceProcessing>(number-1);
    }
    
    /**
     * @brief Приводит число к перечислению Area
     * @param number  Целое число от 1 до 3
     * @throws ошибка ввода
     */
    static Area areaCast(int number) {
        if (number > 3 || number < 1) { throw InputError("areaCast"); }
        return static_cast<Area>(number-1);
    }
    
    /**
     * @brief Приводит число к перечислению DataFormat
     * @param number  Целое число от 1 до 2
     * @throws ошибка ввода
     */
    static DataFormat dataFormatCast(int number) {
        if (number > 2 || number < 1) { throw InputError("dataFormatCast"); }
        return static_cast<DataFormat>(number-1);
    }
    
    /**
     * @brief Приводит число к перечислению Birthrate
     * @param number  Целое число от 1 до 4
     * @throws ошибка ввода
     */
    static Attribute attributeCast(int number) {
        if (number > 4 || number < 1) { throw InputError("attributeCast"); }
        return static_cast<Attribute>(number-1);
    }
    
};


#endif /* Input_hpp */
