# Enum Mapping Comparison

Comparison of different methods of mapping one enum to another to find opposite directions.

## Methods

- **If:** Simple if-else statements.
- **Switch:** Switch statement.
- **Array:** Picking value from a static array.
- **Map:** Using a `std::map`, with `operator[]` and `find()`.
- **Unordered Map:** The same as "Map" but using a `std::unordered_map` instead.
- **Do Nothing:** Control function that does nothing other than returning the passed argument.

```
Run on (4 X 3300 MHz CPU s)
CPU Caches:
  L1 Data 32K (x4)
  L1 Instruction 32K (x4)
  L2 Unified 262K (x4)
  L3 Unified 6291K (x1)
Load Average: 1.95, 2.13, 2.17
----------------------------------------------------------------------------------------------------
Benchmark                                          Time             CPU   Iterations UserCounters...
----------------------------------------------------------------------------------------------------
BM_Opposite_Direction/Do_Nothing                 142 ns          141 ns      4926074 items_per_second=706.77M/s
BM_Opposite_Direction/If                         152 ns          151 ns      4739208 items_per_second=662.004M/s
BM_Opposite_Direction/Switch                     144 ns          144 ns      4915282 items_per_second=695.001M/s
BM_Opposite_Direction/Array                      146 ns          143 ns      5017382 items_per_second=698.181M/s
BM_Opposite_Direction/Map_Index                  459 ns          456 ns      1464101 items_per_second=219.389M/s
BM_Opposite_Direction/Map_Find                   363 ns          362 ns      1887719 items_per_second=275.904M/s
BM_Opposite_Direction/Unordered_Map_Index        529 ns          527 ns      1272936 items_per_second=189.803M/s
BM_Opposite_Direction/Unordered_Map_Find         257 ns          256 ns      2620535 items_per_second=391.151M/s
```
