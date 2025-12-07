## SOLID Writeup

### Interfaces

1. ICostCalculator.h/CostCalculator
2. IModelParams.h/ModelParams.h
3. ITokenizer.h/Tokenizers.cpp

### Data Structures

1. Struct TokenBuffer & Buffer in types.h
2. Data Structure -> Vectors (ex: std::vector<std::string> input in Buffer)
3. N/a

### Polymorphism

1. Model Params Inherits all of its parameters from IModelParams and overrides with a new constructor
2. Cost Calculator inerhits its base CostCalculator from ICostCalculator and implements a new realistic calculator

### Inheritance

1. Realistic Calculator inerhits ICalculator calculate method
2. BPE & SpaceTokenizer ineherit tokenize from ITokenizer with a different token generation algorithm's

### Design Patterns

1. main.cpp Factory - Depending on input will produce classes to produce desired ouput
2. Token Algorithm strategies & different calculators, allowing different classes to implement their own token algorithm inheriting from ITokenizer with the base Tokenize method and different calcualtors all having the base method returning the same type with slightly different calculations.
3. N/a

### Review

1. Configuration operations need to be better, allowing for extension of the confiuration by the user
2. Fix BPE Tokenizer, does not add matched byte pairs and remove old byte pairs accurately

## TODO:

1. Add Enums for tokenizer types and Calculator Types ✅
2. Add energy cost decorator pattern, being able to handle base power cost and then actual compute cost in two different classes will be nice rather than doing everything in calculate ✅
3. Add Custom config for different user input (allowing more than one user)