# Slog - dead simple logging library for C/C++
(Pun интендед)

## Usage 

Logging is done via appropriate (info|warning|error|debug) log functions. Before calling them it is needed to execute `set_log_output` and pass `FILE*` of your liking (usually `stdout`), all log messages will be printed there unless you `set_log_output` somewhere other place again.

There are log levels as well. By default all levels are set, but you can override them with `set_log_level` by either specifying one log level (`INFO`, `WARNING`, `ERROR`, `DEBUG`) or chaining them with `|`.

```
#include "logger.h"

int main() {
    set_log_output(stdout);
    set_log_level(INFO|ERROR|WARNING);

    log_info("Some information: %d %s", 123, "fr");
    log_error("%s", "error message");
    log_debug("Debug won't be printed because the flag was not set");
    log_with_prefix("[Custom prefix] ", "5+(4*90)==%d", 5+(4*90));

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