/*****************************************************************************

     This file is a part of medio (input output med handler for FreeFEM)

     -------------------------------------------------------------------

     Author(s): Mohd Afeef Badri
     Email    : mohd-afeef.badri@cea.com
     Date     : 13/04/2022
     Comment  : The program test medcoupling for writing polygon mesh
                with polygon elements  without  border elements. This
                test  is  eventually used as building blocks for  the
                FreeFEM plugin medio.

     -------------------------------------------------------------------

     medio is FreeFEM plugin intended to enable usage of med files meshes.
     medio is distributed   in  the  hope that it  will be useful, HOWEVER
     WITHOUT ANY WARRANTY;  or  without  even  implied warranty of FITNESS
     FOR A PARTICULAR PURPOSE.

     -------------------------------------------------------------------

     Acknowledgments: Thanks to C. Bourcier for his advice and help
     with medCoupling.

*******************************************************************************/

int UnitTest7()
{


cout << "//-----------------------------------------------------------------//\n"
        "// Starting Unit Test 7\n"
        "//-----------------------------------------------------------------//\n";

//---------------------------------------------------------------------------------
// read mesh in med
//---------------------------------------------------------------------------------

cout << "   # read mesh in med \n";
  MCAuto < MEDFileUMesh > finalMeshWithLabel = MEDFileUMesh::New("mcUT4.med");
cout << "done reading " << endl;
cout << "" << endl;

//---------------------------------------------------------------------------------
// Get label list corresponding to boundary tag
//---------------------------------------------------------------------------------

cout << "   # Get label list corresponding to boundary tag \n";
  std::vector<long int> famIdsPruned = finalMeshWithLabel->getFamiliesIdsOnGroup("boundary");
  for (auto i: famIdsPruned)
    cout << " famIdsPruned - boundary  " << i << endl;
cout << "" << endl;


//---------------------------------------------------------------------------------
// Get label list corresponding to zone_3 tag
//---------------------------------------------------------------------------------

cout << "   # Get label list corresponding to zone_3 tag \n";
  std::vector<long int> famIdsPruned1 = finalMeshWithLabel->getFamiliesIdsOnGroup("zone_3");
  for (auto i: famIdsPruned1)
    cout << " famIdsPruned - zone_3  " << i << endl;
cout << "" << endl;

cout << "//----------------------//\n"
        "// End of Unit Test 7\n"
        "//----------------------//\n\n";

  return 1;

}
