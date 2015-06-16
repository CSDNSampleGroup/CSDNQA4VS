#ifndef _OBJECT_H
#define _OBJECT_H

#if defined(_WINDLL)
#define DLL __declspec(dllexport)
#else
#define DLL _declspec(dllimport)
#endif

class DLL Object
{
public:
	Object();
	~Object();
};

typedef void(Object::*CallBack)(void *p);
typedef struct 
{
	Object* object;
	CallBack method;
} EventHandler;

#define EV_CB(_obj,_func) EventHandler{_obj,(CallBack)&_func}
#define EV_INVOKE(_cb,p) do{ \
		if(_cb.object && _cb.method) {\
			(_cb.object->*_cb.method)(p);\
							}\
	}while(0)
#endif