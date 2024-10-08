#include "cube.h"

#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "../graphics/shaders.h"
#include "../graphics/shader.h"
#include "../graphics/vao.h"
#include "../graphics/vbo.h"
#include "../graphics/ebo.h"
#include "data.h"

int Cube::width = 0;
int Cube::height = 0;
Shader* Cube::shaderProgram = nullptr;
VAO* Cube::vao = nullptr;
VBO* Cube::vbo = nullptr;
EBO* Cube::ebo = nullptr;
float Cube::delta_x = 0;
float Cube::delta_y = 0;

void Cube::setupGraphics(int w, int h)
{
    width = w;
    height = h;

    glViewport(0, 0, width, height);

    shaderProgram = new Shader(vertexShaderSource, fragmentShaderSource);

    // VAO
    vao = new VAO();
    vao->bind();

    // VBO
    vbo = new VBO(vertices, sizeof(vertices));

    // EBO
    ebo = new EBO(indices, sizeof(indices));

    // Привязка атрибутов
    vao->linkAttrib(*vbo, 0, 3, GL_FLOAT, 8 * sizeof(float), (void*)0);
    vao->linkAttrib(*vbo, 1, 3, GL_FLOAT, 8 * sizeof(float), (void*)(3 * sizeof(float)));
    vao->linkAttrib(*vbo, 2, 2, GL_FLOAT, 8 * sizeof(float), (void*)(6 * sizeof(float)));

    glEnable(GL_DEPTH_TEST);
}

void Cube::renderFrame()
{
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);

    // Активация шейдера
    shaderProgram->activate();

    auto model = glm::mat4(1.0f);
    auto view = glm::mat4(1.0f);
    auto proj = glm::mat4(1.0f);

    model = glm::rotate(model, glm::radians(std::abs(delta_x)), glm::vec3(1.0f, delta_x, 1.0f));
    model = glm::rotate(model, glm::radians(std::abs(delta_y)), glm::vec3(delta_y, 1.0f, 1.0f));
    view = glm::translate(view, glm::vec3(0.0f, 0.0f, -4.0f));
    proj = glm::perspective(glm::radians(60.0f), (float)width / (float)height, 0.1f, 100.0f);

    int modelLoc = glGetUniformLocation(shaderProgram->ID, "model");
    glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
    int viewLoc = glGetUniformLocation(shaderProgram->ID, "view");
    glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
    int projLoc = glGetUniformLocation(shaderProgram->ID, "proj");
    glUniformMatrix4fv(projLoc, 1, GL_FALSE, glm::value_ptr(proj));

    vao->bind();
    glDrawElements(GL_TRIANGLES, sizeof(indices) / sizeof(int), GL_UNSIGNED_INT, 0);
}

void Cube::rotate(float d_x, float d_y)
{
    delta_x = d_x;
    delta_y = d_y;
}

void Cube::destroy()
{
    vao->destroy();
    vbo->destroy();
    ebo->destroy();
    shaderProgram->destroy();

    delete vao;
    delete vbo;
    delete ebo;
    delete shaderProgram;
}
