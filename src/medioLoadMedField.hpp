/*****************************************************************************

     This file is a part of medio (input output med handler for FreeFEM)

     -------------------------------------------------------------------

     Author(s): Mohd Afeef Badri
     Email    : mohd-afeef.badri@cea.com
     Date     : 24/07/2023
     Comment  : The program collects functions needed by the medio

     -------------------------------------------------------------------

     medio is FreeFEM plugin intended to enable usage of med files meshes.
     medio is distributed   in  the  hope that it  will be useful, HOWEVER
     WITHOUT ANY WARRANTY;  or  without  even  implied warranty of FITNESS
     FOR A PARTICULAR PURPOSE.

*******************************************************************************/

//------------------------------------------------------------------------------
// loadmedfield: function to load med field for a 2D mesh for a FreeFEM mesh object
//               This functions   expects  three  inputs i) the mesh file name, and
//               ii) the name of the mesh in med mesh and iii) FE variable to fill object.
//------------------------------------------------------------------------------

int loadmedfield(std::string &inputfile, std::string &meshname){

#ifdef DEBUG
  cout << "\n"
          "--------------------------------------\n"
          " loading med mesh \n"
          "--------------------------------------\n";
#endif

  return 0;
}
