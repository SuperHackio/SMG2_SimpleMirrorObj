#include "SimpleMirrorObj.h"

SimpleMirrorObj::SimpleMirrorObj(const char* pName) : MapObjActor(pName, NULL)
{
	mUnk_C4 = NULL;
	MR::createSceneObj(SCENE_OBJ_MIRROR_CAMERA); // MR::createMirrorCamera((void))
}
SimpleMirrorObj::SimpleMirrorObj(const char* pName, const char* pUnk1, MtxPtr pUnk2) : MapObjActor(pName, pUnk1)
{
	mUnk_C4 = pUnk2;
	MR::createSceneObj(SCENE_OBJ_MIRROR_CAMERA); // MR::createMirrorCamera((void))
}

void SimpleMirrorObj::calcAndSetBaseMtx() {
	if (mUnk_C4 == NULL)
	{
		MapObjActor::calcAndSetBaseMtx();
		return;
	}

	// is this right? I mean, it's not going to be called anyways...
	TPos3f mtx;
	mtx.set(mUnk_C4);
	MR::setMirrorReflectionInfoFromMtxYUp(mtx);
	TVec3f vec;
	vec.set(mtx.mMtx[0][3], mtx.mMtx[1][3], mtx.mMtx[2][3]);
	MR::setBaseTRMtx(this, mUnk_C4);
}

void SimpleMirrorObj::init(const JMapInfoIter& rIter) {
	MapObjActor::init(rIter);

	MapObjActorInitInfo info;
	bool b = false;
	if (mUnk_C4 == NULL)
	{
		MapObjActorUtil::setupInitInfoSimpleMapObj(&info);
	}
	else
	{
		//setup Hio node
		info.setupConnectToScene();
		info.setupEffect(NULL, 0);
		info.setupSound(0, NULL);
		info.setupGroupClipping(0x80);
		info.setupDefaultPos();
		b = true;
	}
	info.setupMirrorReflection(b);

	MapObjActor::initialize(rIter, info);
	MR::invalidateClipping(this);
}