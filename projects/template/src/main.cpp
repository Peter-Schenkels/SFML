
////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <random>
#include "../headers/data.h"

std::filesystem::path resourcesDir()
{
    return "resources";
}

////////////////////////////////////////////////////////////
/// Entry point of application
///
/// \return Application exit code
///
////////////////////////////////////////////////////////////
int main()
{
    std::random_device rd;
    std::mt19937       rng(rd());

    // Define some constants
    const float  gameWidth  = 800;
    const float  gameHeight = 600;

    // Create the window of the application
    sf::RenderWindow window(sf::VideoMode({static_cast<unsigned int>(gameWidth), static_cast<unsigned int>(gameHeight)}, 32),
                            "SFML",
                            sf::Style::Titlebar | sf::Style::Close);
    window.setVerticalSyncEnabled(true);

    // Create the SFML logo texture:
    sf::Texture sfmlLogoTexture;
    if (!sfmlLogoTexture.loadFromFile(resourcesDir() / "sfml_logo.png"))
        return EXIT_FAILURE;
    sf::Sprite sfmlLogo;
    sfmlLogo.setTexture(sfmlLogoTexture);
    sfmlLogo.setPosition({170.f, 50.f});


    //Template external headers code
    Data data;
    data.func();

    while (window.isOpen())
    {
        // Handle events
        for (sf::Event event; window.pollEvent(event);)
        {
            // Window closed or escape key pressed: exit
            if ((event.type == sf::Event::Closed) ||
                ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Escape)))
            {
                window.close();
                break;
            }

            // Window size changed, adjust view appropriately
            if (event.type == sf::Event::Resized)
            {
                sf::View view;
                view.setSize({gameWidth, gameHeight});
                view.setCenter({gameWidth / 2.f, gameHeight / 2.f});
                window.setView(view);
            }
        }

        // Clear the window
        window.clear(sf::Color(50, 50, 50));
        window.draw(sfmlLogo);

        // Display things on screen
        window.display();
    }

    return EXIT_SUCCESS;
}
