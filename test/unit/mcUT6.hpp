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

     Acknowledgements: Thanks to C. Bourcier for his advices and help
     with medCoupling.

*******************************************************************************/

int UnitTest6()
{

cout << "//-----------------------------------------------------------------//\n"
        "// Starting Unit Test 6\n"
        "//-----------------------------------------------------------------//\n";

//---------------------------------------------------------------------------------
// read mesh in medfile mesh
//---------------------------------------------------------------------------------

  MCAuto < MEDFileUMesh > finalMeshWithLabel = MEDFileUMesh::New("mcUT4.med");
  const DataArrayIdType * famIds  = finalMeshWithLabel->getFamilyFieldAtLevel(0);
  const DataArrayIdType * famIds1d  = finalMeshWithLabel->getFamilyFieldAtLevel(-1);

  for (int i=0; i < famIds->getNumberOfTuples(); i++)
    cout << " cell_family " << famIds->getIJ(i,0) << endl;

  for (int i=0; i < famIds1d->getNumberOfTuples(); i++)
    cout << " boundary_family " << famIds1d->getIJ(i,0) << endl;

  return 1;

}
