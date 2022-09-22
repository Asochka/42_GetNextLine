# get_next_line (42 project)

This project is to create function that will return new line from given file descriptor.
It was forbidden to use "libft" on this project, so file get_next_line_utils includes some functions from it.
This function returns new line or "NULL" if it is EOF or mistake occured. \
\
It should be compiled with define flag **-D BUFFER_SIZE='value'** in order to create size of buffer that will be read in from file

## Description
For example we have file: \
1 Hello \
2 World \
3 ! 

First call will return "Hello" \
Second - "world" \
Third - "!" \
Fourth and others "(null)" 

## Bonus (files with postfix _bonus)
There is one static variable (**DONE**) \
It can read from different file descriptors (**NOT ALL VALUES OF FILE DESCRIPTOR WERE TOOK INTO ACCONUT**)
