# Enum Mapping Comparison

Comparison of different methods of mapping one enum to another to find opposite directions.

## Methods

- **If:** Simple if-else statements.
- **Switch:** Switch statement.
- **Array:** Picking value from a static array.
- **Do Nothing:** Control function that does nothing other than returning the passed argument.

```
Run on (4 X 3300 MHz CPU s)
CPU Caches:
  L1 Data 32K (x4)
  L1 Instruction 32K (x4)
  L2 Unified 262K (x4)
  L3 Unified 6291K (x1)
Load Average: 3.07, 2.75, 2.53
-------------------------------------------------------------------------------------------
Benchmark                                 Time             CPU   Iterations UserCounters...
-------------------------------------------------------------------------------------------
BM_Opposite_Direction/Do_Nothing        144 ns          143 ns      4844391 items_per_second=696.979M/s
BM_Opposite_Direction/If                165 ns          164 ns      4220783 items_per_second=610.349M/s
BM_Opposite_Direction/Switch            148 ns          143 ns      4889258 items_per_second=698.472M/s
```
