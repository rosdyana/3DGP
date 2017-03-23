/*
-----------------------------------------------------------------------------
Filename:    TutorialApplication.cpp
-----------------------------------------------------------------------------

This source file is part of the
   ___                 __    __ _ _    _ 
  /___\__ _ _ __ ___  / / /\ \ (_) | _(_)
 //  // _` | '__/ _ \ \ \/  \/ / | |/ / |
/ \_// (_| | | |  __/  \  /\  /| |   <| |
\___/ \__, |_|  \___|   \/  \/ |_|_|\_\_|
      |___/                              
      Tutorial Framework
      http://www.ogre3d.org/tikiwiki/
-----------------------------------------------------------------------------
*/
#include "TutorialApplication.h"

//-------------------------------------------------------------------------------------
TutorialApplication::TutorialApplication(void)
{
}
//-------------------------------------------------------------------------------------
TutorialApplication::~TutorialApplication(void)
{
}

//-------------------------------------------------------------------------------------
void TutorialApplication::createScene(void)
{
	// -----------------------------------------
	//	First Entity using penguin
	// -----------------------------------------

	// set ambient light : red-green-blue
	mSceneMgr->setAmbientLight(Ogre::ColourValue(0.5, 0.5, 0.5));

	// create a entity
	Ogre::Entity* firstEntity = mSceneMgr->createEntity("penguin.mesh");

	// create a sceen node
	Ogre::SceneNode* firstNode = mSceneMgr->getRootSceneNode()->createChildSceneNode();

	// save scene node to our entity
	firstNode->attachObject(firstEntity);

	// create a light
	Ogre::Light* light = mSceneMgr->createLight("MainLight");

	// set light position
	light->setPosition(20, 80, 50);

	// move camera position : x,y,z
	mCamera->setPosition(0, 47, 222);

	// -----------------------------------------
	//	Second Entity using ogre head
	// -----------------------------------------

	// create second entity
	Ogre::Entity* secondEntity = mSceneMgr->createEntity("ogrehead.mesh");

	// create a scene node and move to new position
	Ogre::SceneNode* secondNode =  mSceneMgr->getRootSceneNode()->createChildSceneNode(Ogre::Vector3(84, 48, 0));

	// save scene node to our entity
	secondNode->attachObject(secondEntity);

	// -----------------------------------------
	//	Third Entity using ninja and scaling + yaw
	//	yaw is rotate in Y axis
	//	pitch is rotate in X axis
	//	roll is rotate in Z axis	
	// -----------------------------------------

	// create the third entity using ninja
	Ogre::Entity* thirdEntity = mSceneMgr->createEntity("ninja.mesh");

	//create the third scene node for ninja
	Ogre::SceneNode* thirdNode = mSceneMgr->getRootSceneNode()->createChildSceneNode();
	
	// set position
	thirdNode->setPosition(0, 70, 0);

	// set scaling
	thirdNode->setScale(0.25, 0.25 , 0.25);

	// turn to front face :D
	thirdNode->yaw(Ogre::Degree(180));

	// attach the object ( entity->scene node )
	thirdNode->attachObject(thirdEntity);
	
}



#if OGRE_PLATFORM == OGRE_PLATFORM_WIN32
#define WIN32_LEAN_AND_MEAN
#include "windows.h"
#endif

#ifdef __cplusplus
extern "C" {
#endif

#if OGRE_PLATFORM == OGRE_PLATFORM_WIN32
    INT WINAPI WinMain( HINSTANCE hInst, HINSTANCE, LPSTR strCmdLine, INT )
#else
    int main(int argc, char *argv[])
#endif
    {
        // Create application object
        TutorialApplication app;

        try {
            app.go();
        } catch( Ogre::Exception& e ) {
#if OGRE_PLATFORM == OGRE_PLATFORM_WIN32
            MessageBox( NULL, e.getFullDescription().c_str(), "An exception has occured!", MB_OK | MB_ICONERROR | MB_TASKMODAL);
#else
            std::cerr << "An exception has occured: " <<
                e.getFullDescription().c_str() << std::endl;
#endif
        }

        return 0;
    }

#ifdef __cplusplus
}
#endif
