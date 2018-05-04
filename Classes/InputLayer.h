#ifndef __INPUT_LAYER_H__
#define __INPUT_LAYER_H__

#include "cocos2d.h"
#include "SingleTon.h"
#include "GlobalSetting.h"


#ifdef ENABLE_KEY_INPUT
#define KEY_CODE cocos2d::EventKeyboard::KeyCode
#endif
/* Handles input event & hold key
*/
class Input : public cocos2d::Layer,
	public SingleInstance<Input>
{
private:
	Input() {};
	virtual ~Input() {};

#ifdef ENABLE_KEY_INPUT
	// --------- keyboard -----------
	static std::map<KEY_CODE, bool> m_keyDown;
	static std::map<KEY_CODE, bool> m_key;
	static std::map<KEY_CODE, bool> m_keyUp;

	void InitKey();
#endif

	// --------- touch -----------
public:
	bool onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* e) override;
	void onTouchMoved(cocos2d::Touch* touch, cocos2d::Event* e) override;
	/**
	 * \this will be called when you ended touch 
	 * \param touch the touch of the event 
	 * \param e the event info
	 */
	void onTouchEnded(cocos2d::Touch* touch, cocos2d::Event* e) override;

	virtual bool init() override;
	// implement the "static create()" method manually
	CREATE_FUNC(Input);

#ifdef ENABLE_KEY_INPUT
	// --------- keyboard -----------
	static bool GetKeyDown(KEY_CODE);
	static bool GetKey(KEY_CODE);
	static bool GetKeyUp(KEY_CODE);

	/* Clean the stored key event
	* clean key_down & key_up
	* the events will stored again after MAIN_UPDATE & before MAIN_UPDATE (look at the kernel)
	* MUST BE CALLED AT THE END OF MAIN_UPDATE, JUST BEFORE the event re-polling
	*/
	void CleanKeyEvent();
#endif
};

#endif//__INPUT_LAYER_H__