//
//  ClassError.hpp
//  CourseworkInProgramming26
//
//  Created by Сергей Насыбуллин on 26.03.2022.
//

/**
 * @file Перечисления ошибок
 */

#ifndef ClassError_hpp
#define ClassError_hpp

class Error {
public:

    string text;
    
    Error(string text) {
        this -> text = text;
    }
    
    virtual const string what() const = 0;
    
};

class OpenFileError: public Error {
    
    OpenFileError(string text) : Error(text) {}
    
    const string what() const override {
        return "Ошибка открытия файла: " + text;
    }
    
};

class DateError: public Error {
public:
    
    DateError(string text) : Error(text) {}
    
    const string what() const override {
        return "Ошибка ввода даты: " + text + ". Введите еще раз: ";
    }
    
};

class InputError : public Error {
public:
    
    InputError(string text) : Error(text) {}
    
    const string what() const override {
        return "Ошибка ввода: " + text + ". Введите еще раз: ";
    }
    
};


#endif /* ClassError_hpp */
