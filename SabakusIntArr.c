#include "SabakusIntArr.h"
#include <stdio.h>
#include <stdlib.h>


struct IntArr IntArrContructor(){
    struct IntArr item;
    item.Len = 0;
    item.Tlen = 100;
    item.Arr = calloc(item.Tlen,sizeof( (int)3 ) );
    return item;
}

int ExpandIntArr(struct IntArr arr){
    arr.Tlen*=2;
    realloc(arr.Arr,sizeof((int)3)*arr.Tlen);
    if (arr.Arr == NULL) return 0;
    return 1;
}

int IntAppend(struct IntArr arr, int i){
    arr.Arr[arr.Len] = i;
    arr.Len++;
    if (arr.Len>=arr.Tlen){

        if(!ExpandIntArr(arr)) return 0;
    }
    return 1;
}

int IntPop(struct IntArr arr){
    if(arr.Len<1) return 0;
    arr.Len--;
    arr.Arr[arr.Len]=0;
    return 1;
}

