#include <iostream>
#include "Person.h"
#include "List.h"
#include "Node.h"
#include "Dictionary.h"
#include <cmath>

//taken from opendsa-server.cs.vt.edu
int sfold(std::string s, int M) {
  long sum = 0, mul = 1;
  for (int i = 0; i < s.length(); i++) {
    mul = (i % 4 == 0) ? 1 : mul * 256;
    sum += s[i] * mul;
  }
  return (int)(abs(sum) % M);
}

Dictionary::Dictionary(){
    for (int i = 0; i < size; i++){
        table[i] = nullptr;
    }
}
Dictionary::~Dictionary(){
    for (int i = 0; i < size; i++){
        delete table[i];
    }
}
void Dictionary::insert(Person *data){
    int i = sfold(data->get_name(), size);
    if (table[i] == nullptr){
        table[i] = new List();
    }
    table[i]->insert(data);
}
Person *Dictionary::find(std::string name){
    int i = sfold(name, size);
    if (table[i] == nullptr){
        return nullptr;
    }
    return table[i]->find(name);
}
std::string Dictionary::get_keys(){
    std::string result = "";
    for(int i = 0; i < size; i++){
        if (table[i] != nullptr){
            result += table[i]->toString();
        }
    }
    return result;
}