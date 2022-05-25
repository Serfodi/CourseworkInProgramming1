//
//  DeleteViewText.hpp
//  CourseworkInProgramming26
//
//  Created by Сергей Насыбуллин on 18.05.2022.
//

#ifndef DeleteViewText_hpp
#define DeleteViewText_hpp


class DeleteViewText: public ViewText {
public:
    
    DeleteProcessing processing;
    
    DeleteViewText(const DeleteProcessing &processing, const DataModel &dataModel) : ViewText(dataModel) {
        this -> processing = processing;
    }
    
    void output(ostream &out) override {
        
        if (processing.isEmpty) {
            out << "Удален: " << dataModel.fIOInput << ". Дата рождения: " << dataModel.dataInput[0] << endl;
        } else {
            out << "Мать не найдена." << endl;
        }
        
    }
    
};

#endif /* DeleteViewText_hpp */
