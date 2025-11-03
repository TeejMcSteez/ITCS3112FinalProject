## Tokenizer

### Responsibilities

1. Split string into tokens
2. Implements different tokenization algorithms

### Collaborators

1. CostCalculator
2. UI

## Cost Calculator

### Responsibilities

1. Calculates cost from total tokens

### Collaborators

1. ModelParams
2. Tokenizer

## ModelParams

### Responsibilities

1. Stores context length, tokens/sec, etc.

### Collaborators

ConfigIO

## ConfigIO

### Responsibilities

1. Writes new model parameters
2. Reads config model paramters

### Collaborators

ModelParams

## UnitConverter

### Responsibilities

1. Used for common conversion

### Collaborators

1. CostCalculator
2. UI

## UI

Question: is this a needed class? Does it need to be singleton or more extendable for future use?


### Responsibilities

1. Class to interact with program
2. Stores class instances for run time

### Collaborators

1. Tokenizer
2. CostCalculator
3. ConfigIO
4. UnitConverter
