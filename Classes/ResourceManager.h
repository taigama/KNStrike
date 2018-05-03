#ifndef _RESOURCEMANAGER_H_
#define _RESOURCEMANAGER_H_

#include "cocos2d.h"
#include "SingleTon.h"

/** A Singleton class
 * Handles resource management
 */
class ResourceManager : public SingleTon<ResourceManager>
{
public:

	ResourceManager();
	~ResourceManager();

	
	// Loads / Unloads all sprites in the game
	void LoadSprites();
	void UnloadSprites();

	void LoadSounds();

	//// Loads / Unloads all tiled maps in the game
	//bool LoadTiledMap(std::string, cocos2d::Node*);
	//bool UnloadTiledMap();

	// Helper functions to load the tiled map
	void LoadItems();
	void LoadEnemies();		// template for now


	cocos2d::TMXTiledMap* GetMap();

	bool readyDelete;

private:

	cocos2d::TMXTiledMap* m_map;
	cocos2d::Rect m_rect_map;

	//CREATE_FUNC(Ground);

};
#endif // !_RESOURCEMANAGER_H_
