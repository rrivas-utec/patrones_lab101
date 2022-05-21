//
// Created by rrivas on 18/05/2022.
//

#ifndef PATRONES_APPLICATION_H
#define PATRONES_APPLICATION_H

#include "componente.h"
#include "abstract_factory.h"
#include <memory>
#include <string>
#include <unordered_map>
using namespace std;

class application {
    unordered_map<string, shared_ptr<componente_t>> componentes;
public:
    application();
    void run();

    // Soporte al abstract factory y factory
    void add_component(const string& key, const shared_ptr<componente_t>& com);

    // Patron Abstract Factory
    shared_ptr<abstract_factory> create_abstract_factory();
    void build_components(); // Patron Abstract Factory

    void read_components(); // Patron Factory
    void setup_events(); // Patron Observer
};


#endif //PATRONES_APPLICATION_H
