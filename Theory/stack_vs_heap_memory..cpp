#include <iostream>
#include <string>

// Example class
struct Entity {
 private:
  std::string name_;

 public:
  Entity() : name_("Unknown") {}                    // Default constuctor
  Entity(const std::string& name) : name_(name) {}  // Constuctor

  const std::string& GetName() const { return name_; }
};

// Example of stack allocation
void allocate_in_stack() {
  Entity entity("oleguer");  // Value based: Local to this function stack frame
  std::cout << entity.GetName() << std::endl;

  // Pros:
  // - Faster allocation
  // - Automatically "destroyed" when scope is finished
  // Cons:
  // - Can only be used in this scope (between these brackets)
  // - Objects can't me very very big (bigger than 2 MB)
}

void allocate_in_heap() {
  Entity *entity = new Entity("oleguer");  // Created in heap
  std::cout << (*entity).GetName() << std::endl;  // Access pointer value
  std::cout << entity->GetName() << std::endl;  // Arrow automatically does this for us
  // Here we could do something like:
  // some_entity_pointer = entity;
  // This is not copying values, just setting another pointer

  // We have to free the memory allocated
  delete entity;
  // OBS: if we had assigned it to another pointer we could have fone:
  // delete some_entity_pointer

  // Pros:
  // - Control over life-span of the object
  // - Can hold bigger variables
  // Cons:
  // - Can lead into memory leaks
  // - Slower
}

int main() {
  allocate_in_stack();
  allocate_in_heap();

  // Summary:
  // Unless you need to use the entity in different fucntions, use
  // stack allocation
}