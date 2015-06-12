#include "App.h"
#include <stdlib.h>

App::App()
{

}

App::~App()
{

}

void App::start()
{
	pDerive = new Derive();
	pDerive->setCallback(EV_CB(this,App::onCall));
	pDerive->setTest(1024);
	pDerive->callBase();
}

void App::onCall(Derive* d)
{
}

int main(int argc, char** argv)
{
	App* app = new App();
	app->start();

	system("pause");
}