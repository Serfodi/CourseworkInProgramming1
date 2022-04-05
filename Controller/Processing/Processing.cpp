//
//  Processing.cpp
//  CourseworkInProgramming26
//
//  Created by Сергей Насыбуллин on 27.03.2022.
//

#include "Processing.hpp"


// MARK: - viewData

void Processing::viewDataProcessing(List &list) {
    tabel.printTable();
    
    int count = 0;
    while (list[count]) {
        Birth birth = list[count] -> birth;
        count += 1;
        if (isArea(birth)) {
            switch (dataFormat) {
                    
                case day:
                    if (birth.dOB == dataInput[0]) tabel.addToTable(birth);
                    break;
                    
                case interval:
                    if (birth.dOB >= dataInput[0] && birth.dOB <= dataInput[1]) tabel.addToTable(birth);
                    break;
            }
        }
    }
};



// MARK: - histogram

void Processing::histogramProcessing(List &list) {
    
    /// 12 месяцев. 0 месяц не учитывается
    int mouthStat[13] = {
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
    };
    
    int count = 0;
    while (list[count]) {
        Birth birth = list[count] -> birth;
        count += 1;
        if (isArea(birth) && isBirthrate(birth)) {
            mouthStat[birth.dOB.getMonth()] += 1;
        }
    }
    
    histog.histogram(mouthStat);
};



// MARK: - birthrate

void Processing::birthrateProcessing(List &list) {
    // 12 месяцев
    int mouthStat[13]  = {
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
    };
    
    int count = 0;
    while (list[count]) {
        Birth birth = list[count] -> birth;
        count += 1;
        if (isArea(birth) && isBirthrate(birth)) {
            mouthStat[birth.dOB.getMonth()] += 1;
        }
    }
    
    int indexMax = -1; int indexMin = 1;
    int max = 0;
    int min = mouthStat[1];
    for (int i = 1; i<13; i++) {
        if (min > mouthStat[i]) {
            min = mouthStat[i];
            indexMin = i;
        }
        if (max < mouthStat[i]) {
            max = mouthStat[i];
            indexMax = i;
        }
    }
    
    if (indexMax == indexMin) {
        output.mouthEqule(max);
    } else {
        output.mouth(indexMax, indexMin, max, min);
    }
};



// MARK: - delet

void Processing::deletProcessing(List &list) {
    Node *node = list.find(Birth(fIOInput, dataInput[0]));
    if (node == nullptr) throw ErrorFind::noFind;
    list.removeBy(node -> birth);
};
