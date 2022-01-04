# SDL Event to string

Provide C functions and C++ functions to convert a SDL\_Event to a string for tracing (debug).

For a C project copy the files from c\_version to your project.
For a C++ project copy the files from c\_version and rename the .c file to .cpp.
In the directory for the C++ version there are only symbolic links to the C version.

The C++ version has additional functions which are only available at C++ (checked with
the macro `__cplusplus` which only exist at C++).

# License

zlib license

