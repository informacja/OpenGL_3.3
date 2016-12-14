#include <iostream>
using namespace std;

#include <GL\glew.h>
#include <GLFW\glfw3.h>
#include <glm\glm.hpp>
using namespace glm;

int width = 800;
int height = 600;

int main() {

	//Inicjalizacja biblioteki glfw
	if (!glfwInit())
		return 1;

	//Tworzenie okna
	GLFWwindow* window = glfwCreateWindow(width, height, "Advanced OpenGL", NULL, NULL);
	glfwMakeContextCurrent(window);

	//Inicjalizacja OpenGL jeżeli problem jest z tym to znaczy że komputer nie opsługuje tej wersji
	if (glewInit() != GLEW_OK)
		return 2;

	//test glebi
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);

	//Ustalenie Danych
	vec3 vertex[] = { vec3(-0.5f, -0.5f, 0.0f), vec3(0.0f, 0.5f, 0.0f), vec3(0.5f, -0.5f, 0.0f) };

	//Zaczep dla buffora
	GLuint vao, vbo;

	//utworzenie i wpisanie danychdo buffora
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertex), vertex, GL_STATIC_DRAW);   //ważne w 2 parametrze trzeba podac wielkosc w bajtach danych

	//utworzenie obiektu vao(vertex array object)
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, NULL);


	//Pętla główna programu
	while (!glfwWindowShouldClose(window)) {

		//Czyszczenie bufforow i ustalenie kolorow 
		glClearColor(0.3f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		//ustalenie viewport
		glfwGetWindowSize(window, &width, &height);
		glViewport(0, 0, width, height);

		glBindVertexArray(vao);
		glDrawArrays(GL_TRIANGLES, 0, 3);   //Wazne w 3 parametrze trzeba podac ilosc wierzcholkow

		glfwPollEvents();
		//czyszczenie buffora okna
		glfwSwapBuffers(window);
	}

	return 0;

}