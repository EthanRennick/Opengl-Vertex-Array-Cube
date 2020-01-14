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
float vertices[] = { 1.0f, 1.0f, -5.0f, 
-1.0f, 1.0f, -5.0f,
-1.0f, -1.0f, -5.0f, 
1.0f, -1.0f, -5.0f };
// Colors for those vertices
float colors[] = { 1.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 1.0f };

// Index to be drawn
unsigned int vertex_index[] = { 0, 1, 2,
								0, 2, 3};

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

}

void Game::update()
{
	elapsed = clock.getElapsedTime();

	//cout << "Update up" << endl;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		std::cout << "Rotate y attempt left" << std::endl;
		cube[0] = Matrix3::RotationY(.1) * cube[0];
		cube[1] = Matrix3::RotationY(.1) * cube[1];
		cube[2] = Matrix3::RotationY(.1) * cube[2];
		cube[3] = Matrix3::RotationY(.1) * cube[3];
		cube[4] = Matrix3::RotationY(.1) * cube[4];
		cube[5] = Matrix3::RotationY(.1) * cube[5];

	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		std::cout << "Rotate y attempt right" << std::endl;
		cube[0] = Matrix3::RotationY(-.1) * cube[0];
		cube[1] = Matrix3::RotationY(-.1) * cube[1];
		cube[2] = Matrix3::RotationY(-.1) * cube[2];
		cube[3] = Matrix3::RotationY(-.1) * cube[3];
		cube[4] = Matrix3::RotationY(-.1) * cube[4];
		cube[5] = Matrix3::RotationY(-.1) * cube[5];
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		std::cout << "Rotate x attempt up" << std::endl;
		cube[0] = Matrix3::RotationX(.1) * cube[0];
		cube[1] = Matrix3::RotationX(.1) * cube[1];
		cube[2] = Matrix3::RotationX(.1) * cube[2];
		cube[3] = Matrix3::RotationX(.1) * cube[3];
		cube[4] = Matrix3::RotationX(.1) * cube[4];
		cube[5] = Matrix3::RotationX(.1) * cube[5];
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		std::cout << "Rotate x attempt down" << std::endl;
		cube[0] = Matrix3::RotationX(-.1) * cube[0];
		cube[1] = Matrix3::RotationX(-.1) * cube[1];
		cube[2] = Matrix3::RotationX(-.1) * cube[2];
		cube[3] = Matrix3::RotationX(-.1) * cube[3];
		cube[4] = Matrix3::RotationX(-.1) * cube[4];
		cube[5] = Matrix3::RotationX(-.1) * cube[5];

	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		std::cout << "Translate attempt forward" << std::endl;
		cube[0] = Matrix3::Translate(-.01, 0) * cube[0];
		cube[1] = Matrix3::Translate(-.01, 0) * cube[1];
		cube[2] = Matrix3::Translate(-.01, 0) * cube[2];
		cube[3] = Matrix3::Translate(-.01, 0) * cube[3];
		cube[4] = Matrix3::Translate(-.01, 0) * cube[4];
		cube[5] = Matrix3::Translate(-.01, 0) * cube[5];

	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		std::cout << "Translate attempt back" << std::endl;
		cube[0] = Matrix3::Translate(.01, 0) * cube[0];
		cube[1] = Matrix3::Translate(.01, 0) * cube[1];
		cube[2] = Matrix3::Translate(.01, 0) * cube[2];
		cube[3] = Matrix3::Translate(.01, 0) * cube[3];
		cube[4] = Matrix3::Translate(.01, 0) * cube[4];
		cube[5] = Matrix3::Translate(.01, 0) * cube[5];

	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		std::cout << "Scale attempt smol" << std::endl;
		cube[0] = Matrix3::Scale(99, 99) * cube[0];
		cube[1] = Matrix3::Scale(99, 99) * cube[1];
		cube[2] = Matrix3::Scale(99, 99) * cube[2];
		cube[3] = Matrix3::Scale(99, 99) * cube[3];
		cube[4] = Matrix3::Scale(99, 99) * cube[4];
		cube[5] = Matrix3::Scale(99, 99) * cube[5];

	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		std::cout << "Scale attempt big" << std::endl;
		cube[0] = Matrix3::Scale(101, 101) * cube[0];
		cube[1] = Matrix3::Scale(101, 101) * cube[1];
		cube[2] = Matrix3::Scale(101, 101) * cube[2];
		cube[3] = Matrix3::Scale(101, 101) * cube[3];
		cube[4] = Matrix3::Scale(101, 101) * cube[4];
		cube[5] = Matrix3::Scale(101, 101) * cube[5];

	}

	changeThing();

}

void Game::render()
{
	//cout << "Drawing" << endl;

	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_COLOR_ARRAY);

	glVertexPointer(3, GL_FLOAT, 0, &vertices);
	//glVertexPointer(3, GL_FLOAT, 0, &vertices2);
	glColorPointer(3, GL_FLOAT, 0, &colors);

	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, &vertex_index);

	glDisableClientState(GL_COLOR_ARRAY);
	glDisableClientState(GL_VERTEX_ARRAY);

	window.display();

}

void Game::unload()
{
	//cout << "Cleaning up" << endl;
}


void changeThing()
{
	glNewList(1, GL_COMPILE);
	glBegin(GL_TRIANGLES);
	{
		//face one
		//123
		glColor3f(0.0f, 0.0f, 1.0f);
		glVertex3f(cube.at(0).x, cube.at(0).y, cube.at(0).z); //3
		glVertex3f(cube.at(1).x, cube.at(1).y, cube.at(1).z); //1
		glVertex3f(cube.at(2).x, cube.at(2).y, cube.at(2).z); //2

		glColor3f(0.0f, 1.0f, 0.0f);
		glVertex3f(cube.at(0).x, cube.at(0).y, cube.at(0).z); //3
		glVertex3f(cube.at(2).x, cube.at(2).y, cube.at(2).z); //2
		glVertex3f(cube.at(3).x, cube.at(3).y, cube.at(3).z); //4

		////face two
		////437
		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex3f(cube.at(3).x, cube.at(3).y, cube.at(3).z); //4
		glVertex3f(cube.at(0).x, cube.at(0).y, cube.at(0).z); //3
		glVertex3f(cube.at(4).x, cube.at(4).y, cube.at(4).z); //7

		//487
		glColor3f(1.0f, 1.0f, 0.0f);
		glVertex3f(cube.at(3).x, cube.at(3).y, cube.at(3).z); //4
		glVertex3f(cube.at(5).x, cube.at(5).y, cube.at(5).z); //3
		glVertex3f(cube.at(4).x, cube.at(4).y, cube.at(4).z); //7


	}
	glEnd();
	glEndList();
}