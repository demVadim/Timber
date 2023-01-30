#include <SFML/Graphics.hpp>

int main()
{
    sf::VideoMode vm(1920, 1080);
    sf::RenderWindow window(vm, "Timber!!!", sf::Style::Fullscreen);

    //make Fon
    sf::Texture textureBackground;
    textureBackground.loadFromFile("graphics/background.png");

    sf::Sprite spriteBackground;
    spriteBackground.setTexture(textureBackground);
    spriteBackground.setPosition(0,0);

    //make Tree sprite
    sf::Texture textureTree;
    textureTree.loadFromFile("graphics/tree.png");

    sf::Sprite spriteTree;
    spriteTree.setTexture(textureTree);
    spriteTree.setPosition(810,0);

    //make Bee
    sf::Texture textureBee;
    textureBee.loadFromFile("graphics/bee.png");

    sf::Sprite spriteBee;
    spriteBee.setTexture(textureBee);
    spriteBee.setPosition(0,800);

    bool beeActive = false;
    float beeSpeed = 0.0f;

    //make 3 Cloud
    sf::Texture textureCloud;
    textureCloud.loadFromFile("graphics/cloud.png");

    sf::Sprite spriteCloud1;
    sf::Sprite spriteCloud2;
    sf::Sprite spriteCloud3;
    spriteCloud1.setTexture(textureCloud);
    spriteCloud2.setTexture(textureCloud);
    spriteCloud3.setTexture(textureCloud);

    spriteCloud1.setPosition(0,0);
    spriteCloud2.setPosition(0,250);
    spriteCloud3.setPosition(0,500);

    bool cloud1Active = false;
    bool cloud2Active = false;
    bool cloud3Active = false;

    float cloud1Speed = 0.0f;
    float cloud2Speed = 0.0f;
    float cloud3Speed = 0.0f;

    sf::Clock clock;

    while (window.isOpen())
    {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        {
            window.close();
        }

            window.clear();
            //Measure time
            sf::Time dt = clock.restart();
            //setup the bee
            if (!beeActive)
            {
                //How fast is the bee
                srand((int)time(0));
                beeSpeed = (rand() % 200) + 200;

                //How high is bee

                srand((int)time(0) * 10);
                float height = (rand() % 500) + 500;
                spriteBee.setPosition(2000, height);
                beeActive = true;

            }
            else
            // Move the bee
            {
                spriteBee.setPosition(spriteBee.getPosition().x - (beeSpeed * dt.asSeconds()), spriteBee.getPosition().y);

                // Has the bee reached the left-hand edge of the screen?
                if (spriteBee.getPosition().x < -100)
                {
                    // Set it up ready to be a whole new bee next frame
                    beeActive = false;
                }
            }

            // Manage clouds
            // Cloud 1
            if (!cloud1Speed)
            {
                //How fast is the cloud
                srand((int)time(0) * 10);
                cloud1Speed = (rand() % 200);

                // How high is the cloud
                srand((int)time(0) * 10);
                float height = (rand() % 150);
                spriteCloud1.setPosition(-200, height);
                cloud1Active = true;
            }
            else
            {
            spriteCloud1.setPosition(spriteCloud1.getPosition().x + (cloud1Speed * dt.asSeconds()),spriteCloud1.getPosition().y);
            // Has the cloud reached the right hand edge of the screen?
            if (spriteCloud1.getPosition().x > 1920)
            {
            // Set it up ready to be a whole new cloud next frame
            cloud1Active = false;
            }
            }

            // draw scene
            window.draw(spriteBackground);
            window.draw(spriteCloud1);
            window.draw(spriteCloud2);
            window.draw(spriteCloud3);
            window.draw(spriteTree);
            window.draw(spriteBee);
            window.display();
    }


    return 0;
}
