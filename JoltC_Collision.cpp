#include <JoltC.hpp>

JOLTC_SUPPRESS_WARNINGS()

BEGIN_INTERFACE_WRAPPER_CLASS(BroadPhaseLayerInterface);

    virtual uint32_t GetNumBroadPhaseLayers() const override {
        if (funcs.GetNumBroadPhaseLayers) {
            return funcs.GetNumBroadPhaseLayers(data);
        }
        return 0;
    }

    virtual JPH::BroadPhaseLayer GetBroadPhaseLayer(JPH::ObjectLayer layer) const override {
        if (funcs.GetBroadPhaseLayer) {
            return JPH::BroadPhaseLayer(funcs.GetBroadPhaseLayer(data, layer));
        }
        return JPH::BroadPhaseLayer(0);
    }

#if defined(JOLTC_EXTERNAL_PROFILE) || defined(JOLTC_PROFILE_ENABLED)
    virtual const char *GetBroadPhaseLayerName(JPH::BroadPhaseLayer layer) const override {
        if (funcs.GetBroadPhaseLayerName) {
            return funcs.GetBroadPhaseLayerName(data, layer.GetValue());
        }
        return "";
    }
#endif

END_INTERFACE_WRAPPER_CLASS();

DEFINE_INTERFACE_WRAPPER_FUNCTIONS(BroadPhaseLayerInterface);

uint32_t JPH_BroadPhaseLayerInterface_GetNumBroadPhaseLayers(const JPH_BroadPhaseLayerInterface *bplInterface) {
    return ToCpp(bplInterface)->GetNumBroadPhaseLayers();
}

JPH_BroadPhaseLayer JPH_BroadPhaseLayerInterface_GetBroadPhaseLayer(const JPH_BroadPhaseLayerInterface *bplInterface, JPH_ObjectLayer objectLayer) {
    return ToCpp(bplInterface)->GetBroadPhaseLayer(objectLayer).GetValue();
}

#if defined(JOLTC_EXTERNAL_PROFILE) || defined(JOLTC_PROFILE_ENABLED)

const char *JPH_BroadPhaseLayerInterface_GetBroadPhaseLayerName(const JPH_BroadPhaseLayerInterface *bplInterface, JPH_BroadPhaseLayer broadPhaseLayer) {
    return ToCpp(bplInterface)->GetBroadPhaseLayerName(JPH::BroadPhaseLayer(broadPhaseLayer));
}

#endif

JPH_BroadPhaseLayerInterfaceTable *JPH_BroadPhaseLayerInterfaceTable_Create(uint32_t numObjectLayers, uint32_t numBroadPhaseLayers) {
    return ToC(new JPH::BroadPhaseLayerInterfaceTable(numObjectLayers, numBroadPhaseLayers));
}

void JPH_BroadPhaseLayerInterfaceTable_MapObjectToBroadPhaseLayer(JPH_BroadPhaseLayerInterfaceTable *table, JPH_ObjectLayer objectLayer, JPH_BroadPhaseLayer broadPhaseLayer) {
    ToCpp(table)->MapObjectToBroadPhaseLayer(objectLayer, JPH::BroadPhaseLayer(broadPhaseLayer));
}

#if defined(JOLTC_EXTERNAL_PROFILE) || defined(JOLTC_PROFILE_ENABLED)

void JPH_BroadPhaseLayerInterfaceTable_SetBroadPhaseLayerName(JPH_BroadPhaseLayerInterfaceTable *table, JPH_BroadPhaseLayer broadPhaseLayer, const char *name) {
    ToCpp(table)->SetBroadPhaseLayerName(JPH::BroadPhaseLayer(broadPhaseLayer), name);
}

#endif

JPH_BroadPhaseLayerInterfaceMask *JPH_BroadPhaseLayerInterfaceMask_Create(uint32_t numBroadPhaseLayers) {
    return ToC(new JPH::BroadPhaseLayerInterfaceMask(numBroadPhaseLayers));
}

void JPH_BroadPhaseLayerInterfaceMask_ConfigureLayer(JPH_BroadPhaseLayerInterfaceMask *mask, JPH_BroadPhaseLayer broadPhaseLayer, uint32_t groupsToInclude, uint32_t groupsToExclude) {
    ToCpp(mask)->ConfigureLayer(JPH::BroadPhaseLayer(broadPhaseLayer), groupsToInclude, groupsToExclude);
}

#if defined(JOLTC_EXTERNAL_PROFILE) || defined(JOLTC_PROFILE_ENABLED)

void JPH_BroadPhaseLayerInterfaceMask_SetBroadPhaseLayerName(JPH_BroadPhaseLayerInterfaceMask *mask, JPH_BroadPhaseLayer broadPhaseLayer, const char *name) {
    ToCpp(mask)->SetBroadPhaseLayerName(JPH::BroadPhaseLayer(broadPhaseLayer), name);
}

#endif

BEGIN_INTERFACE_WRAPPER_CLASS(ObjectLayerPairFilter);

    virtual bool ShouldCollide(JPH::ObjectLayer layer1, JPH::ObjectLayer layer2) const override {
        if (funcs.ShouldCollide) {
            return funcs.ShouldCollide(data, layer1, layer2);
        }
        return true;
    }

END_INTERFACE_WRAPPER_CLASS();

DEFINE_INTERFACE_WRAPPER_FUNCTIONS(ObjectLayerPairFilter);

bool JPH_ObjectLayerPairFilter_ShouldCollide(const JPH_ObjectLayerPairFilter *filter, JPH_ObjectLayer layer1, JPH_ObjectLayer layer2) {
    return ToCpp(filter)->ShouldCollide(layer1, layer2);
}

JPH_ObjectLayerPairFilterTable *JPH_ObjectLayerPairFilterTable_Create(uint32_t numObjectLayers) {
    return ToC(new JPH::ObjectLayerPairFilterTable(numObjectLayers));
}

uint32_t JPH_ObjectLayerPairFilterTable_GetNumObjectLayers(const JPH_ObjectLayerPairFilterTable *table) {
    return ToCpp(table)->GetNumObjectLayers();
}

void JPH_ObjectLayerPairFilterTable_EnableCollision(JPH_ObjectLayerPairFilterTable *table, JPH_ObjectLayer layer1, JPH_ObjectLayer layer2) {
    ToCpp(table)->EnableCollision(layer1, layer2);
}

void JPH_ObjectLayerPairFilterTable_DisableCollision(JPH_ObjectLayerPairFilterTable *table, JPH_ObjectLayer layer1, JPH_ObjectLayer layer2) {
    ToCpp(table)->DisableCollision(layer1, layer2);
}

JPH_ObjectLayerPairFilterMask *JPH_ObjectLayerPairFilterMask_Create() {
    return ToC(new JPH::ObjectLayerPairFilterMask);
}

uint32_t JPH_ObjectLayerPairFilterMask_GetGroup(JPH_ObjectLayer objectLayer) {
    return JPH::ObjectLayerPairFilterMask::sGetGroup(objectLayer);
}

uint32_t JPH_ObjectLayerPairFilterMask_GetMask(JPH_ObjectLayer objectLayer) {
    return JPH::ObjectLayerPairFilterMask::sGetMask(objectLayer);
}

JPH_ObjectLayer JPH_ObjectLayerPairFilterMask_GetObjectLayer(uint32_t group, uint32_t mask) {
    return JPH::ObjectLayerPairFilterMask::sGetObjectLayer(group, mask);
}

BEGIN_INTERFACE_WRAPPER_CLASS(ObjectVsBroadPhaseLayerFilter);

    virtual bool ShouldCollide(JPH::ObjectLayer layer1, JPH::BroadPhaseLayer layer2) const override {
        if (funcs.ShouldCollide) {
            return funcs.ShouldCollide(data, layer1, layer2.GetValue());
        }
        return true;
    }

END_INTERFACE_WRAPPER_CLASS();

DEFINE_INTERFACE_WRAPPER_FUNCTIONS(ObjectVsBroadPhaseLayerFilter);

bool JPH_ObjectVsBroadPhaseLayerFilter_ShouldCollide(const JPH_ObjectVsBroadPhaseLayerFilter *filter, JPH_ObjectLayer objectLayer, JPH_BroadPhaseLayer broadPhaseLayer) {
    return ToCpp(filter)->ShouldCollide(objectLayer, JPH::BroadPhaseLayer(broadPhaseLayer));
}

JPH_ObjectVsBroadPhaseLayerFilterTable *JPH_ObjectVsBroadPhaseLayerFilterTable_Create(const JPH_BroadPhaseLayerInterface *bplInterface, uint32_t numBroadPhaseLayers, const JPH_ObjectLayerPairFilter *objectLayerPairFilter, uint32_t numObjectLayers) {
    return ToC(new JPH::ObjectVsBroadPhaseLayerFilterTable(*ToCpp(bplInterface), numBroadPhaseLayers, *ToCpp(objectLayerPairFilter), numObjectLayers));
}

JPH_ObjectVsBroadPhaseLayerFilterMask *JPH_ObjectVsBroadPhaseLayerFilterMask_Create(const JPH_BroadPhaseLayerInterfaceMask *bplInterface) {
    return ToC(new JPH::ObjectVsBroadPhaseLayerFilterMask(*ToCpp(bplInterface)));
}

BEGIN_INTERFACE_WRAPPER_CLASS(BroadPhaseLayerFilter);

	virtual bool ShouldCollide(JPH::BroadPhaseLayer inLayer) const override {
        if (funcs.ShouldCollide) {
            return funcs.ShouldCollide(data, inLayer.GetValue());
        }
        return true;
    }

END_INTERFACE_WRAPPER_CLASS();

DEFINE_INTERFACE_WRAPPER_FUNCTIONS(BroadPhaseLayerFilter);

BEGIN_INTERFACE_WRAPPER_CLASS(ObjectLayerFilter);

	virtual bool ShouldCollide(JPH::ObjectLayer inLayer) const override {
        if (funcs.ShouldCollide) {
            return funcs.ShouldCollide(data, inLayer);
        }
        return true;
    }

END_INTERFACE_WRAPPER_CLASS();

DEFINE_INTERFACE_WRAPPER_FUNCTIONS(ObjectLayerFilter);

BEGIN_INTERFACE_WRAPPER_CLASS(BodyFilter);

    virtual bool ShouldCollide(const JPH::BodyID &bodyID) const override {
        if (funcs.ShouldCollide) {
            return funcs.ShouldCollide(data, bodyID.GetIndexAndSequenceNumber());
        }
        return true;
    }

    virtual bool ShouldCollideLocked(const JPH::Body &body) const override {
        if (funcs.ShouldCollideLocked) {
            return funcs.ShouldCollideLocked(data, ToC(&body));
        } else {
            return ShouldCollide(body.GetID());
        }
    }

END_INTERFACE_WRAPPER_CLASS();

DEFINE_INTERFACE_WRAPPER_FUNCTIONS(BodyFilter);

JPH_IgnoreMultipleBodiesFilter *JPH_IgnoreMultipleBodiesFilter_Create(const JPH_BodyID *bodyIDs, int numBodies, JPH_JoltCAllocator allocator) {
    void *ptr = JPH_JoltCAllocator_Allocate(allocator, sizeof(JPH::IgnoreMultipleBodiesFilter));
    auto filter = new(ptr) JPH::IgnoreMultipleBodiesFilter;
    for (int i = 0; i < numBodies; i += 1) {
        filter->IgnoreBody(JPH::BodyID(bodyIDs[i]));
    }

    return ToC(filter);
}

JPH_IgnoreSingleBodyFilter *JPH_IgnoreSingleBodyFilter_Create(JPH_BodyID bodyID, JPH_JoltCAllocator allocator) {
    void *ptr = JPH_JoltCAllocator_Allocate(allocator, sizeof(JPH::IgnoreSingleBodyFilter));
    return ToC(new(ptr) JPH::IgnoreSingleBodyFilter(JPH::BodyID(bodyID)));
}

JPH_IgnoreSingleBodyFilterChained *JPH_IgnoreSingleBodyFilterChained_Create(JPH_BodyID bodyID, const JPH_BodyFilter *otherFilter, JPH_JoltCAllocator allocator) {
    void *ptr = JPH_JoltCAllocator_Allocate(allocator, sizeof(JPH::IgnoreSingleBodyFilterChained));
    return ToC(new(ptr) JPH::IgnoreSingleBodyFilterChained(JPH::BodyID(bodyID), *ToCpp(otherFilter)));
}

BEGIN_INTERFACE_WRAPPER_CLASS(ShapeFilter);

    virtual bool ShouldCollide(const JPH::Shape *shape2, const JPH::SubShapeID &subShapeIDOfShape2) const override {
        if (funcs.ShouldCollide) {
            return funcs.ShouldCollide(data, ToC(shape2), subShapeIDOfShape2.GetValue());
        }
        return true;
    }

    virtual bool ShouldCollide(const JPH::Shape *shape1, const JPH::SubShapeID &subShapeIDOfShape1, const JPH::Shape *shape2, const JPH::SubShapeID &subShapeIDOfShape2) const override {
        if (funcs.ShapesShouldCollide) {
            return funcs.ShapesShouldCollide(data, ToC(shape1), subShapeIDOfShape1.GetValue(), ToC(shape2), subShapeIDOfShape2.GetValue());
        }
        return true;
    }

END_INTERFACE_WRAPPER_CLASS();

DEFINE_INTERFACE_WRAPPER_FUNCTIONS(ShapeFilter);

JPH_ReversedShapeFilter *JPH_ReversedShapeFilter_Create(const JPH_ShapeFilter *other, JPH_JoltCAllocator allocator) {
    void *ptr = JPH_JoltCAllocator_Allocate(allocator, sizeof(JPH::ReversedShapeFilter));
    return ToC(new(ptr) JPH::ReversedShapeFilter(*ToCpp(other)));
}

BEGIN_INTERFACE_WRAPPER_CLASS(SimShapeFilter);

    virtual bool ShouldCollide(const JPH::Body &body1, const JPH::Shape *shape1, const JPH::SubShapeID &subShapeID1, const JPH::Body &body2, const JPH::Shape *shape2, const JPH::SubShapeID &subShapeID2) const override {
        if (funcs.ShouldCollide) {
            return funcs.ShouldCollide(data, &ToC(body1), ToC(shape1), subShapeID1.GetValue(), &ToC(body2), ToC(shape2), subShapeID2.GetValue());
        }
        return true;
    }

END_INTERFACE_WRAPPER_CLASS();

DEFINE_INTERFACE_WRAPPER_FUNCTIONS(SimShapeFilter);

// Default filters

bool JPH_DefaultBroadPhaseLayerFilter_ShouldCollide(const void *data, JPH_BroadPhaseLayer layer) {
    auto filter = reinterpret_cast<const JPH_DefaultBroadPhaseLayerFilter *>(data);
    return ToCpp(filter->objectVsBroadPhaseLayerFilter)->ShouldCollide(filter->layer, JPH::BroadPhaseLayer(layer));
}

const JPH_BroadPhaseLayerFilter *JPH_DefaultBroadPhaseLayerFilter_CreateFilter(JPH_DefaultBroadPhaseLayerFilter *filter, JPH_JoltCAllocator allocator) {
    JPH_BroadPhaseLayerFilter_Funcs funcs = {};
    funcs.ShouldCollide = JPH_DefaultBroadPhaseLayerFilter_ShouldCollide;

    return JPH_BroadPhaseLayerFilter_Create(filter, funcs, allocator);
}

bool JPH_DefaultObjectLayerFilter_ShouldCollide(const void *data, JPH_ObjectLayer layer) {
    auto filter = reinterpret_cast<const JPH_DefaultObjectLayerFilter *>(data);
    return ToCpp(filter->objectLayerPairFilter)->ShouldCollide(filter->layer, layer);
}

const JPH_ObjectLayerFilter *JPH_DefaultObjectLayerFilter_CreateFilter(JPH_DefaultObjectLayerFilter *filter, JPH_JoltCAllocator allocator) {
    JPH_ObjectLayerFilter_Funcs funcs = {};
    funcs.ShouldCollide = JPH_DefaultObjectLayerFilter_ShouldCollide;

    return JPH_ObjectLayerFilter_Create(filter, funcs, allocator);
}

JPH_RayCast JPH_RayCast_Make(JPH_Vec3 origin, JPH_Vec3 direction, float length) {
    return JPH_RayCast{
        .origin=origin,
        .direction=ToC(ToCpp(direction) * length),
    };
}

JPH_RayCast JPH_RayCast_Transformed(const JPH_RayCast *ray, JPH_Mat44 transform) {
    return ToC(ToCpp(ray)->Transformed(ToCpp(transform)));
}

JPH_RayCast JPH_RayCast_Translated(const JPH_RayCast *ray, JPH_Vec3 translation) {
    return ToC(ToCpp(ray)->Translated(ToCpp(translation)));
}

JPH_Vec3 JPH_RayCast_GetPointOnRay(const JPH_RayCast *ray, float fraction) {
    return ToC(ToCpp(ray)->GetPointOnRay(fraction));
}

JPH_RRayCast JPH_RRayCast_Make(JPH_RVec3 origin, JPH_Vec3 direction, float length) {
    return JPH_RRayCast{
        .origin=origin,
        .direction=ToC(ToCpp(direction) * length),
    };
}

JPH_RRayCast JPH_RRayCast_Transformed(const JPH_RRayCast *ray, JPH_RMat44 transform) {
    return ToC(ToCpp(ray)->Transformed(ToCpp(transform)));
}

JPH_RRayCast JPH_RRayCast_Translated(const JPH_RRayCast *ray, JPH_RVec3 translation) {
    return ToC(ToCpp(ray)->Translated(ToCpp(translation)));
}

JPH_RVec3 JPH_RRayCast_GetPointOnRay(const JPH_RRayCast *ray, float fraction) {
    return ToC(ToCpp(ray)->GetPointOnRay(fraction));
}

JPH_RayCastSettings JPH_RayCastSettings_Default() {
    auto result = JPH::RayCastSettings();
    return *reinterpret_cast<JPH_RayCastSettings *>(&result);
}

JPH_RayCastResult JPH_RayCastResult_Default() {
    auto result = JPH::RayCastResult();
    return *reinterpret_cast<JPH_RayCastResult *>(&result);
}

JPH_ShapeCastSettings JPH_ShapeCastSettings_Default() {
    return JPH_ShapeCastSettings{
        .activeEdgeMode=JPH_EActiveEdgeMode_CollideOnlyWithActive,
        .collectFacesMode=JPH_ECollectFacesMode_NoFaces,
        .collisionTolerance=JPH_cDefaultCollisionTolerance,
        .penetrationTolerance=JPH_cDefaultPenetrationTolerance,
        .activeEdgeMovementDirection=JPH_Vec3_Make(0.0f, 0.0f, 0.0f),

        .extraConvexRadius=0.0f,
        .backFaceModeTriangles=JPH_EBackFaceMode_IgnoreBackFaces,
        .backFaceModeConvex=JPH_EBackFaceMode_IgnoreBackFaces,
        .useShrunkenShapeAndConvexRadius=false,
        .returnDeepestPoint=false,
    };
}

JPH_CollideShapeSettings JPH_CollideShapeSettings_Default() {
    return JPH_CollideShapeSettings{
        .activeEdgeMode=JPH_EActiveEdgeMode_CollideOnlyWithActive,
        .collectFacesMode=JPH_ECollectFacesMode_NoFaces,
        .collisionTolerance=JPH_cDefaultCollisionTolerance,
        .penetrationTolerance=JPH_cDefaultPenetrationTolerance,
        .activeEdgeMovementDirection=JPH_Vec3_Make(0.0f, 0.0f, 0.0f),

        .maxSeparationDistance=0.0f,
        .backFaceMode=JPH_EBackFaceMode_IgnoreBackFaces,
        .internalEdgeRemovalVertexToleranceSq=JPH_cDefaultInternalEdgeRemovalVertexToleranceSq,
    };
}

JPH_AABox JPH_BroadPhaseQuery_GetBounds(const JPH_BroadPhaseQuery *query) {
    return ToC(ToCpp(query)->GetBounds());
}

#define DEFINE_COLLISION_COLLECTOR_INTERFACE_WRAPPER_CLASS(name, result_type) \
    class name##Wrapper final : public JPH::name { \
    private: \
        void *data; \
        JPH_CollisionCollector_##result_type##_Funcs funcs; \
        JPH_JoltCAllocator allocator; \
    \
    public: \
        void operator delete (void *ptr) noexcept                { JPH_JoltCAllocator allocator = reinterpret_cast<name##Wrapper *>(ptr)->allocator; JPH_JoltCAllocator_Free(allocator, ptr); } \
        void operator delete (void *ptr, size_t size) noexcept   { JPH_JoltCAllocator allocator = reinterpret_cast<name##Wrapper *>(ptr)->allocator; JPH_JoltCAllocator_Free(allocator, ptr); } \
        void operator delete[] (void *ptr) noexcept              { JPH_JoltCAllocator allocator = reinterpret_cast<name##Wrapper *>(ptr)->allocator; JPH_JoltCAllocator_Free(allocator, ptr); } \
        void operator delete[] (void *ptr, size_t size) noexcept { JPH_JoltCAllocator allocator = reinterpret_cast<name##Wrapper *>(ptr)->allocator; JPH_JoltCAllocator_Free(allocator, ptr); } \
    \
        name##Wrapper(void *data, JPH_CollisionCollector_##result_type##_Funcs funcs, JPH_JoltCAllocator allocator) \
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
        } \
    \
        virtual void Reset() override { \
            if (funcs.Reset) { \
                funcs.Reset(data); \
            } \
        } \
    \
        virtual void OnBody(const JPH::Body &body) override { \
            if (funcs.OnBody) { \
                funcs.OnBody(data, &ToC(body)); \
            } \
        } \
    \
        virtual void OnBodyEnd() override { \
            if (funcs.OnBodyEnd) { \
                funcs.OnBodyEnd(data); \
            } \
        } \
    \
        virtual void SetUserData(uint64_t userData) override { \
            if (funcs.SetUserData) { \
                funcs.SetUserData(data, userData); \
            } \
        } \
    \
        virtual void AddHit(const JPH::name::ResultType &result) override { \
            if (funcs.AddHit) { \
                funcs.AddHit(data, ToC(result)); \
            } \
        } \
    }; \
    \
    JPH_##name *JPH_##name##_Create(void *data, JPH_CollisionCollector_##result_type##_Funcs funcs, JPH_JoltCAllocator allocator) { \
        void *ptr = JPH_JoltCAllocator_Allocate(allocator, sizeof(name##Wrapper)); \
        return ToC(new(ptr) name##Wrapper(data, funcs, allocator)); \
    } \
    \
    void JPH_##name##_Destroy(JPH_##name *self) { \
        delete ToCpp(self); \
    }

DEFINE_COLLISION_COLLECTOR_INTERFACE_WRAPPER_CLASS(RayCastBodyCollector, BroadPhaseCastResult);
DEFINE_COLLISION_COLLECTOR_INTERFACE_WRAPPER_CLASS(CastShapeBodyCollector, BroadPhaseCastResult);
DEFINE_COLLISION_COLLECTOR_INTERFACE_WRAPPER_CLASS(CollideShapeBodyCollector, BodyID);

bool JPH_BroadPhaseQuery_CastRaySimple(const JPH_BroadPhaseQuery *query, JPH_RayCast ray, JPH_ECollisionCollectorType collectorType, void *callbackData, JPH_BroadPhaseQuery_CastRayHitCallback callback, const JPH_BroadPhaseLayerFilter *broadPhaseLayerFilter, const JPH_ObjectLayerFilter *objectLayerFilter) {
    switch (collectorType) {
    case JPH_ECollisionCollectorType_AnyHit: {
        JPH::AnyHitCollisionCollector<JPH::RayCastBodyCollector> collector;
        ToCpp(query)->CastRay(ToCpp(ray), collector, *ToCpp(broadPhaseLayerFilter), *ToCpp(objectLayerFilter));

        if (collector.HadHit()) {
            JPH_BroadPhaseCastResult result;
            result.bodyID = collector.mHit.mBodyID.GetIndexAndSequenceNumber();
            result.fraction = collector.mHit.mFraction;
            if (callback) {
                callback(callbackData, &result);
            }
            return true;
        }
    } break;

    case JPH_ECollisionCollectorType_ClosestHit: {
        JPH::ClosestHitCollisionCollector<JPH::RayCastBodyCollector> collector;
        ToCpp(query)->CastRay(ToCpp(ray), collector, *ToCpp(broadPhaseLayerFilter), *ToCpp(objectLayerFilter));

        if (collector.HadHit()) {
            JPH_BroadPhaseCastResult result;
            result.bodyID = collector.mHit.mBodyID.GetIndexAndSequenceNumber();
            result.fraction = collector.mHit.mFraction;
            if (callback) {
                callback(callbackData, &result);
            }
            return true;
        }
    } break;

    case JPH_ECollisionCollectorType_AllHitsSorted:
    case JPH_ECollisionCollectorType_AllHits: {
        JPH::AllHitCollisionCollector<JPH::RayCastBodyCollector> collector;
        ToCpp(query)->CastRay(ToCpp(ray), collector, *ToCpp(broadPhaseLayerFilter), *ToCpp(objectLayerFilter));

        if (collector.HadHit()) {
            if (callback) {
                if (collectorType == JPH_ECollisionCollectorType_AllHitsSorted) {
                    collector.Sort();
                }

                JPH_BroadPhaseCastResult result;

                for (const auto &hit : collector.mHits) {
                    result.bodyID = hit.mBodyID.GetIndexAndSequenceNumber();
                    result.fraction = hit.mFraction;
                    callback(callbackData, &result);
                }
            }

            return true;
        }
    } break;
    }

    return false;
}

void JPH_BroadPhaseQuery_CastRay(const JPH_BroadPhaseQuery *query, JPH_RayCast ray, JPH_RayCastBodyCollector *collector, const JPH_BroadPhaseLayerFilter *broadPhaseLayerFilter, const JPH_ObjectLayerFilter *objectLayerFilter) {
    ToCpp(query)->CastRay(ToCpp(ray), *ToCpp(collector), *ToCpp(broadPhaseLayerFilter), *ToCpp(objectLayerFilter));
}

void JPH_BroadPhaseQuery_CollideAABox(const JPH_BroadPhaseQuery *query, JPH_AABox box, JPH_CollideShapeBodyCollector *collector, const JPH_BroadPhaseLayerFilter *broadPhaseLayerFilter, const JPH_ObjectLayerFilter *objectLayerFilter) {
    ToCpp(query)->CollideAABox(ToCpp(box), *ToCpp(collector), *ToCpp(broadPhaseLayerFilter), *ToCpp(objectLayerFilter));
}

void JPH_BroadPhaseQuery_CollideSphere(const JPH_BroadPhaseQuery *query, JPH_Vec3 center, float radius, JPH_CollideShapeBodyCollector *collector, const JPH_BroadPhaseLayerFilter *broadPhaseLayerFilter, const JPH_ObjectLayerFilter *objectLayerFilter) {
    ToCpp(query)->CollideSphere(ToCpp(center), radius, *ToCpp(collector), *ToCpp(broadPhaseLayerFilter), *ToCpp(objectLayerFilter));
}

void JPH_BroadPhaseQuery_CollidePoint(const JPH_BroadPhaseQuery *query, JPH_Vec3 point, JPH_CollideShapeBodyCollector *collector, const JPH_BroadPhaseLayerFilter *broadPhaseLayerFilter, const JPH_ObjectLayerFilter *objectLayerFilter) {
    ToCpp(query)->CollidePoint(ToCpp(point), *ToCpp(collector), *ToCpp(broadPhaseLayerFilter), *ToCpp(objectLayerFilter));
}

void JPH_BroadPhaseQuery_CollideOrientedBox(const JPH_BroadPhaseQuery *query, JPH_OrientedBox box, JPH_CollideShapeBodyCollector *collector, const JPH_BroadPhaseLayerFilter *broadPhaseLayerFilter, const JPH_ObjectLayerFilter *objectLayerFilter) {
    ToCpp(query)->CollideOrientedBox(ToCpp(box), *ToCpp(collector), *ToCpp(broadPhaseLayerFilter), *ToCpp(objectLayerFilter));
}

void JPH_BroadPhaseQuery_CastAABox(const JPH_BroadPhaseQuery *query, JPH_AABoxCast box, JPH_CastShapeBodyCollector *collector, const JPH_BroadPhaseLayerFilter *broadPhaseLayerFilter, const JPH_ObjectLayerFilter *objectLayerFilter) {
    ToCpp(query)->CastAABox(ToCpp(box), *ToCpp(collector), *ToCpp(broadPhaseLayerFilter), *ToCpp(objectLayerFilter));
}

DEFINE_COLLISION_COLLECTOR_INTERFACE_WRAPPER_CLASS(CastRayCollector, RayCastResult);
DEFINE_COLLISION_COLLECTOR_INTERFACE_WRAPPER_CLASS(CastShapeCollector, ShapeCastResult);
DEFINE_COLLISION_COLLECTOR_INTERFACE_WRAPPER_CLASS(CollidePointCollector, CollidePointResult);
DEFINE_COLLISION_COLLECTOR_INTERFACE_WRAPPER_CLASS(CollideShapeCollector, CollideShapeResult);
DEFINE_COLLISION_COLLECTOR_INTERFACE_WRAPPER_CLASS(TransformedShapeCollector, TransformedShape);

bool JPH_NarrowPhaseQuery_CastRayClosest(const JPH_NarrowPhaseQuery *query, JPH_RRayCast ray, JPH_RayCastResult *ioHit, const JPH_BroadPhaseLayerFilter *broadPhaseLayerFilter, const JPH_ObjectLayerFilter *objectLayerFilter, const JPH_BodyFilter *bodyFilter) {
    JPH::BroadPhaseLayerFilter defaultBroadPhaseLayerFilter;
    if (!broadPhaseLayerFilter) {
        broadPhaseLayerFilter = ToC(&defaultBroadPhaseLayerFilter);
    }

    JPH::ObjectLayerFilter defaultObjectLayerFilter;
    if (!objectLayerFilter) {
        objectLayerFilter = ToC(&defaultObjectLayerFilter);
    }

    JPH::BodyFilter defaultBodyFilter;
    if (!bodyFilter) {
        bodyFilter = ToC(&defaultBodyFilter);
    }

    return ToCpp(query)->CastRay(ToCpp(ray), *ToCpp(ioHit), *ToCpp(broadPhaseLayerFilter), *ToCpp(objectLayerFilter), *ToCpp(bodyFilter));
}

void JPH_NarrowPhaseQuery_CastRay(const JPH_NarrowPhaseQuery *query, JPH_RRayCast ray, JPH_RayCastSettings settings, JPH_CastRayCollector *collector, const JPH_BroadPhaseLayerFilter *broadPhaseLayerFilter, const JPH_ObjectLayerFilter *objectLayerFilter, const JPH_BodyFilter *bodyFilter, const JPH_ShapeFilter *shapeFilter) {
    JPH::BroadPhaseLayerFilter defaultBroadPhaseLayerFilter;
    if (!broadPhaseLayerFilter) {
        broadPhaseLayerFilter = ToC(&defaultBroadPhaseLayerFilter);
    }

    JPH::ObjectLayerFilter defaultObjectLayerFilter;
    if (!objectLayerFilter) {
        objectLayerFilter = ToC(&defaultObjectLayerFilter);
    }

    JPH::BodyFilter defaultBodyFilter;
    if (!bodyFilter) {
        bodyFilter = ToC(&defaultBodyFilter);
    }

    JPH::ShapeFilter defaultShapeFilter;
    if (!shapeFilter) {
        shapeFilter = ToC(&defaultShapeFilter);
    }

    ToCpp(query)->CastRay(ToCpp(ray), ToCpp(settings), *ToCpp(collector), *ToCpp(broadPhaseLayerFilter), *ToCpp(objectLayerFilter), *ToCpp(bodyFilter), *ToCpp(shapeFilter));
}

void JPH_NarrowPhaseQuery_CollidePoint(const JPH_NarrowPhaseQuery *query, JPH_RVec3 point, JPH_CollidePointCollector *collector, const JPH_BroadPhaseLayerFilter *broadPhaseLayerFilter, const JPH_ObjectLayerFilter *objectLayerFilter, const JPH_BodyFilter *bodyFilter, const JPH_ShapeFilter *shapeFilter) {
    JPH::BroadPhaseLayerFilter defaultBroadPhaseLayerFilter;
    if (!broadPhaseLayerFilter) {
        broadPhaseLayerFilter = ToC(&defaultBroadPhaseLayerFilter);
    }

    JPH::ObjectLayerFilter defaultObjectLayerFilter;
    if (!objectLayerFilter) {
        objectLayerFilter = ToC(&defaultObjectLayerFilter);
    }

    JPH::BodyFilter defaultBodyFilter;
    if (!bodyFilter) {
        bodyFilter = ToC(&defaultBodyFilter);
    }

    JPH::ShapeFilter defaultShapeFilter;
    if (!shapeFilter) {
        shapeFilter = ToC(&defaultShapeFilter);
    }

    ToCpp(query)->CollidePoint(ToCpp(point), *ToCpp(collector), *ToCpp(broadPhaseLayerFilter), *ToCpp(objectLayerFilter), *ToCpp(bodyFilter), *ToCpp(shapeFilter));
}

void JPH_NarrowPhaseQuery_CollideShape(const JPH_NarrowPhaseQuery *query, const JPH_Shape *shape, JPH_Vec3 shapeScale, JPH_RMat44 centerOfMassTransform, JPH_CollideShapeSettings settings, JPH_RVec3 baseOffset, JPH_CollideShapeCollector *collector, const JPH_BroadPhaseLayerFilter *broadPhaseLayerFilter, const JPH_ObjectLayerFilter *objectLayerFilter, const JPH_BodyFilter *bodyFilter, const JPH_ShapeFilter *shapeFilter) {
    JPH::BroadPhaseLayerFilter defaultBroadPhaseLayerFilter;
    if (!broadPhaseLayerFilter) {
        broadPhaseLayerFilter = ToC(&defaultBroadPhaseLayerFilter);
    }

    JPH::ObjectLayerFilter defaultObjectLayerFilter;
    if (!objectLayerFilter) {
        objectLayerFilter = ToC(&defaultObjectLayerFilter);
    }

    JPH::BodyFilter defaultBodyFilter;
    if (!bodyFilter) {
        bodyFilter = ToC(&defaultBodyFilter);
    }

    JPH::ShapeFilter defaultShapeFilter;
    if (!shapeFilter) {
        shapeFilter = ToC(&defaultShapeFilter);
    }

    ToCpp(query)->CollideShape(ToCpp(shape), ToCpp(shapeScale), ToCpp(centerOfMassTransform), ToCpp(settings), ToCpp(baseOffset), *ToCpp(collector), *ToCpp(broadPhaseLayerFilter), *ToCpp(objectLayerFilter), *ToCpp(bodyFilter), *ToCpp(shapeFilter));
}

void JPH_NarrowPhaseQuery_CollideShapeWithInternalEdgeRemoval(const JPH_NarrowPhaseQuery *query, const JPH_Shape *shape, JPH_Vec3 shapeScale, JPH_RMat44 centerOfMassTransform, JPH_CollideShapeSettings settings, JPH_RVec3 baseOffset, JPH_CollideShapeCollector *collector, const JPH_BroadPhaseLayerFilter *broadPhaseLayerFilter, const JPH_ObjectLayerFilter *objectLayerFilter, const JPH_BodyFilter *bodyFilter, const JPH_ShapeFilter *shapeFilter) {
    JPH::BroadPhaseLayerFilter defaultBroadPhaseLayerFilter;
    if (!broadPhaseLayerFilter) {
        broadPhaseLayerFilter = ToC(&defaultBroadPhaseLayerFilter);
    }

    JPH::ObjectLayerFilter defaultObjectLayerFilter;
    if (!objectLayerFilter) {
        objectLayerFilter = ToC(&defaultObjectLayerFilter);
    }

    JPH::BodyFilter defaultBodyFilter;
    if (!bodyFilter) {
        bodyFilter = ToC(&defaultBodyFilter);
    }

    JPH::ShapeFilter defaultShapeFilter;
    if (!shapeFilter) {
        shapeFilter = ToC(&defaultShapeFilter);
    }

    ToCpp(query)->CollideShapeWithInternalEdgeRemoval(ToCpp(shape), ToCpp(shapeScale), ToCpp(centerOfMassTransform), ToCpp(settings), ToCpp(baseOffset), *ToCpp(collector), *ToCpp(broadPhaseLayerFilter), *ToCpp(objectLayerFilter), *ToCpp(bodyFilter), *ToCpp(shapeFilter));
}

void JPH_NarrowPhaseQuery_CastShape(const JPH_NarrowPhaseQuery *query, JPH_RShapeCast shapeCast, JPH_ShapeCastSettings settings, JPH_RVec3 baseOffset, JPH_CastShapeCollector *collector, const JPH_BroadPhaseLayerFilter *broadPhaseLayerFilter, const JPH_ObjectLayerFilter *objectLayerFilter, const JPH_BodyFilter *bodyFilter, const JPH_ShapeFilter *shapeFilter) {
    JPH::BroadPhaseLayerFilter defaultBroadPhaseLayerFilter;
    if (!broadPhaseLayerFilter) {
        broadPhaseLayerFilter = ToC(&defaultBroadPhaseLayerFilter);
    }

    JPH::ObjectLayerFilter defaultObjectLayerFilter;
    if (!objectLayerFilter) {
        objectLayerFilter = ToC(&defaultObjectLayerFilter);
    }

    JPH::BodyFilter defaultBodyFilter;
    if (!bodyFilter) {
        bodyFilter = ToC(&defaultBodyFilter);
    }

    JPH::ShapeFilter defaultShapeFilter;
    if (!shapeFilter) {
        shapeFilter = ToC(&defaultShapeFilter);
    }

    ToCpp(query)->CastShape(ToCpp(shapeCast), ToCpp(settings), ToCpp(baseOffset), *ToCpp(collector), *ToCpp(broadPhaseLayerFilter), *ToCpp(objectLayerFilter), *ToCpp(bodyFilter), *ToCpp(shapeFilter));
}

void JPH_NarrowPhaseQuery_CollectTransformedShapes(const JPH_NarrowPhaseQuery *query, JPH_AABox box, JPH_TransformedShapeCollector *collector, const JPH_BroadPhaseLayerFilter *broadPhaseLayerFilter, const JPH_ObjectLayerFilter *objectLayerFilter, const JPH_BodyFilter *bodyFilter, const JPH_ShapeFilter *shapeFilter) {
    JPH::BroadPhaseLayerFilter defaultBroadPhaseLayerFilter;
    if (!broadPhaseLayerFilter) {
        broadPhaseLayerFilter = ToC(&defaultBroadPhaseLayerFilter);
    }

    JPH::ObjectLayerFilter defaultObjectLayerFilter;
    if (!objectLayerFilter) {
        objectLayerFilter = ToC(&defaultObjectLayerFilter);
    }

    JPH::BodyFilter defaultBodyFilter;
    if (!bodyFilter) {
        bodyFilter = ToC(&defaultBodyFilter);
    }

    JPH::ShapeFilter defaultShapeFilter;
    if (!shapeFilter) {
        shapeFilter = ToC(&defaultShapeFilter);
    }

    ToCpp(query)->CollectTransformedShapes(ToCpp(box), *ToCpp(collector), *ToCpp(broadPhaseLayerFilter), *ToCpp(objectLayerFilter), *ToCpp(bodyFilter), *ToCpp(shapeFilter));
}

JOLTC_POP_WARNINGS()
