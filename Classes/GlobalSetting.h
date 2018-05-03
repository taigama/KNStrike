#ifndef __GLOBAL_SETTING_H__
#define __GLOBAL_SETTING_H__


// ========================================================
// ================= GLOBAL FLAGS =========================

//#define ENABLE_KEY_INPUT

#define ENABLE_DEBUG_DRAW 1// 1 is no mean
#define USE_AUDIO_ENGINE 1// 1 is no mean
// --------------------------------------------------------


// ========================================================
// ================== GLOBAL VARIABLE =====================
class Global
{
public:
	// = cocos coordinate / box2d coordinate
	const static float SCALE_PHYSICS;

	//const static int MAX_COMPONENT;

	
};

const float Global::SCALE_PHYSICS = 32.0f;
//const int Global::MAX_COMPONENT = 5;
// --------------------------------------------------------

#endif//__GLOBAL_SETTING_H__