#include <iostream>
#include "Element.h"
#include "Robot.h"
#include "Inventory.h"
#include "Equipment.h"
#include "Weapon.h"

int main() {
    Inventory i;
    i.addElement(new Robot);
    i.addElement(new Equipment);
    i.addElement(new Weapon);
    i.printInventory();
    std::cout << std::endl;
    try{
        i.addElement(new Robot, 1);
    } catch (std::out_of_range& e) {
        std::cout << e.what() << "\n" << std::endl;
    }
    i.printInventory();
    std::cout << std::endl;
    i.deleteElement(1);
    i.addElement(new Robot, 1);
    i.printInventory();
    try{
        i.deleteElement(5);
    } catch (std::out_of_range& e) {
        std::cout << e.what() << "\n" << std::endl;
    }
    Inventory i2(3);
    i2.addElement(new Robot);
    i2.addElement(new Equipment);
    i2.addElement(new Weapon);
    try{
        i2.addElement(new Robot);
    } catch (std::out_of_range& e) {
        std::cout << e.what() << "\n" << std::endl;
    }
    return 0;
}
