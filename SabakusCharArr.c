#include "SabakusCharArr.h"
#include <stdlib.h>
#include <stdio.h>

struct CharArr CharArrContructor(){
    struct CharArr item;
    item.Len = 0;
    item.Tlen = 100;
    item.Arr = calloc(item.Tlen,sizeof( (char)3 ) );
    return item;
}

int ExpandCharArr(struct CharArr arr){
    arr.Tlen*=2;
    realloc(arr.Arr,sizeof((char)3)*arr.Tlen);
    if (arr.Arr == NULL) return 0;
    return 1;
}

int CharAppend(struct CharArr arr, char i){
    arr.Arr[arr.Len] = i;
    arr.Len++;
    if (arr.Len>=arr.Tlen){

        if(!ExpandCharArr(arr)) return 0;
    }
    return 1;
}

int CharPop(struct CharArr arr){
    if(arr.Len<1) return 0;
    arr.Len--;
    arr.Arr[arr.Len]=0;
    return 1;
}
