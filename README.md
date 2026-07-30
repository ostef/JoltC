# JoltC
C interface to the Jolt physics engine v5.6.0

## How to build
This project uses CMake to integrate with Jolt Physics. JoltPhysics is automatically downloaded if not present, but if you want to use a local version put it in ./JoltPhysics or ../JoltPhysics.

Additional options are:
* JOLTC_BUILD_SHARED_LIBS: Build JoltC as a shared library
* JOLTC_BUILD_COMBINED_SHARED_LIBS: Build Jolt and JoltC as one combined shared library

```
> cmake -B .build
> cmake --build .build
```
