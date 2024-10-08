#ifndef CUBE_H
#define CUBE_H

class Shader;
class VAO;
class VBO;
class EBO;

class Cube
{
private:
        static int width, height;
        static Shader* shaderProgram;
        static VAO* vao;
        static VBO* vbo;
        static EBO* ebo;
        static float delta_x;
        static float delta_y;

public:
        static void setupGraphics(int w, int h);
        static void renderFrame();
        static void rotate(float d_x, float d_y);
        static void destroy();
};

#endif // CUBE_H
