#include <iostream>
#include <vector>

void down_heap(std::vector<int>& data, int from, int to)
{
  int i, j;
  int val = data[from];

  i = from;
  while (i <= to / 2) {
    j = i * 2;
    if (j + 1 <= to && data[j + 1] < data[j]) {
      j += 1;
    }

    if (val <= data[j]) {
      break;
    }

    data[i] = data[j];
    i = j;
  }

  data[i] = val;
}

void heap_sort(std::vector<int>& data)
{
  int n = data.size();

  // build heap
  for (int i = n / 2; 1 <= i; i--) {
    down_heap(data, i, n);
  }

  // sort
  for (int i = n; 2 <= i; i--) {
    std::swap(data[1], data[i]);
    down_heap(data, 1, i - 1);
  }
}

int main(void)
{
  int size = 0;
  std::vector<int> data;

  // this program doesn't use the first element.
  data.push_back(-1);

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

  for (int i = 1; i < data.size(); i++) {
    std::cout << data[i] << " ";
  }

  return 0;
}

