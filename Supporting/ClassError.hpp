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


class Error: public exception {
    
public:
    
//    Error(char *text) : exception() {}
    
    
    
    
};


/// Ошибки ввода
enum ErrorInput {
    /// Выход за приделы массива или перечисления
    outOfIndex,
    /// Неправильный ввод текста
    incorrectData
};

/// Ошибка поиска
enum ErrorFind {
    /// Такого экземпляра не существует
    noFind
};

/// Ошибки открытия файла
enum ErrorFile {
    /// Ошибка открытия
    errorOpen,
};


#endif /* ClassError_hpp */
