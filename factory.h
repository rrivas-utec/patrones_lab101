//
// Created by rudri on 5/20/2022.
//

#ifndef PATRONES_FACTORY_H
#define PATRONES_FACTORY_H

#include <functional>
#include <string>
#include <unordered_map>
#include "componente.h"
#include "sfml_label.h"
#include "sfml_button.h"
using namespace std;

class factory_t {
private:
    unordered_map<string,
        function<shared_ptr<componente_t>(
                string, float, float, float, float)>> callbacks;
    inline static factory_t* instance {};
protected:
    factory_t() = default;
public:
    bool attach(const string& key,
                const function<shared_ptr<componente_t>(
                        string, float, float, float, float)>& createFn) noexcept {
        return callbacks.insert({key, createFn}).second;
    }
    shared_ptr<componente_t> create(const string& key, const string& text,
                                    float left, float top,
                                    float width, float height) {
        return callbacks.at(key)(text, left, top, width, height);
    }

    static factory_t* get_instance() noexcept {
        if (instance == nullptr) instance = new factory_t();
        return instance;
    }
};

//Registrando factories
namespace {
    auto f = factory_t::get_instance();

    auto rl = f->attach("label", [](const string& text,
            float left, float top, float width, float height) {
        return make_shared<sfml_label_t>(text, left, top, width, height); });

    auto rb = f->attach("button", [](const string& text,
            float left, float top, float width, float height) {
        return make_shared<sfml_button_t>(text, left, top, width, height); });
}

#endif //PATRONES_FACTORY_H
