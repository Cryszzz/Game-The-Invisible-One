#version 330 core
in vec4 ParticleColor;
in vec2 TexCoords;
out vec4 color;
uniform sampler2D sprite;

void main()
{
    vec4 texColor = texture(sprite, TexCoords);
    if(texColor.a < 0.1)
        discard;
    texColor.a=texColor.a*ParticleColor.a;
    color = texColor;
}