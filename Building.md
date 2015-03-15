# General information #

Field3D was originally developed under CentOS. It has also been tested under MacOS X Leopard.

By default, Field3D will look in your platform's standard directories for include files and libraries. If your libraries reside elsewhere, refer to the "Customizing the build environment" section below.

If you are compiling on an untested platform, you may need to extend the `systemIncludePaths` and `systemLibPaths` dictionaries in the file called _BuildSupport.py_.

# Building the Field3D library #

To build Field3D, go to the root directory and type `scons`. This will build a shared and a static library and place them in the _install_ folder. By default an optimized/release build is created.

To build a debug version, type `scons debug=1`.

To build a 64-bit version, type `scons do64=1`.

Once the install script has completed, you will find an _install_ folder in the project root. It contains several sub-directories, so that each platform, architecture and debug/release build has its own install area. This is done to ensure that multi-platform builds don't clobber each other's binary files.

The hierarchy follows the pattern: _install/platform/architecture/build\_type/{include,lib}_

For example, after compiling on OS X with all default settings, the following directory will be created:
  * _install/darwin/m32/release/include_
  * _install/darwin/m32/release/lib_.

# Building Field3D on Mac OS X #

Field3D has been built and tested under OS X 10.5. It probably works on older versions too, but this has not yet been tested.

MacPorts can be used to simplify the build process. First, download and install MacPorts if you haven't already done so. Downloads and instructions can be found at http://www.macports.org/

Once MacPorts is on your system, you can use it to install the libraries that Field3D depends on. Each library will take between a few minutes to an hour to install, so don't be alarmed if it seems nothing is happening.

In a terminal, type the following:
(You will be prompted for your password as `sudo` is required for MacPorts to be able to create the necessary directories)

```
  sudo port install scons
  sudo port install boost
  sudo port install hdf5-18
  sudo port install ilmbase
```

Once the installation process is complete, you can proceed to build the Field3D library as described in the "Building the Field3D library" section above.

# Customizing the build environment #

Field3D will look in your platform's standard directories for include files and libraries. If you need to add further library paths, include paths etc., add a _Site.py_ file in the root directory. The file ExampleSite.py can be used for reference.

# Using a custom math library #

The "Site.py" file can be used to change the math library used by Field3D. The only current requirement is that the other library is syntactically equivalent to Imath. At Sony Imageworks, the Imath library is wrapped in an "SPI" namespace - the _ExampleSite.py_ and _SpiMathLib.h_ files shows an example of how to configure it.

# Building with CMake #
At the source top level directory, create a subdirectory e.g. 'build'

Inside that subdirectory, create an executable script call e.g. build.sh

Inside the build.sh file, add the following content

```
#!/bin/sh
rm -f CMakeCache.txt
cmake ..
```

The purpose of doing all this in a subdirectory is for easy clean up after the build.