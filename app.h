#pragma once

#include "include.h"

#include "option.h"

class App
{
public:
	App(GLFWwindow* window);
	~App();
	void run();

private:
	void window();

	bool demo_window;

	Option opt;
	GLFWwindow* m_Window;
};