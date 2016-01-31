#version 330 core

layout(location = 0) in vec3 position;

out vec4 pos;
out vec2 uv;

uniform float depth;

void main() {
    pos = vec4(position.xy, depth, 1.0);
    uv = position.xy*0.5 + 0.5;
    gl_Position = pos;
}
