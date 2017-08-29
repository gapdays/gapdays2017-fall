---
layout: default
permalink: /abstracts/profiling
---

## Christopher Jefferson

### Hooking the interpreter in GAP - profiling and debugging

At the centre of GAP’s interpreter is a single array of functions,
describing how GAP performs every operation, from function calls to
addition. This array gives us a unique opportunity — by intercepting
all calls to functions in this array, we can cheaply and easily track
every operation performed by GAP.

This was the basis for GAP’s line-by-line profiling, and has now been
extended to provide a simple debugger. This talk will discuss the
current state of both profiling and debugging, and show how packages
can add new interpreter hooks to GAP.
