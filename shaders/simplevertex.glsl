#version 330
layout(location=0) in vec3 coords;
layout(location=1) in vec3 normal;
layout(location=2) in vec4 color;
layout(location=3) in vec2 texturecoords;

// Projection View Model and Model matrix
uniform mat4 pvm, m;
// Normal matrix
uniform mat3 nm;

out vec4 vcoords;
out vec3 vnormal;
out vec4 vcolor;
out vec2 vtexturecoords;

void main()
{
    vcoords = m * coords;
    vnormal = nm * normal;
    vcolor = color;
    vtexturecoords = texturecoords;
    gl_Position = pvm * coords;
}
