# SDL Event to string

Provide C functions and C++ functions to convert a SDL\_Event to a string for tracing (debug).

The functions to convert a SDL event to a string is located at the directory evt2str.
The directory evt2str includes the header and C-file.
For a C project simple copy the files from evt2str to your project.
For a C++ project copy the files from evt2str and rename the .c file to .cpp.

The C++ version has additional functions which are only available at C++ (checked with
the macro `__cplusplus` which only exist at C++).

# License

zlib license

