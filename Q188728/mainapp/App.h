#ifndef _APP_H
#define _APP_H

#include "..\libdevrive\Derive.h"

class App : public Object
{
public:
	App();
	~App();
public:
	void start();
	void onCall(Derive* d);
private:
	Derive* pDerive;
};
#endif