#include <JoltC.hpp>

JOLTC_SUPPRESS_WARNINGS()

// ShapeSettings

JOLTC_API JPH_Shape *JPH_EmptyShapeSettings_CreateShape(const JPH_EmptyShapeSettings *settings) {
    JPH::EmptyShapeSettings cppSettings;
    cppSettings.SetEmbedded();
    cppSettings.mUserData = settings->base.userData;
    cppSettings.mCenterOfMass = ToCpp(settings->centerOfMass);

    auto result = cppSettings.Create();
    if (!result.IsValid()) {
        return nullptr;
    }

    auto shape = result.Get().GetPtr();
    shape->AddRef();

    return ToC(shape);
}

JOLTC_API JPH_Shape *JPH_PlaneShapeSettings_CreateShape(const JPH_PlaneShapeSettings *settings) {
    JPH::PlaneShapeSettings cppSettings;
    cppSettings.SetEmbedded();
    cppSettings.mUserData = settings->base.userData;
    cppSettings.mPlane = ToCpp(settings->plane);
    cppSettings.mMaterial = ToCpp(settings->material);
    cppSettings.mHalfExtent = settings->halfExtent;

    auto result = cppSettings.Create();
    if (!result.IsValid()) {
        return nullptr;
    }

    auto shape = result.Get().GetPtr();
    shape->AddRef();

    return ToC(shape);
}

JOLTC_API JPH_Shape *JPH_MeshShapeSettings_CreateShape(const JPH_MeshShapeSettings *settings) {
    auto vertices = JPH::VertexList(ToCpp(settings->vertices), ToCpp(settings->vertices + settings->numVertices));
    auto triangles = JPH::IndexedTriangleList(ToCpp(settings->indexedTriangles), ToCpp(settings->indexedTriangles + settings->numIndexedTriangles));
    auto materialsBegin = reinterpret_cast<JPH::PhysicsMaterialRefC *>(settings->materials);
    auto materialsEnd = reinterpret_cast<JPH::PhysicsMaterialRefC *>(settings->materials + settings->numMaterials);
    auto materials = JPH::PhysicsMaterialList(materialsBegin, materialsEnd);

    auto cppSettings = JPH::MeshShapeSettings(vertices, triangles, materials);
    cppSettings.SetEmbedded();
    cppSettings.mUserData = settings->base.userData;
    cppSettings.mMaxTrianglesPerLeaf = settings->maxTrianglesPerLeaf;
    cppSettings.mActiveEdgeCosThresholdAngle = settings->activeEdgeCosThresholdAngle;
    cppSettings.mPerTriangleUserData = settings->perTriangleUserData;
    cppSettings.mBuildQuality = static_cast<JPH::MeshShapeSettings::EBuildQuality>(settings->buildQuality);

    auto result = cppSettings.Create();
    if (!result.IsValid()) {
        return nullptr;
    }

    auto shape = result.Get().GetPtr();
    shape->AddRef();

    return ToC(shape);
}

JOLTC_API JPH_Shape *JPH_HeightFieldShapeSettings_CreateShape(const JPH_HeightFieldShapeSettings *settings) {
    auto materialsBegin = reinterpret_cast<JPH::PhysicsMaterialRefC *>(settings->materials);
    auto materialsEnd = reinterpret_cast<JPH::PhysicsMaterialRefC *>(settings->materials + settings->numMaterials);
    auto materials = JPH::PhysicsMaterialList(materialsBegin, materialsEnd);

    auto cppSettings = JPH::HeightFieldShapeSettings(settings->heightSamples, ToCpp(settings->offset), ToCpp(settings->scale), settings->sampleCount, settings->materialIndices, materials);
    cppSettings.SetEmbedded();
    cppSettings.mUserData = settings->base.userData;
    cppSettings.mMinHeightValue = settings->minHeightValue;
    cppSettings.mMaxHeightValue = settings->maxHeightValue;
    cppSettings.mMaterialsCapacity = settings->materialsCapacity;
    cppSettings.mBlockSize = settings->blockSize;
    cppSettings.mBitsPerSample = settings->bitsPerSample;
    cppSettings.mActiveEdgeCosThresholdAngle = settings->activeEdgeCosThresholdAngle;

    auto result = cppSettings.Create();
    if (!result.IsValid()) {
        return nullptr;
    }

    auto shape = result.Get().GetPtr();
    shape->AddRef();

    return ToC(shape);
}

JPH_Shape *JPH_SphereShapeSettings_CreateShape(const JPH_SphereShapeSettings *settings) {
    auto cppSettings = JPH::SphereShapeSettings(settings->radius, ToCpp(settings->base.material));
    cppSettings.SetEmbedded();
    cppSettings.mUserData = settings->base.base.userData;
    cppSettings.mDensity = settings->base.density;

    auto result = cppSettings.Create();
    if (!result.IsValid()) {
        return nullptr;
    }

    auto shape = result.Get().GetPtr();
    shape->AddRef();

    return ToC(shape);
}

JPH_Shape *JPH_BoxShapeSettings_CreateShape(const JPH_BoxShapeSettings *settings) {
    auto cppSettings = JPH::BoxShapeSettings(ToCpp(settings->halfExtent), settings->convexRadius, ToCpp(settings->base.material));
    cppSettings.SetEmbedded();
    cppSettings.mUserData = settings->base.base.userData;
    cppSettings.mDensity = settings->base.density;

    auto result = cppSettings.Create();
    if (!result.IsValid()) {
        return nullptr;
    }

    auto shape = result.Get().GetPtr();
    shape->AddRef();

    return ToC(shape);
}

JPH_Shape *JPH_TriangleShapeSettings_CreateShape(const JPH_TriangleShapeSettings *settings) {
    auto cppSettings = JPH::TriangleShapeSettings(ToCpp(settings->v1), ToCpp(settings->v2), ToCpp(settings->v3), settings->convexRadius, ToCpp(settings->base.material));
    cppSettings.SetEmbedded();
    cppSettings.mUserData = settings->base.base.userData;
    cppSettings.mDensity = settings->base.density;

    auto result = cppSettings.Create();
    if (!result.IsValid()) {
        return nullptr;
    }

    auto shape = result.Get().GetPtr();
    shape->AddRef();

    return ToC(shape);
}

JPH_Shape *JPH_CapsuleShapeSettings_CreateShape(const JPH_CapsuleShapeSettings *settings) {
    auto cppSettings = JPH::CapsuleShapeSettings(settings->halfHeightOfCylinder, settings->radius, ToCpp(settings->base.material));
    cppSettings.SetEmbedded();
    cppSettings.mUserData = settings->base.base.userData;
    cppSettings.mDensity = settings->base.density;

    auto result = cppSettings.Create();
    if (!result.IsValid()) {
        return nullptr;
    }

    auto shape = result.Get().GetPtr();
    shape->AddRef();

    return ToC(shape);
}

bool JPH_CapsuleShapeSettings_IsValid(const JPH_CapsuleShapeSettings *settings) {
    return settings->radius > 0.0f && settings->halfHeightOfCylinder >= 0.0f;
}

bool JPH_CapsuleShapeSettings_IsSphere(const JPH_CapsuleShapeSettings *settings) {
    return settings->halfHeightOfCylinder == 0.0f;
}

JPH_Shape *JPH_TaperedCapsuleShapeSettings_CreateShape(const JPH_TaperedCapsuleShapeSettings *settings) {
    auto cppSettings = JPH::TaperedCapsuleShapeSettings(settings->halfHeightOfTaperedCylinder, settings->topRadius, settings->bottomRadius, ToCpp(settings->base.material));
    cppSettings.SetEmbedded();
    cppSettings.mUserData = settings->base.base.userData;
    cppSettings.mDensity = settings->base.density;

    auto result = cppSettings.Create();
    if (!result.IsValid()) {
        return nullptr;
    }

    auto shape = result.Get().GetPtr();
    shape->AddRef();

    return ToC(shape);
}

bool JPH_TaperedCapsuleShapeSettings_IsValid(const JPH_TaperedCapsuleShapeSettings *settings) {
    return settings->topRadius > 0.0f && settings->bottomRadius > 0.0f && settings->halfHeightOfTaperedCylinder >= 0.0f;
}

bool JPH_TaperedCapsuleShapeSettings_IsSphere(const JPH_TaperedCapsuleShapeSettings *settings) {
    float minRadius = settings->topRadius > settings->bottomRadius ? settings->bottomRadius : settings->topRadius;
    float maxRadius = settings->topRadius < settings->bottomRadius ? settings->bottomRadius : settings->topRadius;
	return maxRadius >= 2.0f * settings->halfHeightOfTaperedCylinder + minRadius;
}

JPH_Shape *JPH_CylinderShapeSettings_CreateShape(const JPH_CylinderShapeSettings *settings) {
    auto cppSettings = JPH::CylinderShapeSettings(settings->halfHeight, settings->radius, settings->convexRadius, ToCpp(settings->base.material));
    cppSettings.SetEmbedded();
    cppSettings.mUserData = settings->base.base.userData;
    cppSettings.mDensity = settings->base.density;

    auto result = cppSettings.Create();
    if (!result.IsValid()) {
        return nullptr;
    }

    auto shape = result.Get().GetPtr();
    shape->AddRef();

    return ToC(shape);
}

JPH_Shape *JPH_TaperedCylinderShapeSettings_CreateShape(const JPH_TaperedCylinderShapeSettings *settings) {
    auto cppSettings = JPH::TaperedCylinderShapeSettings(settings->halfHeight, settings->topRadius, settings->bottomRadius, settings->convexRadius, ToCpp(settings->base.material));
    cppSettings.SetEmbedded();
    cppSettings.mUserData = settings->base.base.userData;
    cppSettings.mDensity = settings->base.density;

    auto result = cppSettings.Create();
    if (!result.IsValid()) {
        return nullptr;
    }

    auto shape = result.Get().GetPtr();
    shape->AddRef();

    return ToC(shape);
}

JPH_Shape *JPH_ConvexHullShapeSettings_CreateShape(const JPH_ConvexHullShapeSettings *settings) {
    auto cppSettings = JPH::ConvexHullShapeSettings(ToCpp(settings->points), settings->numPoints, settings->maxConvexRadius, ToCpp(settings->base.material));
    cppSettings.SetEmbedded();
    cppSettings.mUserData = settings->base.base.userData;
    cppSettings.mDensity = settings->base.density;
    cppSettings.mMaxErrorConvexRadius = settings->maxErrorConvexRadius;
    cppSettings.mHullTolerance = settings->hullTolerance;

    auto result = cppSettings.Create();
    if (!result.IsValid()) {
        return nullptr;
    }

    auto shape = result.Get().GetPtr();
    shape->AddRef();

    return ToC(shape);
}

JPH_Shape *JPH_StaticCompoundShapeSettings_CreateShape(const JPH_StaticCompoundShapeSettings *settings) {
    auto cppSettings = JPH::StaticCompoundShapeSettings();
    cppSettings.SetEmbedded();
    cppSettings.mUserData = settings->base.base.userData;
    for (uint32_t i = 0; i < settings->base.numSubShapes; i += 1) {
        const auto &subShape = settings->base.subShapes[i];
        cppSettings.AddShape(ToCpp(subShape.position), ToCpp(subShape.rotation), ToCpp(subShape.shape), subShape.userData);
    }

    auto result = cppSettings.Create();
    if (!result.IsValid()) {
        return nullptr;
    }

    auto shape = result.Get().GetPtr();
    shape->AddRef();

    return ToC(shape);
}

JPH_Shape *JPH_MutableCompoundShapeSettings_CreateShape(const JPH_MutableCompoundShapeSettings *settings) {
    auto cppSettings = JPH::MutableCompoundShapeSettings();
    cppSettings.SetEmbedded();
    cppSettings.mUserData = settings->base.base.userData;
    for (uint32_t i = 0; i < settings->base.numSubShapes; i += 1) {
        const auto &subShape = settings->base.subShapes[i];
        cppSettings.AddShape(ToCpp(subShape.position), ToCpp(subShape.rotation), ToCpp(subShape.shape), subShape.userData);
    }

    auto result = cppSettings.Create();
    if (!result.IsValid()) {
        return nullptr;
    }

    auto shape = result.Get().GetPtr();
    shape->AddRef();

    return ToC(shape);
}

JPH_Shape *JPH_RotatedTranslatedShapeSettings_CreateShape(const JPH_RotatedTranslatedShapeSettings *settings) {
    auto cppSettings = JPH::RotatedTranslatedShapeSettings(ToCpp(settings->position), ToCpp(settings->rotation), ToCpp(settings->base.innerShape));
    cppSettings.SetEmbedded();
    cppSettings.mUserData = settings->base.base.userData;

    auto result = cppSettings.Create();
    if (!result.IsValid()) {
        return nullptr;
    }

    auto shape = result.Get().GetPtr();
    shape->AddRef();

    return ToC(shape);
}

JPH_Shape *JPH_ScaledShapeSettings_CreateShape(const JPH_ScaledShapeSettings *settings) {
    auto cppSettings = JPH::ScaledShapeSettings(ToCpp(settings->base.innerShape), ToCpp(settings->scale));
    cppSettings.SetEmbedded();
    cppSettings.mUserData = settings->base.base.userData;

    auto result = cppSettings.Create();
    if (!result.IsValid()) {
        return nullptr;
    }

    auto shape = result.Get().GetPtr();
    shape->AddRef();

    return ToC(shape);
}

JPH_Shape *JPH_OffsetCenterOfMassShapeSettings_CreateShape(const JPH_OffsetCenterOfMassShapeSettings *settings) {
    auto cppSettings = JPH::OffsetCenterOfMassShapeSettings(ToCpp(settings->offset), ToCpp(settings->base.innerShape));
    cppSettings.SetEmbedded();
    cppSettings.mUserData = settings->base.base.userData;

    auto result = cppSettings.Create();
    if (!result.IsValid()) {
        return nullptr;
    }

    auto shape = result.Get().GetPtr();
    shape->AddRef();

    return ToC(shape);
}

// MassProperties

JPH_Vec3 JPH_MassProperties_GetEquivalentSolidBoxSize(float mass, JPH_Vec3 inertiaDiagonal) {
    return ToC(JPH::MassProperties::sGetEquivalentSolidBoxSize(mass, ToCpp(inertiaDiagonal)));
}

bool JPH_MassProperties_DecomposePrincipalMomentsOfInertia(JPH_MassProperties *massProperties, JPH_Mat44 *outRotation, JPH_Vec3 *outDiagonal) {
    return reinterpret_cast<JPH::MassProperties *>(massProperties)->DecomposePrincipalMomentsOfInertia(*reinterpret_cast<JPH::Mat44 *>(outRotation), *reinterpret_cast<JPH::Vec3 *>(outDiagonal));
}

void JPH_MassProperties_SetMassAndInertiaOfSolidBox(JPH_MassProperties *massProperties, JPH_Vec3 boxSize, float density) {
    reinterpret_cast<JPH::MassProperties *>(massProperties)->SetMassAndInertiaOfSolidBox(ToCpp(boxSize), density);
}

void JPH_MassProperties_ScaleToMass(JPH_MassProperties *massProperties, float mass) {
    reinterpret_cast<JPH::MassProperties *>(massProperties)->ScaleToMass(mass);
}

void JPH_MassProperties_Rotate(JPH_MassProperties *massProperties, JPH_Mat44 rotation) {
    reinterpret_cast<JPH::MassProperties *>(massProperties)->Rotate(ToCpp(rotation));
}

void JPH_MassProperties_Translate(JPH_MassProperties *massProperties, JPH_Vec3 translation) {
    reinterpret_cast<JPH::MassProperties *>(massProperties)->Translate(ToCpp(translation));
}

void JPH_MassProperties_Scale(JPH_MassProperties *massProperties, JPH_Vec3 scale) {
    reinterpret_cast<JPH::MassProperties *>(massProperties)->Scale(ToCpp(scale));
}

// Shape

void JPH_Shape_AddRef(JPH_Shape *shape) {
    ToCpp(shape)->AddRef();
}

void JPH_Shape_Release(JPH_Shape *shape) {
    ToCpp(shape)->Release();
}

uint32_t JPH_Shape_GetRefCount(const JPH_Shape *shape) {
    return ToCpp(shape)->GetRefCount();
}

JPH_EShapeType JPH_Shape_GetType(const JPH_Shape *shape) {
    return static_cast<JPH_EShapeType>(ToCpp(shape)->GetType());
}

JPH_EShapeSubType JPH_Shape_GetSubType(const JPH_Shape *shape) {
    return static_cast<JPH_EShapeSubType>(ToCpp(shape)->GetSubType());
}

uint64_t JPH_Shape_GetUserData(const JPH_Shape *shape) {
    return ToCpp(shape)->GetUserData();
}

void JPH_Shape_SetUserData(JPH_Shape *shape, uint64_t userData) {
    ToCpp(shape)->SetUserData(userData);
}

bool JPH_Shape_MustBeStatic(const JPH_Shape *shape) {
    return ToCpp(shape)->MustBeStatic();
}

JPH_Vec3 JPH_Shape_GetCenterOfMass(const JPH_Shape *shape) {
    return ToC(ToCpp(shape)->GetCenterOfMass());
}

JPH_AABox JPH_Shape_GetLocalBounds(const JPH_Shape *shape) {
    return ToC(ToCpp(shape)->GetLocalBounds());
}

uint32_t JPH_Shape_GetSubShapeIDBitsRecursive(const JPH_Shape *shape) {
    return ToCpp(shape)->GetSubShapeIDBitsRecursive();
}

JPH_AABox JPH_Shape_GetWorldSpaceBounds(const JPH_Shape *shape, JPH_Mat44 centerOfMassTransform, JPH_Vec3 scale) {
    return ToC(ToCpp(shape)->GetWorldSpaceBounds(ToCpp(centerOfMassTransform), ToCpp(scale)));
}

float JPH_Shape_GetInnerRadius(const JPH_Shape *shape) {
    return ToCpp(shape)->GetInnerRadius();
}

JPH_MassProperties JPH_Shape_GetMassProperties(const JPH_Shape *shape) {
    return ToC(ToCpp(shape)->GetMassProperties());
}

const JPH_Shape *JPH_Shape_GetLeafShape(const JPH_Shape *shape, JPH_SubShapeID subShapeID, JPH_SubShapeID *outRemainder) {
    JPH::SubShapeID remainder;
    const JPH::Shape *result = ToCpp(shape)->GetLeafShape(*reinterpret_cast<JPH::SubShapeID *>(&subShapeID), remainder);
    *outRemainder = *reinterpret_cast<JPH_SubShapeID *>(&remainder);
    return ToC(result);
}

const JPH_PhysicsMaterial *JPH_Shape_GetMaterial(const JPH_Shape *shape, JPH_SubShapeID subShapeID) {
    return ToC(ToCpp(shape)->GetMaterial(*reinterpret_cast<JPH::SubShapeID *>(&subShapeID)));
}

JPH_Vec3 JPH_Shape_GetSurfaceNormal(const JPH_Shape *shape, JPH_SubShapeID subShapeID, JPH_Vec3 localSurfacePosition) {
    return ToC(ToCpp(shape)->GetSurfaceNormal(*reinterpret_cast<JPH::SubShapeID *>(&subShapeID), ToCpp(localSurfacePosition)));
}

void JPH_Shape_GetSupportingFace(const JPH_Shape *shape, JPH_SubShapeID subShapeID, JPH_Vec3 direction, JPH_Vec3 scale, JPH_Mat44 centerOfMassTransform, JPH_Shape_SupportingFace *outVertices) {
    ToCpp(shape)->GetSupportingFace(*reinterpret_cast<JPH::SubShapeID *>(&subShapeID), ToCpp(direction), ToCpp(scale), ToCpp(centerOfMassTransform), *reinterpret_cast<JPH::Shape::SupportingFace *>(outVertices));
}

uint64_t JPH_Shape_GetSubShapeUserData(const JPH_Shape *shape, JPH_SubShapeID subShapeID) {
    return ToCpp(shape)->GetSubShapeUserData(*reinterpret_cast<JPH::SubShapeID *>(&subShapeID));
}

void JPH_Shape_GetSubmergedVolume(const JPH_Shape *shape, JPH_Mat44 centerOfMassTransform, JPH_Vec3 scale, JPH_Plane surface, float *outTotalVolume, float *outSubmergedVolume, JPH_Vec3 *outCenterOfBuoyancy) {
#ifdef JOLTC_DEBUG_RENDERER
    ToCpp(shape)->GetSubmergedVolume(ToCpp(centerOfMassTransform), ToCpp(scale), ToCpp(surface), *outTotalVolume, *outSubmergedVolume, *reinterpret_cast<JPH::Vec3 *>(outCenterOfBuoyancy), JPH::RVec3(JPH::Vec3::sZero()));
#else
    ToCpp(shape)->GetSubmergedVolume(ToCpp(centerOfMassTransform), ToCpp(scale), ToCpp(surface), *outTotalVolume, *outSubmergedVolume, *reinterpret_cast<JPH::Vec3 *>(outCenterOfBuoyancy));
#endif
}

void JPH_Shape_GetTrianglesStart(const JPH_Shape *shape, JPH_Shape_GetTrianglesContext *ioContext, JPH_AABox box, JPH_Vec3 positionCOM, JPH_Quat rotation, JPH_Vec3 scale) {
    ToCpp(shape)->GetTrianglesStart(*reinterpret_cast<JPH::Shape::GetTrianglesContext *>(ioContext), ToCpp(box), ToCpp(positionCOM), ToCpp(rotation), ToCpp(scale));
}

uint32_t JPH_Shape_GetTrianglesNext(const JPH_Shape *shape, JPH_Shape_GetTrianglesContext *ioContext, uint32_t maxTrianglesRequested, JPH_Float3 *outTriangleVertices, const JPH_PhysicsMaterial **outMaterials) {
    return static_cast<uint32_t>(ToCpp(shape)->GetTrianglesNext(*reinterpret_cast<JPH::Shape::GetTrianglesContext *>(ioContext), static_cast<int>(maxTrianglesRequested), reinterpret_cast<JPH::Float3 *>(outTriangleVertices), reinterpret_cast<const JPH::PhysicsMaterial **>(outMaterials)));
}

JPH_Shape_Stats JPH_Shape_GetStats(const JPH_Shape *shape) {
    auto stats = ToCpp(shape)->GetStats();
    return *reinterpret_cast<JPH_Shape_Stats *>(&stats);
}

float JPH_Shape_GetVolume(const JPH_Shape *shape) {
    return ToCpp(shape)->GetVolume();
}

bool JPH_Shape_IsValidScale(const JPH_Shape *shape, JPH_Vec3 scale) {
    return ToCpp(shape)->IsValidScale(ToCpp(scale));
}

JPH_Vec3 JPH_Shape_MakeScaleValid(const JPH_Shape *shape, JPH_Vec3 scale) {
    return ToC(ToCpp(shape)->MakeScaleValid(ToCpp(scale)));
}

JPH_Shape *JPH_Shape_ScaleShape(const JPH_Shape *shape, JPH_Vec3 scale) {
    auto result = ToCpp(shape)->ScaleShape(ToCpp(scale));
    if (!result.IsValid()) {
        return nullptr;
    }

    auto scaledShape = result.Get().GetPtr();
    scaledShape->AddRef();

    return ToC(scaledShape);
}

// ConvexShape

void JPH_ConvexShape_SetMaterial(JPH_ConvexShape *shape, const JPH_PhysicsMaterial *material) {
    ToCpp(shape)->SetMaterial(ToCpp(material));
}

const JPH_PhysicsMaterial *JPH_ConvexShape_GetMaterial(const JPH_ConvexShape *shape) {
    return ToC(ToCpp(shape)->GetMaterial());
}

void JPH_ConvexShape_SetDensity(JPH_ConvexShape *shape, float density) {
    ToCpp(shape)->SetDensity(density);
}

float JPH_ConvexShape_GetDensity(const JPH_ConvexShape *shape) {
    return ToCpp(shape)->GetDensity();
}

// SphereShape

float JPH_SphereShape_GetRadius(const JPH_SphereShape *shape) {
    return ToCpp(shape)->GetRadius();
}

// BoxShape

JPH_Vec3 JPH_BoxShape_GetHalfExtent(const JPH_BoxShape *shape) {
    return ToC(ToCpp(shape)->GetHalfExtent());
}

float JPH_BoxShape_GetConvexRadius(const JPH_BoxShape *shape) {
    return ToCpp(shape)->GetConvexRadius();
}

// PlaneShape

JPH_Plane JPH_PlaneShape_GetPlane(const JPH_PlaneShape *shape) {
    return ToC(ToCpp(shape)->GetPlane());
}

float JPH_PlaneShape_GetHalfExtent(const JPH_PlaneShape *shape) {
    return ToCpp(shape)->GetHalfExtent();
}

void JPH_PlaneShape_SetMaterial(JPH_PlaneShape *shape, const JPH_PhysicsMaterial *material) {
    ToCpp(shape)->SetMaterial(ToCpp(material));
}

const JPH_PhysicsMaterial *JPH_PlaneShape_GetMaterial(const JPH_PlaneShape *shape) {
    return ToC(ToCpp(shape)->GetMaterial());
}

// TriangleShape

JPH_Vec3 JPH_TriangleShape_GetVertex1(const JPH_TriangleShape *shape) {
    return ToC(ToCpp(shape)->GetVertex1());
}

JPH_Vec3 JPH_TriangleShape_GetVertex2(const JPH_TriangleShape *shape) {
    return ToC(ToCpp(shape)->GetVertex2());
}

JPH_Vec3 JPH_TriangleShape_GetVertex3(const JPH_TriangleShape *shape) {
    return ToC(ToCpp(shape)->GetVertex3());
}

void JPH_TriangleShape_GetVertices(const JPH_TriangleShape *shape, JPH_Vec3 *outV1, JPH_Vec3 *outV2, JPH_Vec3 *outV3) {
    *outV1 = ToC(ToCpp(shape)->GetVertex1());
    *outV2 = ToC(ToCpp(shape)->GetVertex2());
    *outV3 = ToC(ToCpp(shape)->GetVertex3());
}

float JPH_TriangleShape_GetConvexRadius(const JPH_TriangleShape *shape) {
    return ToCpp(shape)->GetConvexRadius();
}

// CapsuleShape

float JPH_CapsuleShape_GetRadius(const JPH_CapsuleShape *shape) {
    return ToCpp(shape)->GetRadius();
}

float JPH_CapsuleShape_GetHalfHeightOfCylinder(const JPH_CapsuleShape *shape) {
    return ToCpp(shape)->GetHalfHeightOfCylinder();
}

// TaperedCapsuleShape

float JPH_TaperedCapsuleShape_GetTopRadius(const JPH_TaperedCapsuleShape *shape) {
    return ToCpp(shape)->GetTopRadius();
}

float JPH_TaperedCapsuleShape_GetBottomRadius(const JPH_TaperedCapsuleShape *shape) {
    return ToCpp(shape)->GetBottomRadius();
}

float JPH_TaperedCapsuleShape_GetHalfHeight(const JPH_TaperedCapsuleShape *shape) {
    return ToCpp(shape)->GetHalfHeight();
}

// CylinderShape

float JPH_CylinderShape_GetHalfHeight(const JPH_CylinderShape *shape) {
    return ToCpp(shape)->GetHalfHeight();
}

float JPH_CylinderShape_GetRadius(const JPH_CylinderShape *shape) {
    return ToCpp(shape)->GetRadius();
}

float JPH_CylinderShape_GetConvexRadius(const JPH_CylinderShape *shape) {
    return ToCpp(shape)->GetConvexRadius();
}

// TaperedCylinderShape

float JPH_TaperedCylinderShape_GetTopRadius(const JPH_TaperedCylinderShape *shape) {
    return ToCpp(shape)->GetTopRadius();
}

float JPH_TaperedCylinderShape_GetBottomRadius(const JPH_TaperedCylinderShape *shape) {
    return ToCpp(shape)->GetBottomRadius();
}

float JPH_TaperedCylinderShape_GetConvexRadius(const JPH_TaperedCylinderShape *shape) {
    return ToCpp(shape)->GetConvexRadius();
}

float JPH_TaperedCylinderShape_GetHalfHeight(const JPH_TaperedCylinderShape *shape) {
    return ToCpp(shape)->GetHalfHeight();
}

// ConvexHullShape

float JPH_ConvexHullShape_GetConvexRadius(const JPH_ConvexHullShape *shape) {
    return ToCpp(shape)->GetConvexRadius();
}

uint32_t JPH_ConvexHullShape_GetNumPoints(const JPH_ConvexHullShape *shape) {
    return static_cast<uint32_t>(ToCpp(shape)->GetNumPoints());
}

JPH_Vec3 JPH_ConvexHullShape_GetPoint(const JPH_ConvexHullShape *shape, uint32_t index) {
    return ToC(ToCpp(shape)->GetPoint(index));
}

uint32_t JPH_ConvexHullShape_GetNumFaces(const JPH_ConvexHullShape *shape) {
    return static_cast<uint32_t>(ToCpp(shape)->GetNumFaces());
}

uint32_t JPH_ConvexHullShape_GetNumVerticesInFace(const JPH_ConvexHullShape *shape, uint32_t faceIndex) {
    return static_cast<uint32_t>(ToCpp(shape)->GetNumVerticesInFace(faceIndex));
}

uint32_t JPH_ConvexHullShape_GetFaceVertices(const JPH_ConvexHullShape *shape, uint32_t faceIndex, uint32_t maxVertices, uint32_t *outVertices) {
    return static_cast<uint32_t>(ToCpp(shape)->GetFaceVertices(faceIndex, maxVertices, outVertices));
}

uint32_t JPH_ConvexHullShape_GetNumPlanes(const JPH_ConvexHullShape *shape) {
    return static_cast<uint32_t>(ToCpp(shape)->GetPlanes().size());
}

const JPH_Plane *JPH_ConvexHullShape_GetPlanes(const JPH_ConvexHullShape *shape) {
    return reinterpret_cast<const JPH_Plane *>(ToCpp(shape)->GetPlanes().data());
}

// DecoratedShape

const JPH_Shape *JPH_DecoratedShape_GetInnerShape(const JPH_DecoratedShape *shape) {
    return ToC(ToCpp(shape)->GetInnerShape());
}

// RotatedTranslatedShape

JPH_Quat JPH_RotatedTranslatedShape_GetRotation(const JPH_RotatedTranslatedShape *shape) {
    return ToC(ToCpp(shape)->GetRotation());
}

JPH_Vec3 JPH_RotatedTranslatedShape_GetPosition(const JPH_RotatedTranslatedShape *shape) {
    return ToC(ToCpp(shape)->GetPosition());
}

JPH_Vec3 JPH_RotatedTranslatedShape_TransformScale(const JPH_RotatedTranslatedShape *shape, JPH_Vec3 scale) {
    return ToC(ToCpp(shape)->TransformScale(ToCpp(scale)));
}

// ScaledShape

JPH_Vec3 JPH_ScaledShape_GetScale(const JPH_ScaledShape *shape) {
    return ToC(ToCpp(shape)->GetScale());
}

// OffsetCenterOfMassShape

JPH_Vec3 JPH_OffsetCenterOfMassShape_GetOffset(const JPH_OffsetCenterOfMassShape *shape) {
    return ToC(ToCpp(shape)->GetOffset());
}

// CompoundShape

uint32_t JPH_CompoundShape_GetNumSubShapes(const JPH_CompoundShape *shape) {
    return static_cast<uint32_t>(ToCpp(shape)->GetNumSubShapes());
}

uint32_t JPH_CompoundShape_GetCompoundUserData(const JPH_CompoundShape *shape, uint32_t index) {
    return ToCpp(shape)->GetCompoundUserData(index);
}

void JPH_CompoundShape_SetCompoundUserData(JPH_CompoundShape *shape, uint32_t index, uint32_t userData) {
    ToCpp(shape)->SetCompoundUserData(index, userData);
}

bool JPH_CompoundShape_IsSubShapeIDValid(const JPH_CompoundShape *shape, JPH_SubShapeID subShapeID) {
    return ToCpp(shape)->IsSubShapeIDValid(*reinterpret_cast<const JPH::SubShapeID *>(&subShapeID));
}

uint32_t JPH_CompoundShape_GetSubShapeIndexFromID(const JPH_CompoundShape *shape, JPH_SubShapeID subShapeID, JPH_SubShapeID *outRemainder) {
    JPH::SubShapeID remainder;
    uint32_t result = ToCpp(shape)->GetSubShapeIndexFromID(*reinterpret_cast<const JPH::SubShapeID *>(&subShapeID), remainder);
    *outRemainder = *reinterpret_cast<JPH_SubShapeID *>(&remainder);
    return result;
}

// MutableCompoundShape

uint32_t JPH_MutableCompoundShape_AddShape(JPH_MutableCompoundShape *shape, JPH_Vec3 position, JPH_Quat rotation, const JPH_Shape *inShape, uint32_t userData, uint32_t index) {
    return static_cast<uint32_t>(ToCpp(shape)->AddShape(ToCpp(position), ToCpp(rotation), ToCpp(inShape), userData, index));
}

void JPH_MutableCompoundShape_RemoveShape(JPH_MutableCompoundShape *shape, uint32_t index) {
    ToCpp(shape)->RemoveShape(index);
}

void JPH_MutableCompoundShape_ModifyShape(JPH_MutableCompoundShape *shape, uint32_t index, JPH_Vec3 position, JPH_Quat rotation) {
    ToCpp(shape)->ModifyShape(index, ToCpp(position), ToCpp(rotation));
}

void JPH_MutableCompoundShape_ModifyShapeWithShape(JPH_MutableCompoundShape *shape, uint32_t index, JPH_Vec3 position, JPH_Quat rotation, const JPH_Shape *inShape) {
    ToCpp(shape)->ModifyShape(index, ToCpp(position), ToCpp(rotation), ToCpp(inShape));
}

void JPH_MutableCompoundShape_ModifyShapes(JPH_MutableCompoundShape *shape, uint32_t startIndex, uint32_t number, const JPH_Vec3 *positions, const JPH_Quat *rotations, uint32_t positionStride, uint32_t rotationStride) {
    ToCpp(shape)->ModifyShapes(startIndex, number, reinterpret_cast<const JPH::Vec3 *>(positions), reinterpret_cast<const JPH::Quat *>(rotations), positionStride, rotationStride);
}

void JPH_MutableCompoundShape_AdjustCenterOfMass(JPH_MutableCompoundShape *shape) {
    ToCpp(shape)->AdjustCenterOfMass();
}

// MeshShape

uint32_t JPH_MeshShape_GetMaterialIndex(const JPH_MeshShape *shape, JPH_SubShapeID subShapeID) {
    return ToCpp(shape)->GetMaterialIndex(*reinterpret_cast<const JPH::SubShapeID *>(&subShapeID));
}

uint32_t JPH_MeshShape_GetTriangleUserData(const JPH_MeshShape *shape, JPH_SubShapeID subShapeID) {
    return ToCpp(shape)->GetTriangleUserData(*reinterpret_cast<const JPH::SubShapeID *>(&subShapeID));
}

// HeightFieldShape

uint32_t JPH_HeightFieldShape_GetSampleCount(const JPH_HeightFieldShape *shape) {
    return ToCpp(shape)->GetSampleCount();
}

uint32_t JPH_HeightFieldShape_GetBlockSize(const JPH_HeightFieldShape *shape) {
    return ToCpp(shape)->GetBlockSize();
}

const JPH_PhysicsMaterial *JPH_HeightFieldShape_GetMaterial(const JPH_HeightFieldShape *shape, uint32_t x, uint32_t y) {
    return ToC(ToCpp(shape)->GetMaterial(x, y));
}

JPH_Vec3 JPH_HeightFieldShape_GetPosition(const JPH_HeightFieldShape *shape, uint32_t x, uint32_t y) {
    return ToC(ToCpp(shape)->GetPosition(x, y));
}

bool JPH_HeightFieldShape_IsNoCollision(const JPH_HeightFieldShape *shape, uint32_t x, uint32_t y) {
    return ToCpp(shape)->IsNoCollision(x, y);
}

bool JPH_HeightFieldShape_ProjectOntoSurface(const JPH_HeightFieldShape *shape, JPH_Vec3 localPosition, JPH_Vec3 *outSurfacePosition, JPH_SubShapeID *outSubShapeID) {
    JPH::Vec3 surfacePosition;
    JPH::SubShapeID subShapeID;
    bool result = ToCpp(shape)->ProjectOntoSurface(ToCpp(localPosition), surfacePosition, subShapeID);
    *outSurfacePosition = ToC(surfacePosition);
    *outSubShapeID = *reinterpret_cast<JPH_SubShapeID *>(&subShapeID);
    return result;
}

void JPH_HeightFieldShape_GetSubShapeCoordinates(const JPH_HeightFieldShape *shape, JPH_SubShapeID subShapeID, uint32_t *outX, uint32_t *outY, uint32_t *outTriangleIndex) {
    ToCpp(shape)->GetSubShapeCoordinates(*reinterpret_cast<const JPH::SubShapeID *>(&subShapeID), *outX, *outY, *outTriangleIndex);
}

float JPH_HeightFieldShape_GetMinHeightValue(const JPH_HeightFieldShape *shape) {
    return ToCpp(shape)->GetMinHeightValue();
}

float JPH_HeightFieldShape_GetMaxHeightValue(const JPH_HeightFieldShape *shape) {
    return ToCpp(shape)->GetMaxHeightValue();
}

void JPH_HeightFieldShape_GetHeights(const JPH_HeightFieldShape *shape, uint32_t x, uint32_t y, uint32_t sizeX, uint32_t sizeY, float *outHeights, intptr_t heightsStride) {
    ToCpp(shape)->GetHeights(x, y, sizeX, sizeY, outHeights, heightsStride);
}

void JPH_HeightFieldShape_SetHeights(JPH_HeightFieldShape *shape, uint32_t x, uint32_t y, uint32_t sizeX, uint32_t sizeY, const float *inHeights, intptr_t heightsStride, JPH_TempAllocator *allocator, float activeEdgeCosThresholdAngle) {
    ToCpp(shape)->SetHeights(x, y, sizeX, sizeY, inHeights, heightsStride, *ToCpp(allocator), activeEdgeCosThresholdAngle);
}

JOLTC_POP_WARNINGS()
