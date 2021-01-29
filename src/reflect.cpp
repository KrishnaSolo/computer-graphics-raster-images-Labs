#include "reflect.h"
#include "iostream"

void reflect(
  const std::vector<unsigned char> & input,
  const int width,
  const int height,
  const int num_channels,
  std::vector<unsigned char> & reflected)
{
  reflected.resize(width*height*num_channels);
  ////////////////////////////////////////////////////////////////////////////
  // Add your code here
  ////////////////////////////////////////////////////////////////////////////

  std::vector<std::vector<std::vector<unsigned char>>> temp(height);
  for(int i = 0; i < height; ++i) {
    std::vector<std::vector<unsigned char>> tmp(width);
    for(int j = 0; j < width; ++j){
      std::vector<unsigned char> t(num_channels);
      for(int k = 0; k < 3; ++k) {
        t[k] = input[k + 3*(j + width*i)];
      }
      tmp[j] = t;  
    }
    temp[i]=tmp;
  }

  for(int i = 0; i < temp.size(); ++i) {
    std::reverse(temp[i].begin(), temp[i].end());
    for(int j = 0; j < temp[i].size(); ++j){
      for(int k = 0; k < temp[i][j].size(); ++k) {
        reflected[k + 3*(j + width*i)] = temp[i][j][k];
      }
    }
  }
}
