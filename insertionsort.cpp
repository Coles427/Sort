// Insertion Sort
// 
// Author: Rob Gysel
// ECS60, UC Davis
// Adapted from: Lysecky & Vahid "Data Structures Essentials", zyBooks

#include "insertionsort.h"

void InsertionSort(std::vector<int>* numbers, int& memAccess, int& comp) {
   int i = 0;
   int j = 0;
   int temp = 0;  // Temporary variable for swap
   
   for (i = 1; i < numbers->size(); ++i) {
      j = i;
      // Insert numbers[i] into sorted part
      // stopping once numbers[i] in correct position
      while (j > 0 && (*numbers)[j] < (*numbers)[j - 1]) {
         memAccess += 2;
          // Swap numbers[j] and numbers[j - 1]
         temp = (*numbers)[j];
         memAccess++;
         (*numbers)[j] = (*numbers)[j - 1];
         memAccess += 2;
         (*numbers)[j - 1] = temp;
         memAccess ++;
         --j;
         ++comp;
      }
       if(j!= 0){++comp; memAccess += 2;}


   }
   
   return;
}