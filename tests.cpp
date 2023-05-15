#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "Dictionary.h"
#include "Person.h"
#include <iostream>


TEST_CASE("find and insert tests"){
    Person *p1 = new Person("Vlad", "Vostrikov", 1);
    Person *p2 = new Person("Jo", "Schhmmoe", 2);
    Person *p3 = new Person("Jo", "mmoeSchh", 3);//person 2 and 3 hash to the same value
    Dictionary *d = new Dictionary;
    d->insert(p1);
    d->insert(p2);
    d->insert(p3);
    CHECK(d->find("Vostrikov, Vlad")->get_id() == 1);
    CHECK(d->find("Schhmmoe, Jo")->get_id() == 2);
    CHECK(d->find("mmoeSchh, Jo")->get_id() == 3);
    CHECK(d->find("a") == nullptr);
    p1 = new Person("Vlad", "Vostrikov", 4);
    d->insert(p1);
    CHECK(d->find("Vostrikov, Vlad")->get_id() == 4); //checks that the new person is inserted at thebeginning of the linked list
}

TEST_CASE("get_keys test"){
    Dictionary *d = new Dictionary;
    CHECK(d->get_keys() == "");
    Person *p1 = new Person("Vlad", "Vostrikov", 1);
    Person *p2 = new Person("Jo", "Schhmmoe", 2);
    Person *p3 = new Person("Jo", "mmoeSchh", 3);
    d->insert(p1);
    d->insert(p2);
    d->insert(p3);
    CHECK(d->get_keys() == "mmoeSchh, Jo\nSchhmmoe, Jo\nVostrikov, Vlad\n");

}