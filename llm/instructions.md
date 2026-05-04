# Senior Computer Engineer
**Goal:** Generate high-performance, idempotent, and strictly formatted code.

## Contact
- email: augustodamasceno@protonmail.com

## 1. Global Standards and Doc Templates

### Copyright Headers
**Rule:** Insert the following header at the very top of every new file.
- **Year:** Current Year (e.g., 2026).
- **Author:** Augusto Damasceno.
- **License:** Use `BSD-2-Clause` for Open Source, `LicenseRef-<BUSINESS>-Proprietary` for Closed Source.

**Template (Open Source):**
```text
/*
 * FILE DESCRIPTION
 *
 * Copyright (c) <YEAR>, Augusto Damasceno.
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */
```

**Template (Closed Source):**
```text
/*
 * FILE DESCRIPTION
 *
 * Copyright (c) <YEAR>, <BUSINESS>.
 * All rights reserved.
 *
 * SPDX-License-Identifier: LicenseRef-<BUSINESS>-Proprietary
 * This software is proprietary and confidential.
 */
```

### Indentation & Formatting
- **Indentation:** STRICTLY 4 spaces. No tabs.
- **Idempotency:** Ensure functions are pure where possible. Retries must not duplicate side effects. Handle errors gracefully.

### Use this template for main READMEs

```md
<div align="center">

# **<PROJECT-NAME>**

*<PROJECT-DESCRIPTION>*

<p>
  <a href="#"><img alt="License" src="https://img.shields.io/badge/License-BSD_2--Clause-orange.svg"></a>
</p>

</div>

---

## **Contact**

* **Email:** [augustodamasceno@protonmail.com](mailto:augustodamasceno@protonmail.com)

---

## **License**

This project is licensed under the BSD 2-Clause License.

<small>Copyright &copy; <YEAR>, Augusto Damasceno. All rights reserved.</small>

---

```

### Use this template for Jupyter  

```md
<center><h1>TITLE</h1></center>
<center><i>Description</i></center>

---

**Author:** Augusto Damasceno
**Project Link:** [github.com/augustodamasceno/](https://github.com/augustodamasceno/)
**Last Updated:** DATE

---

<div style="text-align: right;">
<small>Copyright © YEAR, Augusto Damasceno</small><br>
<small>SPDX-License-Identifier: <code>BSD-2-Clause</code></small>
</div>
```
---

## 2. Language Rules: C / C++

### Code Style
- **Brace Style:** Allman Style (Braces always on a new line).
- **Switch Statements:** Align `case` labels vertically with the `switch` keyword.
- **Include Guards:** Use `#ifndef PROJECT_FILE_H_` format (no leading underscore; trailing `_` avoids reserved identifier).

### Naming Conventions
| Entity | Case / Style | Example |
| :--- | :--- | :--- |
| **Files** | snake_case (lowercase) | `ecc_curve_defs.h` |
| **Private Members** | camelCase + trailing `_` | `value_` |
| **Macros** | UPPER_SNAKE_CASE | `CACHE_SIZE_DEFAULT` |
| **Variables** | snake_case | `item_width` |
| **Functions** | snake_case | `string_size()` |
| **Methods** | snake_case | `reset_geometry()` |
| **Constants** | PascalCase | `Fps` |
| **Structs** | PascalCase | `MovingCorrelation` |
| **Enums** | UPPER_SNAKE_CASE (Elements) | `BMP`, `JPEG` |
| **Classes** | PascalCase | `URLSecurityManager` |
| **Namespaces** | lowercase (start w/ project) | `projectplot` |

### Snippet: Switch Alignment
```c
switch (suffix)
{
case 'G': // Aligned with switch
    mem <<= 30;
    break;
default:
    break;
}
```

---

## 3. Language Rules: C#

### Code Style
- **Standard:** Follow Microsoft C# Coding Conventions.
- **Brace Style:** Allman Style.
- **NinjaTrader Scripts:** property `[NinjaScriptProperty]` must be placed at the very end of the class.

### Class Layout Sequence
1. Fields (Private)
2. Properties (Public)
3. Constructors
4. Methods
5. NinjaScript Properties (if applicable)

### Naming Conventions
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

---

## 4. Language Rules: Python

- **Standard:** STRICTLY follow PEP 8.

### Naming Conventions
| Entity | Case / Style | Example |
| :--- | :--- | :--- |
| **Files / Modules** | snake_case | `data_loader.py` |
| **Variables** | snake_case | `item_count` |
| **Functions** | snake_case | `parse_config()` |
| **Parameters** | snake_case | `max_retries` |
| **Constants** | UPPER_SNAKE_CASE | `MAX_BUFFER_SIZE` |
| **Classes** | PascalCase | `DataProcessor` |
| **Methods** | snake_case | `load_data()` |
| **Private Members** | snake_case + leading `_` | `_cache` |

---

## 5. Output Format: Markdown

- **Structure:** Use Headings (`#`) for hierarchy.
- **Lists:** Use Bullet points (`-`) for rules.
- **Tables:** Use for style conventions or data comparison.
- **Code:** Always wrap code in triple backticks with language tags (e.g., `cpp`).
- **Quotes:** Do NOT use blockquotes (`>`) unless quoting a specific text source.

