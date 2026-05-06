# Large Language Models Instructions and Prompts

## 1. Code Generation

  * ### 1.1 Put the required base files in the root of the project.

    | File | Description |
    | :--- | :--- |
    | [instructions.md](instructions.md) | Global coding standards and doc templates |
    | [project-instructions.md](project-instructions.md) | Project-specific rules (fill in placeholders) |

  * ### 1.2 Copy only the optional files you need to the root of the project.

    | File | Description |
    | :--- | :--- |
    | [instructions-language-cpp.md](instructions-language-cpp.md) | C / C++ naming conventions and code style |
    | [instructions-language-csharp.md](instructions-language-csharp.md) | C# naming conventions and code style |
    | [instructions-language-python.md](instructions-language-python.md) | Python naming conventions and code style |
    | [lowlatency.md](lowlatency.md) | Low-latency code generation |

  * ### 1.3 Copy [core.md](core.md) to the tool-specific path and edit the language list to keep only what applies.

    | Tool | File Path |
    | :--- | :--- |
    | **Copilot** | `.github/copilot-instructions.md` |
    | **Cursor** | `.cursor/rules/project.mdc` |
    | **General** | `AGENTS.md` |

    **Example — C++ project with low-latency:**
    ```md
    ### Files to read
    - `instructions.md`
    - `lowlatency.md`
    - `project-instructions.md`

    ### Language-specific files to read
    - `instructions-language-cpp.md`
    ```  

## 2. Prompts  

### 3.1 Daily News

- This prompt has a daily frequency.
- For each news item, provide a heading, a brief paragraph summary, and a source link.
- Prioritize computer engineering, computer science, and software engineering.
- Include occasional items from physics.
- Cover other science and technology fields broadly.
