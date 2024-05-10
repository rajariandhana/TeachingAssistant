#include <stdio.h>
#include <string.h>

int main()
{
    while(1)
    {
        int cmd;
        scanf("%d", &cmd);
        if(cmd==0) break;

        char str[100];
        scanf("%s", str);
        int len = strlen(str);

        if(cmd==1) //reverse string
        {
            printf("The Aloos said: ");
            for(int i=len-1; i>=0; i--) printf("%c",str[i]);
            printf("\n");
        }
        else if(cmd==2) //palindrome
        {
            int isPalindrome = 1;
            for(int i=0; i<len/2; i++)
            {
                if(str[i]!=str[len-i-1])
                {
                    isPalindrome = 0;
                    break;
                }
            }

            if(isPalindrome) printf("Seems we have sometin in common\n");
            else printf("Maybe we dont\n");
        }
    }
    printf("Lets show this to DJ\n");
    printf("JD ot siht wohs steL\n");
    return 0;
    
}