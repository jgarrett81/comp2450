# Trial II — *The Critique*

*Warden of the Foundations · Midterm 1 · 15 %*

This trial **requires** you to use an LLM. You will paste the prompt and the reply, then critique what you got. Reading and judging AI output is part of the job now; we are practicing it on purpose.

---

## The prompt

Open Claude (or your LLM of choice) and paste **this exact prompt**:

> *Write a C++ function template that returns the largest element of a `std::vector<T>`. Handle the case where the vector is empty. Briefly explain your design choices.*

Tell us which tool you used and the date:

- **Tool:** (e.g., Claude / ChatGPT / Copilot Chat / …) ChatGPT
- **Date of the conversation:** YYYY-MM-DD 2026/09/17

---

## The LLM's reply

Paste the **full reply**, code and prose. Use a fenced code block for the code. Do not edit the reply — we want to see what you actually got.

```cpp
// (paste the LLM's code here)
#include <vector>
#include <stdexcept>

template <typename T>
T findLargest(const std::vector<T>& values) {
    if (values.empty()) {
        throw std::invalid_argument("Vector is empty");
    }

    T largest = values[0];

    for (size_t i = 1; i < values.size(); ++i) {
        if (values[i] > largest) {
            largest = values[i];
        }
    }

    return largest;
}
```

(paste any prose explanation here, verbatim)
Design choices
Function template: template <typename T> allows the function to work with different types such as int, double, or string (as long as > is supported).
const std::vector<T>&: Passes the vector by reference so it doesn't make an unnecessary copy, while const prevents the function from modifying it.
Empty vector: Throws std::invalid_argument because there is no largest element to return.
Starting with values[0]: Avoids needing a special default value for T, which makes the template more general.
Time complexity: O(n) because every element is checked at most once.

---

## My critique  *( ≥ 150 words )*

Your critique must read like an engineer reviewing a colleague's pull request — specific, technical, and naming exactly what the LLM did. A vague critique ("looks fine to me, but it could be better") is *not* full credit even if the LLM's code was great.

Address each of these:

- **Compile.** Did you actually try to compile and run the code? On what types? What happened?
- **Empty case.** What does the empty-vector case actually do in this code? Is the LLM's choice reasonable? Is it different from what *you* would have chosen?
- **Requirements on `T`.** What does the code require of `T`? What happens if you instantiate it with a type that doesn't support `<` (e.g., a custom struct)?
- **Const-correctness.** Pass by value or by reference? Return by value or by reference? Would you change either?
- **`std::max_element`?** Did the LLM cheat by using the algorithm header, or did it write the loop? Which would *you* have shipped, and why?
- **One concrete improvement.** Name one specific change you would make before merging this into a real project. Not "make it better" — a concrete code change.

(your critique — at least 150 words)

The program that the LLM creatd for me complied and ran the code exactly how it should've and printed out "Largest: ..." based on whatever it was. 
I tested the program on int, double, and string and all three worked and complied and answered how you would've expected them too.  
However, when you run it with an empty vector it throws an invalid argument empty vector, but when it compiles it comes out as "Largest: The vector is empty"
and I feel like that could've been changed to have a different output rather than just keeping the largest part in there. 
For T in the code, it must support the comparison operator because each element is compared to the largest so if you instantiated it with a type that doesn't 
support it, it would just return the largest as the value at position 0 because thats what it gets set as. The vector is passed by reference as to not make another 
copy of the entire vector as it's not needed for the comparison but it is returned by value, but I don't think either would need to be changed.
ChatGPT did not use max_element and wrote the loop itself, but if it was being shipped I think using max_element qould just be quicker and more efficient as a built-in 
function rather than building it's own loop.

The main change I think I would make is changing the loop to std::max_element because it's cleaner and more efficient as a built_in function

T largest = values[0];

    for (size_t i = 1; i < values.size(); ++i) {
        if (values[i] > largest) {                           ==>          auto maxElement = std::max_element(values.begin(), values.end());
            largest = values[i];
        }
    }