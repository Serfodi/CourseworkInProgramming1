//
//  Processing.cpp
//  CourseworkInProgramming26
//
//  Created by Сергей Насыбуллин on 27.03.2022.
//

#include "Processing.hpp"


// MARK: - viewData

void Processing::viewDataProcessing(Hospital hospital, DataModel dataModel, void (*open)(string), void (*read)(Birth&), Test test, Close close) {
    tabel.printTable();
    
    open(to_string(dataModel.number) + ".txt");
    
    Birth birth;
    
    // повторять пока
    while (test) {
        
        read(birth);
        
        if (true) {
            switch (dataModel.dataFormat) {
                case day:
                    if (birth.dOB == dataModel.dataInput[0]) tabel.addToTable(birth);
                    break;
                case interval:
                    if (birth.dOB >= dataModel.dataInput[0] && birth.dOB <= dataModel.dataInput[1]) tabel.addToTable(birth);
                    break;
            }
        }
    }
    close();
};

/*


// MARK: - histogram

void Processing::histogramProcessing() {
    
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

void Processing::birthrateProcessing() {
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

void Processing::deletProcessing() {
    Node *node = list.find(Birth(fIOInput, dataInput[0]));
    if (node == nullptr) throw ErrorFind::noFind;
    list.removeBy(node -> birth);
};

 */
