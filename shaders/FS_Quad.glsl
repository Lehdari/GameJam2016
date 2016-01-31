#version 330 core

varying vec4 pos;
varying vec2 uv;

out vec4 color;

uniform sampler2D texture;
uniform float depth;

void main() {
    vec2 v = vec2(0.5)-uv;
    float c = length(vec2(0.5)-uv);
    color = texture2D(texture, uv-v*c*0.15);
}
