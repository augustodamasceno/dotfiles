# Large Language Models Instructions and Prompts

## 1. Code Generation  

  * ### 1.1 Put [instructions.md](instructions.md) and [project-instructions.md](project-instructions.md) in the root of the project.

  * ### 1.2 Copy [core.md](core.md) to the following files depending on the tool.

| Tool | File Path |
| :--- | :--- |
| **Copilot** | `.github/copilot-instructions.md` |
| **Cursor** | `.cursor/rules/project.mdc` |
| **General** | `AGENTS.md` |  

## 2. Low Latency Code Generation  

  * ### 2.1 Put [lowlatency.md](lowlatency.md) in the root of the project.
  * ### 2.2 Same as section 1.2 but using the file [core-lowlatency.md](core-lowlatency.md). 

## 3. Prompts  

### 3.1 Daily News

- This prompt has a daily frequency.
- For each news item, provide a heading, a brief paragraph summary, and a source link.
- Prioritize computer engineering, computer science, and software engineering.
- Include occasional items from physics.
- Cover other science and technology fields broadly.
