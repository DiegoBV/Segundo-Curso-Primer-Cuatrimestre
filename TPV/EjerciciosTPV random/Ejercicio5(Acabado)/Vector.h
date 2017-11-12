/*
 * Clase Vector simplificada para Tema 2 de TPV. UCM.
 *
 *      Author: Miguel Gómez-Zamalloa Gil
 */

#ifndef VECTOR_H_ // Para evitar inclusiones múltiples. Lo suelen poner los IDEs automáticamente
#define VECTOR_H_ // Todo el código debe ir entre este punto y el #endif (ver abajo)

typedef unsigned int uint; // Depende del entorno puede que uint no se reconozca. Así nos aseguramos.

const uint DEFAULT_CAPACITY = 5; // Capacidad inicial por defecto

template <class T>
class Vector {
private:
	uint capacity;  // Capacidad actual del array dinámico
	uint count = 0; // Contador del número de elementos
	T* elems;       // Array dinámico de elementos de tipo T

public:
	Vector() : capacity(DEFAULT_CAPACITY), elems(new T[capacity]) {}
	~Vector() {delete[] elems; count = 0; elems = nullptr;}
	uint size() const {return count;}
	const T& operator[](int i) const {return elems[i];}
	T& operator[](int i){return elems[i];}
	bool empty() const {return count == 0;}
	void push_back(const T& e); // Pone nuevo elemento al final
	void pop_back(); // Quita último elemento
	bool insert(const T& e, uint i); // Inserta e en posición iésima (desplazando para abrir hueco)
	bool erase(uint i); // Borra el elemento de la pos. iésima (desplazando para cerrar hueco)

private:
	void reallocate();
	void shiftRightFrom(uint i);
	void shiftLeftFrom(uint i);
};

// En las plantillas el código de los métodos va también en el .h

template<class T>
void Vector<T>::push_back(const T& e){
	if (count == capacity) reallocate();
	elems[count] = e;
	++count;
}

template<class T>
void Vector<T>::pop_back(){
	if (count > 0) --count;
}

template<class T>
bool Vector<T>::insert(const T& e, uint i){
	if (i > count) return false;
	else {
		if (count == capacity) reallocate();
		shiftRightFrom(i);
		elems[i] = e;
		++count;
		return true;
	}
}

template<class T>
bool Vector<T>::erase(uint i){
	if (i >= count) return false;
	else {
		shiftLeftFrom(i);
		--count;
		return true;
	}
}


// Private methods

template<class T>
void Vector<T>::shiftRightFrom(uint i){
	for (uint j = count; j > i; j--)
		elems[j] = elems[j-1];
}

template<class T>
void Vector<T>::shiftLeftFrom(uint i){
	for (; i < count-1; i++)
		elems[i] = elems[i+1];
}

template<class T>
void Vector<T>::reallocate(){
	capacity = capacity*2;
	T* newElems = new T[capacity];
	for (uint i = 0; i < size(); i++)
		newElems[i] = elems[i];
	delete[] elems;
	elems = newElems;
}


#endif /* VECTOR_H_ */
