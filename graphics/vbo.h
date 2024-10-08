#ifndef VBO_H
#define VBO_H

#include "GLObject.h"

class VBO : public GLObject
{
public:
    VBO(GLfloat* vertices, GLsizeiptr size);

    void bind() override;
    void unbind() override;
    void destroy() override;
};

#endif // VBO_H
