#include <stdio.h>
#include <string.h>

void _rev(char* str) {
    int n = strlen(str);
    for (int i = 0; i < n/2; i++)
    {
        char t = str[i];
        str[i] = str[n-i-1];
        str[n-i-1] = t;
    }
}

void recursive_sum(char* str0) {
    char *str = str0;
    char num1[101]="0", num2[101]="0", res[105]={};
   
    int a = strlen(str)/2;
    strncpy(num1, str, a);
    _rev(str);
    a = strlen(str) - a;
    strncpy(num2, str, a);

    int n1 = strlen(num1), n2 = strlen(num2);
    int n = (n1 > n2) ? n1 : n2;

    // reverse the number (string)
    _rev(num1);

    // append 0s till the number of digit of both are equal
    char czero[3] = "00";
    strcat(num1, czero);
    strcat(num2, czero);
    
    // arithmetic addition
    int carry = 0;
    for (int i = 0; i <= n; i++) {
        int a = num1[i] - '0', b = num2[i] - '0';
        res[i] = ((a + b + carry) % 10) + '0';
        carry = ((a + b + carry) >= 10) ? 1 : 0;
    }

    for (int i = n; i >= 0; i--)
    {
        if (res[i] != '0') break;
        else {
            res[i] = 0;
        }
    }
    
    _rev(res);
    printf("%s\n", res);
     
    if (strlen(res) <= 1) return;

    return recursive_sum(res);
}

int main() {

    char inp_str[202];

    scanf("%s", inp_str);

    recursive_sum(inp_str);

    return 0;
}