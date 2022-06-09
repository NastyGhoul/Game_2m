class Wall : public sf::Drawable
{
public:
	Wall(float W_x, float W_y);
	Wall() = delete;
	~Wall() = default;
	void draw();
	void update();

private:
	void draw(RenderTarget& target, RenderStates state) const override;
	RectangleShape wallShape;
	const float wallLength{ WALL_LENGTH };
	const float wallWidth{ WALL_WIDTH };
};
Wall::Wall(float W_x, float W_y)
{
	wallShape.setPosition(W_x, W_y);
	wallShape.setSize({ this->wallWidth,this->wallLength });
	wallShape.setFillColor(Color::White);
	wallShape.setOrigin(wallWidth / 2, wallLength / 2);
}
void Wall::draw(RenderTarget& target, RenderStates state) const
{
	target.draw(this->wallShape, state);
}



