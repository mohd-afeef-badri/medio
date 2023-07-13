medio is a library that enables input and output of  mesh files for FreeFEM in `med` format. 

### Dependencies ##
- FreeFEM
- MedCoupling
- MPI

### Compilation with precompiled MedCoupling (install procedure 1)

Here is how a typical compilation process looks like. 

```bash 
autoreconf -i
```

```bash
./configure \
--prefix=/home/Work/tmp/medio \
--with-medcoupling=/home/Install/TarPackages/SALOME-9.10.0-native-UB22.04/BINARIES-UB22.04/MEDCOUPLING \
--with-medfile=/home/Install/TarPackages/SALOME-9.10.0-native-UB22.04/BINARIES-UB22.04/medfile         \
--with-hdf5=/home/Install/TarPackages/SALOME-9.10.0-native-UB22.04/BINARIES-UB22.04/hdf5
```

here,

-  medio will be installed in `/home/Work/tmp/medio/lib` 
- the root directories for `medcoupling` , `medfile`, and `hdf5` which come as precompiled with SALOME are provided `/home/Install/TarPackages/SALOME-9.10.0-native-UB22.04/BINARIES-UB22.04/`.  To get your precompiled SALOME click [here](https://www.salome-platform.org/?page_id=2433).
- finally FreeFEM is assumed to be installed, and present in your `$PATH`. If not use flag `--with-FreeFEM` to configure with FreeFEM installed elsewhere. 

```bash
make
```

```bash
make install
```

### Compilation with MedCoupling (install procedure 2)

Here is how a typical compilation process looks like. 

```bash 
autoreconf -i
```

```bash
./configure \
--prefix=/home/Work/tmp/medio \
--with-dependencies
```


here,

-  medio will be installed in `/home/Work/tmp/medio/lib`
- the root directories for `medcoupling`, `medfile`, and `hdf5` will be found in `ext/MEDCOUPLING-9.11.0-MPI/INSTALL`
- finally FreeFEM is assumed to be installed, and present in your `$PATH`. If not use flag `--with-FreeFEM` to configure with FreeFEM installed elsewhere. 

```bash
make
```

```bash
make install
```
### Check the compilation ###

```
make check
```

### Note ###

to use and run medio please make sure that your `$LD_LIBRARY_PATH` variable contains  `medcoupling`, `medfile`, and `hdf5`  paths. For example for the install above 

```bash
export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:/home/Install/TarPackages/SALOME-9.10.0-native-UB22.04/BINARIES-UB22.04/MEDCOUPLING/lib:/home/Install/TarPackages/SALOME-9.10.0-native-UB22.04/BINARIES-UB22.04/medfile/lib:/home/Install/TarPackages/SALOME-9.10.0-native-UB22.04/BINARIES-UB22.04/hdf5/lib
```

