#include "cover_letter.hpp"

int main()
{
	RichardCato richard_cato;
	SecondDinner second_dinner;
	bool does_workplace_match = richard_cato.is_this_company_the_best_choice(second_dinner);
	richard_cato.closing_statements();
	return 0;
}

float RichardCato::why_this_company(GameDevCompanyToWorkFor &company)
{
	std::string reason_0 = "When setting out on a journey to build my dream game, I made the classic \n\
mistake of attempting to make my first title a competitive multiplayer game. A solid two \n\
years later, several complete rebuilds, a host of referenced GDC talks, and I had my own \n\
hybrid rollback/authoritative server networking solution. The biggest takeaways from the \n\
time I spent studying and working on that project is I find a lot more value and satisfaction \n\
tackling difficult engineering problems, optimizing code, and building a scalable and \n\
maintainable foundation that others can build off of as opposed to gameplay development. \n\
I had this idea of a game that I wanted to bring to life and found myself designing the \n\
systems needed to build the game more than the game itself. The idea of working with designers,\n\
artists,and other engineers to optimize networking and making a multiplayer game feel as \n\
close to a LAN experience as possible would be a dream, because given the free time to work \n\
on anything, this is what I enjoyed the most and poured my time into.\n";

	std::string reason_1 = "I was quite excited to see Ben Brode in Second Dinner’s introduction video.\n\
I recognized his face from my time playing Hearthstone, and Second Dinner’s success with \n\
Marvel Snap comes as no surprise seeing the backgrounds of the executive team. With such \n\
incredible talent, I’m excited to see the description of the position pushing collaboration \n\
and even mentioning mentoring. It appears that Second Dinner is built on the foundation of \n\
creating an open and engaging environment for its employees, and I like how this is further \n\
encouraged by building time into the schedule to bring the team together in person a few \n\
times a year. The most valuable resource I had while pursuing indie game development has \n\
been Discord and the several communities I have found there. Keeping in touch with other \n\
developers and artists has provided a solid network where we can consult each other whenever\n\
a wall has been hit or to show off a technically challenging or clever solution. I also \n\
really appreciate that Second Dinner encourages collaboration across departments. It can be\n\
incredibly valuable to learn more about what goes into each portion of game development, \n\
and I would be thrilled to learn about how the technical artists at Second Dinner are able \n\
to make Marvel Snap visually pop so much.\n";

	std::string reason_2 = "Marvel Snap has a ton of features that make me excited not just from a gaming perspective,\n\
but also from a technical perspective. The thing that I enjoy the most about Marvel Snap is the\n\
incredible amount of juice that is packed into every part of the game. There is so much weight \n\
conveyed with each action that the player can take which makes it feel like more than just another \n\
card game. With such large effects and interactions between cards, it is also incredibly important \n\
that any client side miss predictions are smoothly handled or large events are only triggered after \n\
server verification. I’d love to work with gameplay developers, designers, and artists to make sure \n\
that the features they want to bring to a multiplayer title can work seamlessly and gracefully handle \n\
network fluctuations. When it comes to a live service title, being able to monitor not only the \n\
stability of the game but also what leads to player retention is vital, and it would be a satisfying \n\
problem to study what effects players find most rewarding and tend to drive them towards or away from \n\
certain cards and playstyles.\n";

	_e_desire.add_reason(0.95, reason_0);
	_e_desire.add_reason(0.9, reason_1);
	_e_desire.add_reason(0.95, reason_2);
	
	company.print_reason(reason_0);
	company.print_reason(reason_1);
	company.print_reason(reason_2);

	return _e_desire.get_desire();
}

bool RichardCato::is_this_company_the_best_choice(GameDevCompanyToWorkFor &company)
{
	company.print_logo();
	std::cout << "\nWhy work at " << company.name << "?\n" << std::endl;
	float desire = why_this_company(company);
	return desire >= _e_desire.MIN_DESIRE;
}

void RichardCato::closing_statements()
{
	std::cout << "------------------------------------------\n" << std::endl;
	std::cout << "I am excited to hear back from you and to discuss how I can contribute to the team at Second Dinner!" << std::endl;
	std::cout << "\n\nPress Enter to close..." << std::endl;
	std::cin.get();
}

RichardCato::RichardCato(){
	std::cout << "\n\nPress Enter to begin..." << std::endl;
	std::cin.get();
}

void EmployeeDesireToWork::add_reason(float desire, std::string reason)
{
	assert(desire <= 1.0 && desire >= 0.0);
	_total_desire += desire;
	_n_parameters++;
	_normalized_desire = _total_desire / _n_parameters;
}

void GameDevCompanyToWorkFor::print_logo()
{
	// print the ascii logo one line at a time. Each line is seperated by \n
	std::stringstream ss(ascii_logo);
    std::string line;

    while (std::getline(ss, line, '\n')) {
        std::cout << line << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(20));
    }
}

void GameDevCompanyToWorkFor::print_reason(std::string &reason)
{
	std::cout << "------------------------------------------\n" << std::endl;
	// play an ascii animation of a spinning loading wheel - / | \ - for two seconds
	std::string loading_wheel = "-/|\\";
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < loading_wheel.size(); j++)
		{
			std::cout << "\b" << loading_wheel[j] << std::flush;
			std::this_thread::sleep_for(std::chrono::milliseconds(250));
		}
	}
	std::cout << "\b" << " " << std::flush;
	std::cout << reason << std::endl;
}
