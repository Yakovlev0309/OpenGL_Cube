#ifndef EBO_H
#define EBO_H

#include "GLObject.h"

class EBO : public GLObject
{
public:
    EBO(GLuint* indices, GLsizeiptr size);

    void bind() override;
    void unbind() override;
    void destroy() override;
};

#endif // EBO_H
