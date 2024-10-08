#ifndef VAO_H
#define VAO_H

#include "GLObject.h"
#include "vbo.h"

class VAO : public GLObject
{
public:
    VAO();

    void linkAttrib(VBO& VBO, GLuint layout, GLuint numComponents, GLenum type, GLsizeiptr stride, void* offset);

    void bind() override;
    void unbind() override;
    void destroy() override;
};

#endif // VAO_H
