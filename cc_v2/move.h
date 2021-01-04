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
private:
	unsigned short from;
	unsigned short to;
	double		score;

};


//#endif // !MOVE
