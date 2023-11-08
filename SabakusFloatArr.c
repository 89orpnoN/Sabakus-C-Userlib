#include "SabakusFloatArr.h"
#include <stdlib.h>
#include <stdio.h>


struct FloatArr FloatArrContructor(){
    struct FloatArr item;
    item.Len = 0;
    item.Tlen = 100;
    item.Arr = calloc(item.Tlen,sizeof( (float)3 ) );
    return item;
}

int ExpandCharArr(struct FloatArr arr){
    arr.Tlen*=2;
    realloc(arr.Arr,sizeof((float)3)*arr.Tlen);
    if (arr.Arr == NULL) return 0;
    return 1;
}

int IntAppend(struct FloatArr arr, float i){
    arr.Arr[arr.Len] = i;
    arr.Len++;
    if (arr.Len>=arr.Tlen){

        if(!ExpandCharArr(arr)) return 0;
    }
    return 1;
}

int IntPop(struct FloatArr arr){
    if(arr.Len<1) return 0;
    arr.Len--;
    arr.Arr[arr.Len]=0;
    return 1;
}
