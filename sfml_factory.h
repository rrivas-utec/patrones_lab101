//
// Created by rudri on 5/20/2022.
//

#ifndef PATRONES_SFML_FACTORY_H
#define PATRONES_SFML_FACTORY_H

#include <memory>
#include "sfml_button.h"
#include "sfml_label.h"
#include "abstract_factory.h"

struct sfml_factory: abstract_factory {
    shared_ptr<componente_t> create_label(const string& text, float x, float y, float w, float h) override {
        return make_shared<sfml_label_t>(text, x, y, w, h);
    }
    shared_ptr<componente_t> create_button(const string& text, float x, float y, float w, float h) override {
        return make_shared<sfml_button_t>(text, x, y, w, h);
    };

};


#endif //PATRONES_SFML_FACTORY_H
