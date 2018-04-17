// Quicksort
// 
// Author: Rob Gysel
// ECS60, UC Davis
// Adapted from: Lysecky & Vahid "Data Structures Essentials", zyBooks

#include <vector>

void QuickSort(std::vector<int>* numbers, int& memAccess, int& comp);
void QuickSortRecurse(std::vector<int>* numbers, int i, int k, int& memAccess, int& comp);
int Partition(std::vector<int>* numbers, int i, int k, int& memAccess, int& comp);