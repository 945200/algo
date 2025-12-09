#include <stdio.h>
#include <string.h>
#include <stdlib.h>


char *LoadString(int N);
int StringLength(char *str);
void LoadArray(char *p, char arr[]);
void ReverseArray(char arr[], char rev[], int n);
void DisplayArray(char arr[], int n);
int SumStringASCII(char *p);
void ReverseString(char *start, char *end);

int main() {
    char *str;
    int n;

    printf("Please enter the maximum size of the string:\n");
    scanf("%d", &n);
    getchar();
    
    str = LoadString(n);
    int len = StringLength(str);
    
    char arr[len + 1], rev[len + 1];
    
    LoadArray(str, arr);
    printf("\n Original array: ");
    DisplayArray(arr, len);
    
    ReverseArray(arr, rev, len);
    printf("\n Reversed array: ");
    DisplayArray(rev, len);
    
    int sum = SumStringASCII(str);
    printf("\n Sum of ASCII values: %d\n", sum);
    
    ReverseString(str, str + len - 1);
    printf("String reversed recursively: %s\n", str);
    
    free(str);
    return 0;
}


char *LoadString(int N) {
    char *str = (char *)malloc((N + 1) * sizeof(char));
    if (str == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    
    printf("Please enter the string (max %d characters):\n", N);
    fgets(str, N + 1, stdin);
    
    
    size_t len = strlen(str);
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }
    
    return str;
}


int StringLength(char *str) {
    int length = 0;
    while (str[length] != '\0') {
        length++;
    }
    return length;
}

void LoadArray(char *p, char arr[]) {
    int i = 0;
    while (p[i] != '\0') {
        arr[i] = p[i];
        i++;
    }
    arr[i] = '\0'; 
}


void ReverseArray(char arr[], char rev[], int n) {
    for (int i = 0; i < n; i++) {
        rev[i] = arr[n - 1 - i]; 
    }
    rev[n] = '\0'; 
}


void DisplayArray(char arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%c", arr[i]);
    }
    printf("\n");
}

int SumStringASCII(char *p) {
    if (*p == '\0') {
        return 0; 
    }
    return (int)*p + SumStringASCII(p + 1); 
}


void ReverseString(char *start, char *end) {
    if (start >= end) {
        return; 
    }
    
 
    char temp = *start;
    *start = *end;
    *end = temp;
    
   
    ReverseString(start + 1, end - 1);
}
