#include "Camera.h"
#include <iostream>
Camera::Camera():color(""),  state(""),freq("")
{
  std::cout << "Camera::Camera()" << std::endl;
}

Camera::~Camera()
{
  std::cout << "Camera::~Camera()" << std::endl;
}

string Camera::getColor()
{
  return color;
};

string Camera::getState()
{
  return state;
};

string Camera::getRate()
{
  return freq;
};

void Camera::setColor(string _color)
{
  color = _color;
};

void Camera::setState(string _state)
{
  state = _state;
};

void Camera::setRate(string _freq)
{
  freq = _freq;
};