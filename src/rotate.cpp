#include "rotate.h"

void rotate(
  const std::vector<unsigned char> & input,
  const int width,
  const int height,
  const int num_channels,
  std::vector<unsigned char> & rotated)
{
  //rotated.resize(height*width*num_channels);
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

  for(int i = temp[0].size()-1 ; i >= 0; --i) {
    for(int j = 0; j < temp.size(); ++j){
      for(int k = 0; k < num_channels; ++k) {
        rotated.push_back(temp[j][i][k]);
      }
    }
  }

}
