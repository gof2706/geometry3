#include "teastg.h"
float getperim(float r) {
	float pr;
	pr = 2 * p * r;
	return pr;
}

TEST_CASE("GETPERIM", "[PERIM]") {
	REQUIRE(getperim(3.3) == 20.7345123291015625f);
	REQUIRE(getperim(6.11) == 38.390262603759765625f);
	REQUIRE(getperim(4.21) == 26.4522113800048828125f);
	REQUIRE(getperim(8.98) == 56.423004150390625f);
	REQUIRE(getperim(7.01) == 44.045131683349609375f);
	REQUIRE(getperim(10.10) == 63.460174560546875f);
	cout << "Test perim is done" << endl;
}
