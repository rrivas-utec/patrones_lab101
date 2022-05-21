//
// Created by rrivas on 18/05/2022.
//

#ifndef PATRONES_COMPONENTE_H
#define PATRONES_COMPONENTE_H

#include <string>
#include <functional>
using namespace std;

struct mouse_event_params_t {
    float x;
    float y;
    mouse_event_params_t(float x, float y): x{x}, y{y} {}
};

struct keypress_event_params_t {
    char key_char;
    keypress_event_params_t(char key_char): key_char{key_char} {}
};

class componente_t {
protected:
    string text;
    float x = 0;
    float y = 0;
    float width = 0;
    float height = 0;

public:
    componente_t(const string& text,  float x, float y, float w, float h):
        text(text), x(x), y(y), width(w), height(h) {}
    virtual void draw() = 0;

    virtual void keypress_event(keypress_event_params_t e) {}
    virtual void click_pressed_event(mouse_event_params_t e) {}
    virtual void click_released_event(mouse_event_params_t e) {}
    virtual void mouse_move_event(mouse_event_params_t e) {}
    virtual void mouse_enter_event(mouse_event_params_t e) {}
    virtual void mouse_leave_event(mouse_event_params_t e) {}
    [[nodiscard]] bool is_on_bound(float px, float py) const {
        return (px > x && px < x + width) && (py > y && py < y + height);
    }
    // Callables - Command
    function<void(mouse_event_params_t)> click;
    function<void(mouse_event_params_t)> mouse_move;
    function<void(keypress_event_params_t)> key_press;
};



#endif //PATRONES_COMPONENTE_H
