#include <iostream>
#include "./vector/vector.hpp"
#include "./list/list.hpp"
#include "./container/container.hpp"
#include "./zmytest/test.hpp"
#include <random>

int main()
{

  // char a;

  // for (int i = 0; i < 5; i++)
  // {
  //   std::default_random_engine generator(std::random_device{}());
  //   std::uniform_int_distribution<char> distribution('a', 'z');
  //   a = distribution(generator);
  //   std::cout << a;
  // }
  // std::cout << std::endl;

  lasd::List<int> *list = new lasd::List<int>();
  list->InsertAtFront(3);
  std::cout << list->Front() << std::endl;
  std::cout << list->Size() << std::endl;

  list->InsertAtBack(7);
  std::cout << list->Back() << std::endl;
  list->FrontNRemove();
  std::cout << list->Size()<< std::endl;
  std::cout << list->Front() << std::endl;

  std::string ciao = ("ciao");
  std::cout << ciao << std::endl;
  for(int i = 0; i < 4; i++){
    ciao[i] = toupper(ciao[i]);
  }
  std::cout << ciao << std::endl;
}
