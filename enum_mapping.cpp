#include <benchmark/benchmark.h>
#include <iostream>
#include <map>
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

Direction opposite_direction_with_array(const Direction dir)
{
    static const Direction opposite_directions[8] = {
        Direction::South,
        Direction::Southwest,
        Direction::West,
        Direction::Northwest,
        Direction::North,
        Direction::Northeast,
        Direction::East,
        Direction::Southeast
    };

    return opposite_directions[static_cast<int>(dir)];
}

std::map<Direction, Direction> map_for_index{
    {Direction::North,     Direction::South},
    {Direction::Northeast, Direction::Southwest},
    {Direction::East,      Direction::West},
    {Direction::Southeast, Direction::Northwest},
    {Direction::South,     Direction::North},
    {Direction::Southwest, Direction::Northeast},
    {Direction::West,      Direction::East},
    {Direction::Northwest, Direction::Southeast}
};

const std::map<Direction, Direction> map_for_find{
    {Direction::North,     Direction::South},
    {Direction::Northeast, Direction::Southwest},
    {Direction::East,      Direction::West},
    {Direction::Southeast, Direction::Northwest},
    {Direction::South,     Direction::North},
    {Direction::Southwest, Direction::Northeast},
    {Direction::West,      Direction::East},
    {Direction::Northwest, Direction::Southeast}
};

Direction opposite_direction_with_map_index(const Direction dir)
{
    return map_for_index[dir];
}

Direction opposite_direction_with_map_find(const Direction dir)
{
    return map_for_find.find(dir)->second;
}

Direction do_nothing(const Direction dir)
{
    return dir;
}

static void BM_Opposite_Direction(benchmark::State& state, const std::vector<Direction>& directions, Direction opposite_direction(Direction dir))
{
    Direction opp_dir;

    for (auto _ : state)
        for (auto dir : directions)
            opp_dir = opposite_direction(dir);

    benchmark::DoNotOptimize(opp_dir);

    state.SetItemsProcessed(static_cast<int64_t>(directions.size()) * static_cast<int64_t>(state.iterations()));
}

const std::vector<Direction> random_directions{generate_randomized_directions()};

BENCHMARK_CAPTURE(BM_Opposite_Direction, Do_Nothing, random_directions, do_nothing);
BENCHMARK_CAPTURE(BM_Opposite_Direction, If,         random_directions, opposite_direction_with_if);
BENCHMARK_CAPTURE(BM_Opposite_Direction, Switch,     random_directions, opposite_direction_with_switch);
BENCHMARK_CAPTURE(BM_Opposite_Direction, Array,      random_directions, opposite_direction_with_array);
BENCHMARK_CAPTURE(BM_Opposite_Direction, Map_Index,  random_directions, opposite_direction_with_map_index);
BENCHMARK_CAPTURE(BM_Opposite_Direction, Map_Find,   random_directions, opposite_direction_with_map_find);

BENCHMARK_MAIN();
