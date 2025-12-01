## Local AI Cost Calculator

Used to calculate cost of AI inputs depending on local parameters such as max context length, tokens per second, system power draw, and more.

### Configuration

Example `conf.csv`:

```csv
name,max_context_length,tokens_per_second,system_power_draw,electricity_cost_per_kwh
basic,24000,12,1000,0.13
complex,24000,2,750,0.09
gpt3.5,16384,63,350,0.13
```

### Input

One can enter a string from the command line or input a file to convert the file to a string to read.

This is so multi-line iput can be accepted without the edge cases of console input.

### Building

Compiled with Clang Version 19.1.4 for x86_64-unknown-windows-msvc

Build with `clang main.cpp --std=c++17`

Must be compiled with c++17 or greater for compatibility with string_view and more.

### Running

Build will produce an executable which can be ran

All input will happen from the console asking the user whether or not they would like to use certain options
