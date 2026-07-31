#pragma once

#include <JoltC_Core.h>
#include <JoltC_Body.h>

#ifdef JOLTC_DEBUG_RENDERER
#include <JoltC_DebugRenderer.h>
#endif

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

typedef struct JPH_Constraint {
    char opaque;
} JPH_Constraint;

typedef struct JPH_TwoBodyConstraint {
    JPH_Constraint base;
} JPH_TwoBodyConstraint;

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

typedef struct JPH_MotorSettings {
    JPH_SpringSettings springSettings;
    float minForceLimit;
    float maxForceLimit;
    float minTorqueLimit;
    float maxTorqueLimit;
} JPH_MotorSettings;

#define JPH_ConstraintSettings_cDefaultDrawConstraintSize 1.0f

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

JOLTC_API JPH_TwoBodyConstraint *JPH_ConeConstraintSettings_CreateConstraint(const JPH_ConeConstraintSettings *settings, JPH_Body *body1, JPH_Body *body2);

typedef struct JPH_DistanceConstraintSettings {
    JPH_TwoBodyConstraintSettings base;
    JPH_EConstraintSpace space;
    JPH_RVec3 point1;
    JPH_RVec3 point2;
    float minDistance;
    float maxDistance;
    JPH_SpringSettings limitsSpringSettings;
} JPH_DistanceConstraintSettings;

JOLTC_API JPH_TwoBodyConstraint *JPH_DistanceConstraintSettings_CreateConstraint(const JPH_DistanceConstraintSettings *settings, JPH_Body *body1, JPH_Body *body2);

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

JOLTC_API JPH_TwoBodyConstraint *JPH_FixedConstraintSettings_CreateConstraint(const JPH_FixedConstraintSettings *settings, JPH_Body *body1, JPH_Body *body2);

typedef struct JPH_GearConstraintSettings {
    JPH_TwoBodyConstraintSettings base;
    JPH_EConstraintSpace space;
    JPH_Vec3 hingeAxis1;
    JPH_Vec3 hingeAxis2;
    float ratio;
} JPH_GearConstraintSettings;

JOLTC_API JPH_TwoBodyConstraint *JPH_GearConstraintSettings_CreateConstraint(const JPH_GearConstraintSettings *settings, JPH_Body *body1, JPH_Body *body2);

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

JOLTC_API JPH_TwoBodyConstraint *JPH_HingeConstraintSettings_CreateConstraint(const JPH_HingeConstraintSettings *settings, JPH_Body *body1, JPH_Body *body2);

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

JOLTC_API JPH_TwoBodyConstraint *JPH_PathConstraintSettings_CreateConstraint(const JPH_PathConstraintSettings *settings, JPH_Body *body1, JPH_Body *body2);

typedef struct JPH_PointConstraintSettings {
    JPH_TwoBodyConstraintSettings base;
    JPH_EConstraintSpace space;
    JPH_RVec3 point1;
    JPH_RVec3 point2;
} JPH_PointConstraintSettings;

JOLTC_API JPH_TwoBodyConstraint *JPH_PointConstraintSettings_CreateConstraint(const JPH_PointConstraintSettings *settings, JPH_Body *body1, JPH_Body *body2);

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

JOLTC_API JPH_TwoBodyConstraint *JPH_PulleyConstraintSettings_CreateConstraint(const JPH_PulleyConstraintSettings *settings, JPH_Body *body1, JPH_Body *body2);

typedef struct JPH_RackAndPinionConstraintSettings {
    JPH_TwoBodyConstraintSettings base;
    JPH_EConstraintSpace space;
    JPH_Vec3 hingeAxis;
    JPH_Vec3 sliderAxis;
    float ratio;
} JPH_RackAndPinionConstraintSettings;

JOLTC_API JPH_TwoBodyConstraint *JPH_RackAndPinionConstraintSettings_CreateConstraint(const JPH_RackAndPinionConstraintSettings *settings, JPH_Body *body1, JPH_Body *body2);

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

JOLTC_API JPH_TwoBodyConstraint *JPH_SixDOFConstraintSettings_CreateConstraint(const JPH_SixDOFConstraintSettings *settings, JPH_Body *body1, JPH_Body *body2);
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

JOLTC_API JPH_TwoBodyConstraint *JPH_SliderConstraintSettings_CreateConstraint(const JPH_SliderConstraintSettings *settings, JPH_Body *body1, JPH_Body *body2);

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

JOLTC_API JPH_TwoBodyConstraint *JPH_JPH_SwingTwistConstraintSettings_CreateConstraint(const JPH_SwingTwistConstraintSettings *settings, JPH_Body *body1, JPH_Body *body2);
