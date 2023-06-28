//
// Created by ale on 27/06/23.
//

#ifndef COMPITOPALANO_ES5_INVENTORY_H
#define COMPITOPALANO_ES5_INVENTORY_H


#include <vector>
#include "Element.h"

class Inventory {
private:
    std::vector<Element*> inventory;
    int maxSize;
    int added;
    void deleteInventory();
    void checkPosition(int index);
public:
    explicit Inventory(int maxSize = 0) : maxSize(maxSize), added(0){};
    Inventory(const Inventory& orig);
    Inventory& operator=(const Inventory& right);
    ~Inventory() { deleteInventory(); }
    void addElement (Element* element);
    void addElement(Element* element, int index);
    void printInventory() const;
    void deleteElement(int index);
    bool isEmpty() const;

    void recongizeAndAdd(Element *pElement);
};


#endif //COMPITOPALANO_ES5_INVENTORY_H
