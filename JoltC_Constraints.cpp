#include <JoltC.hpp>

JOLTC_SUPPRESS_WARNINGS()

static inline
void SetConstraintSettings(JPH::ConstraintSettings &cppSettings, const JPH_ConstraintSettings *settings) {
    cppSettings.mEnabled = settings->enabled;
    cppSettings.mConstraintPriority = settings->constraintPriority;
    cppSettings.mNumVelocityStepsOverride = settings->numVelocityStepsOverride;
    cppSettings.mNumPositionStepsOverride = settings->numPositionStepsOverride;
    cppSettings.mDrawConstraintSize = settings->drawConstraintSize;
    cppSettings.mUserData = settings->userData;
}

JPH_SpringSettings JPH_SpringSettings_Default() {
    return JPH_SpringSettings{
        .mode=JPH_ESpringMode_FrequencyAndDamping,
        .frequency=0.0f,
        .damping=0.0f,
    };
}

JPH_SpringSettings JPH_SpringSettings_Make(JPH_ESpringMode mode, float frequencyOrStiffness, float damping) {
    return JPH_SpringSettings{
        .mode=mode,
        .frequency=frequencyOrStiffness,
        .damping=damping,
    };
}

JPH_MotorSettings JPH_MotorSettings_Default() {
    return JPH_MotorSettings{
        .springSettings=JPH_SpringSettings_Make(JPH_ESpringMode_FrequencyAndDamping, 2.0f, 1.0f),
        .minForceLimit=-FLT_MAX,
        .maxForceLimit=FLT_MAX,
        .minTorqueLimit=-FLT_MAX,
        .maxTorqueLimit=FLT_MAX,
    };
}

static inline
JPH_ConstraintSettings JPH_ConstraintSettings_Default() {
    return JPH_ConstraintSettings{
        .enabled=true,
        .constraintPriority=0,
        .numVelocityStepsOverride=0,
        .numPositionStepsOverride=0,
        .drawConstraintSize=1.0f,
        .userData=0,
    };
}

static inline
JPH_TwoBodyConstraintSettings JPH_TwoBodyConstraintSettings_Default() {
    return JPH_TwoBodyConstraintSettings{
        .base=JPH_ConstraintSettings_Default(),
    };
}

JPH_ConeConstraintSettings JPH_ConeConstraintSettings_Default() {
    return JPH_ConeConstraintSettings{
        .base=JPH_TwoBodyConstraintSettings_Default(),
        .space=JPH_EConstraintSpace_WorldSpace,
        .point1=JPH_RVec3_Make(0.0, 0.0, 0.0),
        .twistAxis1=JPH_Vec3_Make(1.0f, 0.0f, 0.0f),
        .point2=JPH_RVec3_Make(0.0, 0.0, 0.0),
        .twistAxis2=JPH_Vec3_Make(1.0f, 0.0f, 0.0f),
        .halfConeAngle=0.0f,
    };
}

JPH_TwoBodyConstraint *JPH_ConeConstraintSettings_CreateConstraint(const JPH_ConeConstraintSettings *settings, JPH_Body *body1, JPH_Body *body2) {
    auto cppSettings = JPH::ConeConstraintSettings();
    SetConstraintSettings(cppSettings, &settings->base.base);
    cppSettings.mSpace = static_cast<JPH::EConstraintSpace>(settings->space);
    cppSettings.mPoint1 = ToCpp(settings->point1);
    cppSettings.mTwistAxis1 = ToCpp(settings->twistAxis1);
    cppSettings.mPoint2 = ToCpp(settings->point2);
    cppSettings.mTwistAxis2 = ToCpp(settings->twistAxis2);
    cppSettings.mHalfConeAngle = settings->halfConeAngle;

    return ToC(cppSettings.Create(*ToCpp(body1), *ToCpp(body2)));
}

JPH_DistanceConstraintSettings JPH_DistanceConstraintSettings_Default() {
    return JPH_DistanceConstraintSettings{
        .base=JPH_TwoBodyConstraintSettings_Default(),
        .space=JPH_EConstraintSpace_WorldSpace,
        .point1=JPH_RVec3_Make(0.0, 0.0, 0.0),
        .point2=JPH_RVec3_Make(0.0, 0.0, 0.0),
        .minDistance=-1.0f,
        .maxDistance=-1.0f,
        .limitsSpringSettings=JPH_SpringSettings_Default(),
    };
}

JPH_TwoBodyConstraint *JPH_DistanceConstraintSettings_CreateConstraint(const JPH_DistanceConstraintSettings *settings, JPH_Body *body1, JPH_Body *body2) {
    auto cppSettings = JPH::DistanceConstraintSettings();
    SetConstraintSettings(cppSettings, &settings->base.base);
    cppSettings.mSpace = static_cast<JPH::EConstraintSpace>(settings->space);
    cppSettings.mPoint1 = ToCpp(settings->point1);
    cppSettings.mPoint2 = ToCpp(settings->point2);
    cppSettings.mMinDistance = settings->minDistance;
    cppSettings.mMaxDistance = settings->maxDistance;
    cppSettings.mLimitsSpringSettings = ToCpp(settings->limitsSpringSettings);

    return ToC(cppSettings.Create(*ToCpp(body1), *ToCpp(body2)));
}

JPH_FixedConstraintSettings JPH_FixedConstraintSettings_Default() {
    return JPH_FixedConstraintSettings{
        .base=JPH_TwoBodyConstraintSettings_Default(),
        .space=JPH_EConstraintSpace_WorldSpace,
        .autoDetectPoint=false,
        .point1=JPH_RVec3_Make(0.0, 0.0, 0.0),
        .axisX1=JPH_Vec3_Make(1.0f, 0.0f, 0.0f),
        .axisY1=JPH_Vec3_Make(0.0f, 1.0f, 0.0f),
        .point2=JPH_RVec3_Make(0.0, 0.0, 0.0),
        .axisX2=JPH_Vec3_Make(1.0f, 0.0f, 0.0f),
        .axisY2=JPH_Vec3_Make(0.0f, 1.0f, 0.0f),
    };
}

JPH_TwoBodyConstraint *JPH_FixedConstraintSettings_CreateConstraint(const JPH_FixedConstraintSettings *settings, JPH_Body *body1, JPH_Body *body2) {
    auto cppSettings = JPH::FixedConstraintSettings();
    SetConstraintSettings(cppSettings, &settings->base.base);
    cppSettings.mSpace = static_cast<JPH::EConstraintSpace>(settings->space);
    cppSettings.mAutoDetectPoint = settings->autoDetectPoint;
    cppSettings.mPoint1 = ToCpp(settings->point1);
    cppSettings.mAxisX1 = ToCpp(settings->axisX1);
    cppSettings.mAxisY1 = ToCpp(settings->axisY1);
    cppSettings.mPoint2 = ToCpp(settings->point2);
    cppSettings.mAxisX2 = ToCpp(settings->axisX2);
    cppSettings.mAxisY2 = ToCpp(settings->axisY2);

    return ToC(cppSettings.Create(*ToCpp(body1), *ToCpp(body2)));
}

JPH_GearConstraintSettings JPH_GearConstraintSettings_Default() {
    return JPH_GearConstraintSettings{
        .base=JPH_TwoBodyConstraintSettings_Default(),
        .space=JPH_EConstraintSpace_WorldSpace,
        .hingeAxis1=JPH_Vec3_Make(1.0f, 0.0f, 0.0f),
        .hingeAxis2=JPH_Vec3_Make(1.0f, 0.0f, 0.0f),
        .ratio=1.0f,
    };
}

JPH_TwoBodyConstraint *JPH_GearConstraintSettings_CreateConstraint(const JPH_GearConstraintSettings *settings, JPH_Body *body1, JPH_Body *body2) {
    auto cppSettings = JPH::GearConstraintSettings();
    SetConstraintSettings(cppSettings, &settings->base.base);
    cppSettings.mSpace = static_cast<JPH::EConstraintSpace>(settings->space);
    cppSettings.mHingeAxis1 = ToCpp(settings->hingeAxis1);
    cppSettings.mHingeAxis2 = ToCpp(settings->hingeAxis2);
    cppSettings.mRatio = settings->ratio;

    return ToC(cppSettings.Create(*ToCpp(body1), *ToCpp(body2)));
}

JPH_HingeConstraintSettings JPH_HingeConstraintSettings_Default() {
    return JPH_HingeConstraintSettings{
        .base=JPH_TwoBodyConstraintSettings_Default(),
        .space=JPH_EConstraintSpace_WorldSpace,
        .point1=JPH_RVec3_Make(0.0, 0.0, 0.0),
        .hingeAxis1=JPH_Vec3_Make(0.0f, 1.0f, 0.0f),
        .normalAxis1=JPH_Vec3_Make(1.0f, 0.0f, 0.0f),
        .point2=JPH_RVec3_Make(0.0, 0.0, 0.0),
        .hingeAxis2=JPH_Vec3_Make(0.0f, 1.0f, 0.0f),
        .normalAxis2=JPH_Vec3_Make(1.0f, 0.0f, 0.0f),
        .limitsMin=-JPH::JPH_PI,
        .limitsMax=JPH::JPH_PI,
        .limitsSpringSettings=JPH_SpringSettings_Default(),
        .maxFrictionTorque=0.0f,
        .motorSettings=JPH_MotorSettings_Default(),
    };
}

JPH_TwoBodyConstraint *JPH_HingeConstraintSettings_CreateConstraint(const JPH_HingeConstraintSettings *settings, JPH_Body *body1, JPH_Body *body2) {
    auto cppSettings = JPH::HingeConstraintSettings();
    SetConstraintSettings(cppSettings, &settings->base.base);
    cppSettings.mSpace = static_cast<JPH::EConstraintSpace>(settings->space);
    cppSettings.mPoint1 = ToCpp(settings->point1);
    cppSettings.mHingeAxis1 = ToCpp(settings->hingeAxis1);
    cppSettings.mNormalAxis1 = ToCpp(settings->normalAxis1);
    cppSettings.mPoint2 = ToCpp(settings->point2);
    cppSettings.mHingeAxis2 = ToCpp(settings->hingeAxis2);
    cppSettings.mNormalAxis2 = ToCpp(settings->normalAxis2);
    cppSettings.mLimitsMin = settings->limitsMin;
    cppSettings.mLimitsMax = settings->limitsMax;
    cppSettings.mLimitsSpringSettings = ToCpp(settings->limitsSpringSettings);
    cppSettings.mMaxFrictionTorque = settings->maxFrictionTorque;
    cppSettings.mMotorSettings = ToCpp(settings->motorSettings);

    return ToC(cppSettings.Create(*ToCpp(body1), *ToCpp(body2)));
}

void JPH_PathConstraintPath_Destroy(JPH_PathConstraintPath *path) {
    delete ToCpp(path);
}

float JPH_PathConstraintPath_GetPathMaxFraction(const JPH_PathConstraintPath *path) {
    return ToCpp(path)->GetPathMaxFraction();
}

float JPH_PathConstraintPath_GetClosestPoint(const JPH_PathConstraintPath *path, JPH_Vec3 position, float fractionHint) {
    return ToCpp(path)->GetClosestPoint(ToCpp(position), fractionHint);
}

void JPH_PathConstraintPath_GetPointOnPath(const JPH_PathConstraintPath *path, float fraction, JPH_Vec3 *outPathPosition, JPH_Vec3 *outPathTangent, JPH_Vec3 *outPathNormal, JPH_Vec3 *outPathBinormal) {
    ToCpp(path)->GetPointOnPath(fraction, *ToCpp(outPathPosition), *ToCpp(outPathTangent), *ToCpp(outPathNormal), *ToCpp(outPathBinormal));
}

void JPH_PathConstraintPath_SetIsLooping(JPH_PathConstraintPath *path, bool isLooping) {
    ToCpp(path)->SetIsLooping(isLooping);
}

bool JPH_PathConstraintPath_IsLooping(const JPH_PathConstraintPath *path) {
    return ToCpp(path)->IsLooping();
}

#ifdef JOLTC_DEBUG_RENDERER
void JPH_PathConstraintPath_DrawPath(const JPH_PathConstraintPath *path, JPH_DebugRenderer *renderer, JPH_RMat44 baseTransform) {
    ToCpp(path)->DrawPath(ToCpp(renderer), ToCpp(baseTransform));
}
#endif

JPH_PathConstraintPathHermite *JPH_PathConstraintPathHermite_Create() {
    return ToC(new JPH::PathConstraintPathHermite);
}

void JPH_PathConstraintPathHermite_AddPoint(JPH_PathConstraintPathHermite *path, JPH_Vec3 position, JPH_Vec3 tangent, JPH_Vec3 normal) {
    ToCpp(path)->AddPoint(ToCpp(position), ToCpp(tangent), ToCpp(normal));
}

JPH_PathConstraintSettings JPH_PathConstraintSettings_Default() {
    return JPH_PathConstraintSettings{
        .base=JPH_TwoBodyConstraintSettings_Default(),
        .path=nullptr,
        .pathPosition=JPH_Vec3_Make(0.0f, 0.0f, 0.0f),
        .pathRotation=JPH_Quat_sIdentity,
        .pathFraction=0.0f,
        .maxFrictionForce=0.0f,
        .positionMotorSettings=JPH_MotorSettings_Default(),
        .rotationConstraintType=JPH_EPathRotationConstraintType_Free,
    };
}

JPH_TwoBodyConstraint *JPH_PathConstraintSettings_CreateConstraint(const JPH_PathConstraintSettings *settings, JPH_Body *body1, JPH_Body *body2) {
    auto cppSettings = JPH::PathConstraintSettings();
    SetConstraintSettings(cppSettings, &settings->base.base);
    cppSettings.mPath = ToCpp(settings->path);
    cppSettings.mPathPosition = ToCpp(settings->pathPosition);
    cppSettings.mPathRotation = ToCpp(settings->pathRotation);
    cppSettings.mPathFraction = settings->pathFraction;
    cppSettings.mMaxFrictionForce = settings->maxFrictionForce;
    cppSettings.mPositionMotorSettings = ToCpp(settings->positionMotorSettings);
    cppSettings.mRotationConstraintType = static_cast<JPH::EPathRotationConstraintType>(settings->rotationConstraintType);

    return ToC(cppSettings.Create(*ToCpp(body1), *ToCpp(body2)));
}

JPH_PointConstraintSettings JPH_PointConstraintSettings_Default() {
    return JPH_PointConstraintSettings{
        .base=JPH_TwoBodyConstraintSettings_Default(),
        .space=JPH_EConstraintSpace_WorldSpace,
        .point1=JPH_RVec3_Make(0.0, 0.0, 0.0),
        .point2=JPH_RVec3_Make(0.0, 0.0, 0.0),
    };
}

JPH_TwoBodyConstraint *JPH_PointConstraintSettings_CreateConstraint(const JPH_PointConstraintSettings *settings, JPH_Body *body1, JPH_Body *body2) {
    auto cppSettings = JPH::PointConstraintSettings();
    SetConstraintSettings(cppSettings, &settings->base.base);
    cppSettings.mSpace = static_cast<JPH::EConstraintSpace>(settings->space);
    cppSettings.mPoint1 = ToCpp(settings->point1);
    cppSettings.mPoint2 = ToCpp(settings->point2);

    return ToC(cppSettings.Create(*ToCpp(body1), *ToCpp(body2)));
}

JPH_PulleyConstraintSettings JPH_PulleyConstraintSettings_Default() {
    return JPH_PulleyConstraintSettings{
        .base=JPH_TwoBodyConstraintSettings_Default(),
        .space=JPH_EConstraintSpace_WorldSpace,
        .bodyPoint1=JPH_RVec3_Make(0.0, 0.0, 0.0),
        .fixedPoint1=JPH_RVec3_Make(0.0, 0.0, 0.0),
        .bodyPoint2=JPH_RVec3_Make(0.0, 0.0, 0.0),
        .fixedPoint2=JPH_RVec3_Make(0.0, 0.0, 0.0),
        .ratio=1.0f,
        .minLength=0.0f,
        .maxLength=-1.0f,
    };
}

JPH_TwoBodyConstraint *JPH_PulleyConstraintSettings_CreateConstraint(const JPH_PulleyConstraintSettings *settings, JPH_Body *body1, JPH_Body *body2) {
    auto cppSettings = JPH::PulleyConstraintSettings();
    SetConstraintSettings(cppSettings, &settings->base.base);
    cppSettings.mBodyPoint1 = ToCpp(settings->bodyPoint1);
    cppSettings.mFixedPoint1 = ToCpp(settings->fixedPoint1);
    cppSettings.mBodyPoint2 = ToCpp(settings->bodyPoint2);
    cppSettings.mFixedPoint2 = ToCpp(settings->fixedPoint2);
    cppSettings.mRatio = settings->ratio;
    cppSettings.mMinLength = settings->minLength;
    cppSettings.mMaxLength = settings->maxLength;

    return ToC(cppSettings.Create(*ToCpp(body1), *ToCpp(body2)));
}

JPH_RackAndPinionConstraintSettings JPH_RackAndPinionConstraintSettings_Default() {
    return JPH_RackAndPinionConstraintSettings{
        .base=JPH_TwoBodyConstraintSettings_Default(),
        .space=JPH_EConstraintSpace_WorldSpace,
        .hingeAxis=JPH_Vec3_Make(1.0f, 0.0f, 0.0f),
        .sliderAxis=JPH_Vec3_Make(1.0f, 0.0f, 0.0f),
        .ratio=1.0f,
    };
}

JPH_TwoBodyConstraint *JPH_RackAndPinionConstraintSettings_CreateConstraint(const JPH_RackAndPinionConstraintSettings *settings, JPH_Body *body1, JPH_Body *body2) {
    auto cppSettings = JPH::RackAndPinionConstraintSettings();
    SetConstraintSettings(cppSettings, &settings->base.base);
    cppSettings.mSpace = static_cast<JPH::EConstraintSpace>(settings->space);
    cppSettings.mHingeAxis = ToCpp(settings->hingeAxis);
    cppSettings.mSliderAxis = ToCpp(settings->sliderAxis);
    cppSettings.mRatio = settings->ratio;

    return ToC(cppSettings.Create(*ToCpp(body1), *ToCpp(body2)));
}

JPH_SixDOFConstraintSettings JPH_SixDOFConstraintSettings_Default() {
    return JPH_SixDOFConstraintSettings{
        .base=JPH_TwoBodyConstraintSettings_Default(),
        .space=JPH_EConstraintSpace_WorldSpace,
        .position1=JPH_RVec3_Make(0.0, 0.0, 0.0),
        .axisX1=JPH_Vec3_Make(1.0f, 0.0f, 0.0f),
        .axisY1=JPH_Vec3_Make(0.0f, 1.0f, 0.0f),
        .position2=JPH_RVec3_Make(0.0, 0.0, 0.0),
        .axisX2=JPH_Vec3_Make(1.0f, 0.0f, 0.0f),
        .axisY2=JPH_Vec3_Make(0.0f, 1.0f, 0.0f),
        .maxFriction={ 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f },
        .swingType=JPH_ESwingType_Cone,
        .limitMin={-FLT_MAX, -FLT_MAX, -FLT_MAX, -FLT_MAX, -FLT_MAX, -FLT_MAX},
        .limitMax={ FLT_MAX,  FLT_MAX,  FLT_MAX,  FLT_MAX,  FLT_MAX,  FLT_MAX},
        .limitsSpringSettings={ JPH_SpringSettings_Default(),  JPH_SpringSettings_Default(),  JPH_SpringSettings_Default() },
        .motorSettings={ JPH_MotorSettings_Default(),  JPH_MotorSettings_Default(),  JPH_MotorSettings_Default() },
    };
}

JPH_TwoBodyConstraint *JPH_SixDOFConstraintSettings_CreateConstraint(const JPH_SixDOFConstraintSettings *settings, JPH_Body *body1, JPH_Body *body2) {
    auto cppSettings = JPH::SixDOFConstraintSettings();
    SetConstraintSettings(cppSettings, &settings->base.base);
    cppSettings.mSpace = static_cast<JPH::EConstraintSpace>(settings->space);
    cppSettings.mPosition1 = ToCpp(settings->position1);
    cppSettings.mAxisX1 = ToCpp(settings->axisX1);
    cppSettings.mAxisY1 = ToCpp(settings->axisY1);
    cppSettings.mPosition2 = ToCpp(settings->position2);
    cppSettings.mAxisX2 = ToCpp(settings->axisX2);
    cppSettings.mAxisY2 = ToCpp(settings->axisY2);
    cppSettings.mSwingType = static_cast<JPH::ESwingType>(settings->swingType);
    memcpy(cppSettings.mMaxFriction, settings->maxFriction, sizeof(settings->maxFriction));
    memcpy(cppSettings.mLimitMin, settings->limitMin, sizeof(settings->limitMin));
    memcpy(cppSettings.mLimitMax, settings->limitMax, sizeof(settings->limitMax));
    memcpy(cppSettings.mLimitsSpringSettings, settings->limitsSpringSettings, sizeof(settings->limitsSpringSettings));
    memcpy(cppSettings.mMotorSettings, settings->motorSettings, sizeof(settings->motorSettings));

    return ToC(cppSettings.Create(*ToCpp(body1), *ToCpp(body2)));
}

void JPH_SixDOFConstraintSettings_MakeFreeAxis(JPH_SixDOFConstraintSettings *settings, JPH_SixDOFConstraintSettings_EAxis axis) {
    settings->limitMin[axis] = -FLT_MAX;
    settings->limitMax[axis] = FLT_MAX;
}

bool JPH_SixDOFConstraintSettings_IsFreeAxis(const JPH_SixDOFConstraintSettings *settings, JPH_SixDOFConstraintSettings_EAxis axis) {
    return settings->limitMin[axis] == -FLT_MAX && settings->limitMax[axis] == FLT_MAX;
}

void JPH_SixDOFConstraintSettings_MakeFixedAxis(JPH_SixDOFConstraintSettings *settings, JPH_SixDOFConstraintSettings_EAxis axis) {
    settings->limitMin[axis] = FLT_MAX;
    settings->limitMax[axis] = -FLT_MAX;
}

bool JPH_SixDOFConstraintSettings_IsFixedAxis(const JPH_SixDOFConstraintSettings *settings, JPH_SixDOFConstraintSettings_EAxis axis) {
    return settings->limitMin[axis] >= settings->limitMax[axis];
}

void JPH_SixDOFConstraintSettings_SetLimitedAxis(JPH_SixDOFConstraintSettings *settings, JPH_SixDOFConstraintSettings_EAxis axis, float min, float max) {
    settings->limitMin[axis] = min;
    settings->limitMax[axis] = max;
}

JPH_SliderConstraintSettings JPH_SliderConstraintSettings_Default() {
    return JPH_SliderConstraintSettings{
        .base=JPH_TwoBodyConstraintSettings_Default(),
        .space=JPH_EConstraintSpace_WorldSpace,
        .autoDetectPoint=false,
        .point1=JPH_RVec3_Make(0.0, 0.0, 0.0),
        .sliderAxis1=JPH_Vec3_Make(1.0f, 0.0f, 0.0f),
        .normalAxis1=JPH_Vec3_Make(0.0f, 1.0f, 0.0f),
        .point2=JPH_RVec3_Make(0.0, 0.0, 0.0),
        .sliderAxis2=JPH_Vec3_Make(1.0f, 0.0f, 0.0f),
        .normalAxis2=JPH_Vec3_Make(0.0f, 1.0f, 0.0f),
        .limitsMin=-FLT_MAX,
        .limitsMax=FLT_MAX,
        .limitsSpringSettings=JPH_SpringSettings_Default(),
        .maxFrictionForce=0.0f,
        .motorSettings=JPH_MotorSettings_Default(),
    };
}

JPH_TwoBodyConstraint *JPH_SliderConstraintSettings_CreateConstraint(const JPH_SliderConstraintSettings *settings, JPH_Body *body1, JPH_Body *body2) {
    auto cppSettings = JPH::SliderConstraintSettings();
    SetConstraintSettings(cppSettings, &settings->base.base);
    cppSettings.mSpace = static_cast<JPH::EConstraintSpace>(settings->space);
    cppSettings.mAutoDetectPoint = settings->autoDetectPoint;
    cppSettings.mPoint1 = ToCpp(settings->point1);
    cppSettings.mSliderAxis1 = ToCpp(settings->sliderAxis1);
    cppSettings.mNormalAxis1 = ToCpp(settings->normalAxis1);
    cppSettings.mPoint2 = ToCpp(settings->point2);
    cppSettings.mSliderAxis2 = ToCpp(settings->sliderAxis2);
    cppSettings.mNormalAxis2 = ToCpp(settings->normalAxis2);
    cppSettings.mLimitsMin = settings->limitsMin;
    cppSettings.mLimitsMax = settings->limitsMax;
    cppSettings.mLimitsSpringSettings = ToCpp(settings->limitsSpringSettings);
    cppSettings.mMaxFrictionForce = settings->maxFrictionForce;
    cppSettings.mMotorSettings = ToCpp(settings->motorSettings);

    return ToC(cppSettings.Create(*ToCpp(body1), *ToCpp(body2)));

}

JPH_SwingTwistConstraintSettings JPH_SwingTwistConstraintSettings_Default() {
    return JPH_SwingTwistConstraintSettings{
        .base=JPH_TwoBodyConstraintSettings_Default(),
        .space=JPH_EConstraintSpace_WorldSpace,
        .position1=JPH_RVec3_Make(0.0, 0.0, 0.0),
        .twistAxis1=JPH_Vec3_Make(1.0f, 0.0f, 0.0f),
        .planeAxis1=JPH_Vec3_Make(0.0f, 1.0f, 0.0f),
        .position2=JPH_RVec3_Make(0.0, 0.0, 0.0),
        .twistAxis2=JPH_Vec3_Make(1.0f, 0.0f, 0.0f),
        .planeAxis2=JPH_Vec3_Make(0.0f, 1.0f, 0.0f),
        .swingType=JPH_ESwingType_Cone,
        .normalHalfConeAngle=0.0f,
        .planeHalfConeAngle=0.0f,
        .twistMinAngle=0.0f,
        .twistMaxAngle=0.0f,
        .maxFrictionTorque=0.0f,
        .swingMotorSettings=JPH_MotorSettings_Default(),
        .twistMotorSettings=JPH_MotorSettings_Default(),
    };
}

JPH_TwoBodyConstraint *JPH_SwingTwistConstraintSettings_CreateConstraint(const JPH_SwingTwistConstraintSettings *settings, JPH_Body *body1, JPH_Body *body2) {
    auto cppSettings = JPH::SwingTwistConstraintSettings();
    SetConstraintSettings(cppSettings, &settings->base.base);
    cppSettings.mSpace = static_cast<JPH::EConstraintSpace>(settings->space);
    cppSettings.mPosition1 = ToCpp(settings->position1);
    cppSettings.mTwistAxis1 = ToCpp(settings->twistAxis1);
    cppSettings.mPlaneAxis1 = ToCpp(settings->planeAxis1);
    cppSettings.mPosition2 = ToCpp(settings->position2);
    cppSettings.mTwistAxis2 = ToCpp(settings->twistAxis2);
    cppSettings.mPlaneAxis2 = ToCpp(settings->planeAxis2);
    cppSettings.mSwingType = static_cast<JPH::ESwingType>(settings->swingType);
    cppSettings.mNormalHalfConeAngle = settings->normalHalfConeAngle;
    cppSettings.mPlaneHalfConeAngle = settings->planeHalfConeAngle;
    cppSettings.mTwistMinAngle = settings->twistMinAngle;
    cppSettings.mTwistMaxAngle = settings->twistMaxAngle;
    cppSettings.mMaxFrictionTorque = settings->maxFrictionTorque;
    cppSettings.mSwingMotorSettings = ToCpp(settings->swingMotorSettings);
    cppSettings.mTwistMotorSettings = ToCpp(settings->twistMotorSettings);

    return ToC(cppSettings.Create(*ToCpp(body1), *ToCpp(body2)));
}

// Constraint

void JPH_Constraint_Destroy(JPH_Constraint *constraint) {
    ToCpp(constraint)->Release();
}

JPH_EConstraintType JPH_Constraint_GetType(const JPH_Constraint *constraint) {
    return static_cast<JPH_EConstraintType>(ToCpp(constraint)->GetType());
}

JPH_EConstraintSubType JPH_Constraint_GetSubType(const JPH_Constraint *constraint) {
    return static_cast<JPH_EConstraintSubType>(ToCpp(constraint)->GetSubType());
}

uint32_t JPH_Constraint_GetConstraintPriority(const JPH_Constraint *constraint) {
    return ToCpp(constraint)->GetConstraintPriority();
}

void JPH_Constraint_SetConstraintPriority(JPH_Constraint *constraint, uint32_t priority) {
    ToCpp(constraint)->SetConstraintPriority(priority);
}

uint32_t JPH_Constraint_GetNumVelocityStepsOverride(const JPH_Constraint *constraint) {
    return ToCpp(constraint)->GetNumVelocityStepsOverride();
}

void JPH_Constraint_SetNumVelocityStepsOverride(JPH_Constraint *constraint, uint32_t steps) {
    ToCpp(constraint)->SetNumVelocityStepsOverride(steps);
}

uint32_t JPH_Constraint_GetNumPositionStepsOverride(const JPH_Constraint *constraint) {
    return ToCpp(constraint)->GetNumPositionStepsOverride();
}

void JPH_Constraint_SetNumPositionStepsOverride(JPH_Constraint *constraint, uint32_t steps) {
    ToCpp(constraint)->SetNumPositionStepsOverride(steps);
}

void JPH_Constraint_SetEnabled(JPH_Constraint *constraint, bool enabled) {
    ToCpp(constraint)->SetEnabled(enabled);
}

bool JPH_Constraint_GetEnabled(const JPH_Constraint *constraint) {
    return ToCpp(constraint)->GetEnabled();
}

#ifdef JOLTC_DEBUG_RENDERER
float JPH_Constraint_GetDrawConstraintSize(const JPH_Constraint *constraint) {
    return ToCpp(constraint)->GetDrawConstraintSize();
}

void JPH_Constraint_SetDrawConstraintSize(JPH_Constraint *constraint, float inSize) {
    ToCpp(constraint)->SetDrawConstraintSize(inSize);
}
#endif

JPH_Body *JPH_TwoBodyConstraint_GetBody1(const JPH_TwoBodyConstraint *constraint) {
    return ToC(ToCpp(constraint)->GetBody1());
}

JPH_Body *JPH_TwoBodyConstraint_GetBody2(const JPH_TwoBodyConstraint *constraint) {
    return ToC(ToCpp(constraint)->GetBody2());
}

void JPH_ConeConstraint_SetHalfConeAngle(JPH_ConeConstraint *constraint, float halfConeAngle) {
    ToCpp(constraint)->SetHalfConeAngle(halfConeAngle);
}

float JPH_ConeConstraint_GetCosHalfConeAngle(const JPH_ConeConstraint *constraint) {
    return ToCpp(constraint)->GetCosHalfConeAngle();
}

void JPH_DistanceConstraint_SetDistance(JPH_DistanceConstraint *constraint, float minDistance, float maxDistance) {
    ToCpp(constraint)->SetDistance(minDistance, maxDistance);
}

float JPH_DistanceConstraint_GetMinDistance(const JPH_DistanceConstraint *constraint) {
    return ToCpp(constraint)->GetMinDistance();
}

float JPH_DistanceConstraint_GetMaxDistance(const JPH_DistanceConstraint *constraint) {
    return ToCpp(constraint)->GetMaxDistance();
}

const JPH_SpringSettings *JPH_DistanceConstraint_GetLimitsSpringSettingsConst(const JPH_DistanceConstraint *constraint) {
    return &ToC(ToCpp(constraint)->GetLimitsSpringSettings());
}

JPH_SpringSettings *JPH_DistanceConstraint_GetLimitsSpringSettings(JPH_DistanceConstraint *constraint) {
    return &ToC(ToCpp(constraint)->GetLimitsSpringSettings());
}

void JPH_DistanceConstraint_SetLimitsSpringSettings(JPH_DistanceConstraint *constraint, JPH_SpringSettings limitsSpringSettings) {
    ToCpp(constraint)->SetLimitsSpringSettings(ToCpp(limitsSpringSettings));
}

void JPH_GearConstraint_SetConstraints(JPH_GearConstraint *constraint, const JPH_Constraint *gear1, const JPH_Constraint *gear2) {
    ToCpp(constraint)->SetConstraints(ToCpp(gear1), ToCpp(gear2));
}

JPH_Vec3 JPH_HingeConstraint_GetLocalSpacePoint1(const JPH_HingeConstraint *constraint) {
    return ToC(ToCpp(constraint)->GetLocalSpacePoint1());
}

JPH_Vec3 JPH_HingeConstraint_GetLocalSpacePoint2(const JPH_HingeConstraint *constraint) {
    return ToC(ToCpp(constraint)->GetLocalSpacePoint2());
}

JPH_Vec3 JPH_HingeConstraint_GetLocalSpaceHingeAxis1(const JPH_HingeConstraint *constraint) {
    return ToC(ToCpp(constraint)->GetLocalSpaceHingeAxis1());
}

JPH_Vec3 JPH_HingeConstraint_GetLocalSpaceHingeAxis2(const JPH_HingeConstraint *constraint) {
    return ToC(ToCpp(constraint)->GetLocalSpaceHingeAxis2());
}

JPH_Vec3 JPH_HingeConstraint_GetLocalSpaceNormalAxis1(const JPH_HingeConstraint *constraint) {
    return ToC(ToCpp(constraint)->GetLocalSpaceNormalAxis1());
}

JPH_Vec3 JPH_HingeConstraint_GetLocalSpaceNormalAxis2(const JPH_HingeConstraint *constraint) {
    return ToC(ToCpp(constraint)->GetLocalSpaceNormalAxis2());
}

float JPH_HingeConstraint_GetCurrentAngle(const JPH_HingeConstraint *constraint) {
    return ToCpp(constraint)->GetCurrentAngle();
}

void JPH_HingeConstraint_SetMaxFrictionTorque(JPH_HingeConstraint *constraint, float frictionTorque) {
    ToCpp(constraint)->SetMaxFrictionTorque(frictionTorque);
}

float JPH_HingeConstraint_GetMaxFrictionTorque(const JPH_HingeConstraint *constraint) {
    return ToCpp(constraint)->GetMaxFrictionTorque();
}

const JPH_MotorSettings *JPH_HingeConstraint_GetMotorSettingsConst(const JPH_HingeConstraint *constraint) {
    return &ToC(ToCpp(constraint)->GetMotorSettings());
}

JPH_MotorSettings *JPH_HingeConstraint_GetMotorSettings(JPH_HingeConstraint *constraint) {
    return &ToC(ToCpp(constraint)->GetMotorSettings());
}

void JPH_HingeConstraint_SetMotorState(JPH_HingeConstraint *constraint, JPH_EMotorState state) {
    ToCpp(constraint)->SetMotorState(static_cast<JPH::EMotorState>(state));
}

JPH_EMotorState JPH_HingeConstraint_GetMotorState(const JPH_HingeConstraint *constraint) {
    return static_cast<JPH_EMotorState>(ToCpp(constraint)->GetMotorState());
}

void JPH_HingeConstraint_SetTargetAngularVelocity(JPH_HingeConstraint *constraint, float angularVelocity) {
    ToCpp(constraint)->SetTargetAngularVelocity(angularVelocity);
}

float JPH_HingeConstraint_GetTargetAngularVelocity(const JPH_HingeConstraint *constraint) {
    return ToCpp(constraint)->GetTargetAngularVelocity();
}

void JPH_HingeConstraint_SetTargetAngle(JPH_HingeConstraint *constraint, float angle) {
    ToCpp(constraint)->SetTargetAngle(angle);
}

float JPH_HingeConstraint_GetTargetAngle(const JPH_HingeConstraint *constraint) {
    return ToCpp(constraint)->GetTargetAngle();
}

void JPH_HingeConstraint_SetTargetOrientationBS(JPH_HingeConstraint *constraint, JPH_Quat orientation) {
    ToCpp(constraint)->SetTargetOrientationBS(ToCpp(orientation));
}

void JPH_HingeConstraint_SetLimits(JPH_HingeConstraint *constraint, float limitsMin, float limitsMax) {
    ToCpp(constraint)->SetLimits(limitsMin, limitsMax);
}

float JPH_HingeConstraint_GetLimitsMin(const JPH_HingeConstraint *constraint) {
    return ToCpp(constraint)->GetLimitsMin();
}

float JPH_HingeConstraint_GetLimitsMax(const JPH_HingeConstraint *constraint) {
    return ToCpp(constraint)->GetLimitsMax();
}

bool JPH_HingeConstraint_HasLimits(const JPH_HingeConstraint *constraint) {
    return ToCpp(constraint)->HasLimits();
}

const JPH_SpringSettings *JPH_HingeConstraint_GetLimitsSpringSettingsConst(const JPH_HingeConstraint *constraint) {
    return &ToC(ToCpp(constraint)->GetLimitsSpringSettings());
}

JPH_SpringSettings *JPH_HingeConstraint_GetLimitsSpringSettings(JPH_HingeConstraint *constraint) {
    return &ToC(ToCpp(constraint)->GetLimitsSpringSettings());
}

void JPH_HingeConstraint_SetLimitsSpringSettings(JPH_HingeConstraint *constraint, JPH_SpringSettings limitsSpringSettings) {
    ToCpp(constraint)->SetLimitsSpringSettings(ToCpp(limitsSpringSettings));
}

void JPH_PathConstraint_SetPath(JPH_PathConstraint *constraint, const JPH_PathConstraintPath *path, float pathFraction) {
    ToCpp(constraint)->SetPath(ToCpp(path), pathFraction);
}

const JPH_PathConstraintPath *JPH_PathConstraint_GetPath(const JPH_PathConstraint *constraint) {
    return ToC(ToCpp(constraint)->GetPath());
}

float JPH_PathConstraint_GetPathFraction(const JPH_PathConstraint *constraint) {
    return ToCpp(constraint)->GetPathFraction();
}

void JPH_PathConstraint_SetMaxFrictionForce(JPH_PathConstraint *constraint, float frictionForce) {
    ToCpp(constraint)->SetMaxFrictionForce(frictionForce);
}

float JPH_PathConstraint_GetMaxFrictionForce(const JPH_PathConstraint *constraint) {
    return ToCpp(constraint)->GetMaxFrictionForce();
}

const JPH_MotorSettings *JPH_PathConstraint_GetPositionMotorSettingsConst(const JPH_PathConstraint *constraint) {
    return &ToC(ToCpp(constraint)->GetPositionMotorSettings());
}

JPH_MotorSettings *JPH_PathConstraint_GetPositionMotorSettings(JPH_PathConstraint *constraint) {
    return &ToC(ToCpp(constraint)->GetPositionMotorSettings());
}

void JPH_PathConstraint_SetPositionMotorState(JPH_PathConstraint *constraint, JPH_EMotorState state) {
    ToCpp(constraint)->SetPositionMotorState(static_cast<JPH::EMotorState>(state));
}

JPH_EMotorState JPH_PathConstraint_GetPositionMotorState(const JPH_PathConstraint *constraint) {
    return static_cast<JPH_EMotorState>(ToCpp(constraint)->GetPositionMotorState());
}

void JPH_PathConstraint_SetTargetVelocity(JPH_PathConstraint *constraint, float velocity) {
    ToCpp(constraint)->SetTargetVelocity(velocity);
}

float JPH_PathConstraint_GetTargetVelocity(const JPH_PathConstraint *constraint) {
    return ToCpp(constraint)->GetTargetVelocity();
}

void JPH_PathConstraint_SetTargetPathFraction(JPH_PathConstraint *constraint, float fraction) {
    ToCpp(constraint)->SetTargetPathFraction(fraction);
}

float JPH_PathConstraint_GetTargetPathFraction(const JPH_PathConstraint *constraint) {
    return ToCpp(constraint)->GetTargetPathFraction();
}

void JPH_PointConstraint_SetPoint1(JPH_PointConstraint *constraint, JPH_EConstraintSpace space, JPH_RVec3 point1) {
    ToCpp(constraint)->SetPoint1(static_cast<JPH::EConstraintSpace>(space), ToCpp(point1));
}

void JPH_PointConstraint_SetPoint2(JPH_PointConstraint *constraint, JPH_EConstraintSpace space, JPH_RVec3 point2) {
    ToCpp(constraint)->SetPoint2(static_cast<JPH::EConstraintSpace>(space), ToCpp(point2));
}

JPH_Vec3 JPH_PointConstraint_GetLocalSpacePoint1(const JPH_PointConstraint *constraint) {
    return ToC(ToCpp(constraint)->GetLocalSpacePoint1());
}

JPH_Vec3 JPH_PointConstraint_GetLocalSpacePoint2(const JPH_PointConstraint *constraint) {
    return ToC(ToCpp(constraint)->GetLocalSpacePoint2());
}

void JPH_PulleyConstraint_SetLength(JPH_PulleyConstraint *constraint, float minLength, float maxLength) {
    ToCpp(constraint)->SetLength(minLength, maxLength);
}

float JPH_PulleyConstraint_GetMinLength(const JPH_PulleyConstraint *constraint) {
    return ToCpp(constraint)->GetMinLength();
}

float JPH_PulleyConstraint_GetMaxLength(const JPH_PulleyConstraint *constraint) {
    return ToCpp(constraint)->GetMaxLength();
}

float JPH_PulleyConstraint_GetCurrentLength(const JPH_PulleyConstraint *constraint) {
    return ToCpp(constraint)->GetCurrentLength();
}

void JPH_RackAndPinionConstraint_SetConstraints(JPH_RackAndPinionConstraint *constraints, const JPH_Constraint *pinion, const JPH_Constraint *rack) {
    ToCpp(constraints)->SetConstraints(ToCpp(pinion), ToCpp(rack));
}

void JPH_SixDOFConstraint_SetTranslationLimits(JPH_SixDOFConstraint *constraint, JPH_Vec3 limitMin, JPH_Vec3 limitMax) {
    ToCpp(constraint)->SetTranslationLimits(ToCpp(limitMin), ToCpp(limitMax));
}

void JPH_SixDOFConstraint_SetRotationLimits(JPH_SixDOFConstraint *constraint, JPH_Vec3 limitMin, JPH_Vec3 limitMax) {
    ToCpp(constraint)->SetRotationLimits(ToCpp(limitMin), ToCpp(limitMax));
}

float JPH_SixDOFConstraint_GetLimitsMin(const JPH_SixDOFConstraint *constraint, JPH_SixDOFConstraintSettings_EAxis axis) {
    return ToCpp(constraint)->GetLimitsMin(static_cast<JPH::SixDOFConstraintSettings::EAxis>(axis));
}

float JPH_SixDOFConstraint_GetLimitsMax(const JPH_SixDOFConstraint *constraint, JPH_SixDOFConstraintSettings_EAxis axis) {
    return ToCpp(constraint)->GetLimitsMax(static_cast<JPH::SixDOFConstraintSettings::EAxis>(axis));
}

JPH_Vec3 JPH_SixDOFConstraint_GetTranslationLimitsMin(const JPH_SixDOFConstraint *constraint) {
    return ToC(ToCpp(constraint)->GetTranslationLimitsMin());
}

JPH_Vec3 JPH_SixDOFConstraint_GetTranslationLimitsMax(const JPH_SixDOFConstraint *constraint) {
    return ToC(ToCpp(constraint)->GetTranslationLimitsMax());
}

JPH_Vec3 JPH_SixDOFConstraint_GetRotationLimitsMin(const JPH_SixDOFConstraint *constraint) {
    return ToC(ToCpp(constraint)->GetRotationLimitsMin());
}

JPH_Vec3 JPH_SixDOFConstraint_GetRotationLimitsMax(const JPH_SixDOFConstraint *constraint) {
    return ToC(ToCpp(constraint)->GetRotationLimitsMax());
}

bool JPH_SixDOFConstraint_IsFixedAxis(const JPH_SixDOFConstraint *constraint, JPH_SixDOFConstraintSettings_EAxis axis) {
    return ToCpp(constraint)->IsFixedAxis(static_cast<JPH::SixDOFConstraintSettings::EAxis>(axis));
}

bool JPH_SixDOFConstraint_IsFreeAxis(const JPH_SixDOFConstraint *constraint, JPH_SixDOFConstraintSettings_EAxis axis) {
    return ToCpp(constraint)->IsFreeAxis(static_cast<JPH::SixDOFConstraintSettings::EAxis>(axis));
}

const JPH_SpringSettings *JPH_SixDOFConstraint_GetLimitsSpringSettings(const JPH_SixDOFConstraint *constraint, JPH_SixDOFConstraintSettings_EAxis axis) {
    return &ToC(ToCpp(constraint)->GetLimitsSpringSettings(static_cast<JPH::SixDOFConstraintSettings::EAxis>(axis)));
}

void JPH_SixDOFConstraint_SetLimitsSpringSettings(JPH_SixDOFConstraint *constraint, JPH_SixDOFConstraintSettings_EAxis axis, JPH_SpringSettings limitsSpringSettings) {
    ToCpp(constraint)->SetLimitsSpringSettings(static_cast<JPH::SixDOFConstraintSettings::EAxis>(axis), ToCpp(limitsSpringSettings));
}

void JPH_SixDOFConstraint_SetMaxFriction(JPH_SixDOFConstraint *constraint, JPH_SixDOFConstraintSettings_EAxis axis, float friction) {
    ToCpp(constraint)->SetMaxFriction(static_cast<JPH::SixDOFConstraintSettings::EAxis>(axis), friction);
}

float JPH_SixDOFConstraint_GetMaxFriction(const JPH_SixDOFConstraint *constraint, JPH_SixDOFConstraintSettings_EAxis axis) {
    return ToCpp(constraint)->GetMaxFriction(static_cast<JPH::SixDOFConstraintSettings::EAxis>(axis));
}

JPH_Quat JPH_SixDOFConstraint_GetRotationInConstraintSpace(const JPH_SixDOFConstraint *constraint) {
    return ToC(ToCpp(constraint)->GetRotationInConstraintSpace());
}

JPH_MotorSettings *JPH_SixDOFConstraint_GetMotorSettings(JPH_SixDOFConstraint *constraint, JPH_SixDOFConstraintSettings_EAxis axis) {
    return &ToC(ToCpp(constraint)->GetMotorSettings(static_cast<JPH::SixDOFConstraintSettings::EAxis>(axis)));
}

const JPH_MotorSettings *JPH_SixDOFConstraint_GetMotorSettingsConst(const JPH_SixDOFConstraint *constraint, JPH_SixDOFConstraintSettings_EAxis axis) {
    return &ToC(ToCpp(constraint)->GetMotorSettings(static_cast<JPH::SixDOFConstraintSettings::EAxis>(axis)));
}

void JPH_SixDOFConstraint_SetMotorState(JPH_SixDOFConstraint *constraint, JPH_SixDOFConstraintSettings_EAxis axis, JPH_EMotorState state) {
    ToCpp(constraint)->SetMotorState(static_cast<JPH::SixDOFConstraintSettings::EAxis>(axis), static_cast<JPH::EMotorState>(state));
}

JPH_EMotorState JPH_SixDOFConstraint_GetMotorState(const JPH_SixDOFConstraint *constraint, JPH_SixDOFConstraintSettings_EAxis axis) {
    return static_cast<JPH_EMotorState>(ToCpp(constraint)->GetMotorState(static_cast<JPH::SixDOFConstraintSettings::EAxis>(axis)));
}

JPH_Vec3 JPH_SixDOFConstraint_GetTargetVelocityCS(const JPH_SixDOFConstraint *constraint) {
    return ToC(ToCpp(constraint)->GetTargetVelocityCS());
}

void JPH_SixDOFConstraint_SetTargetVelocityCS(JPH_SixDOFConstraint *constraint, JPH_Vec3 velocity) {
    ToCpp(constraint)->SetTargetVelocityCS(ToCpp(velocity));
}

void JPH_SixDOFConstraint_SetTargetAngularVelocityCS(JPH_SixDOFConstraint *constraint, JPH_Vec3 angularVelocity) {
    ToCpp(constraint)->SetTargetAngularVelocityCS(ToCpp(angularVelocity));
}

JPH_Vec3 JPH_SixDOFConstraint_GetTargetAngularVelocityCS(const JPH_SixDOFConstraint *constraint) {
    return ToC(ToCpp(constraint)->GetTargetAngularVelocityCS());
}

JPH_Vec3 JPH_SixDOFConstraint_GetTargetPositionCS(const JPH_SixDOFConstraint *constraint) {
    return ToC(ToCpp(constraint)->GetTargetPositionCS());
}

void JPH_SixDOFConstraint_SetTargetPositionCS(JPH_SixDOFConstraint *constraint, JPH_Vec3 position) {
    ToCpp(constraint)->SetTargetPositionCS(ToCpp(position));
}

void JPH_SixDOFConstraint_SetTargetOrientationCS(JPH_SixDOFConstraint *constraint, JPH_Quat prientation) {
    ToCpp(constraint)->SetTargetOrientationCS(ToCpp(prientation));
}

JPH_Quat JPH_SixDOFConstraint_GetTargetOrientationCS(const JPH_SixDOFConstraint *constraint) {
    return ToC(ToCpp(constraint)->GetTargetOrientationCS());
}

void JPH_SixDOFConstraint_SetTargetOrientationBS(JPH_SixDOFConstraint *constraint, JPH_Quat orientation) {
    ToCpp(constraint)->SetTargetOrientationBS(ToCpp(orientation));
}

float JPH_SliderConstraint_GetCurrentPosition(const JPH_SliderConstraint *constraint) {
    return ToCpp(constraint)->GetCurrentPosition();
}

void JPH_SliderConstraint_SetMaxFrictionForce(JPH_SliderConstraint *constraint, float frictionForce) {
    ToCpp(constraint)->SetMaxFrictionForce(frictionForce);
}

float JPH_SliderConstraint_GetMaxFrictionForce(const JPH_SliderConstraint *constraint) {
    return ToCpp(constraint)->GetMaxFrictionForce();
}

JPH_MotorSettings *JPH_SliderConstraint_GetMotorSettings(JPH_SliderConstraint *constraint) {
    return &ToC(ToCpp(constraint)->GetMotorSettings());
}

const JPH_MotorSettings *JPH_SliderConstraint_GetMotorSettingsConst(const JPH_SliderConstraint *constraint) {
    return &ToC(ToCpp(constraint)->GetMotorSettings());
}

void JPH_SliderConstraint_SetMotorState(JPH_SliderConstraint *constraint, JPH_EMotorState state) {
    ToCpp(constraint)->SetMotorState(static_cast<JPH::EMotorState>(state));
}

JPH_EMotorState JPH_SliderConstraint_GetMotorState(const JPH_SliderConstraint *constraint) {
    return static_cast<JPH_EMotorState>(ToCpp(constraint)->GetMotorState());
}

void JPH_SliderConstraint_SetTargetVelocity(JPH_SliderConstraint *constraint, float velocity) {
    ToCpp(constraint)->SetTargetVelocity(velocity);
}

float JPH_SliderConstraint_GetTargetVelocity(const JPH_SliderConstraint *constraint) {
    return ToCpp(constraint)->GetTargetVelocity();
}

void JPH_SliderConstraint_SetTargetPosition(JPH_SliderConstraint *constraint, float position) {
    ToCpp(constraint)->SetTargetPosition(position);
}

float JPH_SliderConstraint_GetTargetPosition(const JPH_SliderConstraint *constraint) {
    return ToCpp(constraint)->GetTargetPosition();
}

void JPH_SliderConstraint_SetLimits(JPH_SliderConstraint *constraint, float limitsMin, float limitsMax) {
    ToCpp(constraint)->SetLimits(limitsMin, limitsMax);
}

float JPH_SliderConstraint_GetLimitsMin(const JPH_SliderConstraint *constraint) {
    return ToCpp(constraint)->GetLimitsMin();
}

float JPH_SliderConstraint_GetLimitsMax(const JPH_SliderConstraint *constraint) {
    return ToCpp(constraint)->GetLimitsMax();
}

bool JPH_SliderConstraint_HasLimits(const JPH_SliderConstraint *constraint) {
    return ToCpp(constraint)->HasLimits();
}

const JPH_SpringSettings *JPH_SliderConstraint_GetLimitsSpringSettingsConst(const JPH_SliderConstraint *constraint) {
    return &ToC(ToCpp(constraint)->GetLimitsSpringSettings());
}

JPH_SpringSettings *JPH_SliderConstraint_GetLimitsSpringSettings(JPH_SliderConstraint *constraint) {
    return &ToC(ToCpp(constraint)->GetLimitsSpringSettings());
}

void JPH_SliderConstraint_SetLimitsSpringSettings(JPH_SliderConstraint *constraint, JPH_SpringSettings limitsSpringSettings) {
    ToCpp(constraint)->SetLimitsSpringSettings(ToCpp(limitsSpringSettings));
}

JPH_Vec3 JPH_SwingTwistConstraint_GetLocalSpacePosition1(const JPH_SwingTwistConstraint *constraint) {
    return ToC(ToCpp(constraint)->GetLocalSpacePosition1());
}

JPH_Vec3 JPH_SwingTwistConstraint_GetLocalSpacePosition2(const JPH_SwingTwistConstraint *constraint) {
    return ToC(ToCpp(constraint)->GetLocalSpacePosition2());
}

JPH_Quat JPH_SwingTwistConstraint_GetConstraintToBody1(const JPH_SwingTwistConstraint *constraint) {
    return ToC(ToCpp(constraint)->GetConstraintToBody1());
}

JPH_Quat JPH_SwingTwistConstraint_GetConstraintToBody2(const JPH_SwingTwistConstraint *constraint) {
    return ToC(ToCpp(constraint)->GetConstraintToBody2());
}

float JPH_SwingTwistConstraint_GetNormalHalfConeAngle(const JPH_SwingTwistConstraint *constraint) {
    return ToCpp(constraint)->GetNormalHalfConeAngle();
}

void JPH_SwingTwistConstraint_SetNormalHalfConeAngle(JPH_SwingTwistConstraint *constraint, float angle) {
    ToCpp(constraint)->SetNormalHalfConeAngle(angle);
}

float JPH_SwingTwistConstraint_GetPlaneHalfConeAngle(const JPH_SwingTwistConstraint *constraint) {
    return ToCpp(constraint)->GetPlaneHalfConeAngle();
}

void JPH_SwingTwistConstraint_SetPlaneHalfConeAngle(JPH_SwingTwistConstraint *constraint, float angle) {
    ToCpp(constraint)->SetPlaneHalfConeAngle(angle);
}

float JPH_SwingTwistConstraint_GetTwistMinAngle(const JPH_SwingTwistConstraint *constraint) {
    return ToCpp(constraint)->GetTwistMinAngle();
}

void JPH_SwingTwistConstraint_SetTwistMinAngle(JPH_SwingTwistConstraint *constraint, float angle) {
    ToCpp(constraint)->SetTwistMinAngle(angle);
}

float JPH_SwingTwistConstraint_GetTwistMaxAngle(const JPH_SwingTwistConstraint *constraint) {
    return ToCpp(constraint)->GetTwistMaxAngle();
}

void JPH_SwingTwistConstraint_SetTwistMaxAngle(JPH_SwingTwistConstraint *constraint, float angle) {
    ToCpp(constraint)->SetTwistMaxAngle(angle);
}

const JPH_MotorSettings *JPH_SwingTwistConstraint_GetSwingMotorSettingsConst(const JPH_SwingTwistConstraint *constraint) {
    return &ToC(ToCpp(constraint)->GetSwingMotorSettings());
}

JPH_MotorSettings *JPH_SwingTwistConstraint_GetSwingMotorSettings(JPH_SwingTwistConstraint *constraint) {
    return &ToC(ToCpp(constraint)->GetSwingMotorSettings());
}

const JPH_MotorSettings *JPH_SwingTwistConstraint_GetTwistMotorSettingsConst(const JPH_SwingTwistConstraint *constraint) {
    return &ToC(ToCpp(constraint)->GetTwistMotorSettings());
}

JPH_MotorSettings *JPH_SwingTwistConstraint_GetTwistMotorSettings(JPH_SwingTwistConstraint *constraint) {
    return &ToC(ToCpp(constraint)->GetTwistMotorSettings());
}

void JPH_SwingTwistConstraint_SetMaxFrictionTorque(JPH_SwingTwistConstraint *constraint, float frictionTorque) {
    ToCpp(constraint)->SetMaxFrictionTorque(frictionTorque);
}

float JPH_SwingTwistConstraint_GetMaxFrictionTorque(const JPH_SwingTwistConstraint *constraint) {
    return ToCpp(constraint)->GetMaxFrictionTorque();
}

void JPH_SwingTwistConstraint_SetSwingMotorState(JPH_SwingTwistConstraint *constraint, JPH_EMotorState state) {
    ToCpp(constraint)->SetSwingMotorState(static_cast<JPH::EMotorState>(state));
}

JPH_EMotorState JPH_SwingTwistConstraint_GetSwingMotorState(const JPH_SwingTwistConstraint *constraint) {
    return static_cast<JPH_EMotorState>(ToCpp(constraint)->GetSwingMotorState());
}

void JPH_SwingTwistConstraint_SetTwistMotorState(JPH_SwingTwistConstraint *constraint, JPH_EMotorState state) {
    ToCpp(constraint)->SetTwistMotorState(static_cast<JPH::EMotorState>(state));
}

JPH_EMotorState JPH_SwingTwistConstraint_GetTwistMotorState(const JPH_SwingTwistConstraint *constraint) {
    return static_cast<JPH_EMotorState>(ToCpp(constraint)->GetTwistMotorState());
}

void JPH_SwingTwistConstraint_SetTargetAngularVelocityCS(JPH_SwingTwistConstraint *constraint, JPH_Vec3 angularVelocity) {
    ToCpp(constraint)->SetTargetAngularVelocityCS(ToCpp(angularVelocity));
}

JPH_Vec3 JPH_SwingTwistConstraint_GetTargetAngularVelocityCS(const JPH_SwingTwistConstraint *constraint) {
    return ToC(ToCpp(constraint)->GetTargetAngularVelocityCS());
}

void JPH_SwingTwistConstraint_SetTargetAngularVelocityBS(JPH_SwingTwistConstraint *constraint, JPH_Vec3 angularVelocity) {
    ToCpp(constraint)->SetTargetAngularVelocityBS(ToCpp(angularVelocity));
}

void JPH_SwingTwistConstraint_SetTargetOrientationCS(JPH_SwingTwistConstraint *constraint, JPH_Quat orientation) {
    ToCpp(constraint)->SetTargetOrientationCS(ToCpp(orientation));
}

JPH_Quat JPH_SwingTwistConstraint_GetTargetOrientationCS(const JPH_SwingTwistConstraint *constraint) {
    return ToC(ToCpp(constraint)->GetTargetOrientationCS());
}

void JPH_SwingTwistConstraint_SetTargetOrientationBS(JPH_SwingTwistConstraint *constraint, JPH_Quat orientation) {
    ToCpp(constraint)->SetTargetOrientationBS(ToCpp(orientation));
}

JPH_Quat JPH_SwingTwistConstraint_GetRotationInConstraintSpace(const JPH_SwingTwistConstraint *constraint) {
    return ToC(ToCpp(constraint)->GetRotationInConstraintSpace());
}

JOLTC_POP_WARNINGS()
