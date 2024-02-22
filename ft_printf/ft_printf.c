#include <stdarg.h>
#include <stdio.h>

void my_printf(const char *format, ...) {
    va_list args;
    va_start(args, format);

    while (*format != '\0') {
        if (*format == '%') {
            format++;
            switch (*format) {
                case 's': {
                    char *string = va_arg(args, char*);
                    printf("%s", string);
                    break;
                }
                case 'd': {
                    int num = va_arg(args, int);
                    printf("%d", num);
                    break;
                }
                default:
                    printf("%c", *format);
            }
        } else {
            putchar(*format);
        }
        format++;
    }

    va_end(args);
}