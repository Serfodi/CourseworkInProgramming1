//
//  Processing.hpp
//  CourseworkInProgramming26
//
//  Created by Сергей Насыбуллин on 27.03.2022.
//

/**
 * @file Содержит классы обработки файла
 */

#ifndef Processing_hpp
#define Processing_hpp


/**
 * Метод обработки, однапроходный алгоритм возврощающий bool
 */
class Processing {
public:
    
    DataModel dataModel;
    
    Processing() {}
    
    Processing(DataModel dataModel) {
        this -> dataModel = dataModel;
    }
    
    virtual void processing(const Birth&) = 0;
    
};



/**
 *
 * Просмотр данных за любой день (или за любой временной интервал)
 *
 */
class ViewBirthProcessing: public Processing {
public:
    
    /// База данных Birth
    vector<Birth> birthData;
    
    ViewBirthProcessing() {}
    
    ViewBirthProcessing(DataModel dataModel) : Processing(dataModel) {}
    
    
    void processing(const Birth &birth) override {
        switch (dataModel.dataFormat) {
            case day:
                if (birth.dOB == dataModel.dataInput[0])
                    birthData.push_back(birth);
            case interval:
                if (birth.dOB >= dataModel.dataInput[0] && birth.dOB <= dataModel.dataInput[1])
                    birthData.push_back(birth);
        }
    }
    
};



/**
 *
 * Вывод гистограммы рождаемости по месяцам года и кривой  рождаемости за год
 *
 */
class HistogramProcessing: public Processing {
public:
    
    int mouth[13] = {
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
    };
    
    HistogramProcessing() {}
    
    HistogramProcessing(DataModel dataModel) : Processing(dataModel) {}
    
    void processing(const Birth &birth) override {
        if ( !Сhildren::attribute(dataModel.attribute, birth.children) ) { return; }
        mouth[birth.dOB.month] += 1;
    }
  
    
};



/**
 *
 * Определение месяцев максимальной и минимальной рождаемости
 *
 */
class BirthrateProcessing: public Processing {
public:
    
    // 0 – кол-во
    // 1 - месяц
    int min[2] = {-1, 0};
    int max[2] = {0, 0};
    
    int mouth[13] = {
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
    };
    
    BirthrateProcessing() {}
    
    BirthrateProcessing(DataModel dataModel) : Processing(dataModel) {}
    
    
    void processing(const Birth &birth) override {
        if (!Сhildren::attribute(dataModel.attribute, birth.children)) { return; }
        
        mouth[birth.dOB.month] += 1;
        
        if ( mouth[birth.dOB.month] > max[0] ) {
            max[0] = mouth[birth.dOB.month];
            max[1] = mouth[birth.dOB.month];
        }
        
        if (min[0] == -1) {
            min[0] = 1;
            min[1] = mouth[birth.dOB.month];
        }
        
        if ( mouth[birth.dOB.month] < min[0] ) {
            min[0] = mouth[birth.dOB.month];
            min[1] = mouth[birth.dOB.month];
        }
        
    }
    
    
};


/**
 *
 * Удаления по: фио матери и году рождения матери
 *
 */
class DeleteProcessing: public Processing {
public:
    
    vector<Birth> birthData;
    
    bool isEmpty = false;
    
    DeleteProcessing(DataModel dataModel) : Processing(dataModel) {}
    
    void processing(const Birth &birth) override {
        if (!(dataModel.fIOInput == birth.fIO && dataModel.dataInput[0] == birth.dOBMother)) {
            birthData.push_back(birth);
        } else {
            isEmpty = true;
        }
    }
    
    
};




#endif /* Processing_hpp */
