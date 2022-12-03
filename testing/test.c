#include "../src/slog.h"

int main() {
    set_log_output(stdout);
    set_log_level(INFO|ERROR|WARNING);

    log_info("Some information: %d %s", 123, "fr");
    log_error("%s", "error message");
    log_debug("Debug won't be printed because the flag was not set");

    create_log_file("logs.log", "w");
    log_info("Writing to a log file now");
    close_log_file();

    log_warning("And to %s again", "stdout");

    log_with_prefix("[Custom prefix] ", "5+(4*90)==%d", 5+(4*90));
}