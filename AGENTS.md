# Learning Repo Source Ownership

The user owns all production C++ source.

- Do not create, delete, or modify `.cpp`, `.cc`, `.cxx`, `.hpp`, or `.h` production files under `src/`.
- This includes blank scaffolds, declarations, stubs, and completed code.
- Tests, documentation, CMake/tooling, and other non-production files are agent-editable.
- Review production source read-only unless the user explicitly requests an exact source edit.
