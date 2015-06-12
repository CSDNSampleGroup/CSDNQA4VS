#include "Derive.h"

Derive::Derive()
{
	pBase = new Base();
}

Derive::~Derive()
{

}

void Derive::callBase()
{
	pBase->setCallback(EV_CB(this, Derive::onCall));
//	pBase->setCallback(this->handler);
	pBase->doSomething();
}

void Derive::setCallback(const EventHandler &cb)
{
	handler = cb;
}

void Derive::setTest(int i)
{
	nTest = i;
}

void Derive::onCall(Base* b)
{
	EV_INVOKE(handler, this);
}

