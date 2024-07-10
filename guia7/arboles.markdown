# Árboles
Table of Contents
=================

- [Árboles](#árboles)
- [Table of Contents](#table-of-contents)
  - [Árbol Binario](#árbol-binario)
  - [Arbol Binario Completo](#arbol-binario-completo)
    - [Árbol Binario -\> Recorrida Inorder](#árbol-binario---recorrida-inorder)
    - [Árbol Binario -\> Recorrida PreOrder](#árbol-binario---recorrida-preorder)
  - [Árbol Binario de Búsqueda](#árbol-binario-de-búsqueda)
  - [Árbol AVL](#árbol-avl)
  - [Heap](#heap)
    - [Max Heap:](#max-heap)

## Árbol Binario
Es una estructura de nodos conectados en la que:
- Cada nodo está conectado a lo sumo con dos nodos.
- Hay un único nodo que tiene padre, y es la raíz.
- No tiene ciclos y cada nodo tiene un único padre.
Se puede representar como:

```cpp
struct nodo{
    int elem;
    nodo* izq;
    nodo* der;
}
```

## Arbol Binario Completo
Está completo si todos los niveles del árbol tienen la máxima cantidad de nodos posible. Es decir, si el árbol tiene `n` niveles, entonces tiene `2^n - 1` nodos.

```cpp
struct nodo{
    int elem;
    nodo* izq;
    nodo* der;
}

nodo*crear_hoja(int elem){
    return new nodo{elem, nullptr, nullptr};
}

nodo* armar_arbol(){
    return new nodo({1, crear_hoja(2), crear_hoja(3)}), new nodo({2, crear_hoja(4), crear_hoja(5)});
}
```

### Árbol Binario -> Recorrida Inorder
Recorre todos los nodos del árbol así:
1. Primero recorrer el subarbol izquierdo,
2. Luego visitar la raiz
3. Luego recorrer el subarbol derecho

void inorder_imprimir(nodo*arbol){

    if(arbol == nullptr) return;
    inorder_imprimir(arbol->izquierdo);
    cout << arbol->elem << endl;
    inorder_imprimir(arbol->derecho);

}

### Árbol Binario -> Recorrida PreOrder

Recorre todos los nodos así:
1. Primero la raiz
2. Después subarbol izquierdo
3. Después subarbol derecho

void preorder_imprimir(nodo*arbol){
    if(arbol == nullptr) return;
    cout<< arbol->elem << endl;
    preorder_imprimir(arbol->izquierdo);
    preorder_imprimir(arbol->derecho);
}

## Árbol Binario de Búsqueda
Problema: Quiero almacenar elementos ordenados y agregar/sacar/buscar de manera eficiente:
- Agregar en O(log n)
- Quitar en O(log n)
- Buscar en O(log n)

Para que un árbol sea binario de búsqueda:
- El elemento de la raíz es mayor que los de la izquierda y menor que los de la derecha.
- Mantengo la altura cercana a log n
  
Rep de ABB:
Para todo n del arbol:
n.elem > todo elemento de n-> izquierdo
n.elem < todo elemento de n-> derecho

Buscar en un ABB:
bool buscar(int n, nodo * abb){
    if(abb == nullptr){
        return false;
    }
    else if(n == abb->elem){
        return true;}
    else if(n < abb->elem){
    return buscar(n, abb->izquierdo); // Está ordenado : )
    }
    else if(n>= abb->elem){
        return buscar(n, abb->derecho);
    }
} // O(h) con h altura del árbol.

Insertar en un ABB:

nodo* insertar(int n, nodo* abb){
    if(abb == nullptr){
        return new nodo(n);
    }
    else if(n < abb->elem){
        abb->izquierdo = insertar(n, abb->izquierdo):
    }
    else if(n > abb-> elem){
        abb->derecho=insertar(n, abb->derecho);
    }
    return abb;
}

Borrar en un ABB es un poco complicado, porque hay que considerar cómo hacemos para reestructurar todo el arbol en base a haber borrado eso.

// PRE: n está en abb
// POST: Elimina n y devuelve la raiz (o la nueva si cambio)

nodo*borrar(int n, nodo  *abb){
    if(n<abb->elem){
        // actualiza el lado izquierdo
        abb->izquierdo = borrar(n,abb->izquierdo);
        return abb;
    }
    else if(n > abb->elem){
        abb->derecho = borrar(n, abb->derecho);
        return abb;
    }
    else{
        // calcula reemplazante y elimina nodo actual
        nodo*nueva_raiz = descontectar_raiz(abb);
        delete abb;
        return nueva_raiz;
    }

}

Para determinar la nueva raiz para reemplazar a la actual y la devuelve.

// Pre: abb no es nullptr
// Post: desconecta la raiz y devuelve la nueva raiz

nodo*desconectar_raiz(nodo *abb){
    nodo *nueva_raiz;
    if(abb->izquierdo == nullptr){
        nueva_raiz = abb->derecho;
    }
    else if(abb->derecho == nullptr){
        nueva_raiz = abb->izquierdo;
    }
    else if(abb->derecho->izquierdo == nullptr){
        nueva_raiz = abb->derecho;
        nueva_raiz->izquierdo = abb->izquierdo;
    }
    else{
        nueva_raiz = quitar_y_devolver_minimo(abb->derecho);
        nueva_raiz->izquierdo = abb->izquierdo;
        nueva_raiz->derecho = abb->derecho;
    }
    return nueva_raiz;
}

Tenemos también quitar_y_devolver_minimo:

nodo* quitar_y_devolver_minimo(nodo* abb){
    while(abb->izquierdo->izquierdo != nullptr){
        abb = abb->izquierdo;
    }
    nodo* minimo = abb->izquierdo;
    abb->izquierdo = minimo->derecho;
    return minimo;
}

## Árbol AVL
Es un ABB Balanceado, eso quiere decir que su altura izquierda - su altura derecha es <= 1
Asegura entonces que la altura total es O(log n)
-> La diferencia de alturas se preserva rebalanceando el arbol al insertar y borrar.
Si hay un desbalanceo, aplicamos una rotación. 
En c++ set y map están implementados sobre árboles balanceados. 

Red-black tree: asegura que desde ningún nodo ningún camino a las hojas es más del doble de largo que otro.

## Heap
El objetivo es encontrar una estructura donde acceder al máximo elemento sea muy eficiente, pero no queremos pagar el costo de mantenerla siempre ordenada del todo.

La idea es almacenarlos de manera conveniente en un arbol binario, en la raiz va el máximo y mantenemos la altura cercana a log n

### Max Heap:
Cumple con que:
- Cada nodo del árbol tiene un elemento mayor o igual al de todos sus descendientes directos o indirectos.
- Es izquierdista: todos los niveles están completos salvo el úlitmo, que se rellena de izquierda a derecha.

Para insertar un elemento:
1. Lo colocamos en la primera hoja
2. Lo vamos subiendo de nivel mientras sea mayor que su padre

Para eliminar un elemento:
1. Intercambiamos la raiz con la última hoja
2. Eliminamos la última hoja
3. Vamos bajando de nivel el elemento que quedó en la raiz mientras sea menor que algún hijo

Como es izquierdista, se puede representar con un vector, se almacenaría cada nivel de arriba hacia abajo y de izquierda a derecha:

12 8 10 3 6 nullptr nullptr

Que se vería:
         12
       /    \ 
      8      10
     / \    /  \
    3   6  null  null 

Notar que:
- La raíz está en v[0].
- Los hijos del nodo v[i] están en v[2i + 1] y v[2i + 2].
- El padre del nodo v[i] está en v[(i - 1)/2].

Para el caso del heap, se representa mejor usando un vector así:

vector<int> _heap;
Donde para todo 1 <= 1 < heap.size(), _heap[i] <= _heap(i-1)/2

int padre(int pos){
    return (pos-1)/2
}
int hijo_izq(int pos){
    return 2*pos+1;
}
int hijo_der(int pos){
    return 2*pos+2;
}

