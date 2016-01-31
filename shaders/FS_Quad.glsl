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

    float d = c * c;
    float n = pow(rand(v + sin(time*10.0)), 2) * d * 0.4;

    vec2 uv2 = uv * 0.9+0.05 - v*c*0.2;

    vec3 s = vec3(0.9 + 0.3*sin(uv2.y*3.14*400.0),
                  0.9 + 0.3*sin(uv2.y*3.14*400.0 + 3.14 * 0.66),
                  0.9 + 0.3*sin(uv2.y*3.14*400.0 + 3.14 * 1.33))+0.5-d;

    vec4 t = texture2D(texture, uv2) * vec4(s, 1.0);



    color = t - t*2*vec4(n, n, n, 1.0) - d*0.3;
}
