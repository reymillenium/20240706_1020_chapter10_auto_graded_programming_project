# COP 1334 Assignment - Introduction to C++

## Chapter 10: Auto-Graded Programming Project**

## Title: Future Value

### Exercise Description:

**Goal**: Manipulate strings using the `string` class methods.

**Assignment**: Write a C++ program that converts datetime strings from the format "YYYY-MM-DD HH:MM:SS" to a more detailed human-readable format, "DDth of MonthName, YYYY at HH:MM AM/PM". This conversion should involve validating the input format, converting the time from 24-hour to 12-hour format with appropriate AM/PM suffixes, and replacing the numeric month with its corresponding name (e.g., "04" to "April").

1. **Validate Input Format:** Ensure the input string matches the expected "YYYY-MM-DD HH:MM:SS" format using string length and character checks.
2. **Convert 24-hour to 12-hour Format:** Extract the hour component and convert it to 12-hour format, appending "AM" or "PM" as appropriate.
3. **Replace Numeric Month with Name:** Convert the month from a numeric value to its corresponding name (e.g., "01" to "January").
4. **Format Day Suffix:** Add the correct suffix to the day (e.g., "1" to "1st", "2" to "2nd").

**Sample Run** User input is marked by square brackets.

```
[2023-01-08 14:05:09]
08th of January, 2023 at 2:05 PM
```

```
[InvalidInput]
Invalid datetime format
```



## Execution from the Terminal (Alternative way without an IDE):

We must provide to the Compiler the same switches that we usually do in the IDE:

```terminal
g++ -Wall -std=c++17 main.cpp
```

That will create a file named 'a.out' if you are working in MacOS or a .exe file if you are on Windows. That's the default executable file's name when we don't provide a name.

But we can also specify the name of the resulting executable file:

```terminal
g++ -Wall -std=c++17 main.cpp -o your_prefered_executable_file_name
```

And in order to run that a.out file, we must execute on the terminal:

```terminal
 % ./a.out
```

## Result of Execution on the Terminal (MacOS example):

```terminal
reinier@reinier % ./your_prefered_executable_file_name

2023-01-08 14:05:09
08th of January, 2023 at 2:05 PM 
  
Process finished with exit code 0
reinier@reinier % 
```

### Author

**Reinier Garcia**

* [Github](https://github.com/reymillenium)
* [Twitter](https://twitter.com/ReinierGarciaR)
* [Linkedin](https://www.linkedin.com/in/reiniergarcia/)
* [Website](https://www.reiniergarcia.dev/)
* [Stack Overflow](https://stackoverflow.com/users/9616949/reinier-garcia)

### License

Copyright © 2024, [Reinier Garcia](https://github.com/reymillenium).


