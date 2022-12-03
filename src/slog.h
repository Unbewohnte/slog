/*
The MIT License (MIT)
Copyright © 2022 Kasyanov Nikolay Alexeyevich (Unbewohnte)
Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the “Software”), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:
The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.
THE SOFTWARE IS PROVIDED “AS IS”, WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/

#ifndef LOGGER_HEADER
#define LOGGER_HEADER

#include <stdio.h>
#include <stdarg.h>

// Used to specify which messages to log and which to not
enum LogLevel {
    INFO    = 1,
    WARNING = 1 << 1,
    ERROR   = 1 << 2,
    DEBUG   = 1 << 3,
};

// Current logging level
extern int LOGGING_LEVEL;

// Current logging output
extern FILE* LOG_OUTPUT;

// Sets logging level to a specified one
void set_log_level(int level);

// Output messages to output
void set_log_output(FILE* output);

// Creates file with fopen's mode and sets log output to it. Returns 0 
// in case of success, non 0 value otherwise
int create_log_file(const char* path, const char* mode);

// Closes previously opened log file and sets log output to stdout.
// Does nothing if log output is std(out|error|input)
void close_log_file();

// Log a message with custom prefix. Counts as INFO log message
void log_with_prefix(const char* prefix, const char* message, ...);

// Log information
void log_info(const char* message, ...);

// Log warning
void log_warning(const char* message, ...);

// Log error
void log_error(const char* message, ...);

// Debug log
void log_debug(const char* message, ...);

#endif