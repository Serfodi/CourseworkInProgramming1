//
//  List.hpp
//  CourseworkInProgramming26
//
//  Created by Сергей Насыбуллин on 27.03.2022.
//

/**
 * @file
 * Используется:
 *      - main
 */

#ifndef List_hpp
#define List_hpp

#include <stdio.h>

#include "ModelBirth.hpp"


/**
 Односвязный список.
 */
class List {
    static List *first;
    
private:
    List *next;
    Birth birth;
    
public:
    
    // MARK: - Инициализатор
    
    List(Birth _data) {
        birth = _data;
        next = 0;
        append();
    }
    
    
    
    // MARK: - Методы
    
private:
    void append() {
        if (first == 0) {
            first = this;
        } else {
            List *last = first;
            while (last -> next != 0) {
                last = last -> next;
            }
            last -> next = this;
        }
    }
    
    void show() {
        std::cout << birth.description();
    }
    
public:
    static void description() {
        List *now = first;
        int pos = 0;
        while (now != 0) {
            now -> show();
            pos++;
            now = now -> next;
        }
    }

    
};


#endif /* List_hpp */
