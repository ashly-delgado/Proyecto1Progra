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

public:
	Booking();
	Booking(double totalPrice, int bookingNumber, int movieid, int scheduleId,int quantitiesOfSeats,int price, int idBooking);
	~Booking();

	//setters
	void setTotalPrice(double);
	void setBookingNumber(int);
	void setMovieId(int);
	void setPrice(int);
	void setQuantitiesOfSeats(int);
	void setScheduleId(int);
	void setIdBooking(int);

	//getters
	double getTotalPrice();
	int getBookingNumber();
	int getMovieId();
	int getScheduleId();
	int getQuantitiesOfSeats();
	int getPrice();
	int getIdBooking();
};