#version 330
in vec4 vcoords;
in vec3 vnormal;
in vec4 vcolor;
in vec2 vtexturecoords;

// (ambient, diffuse, specular, shininess)
uniform vec4 material;

out vec4 fColor;

void main()
{
    fColor = vcolor;
}
