#include "rgba_to_rgb.h"
#include <iostream>

void rgba_to_rgb(
  const std::vector<unsigned char> & rgba,
  const int & width,
  const int & height,
  std::vector<unsigned char> & rgb)
{
  rgb.resize(height*width*3);
  ////////////////////////////////////////////////////////////////////////////
  // Add your code here
  ////////////////////////////////////////////////////////////////////////////

  // we need to iterate throught the array skipping every 4th element which represents alpha
  for(int i = 0; i < height; ++i) {
    for(int j = 0; j < width; ++j){
      for(int k = 0; k < 4; ++k) {
        if(k != 3) {
          rgb[k + 3*(j + width*i)] = rgba[k + 4*(j + width*i)];
        }
      }
    }
  }

}
