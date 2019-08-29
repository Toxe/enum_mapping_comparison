# Enum Mapping Comparison

Comparison of different methods of mapping one enum to another to find opposite directions.

## Methods

- **If:** Simple if-else statements.
- **Switch:** Switch statement.
- **Array:** Picking value from a static array.
- **Map:** Using a `std::map`, with `operator[]` and `find()`.
- **Unordered Map:** The same as "Map" but using a `std::unordered_map` instead.
- **Do Nothing:** Control function that does nothing other than always returning `Direction::North`.

```
Run on (4 X 3300 MHz CPU s)
CPU Caches:
  L1 Data 32K (x4)
  L1 Instruction 32K (x4)
  L2 Unified 262K (x4)
  L3 Unified 6291K (x1)
Load Average: 1.94, 2.00, 2.05
----------------------------------------------------------------------------------------------------
Benchmark                                          Time             CPU   Iterations UserCounters...
----------------------------------------------------------------------------------------------------
BM_Opposite_Direction/Do_Nothing                 142 ns          141 ns      4892231 items_per_second=706.813M/s sum=0
BM_Opposite_Direction/If                         156 ns          156 ns      4408366 items_per_second=641.16M/s sum=378
BM_Opposite_Direction/Switch                     146 ns          142 ns      5002716 items_per_second=703.131M/s sum=378
BM_Opposite_Direction/Array                      141 ns          141 ns      5010558 items_per_second=709.228M/s sum=378
BM_Opposite_Direction/Map_Index                  447 ns          446 ns      1539798 items_per_second=224.306M/s sum=378
BM_Opposite_Direction/Map_Find                   364 ns          363 ns      1844625 items_per_second=275.452M/s sum=378
BM_Opposite_Direction/Unordered_Map_Index        482 ns          481 ns      1392675 items_per_second=208.026M/s sum=378
BM_Opposite_Direction/Unordered_Map_Find         256 ns          256 ns      2634193 items_per_second=390.805M/s sum=378
```
