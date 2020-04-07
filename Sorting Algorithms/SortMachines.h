#ifndef INCLUDE_SORT_MACHINES_H
#define INCLUDE_SORT_MACHINES_H

#include<vector>
#include<iostream>
#include<algorithm>
#include<stdio.h>
#include<random> //To get the mersenne twister engine
#include<chrono> //To get time

////////////////////
// ESTO IGNORENLO //
////////////////////
class RandGen{
public:
    static RandGen& get(){
        if(_instance == nullptr){
            _instance = new RandGen();
        }
        return *_instance;
    }
    std::mt19937 gen;
private:
    static RandGen* _instance;
    RandGen(){
        unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
        gen = std::mt19937(seed);
    };
    ~RandGen(){};
};

RandGen* RandGen::_instance = nullptr;
/////////////////////////////////
// DEJEN DE IGNORAR DESDE AQUI //
/////////////////////////////////
class SortMachine{
public:
    SortMachine(){};

    virtual void sort(std::vector<int> &target) = 0;

    // Imprime el vector target de una manera bonita
    static void print(std::vector<int> &target){
        std::cout << target[0];
        for(int i = 1; i < target.size(); i++){
            std::cout << ", " << target[i];
        }
        std::cout << "\n";
    }

    // Hace aleatorio el vector target
    void shuffle(std::vector<int> &target){
        std::shuffle(target.begin(), target.end(), RandGen::get().gen);
    }
    std::string name = "No Name Sort";
};

/************************************** *
 * A partir de aquí comienza su trabajo *
 * *************************************/

class BubbleSort: public SortMachine{
public:
    BubbleSort(){this->name = "Bubble Sort";}
    void sort(std::vector<int> &target){
        for(int j=target.size()-1;j>0;j--){
            for(int i=0;i<j;i++){
                if(target[i]>target[i+1]){
                    std::iter_swap(target.begin()+i,target.begin()+(i+1));
                }
            }
         //SortMachine::print(target) //Si se quiere ver cada paso
        }
    }
};

class InsertionSort: public SortMachine{
public:
    InsertionSort(){this->name = "Insertion Sort";}
    void sort(std::vector<int> &target){
        for(int j=1; j < target.size(); j++){
            for(int i=j; i > 0;i--){
                if(target[i]<target[i-1]){
                    std::iter_swap(target.begin()+i,target.begin()+(i-1));
                } 
            }
         //SortMachine::print(target) //Si se quiere ver cada paso
        }
    }
};
class MergeSort: public SortMachine{
public:
    MergeSort(){this->name = "Merge Sort";}
    void sort(std::vector<int> &target){
        if(target.size()<2){
            return;
        }
        std::vector<int> A;
        std::vector<int> B;
        int mit=target.size()/2;
        for (int i = 0; i < mit;i++){
            A.push_back(target[i]);
        }
        for (int i = 0; i < (target.size()) - mit; i++){
            B.push_back(target[mit + i]);
        }
        sort(A);
        sort(B);
        Merge(target, A, B);
    }
    void Merge(std::vector<int>& target, std::vector<int> A, std::vector<int>& B){
        int i = 0, j = 0, k = 0;
        while (j < A.size() && k < B.size()) 
        {
            if (A[j] < B[k]) {
                target[i] = A[j];
                j++;
            }
            else {
                target[i] = B[k];
                k++;
            }
            i++;
        }
        while (j < A.size()) {
            target[i] = A[j];
            j++; i++;
        }
        while (k < B.size()) {
            target[i] = B[k];
            k++; i++;
        }
    }
};

class HeapSort: public SortMachine{
public:
    HeapSort(){this->name = "Heap Sort";}
    void MaxHeap(std::vector<int> &target, int i, int j){
         //Convierte el Heap en un MaxHeap
        int maxindex= i ;
        int left=2*i+1;
        int right=2*i+2;
        if(left <= j && target[left]>target[i]){
            maxindex=left;
        }
        if(right <= j && target[right]>target[left]){
            maxindex=right;
        }
        std::iter_swap(target.begin()+i,target.begin()+maxindex);
    }
    void sort(std::vector<int> &target){
        for(int j= target.size()-1;j>0;j--){
            for(int i=target.size()-1; i>=0 ;i--){
                HeapSort::MaxHeap(target,i,j);
            }
        std::iter_swap(target.begin(),target.begin()+j);
        //SortMachine::print(target); //Si se quiere ver cada paso
        }
    }
};

#endif //INCLUDE_SORT_MACHINES_H