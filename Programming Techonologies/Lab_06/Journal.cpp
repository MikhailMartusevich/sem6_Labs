#include "Journal.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

Journal::Journal(const std::string& title, double price, const std::string& volume)
	: _title(title), _price(price), _volume(volume)
{

}

Journal::~Journal()
{

}
