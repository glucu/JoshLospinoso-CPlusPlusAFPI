# Exercises-From-CPP-A-Fast-Paced-Introduction-by-Josh-Lospinoso
# Why?
My journey in learning C++ started back in 2018. Fast forward to one year later towards the end of 2019, I decided to brush up on the basics again and learn modern practices in C++. I stumbled upon this book and came to realization that there are no online sources that gives solutions to these exercises found at the end of each chapter. Why does it matter? For me, Beginners who want to learn programming for the first time, especially a language like C++, won't gain much just by reading the chapters and doing the exercises without knowing if they wrote their code well. It would be nice to supply them with solutions for them to compare their work against others and see if their approach is at least sufficient compared to the solution. 
# Credibility
I will like to meantion that I am still learning C++ to this day, and I am working on my undergraduate degree in the meantime. I am no professional nor a beginner.
# About the exercises 
I will state some facts: 

1. I frame from using `printf()` but instead choose to use `std::cout <<` which is the prefer way to write to console output in C++.

2. **POD types** (Plain old data types like `struct`) is what I won't prefer or use; however, I may make an exception for the exercises. If not I'll use the `class` keyword.

3. I may or may not use concepts that were not introduced in a following chapter, but I will leave a comment explaining what it means. For example: In chapter 2 exercise, I used the keyword `const` when passing an  `enum class` object to reframe the idea that it is not intended to be modified but rather passed as read-only.

4. There are two kinds of styles for indentation in programming languages like C++. The two common ones are **K&R style** (Kernighan & Ritchie Style), and **1TBS** (the one true brace style). I prefer to use the K&R style because of the aesthetics really. Here is an example of **K&R** and **1TBS** respectively: 

```
int main() 
{
  std::cout << "Hello, world!\n";
  return 0;
}
```

```
int main() {

  std::cout << "Hello, world!\n";
  return 0;
}
```
# Feedback
For anyone who is experienced in writing C++ code (or anyone who will like to give tips/advice about this repo), I will gladly accept feedback in what can be done better! :)

