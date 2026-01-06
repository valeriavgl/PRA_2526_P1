#ifndef SQUARE_H
#define SQUARE_H

#include <iostream>
#include <stdexcept>
#include "Rectangle.h"


class Square : public Rectangle {

	private:
		static bool check (Point2D* Vertices);

	public:
		Square();
		Square(const std::string &color, Point2D* vertices);

		void set_vertices(Point2D* vertices) override;
        	void print() override;

       		friend std::ostream& operator<<(std::ostream &out, const Square &square);
};

#endif
