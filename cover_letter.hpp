#ifndef RICHARD_CATO_COVERLETTER_H
#define RICHARD_CATO_COVERLETTER_H

#include <cassert>
#include <string>
#include <iostream>
#include <thread>
#include <chrono>
#include <sstream>

class EmployeeDesireToWork
{
public:
	const float MIN_DESIRE = 0.85;
	void add_reason(float desire, std::string reason);
	float get_desire() {return _normalized_desire;}
	EmployeeDesireToWork(){};
	~EmployeeDesireToWork(){};
private:
	int _n_parameters;
	float _total_desire;
	float _normalized_desire;
};

class GameDevCompanyToWorkFor
{
public:
	std::string name;
protected:
	std::string ascii_logo;
public:
	void print_logo();
	void print_reason(std::string &reason);
	GameDevCompanyToWorkFor(){};
	~GameDevCompanyToWorkFor(){};
};

class RichardCato
{
public:
	bool is_this_company_the_best_choice(GameDevCompanyToWorkFor &company);
	float why_this_company(GameDevCompanyToWorkFor &company);
	void closing_statements();
	RichardCato();
	~RichardCato() {};

private:
	EmployeeDesireToWork _e_desire;
};

class SecondDinner : public GameDevCompanyToWorkFor
{
public:
	SecondDinner(){	
		name = "Second Dinner";
		ascii_logo = "\n\
						    ###\n\
                                                    ##. -#\n\
                                             ###   ##    ##\n\
                                            #+ .###.     .##\n\
                                          ##.  .#.       .##\n\
                                      ####.             .##+###\n\
                                  ###.                 ..       -###   #.#\n\
                               ##+      .-.                        .+#####\n\
                             ##.      #####-            .+#-         ..####\n\
                           #+        -#####             +####     --    .##\n\
                         ##.          .+-.               .-.            +..##\n\
                        #+                                    -#++#-       .##\n\
                       #+       ..                           #-----#.       .#######\n\
                 #-..-+#        +#+........................+#--#--#.         ....   ##\n\
               ##..########+      .................................         +###### ##\n\
              ##.-#########+                                                .#####+ ##\n\
              #+.####++####.                                                 ####-.####\n\
              ## ####. ....      ...    .......            ...  ...  +############ ##\n\
              ##.-#########.  .#######. +####### #########-#########-.############.-#\n\
               #-.+###+#####. ####+#### ###-#### #########.########## ############# ##\n\
              ## +++.  .####-.###  -### ###..##- #########  ####..###.+###-  ######..#\n\
             ## -###########--######### ###     .###..####  ###+ .###.+###+..-#####+ ##\n\
            ##.-############--###   ....###.+##-.###..####  #### .###.-#############.-#\n\
            #..#############-.####-###. +######-.####+#### .#### .###-.########+.... +##\n\
            ##... ..  .-+###. -########--######. ########+ .#### .###- ####. .....#####\n\
             ######-.####-.    .+####-  .###+.    .-+++++.  ####. +##-  .-####### ##\n\
                  #--##########-                   ..               -############ ##\n\
                  #.-############.+###+ ###+####+ #########  .#####.+#####+..#### ##\n\
                  ##- ###. .#####-+#### -########.+########-.### ###. ###-  .###+.##\n\
                   #+.###.-+ ####+ -++.  #### ###- ####.###-+##. -##+ ##########+.##\n\
                  ##+.###.-# #####.###.  ###- ###- ###. ###+######### .#######+-..###\n\
                 #....###. .#####-.###-  ###+ +##+ ###- ###++##.       ###########-..+##\n\
                ## ############## +###+  ###+ +##+ ###+ ###+.###+-###. +####-########.-#\n\
                #+.############-  #####  +###.+### ####.#### -######-.-.####+  +###..###\n\
                #-.+#########. +#-     -+  ..#-..-#++++##+-+#+ .... ### #####.-- ..###\n\
                #####+-...-+###########################################+..-+########\n\
                   ###########                                        ########    ";};
	~SecondDinner(){};
};

#endif