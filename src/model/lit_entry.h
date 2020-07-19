//
// Created by mikhail on 15/07/2020.
//

#ifndef THESAURUS_GTK_LIT_ENTRY_H
#define THESAURUS_GTK_LIT_ENTRY_H


#include <string>

class LitEntry {
    long int    entry_id;
    std::string title;

public:
    virtual std::string get_bibtex() = 0;
};


#endif //THESAURUS_GTK_LIT_ENTRY_H
