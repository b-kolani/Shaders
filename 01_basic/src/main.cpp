#include <SFML/Graphics.hpp>
#include <iostream>
// #include <filesystem>

int main()
{
    sf::RenderWindow    window(
        sf::VideoMode({800, 600}),
        "Shader Playground"
    );

    sf::RectangleShape  rectangle;
    // rectangle.setFillColor(sf::Color::Red);
    rectangle.setSize(sf::Vector2f(300.f, 200.f));
    rectangle.setPosition(sf::Vector2f(250.f, 200.f));

    sf::VertexArray trianglesVertices(
        sf::PrimitiveType::Triangles,
        6
    );

    // Définir la géométrie une seule fois
    const float rectangleTop = 200.f;
    const float rectangleLeft = 250.f;
    const float rectangleWidth = 300.f;
    const float rectangleHeight = 300.f;
    const float rectangleRight = rectangleLeft + rectangleWidth;
    const float rectangleBottom = rectangleTop + rectangleHeight;

    // --- FIRST TRIANGLE (Vertices 0, 1, 2) ---
    trianglesVertices[0].position = sf::Vector2f(rectangleLeft, rectangleTop); // TOP LEFT
    trianglesVertices[0].color = sf::Color::Red;

    trianglesVertices[1].position = sf::Vector2f(rectangleRight, rectangleBottom); // BOTTOM RIGHT
    trianglesVertices[1].color = sf::Color::Yellow;

    trianglesVertices[2].position = sf::Vector2f(rectangleLeft, rectangleBottom); // BOTTOM LEFT
    trianglesVertices[2].color = sf::Color::Green;

    // --- SECOND TRIANGLE (Vertices 3, 4, 5) ---
    trianglesVertices[3].position = sf::Vector2f(rectangleRight, rectangleTop); // TOP RIGHT
    trianglesVertices[3].color = sf::Color::Blue;

    trianglesVertices[4].position = sf::Vector2f(rectangleRight, rectangleBottom); // BOTTOM RIGTH
    trianglesVertices[4].color = sf::Color::Yellow;

    trianglesVertices[5].position = sf::Vector2f(rectangleLeft, rectangleTop); // TOP LEFT
    trianglesVertices[5].color = sf::Color::Red;

    // Shader Object
    // std::cout << std::filesystem::current_path() << std::endl;

    const std::filesystem::path vertexShaderFilename = 
            "./01_basic/shaders/color.vert";

    const std::filesystem::path fragmentShaderFilename = 
            "./01_basic/shaders/red.frag";

    sf::Shader  shaderObj(
        vertexShaderFilename,
        fragmentShaderFilename
    );

    // Transmettre nos variables uniformes
    // au shader
    shaderObj.setUniform("top", rectangleTop);
    shaderObj.setUniform("height", rectangleHeight);
    // shaderObj.setUniform("splitRatio", 0.75f);
    shaderObj.setUniform("left", rectangleLeft);
    shaderObj.setUniform("width", rectangleWidth);
    
    sf::RenderStates renderStates;
    renderStates.shader = &shaderObj;

    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {

            if (event->is<sf::Event::Closed>())
                window.close();

        }

        window.clear();
        // window.draw(rectangle);
        // DRAW TRIANGLES VERTICES
        window.draw(trianglesVertices, renderStates);
        window.display();
    }
    return 0;
}