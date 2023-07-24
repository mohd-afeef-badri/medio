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

int UnitTest9()
{


cout << "//-----------------------------------------------------------------//\n"
        "// Starting Unit Test 9\n"
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
// get total mesh cells
//---------------------------------------------------------------------------------

cout << "   # get total mesh cells \n";
 mcIdType nbOfCells=mesh->getNumberOfCells();
cout << "" << endl;

//---------------------------------------------------------------------------------
// create field on cells
//---------------------------------------------------------------------------------

cout << "   # create field on cells \n"; 
 MEDCouplingFieldDouble *f1=MEDCouplingFieldDouble::New(ON_CELLS,ONE_TIME);
 f1->setName("VectorFieldOnCells"); // Also IntVectorFieldOnCells Int64VectorFieldOnCells FloatVectorFieldOnCells
 f1->setMesh(mesh);
cout << "" << endl;

//---------------------------------------------------------------------------------
// create data for cells attributes
//---------------------------------------------------------------------------------

cout << "   # create data for cells attributes \n"; 
  DataArrayDouble *array=DataArrayDouble::New(); 
  array->alloc(nbOfCells,3);
  f1->setArray(array);
  array->setInfoOnComponent(0,"power [MW/m^3]");
  array->setInfoOnComponent(1,"density [g/cm^3]");
  array->setInfoOnComponent(2,"temperature [K]");
  array->decrRef();
cout << "" << endl;

//---------------------------------------------------------------------------------
// create data
//---------------------------------------------------------------------------------

cout << "   # create data for cells \n";
  mcIdType nbData =  nbOfCells * 3; 
  double *tmp=array->getPointer();
  const double arr1[nbData]={
    1,1,1,2,2,2,3,3,3,4,4,4,5,5,5,6,6,6,7,7,7,8,8,8,9,9,9
  };
  std::copy(arr1,arr1+nbData,tmp);
  f1->setTime(2.12,2,3);  
cout << "" << endl;

//---------------------------------------------------------------------------------
// writing results in file
//---------------------------------------------------------------------------------

cout << "   # writing results in file \n";
  WriteField("mcUT4_field_cells.med",f1,true);
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
  MEDCouplingFieldDouble *f2=dynamic_cast<MEDCouplingFieldDouble *>(ReadFieldCell("mcUT4_field_cells.med","PolyMesh",0,"VectorFieldOnCells",2,3));
cout << "" << endl;

//---------------------------------------------------------------------------------
// writing results in file
//---------------------------------------------------------------------------------

cout << "   # writing results in file \n";
  WriteField("mcUT4_field_cells_out.med",f2,true);
cout << "" << endl;

//---------------------------------------------------------------------------------
// clean up 
//---------------------------------------------------------------------------------  

  f2->decrRef();

cout << "//----------------------//\n"
        "// End of Unit Test 9\n"
        "//----------------------//\n\n";

  return 1;

}
