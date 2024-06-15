#include <iostream>
#include <iterator>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/


int find_close_ops(std::vector<string> &maps, std::vector<int> &player_ps, std::vector<int> &end_point)
{
    int ops = 1337;

    for (int i = 0; i < 4; i++)
    {
        int p = player_ps[i];
        if (maps[i][p] == '#')
            p ++;
        for ( ; p < maps[i].length() ; p ++)
        {
            if (maps[i][p] == '#')
                break;
        }
        if (maps[i][p] == '#')
            end_point[i] = 0;
        if (p == maps[i].length())
            end_point[i] = 1;
        if (end_point[i] == 0 && ops > (p - player_ps[i]))
            ops = p - player_ps[i];
    }
    return (ops);
}


int check_is_good_move(int move, std::vector<string> &maps, std::vector<int> &player_ps, std::vector<int> &stuns)
{
    int major = 0;
    for (int i = 0; i < 4 ; i ++)
    {
        int p = player_ps[i];
        int j = 0;
        int m = move;


        if (stuns[i] == 0)
        {
            if (move == 1)
            {
                p ++;
                m = 2;
            }
            while (j < m)
            {
                p ++;
                if (maps[i][p] != '#')
                    j ++;
                else
                    break ;
            }
            if (j == m)
                major ++;
        }
    }
    return (major);
}


int find_best_move_on_priority(int player_prio, int current_best_move ,std::vector<string> &maps, std::vector<int> &player_ps,\
                                std::vector<int> & stuns)
{
    int move = 3;
    int test_move = 0;

    // std::cerr << "stun " << stun[pla]
    if (stuns[player_prio] > 0)
        return (current_best_move);

    int p = player_ps[player_prio];
    for (int i = p; i < maps[player_prio].length() ; i++)
    {
        if (maps[player_prio][p] == '#')
            break;
        p ++;
    }
    return (p - player_ps[player_prio]);
}

int find_best_move(int move, std::vector<string> &maps, std::vector<int> &player_ps, \
                std::vector<int> &stuns, std::vector<int> &e0_stuns , std::vector<int> &e1_stuns)
{
    int best_move = move;
    int test_moves = 3;
    int test_major = 0;
    int major = check_is_good_move(move, maps, player_ps, stuns);
   
    while (test_moves <= 1)
    {
        test_major = check_is_good_move(test_moves, maps, player_ps, stuns);
        if (test_major > major)
        {
            major = test_major;
            best_move = test_moves;
        }
        test_moves --;
    }
    for (int i = 0; i < 4; i++)
    {
        if (stuns[i] > e0_stuns[i] || stuns[i] > e1_stuns[i])
        {
            best_move = find_best_move_on_priority(i, best_move, maps, player_ps, stuns);
            break;
        }
    }
   return (best_move);
}


int main()
{
    int prio = -1;
    int next_ops = 1337;
    std::vector<string> maps(4);
    std::vector<int> player_ps(4);
    std::vector<int> enemy0_ps(4);
    std::vector<int> enemy1_ps(4);
    std::vector<int> player_stun(4);
    std::vector<int> enemy0_stun(4);
    std::vector<int> enemy1_stun(4);
    std::vector<int> end_point(4);

    int player_idx;
    cin >> player_idx; cin.ignore();
    int nb_games;
    cin >> nb_games; cin.ignore();

    int i = 0;
    while (i < 4)
        end_point[i++] = 0;

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
            maps[i] = gpu;
            player_ps[i] = reg_0;
            enemy0_ps[i] = reg_1;
            enemy1_ps[i] = reg_2;
            player_stun[i] = reg_3;
            enemy0_stun[i] = reg_4;
            enemy1_stun[i] = reg_5;
        }

        next_ops = 1337;
        next_ops = find_close_ops(maps, player_ps, end_point);

        if (check_is_good_move(next_ops, maps, player_ps, player_stun) < 2)
            next_ops = find_best_move(next_ops, maps, player_ps, player_stun, enemy0_stun, enemy1_stun);
        
        std::cerr << next_ops << std::endl;
        if (next_ops == 1)
            cout << "UP" << std::endl;
        else if (next_ops == 2)
            cout << "LEFT" << endl;
        else if (next_ops == 3)
            cout << "DOWN" << endl;
        else
            cout << "RIGHT" << endl;
    }
}