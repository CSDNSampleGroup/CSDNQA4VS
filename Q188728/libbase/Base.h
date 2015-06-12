#ifndef _BASE_H
#define _BASE_H

#include "Object.h"

class DLL Base : public Object
{
public:
	Base();
	~Base();
public:
	void setCallback(const EventHandler &cb);
	void doSomething();
private:
	EventHandler handler;
};
#endif