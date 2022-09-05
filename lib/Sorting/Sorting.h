#ifndef SORTING_H_INCLUDED
#define SORTING_H_INCLUDED

#pragma once

void BubbleSort(double *arr, long length);
void SelectionSortMax(double *arr, long length);
void SelectionSortMin(double *arr, long length);
void InsertionSort(double *arr,long length);
void QuickSort(double *arr, long startIndx, long endIndx);
void MergeSort(double *arr,long startIndx,long endIndx);
#endif