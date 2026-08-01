#pragma once

#ifdef _MSC_VER
#define JOLTC_SUPPRESS_WARNINGS() \
    __pragma(warning (push)) \
    __pragma(warning (disable : 4127)) \
    __pragma(warning (disable : 4514)) \
    __pragma(warning (disable : 4100))

#define JOLTC_POP_WARNINGS() __pragma(warning (pop))
#else
#define JOLTC_SUPPRESS_WARNINGS()
#define JOLTC_POP_WARNINGS()
#endif

#ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable : 4820) // Padding added after data member
#endif

#include <JoltC.h>

#ifdef _MSC_VER
#pragma warning(pop)
#endif

#include <Jolt/Jolt.h>

#include <Jolt/Jolt.h>
#include <Jolt/RegisterTypes.h>
#include <Jolt/Core/Factory.h>
#include <Jolt/Core/TempAllocator.h>
#include <Jolt/Core/JobSystemSingleThreaded.h>
#include <Jolt/Core/JobSystemThreadPool.h>
#include <Jolt/Geometry/AABox.h>
#include <Jolt/Geometry/OrientedBox.h>
#include <Jolt/Geometry/Plane.h>
#include <Jolt/Physics/PhysicsSettings.h>
#include <Jolt/Physics/PhysicsSystem.h>
#include <Jolt/Physics/Collision/BroadPhase/BroadPhaseLayerInterfaceMask.h>
#include <Jolt/Physics/Collision/BroadPhase/ObjectVsBroadPhaseLayerFilterMask.h>
#include <Jolt/Physics/Collision/ObjectLayerPairFilterMask.h>
#include <Jolt/Physics/Collision/BroadPhase/BroadPhaseLayerInterfaceTable.h>
#include <Jolt/Physics/Collision/BroadPhase/ObjectVsBroadPhaseLayerFilterTable.h>
#include <Jolt/Physics/Collision/ObjectLayerPairFilterTable.h>
#include <Jolt/Physics/Collision/CastResult.h>
#include <Jolt/Physics/Collision/CollidePointResult.h>
#include <Jolt/Physics/Collision/CollideShape.h>
#include <Jolt/Physics/Collision/CollisionCollectorImpl.h>
#include <Jolt/Physics/Collision/CollisionDispatch.h>
#include <Jolt/Physics/Collision/EstimateCollisionResponse.h>
#include <Jolt/Physics/Collision/ShapeCast.h>
#include <Jolt/Physics/Collision/AABoxCast.h>
#include <Jolt/Physics/Collision/SimShapeFilter.h>
#include <Jolt/Physics/Collision/Shape/PlaneShape.h>
#include <Jolt/Physics/Collision/Shape/BoxShape.h>
#include <Jolt/Physics/Collision/Shape/SphereShape.h>
#include <Jolt/Physics/Collision/Shape/TriangleShape.h>
#include <Jolt/Physics/Collision/Shape/CapsuleShape.h>
#include <Jolt/Physics/Collision/Shape/TaperedCapsuleShape.h>
#include <Jolt/Physics/Collision/Shape/CylinderShape.h>
#include <Jolt/Physics/Collision/Shape/TaperedCylinderShape.h>
#include <Jolt/Physics/Collision/Shape/ConvexHullShape.h>
#include <Jolt/Physics/Collision/Shape/MeshShape.h>
#include <Jolt/Physics/Collision/Shape/HeightFieldShape.h>
#include <Jolt/Physics/Collision/Shape/StaticCompoundShape.h>
#include <Jolt/Physics/Collision/Shape/MutableCompoundShape.h>
#include <Jolt/Physics/Collision/Shape/DecoratedShape.h>
#include <Jolt/Physics/Collision/Shape/RotatedTranslatedShape.h>
#include <Jolt/Physics/Collision/Shape/ScaledShape.h>
#include <Jolt/Physics/Collision/Shape/OffsetCenterOfMassShape.h>
#include <Jolt/Physics/Collision/Shape/EmptyShape.h>
#include <Jolt/Physics/Body/BodyCreationSettings.h>
#include <Jolt/Physics/Body/BodyActivationListener.h>
#include <Jolt/Physics/SoftBody/SoftBodyCreationSettings.h>
#include <Jolt/Physics/Collision/RayCast.h>
#include <Jolt/Physics/Collision/BroadPhase/BroadPhaseQuery.h>
#include <Jolt/Physics/Collision/NarrowPhaseQuery.h>
#include <Jolt/Physics/Constraints/SpringSettings.h>
#include <Jolt/Physics/Constraints/FixedConstraint.h>
#include <Jolt/Physics/Constraints/PointConstraint.h>
#include <Jolt/Physics/Constraints/DistanceConstraint.h>
#include <Jolt/Physics/Constraints/HingeConstraint.h>
#include <Jolt/Physics/Constraints/SliderConstraint.h>
#include <Jolt/Physics/Constraints/ConeConstraint.h>
#include <Jolt/Physics/Constraints/SwingTwistConstraint.h>
#include <Jolt/Physics/Constraints/SixDOFConstraint.h>
#include <Jolt/Physics/Constraints/GearConstraint.h>
#include <Jolt/Physics/Constraints/PulleyConstraint.h>
#include <Jolt/Physics/Constraints/PathConstraintPath.h>
#include <Jolt/Physics/Constraints/PathConstraintPathHermite.h>
#include <Jolt/Physics/Constraints/PathConstraint.h>
#include <Jolt/Physics/Constraints/RackAndPinionConstraint.h>
#include <Jolt/Physics/Character/Character.h>
#include <Jolt/Physics/Character/CharacterVirtual.h>
#include <Jolt/Physics/Collision/PhysicsMaterialSimple.h>
#include <Jolt/Physics/Collision/GroupFilterTable.h>
#include <Jolt/Physics/Body/BodyLockMulti.h>
#include <Jolt/Physics/Ragdoll/Ragdoll.h>
#include <Jolt/Physics/Vehicle/WheeledVehicleController.h>
#include <Jolt/Physics/Vehicle/MotorcycleController.h>
#include <Jolt/Physics/Vehicle/TrackedVehicleController.h>

#ifdef JOLTC_DEBUG_RENDERER
#include <Jolt/Renderer/DebugRenderer.h>
#include <Jolt/Renderer/DebugRendererSimple.h>
#endif

#define DEFINE_CONVERSION_FUNCTIONS(c_type, cpp_type) \
    static inline const cpp_type &ToCpp(const c_type &v) { \
        return reinterpret_cast<const cpp_type &>(v); \
    } \
    static inline const cpp_type *ToCpp(const c_type *v) { \
        return reinterpret_cast<const cpp_type *>(v); \
    } \
    static inline cpp_type &ToCpp(c_type &v) { \
        return reinterpret_cast<cpp_type &>(v); \
    } \
    static inline cpp_type *ToCpp(c_type *v) { \
        return reinterpret_cast<cpp_type *>(v); \
    } \
    static inline const c_type &ToC(const cpp_type &v) { \
        return reinterpret_cast<const c_type &>(v); \
    } \
    static inline const c_type *ToC(const cpp_type *v) { \
        return reinterpret_cast<const c_type *>(v); \
    } \
    static inline c_type &ToC(cpp_type &v) { \
        return reinterpret_cast<c_type &>(v); \
    } \
    static inline c_type *ToC(cpp_type *v) { \
        return reinterpret_cast<c_type *>(v); \
    }

#define BEGIN_INTERFACE_WRAPPER_CLASS(name) \
    class name##Wrapper final : public JPH::name { \
    private: \
        void *data; \
        JPH_##name##_Funcs funcs; \
        JPH_JoltCAllocator allocator; \
    \
    public: \
        void operator delete (void *ptr) noexcept                { JPH_JoltCAllocator allocator = reinterpret_cast<name##Wrapper *>(ptr)->allocator; JPH_JoltCAllocator_Free(allocator, ptr); } \
        void operator delete (void *ptr, size_t size) noexcept   { JPH_JoltCAllocator allocator = reinterpret_cast<name##Wrapper *>(ptr)->allocator; JPH_JoltCAllocator_Free(allocator, ptr); } \
        void operator delete[] (void *ptr) noexcept              { JPH_JoltCAllocator allocator = reinterpret_cast<name##Wrapper *>(ptr)->allocator; JPH_JoltCAllocator_Free(allocator, ptr); } \
        void operator delete[] (void *ptr, size_t size) noexcept { JPH_JoltCAllocator allocator = reinterpret_cast<name##Wrapper *>(ptr)->allocator; JPH_JoltCAllocator_Free(allocator, ptr); } \
    \
        name##Wrapper(void *data, JPH_##name##_Funcs funcs, JPH_JoltCAllocator allocator) \
            : data(data), funcs(funcs), allocator(allocator) { \
        } \
    \
        name##Wrapper() = delete; \
        name##Wrapper(const name##Wrapper &) = delete; \
        name##Wrapper &operator=(const name##Wrapper &) = delete; \
    \
        virtual ~name##Wrapper() override { \
            if (funcs.Destruct) { \
                funcs.Destruct(data); \
            } \
        }

#define END_INTERFACE_WRAPPER_CLASS() };

#define DEFINE_INTERFACE_WRAPPER_FUNCTIONS(name) \
    JPH_##name *JPH_##name##_Create(void *data, JPH_##name##_Funcs funcs, JPH_JoltCAllocator allocator) { \
        void *ptr = JPH_JoltCAllocator_Allocate(allocator, sizeof(name##Wrapper)); \
        return ToC(new(ptr) name##Wrapper(data, funcs, allocator)); \
    } \
    \
    void JPH_##name##_Destroy(JPH_##name *self) { \
        delete ToCpp(self); \
    }

DEFINE_CONVERSION_FUNCTIONS(JPH_Float3, JPH::Float3);
DEFINE_CONVERSION_FUNCTIONS(JPH_Vec3, JPH::Vec3);
DEFINE_CONVERSION_FUNCTIONS(JPH_DVec3, JPH::DVec3);
DEFINE_CONVERSION_FUNCTIONS(JPH_Vec4, JPH::Vec4);
DEFINE_CONVERSION_FUNCTIONS(JPH_UVec4, JPH::UVec4);
DEFINE_CONVERSION_FUNCTIONS(JPH_Mat44, JPH::Mat44);
DEFINE_CONVERSION_FUNCTIONS(JPH_DMat44, JPH::DMat44);
DEFINE_CONVERSION_FUNCTIONS(JPH_Quat, JPH::Quat);
DEFINE_CONVERSION_FUNCTIONS(JPH_AABox, JPH::AABox);
DEFINE_CONVERSION_FUNCTIONS(JPH_Plane, JPH::Plane);
DEFINE_CONVERSION_FUNCTIONS(JPH_OrientedBox, JPH::OrientedBox);

DEFINE_CONVERSION_FUNCTIONS(JPH_PhysicsSystem, JPH::PhysicsSystem);
DEFINE_CONVERSION_FUNCTIONS(JPH_PhysicsStepListener, JPH::PhysicsStepListener);
DEFINE_CONVERSION_FUNCTIONS(JPH_PhysicsStepListenerContext, JPH::PhysicsStepListenerContext);
DEFINE_CONVERSION_FUNCTIONS(JPH_BodyInterface, JPH::BodyInterface);
DEFINE_CONVERSION_FUNCTIONS(JPH_BodyLockInterface, JPH::BodyLockInterface);
DEFINE_CONVERSION_FUNCTIONS(JPH_TempAllocator, JPH::TempAllocator);
DEFINE_CONVERSION_FUNCTIONS(JPH_TempAllocatorImpl, JPH::TempAllocatorImpl);
DEFINE_CONVERSION_FUNCTIONS(JPH_TempAllocatorImplWithMallocFallback, JPH::TempAllocatorImplWithMallocFallback);
DEFINE_CONVERSION_FUNCTIONS(JPH_TempAllocatorMalloc, JPH::TempAllocatorMalloc);
DEFINE_CONVERSION_FUNCTIONS(JPH_JobSystem, JPH::JobSystem);
DEFINE_CONVERSION_FUNCTIONS(JPH_JobSystemThreadPool, JPH::JobSystemThreadPool);
DEFINE_CONVERSION_FUNCTIONS(JPH_JobSystemSingleThreaded, JPH::JobSystemSingleThreaded);
DEFINE_CONVERSION_FUNCTIONS(JPH_SharedMutex, JPH::SharedMutex);

// Collision

DEFINE_CONVERSION_FUNCTIONS(JPH_BroadPhaseLayerInterface, JPH::BroadPhaseLayerInterface);
DEFINE_CONVERSION_FUNCTIONS(JPH_BroadPhaseLayerInterfaceTable, JPH::BroadPhaseLayerInterfaceTable);
DEFINE_CONVERSION_FUNCTIONS(JPH_BroadPhaseLayerInterfaceMask, JPH::BroadPhaseLayerInterfaceMask);
DEFINE_CONVERSION_FUNCTIONS(JPH_ObjectLayerPairFilter, JPH::ObjectLayerPairFilter);
DEFINE_CONVERSION_FUNCTIONS(JPH_ObjectLayerPairFilterTable, JPH::ObjectLayerPairFilterTable);
DEFINE_CONVERSION_FUNCTIONS(JPH_ObjectLayerPairFilterMask, JPH::ObjectLayerPairFilterMask);
DEFINE_CONVERSION_FUNCTIONS(JPH_ObjectVsBroadPhaseLayerFilter, JPH::ObjectVsBroadPhaseLayerFilter);
DEFINE_CONVERSION_FUNCTIONS(JPH_ObjectVsBroadPhaseLayerFilterTable, JPH::ObjectVsBroadPhaseLayerFilterTable);
DEFINE_CONVERSION_FUNCTIONS(JPH_ObjectVsBroadPhaseLayerFilterMask, JPH::ObjectVsBroadPhaseLayerFilterMask);
DEFINE_CONVERSION_FUNCTIONS(JPH_BroadPhaseLayerFilter, JPH::BroadPhaseLayerFilter);
DEFINE_CONVERSION_FUNCTIONS(JPH_ObjectLayerFilter, JPH::ObjectLayerFilter);
DEFINE_CONVERSION_FUNCTIONS(JPH_GroupFilter, JPH::GroupFilter);
DEFINE_CONVERSION_FUNCTIONS(JPH_BodyFilter, JPH::BodyFilter);
DEFINE_CONVERSION_FUNCTIONS(JPH_IgnoreMultipleBodiesFilter, JPH::IgnoreMultipleBodiesFilter);
DEFINE_CONVERSION_FUNCTIONS(JPH_IgnoreSingleBodyFilter, JPH::IgnoreSingleBodyFilter);
DEFINE_CONVERSION_FUNCTIONS(JPH_IgnoreSingleBodyFilterChained, JPH::IgnoreSingleBodyFilterChained);
DEFINE_CONVERSION_FUNCTIONS(JPH_ShapeFilter, JPH::ShapeFilter);
DEFINE_CONVERSION_FUNCTIONS(JPH_ReversedShapeFilter, JPH::ReversedShapeFilter);
DEFINE_CONVERSION_FUNCTIONS(JPH_BroadPhaseQuery, JPH::BroadPhaseQuery);
DEFINE_CONVERSION_FUNCTIONS(JPH_NarrowPhaseQuery, JPH::NarrowPhaseQuery);
DEFINE_CONVERSION_FUNCTIONS(JPH_RayCast, JPH::RayCast);
DEFINE_CONVERSION_FUNCTIONS(JPH_RRayCast, JPH::RRayCast);
DEFINE_CONVERSION_FUNCTIONS(JPH_RayCastResult, JPH::RayCastResult);
DEFINE_CONVERSION_FUNCTIONS(JPH_BroadPhaseCastResult, JPH::BroadPhaseCastResult);
DEFINE_CONVERSION_FUNCTIONS(JPH_RayCastSettings, JPH::RayCastSettings);
DEFINE_CONVERSION_FUNCTIONS(JPH_AABoxCast, JPH::AABoxCast);
DEFINE_CONVERSION_FUNCTIONS(JPH_RShapeCast, JPH::RShapeCast);
DEFINE_CONVERSION_FUNCTIONS(JPH_CollideShapeSettings, JPH::CollideShapeSettings);
DEFINE_CONVERSION_FUNCTIONS(JPH_ShapeCastSettings, JPH::ShapeCastSettings);
DEFINE_CONVERSION_FUNCTIONS(JPH_ShapeCastResult, JPH::ShapeCastResult);
DEFINE_CONVERSION_FUNCTIONS(JPH_CollidePointResult, JPH::CollidePointResult);
DEFINE_CONVERSION_FUNCTIONS(JPH_CollideShapeResult, JPH::CollideShapeResult);

DEFINE_CONVERSION_FUNCTIONS(JPH_RayCastBodyCollector, JPH::RayCastBodyCollector);
DEFINE_CONVERSION_FUNCTIONS(JPH_CastShapeBodyCollector, JPH::CastShapeBodyCollector);
DEFINE_CONVERSION_FUNCTIONS(JPH_CollideShapeBodyCollector, JPH::CollideShapeBodyCollector);

DEFINE_CONVERSION_FUNCTIONS(JPH_CastRayCollector, JPH::CastRayCollector);
DEFINE_CONVERSION_FUNCTIONS(JPH_CastShapeCollector, JPH::CastShapeCollector);
DEFINE_CONVERSION_FUNCTIONS(JPH_CollidePointCollector, JPH::CollidePointCollector);
DEFINE_CONVERSION_FUNCTIONS(JPH_CollideShapeCollector, JPH::CollideShapeCollector);
DEFINE_CONVERSION_FUNCTIONS(JPH_TransformedShapeCollector, JPH::TransformedShapeCollector);

#ifdef JOLTC_DEBUG_RENDERER

DEFINE_CONVERSION_FUNCTIONS(JPH_DebugRenderer, JPH::DebugRenderer);
DEFINE_CONVERSION_FUNCTIONS(JPH_BodyDrawFilter, JPH::BodyDrawFilter);

#endif

DEFINE_CONVERSION_FUNCTIONS(JPH_PhysicsMaterial, JPH::PhysicsMaterial);

// Shapes

DEFINE_CONVERSION_FUNCTIONS(JPH_Shape, JPH::Shape);
DEFINE_CONVERSION_FUNCTIONS(JPH_ConvexShape, JPH::ConvexShape);
DEFINE_CONVERSION_FUNCTIONS(JPH_SphereShape, JPH::SphereShape);
DEFINE_CONVERSION_FUNCTIONS(JPH_BoxShape, JPH::BoxShape);
DEFINE_CONVERSION_FUNCTIONS(JPH_PlaneShape, JPH::PlaneShape);
DEFINE_CONVERSION_FUNCTIONS(JPH_TriangleShape, JPH::TriangleShape);
DEFINE_CONVERSION_FUNCTIONS(JPH_CapsuleShape, JPH::CapsuleShape);
DEFINE_CONVERSION_FUNCTIONS(JPH_TaperedCapsuleShape, JPH::TaperedCapsuleShape);
DEFINE_CONVERSION_FUNCTIONS(JPH_CylinderShape, JPH::CylinderShape);
DEFINE_CONVERSION_FUNCTIONS(JPH_TaperedCylinderShape, JPH::TaperedCylinderShape);
DEFINE_CONVERSION_FUNCTIONS(JPH_ConvexHullShape, JPH::ConvexHullShape);
DEFINE_CONVERSION_FUNCTIONS(JPH_CompoundShape, JPH::CompoundShape);
DEFINE_CONVERSION_FUNCTIONS(JPH_StaticCompoundShape, JPH::StaticCompoundShape);
DEFINE_CONVERSION_FUNCTIONS(JPH_MutableCompoundShape, JPH::MutableCompoundShape);
DEFINE_CONVERSION_FUNCTIONS(JPH_MeshShape, JPH::MeshShape);
DEFINE_CONVERSION_FUNCTIONS(JPH_HeightFieldShape, JPH::HeightFieldShape);
DEFINE_CONVERSION_FUNCTIONS(JPH_DecoratedShape, JPH::DecoratedShape);
DEFINE_CONVERSION_FUNCTIONS(JPH_RotatedTranslatedShape, JPH::RotatedTranslatedShape);
DEFINE_CONVERSION_FUNCTIONS(JPH_ScaledShape, JPH::ScaledShape);
DEFINE_CONVERSION_FUNCTIONS(JPH_OffsetCenterOfMassShape, JPH::OffsetCenterOfMassShape);
DEFINE_CONVERSION_FUNCTIONS(JPH_EmptyShape, JPH::EmptyShape);

DEFINE_CONVERSION_FUNCTIONS(JPH_TransformedShape, JPH::TransformedShape);

// Body

DEFINE_CONVERSION_FUNCTIONS(JPH_Body, JPH::Body);
DEFINE_CONVERSION_FUNCTIONS(JPH_BodyID, JPH::BodyID);
DEFINE_CONVERSION_FUNCTIONS(JPH_MotionProperties, JPH::MotionProperties);

DEFINE_CONVERSION_FUNCTIONS(JPH_IndexedTriangle, JPH::IndexedTriangle);
DEFINE_CONVERSION_FUNCTIONS(JPH_MassProperties, JPH::MassProperties);
DEFINE_CONVERSION_FUNCTIONS(JPH_BodyCreationSettings, JPH::BodyCreationSettings);
DEFINE_CONVERSION_FUNCTIONS(JPH_SoftBodyCreationSettings, JPH::SoftBodyCreationSettings);

// Constraints

DEFINE_CONVERSION_FUNCTIONS(JPH_SpringSettings, JPH::SpringSettings);
DEFINE_CONVERSION_FUNCTIONS(JPH_MotorSettings, JPH::MotorSettings);

DEFINE_CONVERSION_FUNCTIONS(JPH_PathConstraintPath, JPH::PathConstraintPath);
DEFINE_CONVERSION_FUNCTIONS(JPH_PathConstraintPathHermite, JPH::PathConstraintPathHermite);

DEFINE_CONVERSION_FUNCTIONS(JPH_Constraint, JPH::Constraint);
DEFINE_CONVERSION_FUNCTIONS(JPH_TwoBodyConstraint, JPH::TwoBodyConstraint);
DEFINE_CONVERSION_FUNCTIONS(JPH_ConeConstraint, JPH::ConeConstraint);
DEFINE_CONVERSION_FUNCTIONS(JPH_DistanceConstraint, JPH::DistanceConstraint);
DEFINE_CONVERSION_FUNCTIONS(JPH_FixedConstraint, JPH::FixedConstraint);
DEFINE_CONVERSION_FUNCTIONS(JPH_GearConstraint, JPH::GearConstraint);
DEFINE_CONVERSION_FUNCTIONS(JPH_HingeConstraint, JPH::HingeConstraint);
DEFINE_CONVERSION_FUNCTIONS(JPH_PathConstraint, JPH::PathConstraint);
DEFINE_CONVERSION_FUNCTIONS(JPH_PointConstraint, JPH::PointConstraint);
DEFINE_CONVERSION_FUNCTIONS(JPH_PulleyConstraint, JPH::PulleyConstraint);
DEFINE_CONVERSION_FUNCTIONS(JPH_RackAndPinionConstraint, JPH::RackAndPinionConstraint);
DEFINE_CONVERSION_FUNCTIONS(JPH_SixDOFConstraint, JPH::SixDOFConstraint);
DEFINE_CONVERSION_FUNCTIONS(JPH_SliderConstraint, JPH::SliderConstraint);
DEFINE_CONVERSION_FUNCTIONS(JPH_SwingTwistConstraint, JPH::SwingTwistConstraint);
