#include "syati.h"

class SimpleMirrorObj : public MapObjActor {
public:
	SimpleMirrorObj(const char* pName); //in SMG1, this also took a second "const char*" and what I can only assume is a Mtx pointer, but they always used NULL for both so....
	SimpleMirrorObj(const char* pName, const char* pUnk1, MtxPtr pUnk2); // I'll implement it in case someone wants to mess with it later

	virtual void init(const JMapInfoIter& rIter);
	virtual void calcAndSetBaseMtx();

	MtxPtr mUnk_C4; //0xC4 (SMG1 offset)
};