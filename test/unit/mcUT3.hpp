/*****************************************************************************

     This file is a part of medio (input output med handler for FreeFEM)

     -------------------------------------------------------------------

     Author(s): Mohd Afeef Badri
     Email    : mohd-afeef.badri@cea.com
     Date     : 05/04/2022
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

int UnitTest3()
{

cout << "//-----------------------------------------------------------------//\n"
        "// Starting Unit Test 3\n"
        "//-----------------------------------------------------------------//\n";

cout << "   # creating mesh Node array \n";

// Nodes  of  the  3D mesh
// i.e x,y,z coordinates
double meshNodes[12]={
// x          y     z
0.,0.,1.,
0.,0.,0.,
0.,1.,1.,
1.,1.,1.
};

int  nNodes      = (sizeof(meshNodes)/sizeof(meshNodes[0]))/3;
int  nNodesArray = (sizeof(meshNodes)/sizeof(meshNodes[0]))  ;

cout << "   # creating cellConnectivity \n";


// Connectivity for the Cells
// of the 2D mesh
mcIdType cellConnectivity[48]={
0,1,2,3  // tetra
};

cout << "   # creating 3D mesh \n";

  // create mesh
  MEDCouplingUMesh *medMesh3d=MEDCouplingUMesh::New();

cout << "   # set basic attributes \n";

  // set basic attributes
  medMesh3d->setMeshDimension(3);          // dimension of the mesh
  medMesh3d->allocateCells(1);             // total number of cells
  medMesh3d->setName("TetrahedralMesh");   // name of mesh

cout << "   # add cells manually \n";

  // add cells manually
  medMesh3d->insertNextCell(INTERP_KERNEL::NORM_TETRA4,4,cellConnectivity);
  medMesh3d->finishInsertingCells();

//---------------------------------------------------------------------------------
// 0D mesh creation i.e the nodes
//---------------------------------------------------------------------------------

cout << "   # creating 0D mesh \n";

  // add nodes
  DataArrayDouble *myCoords=DataArrayDouble::New();
  myCoords->alloc(nNodes,3);                  // tottal number of points
  myCoords->setInfoOnComponent(0,"x [m]");    // info attribute on x
  myCoords->setInfoOnComponent(1,"y [m]");    // info attribute on y
  myCoords->setInfoOnComponent(2,"z [m]");    // info attribute on z
  std::copy(meshNodes, meshNodes+nNodesArray, myCoords->getPointer());
  medMesh3d->setCoords(myCoords);
  myCoords->decrRef();

//---------------------------------------------------------------------------------
// write mesh in med and vtu formats
//---------------------------------------------------------------------------------

cout << "   # write mesh in med and vtu \n";

  WriteUMesh("mcUT3.med",medMesh3d,true);
  medMesh3d->writeVTK("mcUT3n.vtu");

cout << "//----------------------//\n"
        "// End of Unit Test 3\n"
        "//----------------------//\n\n";

  return 1;
}
