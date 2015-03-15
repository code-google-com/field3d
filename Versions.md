# Version history #

  * 1.2.0 ([r95](https://code.google.com/p/field3d/source/detail?r=95))
    * [Issue #18](https://code.google.com/p/field3d/issues/detail?id=#18) - Speed up reading of entire SparseFields
    * [Issue #21](https://code.google.com/p/field3d/issues/detail?id=#21) - CubicFieldInterp bug
    * [Issue #28](https://code.google.com/p/field3d/issues/detail?id=#28) - Add global metadata
    * [Issue #29](https://code.google.com/p/field3d/issues/detail?id=#29) - File I/O code uses dynamic\_pointer\_cast instead of field\_dynamic\_cast
    * [Issue #30](https://code.google.com/p/field3d/issues/detail?id=#30) - Prevent reading a field 3 times
    * [Issue #31](https://code.google.com/p/field3d/issues/detail?id=#31) - Overall SparseField caching improvements
    * [Issue #32](https://code.google.com/p/field3d/issues/detail?id=#32) - Replace multiple traits class to single DataTypeTraits
    * [Issue #33](https://code.google.com/p/field3d/issues/detail?id=#33) - Proxy fields should include metadata
    * [Issue #34](https://code.google.com/p/field3d/issues/detail?id=#34) - releaseBlocks() fails when blocks are partially in use
    * [Issue #35](https://code.google.com/p/field3d/issues/detail?id=#35) - Resizing DenseField does not re-allocate memory correctly
    * [Issue #36](https://code.google.com/p/field3d/issues/detail?id=#36) - FieldInterp classes should inherit from RefBase
    * [Issue #37](https://code.google.com/p/field3d/issues/detail?id=#37) - Disable HDF5 warnings unless DEBUG\_HDF is set.
    * [Issue #38](https://code.google.com/p/field3d/issues/detail?id=#38) - Silence class registration messages unless $FIELD3D\_DEBUG is set
    * [Issue #40](https://code.google.com/p/field3d/issues/detail?id=#40) - Race condition opportunity and observed multi-threading crash

  * 1.1.6 ([r78](https://code.google.com/p/field3d/source/detail?r=78))
    * Added 'f3dinfo' app
    * Moved some of the little test apps from apps/ into test/misc\_tests and apps/sample\_code
    * Field3DFile.cpp : parsePartition() will now skip "field3d\_global\_metadata". This is to ensure that .f3d files written using v1.2 of the library will be readable by v1.1.6. ([issue #19](https://code.google.com/p/field3d/issues/detail?id=#19))
  * 1.1.5 ([r63](https://code.google.com/p/field3d/source/detail?r=63))
    * CMake file added (contributed by Nicholas Yue)
    * Removed unused member variables in SparseField ([issue #24](https://code.google.com/p/field3d/issues/detail?id=#24))
    * BuildSupport.py: addField3DInstall now prepends paths to make sure they take precedence over any installed versions.
  * 1.1.4 ([r41](https://code.google.com/p/field3d/source/detail?r=41))
    * Exposing some utility methods in SparseField ([issue #12](https://code.google.com/p/field3d/issues/detail?id=#12))
  * 1.1.3 ([r40](https://code.google.com/p/field3d/source/detail?r=40))
    * Commenting and cleanup of SparseFile.h ([issue #11](https://code.google.com/p/field3d/issues/detail?id=#11))
  * 1.1.2 ([r38](https://code.google.com/p/field3d/source/detail?r=38))
    * Removed some spurious SPI:: namespaces that had snuck in with the SparseFileManager
  * 1.1.1 ([r35](https://code.google.com/p/field3d/source/detail?r=35))
    * Renamed Log -> Msg
    * Merged the various class factories into ClassFactory ([issue #4](https://code.google.com/p/field3d/issues/detail?id=#4))
    * Replaced str() function with explicit boost::lexical\_cast<> calls.
    * Added more Imath typedefs.
    * Implemented block cache for SparseField ([issue #2](https://code.google.com/p/field3d/issues/detail?id=#2))
    * Added base class for reference counted objects ([issue #5](https://code.google.com/p/field3d/issues/detail?id=#5))
    * FieldMapping: Added voxelToWorld that takes iterators.
    * Renamed LinearFieldInterp/CubicFieldInterp template to LinearGenericFieldInterp/CubicGenericFieldInterp
      * Uses the code from LinearDenseFieldInterp
    * Each concrete Field class now has LinearInterp and CubicInterp typedefs for easy access.
    * Added dataTypeToEnum traits function
    * Version handling in file reading code. Field3D can now specify a minimum version number that the library is compatible with.
  * 1.0.1 ([r29](https://code.google.com/p/field3d/source/detail?r=29))
    * FieldMapping intrusive pointers were not thread safe. Fixed. Also fixed reference count in copy constructor.
    * BuildSupport.py - bug fix for dealing with math header file
    * Changed required boost version to 1.34.0
  * 1.0.0 ([r12](https://code.google.com/p/field3d/source/detail?r=12))
    * Initial check-in