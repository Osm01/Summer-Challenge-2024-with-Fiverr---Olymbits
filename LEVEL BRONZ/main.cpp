#include <iostream>
#include <iterator>
#include <math.h>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/


// 1 UP
// 2 LEFT
// 3 DOWN
// 4 RIGHT

class mini_game
{
    private :
        std::string gpu;
        int         reg0;
        int         reg1;
        int         reg2;
        int         reg3;
        int         reg4;
        int         reg5;
        int         reg6;

    public :
        mini_game(std::string g, int r0, int r1, int r2, int r3, int r4, int r5, int r6)
        {
            gpu = g;
            reg0 = r0;
            reg1 = r1;
            reg2 = r2;
            reg3 = r3;
            reg4 = r4;
            reg5 = r5;
            reg6 = r6;
        }

        std::string get_map()
        {
            return (gpu);
        }

        int         get_reg0()
        {
            return (reg0);
        }

        int         get_reg1()
        {
            return (reg1);
        }

        int         get_reg2()
        {
            return (reg2);
        }

        int         get_reg3()
        {
            return (reg3);
        }

        int         get_reg4()
        {
            return (reg4);
        }

        int         get_reg5()
        {
            return (reg5);
        }

        int         get_reg6()
        {
            return (reg6);
        }

};


int mini_game1(mini_game &game)
{
    int distance_with_ops = game.get_map().find("#", game.get_reg0()) - game.get_reg0();

    if (distance_with_ops < 0)
        return 1337;
    return (distance_with_ops);

}

int mini_game2(mini_game &game)
{
    int wind_strength = (int)game.get_map()[0] - 48;

    // values 0-9 
    if (wind_strength > 9)
        return (-1);

    // TARGET (0,0)

    // Moving the x coordinate LEFT (2) or RIGHT (4)
    if (std::abs(game.get_reg0()) > std::abs(game.get_reg1()))
    {
        // Move LEFT for > 0 and Right for < 0
        if (game.get_reg0() > 0)
            return (2);
        else
            return (4);
    }
    if (game.get_reg1() > 0)
        return (1);
    return (3);
}


int translate_play(char play)
{
    // 1 UP
    // 2 LEFT
    // 3 DOWN
    // 4 RIGHT

    if (play == 'U')
        return 1;
    if (play == 'L')
        return (2);
    if (play == 'D')
        return (3);
    return (4);
}

int mini_game3(mini_game &game)
{
    // low risk => move your player by 1 space and decrease your risk by 1
    // no_risk  => move your player by 2 spaces
    // meduim_risk => move your player by 2 spaces but increase your risk by 1
    // high_risk => move your player by 3 space but increase your risk by 2

    char low_risk = game.get_map()[0];
    char no_risk = game.get_map()[1];
    char meduim_risk = game.get_map()[2];
    char high_risk = game.get_map()[3];

    // int player_risk = game.get_reg3();

    // char best_play = '0';

    // if (player_risk + 2 <= 5)
    // {
    //     best_play = low_risk
    // }
    //     best_play = high_risk;
    // else if (player_risk + 1 < 5)
    //     best_play = meduim_risk;
    // else if (player_risk < )
    return (translate_play(no_risk));
}

int mini_game4(mini_game &game)
{
    return (translate_play(game.get_map()[0]));
}

double Distance(double x1, double y1, double x2, double y2) 
{
    return std::sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}



int best_play(std::vector<mini_game> &games, int &is_reseting)
{
    int best_mg1 = mini_game1(games[0]);
    int best_mg2 = mini_game2(games[1]);
    int best_mg4 = mini_game4(games[3]);

    int distance_p_aim = (Distance(games[1].get_reg0(), games[1].get_reg1(), 0, 0));
    int distance_e0_aim = (Distance(games[1].get_reg2(), games[1].get_reg3(), 0, 0));
    int distance_e1_aim = (Distance(games[1].get_reg4(), games[1].get_reg5(), 0, 0));

    std::cerr << "IS RESTING " << is_reseting << " mg1 " << best_mg1 << " mg2 " << best_mg2 << std::endl;
    if (games[0].get_reg0() < games[0].get_reg1() && games[0].get_reg0() < games[0].get_reg2())
        return (best_mg1);
    if (is_reseting == 1)
    {
        is_reseting = 0;
        if (games[0].get_reg3() == 0)
            return (best_mg2);
        return (best_mg1);
    }
    if (games[3].get_map().length() == 1)
        is_reseting = 1;
    return (best_mg4);
}


int main()
{
    std::vector<mini_game> games (4, mini_game("0", 0, 0, 0, 0, 0, 0, 0));
    int is_reseting = 0;

    int player_idx;
    cin >> player_idx; cin.ignore();
    int nb_games;
    cin >> nb_games; cin.ignore();

    // game loop
    while (1) {

        for (int i = 0; i < 3; i++) {
            string score_info;
            getline(cin, score_info);
        }

        for (int i = 0; i < nb_games; i++) {
            string gpu;
            int reg_0;
            int reg_1;
            int reg_2;
            int reg_3;
            int reg_4;
            int reg_5;
            int reg_6;
            cin >> gpu >> reg_0 >> reg_1 >> reg_2 >> reg_3 >> reg_4 >> reg_5 >> reg_6; cin.ignore();

           // Saving the data
            games[i] = mini_game(gpu, reg_0, reg_1, reg_2, reg_3, reg_4, reg_5, reg_6);
        }
    
        int best_move = best_play(games, is_reseting);
        std::cerr << games[3].get_map().length() << " isResting " << is_reseting << std::endl;

        if (best_move == 1)
            std::cout << "UP" << std::endl;
        else if (best_move == 2)
            std::cout << "LEFT" << std::endl;
        else if (best_move == 3)
            std::cout << "DOWN" << std::endl;
        else
            std::cout << "RIGHT" << std::endl;
       
    }
}