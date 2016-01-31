#version 330 core

varying vec4 pos;
varying vec2 uv;

out vec4 color;

uniform sampler2D texture;
uniform float depth;

float rand(vec2 co){
    return fract(sin(dot(co.xy ,vec2(12.9898,78.233))) * 43758.5453);
}

void main() {
    vec2 v = vec2(0.5)-uv;
    float c = length(vec2(0.5)-uv);

    float n = rand(v);

    color = texture2D(texture, uv * 0.86+0.06 - v*c*0.18) + vec4(0.1*n, 0.1*n, 0.1*n, 1.0);
}
