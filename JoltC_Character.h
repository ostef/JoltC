#pragma once

#include <JoltC_Core.h>
#include <JoltC_Shapes.h>
#include <JoltC_Collision.h>
#include <JoltC_Body.h>
#include <JoltC_System.h>

typedef uint32_t JPH_CharacterID;

#define JPH_CharacterID_cInvalidCharacterID 0xffffffff

typedef uint32_t JPH_ECharacterGroundState;
enum {
    JPH_ECharacterGroundState_OnGround,
    JPH_ECharacterGroundState_OnSteepGround,
    JPH_ECharacterGroundState_NotSupported,
    JPH_ECharacterGroundState_InAir,
};

typedef struct JPH_CharacterBaseSettings {
    JPH_Vec3 up;
    JPH_Plane supportingVolume;
    float maxSlopeAngle;
    bool enhancedInternalEdgeRemoval;
    const JPH_Shape *shape;
} JPH_CharacterBaseSettings;

typedef struct JPH_CharacterBase {
    char opaque;
} JPH_CharacterBase;

JOLTC_API void JPH_CharacterBase_Destroy(JPH_CharacterBase *character);
JOLTC_API void JPH_CharacterBase_Release(JPH_CharacterBase *character);

JOLTC_API void JPH_CharacterBase_SetMaxSlopeAngle(JPH_CharacterBase *character, float maxSlopeAngle);
JOLTC_API float JPH_CharacterBase_GetCosMaxSlopeAngle(const JPH_CharacterBase *character);
JOLTC_API void JPH_CharacterBase_SetUp(JPH_CharacterBase *character, JPH_Vec3 up);
JOLTC_API JPH_Vec3 JPH_CharacterBase_GetUp(const JPH_CharacterBase *character);
JOLTC_API JPH_Plane JPH_CharacterBase_GetSupportingVolume(const JPH_CharacterBase *character);
JOLTC_API void JPH_CharacterBase_SetSupportingVolume(JPH_CharacterBase *character, JPH_Plane plane);
JOLTC_API bool JPH_CharacterBase_IsSlopeTooSteep(const JPH_CharacterBase *character, JPH_Vec3 normal);
JOLTC_API const JPH_Shape *JPH_CharacterBase_GetShape(const JPH_CharacterBase *character);
JOLTC_API JPH_ECharacterGroundState JPH_CharacterBase_GetGroundState(const JPH_CharacterBase *character);
JOLTC_API bool JPH_CharacterBase_IsSupported(const JPH_CharacterBase *character);
JOLTC_API JPH_RVec3 JPH_CharacterBase_GetGroundPosition(const JPH_CharacterBase *character);
JOLTC_API JPH_Vec3 JPH_CharacterBase_GetGroundNormal(const JPH_CharacterBase *character);
JOLTC_API JPH_Vec3 JPH_CharacterBase_GetGroundVelocity(const JPH_CharacterBase *character);
JOLTC_API const JPH_PhysicsMaterial *JPH_CharacterBase_GetGroundMaterial(const JPH_CharacterBase *character);
JOLTC_API JPH_BodyID JPH_CharacterBase_GetGroundBodyID(const JPH_CharacterBase *character);
JOLTC_API JPH_SubShapeID JPH_CharacterBase_GetGroundSubShapeID(const JPH_CharacterBase *character);
JOLTC_API uint64_t JPH_CharacterBase_GetGroundUserData(const JPH_CharacterBase *character);

typedef struct JPH_CharacterSettings {
    // JPH_CharacterBaseSettings base
    JPH_Vec3 up;
    JPH_Plane supportingVolume;
    float maxSlopeAngle;
    bool enhancedInternalEdgeRemoval;
    const JPH_Shape *shape;

    JPH_ObjectLayer layer;
    float mass;
    float friction;
    float gravityFactor;
    JPH_EAllowedDOFs allowedDOFs;
} JPH_CharacterSettings;

typedef struct JPH_Character {
    JPH_CharacterBase base;
} JPH_Character;

JOLTC_API JPH_Character *JPH_Character_Create(const JPH_CharacterSettings *settings, JPH_RVec3 position, JPH_Quat rotation, uint64_t userData, JPH_PhysicsSystem *system);

JOLTC_API void JPH_Character_AddToPhysicsSystem(JPH_Character *character, JPH_EActivation activationMode, bool lockBodies);
JOLTC_API void JPH_Character_RemoveFromPhysicsSystem(JPH_Character *character, bool lockBodies);
JOLTC_API void JPH_Character_Activate(JPH_Character *character, bool lockBodies);
JOLTC_API void JPH_Character_PostSimulation(JPH_Character *character, float maxSeparationDistance, bool lockBodies);
JOLTC_API void JPH_Character_SetLinearAndAngularVelocity(JPH_Character *character, JPH_Vec3 linearVelocity, JPH_Vec3 angularVelocity, bool lockBodies);
JOLTC_API JPH_Vec3 JPH_Character_GetLinearVelocity(const JPH_Character *character, bool lockBodies);
JOLTC_API void JPH_Character_SetLinearVelocity(JPH_Character *character, JPH_Vec3 linearVelocity, bool lockBodies);
JOLTC_API void JPH_Character_AddLinearVelocity(JPH_Character *character, JPH_Vec3 linearVelocity, bool lockBodies);
JOLTC_API void JPH_Character_AddImpulse(JPH_Character *character, JPH_Vec3 impulse, bool lockBodies);
JOLTC_API JPH_BodyID JPH_Character_GetBodyID(const JPH_Character *character);
JOLTC_API void JPH_Character_GetPositionAndRotation(const JPH_Character *character, JPH_RVec3 *outPosition, JPH_Quat *outRotation, bool lockBodies);
JOLTC_API void JPH_Character_SetPositionAndRotation(const JPH_Character *character, JPH_RVec3 position, JPH_Quat rotation, JPH_EActivation activationMode, bool lockBodies);
JOLTC_API JPH_RVec3 JPH_Character_GetPosition(const JPH_Character *character, bool lockBodies);
JOLTC_API void JPH_Character_SetPosition(JPH_Character *character, JPH_RVec3 position, JPH_EActivation activationMode, bool lockBodies);
JOLTC_API JPH_Quat JPH_Character_GetRotation(const JPH_Character *character, bool lockBodies);
JOLTC_API void JPH_Character_SetRotation(JPH_Character *character, JPH_Quat rotation, JPH_EActivation activationMode, bool lockBodies);
JOLTC_API JPH_RVec3 JPH_Character_GetCenterOfMassPosition(const JPH_Character *character, bool lockBodies);
JOLTC_API JPH_RMat44 JPH_Character_GetWorldTransform(const JPH_Character *character, bool lockBodies);
JOLTC_API JPH_ObjectLayer JPH_Character_GetLayer(const JPH_Character *character);
JOLTC_API void JPH_Character_SetLayer(JPH_Character *character, JPH_ObjectLayer layer, bool lockBodies);
JOLTC_API bool JPH_Character_SetShape(JPH_Character *character, const JPH_Shape *shape, float maxPenetrationDepth, bool lockBodies);
JOLTC_API JPH_TransformedShape JPH_Character_GetTransformedShape(const JPH_Character *character, bool lockBodies);
JOLTC_API void JPH_Character_CheckCollision(const JPH_Character *character, JPH_RVec3 position, JPH_Quat rotation, JPH_Vec3 movementDirection, float maxSeparationDistance, const JPH_Shape *shape, JPH_RVec3 baseOffset, JPH_CollideShapeCollector *collector, bool lockBodies);
JOLTC_API JPH_CharacterSettings JPH_Character_GetCharacterSettings(const JPH_Character *character, bool lockBodies);

typedef struct JPH_CharacterVirtual {
    JPH_CharacterBase base;
} JPH_CharacterVirtual;

typedef struct JPH_CharacterVirtualSettings {
    // JPH_CharacterBaseSettings base
    JPH_Vec3 up;
    JPH_Plane supportingVolume;
    float maxSlopeAngle;
    bool enhancedInternalEdgeRemoval;
    const JPH_Shape *shape;

    JPH_CharacterID id;
    float mass;
    float maxStrength;
    JPH_Vec3 shapeOffset;
    JPH_EBackFaceMode backFaceMode;
    float predictiveContactDistance;
    uint32_t maxCollisionIterations;
    uint32_t maxConstraintIterations;
    float minTimeRemaining;
    float collisionTolerance;
    float characterPadding;
    uint32_t maxNumHits;
    float hitReductionCosMaxAngle;
    float penetrationRecoverySpeed;
    const JPH_Shape *innerBodyShape;
    JPH_BodyID innerBodyIDOverride;
    JPH_ObjectLayer innerBodyLayer;
} JPH_CharacterVirtualSettings;

typedef struct JPH_CharacterContact {
	JPH_BodyID bodyB;
	JPH_CharacterID characterIDB;
	JPH_SubShapeID subShapeIDB;

	JPH_RVec3 position;
	JPH_Vec3 linearVelocity;
	JPH_Vec3 contactNormal;
	JPH_Vec3 surfaceNormal;
	float distance;
	float fraction;
	JPH_EMotionType motionTypeB;
	bool isSensorB;
	const JPH_CharacterVirtual *characterB;
	uint64_t userData;
	const JPH_PhysicsMaterial *material;
	bool hadCollision;
	bool wasDiscarded;
	bool canPushCharacter;
	bool isBackFacingContact;
} JPH_CharacterContact;

typedef struct JPH_CharacterContactSettings {
    bool canPushCharacter;
    bool canReceiveImpulses;
} JPH_CharacterContactSettings;

typedef struct JPH_CharacterContactListener_Funcs {
    void (JOLTC_CALL *Destruct)(void *data);
    void (JOLTC_CALL *OnAdjustBodyVelocity)(void *data, const JPH_CharacterVirtual *character, const JPH_Body *body2, JPH_Vec3 *ioLinearVelocity, JPH_Vec3 *ioAngularVelocity);
    bool (JOLTC_CALL *OnContactValidate)(void *data, const JPH_CharacterVirtual *character, const JPH_CharacterContact *contact);
    void (JOLTC_CALL *OnContactAdded)(void *data, const JPH_CharacterVirtual *character, const JPH_CharacterContact *contact, JPH_CharacterContactSettings *ioSettings);
    void (JOLTC_CALL *OnContactPersisted)(void *data, const JPH_CharacterVirtual *character, const JPH_CharacterContact *contact, JPH_CharacterContactSettings *ioSettings);
    void (JOLTC_CALL *OnContactRemoved)(void *data, const JPH_CharacterVirtual *character, JPH_BodyID bodyID2, JPH_SubShapeID subShapeID2);
    bool (JOLTC_CALL *OnCharacterContactValidate)(void *data, const JPH_CharacterVirtual *character, const JPH_CharacterContact *contact);
    void (JOLTC_CALL *OnCharacterContactAdded)(void *data, const JPH_CharacterVirtual *character, const JPH_CharacterContact *contact, JPH_CharacterContactSettings *ioSettings);
    void (JOLTC_CALL *OnCharacterContactPersisted)(void *data, const JPH_CharacterVirtual *character, const JPH_CharacterContact *contact, JPH_CharacterContactSettings *ioSettings);
    void (JOLTC_CALL *OnCharacterContactRemoved)(void *data, const JPH_CharacterVirtual *character, JPH_CharacterID otherCharacterID, JPH_SubShapeID subShapeID2);
    void (JOLTC_CALL *OnContactSolve)(void *data, const JPH_CharacterVirtual *character, JPH_BodyID bodyID2, JPH_SubShapeID subShapeID2, JPH_RVec3 contactPosition, JPH_Vec3 contactNormal, JPH_Vec3 contactVelocity, const JPH_PhysicsMaterial *contactMaterial, JPH_Vec3 characterVelocity, JPH_Vec3 *ioNewCharacterVelocity);
    void (JOLTC_CALL *OnCharacterContactSolve)(void *data, const JPH_CharacterVirtual *character, const JPH_CharacterVirtual *otherCharacter, JPH_SubShapeID subShapeID2, JPH_RVec3 contactPosition, JPH_Vec3 contactNormal, JPH_Vec3 contactVelocity, const JPH_PhysicsMaterial *contactMaterial, JPH_Vec3 characterVelocity, JPH_Vec3 *ioNewCharacterVelocity);
} JPH_CharacterContactListener_Funcs;

typedef struct JPH_CharacterContactListener JPH_CharacterContactListener;

JOLTC_API JPH_CharacterContactListener *JPH_CharacterContactListener_Create(void *data, JPH_CharacterContactListener_Funcs funcs, JPH_JoltCAllocator allocator);
JOLTC_API void JPH_CharacterContactListener_Destroy(JPH_CharacterContactListener *self);

typedef struct JPH_CharacterVirtual_ExtendedUpdateSettings {
    JPH_Vec3 stickToFloorStepDown;
    JPH_Vec3 walkStairsStepUp;
    float walkStairsMinStepForward;
    float walkStairsStepForwardTest;
    float walkStairsCosAngleForwardContact;
    JPH_Vec3 walkStairsStepDownExtra;
} JPH_CharacterVirtual_ExtendedUpdateSettings;

JOLTC_API JPH_CharacterVirtual *JPH_CharacterVirtual_Create(const JPH_CharacterSettings *settings, JPH_RVec3 position, JPH_Quat rotation, uint64_t userData, JPH_PhysicsSystem *system);

JOLTC_API JPH_CharacterID JPH_CharacterVirtual_GetID(const JPH_CharacterVirtual *character);
JOLTC_API void JPH_CharacterVirtual_SetListener(JPH_CharacterVirtual *character, JPH_CharacterContactListener *listener);
JOLTC_API JPH_CharacterContactListener *JPH_CharacterVirtual_GetListener(const JPH_CharacterVirtual *character);
// @Todo
// JOLTC_API void JPH_CharacterVirtual_SetCharacterVsCharacterCollision(JPH_CharacterVirtual *character, CharacterVsCharacterCollision *inCharacterVsCharacterCollision);
JOLTC_API JPH_Vec3 JPH_CharacterVirtual_GetLinearVelocity(const JPH_CharacterVirtual *character);
JOLTC_API void JPH_CharacterVirtual_SetLinearVelocity(JPH_CharacterVirtual *character, JPH_Vec3 linearVelocity);
JOLTC_API JPH_RVec3 JPH_CharacterVirtual_GetPosition(const JPH_CharacterVirtual *character);
JOLTC_API void JPH_CharacterVirtual_SetPosition(JPH_CharacterVirtual *character, JPH_RVec3 position);
JOLTC_API JPH_Quat JPH_CharacterVirtual_GetRotation(const JPH_CharacterVirtual *character);
JOLTC_API void JPH_CharacterVirtual_SetRotation(JPH_CharacterVirtual *character, JPH_Quat rotation);
JOLTC_API JPH_RVec3 JPH_CharacterVirtual_GetCenterOfMassPosition(const JPH_CharacterVirtual *character);
JOLTC_API JPH_RMat44 JPH_CharacterVirtual_GetWorldTransform(const JPH_CharacterVirtual *character);
JOLTC_API JPH_RMat44 JPH_CharacterVirtual_GetCenterOfMassTransform(const JPH_CharacterVirtual *character);
JOLTC_API float JPH_CharacterVirtual_GetMass(const JPH_CharacterVirtual *character);
JOLTC_API void JPH_CharacterVirtual_SetMass(JPH_CharacterVirtual *character, float mass);
JOLTC_API float JPH_CharacterVirtual_GetMaxStrength(const JPH_CharacterVirtual *character);
JOLTC_API void JPH_CharacterVirtual_SetMaxStrength(JPH_CharacterVirtual *character, float maxStrength);
JOLTC_API float JPH_CharacterVirtual_GetPenetrationRecoverySpeed(const JPH_CharacterVirtual *character);
JOLTC_API void JPH_CharacterVirtual_SetPenetrationRecoverySpeed(JPH_CharacterVirtual *character, float speed);
JOLTC_API bool JPH_CharacterVirtual_GetEnhancedInternalEdgeRemoval(const JPH_CharacterVirtual *character);
JOLTC_API void JPH_CharacterVirtual_SetEnhancedInternalEdgeRemoval(JPH_CharacterVirtual *character, bool apply);
JOLTC_API float JPH_CharacterVirtual_GetCharacterPadding(const JPH_CharacterVirtual *character);
JOLTC_API uint32_t JPH_CharacterVirtual_GetMaxNumHits(const JPH_CharacterVirtual *character);
JOLTC_API void JPH_CharacterVirtual_SetMaxNumHits(JPH_CharacterVirtual *character, uint32_t maxHits);
JOLTC_API float JPH_CharacterVirtual_GetHitReductionCosMaxAngle(const JPH_CharacterVirtual *character);
JOLTC_API void JPH_CharacterVirtual_SetHitReductionCosMaxAngle(JPH_CharacterVirtual *character, float cosMaxAngle);
JOLTC_API bool JPH_CharacterVirtual_GetMaxHitsExceeded(const JPH_CharacterVirtual *character);
JOLTC_API JPH_Vec3 JPH_CharacterVirtual_GetShapeOffset(const JPH_CharacterVirtual *character);
JOLTC_API void JPH_CharacterVirtual_SetShapeOffset(JPH_CharacterVirtual *character, JPH_Vec3 shapeOffset);
JOLTC_API uint64_t JPH_CharacterVirtual_GetUserData(const JPH_CharacterVirtual *character);
JOLTC_API void JPH_CharacterVirtual_SetUserData(JPH_CharacterVirtual *character, uint64_t userData);
JOLTC_API JPH_BodyID JPH_CharacterVirtual_GetInnerBodyID(const JPH_CharacterVirtual *character);
JOLTC_API JPH_Vec3 JPH_CharacterVirtual_CancelVelocityTowardsSteepSlopes(const JPH_CharacterVirtual *character, JPH_Vec3 desiredVelocity);
JOLTC_API void JPH_CharacterVirtual_StartTrackingContactChanges(JPH_CharacterVirtual *character);
JOLTC_API void JPH_CharacterVirtual_FinishTrackingContactChanges(JPH_CharacterVirtual *character);
JOLTC_API void JPH_CharacterVirtual_Update(JPH_CharacterVirtual *character, float deltaTime, JPH_Vec3 gravity, const JPH_BroadPhaseLayerFilter *broadPhaseLayerFilter, const JPH_ObjectLayerFilter *objectLayerFilter, const JPH_BodyFilter *bodyFilter, const JPH_ShapeFilter *shapeFilter, JPH_TempAllocator *allocator);
JOLTC_API bool JPH_CharacterVirtual_CanWalkStairs(const JPH_CharacterVirtual *character, JPH_Vec3 linearVelocity);
JOLTC_API bool JPH_CharacterVirtual_WalkStairs(JPH_CharacterVirtual *character, float deltaTime, JPH_Vec3 stepUp, JPH_Vec3 stepForward, JPH_Vec3 stepForwardTest, JPH_Vec3 stepDownExtra, const JPH_BroadPhaseLayerFilter *broadPhaseLayerFilter, const JPH_ObjectLayerFilter *objectLayerFilter, const JPH_BodyFilter *bodyFilter, const JPH_ShapeFilter *shapeFilter, JPH_TempAllocator *allocator);
JOLTC_API bool JPH_CharacterVirtual_StickToFloor(JPH_CharacterVirtual *character, JPH_Vec3 stepDown, const JPH_BroadPhaseLayerFilter *broadPhaseLayerFilter, const JPH_ObjectLayerFilter *objectLayerFilter, const JPH_BodyFilter *bodyFilter, const JPH_ShapeFilter *shapeFilter, JPH_TempAllocator *allocator);
JOLTC_API void JPH_CharacterVirtual_ExtendedUpdate(JPH_CharacterVirtual *character, float deltaTime, JPH_Vec3 gravity, const JPH_CharacterVirtual_ExtendedUpdateSettings *settings, const JPH_BroadPhaseLayerFilter *broadPhaseLayerFilter, const JPH_ObjectLayerFilter *objectLayerFilter, const JPH_BodyFilter *bodyFilter, const JPH_ShapeFilter *shapeFilter, JPH_TempAllocator *allocator);
JOLTC_API void JPH_CharacterVirtual_RefreshContacts(JPH_CharacterVirtual *character, const JPH_BroadPhaseLayerFilter *broadPhaseLayerFilter, const JPH_ObjectLayerFilter *objectLayerFilter, const JPH_BodyFilter *bodyFilter, const JPH_ShapeFilter *shapeFilter, JPH_TempAllocator *allocator);
JOLTC_API void JPH_CharacterVirtual_UpdateGroundVelocity(JPH_CharacterVirtual *character);
JOLTC_API bool JPH_CharacterVirtual_SetShape(JPH_CharacterVirtual *character, const JPH_Shape *shape, float maxPenetrationDepth, const JPH_BroadPhaseLayerFilter *broadPhaseLayerFilter, const JPH_ObjectLayerFilter *objectLayerFilter, const JPH_BodyFilter *bodyFilter, const JPH_ShapeFilter *shapeFilter, JPH_TempAllocator *allocator);
JOLTC_API void JPH_CharacterVirtual_SetInnerBodyShape(JPH_CharacterVirtual *character, const JPH_Shape *shape);
JOLTC_API JPH_TransformedShape JPH_CharacterVirtual_GetTransformedShape(const JPH_CharacterVirtual *character);
JOLTC_API void JPH_CharacterVirtual_CheckCollision(const JPH_CharacterVirtual *character, JPH_RVec3 position, JPH_Quat rotation, JPH_Vec3 movementDirection, float maxSeparationDistance, const JPH_Shape *shape, JPH_RVec3 baseOffset, JPH_CollideShapeCollector *ioCollector, const JPH_BroadPhaseLayerFilter *broadPhaseLayerFilter, const JPH_ObjectLayerFilter *objectLayerFilter, const JPH_BodyFilter *bodyFilter, const JPH_ShapeFilter *shapeFilter);
JOLTC_API JPH_CharacterVirtualSettings JPH_CharacterVirtual_GetCharacterVirtualSettings(const JPH_CharacterVirtual *character);

// @Todo
// const ContactList &                 JPH_CharacterVirtual_GetActiveContacts(const JPH_CharacterVirtual *character);

JOLTC_API bool JPH_CharacterVirtual_HasCollidedWithBody(const JPH_CharacterVirtual *character, JPH_BodyID body);
JOLTC_API bool JPH_CharacterVirtual_HasCollidedWithCharacterByID(const JPH_CharacterVirtual *character, JPH_CharacterID characterID);
JOLTC_API bool JPH_CharacterVirtual_HasCollidedWithCharacter(const JPH_CharacterVirtual *character, const JPH_CharacterVirtual *otherCharacter);
