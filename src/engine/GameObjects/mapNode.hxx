#ifndef MAPNODE_HXX_
#define MAPNODE_HXX_

#include "SDL2/SDL.h"

#include <memory>
#include <string>

#include "../sprite.hxx"
#include "../basics/point.hxx"
#include "../tile.hxx"

/** @brief Class that holds map cells
 * Each tile is represented by the map cell class.   
 */
class MapNode
{
public:
  explicit MapNode(Point isoCoordinates);
  ~MapNode() = default;

  /** @brief get Sprite
    * get the Sprite* object for this cell
    * @see Sprite
    */
  Sprite *getSprite() { return _sprite.get(); };

  /// get iso coordinates of this cell
  const Point &getCoordinates() { return _isoCoordinates; };

  /** @brief get Tile ID
    * Retrieves the current Tile ID of this map cell
    * @return Returns the current Tile ID as Integer
    */
  int getTileID() { return _tileID; };

  /** @brief set Tile ID
  * Change the texture of the map cell to a specific tile id and changes the texture of the cells sprite
  * @see Resources#readTileListFile
  * @param tileID The tileID that should be rendered for this map cell
  */
  void setTileID(int tileID)
  {
    //_sprite->changeTexture(tileID);
    _tileID = tileID;
  };

  /** @brief Increase Height
    * Increases the height of the cell and its sprite
    * This function should not be called directly, but only from where the neighboring cells slopes are determined
    */
  void increaseHeight();

  /** @brief Decrease Height 
    * Decreases the height of the cell and its sprite
    * This function should not be called directly, but only from where the neighboring cells slopes are determined
    */
  void decreaseHeight();

  /** @brief Render MapNode
  * Renders the sprite object(s) of the cell
  */
  void render();

  void setElevationBitmask(unsigned char bitmask);

  unsigned char getElevationBitmask() { return _elevationBitmask; };

  void setType(const std::string &type) { _type = type; };

  std::string getType() { return _type; };
  std::string getOrientation() { return _orientation; };

private:
  Point _isoCoordinates;
  std::unique_ptr<Sprite> _sprite;

  SDL_Renderer *_renderer;
  SDL_Window *_window;

  int _tileID;
  int _maxCellHeight = 32;

  std::string _type = "Terrain";
  std::string _orientation = "default";

  unsigned char _elevationBitmask = 0;
};

#endif