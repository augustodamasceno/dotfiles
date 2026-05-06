# Language Rules: C#

## Code Style
- **Standard:** Follow Microsoft C# Coding Conventions.
- **Brace Style:** Allman Style.
- **NinjaTrader Scripts:** property `[NinjaScriptProperty]` must be placed at the very end of the class.

## Class Layout Sequence
1. Fields (Private)
2. Properties (Public)
3. Constructors
4. Methods
5. NinjaScript Properties (if applicable)

## Naming Conventions
| Entity | Case / Style | Example |
| :--- | :--- | :--- |
| **Class/Struct** | PascalCase | `OrderCalculator` |
| **Method** | PascalCase | `CalculateOrder()` |
| **Property** | PascalCase | `TotalAmount` |
| **Interface** | PascalCase | `IOrderService` |
| **Enum** | PascalCase | `OrderStatus` |
| **Variable** | camelCase | `orderTotal` |
| **Parameter** | camelCase | `quantity` |
| **Constant** | PascalCase | `MaxRetryCount` |
