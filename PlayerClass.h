class Player : public sf::Drawable
{
public:

	Player(float P_x, float P_y);
	Player() = delete;
	~Player() = default;

	void update();

	float left();
	float right();
	float up();
	float down();

private:

	CircleShape playerShape;
	const float playerRadius{ PLAYERRADIUS };
	const float playerVelocity{ PLATERVELOCITY };
	Vector2f velocity{ playerVelocity,playerVelocity };
	void draw(RenderTarget& target, RenderStates state) const override;
};
Player::Player(float P_x, float P_y)
{
	playerShape.setPosition(P_x, P_y);
	playerShape.setRadius(this->playerRadius);
	playerShape.setFillColor(Color::Red);
	playerShape.setOrigin(this->playerRadius, this->playerRadius);
}
void Player::draw(RenderTarget& target, RenderStates state) const
{
	target.draw(this->playerShape, state);
}
void Player::update()
{
	this->playerShape.move(this->velocity);
	if (Keyboard::isKeyPressed(Keyboard::Key::Left) && this->left() > 0)
	{
		velocity.x = -playerVelocity;
	}
	else if (Keyboard::isKeyPressed(Keyboard::Key::Right) && this->right() > 0)
	{
		velocity.x = playerVelocity;
	}
	else if (Keyboard::isKeyPressed(Keyboard::Key::Up) && this->up() > 0)
	{
		velocity.y = -playerVelocity;
	}
	else if (Keyboard::isKeyPressed(Keyboard::Key::Down) && this->down() > 0)
	{
		velocity.y = playerVelocity;
	}
	else
	{
		velocity.x = 0;
		velocity.y = 0;
	}
}
float Player::left()
{
	return this->playerShape.getPosition().x - playerShape.getRadius();
}
float Player::right()
{
	return this->playerShape.getPosition().x + playerShape.getRadius();
}
float Player::up()
{
	return this->playerShape.getPosition().x - playerShape.getRadius();
}
float Player::down()
{
	return this->playerShape.getPosition().x + playerShape.getRadius();
}