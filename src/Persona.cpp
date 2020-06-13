#include "Persona.h"
#include <string>
using namespace std;
Persona::Persona()
{

}
Persona::Persona(int numbers){

	this->numbers = numbers;

}

string Persona::getNombre(){
	return nombre;
}

string Persona::getId(){
	return Id;
}

string Persona::getDescripcion(){
	return descripcion;
}
string Persona::getTodo(){
	return getId() + "--" + getDescripcion() + "--" + getNombre() + " ";
}
void Persona::setDescripcion(string descripcion){
	this->descripcion = descripcion;
}
void Persona::setNombre(string nombre){
	this->nombre = nombre;
}

void Persona::setId(string Id){
	this->Id = Id;
}

int Persona::getNumbers(){
	return numbers;
}

void Persona::setNumber(int numbers){
	this->numbers = numbers;
}

Persona::~Persona()
{

}
