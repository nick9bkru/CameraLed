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
  /** @brief получить цвет  
	@brief @return цвет
	*/
  string getColor();
  /** @brief получить состояние  
	@brief @return состояние
	*/
  string getState();
  /** @brief получить частотц  
	@brief @return частоту
	*/
  string getRate();
  /** @brief установить цвет  
	@brief @param цвет
	*/
  void setColor(string _color);
  /** @brief установить состояние  
	@brief @param состояние
	*/
  void setState(string _state);
  /** @brief установить частоту  
	@brief @param частоту
	*/
  void setRate(string _freq);
private:
  /** @brief цвет  */
  string color;
  /** @brief состояние  */
  string state;
  /** @brief частоту  */
  string freq;
  
};

#endif // CAMERA_H
