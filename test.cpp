// lower_bound/upper_bound example
#include <iostream>     // std::cout
#include <algorithm>    // std::lower_bound, std::upper_bound, std::sort
#include <vector>       // std::vector

int main () {
  int myints[] = {10,20,30,40,50,60,70,80};
  std::vector<int> v(myints,myints+8);           // 10 20 30 30 20 10 10 20

  std::sort (v.begin(), v.end());                // 10 10 10 20 20 20 30 30

  int low,up;
  low=std::binary_search (v.begin(), v.end(), 90); //          ^
  //up= std::upper_bound (v.begin(), v.end(), 30) - v.begin(); //                   ^

  std::cout << " at position " << low << '\n';
  //std::cout << "upper_bound at position " << up << '\n';

  return 0;
}