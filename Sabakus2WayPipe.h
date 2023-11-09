#ifndef SABAKUS_C_USERLIB_SABAKUS2WAYPIPE_H
#define SABAKUS_C_USERLIB_SABAKUS2WAYPIPE_H

#include <unistd.h>
#include "SabakusVoidArr.h"

enum Types {
    Void, //se lo usi sei malato
    String,
    Int,
    Float,
};
int TypeLenghts[4] = {
        1,
        sizeof(string),
        sizeof(int),
        sizeof(float)
};

typedef struct {
    int UpStream[2];
    int DownStream[2];
    short short int Type;
    short short int ChunkSize;
    int Pid1;
    int Pid2;

}S2WPipe;

typedef struct {
void* Data;
short int Type;
}SPReadings;

S2WPipe S2WPipeConstructor(int Pid1,int Pid2,int type){
    S2WPipe Pipe;
    if (pipe(Pipe.UpStream)<0 || pipe(Pipe.DownStream)<0) return Pipe;
    Pipe.Pid1 = Pid1;
    Pipe.Pid2 = Pid2;
    Pipe.Type = type;
    Pipe.ChunkSize = TypeLenghts[type]
}

void*

#endif //SABAKUS_C_USERLIB_SABAKUS2WAYPIPE_H
