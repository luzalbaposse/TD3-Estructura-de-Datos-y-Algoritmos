#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int padre(int pos) {
    return (pos - 1) / 2;
}

int hijo_izq(int pos) {
    return 2 * pos + 1;
}

int hijo_der(int pos) {
    return 2 * pos + 2;
}

// Bajar (max-heap)
int max_hijo(const vector<int>& heap, int pos) {
    int ret = pos;
    if (hijo_izq(pos) < heap.size() && heap[ret] < heap[hijo_izq(pos)]) {
        ret = hijo_izq(pos);
    }
    if (hijo_der(pos) < heap.size() && heap[ret] < heap[hijo_der(pos)]) {
        ret = hijo_der(pos);
    }
    return ret;
}

void bajar(vector<int>& heap, int pos, int tam) {
    int pos_bajar = max_hijo(heap, pos);
    if (pos_bajar < tam && pos_bajar != pos) {
        swap(heap[pos], heap[pos_bajar]);
        bajar(heap, pos_bajar, tam);
    }
}

// Subir (max-heap)
void subir(vector<int>& heap, int pos) {
    if (pos && heap[padre(pos)] < heap[pos]) {
        swap(heap[pos], heap[padre(pos)]);
        subir(heap, padre(pos));
    }
}

void insertar_heap(int n, vector<int>& heap) {
    heap.push_back(n);
    subir(heap, heap.size() - 1);
}

void eliminar_maximo(vector<int>& heap, int tam) {
    swap(heap[0], heap[tam - 1]);
    bajar(heap, 0, tam - 1);
}

void construir_max_heap(vector<int>& v) {
    for (int i = v.size() / 2 - 1; i >= 0; i--) {
        bajar(v, i, v.size());
    }
}

void heapsort(vector<int>& v) {
    construir_max_heap(v);

    for (int i = v.size() - 1; i > 0; i--) {
        swap(v[0], v[i]);
        bajar(v, 0, i);
    }
}

int main() {
    vector<int> v = {10, 5, 15, 2, 7, 12, 20};
    cout << "Vector original:" << endl;
    for (int i : v) {
        cout << i << " ";
    }
    cout << endl;

    heapsort(v);

    cout << "Vector ordenado:" << endl;
    for (int i : v) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
