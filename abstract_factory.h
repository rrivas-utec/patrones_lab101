//
// Created by rudri on 5/20/2022.
//

#ifndef PATRONES_ABSTRACT_FACTORY_H
#define PATRONES_ABSTRACT_FACTORY_H

#include "componente.h"
#include <memory>

struct abstract_factory {
    virtual shared_ptr<componente_t> create_label(const string& text, float x, float y, float w, float h) = 0;
    virtual shared_ptr<componente_t> create_button(const string& text, float x, float y, float w, float h) = 0;
};


#endif //PATRONES_ABSTRACT_FACTORY_H
