#ifndef GLOBJECT_H
#define GLOBJECT_H

#include <glad/glad.h>

class GLObject {
public:
    GLuint ID;

public:
    GLObject() = default;

    virtual void bind() = 0;
    virtual void unbind() = 0;
    virtual void destroy() = 0;
};

#endif // GLOBJECT_H
