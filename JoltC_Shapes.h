#pragma once

#include <JoltC_Core.h>

struct JPH_DebugRenderer;

typedef struct JPH_Shape {
    char opaque;
} JPH_Shape;

typedef struct JPH_ShapeSettings {
    uint64_t userData;
} JPH_ShapeSettings;

typedef struct JPH_EmptyShapeSettings {
    JPH_ShapeSettings base;
    JPH_Vec3 centerOfMass;
} JPH_EmptyShapeSettings;

JOLTC_API JPH_EmptyShapeSettings JPH_EmptyShapeSettings_Default();
JOLTC_API JPH_Shape *JPH_EmptyShapeSettings_CreateShape(const JPH_EmptyShapeSettings *settings);

#define JPH_PlaneShapeSettings_cDefaultHalfExtent 1000.0f

typedef struct JPH_PlaneShapeSettings {
    JPH_ShapeSettings base;
    JPH_Plane plane;
    const JPH_PhysicsMaterial *material;
    float halfExtent;
} JPH_PlaneShapeSettings;

JOLTC_API JPH_PlaneShapeSettings JPH_PlaneShapeSettings_Default();
JOLTC_API JPH_Shape *JPH_PlaneShapeSettings_CreateShape(const JPH_PlaneShapeSettings *settings);

typedef struct JPH_IndexedTriangle {
    uint32_t idx[3];
    uint32_t materialIndex;
    uint32_t userData;
} JPH_IndexedTriangle;

typedef uint32_t JPH_MeshShapeSettings_EBuildQuality;
enum JPH_MeshShapeSettings_EBuildQuality_ {
    JPH_MeshShapeSettings_EBuildQuality_FavorRuntimePerformance,
    JPH_MeshShapeSettings_EBuildQuality_FavorBuildSpeed,
};

#define JPH_MeshShapeSettings_cDefaultMaxTrianglesPerLeaf 8
#define JPH_MeshShapeSettings_cDefaultActiveEdgeCosThresholdAngle 0.996195f

typedef struct JPH_MeshShapeSettings {
    JPH_ShapeSettings base;
    uint32_t numVertices;
    JPH_Float3 *vertices;
    uint32_t numIndexedTriangles;
    JPH_IndexedTriangle *indexedTriangles;
    uint32_t numMaterials;
    const JPH_PhysicsMaterial **materials;
    uint32_t maxTrianglesPerLeaf;
    float activeEdgeCosThresholdAngle;
    bool perTriangleUserData;
    JPH_MeshShapeSettings_EBuildQuality buildQuality;
} JPH_MeshShapeSettings;

JOLTC_API JPH_MeshShapeSettings JPH_MeshShapeSettings_Default();
JOLTC_API JPH_Shape *JPH_MeshShapeSettings_CreateShape(const JPH_MeshShapeSettings *settings);

#define JPH_HeightFieldShapeSettings_cDefaultMinHeightValue JPH_cLargeFloat
#define JPH_HeightFieldShapeSettings_cDefaultMaxHeightValue (-JPH_cLargeFloat)
#define JPH_HeightFieldShapeSettings_cDefaultBlockSize 2
#define JPH_HeightFieldShapeSettings_cDefaultBitsPerSample 8
#define JPH_HeightFieldShapeSettings_cDefaultActiveEdgeCosThresholdAngle 0.996195f

typedef struct JPH_HeightFieldShapeSettings {
    JPH_ShapeSettings base;
    JPH_Vec3 offset;
    JPH_Vec3 scale;
    float minHeightValue;
    float maxHeightValue;
    uint32_t materialsCapacity;
    uint32_t blockSize;
    uint32_t bitsPerSample;
    uint32_t sampleCount;
    float *heightSamples;
    uint8_t *materialIndices;
    uint32_t numMaterials;
    const JPH_PhysicsMaterial **materials;
    float activeEdgeCosThresholdAngle;
} JPH_HeightFieldShapeSettings;

JOLTC_API JPH_HeightFieldShapeSettings JPH_HeightFieldShapeSettings_Default();
JOLTC_API JPH_Shape *JPH_HeightFieldShapeSettings_CreateShape(const JPH_HeightFieldShapeSettings *settings);

// @Todo: find a way to implement these (DetermineMinAndMaxSample can be written by hand easily, not so much for the other)
// JOLTC_API void JPH_HeightFieldShapeSettings_DetermineMinAndMaxSample(const JPH_HeightFieldShapeSettings *settings, float *outMinValue, float *outMaxValue, float *outQuantizationScale);
// JOLTC_API uint32_t JPH_HeightFieldShapeSettings_CalculateBitsPerSampleForError(const JPH_HeightFieldShapeSettings *settings, float maxError);

#define JPH_ConvexShapeSettings_cDefaultDensity 1000.0f
#define JPH_ConvexShapeSettings_cDefaultConvexRadius 0.05f

typedef struct JPH_ConvexShapeSettings {
    JPH_ShapeSettings base;
    const JPH_PhysicsMaterial *material;
    float density;
} JPH_ConvexShapeSettings;

typedef struct JPH_SphereShapeSettings {
    JPH_ConvexShapeSettings base;
    float radius;
} JPH_SphereShapeSettings;

JOLTC_API JPH_SphereShapeSettings JPH_SphereShapeSettings_Default();
JOLTC_API JPH_Shape *JPH_SphereShapeSettings_CreateShape(const JPH_SphereShapeSettings *settings);

typedef struct JPH_BoxShapeSettings {
    JPH_ConvexShapeSettings base;
    JPH_Vec3 halfExtent;
    float convexRadius;
} JPH_BoxShapeSettings;

JOLTC_API JPH_BoxShapeSettings JPH_BoxShapeSettings_Default();
JOLTC_API JPH_Shape *JPH_BoxShapeSettings_CreateShape(const JPH_BoxShapeSettings *settings);

typedef struct JPH_TriangleShapeSettings {
    JPH_ConvexShapeSettings base;
    JPH_Vec3 v1;
    JPH_Vec3 v2;
    JPH_Vec3 v3;
    float convexRadius;
} JPH_TriangleShapeSettings;

JOLTC_API JPH_TriangleShapeSettings JPH_TriangleShapeSettings_Default();
JOLTC_API JPH_Shape *JPH_TriangleShapeSettings_CreateShape(const JPH_TriangleShapeSettings *settings);

typedef struct JPH_CapsuleShapeSettings {
    JPH_ConvexShapeSettings base;
    float radius;
    float halfHeightOfCylinder;
} JPH_CapsuleShapeSettings;

JOLTC_API JPH_CapsuleShapeSettings JPH_CapsuleShapeSettings_Default();
JOLTC_API JPH_Shape *JPH_CapsuleShapeSettings_CreateShape(const JPH_CapsuleShapeSettings *settings);
JOLTC_API bool JPH_CapsuleShapeSettings_IsValid(const JPH_CapsuleShapeSettings *settings);
JOLTC_API bool JPH_CapsuleShapeSettings_IsSphere(const JPH_CapsuleShapeSettings *settings);

typedef struct JPH_TaperedCapsuleShapeSettings {
    JPH_ConvexShapeSettings base;
    float halfHeightOfTaperedCylinder;
    float topRadius;
    float bottomRadius;
} JPH_TaperedCapsuleShapeSettings;

JOLTC_API JPH_TaperedCapsuleShapeSettings JPH_TaperedCapsuleShapeSettings_Default();
JOLTC_API JPH_Shape *JPH_TaperedCapsuleShapeSettings_CreateShape(const JPH_TaperedCapsuleShapeSettings *settings);
JOLTC_API bool JPH_TaperedCapsuleShapeSettings_IsValid(const JPH_TaperedCapsuleShapeSettings *settings);
JOLTC_API bool JPH_TaperedCapsuleShapeSettings_IsSphere(const JPH_TaperedCapsuleShapeSettings *settings);

typedef struct JPH_CylinderShapeSettings {
    JPH_ConvexShapeSettings base;
    float halfHeight;
    float radius;
    float convexRadius;
} JPH_CylinderShapeSettings;

JOLTC_API JPH_CylinderShapeSettings JPH_CylinderShapeSettings_Default();
JOLTC_API JPH_Shape *JPH_CylinderShapeSettings_CreateShape(const JPH_CylinderShapeSettings *settings);

typedef struct JPH_TaperedCylinderShapeSettings {
    JPH_ConvexShapeSettings base;
    float halfHeight;
    float topRadius;
    float bottomRadius;
    float convexRadius;
} JPH_TaperedCylinderShapeSettings;

JOLTC_API JPH_TaperedCylinderShapeSettings JPH_TaperedCylinderShapeSettings_Default();
JOLTC_API JPH_Shape *JPH_TaperedCylinderShapeSettings_CreateShape(const JPH_TaperedCylinderShapeSettings *settings);

#define JPH_ConvexHullShapeSettings_cDefaultMaxErrorConvexRadius 0.05f
#define JPH_ConvexHullShapeSettings_cDefaultHullTolerance 1.0e-3f

typedef struct JPH_ConvexHullShapeSettings {
    JPH_ConvexShapeSettings base;
    uint32_t numPoints;
    JPH_Vec3 *points;
    float maxConvexRadius;
    float maxErrorConvexRadius;
    float hullTolerance;
} JPH_ConvexHullShapeSettings;

JOLTC_API JPH_ConvexHullShapeSettings JPH_ConvexHullShapeSettings_Default();
JOLTC_API JPH_Shape *JPH_ConvexHullShapeSettings_CreateShape(const JPH_ConvexHullShapeSettings *settings);

typedef struct JPH_CompoundShapeSettings_SubShapeSettings {
    const JPH_Shape *shape;
    JPH_Vec3 position;
    JPH_Quat rotation;
    uint32_t userData;
} JPH_CompoundShapeSettings_SubShapeSettings;

typedef struct JPH_CompoundShapeSettings {
    JPH_ShapeSettings base;
    uint32_t numSubShapes;
    JPH_CompoundShapeSettings_SubShapeSettings *subShapes;
} JPH_CompoundShapeSettings;

typedef struct JPH_StaticCompoundShapeSettings {
    JPH_CompoundShapeSettings base;
} JPH_StaticCompoundShapeSettings;

JOLTC_API JPH_StaticCompoundShapeSettings JPH_StaticCompoundShapeSettings_Default();
JOLTC_API JPH_Shape *JPH_StaticCompoundShapeSettings_CreateShape(const JPH_StaticCompoundShapeSettings *settings);

typedef struct JPH_MutableCompoundShapeSettings {
    JPH_CompoundShapeSettings base;
} JPH_MutableCompoundShapeSettings;

JOLTC_API JPH_MutableCompoundShapeSettings JPH_MutableCompoundShapeSettings_Default();
JOLTC_API JPH_Shape *JPH_MutableCompoundShapeSettings_CreateShape(const JPH_MutableCompoundShapeSettings *settings);

typedef struct JPH_DecoratedShapeSettings {
    JPH_ShapeSettings base;
    const JPH_Shape *innerShape;
} JPH_DecoratedShapeSettings;

typedef struct JPH_RotatedTranslatedShapeSettings {
    JPH_DecoratedShapeSettings base;
    JPH_Vec3 position;
    JPH_Quat rotation;
} JPH_RotatedTranslatedShapeSettings;

JOLTC_API JPH_RotatedTranslatedShapeSettings JPH_RotatedTranslatedShapeSettings_Default();
JOLTC_API JPH_Shape *JPH_RotatedTranslatedShapeSettings_CreateShape(const JPH_RotatedTranslatedShapeSettings *settings);

typedef struct JPH_ScaledShapeSettings {
    JPH_DecoratedShapeSettings base;
    JPH_Vec3 scale;
} JPH_ScaledShapeSettings;

JOLTC_API JPH_ScaledShapeSettings JPH_ScaledShapeSettings_Default();
JOLTC_API JPH_Shape *JPH_ScaledShapeSettings_CreateShape(const JPH_ScaledShapeSettings *settings);

typedef struct JPH_OffsetCenterOfMassShapeSettings {
    JPH_DecoratedShapeSettings base;
    JPH_Vec3 offset;
} JPH_OffsetCenterOfMassShapeSettings;

JOLTC_API JPH_OffsetCenterOfMassShapeSettings JPH_OffsetCenterOfMassShapeSettings_Default();
JOLTC_API JPH_Shape *JPH_OffsetCenterOfMassShapeSettings_CreateShape(const JPH_OffsetCenterOfMassShapeSettings *settings);

// Shape

typedef struct JPH_EmptyShape {
    JPH_Shape base;
} JPH_EmptyShape;

typedef struct JPH_PlaneShape {
    JPH_Shape base;
} JPH_PlaneShape;

typedef struct JPH_MeshShape {
    JPH_Shape base;
} JPH_MeshShape;

typedef struct JPH_HeightFieldShape {
    JPH_Shape base;
} JPH_HeightFieldShape;

typedef struct JPH_ConvexShape {
    JPH_Shape base;
} JPH_ConvexShape;

typedef struct JPH_SphereShape {
    JPH_ConvexShape base;
} JPH_SphereShape;

typedef struct JPH_BoxShape {
    JPH_ConvexShape base;
} JPH_BoxShape;

typedef struct JPH_TriangleShape {
    JPH_ConvexShape base;
} JPH_TriangleShape;

typedef struct JPH_CapsuleShape {
    JPH_ConvexShape base;
} JPH_CapsuleShape;

typedef struct JPH_TaperedCapsuleShape {
    JPH_ConvexShape base;
} JPH_TaperedCapsuleShape;

typedef struct JPH_CylinderShape {
    JPH_ConvexShape base;
} JPH_CylinderShape;

typedef struct JPH_TaperedCylinderShape {
    JPH_ConvexShape base;
} JPH_TaperedCylinderShape;

typedef struct JPH_ConvexHullShape {
    JPH_ConvexShape base;
} JPH_ConvexHullShape;

typedef struct JPH_CompoundShape {
    JPH_Shape base;
} JPH_CompoundShape;

typedef struct JPH_StaticCompoundShape {
    JPH_CompoundShape base;
} JPH_StaticCompoundShape;

typedef struct JPH_MutableCompoundShape {
    JPH_CompoundShape base;
} JPH_MutableCompoundShape;

typedef struct JPH_DecoratedShape {
    JPH_Shape base;
} JPH_DecoratedShape;

typedef struct JPH_RotatedTranslatedShape {
    JPH_DecoratedShape base;
} JPH_RotatedTranslatedShape;

typedef struct JPH_ScaledShape {
    JPH_DecoratedShape base;
} JPH_ScaledShape;

typedef struct JPH_OffsetCenterOfMassShape {
    JPH_DecoratedShape base;
} JPH_OffsetCenterOfMassShape;

// Shape

typedef uint32_t JPH_SubShapeID;

typedef uint8_t JPH_EShapeType;
enum JPH_EShapeType_ {
    JPH_EShapeType_Convex,
    JPH_EShapeType_Compound,
    JPH_EShapeType_Decorated,
    JPH_EShapeType_Mesh,
    JPH_EShapeType_HeightField,
    JPH_EShapeType_SoftBody,
    JPH_EShapeType_User1,
    JPH_EShapeType_User2,
    JPH_EShapeType_User3,
    JPH_EShapeType_User4,
    JPH_EShapeType_Plane,
    JPH_EShapeType_Empty,
};

typedef uint8_t JPH_EShapeSubType;
enum JPH_EShapeSubType_ {
    JPH_EShapeSubType_Sphere,
    JPH_EShapeSubType_Box,
    JPH_EShapeSubType_Triangle,
    JPH_EShapeSubType_Capsule,
    JPH_EShapeSubType_TaperedCapsule,
    JPH_EShapeSubType_Cylinder,
    JPH_EShapeSubType_ConvexHull,
    JPH_EShapeSubType_StaticCompound,
    JPH_EShapeSubType_MutableCompound,
    JPH_EShapeSubType_RotatedTranslated,
    JPH_EShapeSubType_Scaled,
    JPH_EShapeSubType_OffsetCenterOfMass,
    JPH_EShapeSubType_Mesh,
    JPH_EShapeSubType_HeightField,
    JPH_EShapeSubType_SoftBody,
    JPH_EShapeSubType_User1,
    JPH_EShapeSubType_User2,
    JPH_EShapeSubType_User3,
    JPH_EShapeSubType_User4,
    JPH_EShapeSubType_User5,
    JPH_EShapeSubType_User6,
    JPH_EShapeSubType_User7,
    JPH_EShapeSubType_User8,
    JPH_EShapeSubType_UserConvex1,
    JPH_EShapeSubType_UserConvex2,
    JPH_EShapeSubType_UserConvex3,
    JPH_EShapeSubType_UserConvex4,
    JPH_EShapeSubType_UserConvex5,
    JPH_EShapeSubType_UserConvex6,
    JPH_EShapeSubType_UserConvex7,
    JPH_EShapeSubType_UserConvex8,
    JPH_EShapeSubType_Plane,
    JPH_EShapeSubType_TaperedCylinder,
    JPH_EShapeSubType_Empty,
};

typedef struct JPH_MassProperties {
    float mass;
    JPH_Mat44 inertia;
} JPH_MassProperties;

JOLTC_API JPH_Vec3 JPH_MassProperties_GetEquivalentSolidBoxSize(float mass, JPH_Vec3 inertiaDiagonal);
JOLTC_API bool JPH_MassProperties_DecomposePrincipalMomentsOfInertia(JPH_MassProperties *massProperties, JPH_Mat44 *outRotation, JPH_Vec3 *outDiagonal);
JOLTC_API void JPH_MassProperties_SetMassAndInertiaOfSolidBox(JPH_MassProperties *massProperties, JPH_Vec3 boxSize, float density);
JOLTC_API void JPH_MassProperties_ScaleToMass(JPH_MassProperties *massProperties, float mass);
JOLTC_API void JPH_MassProperties_Rotate(JPH_MassProperties *massProperties, JPH_Mat44 rotation);
JOLTC_API void JPH_MassProperties_Translate(JPH_MassProperties *massProperties, JPH_Vec3 translation);
JOLTC_API void JPH_MassProperties_Scale(JPH_MassProperties *massProperties, JPH_Vec3 scale);

JOLTC_API void JPH_Shape_AddRef(JPH_Shape *shape);
JOLTC_API void JPH_Shape_Release(JPH_Shape *shape);
JOLTC_API uint32_t JPH_Shape_GetRefCount(const JPH_Shape *shape);

JOLTC_API JPH_EShapeType JPH_Shape_GetType(const JPH_Shape *shape);
JOLTC_API JPH_EShapeSubType JPH_Shape_GetSubType(const JPH_Shape *shape);

JOLTC_API uint64_t JPH_Shape_GetUserData(const JPH_Shape *shape);
JOLTC_API void JPH_Shape_SetUserData(JPH_Shape *shape, uint64_t userData);

JOLTC_API bool JPH_Shape_MustBeStatic(const JPH_Shape *shape);
JOLTC_API JPH_Vec3 JPH_Shape_GetCenterOfMass(const JPH_Shape *shape);
JOLTC_API JPH_AABox JPH_Shape_GetLocalBounds(const JPH_Shape *shape);
JOLTC_API uint32_t JPH_Shape_GetSubShapeIDBitsRecursive(const JPH_Shape *shape);
JOLTC_API JPH_AABox JPH_Shape_GetWorldSpaceBounds(const JPH_Shape *shape, JPH_Mat44 centerOfMassTransform, JPH_Vec3 scale);
JOLTC_API float JPH_Shape_GetInnerRadius(const JPH_Shape *shape);

JOLTC_API JPH_MassProperties JPH_Shape_GetMassProperties(const JPH_Shape *shape);

JOLTC_API const JPH_Shape *JPH_Shape_GetLeafShape(const JPH_Shape *shape, JPH_SubShapeID subShapeID, JPH_SubShapeID *outRemainder);
JOLTC_API const JPH_PhysicsMaterial *JPH_Shape_GetMaterial(const JPH_Shape *shape, JPH_SubShapeID subShapeID);
JOLTC_API JPH_Vec3 JPH_Shape_GetSurfaceNormal(const JPH_Shape *shape, JPH_SubShapeID subShapeID, JPH_Vec3 localSurfacePosition);

typedef struct JPH_Shape_SupportingFace {
    uint32_t size;
    JPH_Vec3 elements[32];
} JPH_Shape_SupportingFace;

JOLTC_API void JPH_Shape_GetSupportingFace(const JPH_Shape *shape, JPH_SubShapeID subShapeID, JPH_Vec3 direction, JPH_Vec3 scale, JPH_Mat44 centerOfMassTransform, JPH_Shape_SupportingFace *outVertices);

JOLTC_API uint64_t JPH_Shape_GetSubShapeUserData(const JPH_Shape *shape, JPH_SubShapeID subShapeID);

JOLTC_API void JPH_Shape_GetSubmergedVolume(const JPH_Shape *shape, JPH_Mat44 centerOfMassTransform, JPH_Vec3 scale, JPH_Plane surface, float *outTotalVolume, float *outSubmergedVolume, JPH_Vec3 *outCenterOfBuoyancy);

// @Todo: Shape::CastRay
// @Todo: Shape::CollidePoint

typedef struct JPH_Shape_GetTrianglesContext {
    alignas(16) uint8_t data[4288];
} JPH_Shape_GetTrianglesContext;

JOLTC_API void JPH_Shape_GetTrianglesStart(const JPH_Shape *shape, JPH_Shape_GetTrianglesContext *ioContext, JPH_AABox box, JPH_Vec3 positionCOM, JPH_Quat rotation, JPH_Vec3 scale);
JOLTC_API uint32_t JPH_Shape_GetTrianglesNext(const JPH_Shape *shape, JPH_Shape_GetTrianglesContext *ioContext, uint32_t maxTrianglesRequested, JPH_Float3 *outTriangleVertices, const JPH_PhysicsMaterial **outMaterials);

typedef struct JPH_Shape_Stats {
    size_t sizeBytes;
    uint32_t numTriangles;
} JPH_Shape_Stats;

JOLTC_API JPH_Shape_Stats JPH_Shape_GetStats(const JPH_Shape *shape);

JOLTC_API float JPH_Shape_GetVolume(const JPH_Shape *shape);
JOLTC_API bool JPH_Shape_IsValidScale(const JPH_Shape *shape, JPH_Vec3 scale);
JOLTC_API JPH_Vec3 JPH_Shape_MakeScaleValid(const JPH_Shape *shape, JPH_Vec3 scale);
JOLTC_API JPH_Shape *JPH_Shape_ScaleShape(const JPH_Shape *shape, JPH_Vec3 scale);

#ifdef JOLTC_DEBUG_RENDERER
JOLTC_API void JPH_Shape_Draw(const JPH_Shape *shape, struct JPH_DebugRenderer *renderer, JPH_RMat44 centerOfMassTransform, JPH_Vec3 scale, JPH_Color color, bool useMaterialColors, bool drawWireframe);
JOLTC_API void JPH_Shape_DrawGetSupportFunction(const JPH_Shape *shape, struct JPH_DebugRenderer *renderer, JPH_RMat44 centerOfMassTransform, JPH_Vec3 scale, JPH_Color color, bool drawSupportDirection);
JOLTC_API void JPH_Shape_DrawGetSupportingFace(const JPH_Shape *shape, struct JPH_DebugRenderer *renderer, JPH_RMat44 centerOfMassTransform, JPH_Vec3 scale);
#endif

// ConvexShape

JOLTC_API void JPH_ConvexShape_SetMaterial(JPH_ConvexShape *shape, const JPH_PhysicsMaterial *material);
JOLTC_API const JPH_PhysicsMaterial *JPH_ConvexShape_GetMaterial(const JPH_ConvexShape *shape);
JOLTC_API void JPH_ConvexShape_SetDensity(JPH_ConvexShape *shape, float density);
JOLTC_API float JPH_ConvexShape_GetDensity(const JPH_ConvexShape *shape);

// SphereShape

JOLTC_API float JPH_SphereShape_GetRadius(const JPH_SphereShape *shape);

// BoxShape

JOLTC_API JPH_Vec3 JPH_BoxShape_GetHalfExtent(const JPH_BoxShape *shape);
JOLTC_API float JPH_BoxShape_GetConvexRadius(const JPH_BoxShape *shape);

// PlaneShape

JOLTC_API JPH_Plane JPH_PlaneShape_GetPlane(const JPH_PlaneShape *shape);
JOLTC_API float JPH_PlaneShape_GetHalfExtent(const JPH_PlaneShape *shape);
JOLTC_API void JPH_PlaneShape_SetMaterial(JPH_PlaneShape *shape, const JPH_PhysicsMaterial *material);
JOLTC_API const JPH_PhysicsMaterial *JPH_PlaneShape_GetMaterial(const JPH_PlaneShape *shape);

// TriangleShape

JOLTC_API JPH_Vec3 JPH_TriangleShape_GetVertex1(const JPH_TriangleShape *shape);
JOLTC_API JPH_Vec3 JPH_TriangleShape_GetVertex2(const JPH_TriangleShape *shape);
JOLTC_API JPH_Vec3 JPH_TriangleShape_GetVertex3(const JPH_TriangleShape *shape);
JOLTC_API void JPH_TriangleShape_GetVertices(const JPH_TriangleShape *shape, JPH_Vec3 *outV1, JPH_Vec3 *outV2, JPH_Vec3 *outV3);
JOLTC_API float JPH_TriangleShape_GetConvexRadius(const JPH_TriangleShape *shape);

// CapsuleShape

JOLTC_API float JPH_CapsuleShape_GetRadius(const JPH_CapsuleShape *shape);
JOLTC_API float JPH_CapsuleShape_GetHalfHeightOfCylinder(const JPH_CapsuleShape *shape);

// TaperedCapsuleShape

JOLTC_API float JPH_TaperedCapsuleShape_GetTopRadius(const JPH_TaperedCapsuleShape *shape);
JOLTC_API float JPH_TaperedCapsuleShape_GetBottomRadius(const JPH_TaperedCapsuleShape *shape);
JOLTC_API float JPH_TaperedCapsuleShape_GetHalfHeight(const JPH_TaperedCapsuleShape *shape);

// CylinderShape

JOLTC_API float JPH_CylinderShape_GetHalfHeight(const JPH_CylinderShape *shape);
JOLTC_API float JPH_CylinderShape_GetRadius(const JPH_CylinderShape *shape);
JOLTC_API float JPH_CylinderShape_GetConvexRadius(const JPH_CylinderShape *shape);

// TaperedCylinderShape

JOLTC_API float JPH_TaperedCylinderShape_GetTopRadius(const JPH_TaperedCylinderShape *shape);
JOLTC_API float JPH_TaperedCylinderShape_GetBottomRadius(const JPH_TaperedCylinderShape *shape);
JOLTC_API float JPH_TaperedCylinderShape_GetConvexRadius(const JPH_TaperedCylinderShape *shape);
JOLTC_API float JPH_TaperedCylinderShape_GetHalfHeight(const JPH_TaperedCylinderShape *shape);

// ConvexHullShape

JOLTC_API float JPH_ConvexHullShape_GetConvexRadius(const JPH_ConvexHullShape *shape);
JOLTC_API uint32_t JPH_ConvexHullShape_GetNumPoints(const JPH_ConvexHullShape *shape);
JOLTC_API JPH_Vec3 JPH_ConvexHullShape_GetPoint(const JPH_ConvexHullShape *shape, uint32_t index);
JOLTC_API uint32_t JPH_ConvexHullShape_GetNumFaces(const JPH_ConvexHullShape *shape);
JOLTC_API uint32_t JPH_ConvexHullShape_GetNumVerticesInFace(const JPH_ConvexHullShape *shape, uint32_t faceIndex);
JOLTC_API uint32_t JPH_ConvexHullShape_GetFaceVertices(const JPH_ConvexHullShape *shape, uint32_t faceIndex, uint32_t maxVertices, uint32_t *outVertices);
JOLTC_API uint32_t JPH_ConvexHullShape_GetNumPlanes(const JPH_ConvexHullShape *shape);
JOLTC_API const JPH_Plane *JPH_ConvexHullShape_GetPlanes(const JPH_ConvexHullShape *shape);

// DecoratedShape

JOLTC_API const JPH_Shape *JPH_DecoratedShape_GetInnerShape(const JPH_DecoratedShape *shape);

// RotatedTranslatedShape

JOLTC_API JPH_Quat JPH_RotatedTranslatedShape_GetRotation(const JPH_RotatedTranslatedShape *shape);
JOLTC_API JPH_Vec3 JPH_RotatedTranslatedShape_GetPosition(const JPH_RotatedTranslatedShape *shape);
JOLTC_API JPH_Vec3 JPH_RotatedTranslatedShape_TransformScale(const JPH_RotatedTranslatedShape *shape, JPH_Vec3 scale);

// ScaledShape

JOLTC_API JPH_Vec3 JPH_ScaledShape_GetScale(const JPH_ScaledShape *shape);

// OffsetCenterOfMassShape

JOLTC_API JPH_Vec3 JPH_OffsetCenterOfMassShape_GetOffset(const JPH_OffsetCenterOfMassShape *shape);

// CompoundShape

JOLTC_API uint32_t JPH_CompoundShape_GetNumSubShapes(const JPH_CompoundShape *shape);
JOLTC_API uint32_t JPH_CompoundShape_GetCompoundUserData(const JPH_CompoundShape *shape, uint32_t index);
JOLTC_API void JPH_CompoundShape_SetCompoundUserData(JPH_CompoundShape *shape, uint32_t index, uint32_t userData);
JOLTC_API bool JPH_CompoundShape_IsSubShapeIDValid(const JPH_CompoundShape *shape, JPH_SubShapeID subShapeID);
JOLTC_API uint32_t JPH_CompoundShape_GetSubShapeIndexFromID(const JPH_CompoundShape *shape, JPH_SubShapeID subShapeID, JPH_SubShapeID *outRemainder);

// MutableCompoundShape

JOLTC_API uint32_t JPH_MutableCompoundShape_AddShape(JPH_MutableCompoundShape *shape, JPH_Vec3 position, JPH_Quat rotation, const JPH_Shape *inShape, uint32_t userData, uint32_t index);
JOLTC_API void JPH_MutableCompoundShape_RemoveShape(JPH_MutableCompoundShape *shape, uint32_t index);
JOLTC_API void JPH_MutableCompoundShape_ModifyShape(JPH_MutableCompoundShape *shape, uint32_t index, JPH_Vec3 position, JPH_Quat rotation);
JOLTC_API void JPH_MutableCompoundShape_ModifyShapeWithShape(JPH_MutableCompoundShape *shape, uint32_t index, JPH_Vec3 position, JPH_Quat rotation, const JPH_Shape *inShape);
JOLTC_API void JPH_MutableCompoundShape_ModifyShapes(JPH_MutableCompoundShape *shape, uint32_t startIndex, uint32_t number, const JPH_Vec3 *positions, const JPH_Quat *rotations, uint32_t positionStride, uint32_t rotationStride);
JOLTC_API void JPH_MutableCompoundShape_AdjustCenterOfMass(JPH_MutableCompoundShape *shape);

// MeshShape

JOLTC_API uint32_t JPH_MeshShape_GetMaterialIndex(const JPH_MeshShape *shape, JPH_SubShapeID subShapeID);
JOLTC_API uint32_t JPH_MeshShape_GetTriangleUserData(const JPH_MeshShape *shape, JPH_SubShapeID subShapeID);

// HeightFieldShape

JOLTC_API uint32_t JPH_HeightFieldShape_GetSampleCount(const JPH_HeightFieldShape *shape);
JOLTC_API uint32_t JPH_HeightFieldShape_GetBlockSize(const JPH_HeightFieldShape *shape);
JOLTC_API const JPH_PhysicsMaterial *JPH_HeightFieldShape_GetMaterial(const JPH_HeightFieldShape *shape, uint32_t x, uint32_t y);
JOLTC_API JPH_Vec3 JPH_HeightFieldShape_GetPosition(const JPH_HeightFieldShape *shape, uint32_t x, uint32_t y);
JOLTC_API bool JPH_HeightFieldShape_IsNoCollision(const JPH_HeightFieldShape *shape, uint32_t x, uint32_t y);
JOLTC_API bool JPH_HeightFieldShape_ProjectOntoSurface(const JPH_HeightFieldShape *shape, JPH_Vec3 localPosition, JPH_Vec3 *outSurfacePosition, JPH_SubShapeID *outSubShapeID);
JOLTC_API void JPH_HeightFieldShape_GetSubShapeCoordinates(const JPH_HeightFieldShape *shape, JPH_SubShapeID subShapeID, uint32_t *outX, uint32_t *outY, uint32_t *outTriangleIndex);
JOLTC_API float JPH_HeightFieldShape_GetMinHeightValue(const JPH_HeightFieldShape *shape);
JOLTC_API float JPH_HeightFieldShape_GetMaxHeightValue(const JPH_HeightFieldShape *shape);
JOLTC_API void JPH_HeightFieldShape_GetHeights(const JPH_HeightFieldShape *shape, uint32_t x, uint32_t y, uint32_t sizeX, uint32_t sizeY, float *outHeights, intptr_t heightsStride);
JOLTC_API void JPH_HeightFieldShape_SetHeights(JPH_HeightFieldShape *shape, uint32_t x, uint32_t y, uint32_t sizeX, uint32_t sizeY, const float *inHeights, intptr_t heightsStride, JPH_TempAllocator *allocator, float activeEdgeCosThresholdAngle);

// TransformedShape

typedef struct JPH_SubShapeIDCreator {
    JPH_SubShapeID id;
    uint32_t currentBit;
} JPH_SubShapeIDCreator;

typedef struct JPH_TransformedShape {
    JPH_RVec3 shapePositionCOM;
    JPH_Quat shapeRotation;
    const JPH_Shape *shape;
    JPH_Float3 shapeScale;
    JPH_BodyID bodyID;
    JPH_SubShapeIDCreator subShapeIDCreator;
} JPH_TransformedShape;
