#include <stdint.h>


void remove_chars(char *str, const char *remove) {
	if (!str || !*str || !remove || !*remove) return;
	uint64_t bits[4] = {0, 0, 0, 0};

	const unsigned char *r = (const unsigned char *)remove;
	while (*r) {
		unsigned c = *r++;
		bits[c >> 6] |= (uint64_t)1 << (c & 63);
	}
	unsigned char *read = (unsigned char *)str;
	unsigned char *write = (unsigned char *)str;
	while (*read) {
		unsigned c = *read++;
		if (!(bits[c >> 6] & ((uint64_t)1 << (c & 63)))) {
			*write++ = (char)c;
		}
	}
	*write = '\0';

}
