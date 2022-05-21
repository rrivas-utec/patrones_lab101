//
// Created by rrivas on 18/05/2022.
//

#ifndef PATRONES_SFML_BUTTON_H
#define PATRONES_SFML_BUTTON_H

#include "componente.h"
#include "render.h"
#include "SFML/Graphics.hpp"

class sfml_button_t: public componente_t {
    sf::Color color = sf::Color::White;
public:
    using componente_t::componente_t;

    void draw() {
        auto& canvas = render<sf::RenderWindow>::get_instance()->get();
        sf::RectangleShape shape({width, height});
        shape.setPosition(x, y);
        shape.setFillColor(color);

        // Crear el texto
        sf::Font font;
        sf::Text txt;
        if (font.loadFromFile("./Oxanium-Regular.ttf"))
        {
            txt.setFont(font);
            txt.setFillColor(sf::Color::Blue);
            txt.setCharacterSize(20);
            txt.setString(text);
            txt.setPosition(x , y);
            // Para centrar el texto en el recuadro
            const auto bounds(txt.getLocalBounds());
            const auto box(shape.getSize());
            txt.setOrigin((bounds.width - box.x) / 2 + bounds.left, (bounds.height - box.y) / 2 + bounds.top);
        }

        canvas->draw(shape);
        canvas->draw(txt);
    }
    // Sobrecarga de metodos
    void click_pressed_event(mouse_event_params_t e) override {
        if (click) click(e);
    }
    void click_released_event(mouse_event_params_t e) override {
        if (click) click(e);
    }
    void mouse_move_event(mouse_event_params_t e) override {
        if (mouse_move) mouse_move(e);
    }
    void mouse_enter_event(mouse_event_params_t e) override {
        sf::Cursor crs;
        auto& canvas = render<sf::RenderWindow>::get_instance()->get();
        if (crs.loadFromSystem(sf::Cursor::Hand))
            canvas->setMouseCursor(crs);
        color = sf::Color::Yellow;
    }
    void mouse_leave_event(mouse_event_params_t e) override {
        sf::Cursor crs;
        auto& canvas = render<sf::RenderWindow>::get_instance()->get();
        if (crs.loadFromSystem(sf::Cursor::Arrow))
            canvas->setMouseCursor(crs);
        color = sf::Color::White;
    }
};


#endif //PATRONES_SFML_BUTTON_H
