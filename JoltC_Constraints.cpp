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

JPH_TwoBodyConstraint *JPH_GearConstraintSettings_CreateConstraint(const JPH_GearConstraintSettings *settings, JPH_Body *body1, JPH_Body *body2) {
    auto cppSettings = JPH::GearConstraintSettings();
    SetConstraintSettings(cppSettings, &settings->base.base);
    cppSettings.mSpace = static_cast<JPH::EConstraintSpace>(settings->space);
    cppSettings.mHingeAxis1 = ToCpp(settings->hingeAxis1);
    cppSettings.mHingeAxis2 = ToCpp(settings->hingeAxis2);
    cppSettings.mRatio = settings->ratio;

    return ToC(cppSettings.Create(*ToCpp(body1), *ToCpp(body2)));
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

JPH_TwoBodyConstraint *JPH_PointConstraintSettings_CreateConstraint(const JPH_PointConstraintSettings *settings, JPH_Body *body1, JPH_Body *body2) {
    auto cppSettings = JPH::PointConstraintSettings();
    SetConstraintSettings(cppSettings, &settings->base.base);
    cppSettings.mSpace = static_cast<JPH::EConstraintSpace>(settings->space);
    cppSettings.mPoint1 = ToCpp(settings->point1);
    cppSettings.mPoint2 = ToCpp(settings->point2);

    return ToC(cppSettings.Create(*ToCpp(body1), *ToCpp(body2)));
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

JPH_TwoBodyConstraint *JPH_RackAndPinionConstraintSettings_CreateConstraint(const JPH_RackAndPinionConstraintSettings *settings, JPH_Body *body1, JPH_Body *body2) {
    auto cppSettings = JPH::RackAndPinionConstraintSettings();
    SetConstraintSettings(cppSettings, &settings->base.base);
    cppSettings.mSpace = static_cast<JPH::EConstraintSpace>(settings->space);
    cppSettings.mHingeAxis = ToCpp(settings->hingeAxis);
    cppSettings.mSliderAxis = ToCpp(settings->sliderAxis);
    cppSettings.mRatio = settings->ratio;

    return ToC(cppSettings.Create(*ToCpp(body1), *ToCpp(body2)));
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

JOLTC_POP_WARNINGS()
