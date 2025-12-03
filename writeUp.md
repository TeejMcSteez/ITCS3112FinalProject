## SOLID Writeup

### Interfaces

1. ICostCalculator.h
2. IModelParams.h
3. ITokenizer.h

### Data Structures

1. Struct TokenBuffer & Buffer in types.h
2. Enum -> Map in Byte-pair token algorithm for byte-pairs
3. Data Structure -> Vectors (ex: std::vector<std::string> input in Buffer)

### Polymorphism

1. Model Params Inherits all of its parameters from IModelParams and overrides with a new constructor
2. Cost Calculator inerhits its base CostCalculator from ICostCalculator and implements a new realistic calculator

### Inheritance

### Design Patterns

1. main.cpp Factory - Depending on input will produce classes
2. Token Algorithm strategies, allowing different classes to implement their own token algorithm inheriting from ITokenizer with the base Tokenize method

### Review

1. Configuration operations need to be better, allowing for extension of the confiuration by the user
2. Fix BPE Tokenizer, does not add matched byte pairs and remove old byte pairs accurately