# Slog - dead simple logging library for C/C++
(Pun интендед)

## Usage 

```
#include "logger.h"

int main() {
    set_log_output(stdout);
    set_log_level(INFO|ERROR|WARNING);

    log_info("Some information: %d %s", 123, "fr");
    log_error("%s", "error message");
    log_debug("Debug won't be printed because the flag was not set");

    // Creates file with fopen's mode and sets log output to it
    create_log_file("logs.log", "w");
    log_info("Writing to a log file now");

    // Closes previously opened log file and sets log output to stdout.
    // Does nothing if log output is std(out|error|input)
    close_log_file();

    log_warning("And to %s again", "stdout");
}
```

## Build

- `make` - if you have `gcc` and `make` itself

or

- take out the header and an implementation file and compile the other way that is suitable in your environment

## License
MIT