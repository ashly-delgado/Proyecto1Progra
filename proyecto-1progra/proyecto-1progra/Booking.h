#include <iostream>

class Booking {
private:
	double totalPrice;
	int bookingNumber;
	int movieId;
	int scheduleId;
public:
	Booking();
	Booking(double totalPrice, int bookingNumber, int movieid, int scheduleId);
	~Booking();

	//setters
	void setTotalPrice(double);
	void setBookingNumber(int);
	void setMovieId(int);
	void setScheduleId(int);

	//getters
	double getTotalPrice();
	int getBookingNumber();
	int getMovieId();
	int getScheduleId();
};