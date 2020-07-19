//
// Created by mikhail on 19/07/2020.
//

#ifndef THESAURUS_GTK_PERSON_H
#define THESAURUS_GTK_PERSON_H

#include <string>


class Person {
    std::string first_name;
    std::string last_name;
    std::string middle_name; // for search reasons
    std::string von;         // "de la" or "van der"

public:
    Person(const std::string &first_name, const std::string &last_name, const std::string &middle_name);
    Person(const std::string &first_name, const std::string &last_name,
            const std::string &middle_name, const std::string &von);
    std::string getBibTeX();
};


#endif //THESAURUS_GTK_PERSON_H
