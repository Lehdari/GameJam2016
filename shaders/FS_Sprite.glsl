#version 330 core

varying vec4 pos;
varying vec2 uv;

layout(location = 0) out vec4 color;

uniform sampler2D texture;
uniform float depth;

void main() {
    color = texture2D(texture, uv);
}
