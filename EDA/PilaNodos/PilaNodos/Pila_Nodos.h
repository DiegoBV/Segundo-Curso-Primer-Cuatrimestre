#pragma once
#include <string>
#include <iostream>
using namespace std;

template <typename T>
class Pila_Nodos
{
private:
	class Nodo {
		T elemento;
		Nodo* siguiente;
		Nodo(T elem, Nodo* sig) : elemento(elem), siguiente(sig) {};
	};

	size_t nElementos; //numero elementos en la pila
	Nodo* cima;   //puntero al primer elemento de la pila
	void libera_Mem();
	void copia(const Pila_Nodos<T> &other);
	Nodo* copia_Nodos(const Nodo* node);
public:
	Pila_Nodos();
	~Pila_Nodos();
	Pila_Nodos(const Pila_Nodos<T> &other);
	Pila_Nodos<T> & operator=(Pila_Nodos<T> cont& other);
	void push(T cont& elem);
	T top();
	void pop();
	bool empty();
	size_t size();
	void representa();
};

template <typename T>
void Pila_Nodos<T>::libera_Mem() {
	Nodo* n = cima;
	while (n != nullptr) {
		Nodo* next = n->siguiente;
		delete n;
		n = next;
	}
	cima = nullptr;
}

template <typename T>
void Pila_Nodos<T>::copia(const Pila_Nodos<T> &other) {
	nElementos = other.nElementos;
	cima = copia_Nodos(other.cima);
}

template <typename T>
typename Pila_Nodos<T>::Nodo* Pila_Nodos<T>::copia_Nodos(const Nodo* node) {
	if (node == nullptr) {
		return nullptr;
	}
	else {
		Nodo* tail = copia_Nodos(node->siguiente);
		Nodo* head = new Nodo(node->elemento, tail);
		return head;
	}
}

template <typename T>
Pila_Nodos<T>::Pila_Nodos(const Pila_Nodos<T> &other) {
	copia(other);
}

template <typename T>
Pila_Nodos<T> & Pila_Nodos<T>:: operator=(Pila_Nodos<T> cont& other) {
	if (this != other) {
		libera_Mem();
		copia(other);
	}
	return *this;
}
template <typename T>
Pila_Nodos<T>::Pila_Nodos() : nElementos(0), cima(nullptr) {}

template <typename T>
Pila_Nodos<T>::~Pila_Nodos()
{
	libera_Mem();
}

template <typename T>
void Pila_Nodos<T>::push(T conts& elem) {
	Node* node = new Node(elem, cima);
	cima = node;
	nElementos++;
}

template <typename T>
T Pila_Nodos<T>::top() {
	if (nElementos == 0) {
		cout << "Error, pila vacía";
	}
	else {
		return cima->elemento;
	}
}

template <typename T>
void Pila_Nodos<T>::pop() {
	if (nElementos == 0) {
		cout << "Error, pila vacía";
	}
	else {
		nElementos--;
		Nodo* old_First = cima;
		cima = cima->siguiente;
		delete old_First;
	}
}

template <typename T>
bool Pila_Nodos<T>::empty() {
	return (size() == 0);
}

template <typename T>
size_t Pila_Nodos<T>::size() {
	return nElementos;
}

template <typename T>
void Pila_Nodos<T>::representa() {
	Nodo* n = cima;

	while (n != nullptr) {
		cout << n->elemento;
		n = n->siguiente;
	}
	n = nullptr;
}

