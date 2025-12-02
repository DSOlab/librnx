
# Installation

```bash
cmake -S . -B build -DCMAKE_BUILD_TYPE=Release -DCMAKE_PREFIX_PATH=/usr/local/lib
cmake --build build --target all --config=Release -- -j4
cd build && sudo make install
```

## Testing

Test programs are build while running `cmake` but are **not initialized** via `ctest`. 
We would need to upload/download actual RINEX files for this. If you do however have 
access to RINEX file(s), you can manual run them via:

```bash
build/test/doris_rinex_iterator_data /path/to/doris/rinex
```

and

```bash
build/test/doris_rinex_iterator /path/to/doris/rinex
```
