#version 330 core

varying vec4 pos;
varying vec2 uv;

layout(location = 0) out vec4 color;

uniform sampler2D lastPass;
uniform sampler2D newPass;
uniform float depth;

void main() {
    vec4 nps = texture2D(newPass, uv);

    vec3 lp = vec3(0.0);
    for (int i=0; i<8; ++i)
        lp += texture2D(lastPass, uv+vec2(cos(i*0.25*3.14)*depth*0.004,
                                          sin(i*0.25*3.14)*depth*0.004)).rgb;
    lp *= 0.125;

    //color = texture2D(lastPass, uv)*(1.0-nps.a) + texture2D(newPass, uv)*nps.a;
    color = vec4((lp*(1.0-nps.a) + texture2D(newPass, uv).rgb*nps.a), 1.0);
    //color = vec4(texture2D(lastPass, uv).rgb*0.5 + texture2D(newPass, uv).rgb*0.5, 1.0f);
    //color = texture2D(lastPass, uv);
}
