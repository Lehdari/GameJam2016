#include <SFML/Graphics.hpp>
#include <GL/glew.h>
#include <memory>

#include "QuadTree.hpp"
#include "Renderer.hpp"
#include "Shader.hpp"
#include "ViewPort.hpp"
#include "Character.hpp"
#include "Platform.hpp"
#include "EventQueue.hpp"
#include "make_unique.hpp"


int main(void) {
    // Declare and create a new window
    sf::Window window(sf::VideoMode(1440, 900), "A Game");
    // Limit the framerate to 60 frames per second (this step is optional)
    window.setFramerateLimit(60);

    glewInit();

    EventQueue eventQueue;
    QuadTree quadTree(eventQueue, 2048);
    Renderer renderer(2048, 512);

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
                                tex1, Vector2Glf(0.25f, 0.25f));
    }

    sf::Image charImg;
    charImg.loadFromFile("res/textures/testChar.png");
    Texture charTex;
    charTex.loadFromImage(charImg);

    /*Character character(quadTree, renderer,
                        Vector2Glf(64.0f, 256.0f), Vector2Glf(64.0f, 64.0f),
                        charTex, Vector2Glf(1.0f, 1.0f);*/
    gameObjects_.push_back(make_unique<Character>(quadTree, renderer,
                        Vector2Glf(64.0f, 256.0f), Vector2Glf(64.0f, 64.0f),
                        charTex, Vector2Glf(1.0f, 1.0f)));
/*
    for (auto j=0; j<4; ++j) {
        for (auto i=0; i<10; ++i) {
            Sprite& spr = renderer.getSpriteReference();
            spr.setTexture(&tex2);
            spr.setPosition({ 128.0f*i, 128.0f*j - 256.0f });
        }
    }

    for (auto i=0; i<10; ++i) {
        Sprite& spr = renderer.getSpriteReference();
        spr.setTexture(&tex1);
        spr.setType(Sprite::TYPE_SOLID);
        spr.setScale({ 0.5f, 0.5f });
        spr.setPosition({ 128.0f*i, 0.0f });
    }
*/
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

        for (auto& o : gameObjects_) {
            o->update();
        }

        renderer.render(viewPort, shader);

        //viewPort.setPosition( {t*20, 0.0f} );
        //spr.setScale( { cos(t*PI*0.25)+1.5f, cos(t*PI*0.15)+1.5 } );
        //spr.setRotation(-t*PI*0.45);

        // End the current frame and display its contents on screen
        window.display();

        t += 1.0f/60.0f;
    }

    return 0;
}
