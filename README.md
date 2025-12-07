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

Their must be a configuration file to start entry, this is what the program uses for Model Parameters and without it, it cannot calculate information. Once their is atleast one model the user can add more through the command line not needing to enter the configuration file again. 

### Input

One can enter a string from the command line or input a file to convert the file to a string to read.

This is so multi-line iput can be accepted without the edge cases of console input.

### Building

This should be portable C++ code the compiler used shouldn't matter past optimizations purposes so I've included building with Clang (what I use) and G++ (what is also common)

#### With Clang

Compiled with Clang Version 21.1.0 for x86_64-unknown-windows-msvc

Build with `clang main.cpp -o tokenizer.exe --std=c++17`

Must be compiled with c++17 or greater for compatibility with string_view and more.

#### With G++

Built with `gcc version 14.2.0 (GCC)`

To build with G++ simply `g++ main.cpp -o tokenizer.exe`

### Running

Build will produce an executable which can be ran

All input will happen from the console asking the user whether or not they would like to use certain options

Run with `./tokenizer.exe` or double click the executable.

## OOP Writeup

### Interfaces

Ex: interface/implementation 

1. ICostCalculator.h/CostCalculator
2. IModelParams.h/ModelParams.h
3. ITokenizer.h/Tokenizers.cpp

### Data Structures

1. Struct TokenBuffer & Buffer -> types.h
2. Data Structure -> Vectors (ex: <std::vector><<std::string>> input in Buffer)
3. Enumerations for different types of tokenizers make choice output easier with pre-defined types -> types.h

### Polymorphism

1. Model Params Inherits all of its parameters from IModelParams and overrides with a new constructor -> ModelParams.h
    - All of model parameters local parameters are public making it so that Main can display information about models on the frontend and calculator can use their values on the backend.
2. Cost Calculator inerhits its base CostCalculator from ICostCalculator and implements a new calculator algorithm -> CostCalculator.cpp

### Inheritance

1. Cost Calculator inerhits ICalculator calculate method -> CostCalculator.cpp
2. BPE & SpaceTokenizer ineherit tokenize from ITokenizer with a different token generation algorithm's -> Tokenizers.cpp

## Design Patterns

1. Factory - Depending on input will produce classes to produce desired ouput -> main.cpp
2. Strategy - Token Algorithm strategies & different calculators, allowing different classes to implement their own token algorithm inheriting from ITokenizer with the base Tokenize method and different calcualtors all having the base method returning the same type with slightly different calculations. -> Tokenizers.cpp
3. Decorator Pattern for the energy conversions -> EnergyDecorator.cpp
