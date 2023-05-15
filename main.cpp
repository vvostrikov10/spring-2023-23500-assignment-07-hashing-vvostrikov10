#include <iostream>
#include "Node.h"
#include "List.h"
#include "Dictionary.h"

int main(){
    List *l1 = new List();
    Person *p1 = new Person("Vlad", "Vostrikov", 1);
    Person *p2 = new Person("John", "Doe", 2);
    Person *p3 = new Person("Vlad", "Vostrikov", 3);
    l1->insert(p1);
    l1->insert(p2);
    std::cout << l1->toString() << "\n";
    Dictionary *d1 = new Dictionary();
    d1->insert(p1);
    d1->insert(p2);
    d1->insert(p3);
    std::cout << d1->find("Vostrikov, Vlad")->get_id() << "\n";
    std::cout << d1->get_keys();

}