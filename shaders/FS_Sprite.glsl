#version 330 core

varying vec4 pos;
varying vec4 norm;
varying vec3 col;

out vec4 color;

uniform sampler2D texture;

void main() {
    color = texture2D(texture, pos.xy);
}
