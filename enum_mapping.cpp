#include <benchmark/benchmark.h>
#include <iostream>
#include <random>
#include <string>
#include <vector>

enum class Direction {
    North = 0,
    Northeast,
    East,
    Southeast,
    South,
    Southwest,
    West,
    Northwest
};

Direction opposite_direction_with_if(const Direction dir)
{
    if (dir == Direction::North)
        return Direction::South;
    else if (dir == Direction::Northeast)
        return Direction::Southwest;
    else if (dir == Direction::East)
        return Direction::West;
    else if (dir == Direction::Southeast)
        return Direction::Northwest;
    else if (dir == Direction::South)
        return Direction::North;
    else if (dir == Direction::Southwest)
        return Direction::Northeast;
    else if (dir == Direction::West)
        return Direction::East;
    else
        return Direction::Southeast;
}

Direction opposite_direction_with_switch(const Direction dir)
{
    switch (dir) {
        case Direction::North:     return Direction::South;
        case Direction::Northeast: return Direction::Southwest;
        case Direction::East:      return Direction::West;
        case Direction::Southeast: return Direction::Northwest;
        case Direction::South:     return Direction::North;
        case Direction::Southwest: return Direction::Northeast;
        case Direction::West:      return Direction::East;
        case Direction::Northwest: return Direction::Southeast;
    }
}

std::vector<Direction> generate_randomized_directions()
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, 7);

    gen.seed(0);

    std::vector<Direction> directions;

    for (int i = 0; i < 100; ++i)
        directions.push_back(static_cast<Direction>(dis(gen)));

    return directions;
}

static void BM_Opposite_Direction_With_If(benchmark::State& state)
{
    std::vector<Direction> directions{generate_randomized_directions()};
    Direction opp_dir;

    for (auto _ : state)
        for (auto dir : directions)
            opp_dir = opposite_direction_with_if(dir);

    benchmark::DoNotOptimize(opp_dir);
}

static void BM_Opposite_Direction_With_Switch(benchmark::State& state)
{
    std::vector<Direction> directions{generate_randomized_directions()};
    Direction opp_dir;

    for (auto _ : state)
        for (auto dir : directions)
            opp_dir = opposite_direction_with_switch(dir);

    benchmark::DoNotOptimize(opp_dir);
}

BENCHMARK(BM_Opposite_Direction_With_If);
BENCHMARK(BM_Opposite_Direction_With_Switch);

BENCHMARK_MAIN();
