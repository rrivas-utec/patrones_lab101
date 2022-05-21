//
// Created by rrivas on 18/05/2022.
//

#ifndef PATRONES_SFML_LABEL_H
#define PATRONES_SFML_LABEL_H

#include "componente.h"
#include "render.h"
#include <SFML/Graphics.hpp>

class sfml_label_t: public componente_t {

public:
    using componente_t::componente_t;
    void draw () override {
        sf::Font font;
        sf::Text txt;
        if (font.loadFromFile("./Oxanium-Regular.ttf"))
        {
            txt.setFont(font);
            txt.setFillColor(sf::Color::Yellow);
            txt.setCharacterSize(20);
            txt.setString(text);
            txt.setPosition(x , y);
        }
        auto& canvas = render<sf::RenderWindow>::get_instance()->get();
        canvas->draw(txt);
    }

};


#endif //PATRONES_SFML_LABEL_H
