#pragma once

#include <JoltC_Core.h>
#include <JoltC_Shapes.h>

// Forward declarations
struct JPH_Body;

typedef struct JPH_BroadPhaseLayerInterface {
    char opaque;
} JPH_BroadPhaseLayerInterface;

typedef struct JPH_BroadPhaseLayerInterfaceTable {
    JPH_BroadPhaseLayerInterface base;
} JPH_BroadPhaseLayerInterfaceTable;

typedef struct JPH_BroadPhaseLayerInterfaceMask {
    JPH_BroadPhaseLayerInterface base;
} JPH_BroadPhaseLayerInterfaceMask;

typedef struct JPH_ObjectLayerPairFilter {
    char opaque;
} JPH_ObjectLayerPairFilter;

typedef struct JPH_ObjectLayerPairFilterTable {
    JPH_ObjectLayerPairFilter base;
} JPH_ObjectLayerPairFilterTable;

typedef struct JPH_ObjectLayerPairFilterMask {
    JPH_ObjectLayerPairFilter base;
} JPH_ObjectLayerPairFilterMask;

typedef struct JPH_ObjectVsBroadPhaseLayerFilter {
    char opaque;
} JPH_ObjectVsBroadPhaseLayerFilter;

typedef struct JPH_ObjectVsBroadPhaseLayerFilterTable {
    JPH_ObjectVsBroadPhaseLayerFilter base;
} JPH_ObjectVsBroadPhaseLayerFilterTable;

typedef struct JPH_ObjectVsBroadPhaseLayerFilterMask {
    JPH_ObjectVsBroadPhaseLayerFilter base;
} JPH_ObjectVsBroadPhaseLayerFilterMask;

typedef struct JPH_BroadPhaseLayerFilter {
    char opaque;
} JPH_BroadPhaseLayerFilter;

typedef struct JPH_ObjectLayerFilter {
    char opaque;
} JPH_ObjectLayerFilter;

typedef struct JPH_GroupFilter {
    char opaque;
} JPH_GroupFilter;

typedef struct JPH_BodyFilter {
    char opaque;
} JPH_BodyFilter;

typedef struct JPH_IgnoreMultipleBodiesFilter {
    JPH_BodyFilter base;
} JPH_IgnoreMultipleBodiesFilter;

typedef struct JPH_IgnoreSingleBodyFilter {
    JPH_BodyFilter base;
} JPH_IgnoreSingleBodyFilter;

typedef struct JPH_IgnoreSingleBodyFilterChained {
    JPH_BodyFilter base;
} JPH_IgnoreSingleBodyFilterChained;

typedef struct JPH_ShapeFilter {
    char opaque;
} JPH_ShapeFilter;

typedef struct JPH_ReversedShapeFilter {
    JPH_ShapeFilter base;
} JPH_ReversedShapeFilter;

typedef struct JPH_SimShapeFilter {
    char opaque;
} JPH_SimShapeFilter;

typedef struct JPH_BroadPhaseQuery  JPH_BroadPhaseQuery;
typedef struct JPH_NarrowPhaseQuery JPH_NarrowPhaseQuery;

typedef uint8_t JPH_BroadPhaseLayer;

#if !defined(JOLTC_OBJECT_LAYER_BITS) || JOLTC_OBJECT_LAYER_BITS == 16
    typedef uint16_t JPH_ObjectLayer;
#elif JOLTC_OBJECT_LAYER_BITS == 32
    typedef uint32_t JPH_ObjectLayer;
#else
    #error "JOLTC_OBJECT_LAYER_BITS must be 16 or 32"
#endif

typedef uint32_t JPH_CollisionGroup_GroupID;
typedef uint32_t JPH_CollisionGroup_SubGroupID;

typedef struct JPH_CollisionGroup {
    const JPH_GroupFilter *groupFilter;
    JPH_CollisionGroup_GroupID groupID;
    JPH_CollisionGroup_SubGroupID subGroupID;
} JPH_CollisionGroup;

// Interfaces

typedef struct JPH_BroadPhaseLayerInterface_Funcs {
    void (JOLTC_CALL *Destruct)(void *data);
    uint32_t (JOLTC_CALL *GetNumBroadPhaseLayers)(const void *data);
    JPH_BroadPhaseLayer (JOLTC_CALL *GetBroadPhaseLayer)(const void *data, JPH_ObjectLayer layer);

#if defined(JOLTC_EXTERNAL_PROFILE) || defined(JOLTC_PROFILE_ENABLED)
    const char *(JOLTC_CALL *GetBroadPhaseLayerName)(const void *data, JPH_BroadPhaseLayer layer);
#endif
} JPH_BroadPhaseLayerInterface_Funcs;

JOLTC_API JPH_BroadPhaseLayerInterface *JPH_BroadPhaseLayerInterface_Create(void *data, JPH_BroadPhaseLayerInterface_Funcs funcs, JPH_JoltCAllocator allocator);
JOLTC_API void JPH_BroadPhaseLayerInterface_Destroy(JPH_BroadPhaseLayerInterface *self);
JOLTC_API uint32_t JPH_BroadPhaseLayerInterface_GetNumBroadPhaseLayers(const JPH_BroadPhaseLayerInterface *bplInterface);
JOLTC_API JPH_BroadPhaseLayer JPH_BroadPhaseLayerInterface_GetBroadPhaseLayer(const JPH_BroadPhaseLayerInterface *bplInterface, JPH_ObjectLayer objectLayer);
#if defined(JOLTC_EXTERNAL_PROFILE) || defined(JOLTC_PROFILE_ENABLED)
JOLTC_API const char *JPH_BroadPhaseLayerInterface_GetBroadPhaseLayerName(const JPH_BroadPhaseLayerInterface *bplInterface, JPH_BroadPhaseLayer broadPhaseLayer);
#endif

JOLTC_API JPH_BroadPhaseLayerInterfaceTable *JPH_BroadPhaseLayerInterfaceTable_Create(uint32_t numObjectLayers, uint32_t numBroadPhaseLayers);
JOLTC_API void JPH_BroadPhaseLayerInterfaceTable_MapObjectToBroadPhaseLayer(JPH_BroadPhaseLayerInterfaceTable *table, JPH_ObjectLayer objectLayer, JPH_BroadPhaseLayer broadPhaseLayer);
#if defined(JOLTC_EXTERNAL_PROFILE) || defined(JOLTC_PROFILE_ENABLED)
JOLTC_API void JPH_BroadPhaseLayerInterfaceTable_SetBroadPhaseLayerName(JPH_BroadPhaseLayerInterfaceTable *table, JPH_BroadPhaseLayer broadPhaseLayer, const char *name);
#endif

JOLTC_API JPH_BroadPhaseLayerInterfaceMask *JPH_BroadPhaseLayerInterfaceMask_Create(uint32_t numBroadPhaseLayers);
JOLTC_API void JPH_BroadPhaseLayerInterfaceMask_ConfigureLayer(JPH_BroadPhaseLayerInterfaceMask *mask, JPH_BroadPhaseLayer broadPhaseLayer, uint32_t groupsToInclude, uint32_t groupsToExclude);
#if defined(JOLTC_EXTERNAL_PROFILE) || defined(JOLTC_PROFILE_ENABLED)
JOLTC_API void JPH_BroadPhaseLayerInterfaceMask_SetBroadPhaseLayerName(JPH_BroadPhaseLayerInterfaceMask *mask, JPH_BroadPhaseLayer broadPhaseLayer, const char *name);
#endif

typedef struct JPH_ObjectLayerPairFilter_Funcs {
    void (JOLTC_CALL *Destruct)(void *data);
    bool (JOLTC_CALL *ShouldCollide)(const void *data, JPH_ObjectLayer layer1, JPH_ObjectLayer layer2);
} JPH_ObjectLayerPairFilter_Funcs;

JOLTC_API JPH_ObjectLayerPairFilter *JPH_ObjectLayerPairFilter_Create(void *data, JPH_ObjectLayerPairFilter_Funcs funcs, JPH_JoltCAllocator allocator);
JOLTC_API void JPH_ObjectLayerPairFilter_Destroy(JPH_ObjectLayerPairFilter *self);
JOLTC_API bool JPH_ObjectLayerPairFilter_ShouldCollide(const JPH_ObjectLayerPairFilter *filter, JPH_ObjectLayer layer1, JPH_ObjectLayer layer2);

JOLTC_API JPH_ObjectLayerPairFilterTable *JPH_ObjectLayerPairFilterTable_Create(uint32_t numObjectLayers);
JOLTC_API uint32_t JPH_ObjectLayerPairFilterTable_GetNumObjectLayers(const JPH_ObjectLayerPairFilterTable *table);
JOLTC_API void JPH_ObjectLayerPairFilterTable_EnableCollision(JPH_ObjectLayerPairFilterTable *table, JPH_ObjectLayer layer1, JPH_ObjectLayer layer2);
JOLTC_API void JPH_ObjectLayerPairFilterTable_DisableCollision(JPH_ObjectLayerPairFilterTable *table, JPH_ObjectLayer layer1, JPH_ObjectLayer layer2);

#define JPH_ObjectLayerPairFilterMask_cNumBits (JOLTC_OBJECT_LAYER_BITS / 2)
#define JPH_ObjectLayerPairFilterMask_cMask ((1 << JPH_ObjectLayerPairFilterMask_cNumBits) - 1)

JOLTC_API JPH_ObjectLayerPairFilterMask *JPH_ObjectLayerPairFilterMask_Create();
JOLTC_API uint32_t JPH_ObjectLayerPairFilterMask_GetGroup(JPH_ObjectLayer objectLayer);
JOLTC_API uint32_t JPH_ObjectLayerPairFilterMask_GetMask(JPH_ObjectLayer objectLayer);
JOLTC_API JPH_ObjectLayer JPH_ObjectLayerPairFilterMask_GetObjectLayer(uint32_t group, uint32_t mask);

typedef struct JPH_ObjectVsBroadPhaseLayerFilter_Funcs {
    void (JOLTC_CALL *Destruct)(void *data);
    bool (JOLTC_CALL *ShouldCollide)(const void *data, JPH_ObjectLayer layer1, JPH_BroadPhaseLayer layer2);
} JPH_ObjectVsBroadPhaseLayerFilter_Funcs;

JOLTC_API JPH_ObjectVsBroadPhaseLayerFilter *JPH_ObjectVsBroadPhaseLayerFilter_Create(void *data, JPH_ObjectVsBroadPhaseLayerFilter_Funcs funcs, JPH_JoltCAllocator allocator);
JOLTC_API void JPH_ObjectVsBroadPhaseLayerFilter_Destroy(JPH_ObjectVsBroadPhaseLayerFilter *self);
JOLTC_API bool JPH_ObjectVsBroadPhaseLayerFilter_ShouldCollide(const JPH_ObjectVsBroadPhaseLayerFilter *filter, JPH_ObjectLayer objectLayer, JPH_BroadPhaseLayer broadPhaseLayer);

JOLTC_API JPH_ObjectVsBroadPhaseLayerFilterTable *JPH_ObjectVsBroadPhaseLayerFilterTable_Create(const JPH_BroadPhaseLayerInterface *bplInterface, uint32_t numBroadPhaseLayers, const JPH_ObjectLayerPairFilter *objectLayerPairFilter, uint32_t numObjectLayers);
JOLTC_API JPH_ObjectVsBroadPhaseLayerFilterMask *JPH_ObjectVsBroadPhaseLayerFilterMask_Create(const JPH_BroadPhaseLayerInterfaceMask *bplInterface);

typedef struct JPH_BroadPhaseLayerFilter_Funcs {
    void (JOLTC_CALL *Destruct)(void *data);
    bool (JOLTC_CALL *ShouldCollide)(const void *data, JPH_BroadPhaseLayer layer);
} JPH_BroadPhaseLayerFilter_Funcs;

JOLTC_API JPH_BroadPhaseLayerFilter *JPH_BroadPhaseLayerFilter_Create(void *data, JPH_BroadPhaseLayerFilter_Funcs funcs, JPH_JoltCAllocator allocator);
JOLTC_API void JPH_BroadPhaseLayerFilter_Destroy(JPH_BroadPhaseLayerFilter *self);

typedef struct JPH_ObjectLayerFilter_Funcs {
    void (JOLTC_CALL *Destruct)(void *data);
    bool (JOLTC_CALL *ShouldCollide)(const void *data, JPH_ObjectLayer layer);
} JPH_ObjectLayerFilter_Funcs;

JOLTC_API JPH_ObjectLayerFilter *JPH_ObjectLayerFilter_Create(void *data, JPH_ObjectLayerFilter_Funcs funcs, JPH_JoltCAllocator allocator);
JOLTC_API void JPH_ObjectLayerFilter_Destroy(JPH_ObjectLayerFilter *self);

typedef struct JPH_BodyFilter_Funcs {
    void (JOLTC_CALL *Destruct)(void *data);
    bool (JOLTC_CALL *ShouldCollide)(const void *data, JPH_BodyID bodyID);
    bool (JOLTC_CALL *ShouldCollideLocked)(const void *data, const struct JPH_Body *body);
} JPH_BodyFilter_Funcs;

JOLTC_API JPH_BodyFilter *JPH_BodyFilter_Create(void *data, JPH_BodyFilter_Funcs funcs, JPH_JoltCAllocator allocator);
JOLTC_API void JPH_BodyFilter_Destroy(JPH_BodyFilter *self);

JOLTC_API JPH_IgnoreMultipleBodiesFilter *JPH_IgnoreMultipleBodiesFilter_Create(const JPH_BodyID *bodyIDs, int numBodies, JPH_JoltCAllocator allocator);
JOLTC_API JPH_IgnoreSingleBodyFilter *JPH_IgnoreSingleBodyFilter_Create(JPH_BodyID bodyID, JPH_JoltCAllocator allocator);
JOLTC_API JPH_IgnoreSingleBodyFilterChained *JPH_IgnoreSingleBodyFilterChained_Create(JPH_BodyID bodyID, const JPH_BodyFilter *otherFilter, JPH_JoltCAllocator allocator);

typedef struct JPH_ShapeFilter_Funcs {
    void (JOLTC_CALL *Destruct)(void *data);
    bool (JOLTC_CALL *ShouldCollide)(const void *data, const JPH_Shape *shape2, JPH_SubShapeID subShapeIDOfShape2);
    bool (JOLTC_CALL *ShapesShouldCollide)(const void *data, const JPH_Shape *shape1, JPH_SubShapeID subShapeIDOfShape1, const JPH_Shape *shape2, JPH_SubShapeID subShapeIDOfShape2);
} JPH_ShapeFilter_Funcs;

JOLTC_API JPH_ShapeFilter *JPH_ShapeFilter_Create(void *data, JPH_ShapeFilter_Funcs funcs, JPH_JoltCAllocator allocator);
JOLTC_API void JPH_ShapeFilter_Destroy(JPH_ShapeFilter *self);
JOLTC_API JPH_ReversedShapeFilter *JPH_ReversedShapeFilter_Create(const JPH_ShapeFilter *other, JPH_JoltCAllocator allocator);

typedef struct JPH_SimShapeFilter_Funcs {
    void (JOLTC_CALL *Destruct)(void *data);
    bool (JOLTC_CALL *ShouldCollide)(const void *data, const struct JPH_Body *body1, const JPH_Shape *shape1, JPH_SubShapeID subShapeIDOfShape1, const struct JPH_Body *body2, const JPH_Shape *shape2, JPH_SubShapeID subShapeIDOfShape2);
} JPH_SimShapeFilter_Funcs;

JOLTC_API JPH_SimShapeFilter *JPH_SimShapeFilter_Create(void *data, JPH_SimShapeFilter_Funcs funcs, JPH_JoltCAllocator allocator);
JOLTC_API void JPH_SimShapeFilter_Destroy(JPH_SimShapeFilter *self);

// Default filters

typedef struct JPH_DefaultBroadPhaseLayerFilter {
    const JPH_ObjectVsBroadPhaseLayerFilter *objectVsBroadPhaseLayerFilter;
    JPH_ObjectLayer layer;
} JPH_DefaultBroadPhaseLayerFilter;

JOLTC_API bool JPH_DefaultBroadPhaseLayerFilter_ShouldCollide(const void *data, JPH_BroadPhaseLayer layer);
JOLTC_API const JPH_BroadPhaseLayerFilter *JPH_DefaultBroadPhaseLayerFilter_CreateFilter(JPH_DefaultBroadPhaseLayerFilter *filter, JPH_JoltCAllocator allocator);

typedef struct JPH_DefaultObjectLayerFilter {
    const JPH_ObjectLayerPairFilter *objectLayerPairFilter;
    JPH_ObjectLayer layer;
} JPH_DefaultObjectLayerFilter;

JOLTC_API bool JPH_DefaultObjectLayerFilter_ShouldCollide(const void *data, JPH_ObjectLayer layer);
JOLTC_API const JPH_ObjectLayerFilter *JPH_DefaultObjectLayerFilter_CreateFilter(JPH_DefaultObjectLayerFilter *filter, JPH_JoltCAllocator allocator);

typedef struct JPH_RayCast {
    JPH_Vec3 origin;
    JPH_Vec3 direction;
} JPH_RayCast;

JOLTC_API JPH_RayCast JPH_RayCast_Transformed(const JPH_RayCast *ray, JPH_Mat44 transform);
JOLTC_API JPH_RayCast JPH_RayCast_Translated(const JPH_RayCast *ray, JPH_Vec3 translation);
JOLTC_API JPH_Vec3 JPH_RayCast_GetPointOnRay(const JPH_RayCast *ray, float fraction);

typedef struct JPH_RRayCast {
    JPH_RVec3 origin;
    JPH_Vec3 direction;
} JPH_RRayCast;

JOLTC_API JPH_RRayCast JPH_RRayCast_Transformed(const JPH_RRayCast *ray, JPH_RMat44 transform);
JOLTC_API JPH_RRayCast JPH_RRayCast_Translated(const JPH_RRayCast *ray, JPH_RVec3 translation);
JOLTC_API JPH_RVec3 JPH_RRayCast_GetPointOnRay(const JPH_RRayCast *ray, float fraction);

typedef uint8_t JPH_EBackFaceMode;
enum JPH_EBackFaceMode_ {
    JPH_EBackFaceMode_IgnoreBackFaces,
    JPH_EBackFaceMode_CollideWithBackFaces,
};

typedef struct JPH_RayCastSettings {
    JPH_EBackFaceMode backFaceModeTriangles;
    JPH_EBackFaceMode backFaceModeConvex;
    bool treatConvexAsSolid;
} JPH_RayCastSettings;

JOLTC_API JPH_RayCastSettings JPH_RayCastSettings_Default();

typedef struct JPH_AABoxCast {
    JPH_AABox box;
    JPH_Vec3 direction;
} JPH_AABoxCast;

typedef uint32_t JPH_ECollisionCollectorType;
enum JPH_ECollisionCollectorType_ {
    JPH_ECollisionCollectorType_AnyHit,
    JPH_ECollisionCollectorType_ClosestHit,
    JPH_ECollisionCollectorType_AllHitsSorted,
    JPH_ECollisionCollectorType_AllHits,
};

typedef struct JPH_BroadPhaseCastResult {
    JPH_BodyID bodyID;
    float fraction;
} JPH_BroadPhaseCastResult;

typedef struct JPH_RayCastResult {
    JPH_BodyID bodyID;
    float fraction;
    JPH_SubShapeID subShapeID2;
} JPH_RayCastResult;

JOLTC_API JPH_RayCastResult JPH_RayCastResult_Default();

typedef struct JPH_CollidePointResult {
    JPH_BodyID bodyID;
    JPH_SubShapeID subShapeID;
} JPH_CollidePointResult;

typedef struct JPH_CollideShapeResult_Face {
    size_t size;
    JPH_Vec3 elements[32];
} JPH_CollideShapeResult_Face;

typedef struct JPH_CollideShapeResult {
    JPH_Vec3 contactPointOn1;
    JPH_Vec3 contactPointOn2;
    JPH_Vec3 penetrationAxis;
    float penetrationDepth;
    JPH_SubShapeID subShapeID1;
    JPH_SubShapeID subShapeID2;
    JPH_BodyID bodyID2;
    JPH_CollideShapeResult_Face shape1Face;
    JPH_CollideShapeResult_Face shape2Face;
} JPH_CollideShapeResult;

typedef struct JPH_ShapeCastResult {
    // JPH_CollideShapeResult base
    JPH_Vec3 contactPointOn1;
    JPH_Vec3 contactPointOn2;
    JPH_Vec3 penetrationAxis;
    float penetrationDepth;
    JPH_SubShapeID subShapeID1;
    JPH_SubShapeID subShapeID2;
    JPH_BodyID bodyID2;
    JPH_CollideShapeResult_Face shape1Face;
    JPH_CollideShapeResult_Face shape2Face;

    float fraction;
    bool isBackFaceHit;
} JPH_ShapeCastResult;

typedef uint8_t JPH_EActiveEdgeMode;
enum JPH_EActiveEdgeMode_ {
    JPH_EActiveEdgeMode_CollideOnlyWithActive,
    JPH_EActiveEdgeMode_CollideWithAll,
};

typedef uint8_t JPH_ECollectFacesMode;
enum JPH_ECollectFacesMode_ {
    JPH_ECollectFacesMode_CollectFaces,
    JPH_ECollectFacesMode_NoFaces,
};

typedef struct JPH_CollideSettingsBase {
    JPH_EActiveEdgeMode activeEdgeMode;
    JPH_ECollectFacesMode collectFacesMode;
    float collisionTolerance;
    float penetrationTolerance;
    JPH_Vec3 activeEdgeMovementDirection;
} JPH_CollideSettingsBase;

typedef struct JPH_ShapeCastSettings {
    // JPH_CollideSettingsBase base
    JPH_EActiveEdgeMode activeEdgeMode;
    JPH_ECollectFacesMode collectFacesMode;
    float collisionTolerance;
    float penetrationTolerance;
    JPH_Vec3 activeEdgeMovementDirection;

    float extraConvexRadius;
    JPH_EBackFaceMode backFaceModeTriangles;
    JPH_EBackFaceMode backFaceModeConvex;
    bool useShrunkenShapeAndConvexRadius;
    bool returnDeepestPoint;
} JPH_ShapeCastSettings;

typedef struct JPH_CollideShapeSettings {
    // JPH_CollideSettingsBase base
    JPH_EActiveEdgeMode activeEdgeMode;
    JPH_ECollectFacesMode collectFacesMode;
    float collisionTolerance;
    float penetrationTolerance;
    JPH_Vec3 activeEdgeMovementDirection;

    float maxSeparationDistance;
    JPH_EBackFaceMode backFaceMode;
    float internalEdgeRemovalVertexToleranceSq;
} JPH_CollideShapeSettings;

typedef struct JPH_RShapeCast {
    const JPH_Shape *shape;
    const JPH_Vec3 scale;
    const JPH_RMat44  centerOfMassStart;
    const JPH_Vec3 direction;
    const JPH_AABox shapeWorldBounds;
} JPH_RShapeCast;

// BroadPhase collectors

#define JOLTC_COLLISION_COLLECTOR_FUNCS(ResultType) \
    typedef struct JPH_CollisionCollector_##ResultType##_Funcs { \
        void (JOLTC_CALL *Destruct)(void *data); \
        void (JOLTC_CALL *Reset)(void *data); \
        void (JOLTC_CALL *OnBody)(void *data, const struct JPH_Body *body); \
        void (JOLTC_CALL *OnBodyEnd)(void *data); \
        void (JOLTC_CALL *SetUserData)(void *data, uint64_t userData); \
        void (JOLTC_CALL *AddHit)(void *data, JPH_##ResultType result); \
    } JPH_CollisionCollector_##ResultType##_Funcs;

JOLTC_COLLISION_COLLECTOR_FUNCS(BodyID);
JOLTC_COLLISION_COLLECTOR_FUNCS(BroadPhaseCastResult);
JOLTC_COLLISION_COLLECTOR_FUNCS(RayCastResult);
JOLTC_COLLISION_COLLECTOR_FUNCS(ShapeCastResult);
JOLTC_COLLISION_COLLECTOR_FUNCS(CollidePointResult);
JOLTC_COLLISION_COLLECTOR_FUNCS(CollideShapeResult);
JOLTC_COLLISION_COLLECTOR_FUNCS(TransformedShape);

typedef struct JPH_RayCastBodyCollector JPH_RayCastBodyCollector;
typedef struct JPH_CastShapeBodyCollector JPH_CastShapeBodyCollector;
typedef struct JPH_CollideShapeBodyCollector JPH_CollideShapeBodyCollector;

JOLTC_API JPH_RayCastBodyCollector *JPH_RayCastBodyCollector_Create(void *data, JPH_CollisionCollector_BroadPhaseCastResult_Funcs funcs, JPH_JoltCAllocator allocator);
JOLTC_API void JPH_RayCastBodyCollector_Destroy(JPH_RayCastBodyCollector *self);

JOLTC_API JPH_CastShapeBodyCollector *JPH_CastShapeBodyCollector_Create(void *data, JPH_CollisionCollector_BroadPhaseCastResult_Funcs funcs, JPH_JoltCAllocator allocator);
JOLTC_API void JPH_CastShapeBodyCollector_Destroy(JPH_CastShapeBodyCollector *self);

JOLTC_API JPH_CollideShapeBodyCollector *JPH_CollideShapeBodyCollector_Create(void *data, JPH_CollisionCollector_BodyID_Funcs funcs, JPH_JoltCAllocator allocator);
JOLTC_API void JPH_CollideShapeBodyCollector_Destroy(JPH_CollideShapeBodyCollector *self);

// BroadPhaseQuery

typedef void (*JPH_BroadPhaseQuery_CastRayHitCallback)(void *data, const JPH_BroadPhaseCastResult *hit);
typedef float (*JPH_BroadPhaseQuery_CastRayCollectCallback)(void *data, const JPH_BroadPhaseCastResult *hit);

JOLTC_API JPH_AABox JPH_BroadPhaseQuery_GetBounds(const JPH_BroadPhaseQuery *query);
JOLTC_API bool JPH_BroadPhaseQuery_CastRaySimple(const JPH_BroadPhaseQuery *query, JPH_RayCast ray, JPH_ECollisionCollectorType collectorType, void *callbackData, JPH_BroadPhaseQuery_CastRayHitCallback callback, const JPH_BroadPhaseLayerFilter *broadPhaseLayerFilter, const JPH_ObjectLayerFilter *objectLayerFilter);
JOLTC_API void JPH_BroadPhaseQuery_CastRay(const JPH_BroadPhaseQuery *query, JPH_RayCast ray, JPH_RayCastBodyCollector *collector, const JPH_BroadPhaseLayerFilter *broadPhaseLayerFilter, const JPH_ObjectLayerFilter *objectLayerFilter);
JOLTC_API void JPH_BroadPhaseQuery_CollideAABox(const JPH_BroadPhaseQuery *query, JPH_AABox box, JPH_CollideShapeBodyCollector *collector, const JPH_BroadPhaseLayerFilter *broadPhaseLayerFilter, const JPH_ObjectLayerFilter *objectLayerFilter);
JOLTC_API void JPH_BroadPhaseQuery_CollideSphere(const JPH_BroadPhaseQuery *query, JPH_Vec3 center, float radius, JPH_CollideShapeBodyCollector *collector, const JPH_BroadPhaseLayerFilter *broadPhaseLayerFilter, const JPH_ObjectLayerFilter *objectLayerFilter);
JOLTC_API void JPH_BroadPhaseQuery_CollidePoint(const JPH_BroadPhaseQuery *query, JPH_Vec3 point, JPH_CollideShapeBodyCollector *collector, const JPH_BroadPhaseLayerFilter *broadPhaseLayerFilter, const JPH_ObjectLayerFilter *objectLayerFilter);
JOLTC_API void JPH_BroadPhaseQuery_CollideOrientedBox(const JPH_BroadPhaseQuery *query, JPH_OrientedBox box, JPH_CollideShapeBodyCollector *collector, const JPH_BroadPhaseLayerFilter *broadPhaseLayerFilter, const JPH_ObjectLayerFilter *objectLayerFilter);
JOLTC_API void JPH_BroadPhaseQuery_CastAABox(const JPH_BroadPhaseQuery *query, JPH_AABoxCast box, JPH_CastShapeBodyCollector *collector, const JPH_BroadPhaseLayerFilter *broadPhaseLayerFilter, const JPH_ObjectLayerFilter *objectLayerFilter);

// NarrowPhase collectors

typedef struct JPH_CastRayCollector JPH_CastRayCollector;
typedef struct JPH_CastShapeCollector JPH_CastShapeCollector;
typedef struct JPH_CollidePointCollector JPH_CollidePointCollector;
typedef struct JPH_CollideShapeCollector JPH_CollideShapeCollector;
typedef struct JPH_TransformedShapeCollector JPH_TransformedShapeCollector;

JOLTC_API JPH_CastRayCollector *JPH_CastRayCollector_Create(void *data, JPH_CollisionCollector_RayCastResult_Funcs funcs, JPH_JoltCAllocator allocator);
JOLTC_API void JPH_CastRayCollector_Destroy(JPH_CastRayCollector *self);

JOLTC_API JPH_CastShapeCollector *JPH_CastShapeCollector_Create(void *data, JPH_CollisionCollector_ShapeCastResult_Funcs funcs, JPH_JoltCAllocator allocator);
JOLTC_API void JPH_CastShapeCollector_Destroy(JPH_CastShapeCollector *self);

JOLTC_API JPH_CollidePointCollector *JPH_CollidePointCollector_Create(void *data, JPH_CollisionCollector_CollidePointResult_Funcs funcs, JPH_JoltCAllocator allocator);
JOLTC_API void JPH_CollidePointCollector_Destroy(JPH_CollidePointCollector *self);

JOLTC_API JPH_CollideShapeCollector *JPH_CollideShapeCollector_Create(void *data, JPH_CollisionCollector_CollideShapeResult_Funcs funcs, JPH_JoltCAllocator allocator);
JOLTC_API void JPH_CollideShapeCollector_Destroy(JPH_CollideShapeCollector *self);

JOLTC_API JPH_TransformedShapeCollector *JPH_TransformedShapeCollector_Create(void *data, JPH_CollisionCollector_TransformedShape_Funcs funcs, JPH_JoltCAllocator allocator);
JOLTC_API void JPH_TransformedShapeCollector_Destroy(JPH_TransformedShapeCollector *self);

// NarrowPhaseQuery

JOLTC_API bool JPH_NarrowPhaseQuery_CastRayClosest(const JPH_NarrowPhaseQuery *query, JPH_RRayCast ray, JPH_RayCastResult *ioHit, const JPH_BroadPhaseLayerFilter *broadPhaseLayerFilter, const JPH_ObjectLayerFilter *objectLayerFilter, const JPH_BodyFilter *bodyFilter);
JOLTC_API void JPH_NarrowPhaseQuery_CastRay(const JPH_NarrowPhaseQuery *query, JPH_RRayCast ray, JPH_RayCastSettings settings, JPH_CastRayCollector *collector, const JPH_BroadPhaseLayerFilter *broadPhaseLayerFilter, const JPH_ObjectLayerFilter *objectLayerFilter, const JPH_BodyFilter *bodyFilter, const JPH_ShapeFilter *shapeFilter);
JOLTC_API void JPH_NarrowPhaseQuery_CollidePoint(const JPH_NarrowPhaseQuery *query, JPH_RVec3 point, JPH_CollidePointCollector *collector, const JPH_BroadPhaseLayerFilter *broadPhaseLayerFilter, const JPH_ObjectLayerFilter *objectLayerFilter, const JPH_BodyFilter *bodyFilter, const JPH_ShapeFilter *shapeFilter);
JOLTC_API void JPH_NarrowPhaseQuery_CollideShape(const JPH_NarrowPhaseQuery *query, const JPH_Shape *shape, JPH_Vec3 shapeScale, JPH_RMat44 centerOfMassTransform, JPH_CollideShapeSettings settings, JPH_RVec3 baseOffset, JPH_CollideShapeCollector *collector, const JPH_BroadPhaseLayerFilter *broadPhaseLayerFilter, const JPH_ObjectLayerFilter *objectLayerFilter, const JPH_BodyFilter *bodyFilter, const JPH_ShapeFilter *shapeFilter);
JOLTC_API void JPH_NarrowPhaseQuery_CollideShapeWithInternalEdgeRemoval(const JPH_NarrowPhaseQuery *query, const JPH_Shape *shape, JPH_Vec3 shapeScale, JPH_RMat44 centerOfMassTransform, JPH_CollideShapeSettings settings, JPH_RVec3 baseOffset, JPH_CollideShapeCollector *collector, const JPH_BroadPhaseLayerFilter *broadPhaseLayerFilter, const JPH_ObjectLayerFilter *objectLayerFilter, const JPH_BodyFilter *bodyFilter, const JPH_ShapeFilter *shapeFilter);
JOLTC_API void JPH_NarrowPhaseQuery_CastShape(const JPH_NarrowPhaseQuery *query, JPH_RShapeCast shapeCast, JPH_ShapeCastSettings shapeCastSettings, JPH_RVec3 baseOffset, JPH_CastShapeCollector *collector, const JPH_BroadPhaseLayerFilter *broadPhaseLayerFilter, const JPH_ObjectLayerFilter *objectLayerFilter, const JPH_BodyFilter *bodyFilter, const JPH_ShapeFilter *shapeFilter);
JOLTC_API void JPH_NarrowPhaseQuery_CollectTransformedShapes(const JPH_NarrowPhaseQuery *query, JPH_AABox box, JPH_TransformedShapeCollector *collector, const JPH_BroadPhaseLayerFilter *broadPhaseLayerFilter, const JPH_ObjectLayerFilter *objectLayerFilter, const JPH_BodyFilter *bodyFilter, const JPH_ShapeFilter *shapeFilter);
