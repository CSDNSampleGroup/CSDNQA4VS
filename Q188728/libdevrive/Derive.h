#ifndef _DERIVE_H
#define _DERIVE_H

#include "..\libbase\Base.h"

class DLL Derive : public Object
{
public:
	Derive();
	~Derive();
public:
	void callBase();
	void setCallback(const EventHandler &cb);
	void setTest(int i);
	void onCall(Base* j);
private:
	int nTest;
	Base* pBase;
	EventHandler handler;
};

#endif