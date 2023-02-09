#pragma once
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <sstream>

class Slider
{
private:
	const int kCharacterSize = 14;
	
    int mMinValue;
	int mMaxValue;
	float mSliderPosition = 0;
 
    sf::RenderWindow& mRenderWindow;
    sf::RectangleShape mSlider;
    sf::RectangleShape mAxis;
    sf::Text mText;
    
    bool mIsPressed = false;

    void onMousePressed(const sf::Event& event)
    {
        if (event.mouseButton.button == sf::Mouse::Left) {
            sf::Vector2f mousePosition = mRenderWindow.mapPixelToCoords({event.mouseButton.x, event.mouseButton.y});
            if (mSlider.getGlobalBounds().contains(mousePosition)) 
                    mIsPressed = true;
            else if (mAxis.getGlobalBounds().contains(mousePosition))
                {
                    mIsPressed = true;
                    if (mousePosition.x + mSlider.getSize().x <= mAxis.getPosition().x + mAxis.getSize().x) {
                        mSlider.setPosition({mousePosition.x, mSlider.getPosition().y});
                        mSliderPosition = (mSlider.getPosition().x - mAxis.getPosition().x) / (mAxis.getSize().x - mSlider.getSize().x);
                    }
                    else {
                        mSlider.setPosition({mAxis.getPosition().x + mAxis.getSize().x - mSlider.getSize().x, mSlider.getPosition().y});
                        mSliderPosition = 1;
                    }
                }
            }        
    }

    void onMouseMove(const sf::Event& event)
    {
        if (!mIsPressed) {
            return;
        }
        sf::Vector2f mousePosition = mRenderWindow.mapPixelToCoords({event.mouseMove.x, event.mouseMove.y});
        if ((mousePosition.x >= mAxis.getPosition().x) && (mousePosition.x + mSlider.getSize().x <= mAxis.getPosition().x + mAxis.getSize().x)) {
            mSlider.setPosition({mousePosition.x, mSlider.getPosition().y});
        }
        else if (mousePosition.x < mAxis.getPosition().x) {
            mSlider.setPosition({mAxis.getPosition().x, mSlider.getPosition().y});
        }
        else if (mousePosition.x + mSlider.getSize().x > mAxis.getPosition().x + mAxis.getSize().x) {
            mSlider.setPosition({mAxis.getPosition().x + mAxis.getSize().x - mSlider.getSize().x, mSlider.getPosition().y});
        }

        mSliderPosition = (mSlider.getPosition().x - mAxis.getPosition().x) / (mAxis.getSize().x - mSlider.getSize().x);

    }

public:

    Slider(sf::RenderWindow& window, const sf::Font& font, sf::Vector2f position = {100,200},int min = 0, int max = 100) : mRenderWindow(window)
    {   
        mSlider.setFillColor(sf::Color::Red);
        mSlider.setSize({10,30});
        mSlider.setPosition(position - sf::Vector2f{0, 10});
        mSlider.setOutlineColor(sf::Color::Black);
        mSlider.setOutlineThickness(2);

        mAxis.setFillColor(sf::Color::White);
        mAxis.setSize({500,10});
        mAxis.setPosition(position);

        std::stringstream ss;
        ss << mMinValue;
        mText.setString(ss.str());
        mText.setFont(font);
        mText.setCharacterSize(kCharacterSize);
        mText.setFillColor(sf::Color::White);
        mText.setPosition(position + sf::Vector2f{mAxis.getSize().x + 10, -4});

        mMinValue = min;
        mMaxValue = max;
        mIsPressed = false;
    }
 
    void draw()
    {
        std::stringstream ss;
        ss << mMinValue + (mMaxValue - mMinValue) * mSliderPosition;
        mText.setString(ss.str());

		mRenderWindow.draw(mAxis);
        mRenderWindow.draw(mSlider);
        mRenderWindow.draw(mText);
    }

    int handleEvent(const sf::Event& event) {
        if (event.type == sf::Event::MouseMoved) {
            onMouseMove(event);
        }
        else if (event.type == sf::Event::MouseButtonPressed) {
            onMousePressed(event);
        }
        else if (event.type == sf::Event::MouseButtonReleased) {
            mIsPressed = false;
        }
        return mMinValue + (mMaxValue - mMinValue) * mSliderPosition;
    }
};
