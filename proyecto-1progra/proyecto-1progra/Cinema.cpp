#include "Cinema.h"
#include <iostream>
#include "Movie.h"
#include "Room.h"
#include <string>

//un vector estatico de 10 espacios, que son las peliculas
static int  NUM_MOVIESLIST = 10;
int const numberMaxRooms = 5;
Movie* moviesList = new Movie[NUM_MOVIESLIST];
Booking* bookinglist = new Booking[0];
Sale* saleList = new Sale[0];
int sales = 0;
int numberBooking = 0;
int matriz[11][15] = {
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,1,1,1,1,0,0,0,0,0,0,0,0,0},
	{0,1,1,1,1,1,0,0,0,0,0,0,0,0,0},
	{0,1,1,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,1,1,0,0,0,0,0,1,0,0,0,1,0,0},
	{0,1,1,0,0,0,0,1,1,1,0,1,1,1,0},
	{0,1,1,0,0,0,0,0,1,0,0,0,1,0,0},
	{0,1,1,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,1,1,1,1,1,0,0,0,0,0,0,0,0,0},
	{0,0,1,1,1,1,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
};



Cinema::Cinema() {
	Room room = Room();
	room.setNumber(1);
	room.setRowsQuantities(10);
	room.setSeatsPerRows(10);
	room.setNumberOfSeats(100);
	room.setPrice(3500);
	room.setScheduleCounter(0);

	moviesList[0] = Movie("Moana", 2017, 140, "USA", 6, room);
	moviesList[1] = Movie("Rapidos y furiosos", 2021, 160, "Estados Unidos", 8, room);
	moviesList[2] = Movie("El conjuro", 2017, 150, "Estados Unidos", 7, room);
	moviesList[3] = Movie("El rey leon", 2020, 138, "Estados Unidos", 4, room);
	moviesList[4] = Movie("Frozen", 2021, 145, "Estados Unidos", 5, room);
	moviesList[5] = Movie("Deadpool", 2016, 156, "Canada", 7, room);
	moviesList[6] = Movie("Mufasa", 2024, 160, "Estados Unidos", 8, room);
	moviesList[7] = Movie("Bad Boys 4", 2024, 155, "Estados Unidos", 7, room);
	moviesList[8] = Movie("Escuadron suicida", 2021, 153, "Estados Unidos", 9, room);
	moviesList[9] = Movie("Elementos", 2023, 125, "Estados Unidos", 8, room);

}

//funcion de redimencionar el vector de peliculas
void Cinema::resizeArray(Movie*& array, int& sizeFrom, int newSize) {
	Movie* newArr = new Movie[newSize];
	for (int i = 0; i < sizeFrom && i < newSize; ++i) {
		newArr[i] = array[i];
	}
	delete[] array;
	array = newArr;
}

//funcion para redimencionar las reservas
void Cinema::resizeBookingArray(Booking*& array, int& sizeFrom, int newSize) {
	Booking* newArr = new Booking[newSize];
	for (int i = 0; i < sizeFrom && i < newSize; ++i) {
		newArr[i] = array[i];
	}
	delete[] array;
	array = newArr;
}



//funcion para redimencionar las ventas
void Cinema::resizeSaleArray(Sale*& array, int& sizeFrom, int newSize) {
	Sale* newArr = new Sale[newSize];
	for (int i = 0; i < sizeFrom && i < newSize; ++i) {
		newArr[i] = array[i];
	}
	delete[] array;
	array = newArr;
}

//funcion de agregar mas peliculas al vector,llamando la funcion de redimencionar el vector
void Cinema::addMovieToArray(Movie movie) {
	int newNumber = NUM_MOVIESLIST + 1;
	resizeArray(moviesList, NUM_MOVIESLIST, newNumber);
	moviesList[newNumber - 1] = movie;
	NUM_MOVIESLIST = newNumber;
}

Cinema::~Cinema() {
}

//funcion de mostrar la lista de peliculas
void Cinema::showMoviesList() {
	std::cout << "======================================Peliculas disponibles========================================" << std::endl;
	for (int i = 0; i < NUM_MOVIESLIST; i++) {
		std::cout << "Pelicula " << "numero: " << i << std::endl << "Nombre: " << moviesList[i].getName() << "|" << std::endl <<
			"Anio: " << " " << moviesList[i].getYear() << "|" << std::endl <<
			"Tiempo: " << " " << moviesList[i].getTime() << "|" << std::endl <<
			"Pais: " << " " << moviesList[i].getCountry() << "|" << std::endl <<
			"Resenia: " << " " << moviesList[i].getReview() << "|" << std::endl;
		std::cout << "=====================" << std::endl;

		std::cout << "Informacion de sala: " << std::endl << "Numero de sala: " << "|" << moviesList[i].getRoom().getNumber() << "|" << std::endl <<
			"Numero de asiento: " << "|" << moviesList[i].getRoom().getNumberOfSeats() << "|" << std::endl <<
			"Precio: " << "|" << moviesList[i].getRoom().getPrice() << "|" << std::endl;
		Room room = moviesList[i].getRoom();

		std::cout << "=====================" << std::endl;
		std::cout << "Informacion de horarios: " << std::endl;
		for (int index = 0; index < room.getScheduleCounter(); index++) {
			std::cout << "Fecha de la pelicula: " << "|" << room.getSchedule(index).getDate() << "|" << std::endl <<
				"  Hora de inicio: " << "|" << room.getSchedule(index).getStartHour() << "|" << std::endl <<
				"  Hora de finalizacion: " << "|" << room.getSchedule(index).getEndHour() << "|" << std::endl;
			std::cout << "=====================" << std::endl;
		}
		std::cout << "======================================================================" << std::endl;
	}
}

//funcion de mostrar el menu principal
void Cinema::showMenu() {
	std::cout << "MENU DE NUEVA CINEMA SA:" << std::endl;
	std::cout << "------------------------\n";
	std::cout << "1. Archivo" << std::endl;
	std::cout << "------------------------\n";
	std::cout << "2. Mantenimiento" << std::endl;
	std::cout << "------------------------\n";
	std::cout << "3. Reserva" << std::endl;
	std::cout << "------------------------\n";
	std::cout << "4. Venta" << std::endl;
	std::cout << "------------------------\n";
	std::cout << "5. Salir" << std::endl;
	std::cout << "------------------------\n";
	std::cout << std::endl;
	std::cout << "Porfavor, seleccione una opcion:" << std::endl;
}

//funcion del submenu de mantenimiento
void Cinema::subMenuMantenimiento() {
	std::cout << "MANTENIMIENTO:" << std::endl;
	std::cout << "-------------------\n";
	std::cout << "1. Peliculas:" << std::endl;
	std::cout << "-------------------\n";
	std::cout << "2. Salas:" << std::endl;
	std::cout << "-------------------\n";
	std::cout << "3. Horarios:" << std::endl;
	std::cout << "-------------------\n";
	std::cout << "4. Peliculas Disponibles:" << std::endl;
	std::cout << "-------------------\n";
	std::cout << "Ingrese una opcion:" << std::endl;
}
void Cinema::menuReservar() {
	std::cout << "RESERVA:" << std::endl;
	std::cout << "---------------------------------\n";
	std::cout << "1.Reservar:" << std::endl;
	std::cout << "---------------------------------\n";
	std::cout << "2.Disponibilidad de las butacas:" << std::endl;
	std::cout << "---------------------------------\n";
	std::cout << "3.Lista de reservaciones:" << std::endl;
	std::cout << "---------------------------------\n";
}

void Cinema::listBooking() {
	for (int i = 0; i < numberBooking; i++) {
		std::cout << "----------------------------------------" << std::endl;
		std::cout << "Numero de reserva: " << bookinglist[i].getBookingNumber() << std::endl;
		std::cout << "Identificacion de pelicula: " << bookinglist[i].getMovieId() << std::endl;
		std::cout << "Identificacion de horario: " << bookinglist[i].getScheduleId() << std::endl;
		std::cout << "Cantidad de asientos: " << bookinglist[i].getQuantitiesOfSeats() << std::endl;
		std::cout << "Precio: " << bookinglist[i].getPrice() << std::endl;
		if (bookinglist[i].getState() == 0) {
			std::cout << "Estado de asientos: Pendiente facturar" << std::endl;
		}
		else {
			std::cout << "Estado de asientos: Facturado" << std::endl;
		}
		std::cout << "Total de precio: " << bookinglist[i].getTotalPrice() << std::endl;
		std::cout << "----------------------------------------" << std::endl;
	}
}

//funcion del submenu de reserva
bool Cinema::subMenuReserva() {
	Booking booking;
	int number;
	int maxRow = 0;
	int maxColumn = 0;
	int numberOfSchedule;
	int row;
	int column;
	int countOfSeats;
	int counterSchedule = 0;

	std::cout << "PELICULAS:" << std::endl;
	for (int i = 0; i < NUM_MOVIESLIST; i++) {
		std::cout << i << "| Pelicula:" << " " << moviesList[i].getName() << "|" << std::endl;
	}
	std::cout << std::endl;
	std::cout << "  A cual pelicula desea hacerle una reserva [digite un numero]:" << std::endl;
	number = getInt();
	booking.setMovieId(number);
	std::cout << " Sala en la que se exhibe la pelicula: " << moviesList[number].getRoom().getNumber() << "|" << std::endl;

	if (moviesList[number].getRoom().getScheduleCounter() == 0) {
		std::cout << "La pelicula no cuenta con horarios, Porfavor ingrese a la opcion de \"Mantenimiento\" y cree los horarios" << std::endl;
		return false;
	}
	std::cout << "=========================================" << std::endl;
	std::cout << "Horarios disponibles:" << std::endl;
	for (int i = 0; i < moviesList[number].getRoom().getScheduleCounter(); i++) {
		std::cout << "Numero de horario = " << i << "| " << std::endl << "Pelicula: " << moviesList[number].getName() << "|" << std::endl << "Fecha: " << moviesList[number].getRoom().getSchedule(i).getDate() << "|" << std::endl
			<< "Hora de inicio: " << moviesList[number].getRoom().getSchedule(i).getStartHour() << "|" << std::endl
			<< "hora final: " << moviesList[number].getRoom().getSchedule(i).getEndHour() << "|" << std::endl;
		counterSchedule++;
	}
	std::cout << "=========================================" << std::endl;

	std::cout << " A cual numero de horario desea reserva:" << std::endl;
	numberOfSchedule = getInt();

	while (numberOfSchedule < 0 || numberOfSchedule > counterSchedule) {
		std::cout << "Horario no valido, a cual numero de horario desea reserva:" << std::endl;
		numberOfSchedule = getInt();
	}
	booking.setMovieId(numberOfSchedule);

	moviesList[number].getRoom().getSchedule(numberOfSchedule).showSeats(moviesList[number].getRoom().getRowsQuantities(), moviesList[number].getRoom().getSeatsPerRows());

	std::cout << "\n Ingresar la cantidad de asientos para reservar:\n" << std::endl;
	countOfSeats = getInt();
	booking.setQuantitiesOfSeats(countOfSeats);

	maxRow = moviesList[number].getRoom().getRowsQuantities();
	maxColumn = moviesList[number].getRoom().getSeatsPerRows();
	std::cout << "La siguiente informacion es para las butacas" << std::endl;
	for (int index = 0; index < countOfSeats; index++) {
		std::cout << "Ingresar la fila para los o el asiento: # " << index << std::endl;
		std::cin >> row;
		if (row >= 0 && row < maxRow) {
			std::cout << "Ingresar la columna para los o el asiento:" << std::endl;
			std::cin >> column;
			if (column >= 0 && column < maxColumn) {
				if (moviesList[number].getRoom().getSchedule(numberOfSchedule).getSeatValue(row, column) != 0) {
					std::cout << "Asiento NO disponible" << std::endl;
					index--;
				}
				else {
					booking.addSeatsToList(index, row, column);
					moviesList[number].getRoom().getSchedule(numberOfSchedule).changeSeatStatus(row, column, 1);
				}
			}
			else {
				std::cout << "Columna NO valida." << std::endl;
				index--;
			}

		}
		else {
			std::cout << "Fila NO valida. " << std::endl;
			index--;
		}

	}
	booking.setMovieId(number);
	booking.setScheduleId(numberOfSchedule);
	booking.setPrice(moviesList[number].getRoom().getPrice());
	booking.setTotalPrice(moviesList[number].getRoom().getPrice() * countOfSeats);
	booking.setBookingNumber(numberBooking);
	resizeBookingArray(bookinglist, numberBooking, (numberBooking + 1));
	bookinglist[numberBooking] = booking;
	numberBooking++;
	return true;

}
void Cinema::listSeats() {
	int number;
	int numberOfSchedule;
	int count = 0;
	std::cout << "PELICULAS:" << std::endl;
	for (int i = 0; i < NUM_MOVIESLIST; i++) {
		std::cout << i << "| Pelicula:" << " " << moviesList[i].getName() << "|" << std::endl;
	}
	std::cout << std::endl;
	std::cout << " Seleccionar una pelicula [digite un numero]:" << std::endl;
	number = getInt();
	std::cout << " Sala en la que se exhibe la pelicula: " << moviesList[number].getRoom().getNumber() << "|" << std::endl;

	std::cout << "=========================================" << std::endl;
	std::cout << "Horarios disponibles:" << std::endl;
	for (int i = 0; i < moviesList[number].getRoom().getScheduleCounter(); i++) {
		count++;
		std::cout << "Numero de horario = " << i << "| " << std::endl << "Pelicula: " << moviesList[number].getName() << "|" << std::endl << "Fecha: " << moviesList[number].getRoom().getSchedule(i).getDate() << "|" << std::endl
			<< "Hora de inicio: " << moviesList[number].getRoom().getSchedule(i).getStartHour() << "|" << std::endl
			<< "hora final: " << moviesList[number].getRoom().getSchedule(i).getEndHour() << "|" << std::endl;
	}
	std::cout << "=========================================" << std::endl;
	if (count > 0) {
		std::cout << " A cual numero de horario desea ver la disponibilidad de asientos:" << std::endl;
		numberOfSchedule = getInt();

		moviesList[number].getRoom().getSchedule(numberOfSchedule).showSeats(moviesList[number].getRoom().getRowsQuantities(),
			moviesList[number].getRoom().getSeatsPerRows());
	}
	else {
		std::cout << "No hay horarios disponibles en dicha pelicula, porfavor ir a la opcion de 'MANTENIMIENTO' y crear horarios!!!" << std::endl;
	}
}
void Cinema::fillSale() {
	int idBooking;
	listBooking();
	std::string cardNumber;
	std::string customer;
	Sale sale;
	if (numberBooking > 0) {
		std::cout << "-----------------------------------------" << std::endl;
		std::cout << "Cual reserva desea facturar" << std::endl;
		std::cin >> idBooking;
		if (idBooking >= 0 || idBooking < numberBooking) {
			if (bookinglist[idBooking].getState() == 0) {

				sale.setIdBooking(idBooking);
				sale.setTotal(bookinglist[idBooking].getTotalPrice());
				std::cout << "Porfavor ingresar el Numero de tarjeta: " << std::endl;
				std::cin >> cardNumber;
				sale.setCardNumber(cardNumber);
				std::cout << "Porfavor ingresar la identificacion del cliente: " << std::endl;
				std::cin >> customer;
				sale.setIdCustomer(customer);
				for (int i = 0; i < bookinglist[idBooking].getQuantitiesOfSeats(); i++)
				{
					moviesList[bookinglist[idBooking].getMovieId()].getRoom().getSchedule(bookinglist[idBooking].getScheduleId()).changeSeatStatus(bookinglist[idBooking].getSeatValue(i, 0), bookinglist[idBooking].getSeatValue(i, 1), 2);
				}
				sale.setIdSale(sales);

				resizeSaleArray(saleList, sales, (sales + 1));
				saleList[sales] = sale;
				bookinglist[idBooking].setState(1);
				sales++;
				std::cout << "La venta de ticketes o ticket se realizo correctamente!! " << std::endl;
			}
			else {
				std::cout << "Reserva no disponible, ya fue facturada" << std::endl;
			}
		}
		else {
			std::cout << "Codigo de reserva no valido" << std::endl;
		}
	}
	else {
		std::cout << "No hay Reservas" << std::endl;
	}
}
//funcion del submenu de venta
void Cinema::subMenuVenta() {
	std::cout << "-------------------" << std::endl;
	std::cout << "1.Venta de ticketes" << std::endl;
	std::cout << "-------------------" << std::endl;
	std::cout << "2.Lista de ventas" << std::endl;
	std::cout << "-------------------" << std::endl;

}
void Cinema::listSale() {
	for (int i = 0; i < sales; i++) {
		std::cout << "--------------------------------" << std::endl;
		std::cout << "Identificacion del cliente: " << saleList[i].getIdCustomer() << std::endl;
		std::cout << "Tarjeta del cliente: " << saleList[i].getCardNumber() << std::endl;
		std::cout << "Identificacion de la reserva: " << saleList[i].getIdBooking() << std::endl;
		std::cout << "Total: " << saleList[i].getTotal() << std::endl;
		std::cout << "Identificacion de venta: " << saleList[i].getIdSale() << std::endl;
	}
}

//funcion de agregar pelicula
Movie Cinema::addMovie() {
	Room room = Room();
	Movie movie;
	int yearTheMovie = 0;
	int timeTheMovie = 0;
	int reviewTheMovie = 0;
	std::string nameTheMovie;
	std::string countryTheMovie;

	std::cout << "ingresar el nombre de la pelicula que desea agregar:" << std::endl;
	nameTheMovie = readString();
	movie.setName(nameTheMovie);

	std::cout << "ingresar el anio de la pelicula:" << std::endl;
	yearTheMovie = getInt();
	movie.setYear(yearTheMovie);

	std::cout << "ingresar el tiempo (minutos) de la pelicula:" << std::endl;
	timeTheMovie = getInt();
	movie.setTime(timeTheMovie);

	std::cout << "ingresar el pais de la pelicula:" << std::endl;
	countryTheMovie = readString();
	movie.setCountry(countryTheMovie);

	movie.setRoom(room);
	std::cout << "Se a guardado la pelicula correctamente!!" << std::endl;
	std::cout << std::endl;
	return movie;

}

//funcion del submenu de archivos
void Cinema::subShowFilesMenu() {
	std::cout << "1. Acerca de " << std::endl;
	std::cout << "2. Salir " << std::endl;

}

//funcion de acerca de: creador del cinema
void Cinema::about() {
	std::cout << "==========================================\n";
	std::cout << "        BIENVENIDO A NUEVA CINEMA        " << std::endl;
	std::cout << "==========================================" << std::endl;
	std::cout << "Creadora: Ashly Lizeth Delgado Morales" << std::endl;
	std::cout << std::endl;
	std::cout << "numero de identificacion: 604970068" << std::endl;
	std::cout << std::endl;
	std::cout << "      ES UN GUSTO ATENDERLOS" << std::endl;
	std::cout << "==========================================\n";
	for (int i = 0; i < 11; i++)
	{
		for (int e = 0; e < 15; e++)
		{
			if (matriz[i][e] == 0) {
				std::cout << "\[\033[0;37m\]";
				std::cout << (unsigned char)178;
			}
			else {
				std::cout << "\[\033[0;31m\]";
				std::cout << (unsigned char)178;
			}
		}
		std::cout << std::endl;
	}
	std::cout << "==========================================\n";
	std::cout << "\033[0m";
}
//funcion de agregar horarios
void Cinema::subAddSchedule() {
	Schedule schedule;
	int startHour = 0;
	int endHour = 0;
	std::string date;
	int number = 0;

	for (int i = 0; i < NUM_MOVIESLIST; i++) {
		std::cout << i << "| Pelicula:" << " " << moviesList[i].getName() << "|" << std::endl;
	}

	std::cout << "A cual pelicula desea ingresarle un horario [digite un numero]: " << std::endl;
	number = getInt();

	std::cout << "ingrese la fecha de la pelicula:" << std::endl;
	date = readString();
	schedule.setDate(date);

	std::cout << "ingresar la hora de inicio de la pelicula:" << std::endl;
	startHour = getInt();
	schedule.setStartHour(startHour);

	std::cout << "ingresar la hora de finalizacion de la pelicula:" << std::endl;
	endHour = getInt();
	schedule.setEndHour(endHour);

	if ((startHour >= 0 && startHour <= 24) && (endHour >= 0 && endHour <= 24)) {
		Room room = moviesList[number].getRoom();
		schedule.createSeatsMap(room.getRowsQuantities(), room.getSeatsPerRows());
		room.setSchedule(schedule);
		moviesList[number].setRoom(room);

		std::cout << "El horario de ha guardado con exito!!" << std::endl;

	}
	else {
		std::cout << "Error en las horas debe de ser entre (0 y 24) intentalo de nuevo." << std::endl;
	}
}

//funcion de agregar sala
void Cinema::subAddRoom() {
	Room room;
	int number = 0;
	int numberMovie = 0;
	int numberOfSeats = 0;
	double price = 0;
	int rowsQuantities = 0;
	int seatsPerRows = 0;

	for (int i = 0; i < NUM_MOVIESLIST; i++) {
		std::cout << i << "| Pelicula:" << " " << moviesList[i].getName() << "|" << std::endl;
	}
	std::cout << "A cual pelicula desea ingresarle una sala:" << std::endl;
	numberMovie = getInt();

	std::cout << "Numero de sala:" << std::endl;
	number = getInt();
	while (number <= 0 || number > 5) {
		std::cout << "Error esta sala no esta disponible, ingrese una sala entre (1 y 5) " << std::endl;
		number = getInt();
	}
	room.setNumber(number);

	std::cout << "La siguiente informacion solicitada es para poner elaborar las butacas" << std::endl;
	std::cout << "Digite la cantidad de filas:" << std::endl;
	rowsQuantities = getInt();
	room.setRowsQuantities(rowsQuantities);

	std::cout << "Digite la cantidad de asientos por columna: " << std::endl;
	seatsPerRows = getInt();
	room.setSeatsPerRows(seatsPerRows);

	room.setNumberOfSeats(rowsQuantities * seatsPerRows);

	std::cout << "Precio:" << std::endl;
	price = getDouble();
	room.setPrice(price);
	moviesList[numberMovie].setRoom(room);

	std::cout << "La sala se guardo con exito!!" << std::endl;

}

//funcion para leer una cadena de texto
std::string Cinema::readString() {
	std::string read;
	std::getline(std::cin, read);
	return read;
}

//funcion para pasar a enteros
int Cinema::getInt() {
	int number;
	bool notNumber = true;
	while (notNumber) {
		std::cin >> number;
		if (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Favor Digite un Entero." << std::endl;
			notNumber = true;
		}
		else {
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			notNumber = false;
		}
	}
	return number;
}

//funcion para pasar a decimal
double Cinema::getDouble() {
	double number;
	bool notNumber = true;
	while (notNumber) {
		std::cin >> number;
		if (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Favor digitar un numero." << std::endl;
			notNumber = true;
		}
		else {
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			notNumber = false;
		}
	}
	return number;
}
