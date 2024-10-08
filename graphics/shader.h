#ifndef SHADER_H
#define SHADER_H

#include <glad/glad.h>

class Shader {
public:
    GLuint ID;

public:
    Shader(const char* vertexSource, const char* fragmentSource);

    void activate();
    void destroy();

private:
    void compileErrorsCheck(unsigned int shader, const char* type);
};

#endif // SHADER_H
