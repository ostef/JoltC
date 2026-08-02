#include <JoltC.hpp>

JOLTC_SUPPRESS_WARNINGS()

// @Todo: test enum values

#define ABI_TEST(c_type, cpp_type) \
    JPH_ASSERT(sizeof(c_type) == sizeof(cpp_type)); \
    JPH_ASSERT(alignof(c_type) == alignof(cpp_type));

#define OFFSET_OF(T, field) ((uint64_t)&((const T *)(0))->field)

#define ABI_TEST_OFFSET_OF(c_type, c_field, cpp_type, cpp_field) \
    JPH_ASSERT(OFFSET_OF(c_type, c_field) == OFFSET_OF(cpp_type, cpp_field));

void ABITests() {
    using uint64 = uint64_t;

    JPH_ASSERT(JOLTC_VERSION_ID == JPH_VERSION_ID, "JoltC and Jolt version ID mismatch");

    ABI_TEST(JPH_Float3, JPH::Float3);
    ABI_TEST_OFFSET_OF(JPH_Float3, x, JPH::Float3, x);
    ABI_TEST_OFFSET_OF(JPH_Float3, y, JPH::Float3, y);
    ABI_TEST_OFFSET_OF(JPH_Float3, z, JPH::Float3, z);

    ABI_TEST(JPH_UVec4, JPH::UVec4);
    ABI_TEST_OFFSET_OF(JPH_UVec4, x, JPH::UVec4, mU32[0]);
    ABI_TEST_OFFSET_OF(JPH_UVec4, y, JPH::UVec4, mU32[1]);
    ABI_TEST_OFFSET_OF(JPH_UVec4, z, JPH::UVec4, mU32[2]);
    ABI_TEST_OFFSET_OF(JPH_UVec4, w, JPH::UVec4, mU32[3]);

    ABI_TEST(JPH_Vec3, JPH::Vec3);
    ABI_TEST_OFFSET_OF(JPH_Vec3, x, JPH::Vec3, mF32[0]);
    ABI_TEST_OFFSET_OF(JPH_Vec3, y, JPH::Vec3, mF32[1]);
    ABI_TEST_OFFSET_OF(JPH_Vec3, z, JPH::Vec3, mF32[2]);
    ABI_TEST_OFFSET_OF(JPH_Vec3, z2, JPH::Vec3, mF32[3]);

    ABI_TEST(JPH_Vec4, JPH::Vec4);
    ABI_TEST_OFFSET_OF(JPH_Vec4, x, JPH::Vec4, mF32[0]);
    ABI_TEST_OFFSET_OF(JPH_Vec4, y, JPH::Vec4, mF32[1]);
    ABI_TEST_OFFSET_OF(JPH_Vec4, z, JPH::Vec4, mF32[2]);
    ABI_TEST_OFFSET_OF(JPH_Vec4, w, JPH::Vec4, mF32[3]);

    ABI_TEST(JPH_Mat44, JPH::Mat44);

    ABI_TEST(JPH_DVec3, JPH::DVec3);
    ABI_TEST_OFFSET_OF(JPH_DVec3, x, JPH::DVec3, mF64[0]);
    ABI_TEST_OFFSET_OF(JPH_DVec3, y, JPH::DVec3, mF64[1]);
    ABI_TEST_OFFSET_OF(JPH_DVec3, z, JPH::DVec3, mF64[2]);
    ABI_TEST_OFFSET_OF(JPH_DVec3, z2, JPH::DVec3, mF64[3]);

    ABI_TEST(JPH_DMat44, JPH::DMat44);

    ABI_TEST(JPH_Quat, JPH::Quat);

    ABI_TEST(JPH_AABox, JPH::AABox);
    ABI_TEST(JPH_Plane, JPH::Plane);
    ABI_TEST(JPH_OrientedBox, JPH::OrientedBox);
    ABI_TEST(JPH_PhysicsSettings, JPH::PhysicsSettings);

    ABI_TEST(JPH_BroadPhaseLayer, JPH::BroadPhaseLayer);
    ABI_TEST(JPH_CollisionGroup_GroupID, JPH::CollisionGroup::GroupID);
    ABI_TEST(JPH_CollisionGroup_SubGroupID, JPH::CollisionGroup::SubGroupID);
    ABI_TEST(JPH_CollisionGroup, JPH::CollisionGroup);
    ABI_TEST(JPH_RayCast, JPH::RayCast);
    ABI_TEST(JPH_RRayCast, JPH::RRayCast);
    ABI_TEST(JPH_EBackFaceMode, JPH::EBackFaceMode);
    ABI_TEST(JPH_RayCastSettings, JPH::RayCastSettings);
    ABI_TEST(JPH_AABoxCast, JPH::AABoxCast);
    ABI_TEST(JPH_BroadPhaseCastResult, JPH::BroadPhaseCastResult);
    ABI_TEST_OFFSET_OF(JPH_BroadPhaseCastResult, bodyID, JPH::BroadPhaseCastResult, mBodyID);
    ABI_TEST_OFFSET_OF(JPH_BroadPhaseCastResult, fraction, JPH::BroadPhaseCastResult, mFraction);

    ABI_TEST(JPH_RayCastResult, JPH::RayCastResult);
    ABI_TEST_OFFSET_OF(JPH_RayCastResult, bodyID, JPH::RayCastResult, mBodyID);
    ABI_TEST_OFFSET_OF(JPH_RayCastResult, fraction, JPH::RayCastResult, mFraction);
    ABI_TEST_OFFSET_OF(JPH_RayCastResult, subShapeID2, JPH::RayCastResult, mSubShapeID2);

    ABI_TEST(JPH_CollideShapeResult_Face, JPH::CollideShapeResult::Face);

    ABI_TEST(JPH_CollideShapeResult, JPH::CollideShapeResult);
    ABI_TEST_OFFSET_OF(JPH_CollideShapeResult, contactPointOn1, JPH::CollideShapeResult, mContactPointOn1);
    ABI_TEST_OFFSET_OF(JPH_CollideShapeResult, contactPointOn2, JPH::CollideShapeResult, mContactPointOn2);
    ABI_TEST_OFFSET_OF(JPH_CollideShapeResult, penetrationAxis, JPH::CollideShapeResult, mPenetrationAxis);
    ABI_TEST_OFFSET_OF(JPH_CollideShapeResult, penetrationDepth, JPH::CollideShapeResult, mPenetrationDepth);
    ABI_TEST_OFFSET_OF(JPH_CollideShapeResult, subShapeID1, JPH::CollideShapeResult, mSubShapeID1);
    ABI_TEST_OFFSET_OF(JPH_CollideShapeResult, subShapeID2, JPH::CollideShapeResult, mSubShapeID2);
    ABI_TEST_OFFSET_OF(JPH_CollideShapeResult, bodyID2, JPH::CollideShapeResult, mBodyID2);
    ABI_TEST_OFFSET_OF(JPH_CollideShapeResult, shape1Face, JPH::CollideShapeResult, mShape1Face);
    ABI_TEST_OFFSET_OF(JPH_CollideShapeResult, shape2Face, JPH::CollideShapeResult, mShape2Face);

    ABI_TEST(JPH_ShapeCastSettings, JPH::ShapeCastSettings);
    ABI_TEST_OFFSET_OF(JPH_ShapeCastSettings, activeEdgeMode, JPH::ShapeCastSettings, mActiveEdgeMode);
    ABI_TEST_OFFSET_OF(JPH_ShapeCastSettings, collectFacesMode, JPH::ShapeCastSettings, mCollectFacesMode);
    ABI_TEST_OFFSET_OF(JPH_ShapeCastSettings, collisionTolerance, JPH::ShapeCastSettings, mCollisionTolerance);
    ABI_TEST_OFFSET_OF(JPH_ShapeCastSettings, penetrationTolerance, JPH::ShapeCastSettings, mPenetrationTolerance);
    ABI_TEST_OFFSET_OF(JPH_ShapeCastSettings, activeEdgeMovementDirection, JPH::ShapeCastSettings, mActiveEdgeMovementDirection);
    ABI_TEST_OFFSET_OF(JPH_ShapeCastSettings, extraConvexRadius, JPH::ShapeCastSettings, mExtraConvexRadius);
    ABI_TEST_OFFSET_OF(JPH_ShapeCastSettings, backFaceModeTriangles, JPH::ShapeCastSettings, mBackFaceModeTriangles);
    ABI_TEST_OFFSET_OF(JPH_ShapeCastSettings, backFaceModeConvex, JPH::ShapeCastSettings, mBackFaceModeConvex);
    ABI_TEST_OFFSET_OF(JPH_ShapeCastSettings, useShrunkenShapeAndConvexRadius, JPH::ShapeCastSettings, mUseShrunkenShapeAndConvexRadius);
    ABI_TEST_OFFSET_OF(JPH_ShapeCastSettings, returnDeepestPoint, JPH::ShapeCastSettings, mReturnDeepestPoint);

    ABI_TEST(JPH_CollideShapeSettings, JPH::CollideShapeSettings);
    ABI_TEST_OFFSET_OF(JPH_CollideShapeSettings, activeEdgeMode, JPH::CollideShapeSettings, mActiveEdgeMode);
    ABI_TEST_OFFSET_OF(JPH_CollideShapeSettings, collectFacesMode, JPH::CollideShapeSettings, mCollectFacesMode);
    ABI_TEST_OFFSET_OF(JPH_CollideShapeSettings, collisionTolerance, JPH::CollideShapeSettings, mCollisionTolerance);
    ABI_TEST_OFFSET_OF(JPH_CollideShapeSettings, penetrationTolerance, JPH::CollideShapeSettings, mPenetrationTolerance);
    ABI_TEST_OFFSET_OF(JPH_CollideShapeSettings, activeEdgeMovementDirection, JPH::CollideShapeSettings, mActiveEdgeMovementDirection);
    ABI_TEST_OFFSET_OF(JPH_CollideShapeSettings, maxSeparationDistance, JPH::CollideShapeSettings, mMaxSeparationDistance);
    ABI_TEST_OFFSET_OF(JPH_CollideShapeSettings, backFaceMode, JPH::CollideShapeSettings, mBackFaceMode);
    ABI_TEST_OFFSET_OF(JPH_CollideShapeSettings, internalEdgeRemovalVertexToleranceSq, JPH::CollideShapeSettings, mInternalEdgeRemovalVertexToleranceSq);

    ABI_TEST(JPH_IndexedTriangle, JPH::IndexedTriangle);
    ABI_TEST(JPH_MeshShapeSettings_EBuildQuality, JPH::MeshShapeSettings::EBuildQuality);
    ABI_TEST(JPH_SubShapeID, JPH::SubShapeID);
    ABI_TEST(JPH_EShapeType, JPH::EShapeType);
    ABI_TEST(JPH_EShapeSubType, JPH::EShapeSubType);
    ABI_TEST(JPH_MassProperties, JPH::MassProperties);
    ABI_TEST(JPH_Shape_SupportingFace, JPH::Shape::SupportingFace);
    ABI_TEST(JPH_Shape_GetTrianglesContext, JPH::Shape::GetTrianglesContext);
    ABI_TEST(JPH_Shape_Stats, JPH::Shape::Stats);

    ABI_TEST(JPH_SubShapeIDCreator, JPH::SubShapeIDCreator);
    // ABI_TEST_OFFSET_OF(JPH_SubShapeIDCreator, id, JPH::SubShapeIDCreator, mId);
    // ABI_TEST_OFFSET_OF(JPH_SubShapeIDCreator, currentBit, JPH::SubShapeIDCreator, mCurrentBit);

    ABI_TEST(JPH_TransformedShape, JPH::TransformedShape);
    ABI_TEST_OFFSET_OF(JPH_TransformedShape, shapePositionCOM, JPH::TransformedShape, mShapePositionCOM);
    ABI_TEST_OFFSET_OF(JPH_TransformedShape, shapeRotation, JPH::TransformedShape, mShapeRotation);
    ABI_TEST_OFFSET_OF(JPH_TransformedShape, shape, JPH::TransformedShape, mShape);
    ABI_TEST_OFFSET_OF(JPH_TransformedShape, shapeScale, JPH::TransformedShape, mShapeScale);
    ABI_TEST_OFFSET_OF(JPH_TransformedShape, bodyID, JPH::TransformedShape, mBodyID);
    ABI_TEST_OFFSET_OF(JPH_TransformedShape, subShapeIDCreator, JPH::TransformedShape, mSubShapeIDCreator);

    ABI_TEST(JPH_BodyManager_BodyStats, JPH::BodyManager::BodyStats);
    ABI_TEST(JPH_EBodyType, JPH::EBodyType);
    ABI_TEST(JPH_ECanSleep, JPH::ECanSleep);
    ABI_TEST(JPH_EMotionQuality, JPH::EMotionQuality);
    ABI_TEST(JPH_EMotionType, JPH::EMotionType);
    ABI_TEST(JPH_EAllowedDOFs, JPH::EAllowedDOFs);
    ABI_TEST(JPH_EOverrideMassProperties, JPH::EOverrideMassProperties);
    ABI_TEST(JPH_BodyCreationSettings, JPH::BodyCreationSettings);
    ABI_TEST(JPH_SoftBodyCreationSettings, JPH::SoftBodyCreationSettings);
    ABI_TEST(JPH_EActivation, JPH::EActivation);
    ABI_TEST(JPH_BodyManager_MutexMask, JPH::BodyManager::MutexMask);

    ABI_TEST(JPH_EPhysicsUpdateError, JPH::EPhysicsUpdateError);

    ABI_TEST(JPH_PhysicsStepListenerContext, JPH::PhysicsStepListenerContext);
    ABI_TEST_OFFSET_OF(JPH_PhysicsStepListenerContext, deltaTime, JPH::PhysicsStepListenerContext, mDeltaTime);
    ABI_TEST_OFFSET_OF(JPH_PhysicsStepListenerContext, isFirstStep, JPH::PhysicsStepListenerContext, mIsFirstStep);
    ABI_TEST_OFFSET_OF(JPH_PhysicsStepListenerContext, isLastStep, JPH::PhysicsStepListenerContext, mIsLastStep);
    ABI_TEST_OFFSET_OF(JPH_PhysicsStepListenerContext, physicsSystem, JPH::PhysicsStepListenerContext, mPhysicsSystem);

#ifdef JOLTC_DEBUG_RENDERER
    ABI_TEST(JPH_DebugRenderer_ECastShadow, JPH::DebugRenderer::ECastShadow);
    ABI_TEST(JPH_DebugRenderer_EDrawMode, JPH::DebugRenderer::EDrawMode);
    ABI_TEST(JPH_DebugRenderer_ECullMode, JPH::DebugRenderer::ECullMode);
    ABI_TEST(JPH_ESoftBodyConstraintColor, JPH::ESoftBodyConstraintColor);
    ABI_TEST(JPH_BodyManager_EShapeColor, JPH::BodyManager::EShapeColor);
    ABI_TEST(JPH_BodyManager_DrawSettings, JPH::BodyManager::DrawSettings);
#endif

    ABI_TEST(JPH_CharacterContact, JPH::CharacterContact);
    ABI_TEST_OFFSET_OF(JPH_CharacterContact, bodyB, JPH::CharacterContact, mBodyB);
    ABI_TEST_OFFSET_OF(JPH_CharacterContact, characterIDB, JPH::CharacterContact, mCharacterIDB);
    ABI_TEST_OFFSET_OF(JPH_CharacterContact, subShapeIDB, JPH::CharacterContact, mSubShapeIDB);
    ABI_TEST_OFFSET_OF(JPH_CharacterContact, position, JPH::CharacterContact, mPosition);
    ABI_TEST_OFFSET_OF(JPH_CharacterContact, linearVelocity, JPH::CharacterContact, mLinearVelocity);
    ABI_TEST_OFFSET_OF(JPH_CharacterContact, contactNormal, JPH::CharacterContact, mContactNormal);
    ABI_TEST_OFFSET_OF(JPH_CharacterContact, surfaceNormal, JPH::CharacterContact, mSurfaceNormal);
    ABI_TEST_OFFSET_OF(JPH_CharacterContact, distance, JPH::CharacterContact, mDistance);
    ABI_TEST_OFFSET_OF(JPH_CharacterContact, fraction, JPH::CharacterContact, mFraction);
    ABI_TEST_OFFSET_OF(JPH_CharacterContact, motionTypeB, JPH::CharacterContact, mMotionTypeB);
    ABI_TEST_OFFSET_OF(JPH_CharacterContact, isSensorB, JPH::CharacterContact, mIsSensorB);
    ABI_TEST_OFFSET_OF(JPH_CharacterContact, characterB, JPH::CharacterContact, mCharacterB);
    ABI_TEST_OFFSET_OF(JPH_CharacterContact, userData, JPH::CharacterContact, mUserData);
    ABI_TEST_OFFSET_OF(JPH_CharacterContact, material, JPH::CharacterContact, mMaterial);
    ABI_TEST_OFFSET_OF(JPH_CharacterContact, hadCollision, JPH::CharacterContact, mHadCollision);
    ABI_TEST_OFFSET_OF(JPH_CharacterContact, wasDiscarded, JPH::CharacterContact, mWasDiscarded);
    ABI_TEST_OFFSET_OF(JPH_CharacterContact, canPushCharacter, JPH::CharacterContact, mCanPushCharacter);
    ABI_TEST_OFFSET_OF(JPH_CharacterContact, isBackFacingContact, JPH::CharacterContact, mIsBackFacingContact);

    ABI_TEST(JPH_CharacterContactSettings, JPH::CharacterContactSettings);
    ABI_TEST_OFFSET_OF(JPH_CharacterContactSettings, canPushCharacter, JPH::CharacterContactSettings, mCanPushCharacter);
    ABI_TEST_OFFSET_OF(JPH_CharacterContactSettings, canReceiveImpulses, JPH::CharacterContactSettings, mCanReceiveImpulses);
}

JOLTC_POP_WARNINGS()
