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

/*
int loadmedfield(std::string &inputfile, std::string &meshname){

#ifdef DEBUG
  cout << "\n"
          "--------------------------------------\n"
          " loading med mesh \n"
          "--------------------------------------\n";
#endif

  return 0;
}
*/


template<class K>
class MedFileHandler_Op : public E_F0mps {
  public:
    Expression behaviourName                          ;

    static const int n_name_param = 4                 ;
    static basicAC_F0::name_and_type name_param[]     ;
    Expression nargs[n_name_param]                    ;

    MedFileHandler_Op(const basicAC_F0& args ,
        Expression param1
        ) :
      behaviourName     (param1)
  {
    args.SetNameParam( n_name_param       ,
        name_param            ,
        nargs
        )                     ;
  }
    AnyType operator()(Stack stack) const ;
};

template<class K>
basicAC_F0::name_and_type MedFileHandler_Op<K>::name_param[] =
{
  {"medfilename"         , &typeid(std::string*)},
  {"meshname"            , &typeid(std::string*)},
  {"fieldP0"             , &typeid(KN<K>*)      },
  {"fieldP1"             , &typeid(KN<K>*)      }  
};

template<class K>
class loadmedfield : public OneOperator {
  public:
    loadmedfield() : OneOperator(atype<long>()    ,
        atype<string*>()
        ) {}

    E_F0* code(const basicAC_F0& args) const {
      return new MedFileHandler_Op<K>(args,
          t[0]->CastTo(args[0])
          );
    }
};

template<class K>
AnyType MedFileHandler_Op<K>::operator()(Stack stack) const {

#ifdef DEBUG
  cout << "\n"
          "--------------------------------------\n"
          " loading med field \n"
          "--------------------------------------\n";
#endif

  const string* mfrontBehaviourName = GetAny<string*>((*behaviourName)(stack));

  string* medfilename         = nargs[0] ? GetAny<std::string*>((*nargs[0])(stack)) : NULL;
  string* meshname            = nargs[1] ? GetAny<std::string*>((*nargs[1])(stack)) : NULL;
  KN<K>*  fieldP0             = nargs[2] ? GetAny<KN<K>*>((*nargs[2])(stack))       : NULL;
  KN<K>*  fieldP1             = nargs[3] ? GetAny<KN<K>*>((*nargs[3])(stack))       : NULL;

  return 0L;
}
