/*****************************************************************************

     This file is a part of medio (input output med handler for FreeFEM)

     -------------------------------------------------------------------

     Author(s): Mohd Afeef Badri
     Email    : mohd-afeef.badri@cea.com
     Date     : 06/04/2022
     Comment  : The program collects functions needed by the medio

     -------------------------------------------------------------------

     medio is FreeFEM plugin intended to enable usage of med files meshes.
     medio is distributed   in  the  hope that it  will be useful, HOWEVER
     WITHOUT ANY WARRANTY;  or  without  even  implied warranty of FITNESS
     FOR A PARTICULAR PURPOSE.

*******************************************************************************/

#include "ff++.hpp"

#include "MEDLoader.hxx"
#include "MEDFileData.hxx"
using namespace MEDCoupling;

#include "medioSaveMedMesh.hpp"
#include "medioLoadMedMesh.hpp"
#include "medioGetGroupLabel.hpp"
#include "medioLoadMedField.hpp"
#include "medio.hpp"

using namespace std;
using namespace Fem2D;

static void InitFF()
{


  Global.Add("savemedmesh", "(", new OneOperator2_< int,  pmesh3, std::string* >(savemedmesh));
  Global.Add("savemedmesh", "(", new OneOperator2_< int,  pmesh,  std::string* >(savemedmesh));
  Global.Add("savemedmesh", "(", new OneOperator2_< int,  pmeshS, std::string* >(savemedmesh));
  Global.Add("savemedmesh", "(", new OneOperator2_< int,  pmeshL, std::string* >(savemedmesh));
//Global.Add("getMedLabelsOnGroup", "(", new OneOperator3s_< KN< long > *,  KN< long > *, std::string*, std::string* >(getMedLabelsOnGroup)); // also needs // #include "AFunction_ext.hpp"
  Global.Add("getMedLabelsOnGroup", "(", new OneOperator3_< int, KN< long > *, std::string*, std::string* >(getMedLabelsOnGroup));
  Global.Add("loadmedmesh", "(", new medloader);
  Global.Add("loadmedmesh3", "(", new medloader3);
  Global.Add("loadmedmeshS", "(", new medloaderS);
  Global.Add("loadmedmeshL", "(", new medloaderL);
}
LOADFUNC(InitFF)
