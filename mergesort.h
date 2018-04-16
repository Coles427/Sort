// Merge Sort
// 
// Author: Rob Gysel
// ECS60, UC Davis
// Adapted from: Lysecky & Vahid "Data Structures Essentials", zyBooks

#include <vector>

void MergeSort(std::vector<int>* numbers, int& memAccess, int&comp);
void MergeSortRecurse(std::vector<int>* numbers, int i, int k, int& memAccess, int& comp);
void Merge(std::vector<int>* numbers, int i, int j, int k, int& memAccess, int& comp);