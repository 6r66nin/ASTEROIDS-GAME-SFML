#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>


using namespace std;

class Nave {

private:

	int vida = 3;
	float speed = 8.0f;
	bool colisions = 1;
	sf::Texture NABET;
	sf::Sprite NABE;
	sf::Texture shielt;
	sf::Sprite shield;
	int trans = 40;


public:

	Nave() {

		NABET.loadFromFile("Idle.png");
		NABE.setTexture(NABET);
		NABE.setScale(2,2);
		NABE.setOrigin(NABET.getSize().x / 2, NABET.getSize().y / 2);
		NABE.setPosition(400, 400);
		shielt.loadFromFile("BUZZ1.png");

	}

	void draw(sf::RenderWindow& window) {
		
		window.draw(NABE);

	}
	

	void moove(float x, float y) {


		NABE.move(x, y);


	}
	
	void roote(float x) {


		NABE.rotate(x);


	}

	float rspeed() {

		return speed;

	}

	float rpos() {

		return NABE.getPosition().x;
	}
	float rposy() {

		return NABE.getPosition().y;

	}

	auto r() {

		return NABE.getGlobalBounds();


	}

	int hit(bool t) { 
		
		if (t)
		{
			vida--; 

		}
		
		
		return vida;
	}


	void colis(bool a) {

		if (!a)
		{
			colisions = (colisions) ? 0 : 1;

		}
		else
		{
			colisions = 0;
		}
	}

	bool colisactive() {

		return colisions;

	}

	void buzzheart() {
		
		vida++;

	}



	auto postionv() {
		
		return NABE.getPosition();

	}

	void shad() {



		trans += 20;
		
		NABE.setColor(sf::Color(trans, trans, trans, 255));

	}

	void shad_ () {

		NABE.setColor(sf::Color::White);
	}

	void color(sf::Color c) {

		NABE.setColor(c);
	}

};


class asteroids {

private:

	
	int vida = 1;
	sf::Texture TExturasteroid;
	sf::Sprite asteroid;
	bool specialone;
	bool created;

public:



	asteroids(bool s){
		
		TExturasteroid.loadFromFile("Asteroid1.png");

		asteroid.setTexture(TExturasteroid);
		asteroid.setOrigin(TExturasteroid.getSize().x / 2, TExturasteroid.getSize().y / 2);
		asteroid.setScale(4,4 );
		asteroid.setPosition(-100, -asteroid.getScale().y - 20);
		created = 0;
		specialone = s;
		


	}
	
	

	void movement(float x, float speed) {


		if (!created)
		{	

			asteroid.move(0, rand() % 4 + speed);
			asteroid.rotate(0);
		}
		else
		{	

			asteroid.move(0, rand() % 2 + speed);
			asteroid.rotate(rand() % 1 + 2);

		}
		

		if (asteroid.getPosition().y > 660 && specialone)
		{	
			int num = rand() % 2 + 1;
			asteroid.setPosition(x, -asteroid.getScale().y - 20);
			created = 1;
			TExturasteroid.loadFromFile("Asteroid" + to_string(num) + ".png");
			asteroid.setRotation(rand() % 300);
			
			if (num == 1)
			{
				asteroid.setScale(2,2);
				asteroid.setOrigin(TExturasteroid.getSize().x / 2 - 3, TExturasteroid.getSize().y / 2 - 3);

			}
			else
			{	
				asteroid.setScale(rand() % 5 + 2, rand() % 5 + 2);
				asteroid.setOrigin(TExturasteroid.getSize().x / 2 - 4, TExturasteroid.getSize().y / 2 - 4);
			}

			asteroid.setTexture(TExturasteroid);
		}
		else if (asteroid.getPosition().y > 660)
		{	
			int num = rand() % 2 + 1;
			asteroid.setPosition(rand() % 700 + 100 , -asteroid.getScale().y - 20);
			TExturasteroid.loadFromFile("Asteroid" + to_string(num) + ".png");
			asteroid.setOrigin(TExturasteroid.getSize().x / 2, TExturasteroid.getSize().y / 2);
			asteroid.setRotation(rand() % 300);
			if (num == 1)
			{
				asteroid.setScale(2, 2);
			}
			else
			{
				asteroid.setScale(rand() % 3 + 2, rand() % 3 + 2);

				asteroid.setOrigin(TExturasteroid.getSize().x / 2 - 4, TExturasteroid.getSize().y / 2 - 4);
			}

			asteroid.setTexture(TExturasteroid);

		}


	
	}
	
	auto drawhit() {

		sf::CircleShape Hitboxaster(TExturasteroid.getSize().x - asteroid.getScale().x - 8);
		Hitboxaster.setOrigin(Hitboxaster.getRadius(), Hitboxaster.getRadius());
		Hitboxaster.setFillColor(sf::Color::White);
		Hitboxaster.setPosition(asteroid.getPosition().x, asteroid.getPosition().y);
		
		return Hitboxaster.getGlobalBounds();

		
	}
	


	void draw(sf::RenderWindow& window) {

		window.draw(asteroid);
		
	}

	auto r() {

		return asteroid.getGlobalBounds();


	}

};


class buzzes {

private:
	
	sf::Texture BUZZT;
	sf::Sprite	BUZZ;
	float size;
	float trans;
	bool a = 0;
public:

	buzzes() { BUZZ.setPosition(-40, 0); }

	void set(int _num) {
		
		size = 0.18;

		BUZZT.loadFromFile("BUZZ0.png");

		
		BUZZ.setTexture(BUZZT);
		BUZZ.setOrigin(BUZZT.getSize().x / 2, BUZZT.getSize().y / 2);
		
		
		BUZZ.setScale(size, size);
		BUZZ.setColor(sf::Color::Magenta);
		
		BUZZ.setPosition(rand() % 600 + 100, rand() % 400 + 100);
		
		trans = 255;



	}

	bool buzzupdt(float time) {

		trans -= 10;
	
		if (time > 12)
		{		
			size -= 0.1;

			BUZZ.setScale(size, size);
			
		}
		else if (time>=10)
		{
			BUZZ.setColor(sf::Color(255, 255, 255, trans));
			

		}
		
		if (size < 0)
		{	
			
			BUZZ.setColor(sf::Color::Transparent);
			return 1;

		}
		else
		{
			return 0;

		}

	}

	void showbuzz(sf::RenderWindow& window) {


		window.draw(BUZZ);

	}

	auto hbuzz(){


		return BUZZ.getGlobalBounds();
	
	}


	void buzzend() {
		
		BUZZ.setPosition( -40 , 0);
	
	}
	
	auto rsprite() {

		return BUZZ.getPosition();

	}


};


class partchoques {

private:
	
	vector<sf::Texture> textt;
	vector<sf::Sprite> spritevet;
	sf::Sprite sprit;
	float speed, speedy;
	int trans = 255;

public:

	partchoques(int i) {
		
		
		sf::Texture tt;
		tt.loadFromFile("PART" + to_string(i) + ".png");
		tt.setSmooth(true);
		textt.push_back(tt);
		sprit.setOrigin(tt.getSize().x / 2, tt.getSize().y / 2);
		sprit.setScale(0.7, 0.7);
		if (i == 5)
		{
			sprit.setScale(0.1, 0.1);

		}
		sprit.setTexture(tt);
		speed = 0;
		speedy = 0;
	}

	void pos(sf::Vector2f l) {
		trans = 255;
		sprit.setColor(sf::Color(255, 255, 255, 255));
		speed = rand() % (4 - (-3) + 1) + (-3);
		speedy = rand() % 3 + 1;
		sprit.setTexture(textt[textt.size() - 1]);
		sprit.setPosition(l);
		spritevet.push_back(sprit);

	}

	void uptt() {


		spritevet[spritevet.size() - 1].rotate(2);
		spritevet[spritevet.size() - 1].move(speed,speedy);
		if (speed > 0.8)
		{
			speed -= 0.03;

		}
		if (speedy > 0.8)
		{
			speedy -= 0.03;

		}

		if (speed <=0.8 && speedy <= 0.8)
		{
			trans--;
			if (trans > 0)
			{
				spritevet[spritevet.size() - 1].setColor(sf::Color(255, 255, 255, trans));

			}
		

		}
	}

	void show(sf::RenderWindow& w) {

		w.draw(spritevet[spritevet.size() - 1]);

	}
};

class partdead
{
public:
	
	partdead() {

		for (int i = 0; i < 12; i++)
		{
			sf::Texture ola;
			ola.loadFromFile("EXPLO" + to_string(i) + ".png");
			vetexture.push_back(ola);
		}
		
		Explosion.setOrigin(vetexture[0].getSize().x / 2, vetexture[0].getSize().y / 2);
	
	}

	void showexplo(sf::RenderWindow& w, sf::Vector2f f) {
		
		time += speed;
		
		if (time >= 0.5f)
		{	
			ee++;
			frame = (frame + 1) % framem;
			time = 0;
		}
		
		Explosion.setPosition(f);
		Explosion.setTexture(vetexture[frame]);
		
		
		if (ee < 12)
		{
			w.draw(Explosion);

		}
		else if (frame < 2)
		{	

			Explosion.setPosition(f.x + rand() % 5, f.y + rand() % 7);
			w.draw(Explosion);

		}

		

		
	}
	
private:
	int ee = 0;
	int framem = 12;
	float time = 0.0f;
	float speed = 0.1;
	int frame = 0;
	vector<sf::Texture> vetexture;
	sf::Sprite Explosion;

};


void jeartsanim(sf::Sprite& f , float& trans) {


	 trans -= 20;
	 
	 f.setColor(sf::Color(255, trans, trans, 255));



}

sf::Texture DibujoPlaneta3;
sf::Texture DibujoPlaneta2;
sf::Texture Background;
sf::Texture DibujoPlaneta;


sf::RectangleShape Dibujo1(sf::Vector2f(750.f, 550.f));
sf::RectangleShape Hitbox(sf::Vector2f(20, 60));
sf::RectangleShape HitboxY(sf::Vector2f(60, 20));
sf::RectangleShape Hitboxb(sf::Vector2f(65, 65));



sf::Font MAinFont;
sf::Text Timertext;

sf::CircleShape trifinal;








