#include "piece.h"


piece& piece::operator=(const piece& other)
{
	if (this == &other) return *this;    // TODO: tu wstawi� instrukcj� return
	color = other.color;
	return *this;

}
