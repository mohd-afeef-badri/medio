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

    static const int n_name_param = 5                 ;
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
  {"meshname"            , &typeid(std::string*)},
  {"fieldname"           , &typeid(std::string*)},
  {"field"               , &typeid(KN<K>*)      },
  {"order"               , &typeid(long*)       },
  {"iteration"           , &typeid(long*)       }
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

  const string* medfilename   = GetAny<string*>((*behaviourName)(stack));

  string* meshname            = nargs[0] ? GetAny<std::string*>((*nargs[0])(stack)) : NULL;
  string* fieldname           = nargs[1] ? GetAny<std::string*>((*nargs[1])(stack)) : NULL;
  KN<K>*  field               = nargs[2] ? GetAny<KN<K>*>((*nargs[2])(stack))       : NULL;
  long*   order               = nargs[3] ? GetAny<long*>((*nargs[3])(stack))        : NULL;
  long*   iteration           = nargs[4] ? GetAny<long*>((*nargs[4])(stack))        : NULL;

  if(meshname == NULL) {
    cout << " \n"
         << " \033[1;36m [loadmedfield] cannot work no meshname provided     :: \033[0m " << *meshname
         << " \n"
         << endl;

    exit(111);
    }

  if(fieldname == NULL) {
    cout << " \n"
         << " \033[1;36m [loadmedfield] cannot work no fieldname provided     :: \033[0m " << *fieldname
         << " \n"
         << endl;

    exit(111);
    }

  if(medfilename!=NULL && verbosity)
    cout << " \n"
         << " \033[1;36m [loadmedfield]  medfilename :: \033[0m " << *medfilename
         << " \n"
         << endl;

  if(meshname!=NULL && verbosity)
    cout << " \n"
         << " \033[1;36m [loadmedfield]  meshname :: \033[0m " << *meshname
         << " \n"
         << endl;

  if(fieldname!=NULL && verbosity)
    cout << " \n"
         << " \033[1;36m [loadmedfield]  fieldname :: \033[0m " << *fieldname
         << " \n"
         << endl;

  int nbFields   = field->n;

  int orderField = 1;
  if(nargs[3])
    orderField=*order;

  int iterationField = 1;
  if(nargs[4])
    iterationField=*iteration;


  if(verbosity) cout << " \033[1;36m [loadmedfield]  reading file   :: \033[0m "<< *medfilename
                     << " \033[1;36m reading mesh   :: \033[0m " << *meshname
                     << " \033[1;36m reading field  :: \033[0m " << *fieldname
                     << " \033[1;36m iterationField :: \033[0m " << iterationField
                     << " \033[1;36m orderField     :: \033[0m " << orderField;

  MEDCouplingFieldDouble *f2 = dynamic_cast<MEDCouplingFieldDouble *>(ReadFieldNode( *medfilename, *meshname , 0, *fieldname , iterationField, orderField));


  double *nodesRead=f2->getArray()->getPointer();

  for (int i = 0; i < nbFields; i++){
#ifdef DEBUG
   cout << "nodesRead [ " << i << " ] = " <<  nodesRead[i] << endl;
#endif
   field->operator[](i) = nodesRead[i];
   }

  return 0L;
}
