# JoltC
C interface to the Jolt physics engine v5.6.0

## Why a new JoltC?
The main purpose of this interface is to be a proxy to other languages such as Jai, with [JoltC-BindGen](https://github.com/ostef/JoltC-BindGen/). As such they are maybe a bit less convenient to use in C.

Other C bindings:
* [amerkoleci/joltc](https://github.com/amerkoleci/joltc)
* [zig-gamedev/zphysics](https://github.com/zig-gamedev/zphysics/tree/main/libs/JoltC)
* [SecondHalfGames/JoltC](https://github.com/SecondHalfGames/JoltC/)

## How to build
This project uses CMake to integrate with Jolt Physics. JoltPhysics is automatically downloaded if not present, but if you want to use a local version put it in ./JoltPhysics or ../JoltPhysics.

Additional options are:
* JOLTC_BUILD_SHARED_LIBS: Build JoltC as a shared library
* JOLTC_BUILD_COMBINED_SHARED_LIBS: Build Jolt and JoltC as one combined shared library

```
> cmake -B .build
> cmake --build .build
```

## Not implemented yet
The following parts of Jolt are not yet implemented:
* Shape casts and extended collision queries
* Constraints
* Character
* Skeleton and Ragdoll
* Vehicles
