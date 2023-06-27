//
// Created by ale on 27/06/23.
//

#include <stdexcept>
#include "Inventory.h"

void Inventory::deleteInventory() {
    if(inventory.empty()) {
        for (auto &i: inventory) {
            if (i)
                delete i;
        }
    }
}

void Inventory::checkPosition(int index) {
    bool error = false;
    if(index < 0)
        error = true;
    if(!error && maxSize){
        if(index >= maxSize)
            error = true;
    }
    if(error)
        throw std::out_of_range("indice non valido");
}

int Inventory::getSize() const {
    return inventory.size();
}

const std::vector<Element *> &Inventory::getInventory() const {
    return inventory;
}

void Inventory::addElement(Element *element) {
    if(maxSize && added >= maxSize)
        throw std::out_of_range("inventario pieno");
    inventory.push_back(element);
    added += 1;
}

void Inventory::addElement(Element *element, int index) {
    checkPosition(index);
    if(inventory[index])
        throw std::out_of_range("posizione già occupata");
    inventory[index] = element;
}

Inventory::Inventory(const Inventory &orig) {
    if(this != &orig) {
        maxSize = orig.maxSize;
        if(orig.getSize()) {
            deleteInventory();
            for (auto &i: orig.inventory) {
                inventory.push_back(new Element(*i));
            }
        }
    }
}

Inventory &Inventory::operator=(const Inventory &right) {
    if(this != &right) {
        maxSize = right.maxSize;
        if(right.getSize()) {
            deleteInventory();
            for (auto &i: right.inventory) {
                inventory.push_back(new Element(*i));
            }
        }
    }
    return *this;
}

void Inventory::printInventory() const {
    for (auto &i: inventory) {
        i->printDescription();
    }
}

void Inventory::deleteElement(int index) {
    checkPosition(index);
    if(index >= inventory.size())
        throw std::out_of_range("posizione non valida");
    if(inventory[index]) {
        delete inventory[index];
        inventory[index] = nullptr;
    }
}


