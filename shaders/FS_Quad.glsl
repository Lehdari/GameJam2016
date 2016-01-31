#version 330 core

varying vec4 pos;
varying vec2 uv;

out vec4 color;

uniform sampler2D texture;
uniform float depth;
uniform float time;

float rand(vec2 co){
    return fract(sin(dot(co.xy ,vec2(12.9898,78.233))) * 43758.5453);
}

void main() {
    vec2 v = vec2(0.5)-uv;
    float c = length(vec2(0.5) - uv);

    float n = pow(rand(v + sin(time*10.0)), 2) * c * c * 0.5;

    color = texture2D(texture, uv * 0.9+0.05 - v*c*0.12) - vec4(n, n, n, 1.0);
}
