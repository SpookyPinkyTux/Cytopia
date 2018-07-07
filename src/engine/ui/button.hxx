#ifndef BUTTON_HXX_
#define BUTTON_HXX_

#include "uiElement.hxx"

class Button : public UiElement
{
public:
  Button(int x, int y, int uiSpriteID, const std::string &groupID = "", int actionID = 0, const std::string &parentOfGroup = "")
      : UiElement(x, y, uiSpriteID, groupID, actionID, parentOfGroup){};
  Button(int x, int y, int w, int h, const std::string &text, const std::string &groupID = "", int actionID = 0,
         const std::string &parentOfGroup = "");

  ~Button() = default;

  virtual void draw();

private:
  SDL_Rect rect;

  bool _isPressed = false;
  bool _isMouseOver = false;
};

#endif