#pragma once

#include <JoltC_Core.h>
#include <JoltC_Shapes.h>
#include <JoltC_Collision.h>
#include <JoltC_Body.h>
#include <JoltC_System.h>

typedef uint32_t JPH_CharacterID;

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
