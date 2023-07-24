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

int UnitTest5()
{

cout << "//-----------------------------------------------------------------//\n"
        "// Starting Unit Test 5\n"
        "//-----------------------------------------------------------------//\n";

//---------------------------------------------------------------------------------
// read mesh in med
//---------------------------------------------------------------------------------

cout << "   # read mesh in med \n";

  MEDCouplingUMesh *mesh=ReadUMeshFromFile("mcUT3.med","TetrahedralMesh",0);
  cout << "      done reading " << endl;
  cout << "" << endl;

cout << "   # mesh attributes read from file \n";

  cout << "      mesh->getSpaceDimension()  :" << mesh->getSpaceDimension()<< endl;
  cout << "      mesh->getMeshDimension()   :" << mesh->getMeshDimension() << endl;
  cout << "      mesh->getNumberOfCells()   :" << mesh->getNumberOfCells() << endl;
  cout << "      mesh->getNumberOfNodes()   :" << mesh->getNumberOfNodes() << endl;
  cout << "" << endl;

  double *nodesRead ;
  nodesRead = mesh->getCoords()->getPointer();

cout << "   # mesh nodes info \n";

  for (int i=0; i < mesh->getNumberOfNodes()*mesh->getMeshDimension(); i++)
    cout << "       nodesRead["<<i<<"] " << nodesRead[i] << endl;
  cout << "" << endl;

cout << "   # mesh NodalConnectivity info \n";

  mcIdType *NodalConnectivity ;
  NodalConnectivity = mesh->getNodalConnectivity()->getPointer();
  for (int i=0; i < mesh->getNumberOfCells()*3+mesh->getNumberOfCells(); i++)
    cout << "       NodalConnectivity["<<i<<"] " << NodalConnectivity[i] << endl;
  cout << "" << endl;

cout << "   # mesh NodalConnectivityIndex info \n";

  mcIdType *NodalConnectivityIndex ;
  NodalConnectivityIndex = mesh->getNodalConnectivityIndex()->getPointer();
  for (int i=0; i < mesh->getNumberOfCells()+1; i++)
    cout << "       NodalConnectivityIndex["<<i<<"] " << NodalConnectivityIndex[i] << endl;
  cout << "" << endl;

  mesh->decrRef();

cout << "//----------------------//\n"
        "// End of Unit Test 5\n"
        "//----------------------//\n\n";

  return 1;

}
