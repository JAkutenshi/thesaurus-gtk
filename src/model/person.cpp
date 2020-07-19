//
// Created by mikhail on 19/07/2020.
//

#include "person.h"

Person::Person(const std::string &first_name, const std::string &last_name, const std::string &middle_name) :
        first_name(first_name), last_name(last_name), middle_name(middle_name) {}

Person::Person(const std::string &first_name, const std::string &last_name,
        const std::string &middle_name, const std::string &von) :
        first_name(first_name), last_name(last_name), middle_name(middle_name), von(von) {}

std::string Person::getBibTeX() {
    return first_name + (von.length() != 0 ? " " + von + " " : " ") + last_name;
}
