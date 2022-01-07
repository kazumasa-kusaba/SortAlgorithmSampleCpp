#include <iostream>
#include <vector>

void down_heap(std::vector<int>& data, int from, int to)
{
  // TODO: write here
}

void heap_sort(std::vector<int>& data)
{
  // TODO: write here
}

int main(void)
{
  int size = 0;
  std::vector<int> data;

  std::cout << "Enter the size of data that you want to register: ";
  std::cin >> size;

  std::cout << "Enter the values" << std::endl;
  for (int i = 0; i < size; i++) {
    int val = 0;
    std::cout << i << ": ";
    std::cin >> val;
    data.push_back(val);
  }

  heap_sort(data);

  for (auto x: data) {
    std::cout << x << " ";
  }

  return 0;
}

