#include "screen.cpp"
#include <numeric>
#include <array>

int main(int argc, char *argv[])
{
    Screen screen("square", 500, 500);
    screen.clear();

    std::array<std::array<int, 2>, 4> square = {{
        {100, 100},
        {400, 100},
        {400, 400},
        {100, 400},
    }};

    int square_l = square.size();
    for (long i = 0; i < square_l; i++)
    {
        std::array<int, 2> c_point = square[i];
        std::array<int, 2> n_point;
        if (i < square_l - 1) n_point = square[i + 1];
        else n_point = square[0];

        screen.drawLine(c_point[0], c_point[1], n_point[0], n_point[1]);
    }

    screen.render();

    while (true)
    {
        screen.input();
    }

    return 0;
}
