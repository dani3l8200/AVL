#ifndef PERSONA_H
#define PERSONA_H

#include <string>
using namespace std;
class Persona
{
	public:
		Persona();
		Persona(int);
		string getNombre();
		int getNumbers();
		void setNumber(int);
		string getId();
		string getDescripcion();
		void setNombre(string);
		void setId(string);
		void setDescripcion(string);
		string getTodo();
		~Persona();


	private:
		string nombre;
		string descripcion;
		string Id;
		int numbers;
};

#endif // PERSONA_H
