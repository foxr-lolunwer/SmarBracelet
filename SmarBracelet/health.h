#pragma once
#pragma warning( disable : 4996 )

using namespace std;
class health
{
public:
	void set_information(string name, int age, int weight, int height);
	int* test_heart_rate();
	int Intelligence_Calculate_Steps();
	string m_name;
	int m_age;
	int m_weight;
	double m_height;
	int m_heart_rate = 0;
	int BMI;
	sf::RenderWindow window_health;
	sf::Sprite user_person;
	sf::Texture user_person_img;
	sf::Sprite map;
	sf::Texture map_img;
	sf::Event event_health;
};

void health::set_information(string name, int age, int weight, int height)
{
	m_name = name;
	m_age = age;
	m_weight = weight;
	m_height = height / 100.0;
	BMI = m_weight / (m_height * m_height);
}

int*::health::test_heart_rate()
{
	srand(time(0));
	static int arr[50];
	for (int i = 0; i < 50; i++)
		arr[i] = ((rand() + i * 2) % 131) + 20;
	return arr;
}

int health::Intelligence_Calculate_Steps()
{
	int count = 0;
	sf::Vector2f user_person_position = user_person.getPosition();
	window_health.create(sf::VideoMode(735, 1188), "Map", sf::Style::Close);
	window_health.setFramerateLimit(60);
	while (true)
	{
		user_person_position = user_person.getPosition();
		window_health.waitEvent(event_health);
		if (event_health.type == sf::Event::Closed)
		{
			window_health.close();
			return count;
		}
		if (event_health.type == sf::Event::KeyPressed)
		{
			if (event_health.key.scancode == sf::Keyboard::Scan::Up && user_person_position.y - 10 >= 0 || 
				event_health.key.scancode == sf::Keyboard::Scan::W && user_person_position.y -10 >= 0)
			{
				user_person.move(sf::Vector2f(0, -10));
				count++;
			}
			else if (event_health.key.scancode == sf::Keyboard::Scan::Left && user_person_position.x - 10 >= 0 ||
				event_health.key.scancode == sf::Keyboard::Scan::A && user_person_position.x - 10 >= 0)
			{
				user_person.move(sf::Vector2f(-10, 0));
				count++;
			}
			else if (event_health.key.scancode == sf::Keyboard::Scan::Down && user_person_position.y + 10 <= 1088 ||
				event_health.key.scancode == sf::Keyboard::Scan::S && user_person_position.y + 10 <= 1088)
			{
				user_person.move(sf::Vector2f(0, 10));
				count++;
			}
			else if (event_health.key.scancode == sf::Keyboard::Scan::Right && user_person_position.x + 10 <= 635 ||
				event_health.key.scancode == sf::Keyboard::Scan::D && user_person_position.x + 10 <= 635)
			{
				user_person.move(sf::Vector2f(10, 0));
				count++;
			}
			else if (event_health.key.scancode == sf::Keyboard::Scan::Escape || 
				event_health.key.scancode == sf::Keyboard::Scan::Enter || 
				event_health.key.scancode == sf::Keyboard::Scan::NumpadEnter)
			{
				window_health.close();
				return count;
			}
			else
				continue;
		}
		window_health.clear();
		window_health.draw(map);
		window_health.draw(user_person);
		window_health.display();
	}
}