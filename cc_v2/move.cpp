#include "move.h"

mov::mov()
{
	from = 0;
	to = 0;
	score = 0;
}
mov::mov(unsigned from, unsigned to) {
	this->from = from;
	this->to = to;
	score = 0;
}
mov::mov(const mov& other) {
	from = other.from;
	to = other.to;
	score = other.score;

}
mov& mov::operator=(const mov& other)
{
	if (this == &other) return *this;
	from = other.from;
	to = other.to;
	score = other.score;
	return *this;


}
std::string mov::show()
{
	return std::string("from: "+std::to_string(from)+" to: "+std::to_string(to)+" score: "+std::to_string(score));
}
bool operator<(const mov& this_one, const mov& other) {
	return this_one.score < other.score;
}
bool operator>(const mov& this_one, const mov& other) {
	return this_one.score > other.score;
}
bool operator<=(const mov& this_one, const mov& other) {
	return this_one.score <= other.score;
}
bool operator>=(const mov& this_one, const mov& other) {
	return this_one.score >= other.score;
}
bool operator==(const mov& this_one, const mov& other) {
	return this_one.score == other.score;
}

void mov::set_score(double score) { this->score = score; }
