#include "piece.h"


piece& piece::operator=(const piece& other)
{
	if (this == &other) return *this;    // TODO: tu wstawiæ instrukcjê return
	color = other.color;
	return *this;

}
