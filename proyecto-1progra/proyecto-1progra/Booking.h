#include <iostream>

class Booking {
private:
	int idBooking;
	double totalPrice;
	int bookingNumber;
	int movieId;
	int scheduleId;
	int** matrixSeatsPerBooking;
	int quantitiesOfSeats;
	int price;
	int state;
public:
	Booking();
	Booking(double totalPrice, int bookingNumber, int movieid, int scheduleId,int quantitiesOfSeats,int price, int state);
	~Booking();

	//setters
	void setTotalPrice(double);
	void setBookingNumber(int);
	void setState(int);
	void setMovieId(int);
	void setPrice(int);
	void setQuantitiesOfSeats(int);
	void setScheduleId(int);
	void addSeatsToList(int, int, int);
	int getSeatValue(int,int);

	//getters
	double getTotalPrice();
	int getBookingNumber();
	int getMovieId();
	int getScheduleId();
	int getQuantitiesOfSeats();
	int getPrice();
	int getState();
};