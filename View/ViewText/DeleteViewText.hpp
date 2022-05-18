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
    
    DeleteViewText(const DataModel &dataModel) : ViewText(dataModel) { }
    
    void output(ostream &out) override {
        out << "Удален: " << dataModel.fIOInput << ". Дата рождения: " << dataModel.dataInput[0] << endl;
    }
    
};

#endif /* DeleteViewText_hpp */
