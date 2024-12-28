#include "Header.h"

int main() {

	while (true) {


		sf::RenderWindow Ventana(sf::VideoMode(800, 600), "ola");
		Ventana.setFramerateLimit(60);

		vector<asteroids> vecast;
		vector<partchoques> vesprit;

		asteroids nasteroide(1);
		vecast.push_back(nasteroide);

		for (int i = 0; i < 8; i++)
		{
			asteroids nasteroide(0);
			vecast.push_back(nasteroide);

		}

		int numast = 0;


		sf::Texture jearts;
		jearts.loadFromFile("hearts" + to_string(3) + ".png");
		sf::Sprite spriter(jearts);
		spriter.setColor(sf::Color::Red);
		spriter.setScale(0.1, 0.1);
		spriter.setPosition(spriter.getPosition().x + 18, spriter.getPosition().y);

		float timer = 0.0f;
		sf::Clock clock;
		sf::Clock colclock;
		sf::Clock Timerclo;
		sf::Clock Timerbuzz;
		sf::Clock Tbuzz;
		sf::Clock speed;
		sf::Clock hearttt;
		//Dibujos extras

		Dibujo1.setOrigin(Dibujo1.getSize().x / 2, Dibujo1.getSize().y / 2);
		Dibujo1.setOutlineThickness(5);
		Dibujo1.setOutlineColor(sf::Color::Green);
		Dibujo1.setFillColor(sf::Color::Transparent);
		Dibujo1.setPosition(400, 300);

		DibujoPlaneta2.loadFromFile("PLANET2.png");
		sf::Sprite Planetaback2;
		Planetaback2.setTexture(DibujoPlaneta2);
		Planetaback2.setScale(2, 2);
		Planetaback2.setOrigin(DibujoPlaneta2.getSize().x / 2, DibujoPlaneta2.getSize().y / 2);
		Planetaback2.setPosition(600, 100);

		Background.loadFromFile("pngwing.com.png");
		Background.setSmooth(true);
		sf::CircleShape circulo(500);
		circulo.setTexture(&Background);
		circulo.setOrigin(circulo.getRadius(), circulo.getRadius());
		circulo.setPosition(400, 300);
		circulo.setFillColor(sf::Color(255, 255, 255, 120));
		DibujoPlaneta.loadFromFile("PLANET.png");
		DibujoPlaneta.setSmooth(true);
		sf::Sprite Planetaback;
		Planetaback.setTexture(DibujoPlaneta);
		Planetaback.setScale(0.5, 0.5);
		Planetaback.setOrigin(40, 40);
		Planetaback.setPosition(300, 200);

		sf::CircleShape inicio = circulo;
		double transini = 200;
		inicio.setOrigin(inicio.getRadius(), inicio.getRadius());
		inicio.setFillColor(sf::Color(255, 255, 255, transini));
		bool iniciot = 1;

		DibujoPlaneta3.loadFromFile("BUZZ1.png");
		sf::Sprite Planetaini;
		Planetaini.setTexture(DibujoPlaneta3);
		Planetaini.setOrigin(DibujoPlaneta3.getSize().x / 2, DibujoPlaneta3.getSize().y / 2);
		Planetaini.setPosition(300, 200);

		trifinal.setPointCount(3);
		trifinal.setRadius(500);
		trifinal.setRotation(-10);
		trifinal.setOrigin(trifinal.getRadius(), trifinal.getRadius());
		trifinal.setPosition(50, 500);
		float finaltrans = 0;
		bool finaal = 0;

		sf::Text timertext;
		sf::Text text2;
		sf::CircleShape mos;
		mos.setRadius(4);
		mos.setFillColor(sf::Color::White);
		mos.setOrigin(mos.getRadius(), mos.getRadius());


		//HITBOX SETS

		Hitbox.setOrigin(Hitbox.getSize().x / 2, Hitbox.getSize().y / 2);
		Hitbox.setFillColor(sf::Color::White);

		HitboxY.setOrigin(HitboxY.getSize().x / 2, HitboxY.getSize().y / 2);
		HitboxY.setFillColor(sf::Color::White);

		// Texturas choque


		for (int i = 0; i < 6; i++)
		{
			partchoques nnn(i);
			vesprit.push_back(nnn);
		}



		bool isac = 0;
		float trans = 255;

		//objetos

		buzzes buzz;
		partdead bum;
		Nave Navesita;

		//EXTRA

		float timeASTEROID = 4.0f;
		MAinFont.loadFromFile("Minecraft.ttf");
		Timertext.setFont(MAinFont);
		Timertext.setPosition(spriter.getPosition().x + 200, spriter.getPosition().y + 26);

		sf::Text textoini = Timertext;
		textoini.setString("PRESS SPACE!");
		textoini.setLetterSpacing(2);
		textoini.setOrigin(100, textoini.getScale().y / 2);
		textoini.setPosition(400, 400);
		textoini.setCharacterSize(34);
		float teini = 0.2;
		float asteroidspeed = 5;

		bool buzzis = 0;
		bool gameop = 1;

		Hitboxb.setOrigin(Hitboxb.getSize().x / 2, Hitboxb.getSize().y / 2);
		Hitboxb.setFillColor(sf::Color::White);
		Hitboxb.setPosition(-70, -90);

		sf::Music music;
		music.openFromFile("MUSIC1.mp3");
		sf::Music music2;
		music2.openFromFile("MUSIC2.mp3");
		music2.setLoop(true);
		music2.setVolume(40.f);
		music2.play();


		srand(static_cast<unsigned int>(time(nullptr)));

		//BUCLE PRINCIPAL
		while (Ventana.isOpen()) {

			sf::Event event;
			while (Ventana.pollEvent(event)) {

				if (event.type == sf::Event::Closed)
				{
					Ventana.close();
					gameop = 0;
				}


			}


			Ventana.clear(sf::Color(10, 8, 20));

			while (iniciot || transini > 0) {

				sf::Event event;
				while (Ventana.pollEvent(event)) {

					if (event.type == sf::Event::Closed)
					{
						Ventana.close();
					}


				}
				Ventana.clear(sf::Color(10, 8, 20));


				textoini.rotate(teini);

				if (textoini.getRotation() > 6 || textoini.getRotation() < -50)
				{
					teini *= -1;
				}
				inicio.move(-0.1, -0.1);
				inicio.setRadius(inicio.getRadius() + 0.1);
				Ventana.draw(inicio);
				Planetaini.rotate(0.5);
				Planetaini.setScale(Planetaini.getScale().x + 0.0001, Planetaini.getScale().y + 0.0001);
				Ventana.draw(Planetaini);
				Ventana.draw(textoini);
				Ventana.display();

				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {

					iniciot = 0;
				}

				if (iniciot == 0)
				{
					Planetaini.setColor(sf::Color(255, 255, 255, transini));
					textoini.setFillColor(sf::Color(255, 255, 255, transini));
					inicio.setFillColor(sf::Color(255, 255, 255, transini));


					transini -= 3;
				}
				if (transini <= 0)
				{
					Timerclo.restart();
					Timerbuzz.restart();
					speed.restart();
					Timerclo.restart();
					music2.stop();
					music.play();
					music.setLoop(true);

				}


			}


			timer += clock.restart().asSeconds();

			//Controles

			if (Navesita.hit(0) > 0)
			{

				if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && Navesita.rpos() >= 40)
				{
					Navesita.moove(-Navesita.rspeed(), 0);
				}
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && Navesita.rpos() <= 760)
				{
					Navesita.moove(Navesita.rspeed(), 0);
				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && Navesita.rposy() >= 50)
				{
					Navesita.moove(0, -Navesita.rspeed());
				}
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && Navesita.rposy() <= 540)
				{
					Navesita.moove(0, Navesita.rspeed());

				}


			}
			else
			{
				Navesita.color(sf::Color::Black);
				Navesita.moove(0.5, 0.6);
				Navesita.roote(2.f);
				Hitbox.setPosition(-70, 0);
				HitboxY.setPosition(-70, 0);

				//Navesita.colis(1);
			}

			//hitbox

			if (Navesita.hit(0) >= 0)
			{
				Hitbox.setPosition(Navesita.rpos(), Navesita.rposy());
				HitboxY.setPosition(Navesita.rpos(), Navesita.rposy() + 14);

			}

			Hitboxb.setPosition(buzz.rsprite().x, buzz.rsprite().y + 20);



			//Mecanicas



			if (Timerbuzz.getElapsedTime().asSeconds() >= rand() % 4 + 15 && buzzis == 0 && Navesita.hit(0) < 3)
			{
				Tbuzz.restart();

				buzz.set(0);

				buzzis = 1;

			}


			if (Hitbox.getGlobalBounds().intersects(Hitboxb.getGlobalBounds()) || HitboxY.getGlobalBounds().intersects(Hitboxb.getGlobalBounds()))
			{

				buzz.buzzend();

				Navesita.buzzheart();
				jearts.loadFromFile("hearts" + to_string(Navesita.hit(0)) + ".png");
				spriter.setTexture(jearts);
				buzzis = 0;
				Timerbuzz.restart();
				hearttt.restart();


			}

			if (hearttt.getElapsedTime().asSeconds() < 1)
			{
				jeartsanim(spriter, trans);

			}

			if (buzz.buzzupdt(Tbuzz.getElapsedTime().asSeconds()) && buzzis) {

				buzz.buzzend();
				buzzis = 0;
				Timerbuzz.restart();

			}



			if (timer >= timeASTEROID)
			{

				timer = 0.0f;
				timeASTEROID += 5;

				if (numast < 9)
				{
					numast += 1;

				}

			}

			if (!Navesita.colisactive() && Navesita.hit(0) > 0)
			{

				jeartsanim(spriter, trans);

				Navesita.shad();
				isac = 1;


			}

			if (speed.getElapsedTime().asSeconds() >= timeASTEROID)
			{
				asteroidspeed += 1;

				speed.restart();

			}







			if (colclock.getElapsedTime().asSeconds() >= 0.9 && !Navesita.colisactive()) {
				trans = 255;
				spriter.setColor(sf::Color::Red);
				Navesita.colis(0);
				Navesita.shad_();
			}

			Ventana.draw(Dibujo1);

			Planetaback2.rotate(0.11f);
			Planetaback2.move(-0.02, 0.04);
			Planetaback.rotate(0.1f);
			circulo.rotate(0.006f);
			Ventana.draw(circulo);
			Ventana.draw(Planetaback);
			Ventana.draw(Planetaback2);

			for (int i = 0; i < numast + 1; i++)
			{

				vecast[i].movement(Navesita.rpos(), asteroidspeed);
				vecast[i].draw(Ventana);
				vecast[i].drawhit();

				if (Hitbox.getGlobalBounds().intersects(vecast[i].drawhit()) && Navesita.colisactive() || HitboxY.getGlobalBounds().intersects(vecast[i].drawhit()) && Navesita.colisactive())
				{

					Navesita.hit(1);

					Navesita.colis(0);
					colclock.restart();
					jearts.loadFromFile("hearts" + to_string(Navesita.hit(0)) + ".png");
					spriter.setTexture(jearts);

					Timerbuzz.restart();



					if (Navesita.hit(0) >= 0)
					{

						int e = 0;

						for (auto& ye : vesprit)
						{
							e++;
							ye.pos(Navesita.postionv());

							if (e > 4 && Navesita.hit(0) > 0)
							{
								break;
							}
							else if (e > 5)
							{
								break;
							}
						}

					}


				}


			}


			if (isac && Navesita.hit(0) >= 0)
			{
				int e = 0;

				for (auto& i : vesprit)
				{
					e++;
					i.uptt();
					i.show(Ventana);

					if (e > 4 && Navesita.hit(0) > 0)
					{
						break;
					}
					else if (e > 5)
					{
						break;
					}
				}


			}





			Navesita.draw(Ventana);
			if (Navesita.hit(0) == 0)
			{
				bum.showexplo(Ventana, Navesita.postionv());

			}
			Ventana.draw(spriter);

			if (Navesita.hit(0) > 0)
			{
				int timeee = Timerclo.getElapsedTime().asSeconds();
				Timertext.setString(to_string(timeee));

				Ventana.draw(Timertext);

			}
			buzz.showbuzz(Ventana);


			if (Navesita.hit(0) <= 0)
			{	
				sf::Vector2i v = sf::Mouse::getPosition(Ventana);
				mos.setPosition(v.x, v.y);

				if (!finaal)
				{	
					timertext = Timertext;
					timertext.setString("Points: " + Timertext.getString());
					timertext.setPosition(100, 360);
					timertext.setOutlineThickness(0.1);
					timertext.setOutlineColor(sf::Color::Black);
					timertext.setOrigin(timertext.getLocalBounds().width / 2, timertext.getLocalBounds().height / 2);
					timertext.setCharacterSize(34);
					finaal = 1;

					text2 = timertext;
					text2.setString("Back to Menu");
					text2.setPosition(100, 500);



				}



				if (finaltrans < 240)
				{
					if (music.getVolume() > 20)
					{
						music.setVolume(music.getVolume() - 0.5);

					}
					finaltrans += 1;
					trifinal.setFillColor(sf::Color(160, 155, 160, finaltrans));
					timertext.setFillColor(sf::Color(100, 300, 200, finaltrans));
					text2.setFillColor(sf::Color(100, 300, 200, finaltrans));
				}

				timertext.rotate(teini);

				text2.rotate(-teini);

				if (timertext.getRotation() > 6)
				{
					teini *= -1;
				}

				Ventana.draw(trifinal);
				Ventana.draw(timertext);
				Ventana.draw(text2);



				if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && text2.getGlobalBounds().intersects(mos.getGlobalBounds()))
				{
					break;
				}

			}


			//Ventana.draw(Hitboxb);

			Ventana.display();
		}

		if (!gameop)
		{
			break;
		}

	}

}

