//
//  ClassError.hpp
//  CourseworkInProgramming26
//
//  Created by Сергей Насыбуллин on 26.03.2022.
//

/**
 * @file
 * Используется:
 *      - main
 *      - Input
 *      - FileProcess
 */

#ifndef ClassError_hpp
#define ClassError_hpp

#include <stdio.h>

/// Ошибки ввода
enum ErrorInput {
    /// Выход за приделы массива или перечисления
    outOfIndex,
    /// Неправильный ввод текста
    incorrectData
};

/// Ошибки открытия файла
enum ErrorFile {
    /// Ошибка открытия
    errorOpen,
};


#endif /* ClassError_hpp */
