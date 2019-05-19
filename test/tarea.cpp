#include "testg.h"
float getarea(float r) {
	float pl;
	pl = p * r * r;
	return pl;
}

TEST_CASE("GETAREA", "[AREA]") {
	REQUIRE(getarea(2.2) == 15.20531f);
	REQUIRE(getarea(6.11) == 117.28226f);
	cout << "Test area is done" << endl;
}

