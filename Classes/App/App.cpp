#include "App.hpp"

using namespace nihil;

App::App(AppCreationArgs args)
{
	glfwInit();
	glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
	glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

	scene = new Scene();

	this->engine = args.engine;
	this->width = args.width;
	this->height = args.height;
	this->name = args.name;

	get = new Proxy(
		&width,
		&height,
		&name,
		engine,
		scene,
		window,
		&shouldClose,
		&appVersion,
		&vulkanVersion
	);

	window = glfwCreateWindow(width, height, name.c_str(), NULL, NULL);

	get->window = window;

	engine->setApp(this);
}
App::~App()
{
	glfwDestroyWindow(window);
	glfwTerminate();

	delete engine;
	delete scene;
}
void App::handle()
{
	shouldClose = glfwWindowShouldClose(window);
	glfwPollEvents();
	//engine->Draw(scene);
}