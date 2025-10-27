#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main() {
    FILE *fp;
    int i, j, stradd1;
    char line[60], name[60], stradd[60];

    fp = fopen("objectcode.txt", "r");
    fscanf(fp, "%s", line);

    for (i = 2, j = 0; i < 8 && j < 6; i++, j++) {
        name[j] = line[i];
    }
    name[j] = '\0';
    printf("Program Name: %s\n", name);

    do {
        fscanf(fp, "%s", line);

        if (line[0] == 'T') {
            for (i = 2, j = 0; i < 8 && j < 6; i++, j++) {
                stradd[j] = line[i];
            }
            stradd[j] = '\0';
            stradd1 = strtol(stradd, NULL, 16);

            i = 12;
            while (line[i] != '\0') {
                if (line[i] == '^') {
                    i++;
                    continue;
                } else {
                    printf("%X : \t%c%c\n", stradd1, line[i], line[i + 1]);
                    stradd1++;
                    i += 2;
                }
            }
        } 
        else if (line[0] == 'E') {
            break;
        }

    } while (!feof(fp));
    fclose(fp);
}
