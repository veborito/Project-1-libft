#include <exception>
#include <iostream>
#include <string>

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
    Bureaucrat boris("Boris", 1);
    Bureaucrat carmelle("Carmelle", 150);
    Bureaucrat mily("Mily", 10);
    Bureaucrat malia(mily);
    Form f1("relou", 100);
    Form f2("relou2", 1);
    Form f3("relou3", 75);
    Form f4(f3);

    std::cout << malia << '\n';
    std::cout << f4 << '\n';
    try {
        Form mauvais("relou", 200);
    } catch (std::exception &e) {
        std::cout << e.what() << '\n';
    }
    try {
        Form mauvais2("relou", 0);
    } catch (std::exception &e) {
        std::cout << e.what() << '\n';
    }
    try {
        boris.signForm(f1);
        carmelle.signForm(f1);
    } catch (std::exception &e) {
        std::cout << e.what() << '\n';
    }
    try {
        carmelle.signForm(f2);
    } catch (std::exception &e) {
        std::cout << e.what() << '\n';
    }
    try {
        mily.signForm(f3);
    } catch (std::exception &e) {
        std::cout << e.what() << '\n';
    }
    return 0;
}
