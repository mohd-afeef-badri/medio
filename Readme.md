Medio is a library designed to facilitate the input and output of mesh files for FreeFEM in the `med` format native mesh format from (an open-source pre/post processing tool).

Medio is a library designed to facilitate the input and output of mesh files for FreeFEM in the `med` format, which is the native mesh format utilized by [SALOME](https://www.salome-platform.org/), an open-source pre/post-processing tool known for its robust capabilities in computational engineering and simulation.

Medio bridges the gap between FreeFEM and SALOME, enabling seamless data exchange and promoting interoperability between these powerful tools.

### Dependencies ##
To compile and use Medio, you will need the following dependencies:
- FreeFEM
- MedCoupling
- MPI

### Compilation with precompiled MedCoupling (install procedure 1)

Below, we present a step-by-step guide on how to compile and install Medio with precompiled MedCoupling support for FreeFEM:

##### Prepare the Build Configuration: #####
Run the following command to prepare the build configuration:
```bash 
autoreconf -i
```
##### Configure the Build: #####
Now, let's configure the build by specifying the necessary options using the `configure` script:
```bash
./configure \
--prefix=/home/Work/tmp/medio \
--with-medcoupling=/home/Install/TarPackages/SALOME-9.10.0-native-UB22.04/BINARIES-UB22.04/MEDCOUPLING \
--with-medfile=/home/Install/TarPackages/SALOME-9.10.0-native-UB22.04/BINARIES-UB22.04/medfile         \
--with-hdf5=/home/Install/TarPackages/SALOME-9.10.0-native-UB22.04/BINARIES-UB22.04/hdf5
```

In this configuration:
-  medio will be installed in the  `/home/Work/tmp/medio/lib` directory. You can choose a directory that you wish to install medio.  
- The root directories for `medcoupling` , `medfile`, and `hdf5` which come as precompiled with SALOME are provided `/home/Install/TarPackages/SALOME-9.10.0-native-UB22.04/BINARIES-UB22.04/`.  To get your precompiled SALOME click [here](https://www.salome-platform.org/?page_id=2433).
- To proceed with the build, ensure that FreeFEM is already installed and available in your  `$PATH`. If not use flag `--with-FreeFEM` to configure with FreeFEM installed elsewhere.

Please note you will need to adapt each flag to your specific system. 

##### Compile medio: #####
With the configuration set, it's time to compile medio and make sure it is ready for use:
```bash
make
```

##### Install medio: #####
Once the compilation process is successful, proceed to install medio using the following command:
```bash
make install
```
By following these steps, you should have successfully compiled and installed medio linked with precompiled MedCoupling support for FreeFEM.

### Compilation with MedCoupling (install procedure 2)

Here is a step-by-step guide for the typical compilation process:

##### Prepare the Build Configuration: #####

Begin by running the following command to set up the build configuration:
```bash 
autoreconf -i
```

##### Configure the Build: #####
Next, use the `configure` script to configure the build with the required options:
```bash
./configure \
--prefix=/home/Work/tmp/medio \
--with-dependencies
```


In this configuration:

-  medio will be installed in the  `/home/Work/tmp/medio/lib` directory. You can choose a directory that you wish to install medio.  
- After successfull install, the root directories for medcoupling, medfile, and hdf5 will be automatically located in `ext/MEDCOUPLING-9.11.0-MPI/INSTALL`.
-  Ensure that FreeFEM is already installed and available in your `$PATH`. If not use flag `--with-FreeFEM` to configure with FreeFEM installed elsewhere. 

##### Compile medio: #####
With the configuration set, it's time to compile medio and make sure it is ready for use:
```bash
make
```

##### Install medio: #####
Once the compilation process is successful, proceed to install medio using the following command:
```bash
make install
```
By following these steps, you should have successfully compiled and installed medio linked with MedCoupling support for FreeFEM.


### Check the compilation ###
To ensure a successful compilation, you can run the following command to perform checks:
```
make check
```

### Note ###

to use and run medio please make sure that your `$LD_LIBRARY_PATH` variable contains  `medcoupling`, `medfile`, and `hdf5`  paths. For example for the install above 

```bash
export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:/home/Install/TarPackages/SALOME-9.10.0-native-UB22.04/BINARIES-UB22.04/MEDCOUPLING/lib:/home/Install/TarPackages/SALOME-9.10.0-native-UB22.04/BINARIES-UB22.04/medfile/lib:/home/Install/TarPackages/SALOME-9.10.0-native-UB22.04/BINARIES-UB22.04/hdf5/lib
```
By following these steps, you will have successfully compiled and installed Medio with MedCoupling support for FreeFEM, allowing smooth mesh file handling and data exchange between FreeFEM and SALOME. Don't forget to set the necessary environment variables to ensure seamless operation. Enjoy utilizing the power and efficiency of medio in your computational simulations!
