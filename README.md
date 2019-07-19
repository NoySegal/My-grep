# My grep
Custom implementation for the Unix [grep](https://en.wikipedia.org/wiki/Grep) command as a command-line utility for searching datasets in files.

## Getting Started

These instructions will get you a copy of the project up and running on your local machine for development and testing purposes.

### Prerequisites

This version of the code compiles successfully on Ubuntu-18.04. Should also compile on other linux variants. Other operating systems are currently not supported.

You'll need gcc compiler, for compiling the code and generating an executble:

```
$ sudo apt install gcc
```

Next, I recommened using a Makefile, for simpler compilation/testing and shorter turn-around times.

```
$ sudo apt install make
```

Optional: Valgrind, it can detect many memory-related errors that are common in C programs and that can lead to crashes and unpredictable behaviour. Recommended.

```
$ sudo apt install valgrind
```

### Installing

Clone the repo

```
git clone https://github.com/NoySegal/My-grep.git
```

Compile on your system either with typing:

```
make
```

or with typing the full command:

```
gcc main.c init.c match.c -o my_grep -Wall
```

### Usage

#### The program accepts two arguments: an expression and a file name. In any case that no file name was provided, then it will be read from the stdin. The program scans the file line-by-line and prints only the lines where the expression appears.

#### Parameters (can be provided simultaneously)

* **-A #NUM** The program will print **#NUM** lines after every match.
* **-b** The program will print the byte offset (at the start of line) from the beginning of the file until the beginning of the line.
* **-c** Instead of printing the matching lines, the program will print the number of matching lines.
* **-i** The program will ignore letter case.
* **-n** The program will print the line number in the file (at the start of each line).
* **-v** Revesre the program action. Instead of finding matches for the expression, print the lines which don't have the expression.
* **-x** The program will do only tight matches (nothing but the expression).
* **-E** The program will handle some regular expression (see below for details).

#### Types of patterns

The pattern can be consisted of lowercaser and uppercase letters, digits, and al ASCII characters in the range between 33 and 126 (Decimal).
Searching for the special characters: \|{}[] will have to be escaped by a backslash '\' even when -E switch is not on.

#### REGEX Usage

The search for regular expressions must be preceded by **-E** flag. Where the expression should be surrounded by quotation marks. The supported regex types are:

* **(str1|str2)** Which looks for either str1 or str2.
* **.** (a dot) Matches any literal character c. Dots can't appear inside parenthesis.
* **[x-y]** Matches for any character between x and y (including).
* **^** Matches the beginning of the input string.
* **$** Matches the end of the input string.
* <b>*</b> Matches zero or more occurrences of the previous character.

### Example

Running: ./my\_grep -n -i "o\\.pdf" test.html

Where **test.html** contains:

```html
<HTML>
<HEAD>
<TITLE>Just a Test (Simple)</TITLE>
</HEAD>
<body>
  <h1>Website headline in h1</h1>
<ul>
  <li> <a href="intro.pdf">Revisiting</a>
  <li> <a href="Mudularity.docx">Modularity</a>
  <li> <a href="FileIO.pdf">I/O and files in C</a>

</ul>
```

Will print:

```html
8:<li> <a href="intro.pdf">Revisiting</a>
10:<li> <a href="FileIO.pdf">I/O and files in C</a>
```


