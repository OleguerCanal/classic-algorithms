// Sortable objects tests

#include "stdlib.h"
#include "iostream"
#include <algorithm>
#include <string>
#include <deque>
#include <vector>
#include <queue>

class Person {
  public:
    std::string name;
    int age;

    Person(std::string PersonName, int PersonAge) :
        name(PersonName), age(PersonAge) {}
    
    bool operator< (const Person OtherPerson) {
        return (age < OtherPerson.age);
    }

    bool operator> (const Person OtherPerson) {
        return (age > OtherPerson.age);
    }
};

// struct PersonComparator {
//     // Return true if p1 < p2
//     bool operator() (Person p1, Person p2) {
//         if (p1.age < p2.age)
//             return true;
//         return false;
//     }
// };

int main() {
    Person p1("Oleguer", 24);
    Person p2("Elisenda", 21);

    // std::vector<Person> people =
    //     {Person("a", 1), Person("c", 3), Person("d", 4), Person("b", 2)};

    // PersonComparator comp;
    // std::sort(people.begin(), people.end(), comp);
    std::cout << (p1 < p2) << std::endl;

    // std::priority_queue<Person> people;
    // people.push(Person("a", 1));
    // people.push(Person("d", 4));
    // people.push(Person("b", 2));
    // people.push(Person("e", 5));
    // people.push(Person("c", 3));

    // // for (Person p : people) {
    // //     std::cout << p.name << ", " << p.age << std::endl;
    // // }
    // while (!people.empty()) {
    //     Person p = people.top();
    //     std::cout << p.name << ", " << p.age << std::endl;
    //     people.pop();
    // }
}