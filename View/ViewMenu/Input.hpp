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


using namespace std;


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
    int number() {
        string textNumber = text();
        int number;
        number = stoi(textNumber);
        return number;
    }
    
    
    /// Ввод с клавиатуры текста string
    string text() {
        string text;
        getline(cin, text);
        return text;
    }
    
    
    /**
     * Приводит строчку к Data
     *
     * Память выделяется внутри
     *
     * @param dataText  Строка в формате "дд.мм.гггг" или "дд.мм.гггг - дд.мм.гггг"
     * @param format Формат преобразования к одной дате или интервалу
     *
     * @return Динамический массив из одной или двух дат зависит от Data format
     *
     * @throws
     *
     * @Warning Память выделяется внутри
     */
    Data * const dataCast (string dataText, DataFormat format) const {
        if (dataText == "") { throw ErrorInput::incorrectData; }
        
        Data *data = new Data[format+1]; // Вопрос на засыпку: где выделать память?
        
        switch (format) {
            case day:
                data[0] = Data(dataText);
                break;
            case interval:
                string *components = ExtensionString::componentsSeparatedBy(dataText, '-', format + 1);
                for (int i=0; i < format + 1 ; i++) {
                    data[i] = Data(*(components + i));
                }
                delete [] components;
                break;
        }
        return data;
    }

    
    
    
    
    // MARK:  Cast to enum ChoiceMenu
    
    /**
     * @brief Приводит число к перечислению ChoiceProcessing
     * @param number  Целое число от 1 до 4
     * @throws
     */
    ChoiceProcessing choiceProcessingCast(int number) {
        if (number > 4 || number < 1) { throw ErrorInput::outOfIndex; }
        return static_cast<ChoiceProcessing>(number-1);
    }
    
    /**
     * @brief Приводит число к перечислению Area
     * @param number  Целое число от 1 до 3
     * @throws
     */
    Area areaCast(int number) {
        if (number > 3 || number < 1) { throw ErrorInput::outOfIndex; }
        return static_cast<Area>(number-1);
    }
    
    /**
     * @brief Приводит число к перечислению DataFormat
     * @param number  Целое число от 1 до 2
     * @throws
     */
    DataFormat dataFormatCast(int number) {
        if (number > 2 || number < 1) { throw ErrorInput::outOfIndex; }
        return static_cast<DataFormat>(number-1);
    }
    
    /**
     * @brief Приводит число к перечислению Birthrate
     * @param number  Целое число от 1 до 4
     * @throws
     */
    Attribute attributeCast(int number) {
        if (number > 4 || number < 1) { throw ErrorInput::outOfIndex; }
        return static_cast<Attribute>(number-1);
    }
    
    
    ~Input() {}
    
    
};


#endif /* Input_hpp */
