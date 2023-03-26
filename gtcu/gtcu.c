// GCTU - Genetic code translation utiliy

#include <stdio.h>
#include <string.h>

int main()
{
    char dna_seq[1000], rna_seq[1000], mrna_seq[1000], trna_seq[1000];
    int len, i;

    // get input DNA sequence
    printf("\033[38;2;74;213;42mEnter the DNA sequence: ");
    scanf("%s", dna_seq);
    len = strlen(dna_seq);

    // initialize RNA sequence
    for (i = 0; i < len; i++) {
        if (dna_seq[i] == 'T') {
            rna_seq[i] = 'U';
        } else {
            rna_seq[i] = dna_seq[i];
        }
    }

    // initialize mRNA sequence
    for (i = 0; i < len; i++) {
        if (rna_seq[i] == 'U') {
            mrna_seq[i] = 'A';
        } else if (rna_seq[i] == 'A') {
            mrna_seq[i] = 'U';
        } else if (rna_seq[i] == 'C') {
            mrna_seq[i] = 'G';
        } else if (rna_seq[i] == 'G') {
            mrna_seq[i] = 'C';
        }
    }

    // initialize tRNA sequence
    for (i = 0; i < len; i++) {
        if (mrna_seq[i] == 'A') {
            trna_seq[i] = 'U';
        } else if (mrna_seq[i] == 'U') {
            trna_seq[i] = 'A';
        } else if (mrna_seq[i] == 'G') {
            trna_seq[i] = 'C';
        } else if (mrna_seq[i] == 'C') {
            trna_seq[i] = 'G';
        }
        if ((i + 1) % 3 == 0) {
            trna_seq[i+1] = ' ';
        }
    }

    // output resulting RNA sequence
    printf("\033[1;32mRNA sequence (rRNA): \033[0m");
    for (i = 0; i < len; i++) {
        printf("\033[0;36m%c", rna_seq[i]);
        if ((i + 1) % 3 == 0) {
            printf(" ");
        }
    }
    printf("\n");

    // output resulting mRNA sequence
    printf("\033[1;32mmRNA sequence: \033[0m");
    for (i = 0; i < len; i++) {
        if (mrna_seq[i] != '\0') {
            printf("\033[0;36m%c", mrna_seq[i]);
            if ((i + 1) % 3 == 0) {
                printf(" ");
            }
        }
    }
    printf("\n");

    // output resulting tRNA sequence
    printf("\033[1;32mtRNA sequence: \033[0m");
    for (i = 0; i < len; i++) {
        if (trna_seq[i] != '\0') {
            printf("\033[0;36m%c", trna_seq[i]);
            if ((i + 1) % 3 == 0) {
                printf(" ");
            }
        }
    }
    printf("\n");

    return 0;
}
