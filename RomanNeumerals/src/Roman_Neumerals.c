#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "Roman_Neumerals.h"

char RomanResult[25];

/*Convert string case from Lower Case to Upper Case*/
void ConverttoUpperCase(char* str){
    
    int i;
    
    if(str){
        
        for(i=0;str[i];i++){
            str[i] = toupper(str[i]);
        }
        
    }
}
/*Convert String Value to Decimal Value*/
unsigned long getSumValue(char* ParseStr){
    
    int i;
    long sum = 0;
    int prev = 0;
    int curr = 0;
    
    for(i=0;i<strlen(ParseStr);i++){
        
        switch (ParseStr[i]) {
            
            case 'I':
                curr = 1;
                break;
            case 'V':
                curr = 5;
                break;
            case 'X':
                curr = 10;
                break;
            case 'L':
                curr = 50;
                break;
            case 'C':
                curr = 100;
                break;
            case 'D':
                curr = 500;
                break;
            case 'M':
                curr = 1000;
                break;
                
        }
        if(prev < curr){
            sum = (curr - sum);
            prev = curr;
        }else{
            sum += curr;
        }        
    }
    
    return sum;
}

/*Convert the Decimal Value back to string Value*/
void getRomanString(unsigned long value){
    
    long count = 0;
    memset(RomanResult, '\0', sizeof(RomanResult));
    
    while(value > 0){
        
        if(value/1000)
        {
            count = value/1000;
            while(count > 0){
             strcat(RomanResult, "M");
                count--;
            }
            value = value % 1000;
        }
        else if(value/500)
        {
            strcat(RomanResult, "D");
            value = value % 500;
        }
        else if(value/100)
        {
            count = value/100;
            if(count == 4)
            {
              strcat(RomanResult, "CD");
            }else
            {
                while(count <= 3 && count > 0)
                {
                    strcat(RomanResult, "C");
                    count--;
                }
            }
            value = value % 100;
        }
        else if(value/50)
        {
            strcat(RomanResult, "L");
            value = value % 50;
        }
        else if(value/10)
        {
            count = value/10;
            if(count == 4)
            {
                strcat(RomanResult, "XL");
            }else
            {
                while(count <= 3 && count > 0)
                {
                    strcat(RomanResult, "X");
                    count--;
                }
            }
            value = value % 10;
        }
        else if(value/5)
        {
            strcat(RomanResult, "V");
            value = value % 5;
        }
        else if(value/1)
        {
            count = value/1;
            if(count == 4)
            {
                strcat(RomanResult, "IV");
            }else
            {
                while(count <= 3 && count > 0)
                {
                    strcat(RomanResult, "I");
                    count--;
                }
            }
            break;
        }
        
    }
    
    return;
}

/*Add Roman Neumerals*/
char* AddRomanNeumerals(char* str1, char* str2){
    char *invalid_val = "\0";
    char* temp=RomanResult;
    long total=0;
    
    if(!str1){
       return invalid_val;
    }else{
        ConverttoUpperCase(str1);
    }
    
    if(!str2){
       return str1;
    }else{
        ConverttoUpperCase(str2);
    }
       
    total += getSumValue(str1) + getSumValue(str2);
    
    getRomanString(total);
        
    return temp;
}

/*Sub Roman Neumerals*/
char* SubRomanNeumerals(char* str1, char* str2){
    
    long total=0,sum1=0,sum2=0;
    char *temp=RomanResult;
    char *invalid_val = "\0";
    if(!str1){
        return invalid_val;
    }else{
        ConverttoUpperCase(str1);
    }
    
    if(!str2){
        return str1;
    }else{
        ConverttoUpperCase(str2);
    }
    
    sum1 = getSumValue(str1);
    sum2 = getSumValue(str2);
    
    if(sum1 > sum2){
        total = sum1 - sum2;
    }else{
       printf("The Sub1 value should be greater than Sub2 \n"); 
       return invalid_val; //Inavlid Sub
    }
    
    getRomanString(total);
    
    return temp;
    
}

