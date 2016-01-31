#include <SFML/Graphics.hpp>
#include <GL/glew.h>
#include <memory>

#include "make_unique.hpp"
#include "QuadTree.hpp"
#include "Renderer.hpp"
#include "Shader.hpp"
#include "ViewPort.hpp"
#include "Character.hpp"
#include "Platform.hpp"
#include "EventQueue.hpp"
#include "ParallaxBackground.hpp"


int main(void) {

    sf::ContextSettings settings;
    settings.depthBits = 8;
    settings.stencilBits = 0;
    settings.antialiasingLevel = 0;
    settings.majorVersion = 3;
    settings.minorVersion = 3;

    sf::Window window(sf::VideoMode(1440, 900), "A Game", sf::Style::Default, settings);
    window.setFramerateLimit(60);

    glewInit();
    glEnable(GL_DEPTH_TEST);

    EventQueue eventQueue;
    QuadTree quadTree(eventQueue, 2048);
    Renderer renderer({32, 32, 32, 32, 2048}, 512, 1440, 900);

    sf::Image img1;
    img1.loadFromFile("res/textures/test.png");
    Texture tex1;
    tex1.loadFromImage(img1);
    sf::Image img2;
    img2.loadFromFile("res/textures/test2.png");
    Texture tex2;
    tex2.loadFromImage(img2);

    std::vector<Platform> platforms_;
    std::vector<std::unique_ptr<GameObject>> gameObjects_;

    for (auto i=0u; i<10; ++i) {
        platforms_.emplace_back(quadTree, renderer,
                                Vector2Glf(i*32.0f, 0.0f), Vector2Glf(32.0f, 32.0f),
                                tex1, Vector2Glf(0.25f, 0.25f), 4);
    }

    sf::Image charImg;
    charImg.loadFromFile("res/textures/testChar.png");
    Texture charTex;
    charTex.loadFromImage(charImg);

    gameObjects_.push_back(make_unique<Character>(quadTree, renderer,
                           Vector2Glf(64.0f, 0.0f), Vector2Glf(64.0f, 64.0f),
                           charTex, Vector2Glf(1.0f, 1.0f), 4));

    /*for (auto j=0; j<4; ++j) {
        for (auto i=0; i<30; ++i) {
            Sprite& spr = renderer.getSpriteReference();
            spr.setTexture(&tex2);
            spr.setPosition({ 128.0f*i, 128.0f*j - 256.0f });
            spr.setDepth(0.5f);
        }
    }*/

    /*for (auto i=0; i<10; ++i) {
        Sprite& spr = renderer.getSpriteReference();
        spr.setTexture(&tex1);
        spr.setType(Sprite::TYPE_SOLID);
        spr.setScale({ 0.5f, 0.5f });
        spr.setPosition({ 128.0f*i, 0.0f });
    }*/

    ParallaxBackground bg(renderer);
    bg.addLayer("res/textures/cityBackground4.png", 0, 0.2f, { 1000.0f, 0.0f });
    bg.addLayer("res/textures/cityBackground3.png", 1, 0.3f, { 1000.0f, -600.0f });
    bg.addLayer("res/textures/cityBackground2.png", 2, 0.6f, { 6000.0f, 40.0f });
    bg.addLayer("res/textures/cityBackground1.png", 3, 0.75f, { 4500.0f, 50.0f });

    Shader shader("shaders/VS_Sprite.glsl", "shaders/FS_Sprite.glsl");

    ViewPort viewPort(1440.0f, 900.0f, Vector2Glf(0.0f, 0.0f));
    viewPort.setPosition({ 512.0f, 0.0f });

    float t = 0.0f;

    // The main loop - ends as soon as the window is closed
    while (window.isOpen()) {
        // Event processing
        sf::Event event;
        while (window.pollEvent(event)) {
            // Request for closing the window
            if (event.type == sf::Event::Closed)
                window.close();
        }
        // Activate the window for OpenGL rendering
        glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);

        /*for (auto& o : gameObjects_) {
            o->update();
        }*/

        viewPort.setPosition({2160.0f+1440.0f*cos(t*PI*0.1 + PI), 0.0f});
        bg.update(viewPort);

        renderer.render(viewPort, shader, t);

        window.display();

        t += 1.0f/60.0f;
    }

    return 0;
}
