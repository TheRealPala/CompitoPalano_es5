//
// Created by ale on 27/06/23.
//

#include <stdexcept>
#include "Inventory.h"
#include "Weapon.h"
#include "Equipment.h"
#include "Robot.h"

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
        added = orig.added;
        if(!orig.isEmpty()) {
            deleteInventory();
            for (auto &i: orig.inventory) {
                recongizeAndAdd(i);
            }
        }
    }
}

Inventory &Inventory::operator=(const Inventory &right) {
    if(this != &right) {
        maxSize = right.maxSize;
        added = right.added;
        if(!right.isEmpty()) {
            deleteInventory();
            for (auto &i: right.inventory) {
                recongizeAndAdd(i);
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
    if(maxSize)
        added -= 1;
}

void Inventory::recongizeAndAdd(Element * pElement) {
    if(dynamic_cast<Robot*>(pElement))
        inventory.push_back(new Robot(*dynamic_cast<Robot*>(pElement)));
    else if(dynamic_cast<Equipment*>(pElement))
        inventory.push_back(new Equipment(*dynamic_cast<Equipment*>(pElement)));
    else if(dynamic_cast<Weapon*>(pElement))
        inventory.push_back(new Weapon(*dynamic_cast<Weapon*>(pElement)));
    else
        inventory.push_back(new Element(*pElement));
}

bool Inventory::isEmpty() const {
    return inventory.empty();
}


