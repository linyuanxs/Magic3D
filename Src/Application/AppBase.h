#pragma once
#include "OIS.h"

#define DEBUGDUMPFILE 0

namespace Ogre
{
    class RenderWindow;
}

namespace MagicApp
{
    struct FrameEvent
    {
        float timeSinceLastEvent;
        float timeSinceLastFrame;
    };

    class AppBase
    {
    public:
        AppBase(void);

        virtual bool Enter(void);
        virtual bool Update(double timeElapsed);
        virtual bool Exit(void);

        virtual bool FrameStarted(const FrameEvent& evt);
        virtual bool FrameEnded(const FrameEvent& evt);
        virtual bool MouseMoved(const OIS::MouseEvent &arg);
        virtual bool MousePressed(const OIS::MouseEvent &arg, OIS::MouseButtonID id);
        virtual bool MouseReleased(const OIS::MouseEvent &arg, OIS::MouseButtonID id);
        virtual bool KeyPressed(const OIS::KeyEvent &arg);
        virtual bool KeyReleased(const OIS::KeyEvent &arg);
        virtual void WindowResized(Ogre::RenderWindow* rw);
        virtual void WindowFocusChanged(Ogre::RenderWindow *rw);

        virtual ~AppBase(void) = 0;
    };
}
