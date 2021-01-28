#include "write_ppm.h"
#include <fstream>
#include <cassert>
#include <iostream>
#include <string>

bool write_ppm(
  const std::string & filename,
  const std::vector<unsigned char> & data,
  const int width,
  const int height,
  const int num_channels)
{
  assert(
    (num_channels == 3 || num_channels ==1 ) &&
    ".ppm only supports RGB or grayscale images");
  ////////////////////////////////////////////////////////////////////////////
  // Replace with your code here:
  ///////////////////////////////////////////////////////////////////////////

  //open the ppm file
  std::ofstream myfile (filename);
  if (myfile.is_open())
  {
    //add magic numbers at top of ppm file
    myfile << "P3 " + std::to_string(width) + " " + std::to_string(height) + " 255\n";

    //go throught our data array and correctly space them out - we alse typecaste to ints
    for(int i = 0; i < height; ++i){
      for(int j = 0; j< width; ++j) {
        for(int k = 0; k<3; k++){

          //case 1 check for first element in beginning of each row - might no be needed
          if(k == 0 && j == 0){
            myfile << (unsigned int)data[k + 3*(j + width*i)];
            myfile <<  " ";
          } 

          //case 2 check for when get back to r element - so we can group rgb rgb rgb... etc in the row
          else if(k == 0) {
            myfile << " " ; 
            myfile << (unsigned int)data[k + 3*(j + width*i)];
            myfile << " ";
          } else if(j == width-1){
            myfile << (unsigned int)data[k + 3*(j + width*i)];
            myfile << " \n";
          }
          else {
            myfile << (unsigned int)data[k + 3*(j + width*i)];
            myfile <<  " ";
          }
        }
      }
    }
    myfile.close();
    return true;
  }
  return false;
  ////////////////////////////////////////////////////////////////////////////
}
