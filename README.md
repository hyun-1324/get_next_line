# get_next_line

A lightweight C library that provides a `get_next_line()` function to read a file line by line.

---

## 📝 What It Does

`get_next_line()` reads and returns the next line from a file or standard input — one call, one line.
It handles all the behind-the-scenes work: buffering, memory management, partial reads, and newline detection.

✔️ Reads from any valid file descriptor
✔️ Handles very large or very small buffers
✔️ Returns lines that include the newline character `\n` if present
✔️ Returns `NULL` when there is nothing left to read

---

## 🚀 How to Compile

```bash
# For the basic version:
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c main.c

# For the bonus version (supports multiple files at once):
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line_bonus.c get_next_line_utils_bonus.c main.c
```

> You can choose any `BUFFER_SIZE` value.

---

## 💻 Example

```c
#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main(void)
{
    int fd = open("example.txt", O_RDONLY);
    char *line;

    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);
    }
    close(fd);
    return 0;
}
```

---

## 📄 License

This project is licensed under the MIT License.
See the [LICENSE](./LICENSE) file for details.
