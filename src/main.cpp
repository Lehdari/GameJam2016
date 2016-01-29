#include <SFML/Graphics.hpp>
#include <GL/glew.h>

#include "Renderer.hpp"
#include "Shader.hpp"


int main(void) {
    // Declare and create a new window
    sf::Window window(sf::VideoMode(800, 600), "A Game");
    // Limit the framerate to 60 frames per second (this step is optional)
    window.setFramerateLimit(60);

    glewInit();

    Renderer renderer(1024);

    sf::Image img;
    img.loadFromFile("res/textures/test.png");
    Texture tex;
    tex.loadFromImage(img);

    Sprite& spr = renderer.getReference();
    spr.setTexture(&tex);

    Shader shader("shaders/VS_Sprite.glsl", "shaders/FS_Sprite.glsl");

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
        window.setActive();
        // OpenGL drawing commands go here...

        renderer.render(shader);

        // End the current frame and display its contents on screen
        window.display();
    }

    return 0;
}
