#ifndef ARRAY_H_INCLUDED
#define ARRAY_H_INCLUDED

#pragma once

double *MakeDblArray(long lenght);

void PrintDblArr(double *arr, long lenght);
void ScanDblArr(double *arr, long lenght);
long GetIndexOfMaxElement(double *arr, long length);

#endif