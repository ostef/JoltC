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

static inline
JPH::CharacterVirtualSettings ToCpp(const JPH_CharacterVirtualSettings &settings) {
    JPH::CharacterVirtualSettings result;
    result.mUp = ToCpp(settings.up);
    result.mSupportingVolume = ToCpp(settings.supportingVolume);
    result.mMaxSlopeAngle = settings.maxSlopeAngle;
    result.mEnhancedInternalEdgeRemoval = settings.enhancedInternalEdgeRemoval;
    result.mShape = ToCpp(settings.shape);
    result.mID = JPH::CharacterID(settings.id);
    result.mMass = settings.mass;
    result.mMaxStrength = settings.maxStrength;
    result.mShapeOffset = ToCpp(settings.shapeOffset);
    result.mBackFaceMode = static_cast<JPH::EBackFaceMode>(settings.backFaceMode);
    result.mPredictiveContactDistance = settings.predictiveContactDistance;
    result.mMaxCollisionIterations = settings.maxCollisionIterations;
    result.mMaxConstraintIterations = settings.maxConstraintIterations;
    result.mMinTimeRemaining = settings.minTimeRemaining;
    result.mCollisionTolerance = settings.collisionTolerance;
    result.mCharacterPadding = settings.characterPadding;
    result.mMaxNumHits = settings.maxNumHits;
    result.mHitReductionCosMaxAngle = settings.hitReductionCosMaxAngle;
    result.mPenetrationRecoverySpeed = settings.penetrationRecoverySpeed;
    result.mInnerBodyShape = ToCpp(settings.innerBodyShape);
    result.mInnerBodyIDOverride = JPH::BodyID(settings.innerBodyIDOverride);
    result.mInnerBodyLayer = settings.innerBodyLayer;

    return result;
}

static inline
JPH_CharacterVirtualSettings ToC(const JPH::CharacterVirtualSettings &settings) {
    JPH_CharacterVirtualSettings result;
    result.up = ToC(settings.mUp);
    result.supportingVolume = ToC(settings.mSupportingVolume);
    result.maxSlopeAngle = settings.mMaxSlopeAngle;
    result.enhancedInternalEdgeRemoval = settings.mEnhancedInternalEdgeRemoval;
    result.shape = ToC(settings.mShape);
    result.id = settings.mID.GetValue();
    result.mass = settings.mMass;
    result.maxStrength = settings.mMaxStrength;
    result.shapeOffset = ToC(settings.mShapeOffset);
    result.backFaceMode = static_cast<JPH_EBackFaceMode>(settings.mBackFaceMode);
    result.predictiveContactDistance = settings.mPredictiveContactDistance;
    result.maxCollisionIterations = settings.mMaxCollisionIterations;
    result.maxConstraintIterations = settings.mMaxConstraintIterations;
    result.minTimeRemaining = settings.mMinTimeRemaining;
    result.collisionTolerance = settings.mCollisionTolerance;
    result.characterPadding = settings.mCharacterPadding;
    result.maxNumHits = settings.mMaxNumHits;
    result.hitReductionCosMaxAngle = settings.mHitReductionCosMaxAngle;
    result.penetrationRecoverySpeed = settings.mPenetrationRecoverySpeed;
    result.innerBodyShape = ToC(settings.mInnerBodyShape);
    result.innerBodyIDOverride = settings.mInnerBodyIDOverride.GetIndexAndSequenceNumber();
    result.innerBodyLayer = settings.mInnerBodyLayer;

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

// CharacterContactListener

BEGIN_INTERFACE_WRAPPER_CLASS(CharacterContactListener);

    virtual void OnAdjustBodyVelocity(const JPH::CharacterVirtual *inCharacter, const JPH::Body &inBody2, JPH::Vec3 &ioLinearVelocity, JPH::Vec3 &ioAngularVelocity) override {
        if (funcs.OnAdjustBodyVelocity) {
            funcs.OnAdjustBodyVelocity(data, ToC(inCharacter), &ToC(inBody2), &ToC(ioLinearVelocity), &ToC(ioAngularVelocity));
        }
    }

    virtual bool OnContactValidate(const JPH::CharacterVirtual *inCharacter, const JPH::CharacterContact &inContact) override {
        if (funcs.OnContactValidate) {
            return funcs.OnContactValidate(data, ToC(inCharacter), &ToC(inContact));
        }

        return true;
    }

    virtual void OnContactAdded(const JPH::CharacterVirtual *inCharacter, const JPH::CharacterContact &inContact, JPH::CharacterContactSettings &ioSettings) override {
        if (funcs.OnContactAdded) {
            funcs.OnContactAdded(data, ToC(inCharacter), &ToC(inContact), &ToC(ioSettings));
        }
    }

    virtual void OnContactPersisted(const JPH::CharacterVirtual *inCharacter, const JPH::CharacterContact &inContact, JPH::CharacterContactSettings &ioSettings) override {
        if (funcs.OnContactPersisted) {
            funcs.OnContactPersisted(data, ToC(inCharacter), &ToC(inContact), &ToC(ioSettings));
        }
    }

    virtual void OnContactRemoved(const JPH::CharacterVirtual *inCharacter, const JPH::BodyID &inBodyID2, const JPH::SubShapeID &inSubShapeID2) override {
        if (funcs.OnContactRemoved) {
            funcs.OnContactRemoved(data, ToC(inCharacter), inBodyID2.GetIndexAndSequenceNumber(), inSubShapeID2.GetValue());
        }
    }

    virtual bool OnCharacterContactValidate(const JPH::CharacterVirtual *inCharacter, const JPH::CharacterContact &inContact) override {
        if (funcs.OnCharacterContactValidate) {
            return funcs.OnCharacterContactValidate(data, ToC(inCharacter), &ToC(inContact));
        }
        return true;
    }

    virtual void OnCharacterContactAdded(const JPH::CharacterVirtual *inCharacter, const JPH::CharacterContact &inContact, JPH::CharacterContactSettings &ioSettings) override {
        if (funcs.OnCharacterContactAdded) {
            funcs.OnCharacterContactAdded(data, ToC(inCharacter), &ToC(inContact), &ToC(ioSettings));
        }
    }

    virtual void OnCharacterContactPersisted(const JPH::CharacterVirtual *inCharacter, const JPH::CharacterContact &inContact, JPH::CharacterContactSettings &ioSettings) override {
        if (funcs.OnCharacterContactPersisted) {
            funcs.OnCharacterContactPersisted(data, ToC(inCharacter), &ToC(inContact), &ToC(ioSettings));
        }
    }

    virtual void OnCharacterContactRemoved(const JPH::CharacterVirtual *inCharacter, const JPH::CharacterID &inOtherCharacterID, const JPH::SubShapeID &inSubShapeID2) override {
        if (funcs.OnCharacterContactRemoved) {
            funcs.OnCharacterContactRemoved(data, ToC(inCharacter), inOtherCharacterID.GetValue(), inSubShapeID2.GetValue());
        }
    }

    virtual void OnContactSolve(const JPH::CharacterVirtual *inCharacter, const JPH::BodyID &inBodyID2, const JPH::SubShapeID &inSubShapeID2, JPH::RVec3Arg inContactPosition, JPH::Vec3Arg inContactNormal, JPH::Vec3Arg inContactVelocity, const JPH::PhysicsMaterial *inContactMaterial, JPH::Vec3Arg inCharacterVelocity, JPH::Vec3 &ioNewCharacterVelocity) override {
        if (funcs.OnContactSolve) {
            funcs.OnContactSolve(data, ToC(inCharacter), inBodyID2.GetIndexAndSequenceNumber(), inSubShapeID2.GetValue(), ToC(inContactPosition), ToC(inContactNormal), ToC(inContactVelocity), ToC(inContactMaterial), ToC(inCharacterVelocity), &ToC(ioNewCharacterVelocity));
        }
    }

    virtual void OnCharacterContactSolve(const JPH::CharacterVirtual *inCharacter, const JPH::CharacterVirtual *inOtherCharacter, const JPH::SubShapeID &inSubShapeID2, JPH::RVec3Arg inContactPosition, JPH::Vec3Arg inContactNormal, JPH::Vec3Arg inContactVelocity, const JPH::PhysicsMaterial *inContactMaterial, JPH::Vec3Arg inCharacterVelocity, JPH::Vec3 &ioNewCharacterVelocity) override {
        if (funcs.OnCharacterContactSolve) {
            funcs.OnCharacterContactSolve(data, ToC(inCharacter), ToC(inOtherCharacter), inSubShapeID2.GetValue(), ToC(inContactPosition), ToC(inContactNormal), ToC(inContactVelocity), ToC(inContactMaterial), ToC(inCharacterVelocity), &ToC(ioNewCharacterVelocity));
        }
    }

END_INTERFACE_WRAPPER_CLASS();

DEFINE_INTERFACE_WRAPPER_FUNCTIONS(CharacterContactListener);

// CharacterVirtual

JPH_CharacterVirtual *JPH_CharacterVirtual_Create(const JPH_CharacterVirtualSettings *settings, JPH_RVec3 position, JPH_Quat rotation, uint64_t userData, JPH_PhysicsSystem *system) {
    auto cppSettings = ToCpp(*settings);
    return ToC(new JPH::CharacterVirtual(&cppSettings, ToCpp(position), ToCpp(rotation), userData, ToCpp(system)));
}

JPH_CharacterID JPH_CharacterVirtual_GetID(const JPH_CharacterVirtual *character) {
    return ToCpp(character)->GetID().GetValue();
}

void JPH_CharacterVirtual_SetListener(JPH_CharacterVirtual *character, JPH_CharacterContactListener *listener) {
    ToCpp(character)->SetListener(ToCpp(listener));
}

JPH_CharacterContactListener *JPH_CharacterVirtual_GetListener(const JPH_CharacterVirtual *character) {
    return ToC(ToCpp(character)->GetListener());
}

JPH_Vec3 JPH_CharacterVirtual_GetLinearVelocity(const JPH_CharacterVirtual *character) {
    return ToC(ToCpp(character)->GetLinearVelocity());
}

void JPH_CharacterVirtual_SetLinearVelocity(JPH_CharacterVirtual *character, JPH_Vec3 linearVelocity) {
    ToCpp(character)->SetLinearVelocity(ToCpp(linearVelocity));
}

JPH_RVec3 JPH_CharacterVirtual_GetPosition(const JPH_CharacterVirtual *character) {
    return ToC(ToCpp(character)->GetPosition());
}

void JPH_CharacterVirtual_SetPosition(JPH_CharacterVirtual *character, JPH_RVec3 position) {
    ToCpp(character)->SetPosition(ToCpp(position));
}

JPH_Quat JPH_CharacterVirtual_GetRotation(const JPH_CharacterVirtual *character) {
    return ToC(ToCpp(character)->GetRotation());
}

void JPH_CharacterVirtual_SetRotation(JPH_CharacterVirtual *character, JPH_Quat rotation) {
    ToCpp(character)->SetRotation(ToCpp(rotation));
}

JPH_RVec3 JPH_CharacterVirtual_GetCenterOfMassPosition(const JPH_CharacterVirtual *character) {
    return ToC(ToCpp(character)->GetCenterOfMassPosition());
}

JPH_RMat44 JPH_CharacterVirtual_GetWorldTransform(const JPH_CharacterVirtual *character) {
    return ToC(ToCpp(character)->GetWorldTransform());
}

JPH_RMat44 JPH_CharacterVirtual_GetCenterOfMassTransform(const JPH_CharacterVirtual *character) {
    return ToC(ToCpp(character)->GetCenterOfMassTransform());
}

float JPH_CharacterVirtual_GetMass(const JPH_CharacterVirtual *character) {
    return ToCpp(character)->GetMass();
}

void JPH_CharacterVirtual_SetMass(JPH_CharacterVirtual *character, float mass) {
    ToCpp(character)->SetMass(mass);
}

float JPH_CharacterVirtual_GetMaxStrength(const JPH_CharacterVirtual *character) {
    return ToCpp(character)->GetMaxStrength();
}

void JPH_CharacterVirtual_SetMaxStrength(JPH_CharacterVirtual *character, float maxStrength) {
    ToCpp(character)->SetMaxStrength(maxStrength);
}

float JPH_CharacterVirtual_GetPenetrationRecoverySpeed(const JPH_CharacterVirtual *character) {
    return ToCpp(character)->GetPenetrationRecoverySpeed();
}

void JPH_CharacterVirtual_SetPenetrationRecoverySpeed(JPH_CharacterVirtual *character, float speed) {
    ToCpp(character)->SetPenetrationRecoverySpeed(speed);
}

bool JPH_CharacterVirtual_GetEnhancedInternalEdgeRemoval(const JPH_CharacterVirtual *character) {
    return ToCpp(character)->GetEnhancedInternalEdgeRemoval();
}

void JPH_CharacterVirtual_SetEnhancedInternalEdgeRemoval(JPH_CharacterVirtual *character, bool apply) {
    ToCpp(character)->SetEnhancedInternalEdgeRemoval(apply);
}

float JPH_CharacterVirtual_GetCharacterPadding(const JPH_CharacterVirtual *character) {
    return ToCpp(character)->GetCharacterPadding();
}

uint32_t JPH_CharacterVirtual_GetMaxNumHits(const JPH_CharacterVirtual *character) {
    return ToCpp(character)->GetMaxNumHits();
}

void JPH_CharacterVirtual_SetMaxNumHits(JPH_CharacterVirtual *character, uint32_t maxHits) {
    ToCpp(character)->SetMaxNumHits(maxHits);
}

float JPH_CharacterVirtual_GetHitReductionCosMaxAngle(const JPH_CharacterVirtual *character) {
    return ToCpp(character)->GetHitReductionCosMaxAngle();
}

void JPH_CharacterVirtual_SetHitReductionCosMaxAngle(JPH_CharacterVirtual *character, float cosMaxAngle) {
    ToCpp(character)->SetHitReductionCosMaxAngle(cosMaxAngle);
}

bool JPH_CharacterVirtual_GetMaxHitsExceeded(const JPH_CharacterVirtual *character) {
    return ToCpp(character)->GetMaxHitsExceeded();
}

JPH_Vec3 JPH_CharacterVirtual_GetShapeOffset(const JPH_CharacterVirtual *character) {
    return ToC(ToCpp(character)->GetShapeOffset());
}

void JPH_CharacterVirtual_SetShapeOffset(JPH_CharacterVirtual *character, JPH_Vec3 shapeOffset) {
    ToCpp(character)->SetShapeOffset(ToCpp(shapeOffset));
}

uint64_t JPH_CharacterVirtual_GetUserData(const JPH_CharacterVirtual *character) {
    return ToCpp(character)->GetUserData();
}

void JPH_CharacterVirtual_SetUserData(JPH_CharacterVirtual *character, uint64_t userData) {
    ToCpp(character)->SetUserData(userData);
}

JPH_BodyID JPH_CharacterVirtual_GetInnerBodyID(const JPH_CharacterVirtual *character) {
    return ToCpp(character)->GetInnerBodyID().GetIndexAndSequenceNumber();
}

JPH_Vec3 JPH_CharacterVirtual_CancelVelocityTowardsSteepSlopes(const JPH_CharacterVirtual *character, JPH_Vec3 desiredVelocity) {
    return ToC(ToCpp(character)->CancelVelocityTowardsSteepSlopes(ToCpp(desiredVelocity)));
}

void JPH_CharacterVirtual_StartTrackingContactChanges(JPH_CharacterVirtual *character) {
    ToCpp(character)->StartTrackingContactChanges();
}

void JPH_CharacterVirtual_FinishTrackingContactChanges(JPH_CharacterVirtual *character) {
    ToCpp(character)->FinishTrackingContactChanges();
}

void JPH_CharacterVirtual_Update(JPH_CharacterVirtual *character, float deltaTime, JPH_Vec3 gravity, const JPH_BroadPhaseLayerFilter *broadPhaseLayerFilter, const JPH_ObjectLayerFilter *objectLayerFilter, const JPH_BodyFilter *bodyFilter, const JPH_ShapeFilter *shapeFilter, JPH_TempAllocator *allocator) {
    ToCpp(character)->Update(deltaTime, ToCpp(gravity), *ToCpp(broadPhaseLayerFilter), *ToCpp(objectLayerFilter), *ToCpp(bodyFilter), *ToCpp(shapeFilter), *ToCpp(allocator));
}

bool JPH_CharacterVirtual_CanWalkStairs(const JPH_CharacterVirtual *character, JPH_Vec3 linearVelocity) {
    return ToCpp(character)->CanWalkStairs(ToCpp(linearVelocity));
}

bool JPH_CharacterVirtual_WalkStairs(JPH_CharacterVirtual *character, float deltaTime, JPH_Vec3 stepUp, JPH_Vec3 stepForward, JPH_Vec3 stepForwardTest, JPH_Vec3 stepDownExtra, const JPH_BroadPhaseLayerFilter *broadPhaseLayerFilter, const JPH_ObjectLayerFilter *objectLayerFilter, const JPH_BodyFilter *bodyFilter, const JPH_ShapeFilter *shapeFilter, JPH_TempAllocator *allocator) {
    return ToCpp(character)->WalkStairs(deltaTime, ToCpp(stepUp), ToCpp(stepForward), ToCpp(stepForwardTest), ToCpp(stepDownExtra), *ToCpp(broadPhaseLayerFilter), *ToCpp(objectLayerFilter), *ToCpp(bodyFilter), *ToCpp(shapeFilter), *ToCpp(allocator));
}

bool JPH_CharacterVirtual_StickToFloor(JPH_CharacterVirtual *character, JPH_Vec3 stepDown, const JPH_BroadPhaseLayerFilter *broadPhaseLayerFilter, const JPH_ObjectLayerFilter *objectLayerFilter, const JPH_BodyFilter *bodyFilter, const JPH_ShapeFilter *shapeFilter, JPH_TempAllocator *allocator) {
    return ToCpp(character)->StickToFloor(ToCpp(stepDown), *ToCpp(broadPhaseLayerFilter), *ToCpp(objectLayerFilter), *ToCpp(bodyFilter), *ToCpp(shapeFilter), *ToCpp(allocator));
}

void JPH_CharacterVirtual_ExtendedUpdate(JPH_CharacterVirtual *character, float deltaTime, JPH_Vec3 gravity, const JPH_CharacterVirtual_ExtendedUpdateSettings *settings, const JPH_BroadPhaseLayerFilter *broadPhaseLayerFilter, const JPH_ObjectLayerFilter *objectLayerFilter, const JPH_BodyFilter *bodyFilter, const JPH_ShapeFilter *shapeFilter, JPH_TempAllocator *allocator) {
    ToCpp(character)->ExtendedUpdate(deltaTime, ToCpp(gravity), *ToCpp(settings), *ToCpp(broadPhaseLayerFilter), *ToCpp(objectLayerFilter), *ToCpp(bodyFilter), *ToCpp(shapeFilter), *ToCpp(allocator));
}

void JPH_CharacterVirtual_RefreshContacts(JPH_CharacterVirtual *character, const JPH_BroadPhaseLayerFilter *broadPhaseLayerFilter, const JPH_ObjectLayerFilter *objectLayerFilter, const JPH_BodyFilter *bodyFilter, const JPH_ShapeFilter *shapeFilter, JPH_TempAllocator *allocator) {
    ToCpp(character)->RefreshContacts(*ToCpp(broadPhaseLayerFilter), *ToCpp(objectLayerFilter), *ToCpp(bodyFilter), *ToCpp(shapeFilter), *ToCpp(allocator));
}

void JPH_CharacterVirtual_UpdateGroundVelocity(JPH_CharacterVirtual *character) {
    ToCpp(character)->UpdateGroundVelocity();
}

bool JPH_CharacterVirtual_SetShape(JPH_CharacterVirtual *character, const JPH_Shape *shape, float maxPenetrationDepth, const JPH_BroadPhaseLayerFilter *broadPhaseLayerFilter, const JPH_ObjectLayerFilter *objectLayerFilter, const JPH_BodyFilter *bodyFilter, const JPH_ShapeFilter *shapeFilter, JPH_TempAllocator *allocator) {
    return ToCpp(character)->SetShape(ToCpp(shape), maxPenetrationDepth, *ToCpp(broadPhaseLayerFilter), *ToCpp(objectLayerFilter), *ToCpp(bodyFilter), *ToCpp(shapeFilter), *ToCpp(allocator));
}

void JPH_CharacterVirtual_SetInnerBodyShape(JPH_CharacterVirtual *character, const JPH_Shape *shape) {
    ToCpp(character)->SetInnerBodyShape(ToCpp(shape));
}

JPH_TransformedShape JPH_CharacterVirtual_GetTransformedShape(const JPH_CharacterVirtual *character) {
    return ToC(ToCpp(character)->GetTransformedShape());
}

void JPH_CharacterVirtual_CheckCollision(const JPH_CharacterVirtual *character, JPH_RVec3 position, JPH_Quat rotation, JPH_Vec3 movementDirection, float maxSeparationDistance, const JPH_Shape *shape, JPH_RVec3 baseOffset, JPH_CollideShapeCollector *ioCollector, const JPH_BroadPhaseLayerFilter *broadPhaseLayerFilter, const JPH_ObjectLayerFilter *objectLayerFilter, const JPH_BodyFilter *bodyFilter, const JPH_ShapeFilter *shapeFilter) {
    ToCpp(character)->CheckCollision(ToCpp(position), ToCpp(rotation), ToCpp(movementDirection), maxSeparationDistance, ToCpp(shape), ToCpp(baseOffset), *ToCpp(ioCollector), *ToCpp(broadPhaseLayerFilter), *ToCpp(objectLayerFilter), *ToCpp(bodyFilter), *ToCpp(shapeFilter));
}

JPH_CharacterVirtualSettings JPH_CharacterVirtual_GetCharacterVirtualSettings(const JPH_CharacterVirtual *character) {
    return ToC(ToCpp(character)->GetCharacterVirtualSettings());
}

bool JPH_CharacterVirtual_HasCollidedWithBody(const JPH_CharacterVirtual *character, JPH_BodyID body) {
    return ToCpp(character)->HasCollidedWith(ToCpp(body));
}

bool JPH_CharacterVirtual_HasCollidedWithCharacterByID(const JPH_CharacterVirtual *character, JPH_CharacterID characterID) {
    return ToCpp(character)->HasCollidedWith(JPH::CharacterID(characterID));
}

bool JPH_CharacterVirtual_HasCollidedWithCharacter(const JPH_CharacterVirtual *character, const JPH_CharacterVirtual *otherCharacter) {
    return ToCpp(character)->HasCollidedWith(ToCpp(otherCharacter));
}
