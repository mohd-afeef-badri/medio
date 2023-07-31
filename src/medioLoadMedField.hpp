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




// ------------------------------------------------------------------------------
//
// C++ template class named `MedFileHandler_Op`, which is derived from FreeFEM's
// `E_F0mps` class. The class handles operations involving  MED  to read fields.
//
//  1. `template<class K>:` This is a template class, with a template parameter K
//      specified to determine the behavior of the class for different data types.
//
//  2.  `Expression behaviourName:` declares a member variable named `medFileName`
//      of type Expression. It represents the name or identifier of the med.
//
//  3.  `static const int n_name_param:` declares a static constant for # of named]
//       parameters used in the class.
//
//  4.  `static basicAC_F0::name_and_type name_param[]:`  declares a  static array]
//      `name_param` to store names of parameters and their types.
//
//  5.  `Expression nargs[n_name_param]:` an array of Expression objects `nargs`
//      to be used to store expression objects for each name parameter.
//
//  6.  `MedFileHandler_Op(const basicAC_F0& args, Expression param1):` constructor
//      of the `MedFileHandler_Op` class. Tkes two arguments: `args` and `param1`.
//      This initializes `medFileName` member variable with the value `param1`.
//
//  7.  `AnyType operator()(Stack stack) const;:` declares a  member function  named
//       `operator()` that takes a single argument stack of type `Stack` and returns
//       `AnyType`.
//
// ------------------------------------------------------------------------------

template<class K>
class MedFileHandler_Op : public E_F0mps {
  public:
    Expression medFileName                            ;

    static const int n_name_param = 6                 ;
    static basicAC_F0::name_and_type name_param[]     ;
    Expression nargs[n_name_param]                    ;

    MedFileHandler_Op(const basicAC_F0& args ,
        Expression param1
        ) :
      medFileName     (param1)
  {
    args.SetNameParam( n_name_param       ,
        name_param            ,
        nargs
        )                     ;
  }
    AnyType operator()(Stack stack) const ;
};

// ------------------------------------------------------------------------------
//
// a  static array named `name_param` provides structured way to access & handle
// the names and types of parameters used in the `MedFileHandler_Op` class
//
// The array elements are structured as follows:
//
//    "meshname": [std::string] mesh name of the target mesh in the med file.
//    "fieldname": [std::string] target field name in the med file.
//    "field":  [double[int]] output the field read in the med file too this.
//    "order": [int] to be used for vector fields default value -1 for scalar.
//    "iteration": [int] target iteration (time-iteration).
//    "type": [std::string] type of data to read, [FLOAT] or [DOUBLE].
//
// ------------------------------------------------------------------------------

template<class K>
basicAC_F0::name_and_type MedFileHandler_Op<K>::name_param[] =
{
  {"meshname"            , &typeid(std::string*)},
  {"fieldname"           , &typeid(std::string*)},
  {"field"               , &typeid(KN<K>*)      },
  {"order"               , &typeid(long*)       },
  {"iteration"           , &typeid(long*)       },
  {"type"                , &typeid(std::string*)}
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

  const string* medfilename   = GetAny<string*>((*medFileName)(stack));

  string* meshname            = nargs[0] ? GetAny<std::string*>((*nargs[0])(stack)) : NULL;
  string* fieldname           = nargs[1] ? GetAny<std::string*>((*nargs[1])(stack)) : NULL;
  KN<K>*  field               = nargs[2] ? GetAny<KN<K>*>((*nargs[2])(stack))       : NULL;
  long*   order               = nargs[3] ? GetAny<long*>((*nargs[3])(stack))        : NULL;
  long*   iteration           = nargs[4] ? GetAny<long*>((*nargs[4])(stack))        : NULL;
  string* type                = nargs[5] ? GetAny<std::string*>((*nargs[5])(stack)) : NULL;

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

  int orderField = -1;                  // Default value of med (seems so: Thanks to Christian VAN WAMBEKE)
  if(nargs[3])
    orderField=*order;

  int iterationField = -1;              // Default value of med (seems so: Thanks to Christian VAN WAMBEKE)
  if(nargs[4])
    iterationField=*iteration;

  string typeField = "DOUBLE";          // Default value of med (seems so: Thanks to Christian VAN WAMBEKE)
  if(nargs[5])
    typeField=*type;

  if(verbosity) cout << " \033[1;36m [loadmedfield]    \033[0m "
                     << "\n   \033[1;36m reading file   :: \033[0m " << *medfilename
                     << "\n   \033[1;36m reading mesh   :: \033[0m " << *meshname
                     << "\n   \033[1;36m reading field  :: \033[0m " << *fieldname
                     << "\n   \033[1;36m iterationField :: \033[0m " << iterationField
                     << "\n   \033[1;36m orderField     :: \033[0m " << orderField
                     << "\n   \033[1;36m typeField      :: \033[0m " << typeField
                     << "\n"
                     << endl;

  if(typeField == "FLOAT") {

    MEDCouplingFieldFloat *f2 = dynamic_cast<MEDCouplingFieldFloat *>(ReadFieldNode( *medfilename, *meshname , 0, *fieldname , iterationField, orderField));

    if(verbosity) cout << " \033[1;36m [loadmedfield]  Finished reading FLOAT fields \033[0m" << endl;

    float *nodesRead=f2->getArray()->getPointer();

    for (int i = 0; i < nbFields; i++) {
#ifdef DEBUG
     cout << "nodesRead [ " << i << " ] = " <<  nodesRead[i] << endl;
#endif
     field->operator[](i) = nodesRead[i];
    }
  }
  else if(typeField == "DOUBLE") {
    MEDCouplingFieldDouble *f2 = dynamic_cast<MEDCouplingFieldDouble *>(ReadFieldNode( *medfilename, *meshname , 0, *fieldname , iterationField, orderField));

    if(verbosity) cout << " \033[1;36m [loadmedfield]  Finished reading DOUBLE fields \033[0m" << endl;

    double *nodesRead=f2->getArray()->getPointer();

    for (int i = 0; i < nbFields; i++) {
#ifdef DEBUG
     cout << "nodesRead [ " << i << " ] = " <<  nodesRead[i] << endl;
#endif
     field->operator[](i) = nodesRead[i];
    }
  }
  else {
    if(verbosity) cout << " \033[1;31m [loadmedfield]  Not recognized type for fields \033[0m" << endl;
  }



  return 0L;
}
