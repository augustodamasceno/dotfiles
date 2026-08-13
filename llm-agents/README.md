# Large Language Models and Agents Instructions and Prompts

## 1. Agentic Code Generation

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

    **Note:** These are the **source of truth** files. All AI coding assistants will read these files from your project root to understand your work standards and the project context.

  * ### 1.3 Tool-specific agentic files

    These files are tool adapters that reference the **source of truth** instruction files (1.1 and 1.2). They contain high-level guidance specific to each AI tool, but delegate detailed standards to the instruction files in your project.

    **How they work:**
    - Each tool-specific file includes a section that lists which instruction files to read
    - When deployed to your project root, the AI assistant reads both the tool-specific configuration AND the instruction files you've placed in the root
    - The instruction files are the single source of truth

    **Tool-specific agentic files and their target paths:**

    | Tool | Target Path |
    | :--- | :--- |
    | **GitHub Copilot** | `.github/copilot-instructions.md` |
    | **Cursor** | `.cursor/rules/project.mdc`, `.cursorrules` |
    | **Claude CLI** | `.clauderules` |
    | **Windsurf** | `.windsurfrules` |
    | **Aider** | `.aider.conf.yml` |
    | **Roo** | `.roo/rules.md` |
    | **Cline** | `.clinerules` |
    | **Continue** | `.continuerules` |
    | **Cody** | `.vscode/cody.json` (instructions field) |
    | **Amazon Q** | `.aws/q/instructions.md` |
    | **Supermaven** | `.supermaven/rules.md` |
    | **Plandex** | `.plandex/instructions.md` |
    | **OpenHands** | `.openhands/rules.md` |
    | **Pieces** | `.pieces/context.md` |
    | **Codeium** | `.codeiumrules` |
    | **Devin** | `.devinrules` |
    | **Bolt.new** | `.boltrules` |
    | **PearAI** | `.pearairules` |
    | **Blackbox AI** | `.blackboxrules` |
    | **Claude Code** | `CLAUDE.md` |
    | **Gemini CLI** | `GEMINI.md` |
    | **Qodo** | `.qodorules` |
    | **Zed AI** | `.zedrules` |
    | **Double.bot** | `.doublerules` |
    | **Gemini Code Assist** | `AGENTS.md` |
    | **Tabnine** | `AGENTS.md` |
    | **CodeGPT** | `AGENTS.md` |
    | **Bito AI** | `AGENTS.md` |
    | **Mintlify** | `AGENTS.md` |
    | **v0.dev / Vercel AI** | `AGENTS.md` |
    | **Other AI assistants** | `AGENTS.md` |

    **Setup workflow:**
    1. Copy sections 1.1 and 1.2 instruction files to your project root (these are your source of truth)
    2. Copy the relevant tool-specific files from section 1.3 to their tool-specific paths
    3. Each tool will read the tool-specific file first, then follow references to find the detailed instruction files in your root
    4. Edit instruction files as needed; tool-specific files rarely need modification

    **Example — C++ project with low-latency:**
    
    *Files to deploy to project root:*
    ```
    instructions.md                    (from 1.1)
    project-instructions.md            (from 1.1)
    instructions-language-cpp.md       (from 1.2)
    lowlatency.md                      (from 1.2)
    .github/copilot-instructions.md    (from 1.3, copy core.md)
    ```
    
    *Content of .github/copilot-instructions.md will reference:*
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
