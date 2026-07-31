#pragma once

#include <JoltC_Core.h>
#include <JoltC_Body.h>

#ifdef JOLTC_DEBUG_RENDERER
#include <JoltC_DebugRenderer.h>
#endif

struct JPH_TwoBodyConstraint;

typedef uint32_t JPH_EConstraintType;
enum JPH_EConstraintType_ {
    JPH_EConstraintType_Constraint,
    JPH_EConstraintType_TwoBodyConstraint,
};

typedef uint32_t JPH_EConstraintSubType;
enum JPH_EConstraintSubType_ {
    JPH_EConstraintSubType_Fixed,
    JPH_EConstraintSubType_Point,
    JPH_EConstraintSubType_Hinge,
    JPH_EConstraintSubType_Slider,
    JPH_EConstraintSubType_Distance,
    JPH_EConstraintSubType_Cone,
    JPH_EConstraintSubType_SwingTwist,
    JPH_EConstraintSubType_SixDOF,
    JPH_EConstraintSubType_Path,
    JPH_EConstraintSubType_Vehicle,
    JPH_EConstraintSubType_RackAndPinion,
    JPH_EConstraintSubType_Gear,
    JPH_EConstraintSubType_Pulley,

    JPH_EConstraintSubType_User1,
    JPH_EConstraintSubType_User2,
    JPH_EConstraintSubType_User3,
    JPH_EConstraintSubType_User4,
};

typedef uint32_t JPH_EConstraintSpace;
enum JPH_EConstraintSpace_ {
    JPH_EConstraintSpace_LocalToBodyCOM,
    JPH_EConstraintSpace_WorldSpace,
};

typedef uint8_t JPH_ESpringMode;
enum JPH_ESpringMode_ {
    JPH_ESpringMode_FrequencyAndDamping,
    JPH_ESpringMode_StiffnessAndDamping,
    JPH_ESpringMode_MassNormalizedStiffnessAndDamping,
};

typedef struct JPH_SpringSettings {
    JPH_ESpringMode mode;
    union {
        float frequency;
        float stiffness;
    };
    float damping;
} JPH_SpringSettings;

typedef uint32_t JPH_EMotorState;
enum JPH_EMotorState_ {
    JPH_EMotorState_Off,
    JPH_EMotorState_Velocity,
    JPH_EMotorState_Position,
    JPH_EMotorState_PositionAndVelocity,
};

typedef struct JPH_MotorSettings {
    JPH_SpringSettings springSettings;
    float minForceLimit;
    float maxForceLimit;
    float minTorqueLimit;
    float maxTorqueLimit;
} JPH_MotorSettings;

typedef struct JPH_ConstraintSettings {
    bool enabled;
    uint32_t constraintPriority;
    uint32_t numVelocityStepsOverride;
    uint32_t numPositionStepsOverride;
    float drawConstraintSize;
    uint64_t userData;
} JPH_ConstraintSettings;

// typedef struct JPH_VehicleConstraintSettings {
//     JPH_ConstraintSettings base;
// } JPH_VehicleConstraintSettings;

typedef struct JPH_TwoBodyConstraintSettings {
    JPH_ConstraintSettings base;
} JPH_TwoBodyConstraintSettings;

typedef struct JPH_ConeConstraintSettings {
    JPH_TwoBodyConstraintSettings base;
    JPH_EConstraintSpace space;
    JPH_RVec3 point1;
    JPH_Vec3 twistAxis1;
    JPH_RVec3 point2;
    JPH_Vec3 twistAxis2;
    float halfConeAngle;
} JPH_ConeConstraintSettings;

JOLTC_API struct JPH_TwoBodyConstraint *JPH_ConeConstraintSettings_CreateConstraint(const JPH_ConeConstraintSettings *settings, JPH_Body *body1, JPH_Body *body2);

typedef struct JPH_DistanceConstraintSettings {
    JPH_TwoBodyConstraintSettings base;
    JPH_EConstraintSpace space;
    JPH_RVec3 point1;
    JPH_RVec3 point2;
    float minDistance;
    float maxDistance;
    JPH_SpringSettings limitsSpringSettings;
} JPH_DistanceConstraintSettings;

JOLTC_API struct JPH_TwoBodyConstraint *JPH_DistanceConstraintSettings_CreateConstraint(const JPH_DistanceConstraintSettings *settings, JPH_Body *body1, JPH_Body *body2);

typedef struct JPH_FixedConstraintSettings {
    JPH_TwoBodyConstraintSettings base;
    JPH_EConstraintSpace space;
    bool autoDetectPoint;
    JPH_RVec3 point1;
    JPH_Vec3 axisX1;
    JPH_Vec3 axisY1;
    JPH_RVec3 point2;
    JPH_Vec3 axisX2;
    JPH_Vec3 axisY2;
} JPH_FixedConstraintSettings;

JOLTC_API struct JPH_TwoBodyConstraint *JPH_FixedConstraintSettings_CreateConstraint(const JPH_FixedConstraintSettings *settings, JPH_Body *body1, JPH_Body *body2);

typedef struct JPH_GearConstraintSettings {
    JPH_TwoBodyConstraintSettings base;
    JPH_EConstraintSpace space;
    JPH_Vec3 hingeAxis1;
    JPH_Vec3 hingeAxis2;
    float ratio;
} JPH_GearConstraintSettings;

JOLTC_API struct JPH_TwoBodyConstraint *JPH_GearConstraintSettings_CreateConstraint(const JPH_GearConstraintSettings *settings, JPH_Body *body1, JPH_Body *body2);

typedef struct JPH_HingeConstraintSettings {
    JPH_TwoBodyConstraintSettings base;
    JPH_EConstraintSpace space;
    JPH_RVec3 point1;
    JPH_Vec3 hingeAxis1;
    JPH_Vec3 normalAxis1;
    JPH_RVec3 point2;
    JPH_Vec3 hingeAxis2;
    JPH_Vec3 normalAxis2;
    float limitsMin;
    float limitsMax;
    JPH_SpringSettings limitsSpringSettings;
    float maxFrictionTorque;
    JPH_MotorSettings motorSettings;
} JPH_HingeConstraintSettings;

JOLTC_API struct JPH_TwoBodyConstraint *JPH_HingeConstraintSettings_CreateConstraint(const JPH_HingeConstraintSettings *settings, JPH_Body *body1, JPH_Body *body2);

typedef struct JPH_PathConstraintPath {
    char opaque;
} JPH_PathConstraintPath;

JOLTC_API void JPH_PathConstraintPath_Destroy(JPH_PathConstraintPath *path);
JOLTC_API float JPH_PathConstraintPath_GetPathMaxFraction(const JPH_PathConstraintPath *path);
JOLTC_API float JPH_PathConstraintPath_GetClosestPoint(const JPH_PathConstraintPath *path, JPH_Vec3 position, float fractionHint);
JOLTC_API void JPH_PathConstraintPath_GetPointOnPath(const JPH_PathConstraintPath *path, float fraction, JPH_Vec3 *outPathPosition, JPH_Vec3 *outPathTangent, JPH_Vec3 *outPathNormal, JPH_Vec3 *outPathBinormal);
JOLTC_API void JPH_PathConstraintPath_SetIsLooping(JPH_PathConstraintPath *path, bool isLooping);
JOLTC_API bool JPH_PathConstraintPath_IsLooping(const JPH_PathConstraintPath *path);
#ifdef JOLTC_DEBUG_RENDERER
JOLTC_API void JPH_PathConstraintPath_DrawPath(const JPH_PathConstraintPath *path, JPH_DebugRenderer *renderer, JPH_RMat44 baseTransform);
#endif

typedef struct JPH_PathConstraintPathHermite {
    JPH_PathConstraintPath base;
} JPH_PathConstraintPathHermite;

JOLTC_API JPH_PathConstraintPathHermite *JPH_PathConstraintPathHermite_Create();
JOLTC_API void JPH_PathConstraintPathHermite_AddPoint(JPH_PathConstraintPathHermite *path, JPH_Vec3 position, JPH_Vec3 tangent, JPH_Vec3 normal);

typedef uint32_t JPH_EPathRotationConstraintType;
enum JPH_EPathRotationConstraintType_ {
    JPH_EPathRotationConstraintType_Free,
    JPH_EPathRotationConstraintType_ConstrainAroundTangent,
    JPH_EPathRotationConstraintType_ConstrainAroundNormal,
    JPH_EPathRotationConstraintType_ConstrainAroundBinormal,
    JPH_EPathRotationConstraintType_ConstrainToPath,
    JPH_EPathRotationConstraintType_FullyConstrained,
};

typedef struct JPH_PathConstraintSettings {
    JPH_TwoBodyConstraintSettings base;
    const JPH_PathConstraintPath *path;
    JPH_Vec3 pathPosition;
    JPH_Quat pathRotation;
    float pathFraction;
    float maxFrictionForce;
    JPH_MotorSettings positionMotorSettings;
    JPH_EPathRotationConstraintType rotationConstraintType;
} JPH_PathConstraintSettings;

JOLTC_API struct JPH_TwoBodyConstraint *JPH_PathConstraintSettings_CreateConstraint(const JPH_PathConstraintSettings *settings, JPH_Body *body1, JPH_Body *body2);

typedef struct JPH_PointConstraintSettings {
    JPH_TwoBodyConstraintSettings base;
    JPH_EConstraintSpace space;
    JPH_RVec3 point1;
    JPH_RVec3 point2;
} JPH_PointConstraintSettings;

JOLTC_API struct JPH_TwoBodyConstraint *JPH_PointConstraintSettings_CreateConstraint(const JPH_PointConstraintSettings *settings, JPH_Body *body1, JPH_Body *body2);

typedef struct JPH_PulleyConstraintSettings {
    JPH_TwoBodyConstraintSettings base;
    JPH_EConstraintSpace space;
    JPH_RVec3 bodyPoint1;
    JPH_RVec3 fixedPoint1;
    JPH_RVec3 bodyPoint2;
    JPH_RVec3 fixedPoint2;
    float ratio;
    float minLength;
    float maxLength;
} JPH_PulleyConstraintSettings;

JOLTC_API struct JPH_TwoBodyConstraint *JPH_PulleyConstraintSettings_CreateConstraint(const JPH_PulleyConstraintSettings *settings, JPH_Body *body1, JPH_Body *body2);

typedef struct JPH_RackAndPinionConstraintSettings {
    JPH_TwoBodyConstraintSettings base;
    JPH_EConstraintSpace space;
    JPH_Vec3 hingeAxis;
    JPH_Vec3 sliderAxis;
    float ratio;
} JPH_RackAndPinionConstraintSettings;

JOLTC_API struct JPH_TwoBodyConstraint *JPH_RackAndPinionConstraintSettings_CreateConstraint(const JPH_RackAndPinionConstraintSettings *settings, JPH_Body *body1, JPH_Body *body2);

typedef uint32_t JPH_SixDOFConstraintSettings_EAxis;
enum JPH_SixDOFConstraintSettings_EAxis_ {
    JPH_SixDOFConstraintSettings_EAxis_TranslationX,
    JPH_SixDOFConstraintSettings_EAxis_TranslationY,
    JPH_SixDOFConstraintSettings_EAxis_TranslationZ,
    JPH_SixDOFConstraintSettings_EAxis_RotationX,
    JPH_SixDOFConstraintSettings_EAxis_RotationY,
    JPH_SixDOFConstraintSettings_EAxis_RotationZ,

    JPH_SixDOFConstraintSettings_EAxis_Num,
    JPH_SixDOFConstraintSettings_EAxis_NumTranslation = JPH_SixDOFConstraintSettings_EAxis_TranslationZ + 1,
};

typedef uint8_t JPH_ESwingType;
enum JPH_ESwingType_ {
    JPH_ESwingType_Cone,
    JPH_ESwingType_Pyramid,
};

typedef struct JPH_SixDOFConstraintSettings {
    JPH_TwoBodyConstraintSettings base;
    JPH_EConstraintSpace space;
    JPH_RVec3 position1;
    JPH_Vec3 axisX1;
    JPH_Vec3 axisY1;
    JPH_RVec3 position2;
    JPH_Vec3 axisX2;
    JPH_Vec3 axisY2;
    float maxFriction[JPH_SixDOFConstraintSettings_EAxis_Num];
    JPH_ESwingType swingType;
    float limitMin[JPH_SixDOFConstraintSettings_EAxis_Num];
    float limitMax[JPH_SixDOFConstraintSettings_EAxis_Num];
    JPH_SpringSettings limitsSpringSettings[JPH_SixDOFConstraintSettings_EAxis_NumTranslation];
    JPH_MotorSettings motorSettings[JPH_SixDOFConstraintSettings_EAxis_Num];
} JPH_SixDOFConstraintSettings;

JOLTC_API struct JPH_TwoBodyConstraint *JPH_SixDOFConstraintSettings_CreateConstraint(const JPH_SixDOFConstraintSettings *settings, JPH_Body *body1, JPH_Body *body2);
JOLTC_API void JPH_SixDOFConstraintSettings_MakeFreeAxis(JPH_SixDOFConstraintSettings *settings, JPH_SixDOFConstraintSettings_EAxis axis);
JOLTC_API bool JPH_SixDOFConstraintSettings_IsFreeAxis(const JPH_SixDOFConstraintSettings *settings, JPH_SixDOFConstraintSettings_EAxis axis);
JOLTC_API void JPH_SixDOFConstraintSettings_MakeFixedAxis(JPH_SixDOFConstraintSettings *settings, JPH_SixDOFConstraintSettings_EAxis axis);
JOLTC_API bool JPH_SixDOFConstraintSettings_IsFixedAxis(const JPH_SixDOFConstraintSettings *settings, JPH_SixDOFConstraintSettings_EAxis axis);
JOLTC_API void JPH_SixDOFConstraintSettings_SetLimitedAxis(JPH_SixDOFConstraintSettings *settings, JPH_SixDOFConstraintSettings_EAxis axis, float min, float max);

typedef struct JPH_SliderConstraintSettings {
    JPH_TwoBodyConstraintSettings base;
    JPH_EConstraintSpace space;
    bool autoDetectPoint;
    JPH_RVec3 point1;
    JPH_Vec3 sliderAxis1;
    JPH_Vec3 normalAxis1;
    JPH_RVec3 point2;
    JPH_Vec3 sliderAxis2;
    JPH_Vec3 normalAxis2;
    float limitsMin;
    float limitsMax;
    JPH_SpringSettings limitsSpringSettings;
    float maxFrictionForce;
    JPH_MotorSettings motorSettings;
} JPH_SliderConstraintSettings;

JOLTC_API struct JPH_TwoBodyConstraint *JPH_SliderConstraintSettings_CreateConstraint(const JPH_SliderConstraintSettings *settings, JPH_Body *body1, JPH_Body *body2);

typedef struct JPH_SwingTwistConstraintSettings {
    JPH_TwoBodyConstraintSettings base;
    JPH_EConstraintSpace space;
    JPH_RVec3 position1;
    JPH_Vec3 twistAxis1;
    JPH_Vec3 planeAxis1;
    JPH_RVec3 position2;
    JPH_Vec3 twistAxis2;
    JPH_Vec3 planeAxis2;
    JPH_ESwingType swingType;
    float normalHalfConeAngle;
    float planeHalfConeAngle;
    float twistMinAngle;
    float twistMaxAngle;
    float maxFrictionTorque;
    JPH_MotorSettings swingMotorSettings;
    JPH_MotorSettings twistMotorSettings;
} JPH_SwingTwistConstraintSettings;

JOLTC_API struct JPH_TwoBodyConstraint *JPH_SwingTwistConstraintSettings_CreateConstraint(const JPH_SwingTwistConstraintSettings *settings, JPH_Body *body1, JPH_Body *body2);

// Constraint

typedef struct JPH_Constraint {
    char opaque;
} JPH_Constraint;

JOLTC_API void JPH_Constraint_Destroy(JPH_Constraint *constraint);
JOLTC_API JPH_EConstraintType JPH_Constraint_GetType(const JPH_Constraint *constraint);
JOLTC_API JPH_EConstraintSubType JPH_Constraint_GetSubType(const JPH_Constraint *constraint);
JOLTC_API uint32_t JPH_Constraint_GetConstraintPriority(const JPH_Constraint *constraint);
JOLTC_API void JPH_Constraint_SetConstraintPriority(JPH_Constraint *constraint, uint32_t priority);
JOLTC_API uint32_t JPH_Constraint_GetNumVelocityStepsOverride(const JPH_Constraint *constraint);
JOLTC_API void JPH_Constraint_SetNumVelocityStepsOverride(JPH_Constraint *constraint, uint32_t steps);
JOLTC_API uint32_t JPH_Constraint_GetNumPositionStepsOverride(const JPH_Constraint *constraint);
JOLTC_API void JPH_Constraint_SetNumPositionStepsOverride(JPH_Constraint *constraint, uint32_t steps);
JOLTC_API void JPH_Constraint_SetEnabled(JPH_Constraint *constraint, bool enabled);
JOLTC_API bool JPH_Constraint_GetEnabled(const JPH_Constraint *constraint);
#ifdef JOLTC_DEBUG_RENDERER
JOLTC_API float JPH_Constraint_GetDrawConstraintSize(const JPH_Constraint *constraint);
JOLTC_API void JPH_Constraint_SetDrawConstraintSize(JPH_Constraint *constraint, float inSize);
#endif
// @Todo
// JOLTC_API JPH_ConstraintSettings *JPH_Constraint_GetConstraintSettings(const JPH_Constraint *constraint);

typedef struct JPH_TwoBodyConstraint {
    JPH_Constraint base;
} JPH_TwoBodyConstraint;

JOLTC_API JPH_Body *JPH_TwoBodyConstraint_GetBody1(const JPH_TwoBodyConstraint *constraint);
JOLTC_API JPH_Body *JPH_TwoBodyConstraint_GetBody2(const JPH_TwoBodyConstraint *constraint);

typedef struct JPH_ConeConstraint {
    JPH_TwoBodyConstraint base;
} JPH_ConeConstraint;

JOLTC_API void JPH_ConeConstraint_SetHalfConeAngle(JPH_ConeConstraint *constraint, float halfConeAngle);
JOLTC_API float JPH_ConeConstraint_GetCosHalfConeAngle(const JPH_ConeConstraint *constraint);

typedef struct JPH_DistanceConstraint {
    JPH_TwoBodyConstraint base;
} JPH_DistanceConstraint;

JOLTC_API void JPH_DistanceConstraint_SetDistance(JPH_DistanceConstraint *constraint, float minDistance, float maxDistance);
JOLTC_API float JPH_DistanceConstraint_GetMinDistance(const JPH_DistanceConstraint *constraint);
JOLTC_API float JPH_DistanceConstraint_GetMaxDistance(const JPH_DistanceConstraint *constraint);
JOLTC_API const JPH_SpringSettings *JPH_DistanceConstraint_GetLimitsSpringSettingsConst(const JPH_DistanceConstraint *constraint);
JOLTC_API JPH_SpringSettings *JPH_DistanceConstraint_GetLimitsSpringSettings(JPH_DistanceConstraint *constraint);
JOLTC_API void JPH_DistanceConstraint_SetLimitsSpringSettings(JPH_DistanceConstraint *constraint, const JPH_SpringSettings *limitsSpringSettings);

typedef struct JPH_FixedConstraint {
    JPH_TwoBodyConstraint base;
} JPH_FixedConstraint;

typedef struct JPH_GearConstraint {
    JPH_TwoBodyConstraint base;
} JPH_GearConstraint;

JOLTC_API void JPH_GearConstraint_SetConstraints(JPH_GearConstraint *constraint, const JPH_Constraint *gear1, const JPH_Constraint *gear2);

typedef struct JPH_HingeConstraint {
    JPH_TwoBodyConstraint base;
} JPH_HingeConstraint;

JOLTC_API JPH_Vec3 JPH_HingeConstraint_GetLocalSpacePoint1(const JPH_HingeConstraint *constraint);
JOLTC_API JPH_Vec3 JPH_HingeConstraint_GetLocalSpacePoint2(const JPH_HingeConstraint *constraint);
JOLTC_API JPH_Vec3 JPH_HingeConstraint_GetLocalSpaceHingeAxis1(const JPH_HingeConstraint *constraint);
JOLTC_API JPH_Vec3 JPH_HingeConstraint_GetLocalSpaceHingeAxis2(const JPH_HingeConstraint *constraint);
JOLTC_API JPH_Vec3 JPH_HingeConstraint_GetLocalSpaceNormalAxis1(const JPH_HingeConstraint *constraint);
JOLTC_API JPH_Vec3 JPH_HingeConstraint_GetLocalSpaceNormalAxis2(const JPH_HingeConstraint *constraint);
JOLTC_API float JPH_HingeConstraint_GetCurrentAngle(const JPH_HingeConstraint *constraint);
JOLTC_API void JPH_HingeConstraint_SetMaxFrictionTorque(JPH_HingeConstraint *constraint, float frictionTorque);
JOLTC_API float JPH_HingeConstraint_GetMaxFrictionTorque(const JPH_HingeConstraint *constraint);
JOLTC_API const JPH_MotorSettings *JPH_HingeConstraint_GetMotorSettingsConst(const JPH_HingeConstraint *constraint);
JOLTC_API JPH_MotorSettings *JPH_HingeConstraint_GetMotorSettings(JPH_HingeConstraint *constraint);
JOLTC_API void JPH_HingeConstraint_SetMotorState(JPH_HingeConstraint *constraint, JPH_EMotorState state);
JOLTC_API JPH_EMotorState JPH_HingeConstraint_GetMotorState(const JPH_HingeConstraint *constraint);
JOLTC_API void JPH_HingeConstraint_SetTargetAngularVelocity(JPH_HingeConstraint *constraint, float angularVelocity);
JOLTC_API float JPH_HingeConstraint_GetTargetAngularVelocity(const JPH_HingeConstraint *constraint);
JOLTC_API void JPH_HingeConstraint_SetTargetAngle(JPH_HingeConstraint *constraint, float angle);
JOLTC_API float JPH_HingeConstraint_GetTargetAngle(const JPH_HingeConstraint *constraint);
JOLTC_API void JPH_HingeConstraint_SetTargetOrientationBS(JPH_HingeConstraint *constraint, JPH_Quat orientation);
JOLTC_API void JPH_HingeConstraint_SetLimits(JPH_HingeConstraint *constraint, float limitsMin, float limitsMax);
JOLTC_API float JPH_HingeConstraint_GetLimitsMin(const JPH_HingeConstraint *constraint);
JOLTC_API float JPH_HingeConstraint_GetLimitsMax(const JPH_HingeConstraint *constraint);
JOLTC_API bool JPH_HingeConstraint_HasLimits(const JPH_HingeConstraint *constraint);
JOLTC_API const JPH_SpringSettings *JPH_HingeConstraint_GetLimitsSpringSettingsConst(const JPH_HingeConstraint *constraint);
JOLTC_API JPH_SpringSettings *JPH_HingeConstraint_GetLimitsSpringSettings(JPH_HingeConstraint *constraint);
JOLTC_API void JPH_HingeConstraint_SetLimitsSpringSettings(JPH_HingeConstraint *constraint, JPH_SpringSettings *limitsSpringSettings);

typedef struct JPH_PathConstraint {
    JPH_TwoBodyConstraint base;
} JPH_PathConstraint;

JOLTC_API void JPH_PathConstraint_SetPath(JPH_PathConstraint *constraint, const JPH_PathConstraintPath *path, float pathFraction);
JOLTC_API const JPH_PathConstraintPath *JPH_PathConstraint_GetPath(const JPH_PathConstraint *constraint);
JOLTC_API float JPH_PathConstraint_GetPathFraction(const JPH_PathConstraint *constraint);
JOLTC_API void JPH_PathConstraint_SetMaxFrictionForce(JPH_PathConstraint *constraint, float frictionForce);
JOLTC_API float JPH_PathConstraint_GetMaxFrictionForce(const JPH_PathConstraint *constraint);
JOLTC_API const JPH_MotorSettings *JPH_PathConstraint_GetPositionMotorSettingsConst(const JPH_PathConstraint *constraint);
JOLTC_API JPH_MotorSettings *JPH_PathConstraint_GetPositionMotorSettings(JPH_PathConstraint *constraint);
JOLTC_API void JPH_PathConstraint_SetPositionMotorState(JPH_PathConstraint *constraint, JPH_EMotorState state);
JOLTC_API JPH_EMotorState JPH_PathConstraint_GetPositionMotorState(const JPH_PathConstraint *constraint);
JOLTC_API void JPH_PathConstraint_SetTargetVelocity(JPH_PathConstraint *constraint, float velocity);
JOLTC_API float JPH_PathConstraint_GetTargetVelocity(const JPH_PathConstraint *constraint);
JOLTC_API void JPH_PathConstraint_SetTargetPathFraction(JPH_PathConstraint *constraint, float fraction);
JOLTC_API float JPH_PathConstraint_GetTargetPathFraction(const JPH_PathConstraint *constraint);

typedef struct JPH_PointConstraint {
    JPH_TwoBodyConstraint base;
} JPH_PointConstraint;

JOLTC_API void JPH_PointConstraint_SetPoint1(JPH_PointConstraint *constraint, JPH_EConstraintSpace space, JPH_RVec3 point1);
JOLTC_API void JPH_PointConstraint_SetPoint2(JPH_PointConstraint *constraint, JPH_EConstraintSpace space, JPH_RVec3 point2);
JOLTC_API JPH_Vec3 JPH_PointConstraint_GetLocalSpacePoint1(const JPH_PointConstraint *constraint);
JOLTC_API JPH_Vec3 JPH_PointConstraint_GetLocalSpacePoint2(const JPH_PointConstraint *constraint);

typedef struct JPH_PulleyConstraint {
    JPH_TwoBodyConstraint base;
} JPH_PulleyConstraint;

JOLTC_API void JPH_PulleyConstraint_SetLength(JPH_PulleyConstraint *constraint, float minLength, float maxLength);
JOLTC_API float JPH_PulleyConstraint_GetMinLength(const JPH_PulleyConstraint *constraint);
JOLTC_API float JPH_PulleyConstraint_GetMaxLength(const JPH_PulleyConstraint *constraint);
JOLTC_API float JPH_PulleyConstraint_GetCurrentLength(const JPH_PulleyConstraint *constraint);

typedef struct JPH_RackAndPinionConstraint {
    JPH_TwoBodyConstraint base;
} JPH_RackAndPinionConstraint;

JOLTC_API void JPH_RackAndPinionConstraint_SetConstraints(JPH_RackAndPinionConstraint *constraints, const JPH_Constraint *pinion, const JPH_Constraint *rack);

typedef struct JPH_SixDOFConstraint {
    JPH_TwoBodyConstraint base;
} JPH_SixDOFConstraint;

JOLTC_API void JPH_SixDOFConstraint_SetTranslationLimits(JPH_SixDOFConstraint *constraint, JPH_Vec3 limitMin, JPH_Vec3 limitMax);
JOLTC_API void JPH_SixDOFConstraint_SetRotationLimits(JPH_SixDOFConstraint *constraint, JPH_Vec3 limitMin, JPH_Vec3 limitMax);
JOLTC_API float JPH_SixDOFConstraint_GetLimitsMin(const JPH_SixDOFConstraint *constraint, JPH_SixDOFConstraintSettings_EAxis axis);
JOLTC_API float JPH_SixDOFConstraint_GetLimitsMax(const JPH_SixDOFConstraint *constraint, JPH_SixDOFConstraintSettings_EAxis axis);
JOLTC_API JPH_Vec3 JPH_SixDOFConstraint_GetTranslationLimitsMin(const JPH_SixDOFConstraint *constraint);
JOLTC_API JPH_Vec3 JPH_SixDOFConstraint_GetTranslationLimitsMax(const JPH_SixDOFConstraint *constraint);
JOLTC_API JPH_Vec3 JPH_SixDOFConstraint_GetRotationLimitsMin(const JPH_SixDOFConstraint *constraint);
JOLTC_API JPH_Vec3 JPH_SixDOFConstraint_GetRotationLimitsMax(const JPH_SixDOFConstraint *constraint);
JOLTC_API bool JPH_SixDOFConstraint_IsFixedAxis(const JPH_SixDOFConstraint *constraint, JPH_SixDOFConstraintSettings_EAxis axis);
JOLTC_API bool JPH_SixDOFConstraint_IsFreeAxis(const JPH_SixDOFConstraint *constraint, JPH_SixDOFConstraintSettings_EAxis axis);
JOLTC_API const JPH_SpringSettings *JPH_SixDOFConstraint_GetLimitsSpringSettings(const JPH_SixDOFConstraint *constraint, JPH_SixDOFConstraintSettings_EAxis axis);
JOLTC_API void JPH_SixDOFConstraint_SetLimitsSpringSettings(JPH_SixDOFConstraint *constraint, JPH_SixDOFConstraintSettings_EAxis axis, const JPH_SpringSettings *limitsSpringSettings);
JOLTC_API void JPH_SixDOFConstraint_SetMaxFriction(JPH_SixDOFConstraint *constraint, JPH_SixDOFConstraintSettings_EAxis axis, float friction);
JOLTC_API float JPH_SixDOFConstraint_GetMaxFriction(const JPH_SixDOFConstraint *constraint, JPH_SixDOFConstraintSettings_EAxis axis);
JOLTC_API JPH_Quat JPH_SixDOFConstraint_GetRotationInConstraintSpace(const JPH_SixDOFConstraint *constraint);
JOLTC_API JPH_MotorSettings *JPH_SixDOFConstraint_GetMotorSettings(JPH_SixDOFConstraint *constraint, JPH_SixDOFConstraintSettings_EAxis axis);
JOLTC_API const JPH_MotorSettings *JPH_SixDOFConstraint_GetMotorSettingsConst(const JPH_SixDOFConstraint *constraint, JPH_SixDOFConstraintSettings_EAxis axis);
JOLTC_API void JPH_SixDOFConstraint_SetMotorState(JPH_SixDOFConstraint *constraint, JPH_SixDOFConstraintSettings_EAxis axis, JPH_EMotorState state);
JOLTC_API JPH_EMotorState JPH_SixDOFConstraint_GetMotorState(const JPH_SixDOFConstraint *constraint, JPH_SixDOFConstraintSettings_EAxis axis);
JOLTC_API JPH_Vec3 JPH_SixDOFConstraint_GetTargetVelocityCS(const JPH_SixDOFConstraint *constraint);
JOLTC_API void JPH_SixDOFConstraint_SetTargetVelocityCS(JPH_SixDOFConstraint *constraint, JPH_Vec3 velocity);
JOLTC_API void JPH_SixDOFConstraint_SetTargetAngularVelocityCS(JPH_SixDOFConstraint *constraint, JPH_Vec3 angularVelocity);
JOLTC_API JPH_Vec3 JPH_SixDOFConstraint_GetTargetAngularVelocityCS(const JPH_SixDOFConstraint *constraint);
JOLTC_API JPH_Vec3 JPH_SixDOFConstraint_GetTargetPositionCS(const JPH_SixDOFConstraint *constraint);
JOLTC_API void JPH_SixDOFConstraint_SetTargetPositionCS(JPH_SixDOFConstraint *constraint, JPH_Vec3 position);
JOLTC_API void JPH_SixDOFConstraint_SetTargetOrientationCS(JPH_SixDOFConstraint *constraint, JPH_Quat prientation);
JOLTC_API JPH_Quat JPH_SixDOFConstraint_GetTargetOrientationCS(const JPH_SixDOFConstraint *constraint);
JOLTC_API void JPH_SixDOFConstraint_SetTargetOrientationBS(JPH_SixDOFConstraint *constraint, JPH_Quat orientation);

typedef struct JPH_SliderConstraint {
    JPH_TwoBodyConstraint base;
} JPH_SliderConstraint;

JOLTC_API float JPH_SliderConstraint_GetCurrentPosition(const JPH_SliderConstraint *constraint);
JOLTC_API void JPH_SliderConstraint_SetMaxFrictionForce(JPH_SliderConstraint *constraint, float frictionForce);
JOLTC_API float JPH_SliderConstraint_GetMaxFrictionForce(const JPH_SliderConstraint *constraint);
JOLTC_API JPH_MotorSettings *JPH_SliderConstraint_GetMotorSettings(JPH_SliderConstraint *constraint);
JOLTC_API const JPH_MotorSettings *JPH_SliderConstraint_GetMotorSettingsConst(const JPH_SliderConstraint *constraint);
JOLTC_API void JPH_SliderConstraint_SetMotorState(JPH_SliderConstraint *constraint, JPH_EMotorState state);
JOLTC_API JPH_EMotorState JPH_SliderConstraint_GetMotorState(const JPH_SliderConstraint *constraint);
JOLTC_API void JPH_SliderConstraint_SetTargetVelocity(JPH_SliderConstraint *constraint, float velocity);
JOLTC_API float JPH_SliderConstraint_GetTargetVelocity(const JPH_SliderConstraint *constraint);
JOLTC_API void JPH_SliderConstraint_SetTargetPosition(JPH_SliderConstraint *constraint, float position);
JOLTC_API float JPH_SliderConstraint_GetTargetPosition(const JPH_SliderConstraint *constraint);
JOLTC_API void JPH_SliderConstraint_SetLimits(JPH_SliderConstraint *constraint, float limitsMin, float limitsMax);
JOLTC_API float JPH_SliderConstraint_GetLimitsMin(const JPH_SliderConstraint *constraint);
JOLTC_API float JPH_SliderConstraint_GetLimitsMax(const JPH_SliderConstraint *constraint);
JOLTC_API bool JPH_SliderConstraint_HasLimits(const JPH_SliderConstraint *constraint);
JOLTC_API const JPH_SpringSettings *JPH_SliderConstraint_GetLimitsSpringSettingsConst(const JPH_SliderConstraint *constraint);
JOLTC_API JPH_SpringSettings *JPH_SliderConstraint_GetLimitsSpringSettings(JPH_SliderConstraint *constraint);
JOLTC_API void JPH_SliderConstraint_SetLimitsSpringSettings(JPH_SliderConstraint *constraint, const JPH_SpringSettings *limitsSpringSettings);

typedef struct JPH_SwingTwistConstraint {
    JPH_TwoBodyConstraint base;
} JPH_SwingTwistConstraint;

JPH_Vec3 JPH_SwingTwistConstraint_GetLocalSpacePosition1(const JPH_SwingTwistConstraint *constraint);
JPH_Vec3 JPH_SwingTwistConstraint_GetLocalSpacePosition2(const JPH_SwingTwistConstraint *constraint);
JPH_Quat JPH_SwingTwistConstraint_GetConstraintToBody1(const JPH_SwingTwistConstraint *constraint);
JPH_Quat JPH_SwingTwistConstraint_GetConstraintToBody2(const JPH_SwingTwistConstraint *constraint);
float JPH_SwingTwistConstraint_GetNormalHalfConeAngle(const JPH_SwingTwistConstraint *constraint);
void JPH_SwingTwistConstraint_SetNormalHalfConeAngle(JPH_SwingTwistConstraint *constraint, float angle);
float JPH_SwingTwistConstraint_GetPlaneHalfConeAngle(const JPH_SwingTwistConstraint *constraint);
void JPH_SwingTwistConstraint_SetPlaneHalfConeAngle(JPH_SwingTwistConstraint *constraint, float angle);
float JPH_SwingTwistConstraint_GetTwistMinAngle(const JPH_SwingTwistConstraint *constraint);
void JPH_SwingTwistConstraint_SetTwistMinAngle(JPH_SwingTwistConstraint *constraint, float angle);
float JPH_SwingTwistConstraint_GetTwistMaxAngle(const JPH_SwingTwistConstraint *constraint);
void JPH_SwingTwistConstraint_SetTwistMaxAngle(JPH_SwingTwistConstraint *constraint, float angle);
const JPH_MotorSettings *JPH_SwingTwistConstraint_GetSwingMotorSettingsConst(const JPH_SwingTwistConstraint *constraint);
JPH_MotorSettings *JPH_SwingTwistConstraint_GetSwingMotorSettings(JPH_SwingTwistConstraint *constraint);
const JPH_MotorSettings *JPH_SwingTwistConstraint_GetTwistMotorSettingsConst(const JPH_SwingTwistConstraint *constraint);
JPH_MotorSettings *JPH_SwingTwistConstraint_GetTwistMotorSettings(JPH_SwingTwistConstraint *constraint);
void JPH_SwingTwistConstraint_SetMaxFrictionTorque(JPH_SwingTwistConstraint *constraint, float frictionTorque);
float JPH_SwingTwistConstraint_GetMaxFrictionTorque(const JPH_SwingTwistConstraint *constraint);
void JPH_SwingTwistConstraint_SetSwingMotorState(JPH_SwingTwistConstraint *constraint, JPH_EMotorState state);
JPH_EMotorState JPH_SwingTwistConstraint_GetSwingMotorState(const JPH_SwingTwistConstraint *constraint);
void JPH_SwingTwistConstraint_SetTwistMotorState(JPH_SwingTwistConstraint *constraint, JPH_EMotorState state);
JPH_EMotorState JPH_SwingTwistConstraint_GetTwistMotorState(const JPH_SwingTwistConstraint *constraint);
void JPH_SwingTwistConstraint_SetTargetAngularVelocityCS(JPH_SwingTwistConstraint *constraint, JPH_Vec3 angularVelocity);
JPH_Vec3 JPH_SwingTwistConstraint_GetTargetAngularVelocityCS(const JPH_SwingTwistConstraint *constraint);
void JPH_SwingTwistConstraint_SetTargetAngularVelocityBS(JPH_SwingTwistConstraint *constraint, JPH_Vec3 angularVelocity);
void JPH_SwingTwistConstraint_SetTargetOrientationCS(JPH_SwingTwistConstraint *constraint, JPH_Quat orientation);
JPH_Quat JPH_SwingTwistConstraint_GetTargetOrientationCS(const JPH_SwingTwistConstraint *constraint);
void JPH_SwingTwistConstraint_SetTargetOrientationBS(JPH_SwingTwistConstraint *constraint, JPH_Quat orientation);
JPH_Quat JPH_SwingTwistConstraint_GetRotationInConstraintSpace(const JPH_SwingTwistConstraint *constraint);
