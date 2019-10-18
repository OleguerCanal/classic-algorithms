// Sortable objects tests

#include "stdlib.h"
#include "iostream"
#include <algorithm>
#include <string>
#include <deque>

class Person {
  public:
    std::string name;
    int age;

    Person(std::string PersonName, int PersonAge) :
        name(PersonName), age(PersonAge) {}
    
    // Compares by age
    bool operator <(const Person OtherPerson) {
        if (age < OtherPerson.age)
            return true;
        return false;
    }
};

int main() {
    Person p1("Oleguer", 24);
    Person p2("Elisenda", 21);

    std::deque<Person> people =
        {Person("a", 1), Person("c", 3), Person("d", 4), Person("b", 2)};

    std::sort(people.begin(), people.end());


    for (Person p : people) {
        std::cout << p.name << ", " << p.age << std::endl;
    }
}