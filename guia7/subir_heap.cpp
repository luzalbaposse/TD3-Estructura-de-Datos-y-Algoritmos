#include <vector>
#include <iostream>
using namespace std;
#include <list>
#include <gtest/gtest.h>

vector<int> _heap;
int padre(int pos){
    return (pos-1)/2;
}

int hijo_izq(int pos){
    return 2*pos+1;
}

int hijo_der(int pos){
    return 2*pos+2;
}

// Bajar Max-Heap
int max_hijo(const vector<int>&heap, int pos){
    int ret = pos;
    if(hijo_izq(pos) < heap.size() && heap[ret] < heap[hijo_izq(pos)]){
        ret = hijo_izq(pos);
    }
    if(hijo_der(pos) < heap.size() && heap[ret] < heap[hijo_der(pos)]){
        ret = hijo_der(pos);
    }
    return ret;
}

void bajar(vector<int>& heap, int pos) {
    int pos_bajar = max_hijo(heap, pos);
    if (pos_bajar != pos) {
        swap(heap[pos], heap[pos_bajar]);
        bajar(heap, pos_bajar);
    }
 }
//Subir Max Heap

void subir(vector<int>& heap, int pos) {
    if (pos && heap[padre(pos)] < heap[pos]) {
        swap(heap[pos], heap[padre(pos)]);
        subir(heap, padre(pos));
    }
}

 void insertar_heap(int n, vector<int> &heap){
    heap.push_back(n);
    subir(heap,heap.size()-1);
 }
 void eliminar_maximo(vector <int> &heap){
    heap[0] = heap[heap.size()-1];
    heap.pop_back();
    bajar(heap,0);
 }


 int main() {
    vector<int> heap;
    insertar_heap(10, heap);
    insertar_heap(5, heap);
    insertar_heap(15, heap);
    insertar_heap(2, heap);
    insertar_heap(7, heap);
    insertar_heap(12, heap);
    insertar_heap(20, heap);

    cout << "Heap después de inserciones:" << endl;
    for (int i : heap) {
        cout << i << " ";
    }
    cout << endl;

    eliminar_maximo(heap);
    cout << "Heap después de eliminar el máximo:" << endl;
    for (int i : heap) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}