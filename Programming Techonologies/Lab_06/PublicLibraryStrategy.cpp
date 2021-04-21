#include "PublicLibraryStrategy.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

PublicLibraryStrategy::PublicLibraryStrategy(int nomianlHoldPeriod)
	: _nomianlHoldPeriod(nomianlHoldPeriod)
{}

PublicLibraryStrategy::~PublicLibraryStrategy() {}

int PublicLibraryStrategy::HoldPeriod(const Reader& reader) const {
	// Не зависимо от категории читателя, период для всех одинаковый
	return _nomianlHoldPeriod;
}
