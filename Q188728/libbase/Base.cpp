#include "Base.h"

Base::Base()
{

}

Base::~Base()
{

}

void Base::setCallback(const EventHandler &cb)
{
	handler = cb;
}

void Base::doSomething()
{
	EV_INVOKE(this->handler, this);
}

