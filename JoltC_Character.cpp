#include <JoltC.hpp>

static inline
JPH::CharacterSettings ToCpp(const JPH_CharacterSettings &settings) {
    JPH::CharacterSettings result;
    result.mUp = ToCpp(settings.up);
    result.mSupportingVolume = ToCpp(settings.supportingVolume);
    result.mMaxSlopeAngle = settings.maxSlopeAngle;
    result.mEnhancedInternalEdgeRemoval = settings.enhancedInternalEdgeRemoval;
    result.mShape = ToCpp(settings.shape);
    result.mLayer = settings.layer;
    result.mMass = settings.mass;
    result.mFriction = settings.friction;
    result.mGravityFactor = settings.gravityFactor;
    result.mAllowedDOFs = static_cast<JPH::EAllowedDOFs>(settings.allowedDOFs);

    return result;
}

static inline
JPH_CharacterSettings ToC(const JPH::CharacterSettings &settings) {
    JPH_CharacterSettings result;
    result.up = ToC(settings.mUp);
    result.supportingVolume = ToC(settings.mSupportingVolume);
    result.maxSlopeAngle = settings.mMaxSlopeAngle;
    result.enhancedInternalEdgeRemoval = settings.mEnhancedInternalEdgeRemoval;
    result.shape = ToC(settings.mShape);
    result.layer = settings.mLayer;
    result.mass = settings.mMass;
    result.friction = settings.mFriction;
    result.gravityFactor = settings.mGravityFactor;
    result.allowedDOFs = static_cast<JPH_EAllowedDOFs>(settings.mAllowedDOFs);

    return result;
}

// CharacterBase

void JPH_CharacterBase_Destroy(JPH_CharacterBase *character) {
    delete ToCpp(character);
}

void JPH_CharacterBase_Release(JPH_CharacterBase *character) {
    ToCpp(character)->Release();
}

void JPH_CharacterBase_SetMaxSlopeAngle(JPH_CharacterBase *character, float maxSlopeAngle) {
    ToCpp(character)->SetMaxSlopeAngle(maxSlopeAngle);
}

float JPH_CharacterBase_GetCosMaxSlopeAngle(const JPH_CharacterBase *character) {
    return ToCpp(character)->GetCosMaxSlopeAngle();
}

void JPH_CharacterBase_SetUp(JPH_CharacterBase *character, JPH_Vec3 up) {
    return ToCpp(character)->SetUp(ToCpp(up));
}

JPH_Vec3 JPH_CharacterBase_GetUp(const JPH_CharacterBase *character) {
    return ToC(ToCpp(character)->GetUp());
}

JPH_Plane JPH_CharacterBase_GetSupportingVolume(const JPH_CharacterBase *character) {
    return ToC(ToCpp(character)->GetSupportingVolume());
}

void JPH_CharacterBase_SetSupportingVolume(JPH_CharacterBase *character, JPH_Plane plane) {
    ToCpp(character)->SetSupportingVolume(ToCpp(plane));
}

bool JPH_CharacterBase_IsSlopeTooSteep(const JPH_CharacterBase *character, JPH_Vec3 normal) {
    return ToCpp(character)->IsSlopeTooSteep(ToCpp(normal));
}

const JPH_Shape *JPH_CharacterBase_GetShape(const JPH_CharacterBase *character) {
    return ToC(ToCpp(character)->GetShape());
}

JPH_ECharacterGroundState JPH_CharacterBase_GetGroundState(const JPH_CharacterBase *character) {
    return static_cast<JPH_ECharacterGroundState>(ToCpp(character)->GetGroundState());
}

bool JPH_CharacterBase_IsSupported(const JPH_CharacterBase *character) {
    return ToCpp(character)->IsSupported();
}

JPH_RVec3 JPH_CharacterBase_GetGroundPosition(const JPH_CharacterBase *character) {
    return ToC(ToCpp(character)->GetGroundPosition());
}

JPH_Vec3 JPH_CharacterBase_GetGroundNormal(const JPH_CharacterBase *character) {
    return ToC(ToCpp(character)->GetGroundNormal());
}

JPH_Vec3 JPH_CharacterBase_GetGroundVelocity(const JPH_CharacterBase *character) {
    return ToC(ToCpp(character)->GetGroundVelocity());
}

const JPH_PhysicsMaterial *JPH_CharacterBase_GetGroundMaterial(const JPH_CharacterBase *character) {
    return ToC(ToCpp(character)->GetGroundMaterial());
}

JPH_BodyID JPH_CharacterBase_GetGroundBodyID(const JPH_CharacterBase *character) {
    return ToCpp(character)->GetGroundBodyID().GetIndexAndSequenceNumber();
}

JPH_SubShapeID JPH_CharacterBase_GetGroundSubShapeID(const JPH_CharacterBase *character) {
    return ToCpp(character)->GetGroundSubShapeID().GetValue();
}

uint64_t JPH_CharacterBase_GetGroundUserData(const JPH_CharacterBase *character) {
    return ToCpp(character)->GetGroundUserData();
}

// Character

JPH_Character *JPH_Character_Create(const JPH_CharacterSettings *settings, JPH_RVec3 position, JPH_Quat rotation, uint64_t userData, JPH_PhysicsSystem *system) {
    auto cppSettings = ToCpp(*settings);
    return ToC(new JPH::Character(&cppSettings, ToCpp(position), ToCpp(rotation), userData, ToCpp(system)));
}

void JPH_Character_AddToPhysicsSystem(JPH_Character *character, JPH_EActivation activationMode, bool lockBodies) {
    ToCpp(character)->AddToPhysicsSystem(static_cast<JPH::EActivation>(activationMode), lockBodies);
}

void JPH_Character_RemoveFromPhysicsSystem(JPH_Character *character, bool lockBodies) {
    ToCpp(character)->RemoveFromPhysicsSystem(lockBodies);
}

void JPH_Character_Activate(JPH_Character *character, bool lockBodies) {
    ToCpp(character)->Activate(lockBodies);
}

void JPH_Character_PostSimulation(JPH_Character *character, float maxSeparationDistance, bool lockBodies) {
    ToCpp(character)->PostSimulation(maxSeparationDistance, lockBodies);
}

void JPH_Character_SetLinearAndAngularVelocity(JPH_Character *character, JPH_Vec3 linearVelocity, JPH_Vec3 angularVelocity, bool lockBodies) {
    ToCpp(character)->SetLinearAndAngularVelocity(ToCpp(linearVelocity), ToCpp(angularVelocity), lockBodies);
}

JPH_Vec3 JPH_Character_GetLinearVelocity(const JPH_Character *character, bool lockBodies) {
    return ToC(ToCpp(character)->GetLinearVelocity(lockBodies));
}

void JPH_Character_SetLinearVelocity(JPH_Character *character, JPH_Vec3 linearVelocity, bool lockBodies) {
    ToCpp(character)->SetLinearVelocity(ToCpp(linearVelocity), lockBodies);
}

void JPH_Character_AddLinearVelocity(JPH_Character *character, JPH_Vec3 linearVelocity, bool lockBodies) {
    ToCpp(character)->AddLinearVelocity(ToCpp(linearVelocity), lockBodies);
}

void JPH_Character_AddImpulse(JPH_Character *character, JPH_Vec3 impulse, bool lockBodies) {
    ToCpp(character)->AddImpulse(ToCpp(impulse), lockBodies);
}

JPH_BodyID JPH_Character_GetBodyID(const JPH_Character *character) {
    return ToCpp(character)->GetBodyID().GetIndexAndSequenceNumber();
}

void JPH_Character_GetPositionAndRotation(const JPH_Character *character, JPH_RVec3 *outPosition, JPH_Quat *outRotation, bool lockBodies) {
    ToCpp(character)->GetPositionAndRotation(*ToCpp(outPosition), *ToCpp(outRotation), lockBodies);
}

void JPH_Character_SetPositionAndRotation(const JPH_Character *character, JPH_RVec3 position, JPH_Quat rotation, JPH_EActivation activationMode, bool lockBodies) {
    ToCpp(character)->SetPositionAndRotation(ToCpp(position), ToCpp(rotation), static_cast<JPH::EActivation>(activationMode), lockBodies);
}

JPH_RVec3 JPH_Character_GetPosition(const JPH_Character *character, bool lockBodies) {
    return ToC(ToCpp(character)->GetPosition(lockBodies));
}

void JPH_Character_SetPosition(JPH_Character *character, JPH_RVec3 position, JPH_EActivation activationMode, bool lockBodies) {
    ToCpp(character)->SetPosition(ToCpp(position), static_cast<JPH::EActivation>(activationMode), lockBodies);
}

JPH_Quat JPH_Character_GetRotation(const JPH_Character *character, bool lockBodies) {
    return ToC(ToCpp(character)->GetRotation(lockBodies));
}

void JPH_Character_SetRotation(JPH_Character *character, JPH_Quat rotation, JPH_EActivation activationMode, bool lockBodies) {
    ToCpp(character)->SetRotation(ToCpp(rotation), static_cast<JPH::EActivation>(activationMode), lockBodies);
}

JPH_RVec3 JPH_Character_GetCenterOfMassPosition(const JPH_Character *character, bool lockBodies) {
    return ToC(ToCpp(character)->GetCenterOfMassPosition(lockBodies));
}

JPH_RMat44 JPH_Character_GetWorldTransform(const JPH_Character *character, bool lockBodies) {
    return ToC(ToCpp(character)->GetWorldTransform(lockBodies));
}

JPH_ObjectLayer JPH_Character_GetLayer(const JPH_Character *character) {
    return ToCpp(character)->GetLayer();
}

void JPH_Character_SetLayer(JPH_Character *character, JPH_ObjectLayer layer, bool lockBodies) {
    ToCpp(character)->SetLayer(layer, lockBodies);
}

bool JPH_Character_SetShape(JPH_Character *character, const JPH_Shape *shape, float maxPenetrationDepth, bool lockBodies) {
    return ToCpp(character)->SetShape(ToCpp(shape), maxPenetrationDepth, lockBodies);
}

JPH_TransformedShape JPH_Character_GetTransformedShape(const JPH_Character *character, bool lockBodies) {
    return ToC(ToCpp(character)->GetTransformedShape(lockBodies));
}

void JPH_Character_CheckCollision(const JPH_Character *character, JPH_RVec3 position, JPH_Quat rotation, JPH_Vec3 movementDirection, float maxSeparationDistance, const JPH_Shape *shape, JPH_RVec3 baseOffset, JPH_CollideShapeCollector *collector, bool lockBodies) {
    ToCpp(character)->CheckCollision(ToCpp(position), ToCpp(rotation), ToCpp(movementDirection), maxSeparationDistance, ToCpp(shape), ToCpp(baseOffset), *ToCpp(collector), lockBodies);
}

JPH_CharacterSettings JPH_Character_GetCharacterSettings(const JPH_Character *character, bool lockBodies) {
    return ToC(ToCpp(character)->GetCharacterSettings(lockBodies));
}
