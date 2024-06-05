#include <iostream>
#include "lib/glad/glad.h"
#include <GLFW/glfw3.h>

// Forward declaration of methods - stops compile errors about unknown method
void error_callback(int error, const char* description);

int main() 
{
	
	if (!glfwInit()) 
	{
		std::cerr << "Failed to initialize GLFW" << std::endl;
		return -1;
	}
	
	 glfwSetErrorCallback(error_callback);

	// Create a new window with glfw and assign it to a pointer named window.
	// The window is then set as the current context, making all relevant changes apply to that window. 
	GLFWwindow* window = glfwCreateWindow(640, 480, "Yes", NULL, NULL);

	if (!window) 
	{
		std::cerr << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}

	glfwMakeContextCurrent(window);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
    	std::cerr << "Failed to initialize GLAD" << std::endl;
		return -1;
	}
	
	// This is the main loop of the application.
	while (!glfwWindowShouldClose(window)) 
	{
		glClear(GL_COLOR_BUFFER_BIT);

		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	// Cleans up the environment and memory by deconsutrcting objects and closing the application.
	glfwDestroyWindow(window);
	glfwTerminate();
	return 0;
}

void error_callback(int error, const char* description)
{
	std::cerr << error << ": " << description << std::endl;
	return;
}



