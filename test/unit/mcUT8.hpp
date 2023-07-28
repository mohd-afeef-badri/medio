/*****************************************************************************

     This file is a part of medio (input output med handler for FreeFEM)

     -------------------------------------------------------------------

     Author(s): Mohd Afeef Badri
     Email    : mohd-afeef.badri@cea.com
     Date     : 24/07/2023
     Comment  : The program test medcoupling for writing polygon mesh
                with polygon elements  without  border elements. This
                test  is  eventually used as building blocks for  the
                FreeFEM plugin medio.

     -------------------------------------------------------------------

     medio is FreeFEM plugin intended to enable usage of med files meshes.
     medio is distributed   in  the  hope that it  will be useful, HOWEVER
     WITHOUT ANY WARRANTY;  or  without  even  implied warranty of FITNESS
     FOR A PARTICULAR PURPOSE.

*******************************************************************************/

int UnitTest8()
{


cout << "//-----------------------------------------------------------------//\n"
        "// Starting Unit Test 8\n"
        "//-----------------------------------------------------------------//\n";

//---------------------------------------------------------------------------------
// read mesh in med
//---------------------------------------------------------------------------------

cout << "   # read mesh in med \n";
  //MCAuto < MEDFileUMesh > finalMeshWithLabel = MEDFileUMesh::New("mcUT4.med");
  MEDCouplingUMesh *mesh=ReadUMeshFromFile("mcUT4.med","PolyMesh",0);
cout << "done reading " << endl;
cout << "" << endl;

//---------------------------------------------------------------------------------
// get total mesh nodes
//---------------------------------------------------------------------------------

cout << "   # get total mesh nodes \n";
 mcIdType nbOfNodes=mesh->getNumberOfNodes();
cout << "" << endl;

//---------------------------------------------------------------------------------
// create field on nodes
//---------------------------------------------------------------------------------

cout << "   # create field on nodes \n"; 
 MEDCouplingFieldDouble *f1=MEDCouplingFieldDouble::New(ON_NODES,ONE_TIME);
 f1->setName("VectorFieldOnNodes");
 f1->setMesh(mesh);
cout << "" << endl;

//---------------------------------------------------------------------------------
// create data for nodes attributes
//---------------------------------------------------------------------------------

cout << "   # create data for nodes attributes \n"; 
  DataArrayDouble *array=DataArrayDouble::New(); 
  array->alloc(nbOfNodes,3);
  f1->setArray(array);
  array->setInfoOnComponent(0,"power [MW/m^3]");
  array->setInfoOnComponent(1,"density [g/cm^3]");
  array->setInfoOnComponent(2,"temperature [K]");
  array->decrRef();
cout << "" << endl;

//---------------------------------------------------------------------------------
// create data for nodes
//---------------------------------------------------------------------------------

cout << "   # create data for nodes \n";
  mcIdType nbData =  nbOfNodes * 3; 
  double *tmp=array->getPointer();
  const double arr1[nbData]={
    11,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,
    111,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,
    1111,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24
  };
  std::copy(arr1,arr1+nbData,tmp);
  f1->setTime(2.12,2,3);  
cout << "" << endl;

//---------------------------------------------------------------------------------
// writing results in file
//---------------------------------------------------------------------------------

cout << "   # writing results in file \n";
  WriteField("mcUT4_field_nodes.med",f1,true);
cout << "" << endl;


//---------------------------------------------------------------------------------
// clean up 
//---------------------------------------------------------------------------------
  
  mesh->decrRef();
  f1->decrRef();

//---------------------------------------------------------------------------------
// read mesh and field in med
//---------------------------------------------------------------------------------

cout << "   # read mesh and field in med \n"; 
  MEDCouplingFieldDouble *f2=dynamic_cast<MEDCouplingFieldDouble *>(ReadFieldNode("mcUT4_field_nodes.med","PolyMesh",0,"VectorFieldOnNodes",2,3));
cout << "" << endl;

double *nodesRead=f2->getArray()->getPointer();
for (int i = 0; i < nbData; i++)
   cout << "f2 [ " << i << " ] = " <<  nodesRead[i] << endl;


//---------------------------------------------------------------------------------
// writing results in file
//---------------------------------------------------------------------------------

cout << "   # writing results in file \n";
  WriteField("mcUT4_field_nodes_out.med",f2,true);
cout << "" << endl;

//---------------------------------------------------------------------------------
// clean up 
//---------------------------------------------------------------------------------  

  f2->decrRef();
  
cout << "//----------------------//\n"
        "// End of Unit Test 8\n"
        "//----------------------//\n\n";

  return 1;

}
