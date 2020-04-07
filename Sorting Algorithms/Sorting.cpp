#include "SortMachines.h"

int main() {
    /////////////////////////////////
    //          Bubble             //
    /////////////////////////////////
    SortMachine *my_sort_machine_1 = new BubbleSort();    // Máquina 1, con un BubbleSort
    std::cout<< my_sort_machine_1->name << ": " << std::endl;
    std::vector<int> x(10);
    for(int i = 0; i < x.size(); i++){
           x[i] = i;
    }
    my_sort_machine_1->shuffle(x);    // Alteramos el orden de x
    SortMachine::print(x);    // Lo imprimimos nadamás porque sí
    my_sort_machine_1->sort(x);    // En principio, ordenamos
    SortMachine::print(x);    // Imprimimos el resultado

    /////////////////////////////////
    //          Insert             //
    /////////////////////////////////
    SortMachine *my_sort_machine_2 = new InsertionSort();    // Máquina 2, con un Insertion Sort
    std::cout<< my_sort_machine_2->name << ": " << std::endl;
    std::vector<int> y(10);
    for(int i = 0; i < y.size(); i++){
        y[i] = i;
    }
    my_sort_machine_2->shuffle(y);    // Alteramos el orden de y
    SortMachine::print(y);    // Lo imprimimos nadamás porque sí
    my_sort_machine_2->sort(y);    // En principio, ordenamos
    SortMachine::print(y);    // Imprimimos el resultado

    /////////////////////////////////
    //          Merge              //
    /////////////////////////////////
    SortMachine *my_sort_machine_3 = new MergeSort();    // Máquina 3, con un Merge Sort
    std::cout<< my_sort_machine_3->name << ": " << std::endl;
    std::vector<int> z(10);
    for(int i = 0; i < z.size(); i++){
        z[i] = i;
    }
    my_sort_machine_3->shuffle(z);    // Alteramos el orden de y
    SortMachine::print(z);    // Lo imprimimos nadamás porque sí
    my_sort_machine_3->sort(z);    // En principio, ordenamos
    SortMachine::print(z);    // Imprimimos el resultado

    /////////////////////////////////
    //            Heap             //
    /////////////////////////////////
    SortMachine *my_sort_machine_4 = new HeapSort();    // Máquina 4, con un Heap Sort
    std::cout<< my_sort_machine_4->name << ": " << std::endl;
    std::vector<int> w(10);
    for(int i = 0; i < w.size(); i++){
        w[i] = i;
    }
    my_sort_machine_4->shuffle(w);    // Alteramos el orden de y
    SortMachine::print(w);    // Lo imprimimos nadamás porque sí
    my_sort_machine_4->sort(w);    // En principio, ordenamos
    SortMachine::print(w);    // Imprimimos el resultado

    return 0;
}