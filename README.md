# Useful Commands

## Basic Running

```
    flex myFile.l
    gcc lex.yy.c -o output -lfl //IF ON MAC OS USE -ll (two L's) instead!!!!!!!!!!!
    ./output
```

The `-o output` is completely optional.  Will default to writing a file called `a.out`.

## Pipe Input and Output
```
    cat input.txt | ./a.out  > tokens.txt
```
The above feeds in `input.txt` into `a.out`, which is generated from my flex file.  Then, `a.out`'s output is written to a file called `tokens.txt`.

## Compare Tokens

[Reference/Source StackOverflow Answer](https://stackoverflow.com/a/8582530)

Command to compare tokens given from assignment and tokens generated by my file.

```
diff -w -u file1.txt file2.txt | sed -n '1,2d;/^[-+]/p'
```

`diff` finds difference between files 1 and 2  
`-w` ignores whitespace   
`-u` output NUM (default 3) lines of unified context  
not 100% sure why or if `-u` this is necessary, probably makes it easier to parse it with the sed regex

Then it pipes into `sed`  
`sed` is a stream editor to edit output of `diff`  
`-n` supress automatic printing of pattern space  


**Terminal Output:** Prints `-apple` if, for example, apple is present in file1 but *NOT* file2.  Prints `+apple` if apple is present in file2 but *NOT* file1.  Essentially, the + and - are with respect to file1. `+apple` if adding "apple" to **file1** would obtain no difference.  `-apple` if removing "apple" from **file1** would obtain no difference.

No output is printed if there are no differences.

Remove `-w` if whitespace should not be ignored.

Read `man sed` and `man diff` for further options and info.

## Bison flags

`-k` generates a token table  
`-x` generates an xml file of the grammar for visual representation  
`-g` generates a .DOT file; not sure the proper application to open this for the visual.  Tried apache openoffice.  
`--language=C++` generates the parser in C++  
`--report=all` generates a report of the language; could be useful for debugging the language  
`-d` produces a header file