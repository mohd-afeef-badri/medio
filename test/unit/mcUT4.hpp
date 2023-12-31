/*****************************************************************************

     This file is a part of medio (input output med handler for FreeFEM)

     -------------------------------------------------------------------

     Author(s): Mohd Afeef Badri
     Email    : mohd-afeef.badri@cea.com
     Date     : 05/04/2022
     Comment  : The program test medcoupling for writing polygon with
                few boundary lines and groups and famalies

     -------------------------------------------------------------------

     medio is FreeFEM plugin intended to enable usage of med files meshes.
     medio is distributed   in  the  hope that it  will be useful, HOWEVER
     WITHOUT ANY WARRANTY;  or  without  even  implied warranty of FITNESS
     FOR A PARTICULAR PURPOSE.

*******************************************************************************/

int UnitTest4()
{

cout << "//-----------------------------------------------------------------//\n"
        "// Starting Unit Test 4\n"
        "//-----------------------------------------------------------------//\n";

cout << "   # creating mesh Node array \n";

// Nodes  of  the  2D mesh
// i.e x and y coordinates
double meshNodes[48]={
// x          y
0.333333 ,0.166667,
0.166667 ,0.333333,
0.833333 ,0.166667,
0.666667 ,0.333333,
0.333333 ,0.666667,
0.166667 ,0.833333,
0.833333 ,0.666667,
0.666667 ,0.833333,
0	 ,0,
0.5	 ,0,
1	 ,0,
0	 ,0.5,
1	 ,0.5,
0	 ,1,
0.5	 ,1,
1	 ,1,
0.25	 ,0,
0.75	 ,0,
1	 ,0.25,
1	 ,0.75,
0.25	 ,1,
0.75	 ,1,
0	 ,0.25,
0	 ,0.75
};

int  nNodes      = (sizeof(meshNodes)/sizeof(meshNodes[0]))/2;
int  nNodesArray = (sizeof(meshNodes)/sizeof(meshNodes[0]))  ;

cout << "   # creating cellConnectivity \n";

// Connectivity for the Cells
// of the 2D mesh
mcIdType cellConnectivity[56]={
16, 0,  1,  22, 8,         // polygon
16, 9,  17, 2,  3,  0,     // polygon
17, 10, 18, 2,             // polygon
22, 1,  4,  5,  23, 11,    // polygon
0 ,3 , 6  ,7 , 4, 1,       // polygon
2 ,18, 12 ,19, 6, 3,       // polygon
23,5,  20 ,13,             // polygon
4 ,7 , 21 ,14 ,20, 5,      // polygon
6 ,19, 15 ,21, 7,          // polygon
22, 8,                     // line
8 ,16,                     // line
17, 9,                     // line
9 ,16,                     // line
};

//---------------------------------------------------------------------------------
// 2D mesh creation
//---------------------------------------------------------------------------------

cout << "   # creating 2D mesh \n";

  // create mesh for 2D polygons
  MEDCouplingUMesh *medMesh2d=MEDCouplingUMesh::New();

cout << "   # set basic attributes \n";

  // set basic attributes
  medMesh2d->setMeshDimension(2);           // dimension of the mesh
  medMesh2d->allocateCells(10);             // total number of cells
  medMesh2d->setName("PolyMesh");           // name of mesh

cout << "   # add cells manually \n";

  // add cells manually
  medMesh2d->insertNextCell(INTERP_KERNEL::NORM_POLYGON,5,cellConnectivity);
  medMesh2d->insertNextCell(INTERP_KERNEL::NORM_POLYGON,6,cellConnectivity+5);
  medMesh2d->insertNextCell(INTERP_KERNEL::NORM_POLYGON,4,cellConnectivity+11);
  medMesh2d->insertNextCell(INTERP_KERNEL::NORM_POLYGON,6,cellConnectivity+15);
  medMesh2d->insertNextCell(INTERP_KERNEL::NORM_POLYGON,6,cellConnectivity+21);
  medMesh2d->insertNextCell(INTERP_KERNEL::NORM_POLYGON,6,cellConnectivity+27);
  medMesh2d->insertNextCell(INTERP_KERNEL::NORM_POLYGON,4,cellConnectivity+33);
  medMesh2d->insertNextCell(INTERP_KERNEL::NORM_POLYGON,6,cellConnectivity+37);
  medMesh2d->insertNextCell(INTERP_KERNEL::NORM_POLYGON,5,cellConnectivity+43);
  medMesh2d->finishInsertingCells();

//---------------------------------------------------------------------------------
// 1D mesh creation
//---------------------------------------------------------------------------------

cout << "   # creating 1D mesh \n";

  // create mesh for 1D lines
  MEDCouplingUMesh *medMesh1d=MEDCouplingUMesh::New();

cout << "   # set basic attributes \n";

  // set basic attributes
  medMesh1d->setMeshDimension(1);           // dimension of the mesh
  medMesh1d->allocateCells(4);              // total number of lines
  medMesh1d->setName("PolyMesh");           // name of mesh

cout << "   # add cells manually \n";

  // add lines manually
  medMesh1d->insertNextCell(INTERP_KERNEL::NORM_SEG2,2,cellConnectivity+48);
  medMesh1d->insertNextCell(INTERP_KERNEL::NORM_SEG2,2,cellConnectivity+50);
  medMesh1d->insertNextCell(INTERP_KERNEL::NORM_SEG2,2,cellConnectivity+52);
  medMesh1d->insertNextCell(INTERP_KERNEL::NORM_SEG2,2,cellConnectivity+54);
  medMesh1d->finishInsertingCells();

//---------------------------------------------------------------------------------
// 0D mesh creation i.e the nodes
//---------------------------------------------------------------------------------

cout << "   # creating 2D mesh \n";

  // add nodes
  DataArrayDouble *myCoords=DataArrayDouble::New();
  myCoords->alloc(nNodes,2); // tottal number of points
  myCoords->setInfoOnComponent(0,"x [m]");
  myCoords->setInfoOnComponent(1,"y [m]");
  std::copy(meshNodes, meshNodes+nNodesArray, myCoords->getPointer());
  medMesh2d->setCoords(myCoords);
  medMesh1d->setCoords(myCoords);
  myCoords->decrRef();


//---------------------------------------------------------------------------------
// Create high level API med mesh (MedFile)
//---------------------------------------------------------------------------------

cout << "   # Create high level API med mesh (MedFile) \n";

  MCAuto<MEDFileUMesh> finalMesh = MEDFileUMesh::New();
  finalMesh->setMeshAtLevel(0 ,medMesh2d);
  finalMesh->setMeshAtLevel(-1,medMesh1d);

//---------------------------------------------------------------------------------
// Create families associated
//---------------------------------------------------------------------------------

cout << "   # Create families associated \n";

  MCAuto<DataArrayIdType> fam2d = DataArrayIdType::New();
  MCAuto<DataArrayIdType> fam1d = DataArrayIdType::New();

  fam2d->alloc(9,1);
  fam1d->alloc(4,1);

  mcIdType elemsFams[13] = {-1,-2,-2,-2,-2,-2,-3,-3,-3,3,3,3,3};

  std::copy(elemsFams  ,elemsFams+9 ,fam2d->getPointer());
  std::copy(elemsFams+9,elemsFams+13,fam1d->getPointer());

  finalMesh->setFamilyFieldArr(-1,fam1d);
  finalMesh->setFamilyFieldArr(0,fam2d);

  std::map<std::string,mcIdType> theFamilies;
  theFamilies["cell_zone_1"]=-1;
  theFamilies["cell_zone_2"]=-2;
  theFamilies["cell_zone_3"]=-3;
  theFamilies["border_zone_1"]=3;

//---------------------------------------------------------------------------------
// Create groups associated
//---------------------------------------------------------------------------------

cout << "   # Create groups associated \n";

  std::map<std::string, std::vector<std::string> > theGroups;
  theGroups["zone_1"].push_back("cell_zone_1");
  theGroups["zone_2"].push_back("cell_zone_2");
  theGroups["zone_3"].push_back("cell_zone_3");
  theGroups["boundary"].push_back("border_zone_1");

  finalMesh->setFamilyInfo(theFamilies);
  finalMesh->setGroupInfo(theGroups);

//---------------------------------------------------------------------------------
// write mesh in med
//---------------------------------------------------------------------------------

cout << "   # write mesh in med \n";

  finalMesh->write("mcUT4.med",2);          // med

cout << "//----------------------//\n"
        "// End of Unit Test 4\n"
        "//----------------------//\n\n";

  return 1;
}
