//
// mSFML
//

#include <iostream>
#include "mSFML.hpp"

mSFML::mSFML(const std::string &windowName, const int winX, const int winY, const std::string &fontPath)
	: _window(sf::VideoMode(winX, winY), windowName.c_str()),
	_winX(winX),
	_winY(winY),
	_frameClock(),
	_current_key(NONE),
	_key_map({ {sf::Keyboard::Unknown,	IGui::NONE},
		 {sf::Keyboard::Space,	IGui::SPACE},
		 {sf::Keyboard::Right,	IGui::RIGHT},
		 {sf::Keyboard::Left,	IGui::LEFT},
		 {sf::Keyboard::Up,		IGui::UP},
		 {sf::Keyboard::Down,	IGui::DOWN},
		 {sf::Keyboard::Num0,	IGui::K_0},
		 {sf::Keyboard::Num1,	IGui::K_1},
		 {sf::Keyboard::Num2,	IGui::K_2},
		 {sf::Keyboard::Num3,	IGui::K_3},
		 {sf::Keyboard::Num4,	IGui::K_4},
		 {sf::Keyboard::Num5,	IGui::K_5},
		 {sf::Keyboard::Num6,	IGui::K_6},
		 {sf::Keyboard::Num7,	IGui::K_7},
		 {sf::Keyboard::Num8,	IGui::K_8},
		 {sf::Keyboard::Num9,	IGui::K_9} })

{
	this->_window.setFramerateLimit(60);
	if (fontPath != "")
		this->loadFont(fontPath);

	std::cout << "[Window::Window] "
		<< windowName << " "
		<< winX << "x"
		<< winY
		<< std::endl;
}

mSFML::~mSFML() {}

/*
** Window
*/
void			mSFML::update(void)
{
	_frameTime = _frameClock.restart();
}

bool			mSFML::isAlive(void)
{
	return (_window.isOpen());
}

void			mSFML::display(void)
{
	_window.display();
}

void			mSFML::clear(void)
{
	_window.clear(sf::Color::Blue);
}

/*
** Keyboard Event
*/
void			mSFML::handleEvents(void)
{
	sf::Event		event;

	while (this->_window.pollEvent(event))
	{
		switch (event.type)
		{
		case sf::Event::Closed:
			if (DEBUG)
				std::cout << "[Window::handleEvents] Closed window event" << std::endl;
			this->_window.close();
			break;
		case sf::Event::KeyPressed:
			if (event.key.code == sf::Keyboard::Escape)
			{
				if (DEBUG)
					std::cout << "[Window::handleEvents] Closed window event" << std::endl;
				this->_window.close();
			}
			else if (event.key.code)
			{
				if ((this->_current_key = this->_key_map[event.key.code]) == NONE)
					std::cout << "[key pressed] => code : [" << event.key.code
					<< "] /!\\ hasnt been found /!\\" << std::endl;
			}
			break;
		case sf::Event::KeyReleased:
			this->_current_key = NONE;
		default:
			break;
		}
	}
}

IGui::Key		mSFML::getKey(void) const
{
	return (this->_current_key);
}

/*
** Mouse Events
*/
unsigned int		mSFML::getMouseX(void) const
{
	return (this->_mouse.getPosition(this->_window).x);
}

unsigned int		mSFML::getMouseY(void) const
{
	return (this->_mouse.getPosition(this->_window).y);
}

bool				mSFML::buttonLeftIsClicked(void) const
{
	return (this->_mouse.isButtonPressed(sf::Mouse::Button::Left));
}

bool				mSFML::buttonRightIsClicked(void) const
{
	return (this->_mouse.isButtonPressed(sf::Mouse::Button::Right));
}

/*
** Font
*/
void				mSFML::loadFont(const std::string &path)
{
	this->_font.loadFromFile(path);
}

void				mSFML::writeAt(const std::string &msg,
	const float x, const float y,
	const unsigned int hexaColorCode,
	const float scale)
{
	std::vector<unsigned int> rgb = hexaToRgb(hexaColorCode);
	sf::Text text;

	text.setFont(this->_font);
	text.setString(msg);
	text.setFillColor(sf::Color(rgb[0], rgb[1], rgb[2]));
	text.setScale(scale, scale);
	text.setPosition(x, y);
	this->_window.draw(text);
}

/*
** Animated Sprite
*/

Animation			mSFML::loadAnimation(const std::string &path)
{
	Animation		animation;
	const sf::Texture	*texture;

	if ((texture = _manager.load(path)) == NULL)
		throw std::out_of_range("Failed to load texture " + path);
	animation.setSpriteSheet(*texture);
	return (animation);
}

void				mSFML::addFrames(Animation &animation, const unsigned int nbFrame, const unsigned int x1, const unsigned int x2, const unsigned int x3, const unsigned int x4)
{
	for (unsigned int i = 0; i < nbFrame; i++)
		animation.addFrame(i * x1, x2, x3, x4);
}

void				mSFML::addFrame(Animation &animation, const unsigned int x1, const unsigned int x2, const unsigned int x3, const unsigned int x4)
{
	animation.addFrame(x1, x2, x3, x4);
}

void				mSFML::updateAnimatedSprite(Animation &currentAnimation, AnimatedSprite &animatedSprite, const float x, const float y)
{
	animatedSprite.play(currentAnimation);
	animatedSprite.setPosition(x, y);
	animatedSprite.update(_frameTime);
	this->_window.draw(animatedSprite);
}

void				mSFML::updateAnimatedSprite(AnimatedSprite &animatedSprite, const float x, const float y)
{
	animatedSprite.play(*animatedSprite.getAnimation());
	animatedSprite.setPosition(x, y);
	animatedSprite.update(_frameTime);
	this->_window.draw(animatedSprite);
}

void				mSFML::moveAnimatedSprite(AnimatedSprite &animatedSprite, const float x, const float y)
{
	animatedSprite.move(x * _frameTime.asSeconds(), y * _frameTime.asSeconds());
}

/*
** textures
*/
void				mSFML::setTextureAt(const std::string &path, const float x, const float y, const float scale)
{
	sf::Sprite		sprite;
	const sf::Texture	*texture;

	if ((texture = _manager.load(path)) == NULL)
		throw std::out_of_range("Failed to load texture " + path);
	sprite.setTexture(*texture);
	sprite.setPosition(x, y);
	sprite.setScale(scale, scale);
	this->_window.draw(sprite);
}

void				mSFML::setTextureRecAt(const std::string &path, const float x, const float y, const float h1, const float w1, const float h2, const float w2, const float scale)
{
	sf::Sprite		sprite;
	const sf::Texture	*texture;

	if (!(texture = _manager.load(path)))
		throw std::out_of_range("Failed to load texture " + path);
	sprite.setTexture(*texture);
	sprite.setTextureRect(sf::IntRect(h1, w1, h2, w2));
	sprite.setPosition(sf::Vector2f(x, y));
	sprite.setScale(scale, scale);
	this->_window.draw(sprite);
}

/*
** Fill Rectangle
*/
void				mSFML::fillRec(const unsigned int x, const unsigned int y, const unsigned int i, const unsigned int j, const unsigned int hexaColorCode, const unsigned int alpha)
{
	std::vector<unsigned int> rgb = hexaToRgb(hexaColorCode);
	sf::RectangleShape rectangle;

	rectangle.setPosition(sf::Vector2f(x, y));
	rectangle.setSize(sf::Vector2f(i, j));
	rectangle.setFillColor(sf::Color(rgb[0], rgb[1], rgb[2], alpha));
	this->_window.draw(rectangle);
}

void				mSFML::fillCircle(const unsigned int x, const unsigned int y, const unsigned int i, const unsigned int j, const unsigned int hexaColorCode)
{
	std::vector<unsigned int> rgb = hexaToRgb(hexaColorCode);
	sf::CircleShape circle;

	circle.setPosition(x, y);
	circle.setScale(sf::Vector2f(i, j));
	circle.setFillColor(sf::Color(rgb[0], rgb[1], rgb[2], 255));
	this->_window.draw(circle);
}
