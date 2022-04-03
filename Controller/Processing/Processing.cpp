//
//  Processing.cpp
//  CourseworkInProgramming26
//
//  Created by Сергей Насыбуллин on 27.03.2022.
//

#include "Processing.hpp"


// MARK: - viewData

void Processing::viewDataProcessing() {
    
};



// MARK: - histogram

void Processing::histogramProcessing() {
    
};



// MARK: - birthrate

void Processing::birthrateProcessing() {
    
};



// MARK: - delet

void Processing::deletProcessing(List &list) {
    Node *node = list.find(Birth(fIO, data[0]));
    if (node == nullptr) throw ErrorFind::noFind;
    list.removeBy(node -> birth);
};
