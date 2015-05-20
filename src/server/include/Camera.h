#ifndef CAMERA_H
#define CAMERA_H
#include <string>

using namespace std;
/** @class Camera
	@brief класс хранящий состояние камеры
*/
class Camera
{
public:
  Camera();
  ~Camera();
  
  string getColor();
  string getState();
  string getRate();
  
  void setColor(string _color);
  void setState(string _state);
  void setRate(string _freq);
private:
  string color;
  string state;
  string freq;
  
};

#endif // CAMERA_H
