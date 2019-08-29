# Enum Mapping Comparison

Comparison of different methods of mapping one enum to another to find opposite directions.

## Methods

- **If:** Simple if-else statements.
- **Switch:** Switch statement.
- **Array:** Picking value from a static array.
- **Map:** Using a `std::map`, with `operator[]` and `find()`.
- **Do Nothing:** Control function that does nothing other than returning the passed argument.

```
Run on (4 X 3300 MHz CPU s)
CPU Caches:
  L1 Data 32K (x4)
  L1 Instruction 32K (x4)
  L2 Unified 262K (x4)
  L3 Unified 6291K (x1)
Load Average: 2.28, 2.26, 2.19
-------------------------------------------------------------------------------------------
Benchmark                                 Time             CPU   Iterations UserCounters...
-------------------------------------------------------------------------------------------
BM_Opposite_Direction/Do_Nothing        171 ns          170 ns      4070880 items_per_second=586.882M/s
BM_Opposite_Direction/If                198 ns          198 ns      3509652 items_per_second=504.809M/s
BM_Opposite_Direction/Switch            170 ns          169 ns      4222973 items_per_second=591.418M/s
BM_Opposite_Direction/Array             197 ns          196 ns      3578348 items_per_second=510.746M/s
BM_Opposite_Direction/Map_Index         575 ns          571 ns      1205670 items_per_second=175.214M/s
BM_Opposite_Direction/Map_Find          454 ns          452 ns      1531219 items_per_second=221.079M/s
```
