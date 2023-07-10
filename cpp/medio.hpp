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

//------------------------------------------------------------
// medloader for loading 2D med file to a FreeFEM mesh //
//------------------------------------------------------------
class medloader_Op : public E_F0mps
{
public:
    Expression filename			                ;

    static const int n_name_param = 1		        ;
    static basicAC_F0::name_and_type name_param[]	;
    Expression nargs[n_name_param]			;

    medloader_Op(const basicAC_F0& args		,
                      Expression param1
                     ) :
        filename     (param1)
    {
        args.SetNameParam(n_name_param	,
                          name_param	,
                          nargs
                         )		;
    }

    AnyType operator()(Stack stack) const		;
};


basicAC_F0::name_and_type medloader_Op::name_param[] =
{
    {"meshname", &typeid(std::string*)}
};

class medloader : public OneOperator
{
public:
  medloader() : OneOperator(atype< pmesh >( ), atype< string * >( )) {}

  E_F0 *code(const basicAC_F0 &args) const {
    return new medloader_Op(args, t[0]->CastTo(args[0]));
  }
};

AnyType medloader_Op::operator()(Stack stack) const
{
  string* inputfile  = GetAny<string*>((*filename)(stack))	;
  string* meshname   = nargs[0] ? GetAny<std::string*>((*nargs[0])(stack)) : NULL;

  Mesh *Th = loadmed(*inputfile, *meshname);
  Add2StackOfPtr2FreeRC(stack, Th);
  return Th;
}



//------------------------------------------------------------
// medloader for loading 3D med file to a FreeFEM mesh //
//------------------------------------------------------------
class medloader3_Op : public E_F0mps
{
public:
    Expression filename			                ;

    static const int n_name_param = 1		        ;
    static basicAC_F0::name_and_type name_param[]	;
    Expression nargs[n_name_param]			;

 public:
    medloader3_Op(const basicAC_F0& args		,
                      Expression param1
                     ) :
        filename     (param1)
    {
        args.SetNameParam(n_name_param	,
                          name_param	,
                          nargs
                         )		;
    }

    AnyType operator()(Stack stack) const		;
};


basicAC_F0::name_and_type medloader3_Op::name_param[] =
{
    {"meshname", &typeid(std::string*)}
};

class medloader3 : public OneOperator
{
public:
  medloader3() : OneOperator(atype< pmesh3 >( ), atype< string * >( )) {}

  E_F0 *code(const basicAC_F0 &args) const {
    return new medloader3_Op(args, t[0]->CastTo(args[0]));
  }
};

AnyType medloader3_Op::operator()(Stack stack) const
{
  string* inputfile  = GetAny<string*>((*filename)(stack))	;
  string* meshname   = nargs[0] ? GetAny<std::string*>((*nargs[0])(stack)) : NULL;

  Mesh3 *Th3 = loadmed3(*inputfile, *meshname);
  Add2StackOfPtr2FreeRC(stack, Th3);
  return Th3;
}



//------------------------------------------------------------
// medloader for loading 3DS med file to a FreeFEM mesh //
//------------------------------------------------------------
class medloaderS_Op : public E_F0mps
{
public:
    Expression filename			                ;

    static const int n_name_param = 1		        ;
    static basicAC_F0::name_and_type name_param[]	;
    Expression nargs[n_name_param]			;

 public:
    medloaderS_Op(const basicAC_F0& args		,
                      Expression param1
                     ) :
        filename     (param1)
    {
        args.SetNameParam(n_name_param	,
                          name_param	,
                          nargs
                         )		;
    }

    AnyType operator()(Stack stack) const		;
};


basicAC_F0::name_and_type medloaderS_Op::name_param[] =
{
    {"meshname", &typeid(std::string*)}
};

class medloaderS : public OneOperator
{
public:
  medloaderS() : OneOperator(atype< pmeshS >( ), atype< string * >( )) {}

  E_F0 *code(const basicAC_F0 &args) const {
    return new medloaderS_Op(args, t[0]->CastTo(args[0]));
  }
};

AnyType medloaderS_Op::operator()(Stack stack) const
{
  string* inputfile  = GetAny<string*>((*filename)(stack))	;
  string* meshname   = nargs[0] ? GetAny<std::string*>((*nargs[0])(stack)) : NULL;

  MeshS *ThS = loadmedS(*inputfile, *meshname);
  Add2StackOfPtr2FreeRC(stack, ThS);
  return ThS;
}



//------------------------------------------------------------
// medloader for loading 3DL med file to a FreeFEM mesh //
//------------------------------------------------------------
class medloaderL_Op : public E_F0mps
{
public:
    Expression filename			                ;

    static const int n_name_param = 1		        ;
    static basicAC_F0::name_and_type name_param[]	;
    Expression nargs[n_name_param]			;

 public:
    medloaderL_Op(const basicAC_F0& args		,
                      Expression param1
                     ) :
        filename     (param1)
    {
        args.SetNameParam(n_name_param	,
                          name_param	,
                          nargs
                         )		;
    }

    AnyType operator()(Stack stack) const		;
};


basicAC_F0::name_and_type medloaderL_Op::name_param[] =
{
    {"meshname", &typeid(std::string*)}
};

class medloaderL : public OneOperator
{
public:
  medloaderL() : OneOperator(atype< pmeshL >( ), atype< string * >( )) {}

  E_F0 *code(const basicAC_F0 &args) const {
    return new medloaderL_Op(args, t[0]->CastTo(args[0]));
  }
};

AnyType medloaderL_Op::operator()(Stack stack) const
{
  string* inputfile  = GetAny<string*>((*filename)(stack))	;
  string* meshname   = nargs[0] ? GetAny<std::string*>((*nargs[0])(stack)) : NULL;

  MeshL *ThL = loadmedL(*inputfile, *meshname);
  Add2StackOfPtr2FreeRC(stack, ThL);
  return ThL;
}
