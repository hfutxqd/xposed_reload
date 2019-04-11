#include <stdio.h>
#include <string.h>

#define PACKAGES_FILE "/system/xposed_packages.list"
#define MODULES_FILE "/system/xposed_modules.list"

int find_equals(const char* str) {
    int i = 0;
    for (; str[i] != '=' && str[i] != 0; i++);
    return i;
}

int main(int argc, char **argv) {
    FILE *file = fopen(PACKAGES_FILE, "r");
    FILE *modules_file = fopen(MODULES_FILE, "w");
    if (file != NULL && modules_file != NULL) {
        char line[128];
        while (fgets(line, sizeof line, file) != NULL) {
            int pos = find_equals(line);
            fputs(line + pos + 1, modules_file);
            line[pos] = 0;
            printf("enabled: %s\n", line);
        }
        fclose(file);
        fclose(modules_file);
    } else {
        if (file) {
            perror(MODULES_FILE);
        } else {
            perror(PACKAGES_FILE);
        }
    }

    return 0;
}