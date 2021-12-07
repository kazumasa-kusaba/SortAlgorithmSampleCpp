#include <iostream>
#include <vector>

int partition(std::vector<int>& data, int left, int right)
{
  int i = left - 1;
  int j = right;
  int pivot = data[right];
  int t = 0;

  while (1) {
    while (data[++i] < pivot);

    while (i < --j && pivot < data[j]);

    if (i >= j) break;

    t = data[i];
    data[i] = data[j];
    data[j] = t;
  }

  t = data[i];
  data[i] = pivot;
  data[right] = t;

  return i;
}

void quick_sort(std::vector<int>& data, int left, int right)
{
  int v = 0;

  if (left >= right) {
    return;
  }

  v = partition(data, left, right);

  quick_sort(data, left,  v - 1);
  quick_sort(data, v + 1, right);
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

  quick_sort(data, 0, data.size() - 1);

  for (auto x: data) {
    std::cout << x << " ";
  }

  return 0;
}

