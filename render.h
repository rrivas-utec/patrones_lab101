//
// Created by rrivas on 18/05/2022.
//

#ifndef PATRONES_RENDER_H
#define PATRONES_RENDER_H

#include <SFML/Graphics.hpp>
#include <memory>

using namespace std;

template <typename T>
using smart_ptr = std::unique_ptr<T>;
//using smart_ptr = T*;

template <typename T, typename ...Params>
auto make_smart (Params ...params) { return std::make_unique<T>(params...); };
//auto make_smart (Params ...params) { return new T(params...); };

template <typename T>
class render {
    smart_ptr<T> data {};
    inline static render<T>* instance;
    template <typename ...Params>
    explicit render(Params... params): data(make_smart<T>(params...)) {}
public:
    template <typename ...Params>
    static render<T>* get_instance(Params ...params) {
        if (instance == nullptr) instance = new render<T>(params...);
        return instance;
    }
    smart_ptr<T>& get(){ return data; }
};


#endif //PATRONES_RENDER_H
