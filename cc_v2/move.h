#pragma once
#include <string>
//#ifndef MOVE

//#define MOVE
class mov //describes move in chess
{
public:
	mov();
	mov(unsigned, unsigned);
	void set_score(double);

	mov(const mov&);
	mov& operator=(const mov&);
	friend bool operator<(const mov&, const mov&);
	friend bool operator>(const mov&, const mov&);
	friend bool operator<=(const mov&, const mov&);
	friend bool operator>=(const mov&, const mov&);
	friend bool operator==(const mov&, const mov&);
	std::string show();
	unsigned short get_to() { return this->to; };
	unsigned short get_from() { return this->from; };
	double get_score() { return this->score; };


private:
	unsigned short from;
	unsigned short to;
	double		score;

};


//#endif // !MOVE
