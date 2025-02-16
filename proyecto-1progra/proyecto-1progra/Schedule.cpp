#include "Schedule.h"
#include <iostream>

Schedule::Schedule() {
	date = "";
	startHour = 0;
	endHour = 0;
}

Schedule::Schedule(std::string date, int startHour, int endHour) {
	this->date = date;
	this->startHour = startHour;
	this->endHour = endHour;
}

Schedule::~Schedule() {

}

//gets metodos
std::string Schedule::getDate() {
	return date;
}
int Schedule::getStartHour() {
	return startHour;
}

int Schedule::getEndHour() {
	return endHour;
}

//sets metodos
void Schedule::setDate(std::string date) {
	this->date = date;
}

void Schedule::setStartHour(int startHour) {
	this->startHour = startHour;
}

void Schedule::setEndHour(int endHour) {
	this->endHour = endHour;
}

//funcion de crear el mapa de las butacas
void Schedule::createSeatsMap(int rowsQuantities, int seatsPerRows) {
	seatsMap = new int* [rowsQuantities];
	for (int i = 0; i < rowsQuantities; i++)
	{
		seatsMap[i] = new int[seatsPerRows];
	}
	for (int i = 0; i < rowsQuantities; i++)
	{
		for (int e = 0; e < seatsPerRows; e++)
		{
			seatsMap[i][e] = 0;
		}
	}
}

//funcion de escoger el estado del asiento
void Schedule::changeSeatStatus(int row, int column,int value) {
	seatsMap[row][column] = value;
}

int Schedule::getSeatValue(int rows, int columns) {
	return seatsMap[rows][columns];
}

//mostrar asientos
void Schedule::showSeats(int rows, int columns) {
	std::cout << "\033[36m";
	std::cout << " ---   BUTACAS  ---" << std::endl;
	std::cout << "\033[0m";
	for (int i = 0; i < rows; i++) {
		for (int e = 0; e < columns; e++) {
			std::cout << "[ ";
			if (seatsMap[i][e] == 0) {
				std::cout << "\033[36m";
				std::cout << "D";
			}
			if (seatsMap[i][e] == 1) {
				std::cout << "\033[35m";
				std::cout << "R";
			}
			if (seatsMap[i][e] == 2) {
				std::cout << "\033[31m";
				std::cout << "V";
			}
			std::cout << "\033[0m";
			std::cout << " ]";
		}
		std::cout << std::endl;
	}
	std::cout << "\033[36m";
	std::cout << "Disponible"<<std::endl;
	std::cout << "\033[35m";
	std::cout << "Reservado" << std::endl;
	std::cout << "\033[31m";
	std::cout << "Vendido" << std::endl;
	std::cout << "\033[0m";
}
