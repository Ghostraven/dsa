#include <cstdio>
#include <iostream>
#include <cstring>

#define NMAX 256

using namespace std;

void intAndFloat() {
    int pointIndex = 0;
    char myNumber[40];
    char *p = myNumber;
    cin >> myNumber;
    for (int i = 0; i < 40; i++) {
        if (*(p+i) != '\0') {
            if (*(p+i) == '.') {
                pointIndex = i;
                break;
            }
        } else {
            break;
        }
    }
    cout << "The integer part of the number is: ";
    for (int i = 0; i < pointIndex; i++) {
        cout << *(p+i);
    }
    cout << endl << "The float part of the number is: ";
    for (int i = pointIndex; i < 40; i++) {
        if (*(p+i) != '\0') {
            cout << *(p+i);
        } else {
            break;
        }
    }
    cout << endl;
}


void commonWords() {
    char first[NMAX], second[NMAX], x[NMAX][NMAX / 8], y[NMAX][NMAX / 8];
    char s[] = " ,.?!";
    char *t, *p1 = first, *p2 = second;
	int xn = 0, yn = 0;
	strcpy(first, "How much wood would a woodchuck chuck if a woodchuck could chuck wood?\0");
	strcpy(second, "I am a woodchuck.\0");

	t = strtok(p1, s);
	while (t != NULL) {
		strcpy(x[xn++], t);
		t =  strtok(NULL, s);
	}
	
	for (int i = 0; i < xn - 1; i++)
		for (int j = i + 1; j < xn; j++)
			if (strcmp(x[i], x[j]) == 0)
				strcpy(x[j], " ");
	
	t = strtok(p2, s);
	while (t != NULL) {
		strcpy(y[yn++], t);
		t =  strtok(NULL, s);
	}
	
	for (int i = 0; i < xn; i++)
		for (int j = 0; j < yn; j++)
			if (strcmp(x[i], y[j]) == 0)
				printf("%s ", x[i]);	
	
	printf("\n");
}

void chick() {
    char x[NMAX], s[] = "aeiou";
    strcpy(x, "Ce faci?");
    char * p = x;
    for (int i = 0; i < strlen(x); i++) {
        cout << *(p+i);
        if (strchr(s, (*(p+i))) != NULL) {
            printf("p%c", (*(p+i)));
        }
    }
    cout << endl;
}

int main() {
    intAndFloat();
    chick();
    commonWords();
    return 0;
}
