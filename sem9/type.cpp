#include <iostream>

class UserId {
private:  
  int id_;

public:
  explicit UserId(int id) : id_(id) {
  }

  explicit operator int() {
    return id_;
  }

  UserId& operator+=(const UserId& other) {
    id_ += other.id_;
    return *this;
  }
};

class GroupId {
private:  
  int id_;

public:
  explicit GroupId(int id) : id_(id) {
  }

  explicit operator int() {
    return id_;
  }
};

void IncrementUserId(UserId& user, int id) {
  user += UserId(id);
}

void foo(int id) {
  std::cout << id;
}

int main() {
  UserId user(100);
  GroupId group(123);
  
  IncrementUserId(user, (int)(group));
 
  // A(B)
  // B -> A

  // B b;
  // A a = b;

  //foo(user);

  return 0;
}

