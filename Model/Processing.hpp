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
    virtual void processingEnd() = 0;
    
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
    
    void processingEnd() override {
        sort(birthData.begin(), birthData.end());
    }
    
};



/**
 *
 * Вывод гистограммы рождаемости по месяцам года и кривой  рождаемости за год
 *
 */
class HistogramProcessing: public Processing {
public:
    
    int mouth[12] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    
    HistogramProcessing() {}
    HistogramProcessing(DataModel dataModel) : Processing(dataModel) {}
    
    void processing(const Birth &birth) override {
        if ( !Сhildren::attribute(dataModel.attribute, birth.children) ) { return; }
        mouth[birth.dOB.month -1] += 1;
    }
  
    void processingEnd() override {}
    
};



/**
 *
 * Определение месяцев максимальной и минимальной рождаемости
 *
 */
class BirthrateProcessing: public Processing {
public:
    
    int min[2] = {INT_MAX, 0}; // 0 – кол-во. 1 - месяц
    int max[2] = {0, 0};
    
    vector<int> mouth = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
    
    BirthrateProcessing() {}
    BirthrateProcessing(DataModel dataModel) : Processing(dataModel) {}
    
    void processing(const Birth &birth) override {
        if (!Сhildren::attribute(dataModel.attribute, birth.children)) { return; }
        mouth[birth.dOB.month -1] += 1;
    }
    
    void processingEnd() override {
        max[1] = int(distance(mouth.begin(), max_element(mouth.begin(), mouth.end())));
        max[0] = mouth[max[1]];
        min[1] = int(distance(mouth.begin(), min_element(mouth.begin(), mouth.end())));
        min[0] = mouth[min[1]];
    }
    
};


/**
 *
 * Удаления по: фио матери и году рождения матери
 *
 */
class DeleteProcessing: public Processing {
public:
    
    Birth birth;
    
    DeleteProcessing() {};
    
    /// Нашел?
    bool isEmpty = false;
    
    DeleteProcessing(DataModel dataModel) : Processing(dataModel) {}
    
    void processing(const Birth &birth) override {
        if (dataModel.fIOInput == birth.fIO && dataModel.dataInput[0] == birth.dOBMother) {
            this -> birth = birth;
            isEmpty = true;
        }
    }
    
    void processingEnd() override {}
    
};




#endif /* Processing_hpp */
