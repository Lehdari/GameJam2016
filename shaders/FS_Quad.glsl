#version 330 core

varying vec4 pos;
varying vec2 uv;

out vec4 color;

uniform sampler2D texture;
uniform float depth;

void main() {
    color = texture2D(texture, uv);
}
