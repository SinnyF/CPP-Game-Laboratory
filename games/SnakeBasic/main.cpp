#include <iostream>
#include <string>

int main()
{
    const int width = 10;
    const int height = 6;

    // Super simple "leaderboard"
    int bestScore = 0;

    bool running = true;

    while (running)
    {
        // ----- MAIN MENU -----
        std::cout << "\n=== SNAKE PROTOTYPE (Version 0) ===\n";
        std::cout << "1) Play\n";
        std::cout << "2) Controls / Help\n";
        std::cout << "3) Leaderboard\n";
        std::cout << "4) Quit\n";
        std::cout << "Select: ";

        std::string choiceStr;
        std::getline(std::cin, choiceStr);

        if (choiceStr.size() == 0)
            continue;

        char choice = choiceStr[0];

        if (choice == '1')
        {
            // ----- PLAY (very naive game loop) -----
            int playerX = width / 2;
            int playerY = height / 2;

            int score = 0; // We'll pretend score increases when you move

            bool playing = true;
            while (playing)
            {
                // RENDER
                std::cout << "\n";
                for (int y = 0; y < height; ++y)
                {
                    for (int x = 0; x < width; ++x)
                    {
                        if (x == playerX && y == playerY)
                            std::cout << "@ ";
                        else
                            std::cout << ". ";
                    }
                    std::cout << "\n";
                }

                std::cout << "Score: " << score << "\n";
                std::cout << "Move (w/a/s/d), menu (q): ";

                // INPUT
                std::string input;
                std::getline(std::cin, input);
                if (input.size() == 0)
                    continue;

                char c = input[0];

                // UPDATE
                if (c == 'q')
                {
                    playing = false; // back to menu
                }
                else if (c == 'w')
                {
                    playerY -= 1;
                    score += 1;
                }
                else if (c == 's')
                {
                    playerY += 1;
                    score += 1;
                }
                else if (c == 'a')
                {
                    playerX -= 1;
                    score += 1;
                }
                else if (c == 'd')
                {
                    playerX += 1;
                    score += 1;
                }

                // Bounds handling (clamp)
                if (playerX < 0) playerX = 0;
                if (playerX >= width) playerX = width - 1;
                if (playerY < 0) playerY = 0;
                if (playerY >= height) playerY = height - 1;
            }

            // "Outro" idea: update best score when leaving play
            if (score > bestScore)
                bestScore = score;
        }
        else if (choice == '2')
        {
            // ----- HELP -----
            std::cout << "\n--- Controls / Help ---\n";
            std::cout << "Play: Move with w/a/s/d\n";
            std::cout << "In game: press q to return to menu\n";
            std::cout << "(This is an early prototype; we'll refactor a lot soon.)\n";
            std::cout << "\nPress ENTER to return to menu...";
            std::string tmp;
            std::getline(std::cin, tmp);
        }
        else if (choice == '3')
        {
            // ----- LEADERBOARD (fake, just best score) -----
            std::cout << "\n--- Leaderboard ---\n";
            std::cout << "Best score: " << bestScore << "\n";
            std::cout << "\nPress ENTER to return to menu...";
            std::string tmp;
            std::getline(std::cin, tmp);
        }
        else if (choice == '4')
        {
            running = false;
        }
        else
        {
            std::cout << "Unknown choice. Please select 1–4.\n";
        }
    }

    std::cout << "Bye!\n";
    return 0;
}