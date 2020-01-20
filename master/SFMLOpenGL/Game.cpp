#include <Game.h>

bool flip = false;
int current = 1;

Game::Game() : window(VideoMode(800, 600), "OpenGL Cube")
{

}

Game::~Game() {}

void changeThing();

vector<gpp::Vector3> cube;



// Vertices for one Triangle
float vertices[] = { 1.0f, 1.0f, -5.0f, //1
-1.0f, 1.0f, -5.0f, //2
-1.0f, -1.0f, -5.0f,  //3
1.0f, -1.0f, -5.0f, //4
-1.0f, 1.0f, -10.0f, //5
-1.0f, -1.0f, -10.0f, //6
1.0f, -1.0f, -10.0f, //7
1.0f, 1.0f, -10.0f //8
};

// Colors for those vertices 
float colors[] = { 1.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f, 1.0f, 1.0f, 1.0f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f, 0.0f };

// Index to be drawn
unsigned int vertex_index[] = { 0, 1, 2,
								0, 1, 3,
								3, 2, 6,
								3, 7, 6,
								7,6,5,
								7,4,5,
								4,5,1,
								5,0,1,
								5,1,2,
								5,6,2,
								4,0,3,
								4,7,3};

void Game::run()
{

	initialize();

	Event event;

	while (isRunning) {

		//cout << "Game running..." << endl;

		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
			{
				isRunning = false;
			}
		}
		update();
		render();
	}

}

void Game::initialize()
{
	isRunning = true;

	//glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glMatrixMode(GL_PROJECTION); //small, far away
	glLoadIdentity();
	gluPerspective(45.0, window.getSize().x / window.getSize().y, 1.0, 500.0);
	glMatrixMode(GL_MODELVIEW); //object moves, not us, not our view of it. its mass doesnt change


	cube.push_back(gpp::Vector3(1.0f, -1.0f, -5.0f)); //3 - 0
	cube.push_back(gpp::Vector3(-1.0f, -1.0f, -5.0f)); //2 - 1
	cube.push_back(gpp::Vector3(-1.0f, 1.0f, -5.0f)); //1 - 2
	cube.push_back(gpp::Vector3(1.0f, 1.0f, -5.0f)); //4 - 3
	cube.push_back(gpp::Vector3(1.0f, -1.0f, -10.0f)); //7 - 4
	cube.push_back(gpp::Vector3(1.0f, 1.0f, -10.0f)); //8 - 5
	cube.push_back(gpp::Vector3(-1.0f, -1.0f, -10.0f)); //6 - 6
	cube.push_back(gpp::Vector3(-1.0f, 1.0f, -10.0f)); //5 - 7
	 
}

void Game::update()
{
	elapsed = clock.getElapsedTime();

	//cout << "Update up" << endl;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		for (int i = 0; i < 8; i++)
		{
			cube[i] = Matrix3::RotationY(.1) * cube[i];

		}

		vertices[0] = (cube.at(0).x); //3
		vertices[1] = (cube.at(0).y); //1
		vertices[2] = (cube.at(0).z); //2

		vertices[3] = (cube.at(1).x); 
		vertices[4] = (cube.at(1).y); 
		vertices[5] = (cube.at(1).z); 
		
		vertices[6] = (cube.at(2).x); 
		vertices[7] = (cube.at(2).y); 
		vertices[8] = (cube.at(2).z); 

		vertices[9] = (cube.at(3).x);
		vertices[10] = (cube.at(3).y);
		vertices[11] = (cube.at(3).z);

		vertices[12] = (cube.at(4).x);
		vertices[13] = (cube.at(4).y);
		vertices[14] = (cube.at(4).z);

		vertices[15] = (cube.at(5).x);
		vertices[16] = (cube.at(5).y);
		vertices[17] = (cube.at(5).z);

		vertices[18] = (cube.at(6).x);
		vertices[19] = (cube.at(6).y);
		vertices[20] = (cube.at(6).z);

		vertices[21] = (cube.at(7).x);
		vertices[22] = (cube.at(7).y);
		vertices[23] = (cube.at(7).z);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		std::cout << "Rotate y attempt right" << std::endl;
		for (int i = 0; i < 8; i++)
		{
			cube[i] = Matrix3::RotationY(-.1) * cube[i];
		}

		vertices[0] = (cube.at(0).x); //3
		vertices[1] = (cube.at(0).y); //1
		vertices[2] = (cube.at(0).z); //2

		vertices[3] = (cube.at(1).x);
		vertices[4] = (cube.at(1).y);
		vertices[5] = (cube.at(1).z);

		vertices[6] = (cube.at(2).x);
		vertices[7] = (cube.at(2).y);
		vertices[8] = (cube.at(2).z);

		vertices[9] = (cube.at(3).x);
		vertices[10] = (cube.at(3).y);
		vertices[11] = (cube.at(3).z);

		vertices[12] = (cube.at(4).x);
		vertices[13] = (cube.at(4).y);
		vertices[14] = (cube.at(4).z);

		vertices[15] = (cube.at(5).x);
		vertices[16] = (cube.at(5).y);
		vertices[17] = (cube.at(5).z);

		vertices[18] = (cube.at(6).x);
		vertices[19] = (cube.at(6).y);
		vertices[20] = (cube.at(6).z);

		vertices[21] = (cube.at(7).x);
		vertices[22] = (cube.at(7).y);
		vertices[23] = (cube.at(7).z);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		std::cout << "Rotate x attempt up" << std::endl;
		for (int i = 0; i < 8; i++)
		{
			cube[i] = Matrix3::RotationX(.1) * cube[i];
		}

		vertices[0] = (cube.at(0).x); //3
		vertices[1] = (cube.at(0).y); //1
		vertices[2] = (cube.at(0).z); //2

		vertices[3] = (cube.at(1).x);
		vertices[4] = (cube.at(1).y);
		vertices[5] = (cube.at(1).z);

		vertices[6] = (cube.at(2).x);
		vertices[7] = (cube.at(2).y);
		vertices[8] = (cube.at(2).z);

		vertices[9] = (cube.at(3).x);
		vertices[10] = (cube.at(3).y);
		vertices[11] = (cube.at(3).z);

		vertices[12] = (cube.at(4).x);
		vertices[13] = (cube.at(4).y);
		vertices[14] = (cube.at(4).z);

		vertices[15] = (cube.at(5).x);
		vertices[16] = (cube.at(5).y);
		vertices[17] = (cube.at(5).z);

		vertices[18] = (cube.at(6).x);
		vertices[19] = (cube.at(6).y);
		vertices[20] = (cube.at(6).z);

		vertices[21] = (cube.at(7).x);
		vertices[22] = (cube.at(7).y);
		vertices[23] = (cube.at(7).z);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		std::cout << "Rotate x attempt down" << std::endl;
	
		for (int i = 0; i < 8; i++)
		{
			cube[i] = Matrix3::RotationX(-.1) * cube[i];
		}

		vertices[0] = (cube.at(0).x); //3
		vertices[1] = (cube.at(0).y); //1
		vertices[2] = (cube.at(0).z); //2

		vertices[3] = (cube.at(1).x);
		vertices[4] = (cube.at(1).y);
		vertices[5] = (cube.at(1).z);

		vertices[6] = (cube.at(2).x);
		vertices[7] = (cube.at(2).y);
		vertices[8] = (cube.at(2).z);

		vertices[9] = (cube.at(3).x);
		vertices[10] = (cube.at(3).y);
		vertices[11] = (cube.at(3).z);

		vertices[12] = (cube.at(4).x);
		vertices[13] = (cube.at(4).y);
		vertices[14] = (cube.at(4).z);

		vertices[15] = (cube.at(5).x);
		vertices[16] = (cube.at(5).y);
		vertices[17] = (cube.at(5).z);

		vertices[18] = (cube.at(6).x);
		vertices[19] = (cube.at(6).y);
		vertices[20] = (cube.at(6).z);

		vertices[21] = (cube.at(7).x);
		vertices[22] = (cube.at(7).y);
		vertices[23] = (cube.at(7).z);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		std::cout << "Translate attempt forward" << std::endl;
		
		for (int i = 0; i < 8; i++)
		{
			cube[i] = Matrix3::Translate(-.01, 0) * cube[i];
		}

		vertices[0] = (cube.at(0).x); //3
		vertices[1] = (cube.at(0).y); //1
		vertices[2] = (cube.at(0).z); //2

		vertices[3] = (cube.at(1).x);
		vertices[4] = (cube.at(1).y);
		vertices[5] = (cube.at(1).z);

		vertices[6] = (cube.at(2).x);
		vertices[7] = (cube.at(2).y);
		vertices[8] = (cube.at(2).z);

		vertices[9] = (cube.at(3).x);
		vertices[10] = (cube.at(3).y);
		vertices[11] = (cube.at(3).z);

		vertices[12] = (cube.at(4).x);
		vertices[13] = (cube.at(4).y);
		vertices[14] = (cube.at(4).z);

		vertices[15] = (cube.at(5).x);
		vertices[16] = (cube.at(5).y);
		vertices[17] = (cube.at(5).z);

		vertices[18] = (cube.at(6).x);
		vertices[19] = (cube.at(6).y);
		vertices[20] = (cube.at(6).z);

		vertices[21] = (cube.at(7).x);
		vertices[22] = (cube.at(7).y);
		vertices[23] = (cube.at(7).z);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		std::cout << "Translate attempt back" << std::endl;
		
		for (int i = 0; i < 8; i++)
		{
			cube[i] = Matrix3::Translate(.01, 0) * cube[i];

		}

		vertices[0] = (cube.at(0).x); //3
		vertices[1] = (cube.at(0).y); //1
		vertices[2] = (cube.at(0).z); //2

		vertices[3] = (cube.at(1).x);
		vertices[4] = (cube.at(1).y);
		vertices[5] = (cube.at(1).z);

		vertices[6] = (cube.at(2).x);
		vertices[7] = (cube.at(2).y);
		vertices[8] = (cube.at(2).z);

		vertices[9] = (cube.at(3).x);
		vertices[10] = (cube.at(3).y);
		vertices[11] = (cube.at(3).z);

		vertices[12] = (cube.at(4).x);
		vertices[13] = (cube.at(4).y);
		vertices[14] = (cube.at(4).z);

		vertices[15] = (cube.at(5).x);
		vertices[16] = (cube.at(5).y);
		vertices[17] = (cube.at(5).z);

		vertices[18] = (cube.at(6).x);
		vertices[19] = (cube.at(6).y);
		vertices[20] = (cube.at(6).z);

		vertices[21] = (cube.at(7).x);
		vertices[22] = (cube.at(7).y);
		vertices[23] = (cube.at(7).z);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		std::cout << "Scale attempt smol" << std::endl;
		
		for (int i = 0; i < 8; i++)
		{
			cube[i] = Matrix3::Scale(99, 99) * cube[i];

		}

		vertices[0] = (cube.at(0).x); //3
		vertices[1] = (cube.at(0).y); //1
		vertices[2] = (cube.at(0).z); //2

		vertices[3] = (cube.at(1).x);
		vertices[4] = (cube.at(1).y);
		vertices[5] = (cube.at(1).z);

		vertices[6] = (cube.at(2).x);
		vertices[7] = (cube.at(2).y);
		vertices[8] = (cube.at(2).z);

		vertices[9] = (cube.at(3).x);
		vertices[10] = (cube.at(3).y);
		vertices[11] = (cube.at(3).z);

		vertices[12] = (cube.at(4).x);
		vertices[13] = (cube.at(4).y);
		vertices[14] = (cube.at(4).z);

		vertices[15] = (cube.at(5).x);
		vertices[16] = (cube.at(5).y);
		vertices[17] = (cube.at(5).z);

		vertices[18] = (cube.at(6).x);
		vertices[19] = (cube.at(6).y);
		vertices[20] = (cube.at(6).z);

		vertices[21] = (cube.at(7).x);
		vertices[22] = (cube.at(7).y);
		vertices[23] = (cube.at(7).z);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		std::cout << "Scale attempt big" << std::endl;
		
		for (int i = 0; i < 8; i++)
		{
			cube[i] = Matrix3::Scale(101, 101) * cube[i];

		}

		vertices[0] = (cube.at(0).x); //3
		vertices[1] = (cube.at(0).y); //1
		vertices[2] = (cube.at(0).z); //2

		vertices[3] = (cube.at(1).x);
		vertices[4] = (cube.at(1).y);
		vertices[5] = (cube.at(1).z);

		vertices[6] = (cube.at(2).x);
		vertices[7] = (cube.at(2).y);
		vertices[8] = (cube.at(2).z);

		vertices[9] = (cube.at(3).x);
		vertices[10] = (cube.at(3).y);
		vertices[11] = (cube.at(3).z);

		vertices[12] = (cube.at(4).x);
		vertices[13] = (cube.at(4).y);
		vertices[14] = (cube.at(4).z);

		vertices[15] = (cube.at(5).x);
		vertices[16] = (cube.at(5).y);
		vertices[17] = (cube.at(5).z);

		vertices[18] = (cube.at(6).x);
		vertices[19] = (cube.at(6).y);
		vertices[20] = (cube.at(6).z);

		vertices[21] = (cube.at(7).x);
		vertices[22] = (cube.at(7).y);
		vertices[23] = (cube.at(7).z);
	}

	

}

void Game::render()
{
	//cout << "Drawing" << endl;
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_COLOR_ARRAY);

	glVertexPointer(3, GL_FLOAT, 0, &vertices);
	glColorPointer(3, GL_FLOAT, 0, &colors);

	glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, &vertex_index);

	glDisableClientState(GL_COLOR_ARRAY);
	glDisableClientState(GL_VERTEX_ARRAY);

	window.display();

}

void Game::unload()
{
	//cout << "Cleaning up" << endl;
}
