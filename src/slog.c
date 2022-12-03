/*
The MIT License (MIT)
Copyright © 2022 Kasyanov Nikolay Alexeyevich (Unbewohnte)
Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the “Software”), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:
The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.
THE SOFTWARE IS PROVIDED “AS IS”, WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/

#include "slog.h"

// Current logging level
int LOGGING_LEVEL = INFO|WARNING|ERROR|DEBUG;

// Current logging output
FILE* LOG_OUTPUT;

// Sets logging level to a specified one
void set_log_level(int level) {
    LOGGING_LEVEL = level;
}

// Output messages to output instead
void set_log_output(FILE* output) {
    if (output) {
        LOG_OUTPUT = output;
    } else {
        LOG_OUTPUT = stdout;
    }
}

// Creates file with fopen's mode and sets log output to it. Returns 0 
// in case of success, non 0 value otherwise
int create_log_file(const char* path, const char* mode) {
    FILE* log_file;
    
    log_file = fopen(path, mode);
    if (!log_file) {
        return 1;
    }

    set_log_output(log_file);

    return 0;
}

// Closes previously opened log file and sets log output to stdout.
// Does nothing if log output is std(out|error|input)
void close_log_file() {
    if (LOG_OUTPUT && !(LOG_OUTPUT == stdout || LOG_OUTPUT == stderr || LOG_OUTPUT == stdin)) {
        fclose(LOG_OUTPUT);
        set_log_output(stdout);
    }
}

// Log a message with custom prefix. Counts as INFO log message
void log_with_prefix(const char* prefix, const char* message, ...) {
    if (LOG_OUTPUT && ((LOGGING_LEVEL & INFO) == INFO) && prefix && message) {
        va_list arg;

        fprintf(LOG_OUTPUT, "%s", prefix);
        va_start(arg, message);
        vfprintf(LOG_OUTPUT, message, arg);
        va_end(arg);
        fprintf(LOG_OUTPUT, "\n");
    }
}

// Log information
void log_info(const char* message, ...) {
    if (LOG_OUTPUT && ((LOGGING_LEVEL & INFO) == INFO) && message) {
        va_list arg;

        fprintf(LOG_OUTPUT, "[INFO] ");
        va_start(arg, message);
        vfprintf(LOG_OUTPUT, message, arg);
        va_end(arg);
        fprintf(LOG_OUTPUT, "\n");
    }
}

// Log warning
void log_warning(const char* message, ...) {
    if (LOG_OUTPUT && ((LOGGING_LEVEL & WARNING) == WARNING) && message) {
        va_list arg;

        fprintf(LOG_OUTPUT, "[WARNING] ");
        va_start(arg, message);
        vfprintf(LOG_OUTPUT, message, arg);
        va_end(arg);
        fprintf(LOG_OUTPUT, "\n");
    }
}

// Log error
void log_error(const char* message, ...) {
    if (LOG_OUTPUT && ((LOGGING_LEVEL & ERROR) == ERROR) && message) {
        va_list arg;

        fprintf(LOG_OUTPUT, "[ERROR] ");
        va_start(arg, message);
        vfprintf(LOG_OUTPUT, message, arg);
        va_end(arg);
        fprintf(LOG_OUTPUT, "\n");
    }
}

// Debug log
void log_debug(const char* message, ...) {
    if (LOG_OUTPUT && ((LOGGING_LEVEL & DEBUG) == DEBUG) && message) {
        va_list arg;

        fprintf(LOG_OUTPUT, "[DEBUG] ");
        va_start(arg, message);
        vfprintf(LOG_OUTPUT, message, arg);
        va_end(arg);
        fprintf(LOG_OUTPUT, "\n");
    }
}