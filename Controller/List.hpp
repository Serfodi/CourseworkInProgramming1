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

#include "Birth.hpp"
#include "ClassError.hpp"

 
struct Node {
    Birth birth;
    
    Node* next;
    Node(Birth _new) : birth(_new), next(nullptr) {}
};

struct List {
public:
    /// Начало списка
    Node* first;
    /// Последний элемент списка
    Node* last;
    
    
    List() : first(nullptr), last(nullptr) {}

    
    /// Добавляет элемент в конец списка.
    void append(Birth birth) {
        Node* p = new Node(birth);
        // Если это первый
        if (first == nullptr) {
          first = p;
          last = p;
          return;
        }
        last -> next = p;
        last = p;
    }
    
    Node* find(Birth birth) {
        Node* p = first;
        while (p && p -> birth != birth) {
            p = p->next;
        }
        return (p && p -> birth == birth) ? p : nullptr;
    }
    
    /// Удаления по заданному значению
    ///
    /// @throw ErrorFind::noFind
    void removeBy(Birth birth) {
        if (isEmpty()) return;
        if (first -> birth == birth) {
            removeFirst();
            return;
        }
        else if (last -> birth == birth) {
            removeLast();
            return;
        }
        Node* slow = first;
        Node* fast = first->next;
        while (fast && fast -> birth != birth) {
            fast = fast -> next;
            slow = slow -> next;
        }
        if (!fast) {
            cout << "конец чего то";
        }
        slow->next = fast->next;
        delete fast;
    }
    
    Node* operator[] (const int index) {
        Node* p = first;
        for (int i = 0; i < index; i++) {
            p = p -> next;
            if (!p) return nullptr;
        }
        return p;
    }
    
    
    /// Просмотреть весь список
    void description() {
        Node* p = first;
        while (p) {
            cout << p -> birth.description();
            p = p -> next;
        }
    }
    
    
//    MARK:  Private metode
    
private:
    
    /// Проверяет существование списка
    bool isEmpty() {
        return first == nullptr;
    }
    
    /// Удаления первого
    void removeFirst() {
        Node* p = first;
        first = p->next;
        delete p;
    }

    /// Удаления последнего
    void removeLast() {
        if (first == last) {
            removeFirst();
            return;
        }
        Node* p = first;
        while (p -> next != last) p = p -> next;
        p -> next = nullptr;
        delete last;
        last = p;
    }
    
    
};


#endif /* List_hpp */
