#include <iostream>
#include <string>

using namespace std;

class Student {
protected:
    float rating;
    unsigned int mark;
    unsigned int scholarship;
    string say;
public:
    string surname;               //Отсутсвие инкапсуляции

    void setRating(float rating) {  //инкапсуляция с помощью set/get
        this->rating = rating;
    }

    float getRating() const {
        return rating;
    }

    void setMark(unsigned int mark) {
        this->mark = mark;
    }

    unsigned int getMark() const {
        return mark;
    }

    void fallingRating(float rating) { //инкапсуляция с помощью специальных методов
        this->rating -= rating;
    }

    virtual void saysay() const {  //замена поведения
        cout << say << endl;
    }

    virtual void Mark() {           //расширение поведения
        cout<< "Your mark : "<< getMark() << endl;
    }

};

class BadStudent : public Student {
public:
    BadStudent(const float rating, const unsigned int mark, const string say, const string surname) {
        this->rating = rating;
        this->mark = mark;
        this->scholarship = 0;
        this->say = say;
        this->surname = surname;
    }
    void saysay() const {
        cout<< say << endl;
    }

    void Mark() {
        Student::Mark();
        if (getMark() > 3)
            cout<< "This is my first good mark." << endl;
    }

};

class GoodStudent : public Student {  //инкапсуляция за счет абстракций
public:
    GoodStudent(const float rating, const unsigned int mark, const string say, const string surname) {
        this->rating = rating;
        this->mark = mark;
        this->scholarship = 5500;
        this->say = say;
        this->surname = surname;
    }

    void setScholarship(unsigned int scholarship) {
        this->scholarship = scholarship;
    }

    unsigned int getScholarship() {
        return scholarship;
    }

};

void Hello(Student *s) {
    s->saysay();
}

void Exam(Student *s) {
    s->Mark();
}

int main() {
    BadStudent B(3.2,4,"Hello","Kokorin");
    GoodStudent H(5.0,5,"Good morning","Asov");
    cout << B.surname << endl;
    B.fallingRating(0.1);
    cout << B.getRating() <<endl;
    cout << H.getScholarship() <<endl;
    Hello(&B);
    Exam(&B);
    return 0;
}