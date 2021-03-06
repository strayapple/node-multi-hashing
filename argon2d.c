#include "argon2d.h"
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <stdio.h>

#include "argon2d/argon2.h"
#include "crypto/blake2.h"

void Argon2dHash(const char* in, char* out) {
	
	size_t INPUT_BYTES = 80;  				// Lenth of a block header in bytes. Input Length = Salt Length (salt = input)
	size_t OUTPUT_BYTES = 32; 				// Length of output needed for a 256-bit hash
	unsigned int DEFAULT_ARGON2_FLAG = 2; 	// Same as ARGON2_DEFAULT_FLAGS

	argon2_context context;
	context.out = (uint8_t *)out;
	context.outlen = (uint32_t)OUTPUT_BYTES;
	context.pwd = (uint8_t *)in;
	context.pwdlen = (uint32_t)INPUT_BYTES;
	context.salt = (uint8_t *)in; //salt = input
	context.saltlen = (uint32_t)INPUT_BYTES;
	context.secret = NULL;
	context.secretlen = 0;
	context.ad = NULL;
	context.adlen = 0;
	context.allocate_cbk = NULL;
	context.free_cbk = NULL;
	context.flags = DEFAULT_ARGON2_FLAG;
			
	context.m_cost = 250; // Memory in KiB (~256KB)
	context.lanes = 4;    // Degree of Parallelism
	context.threads = 1;  // Threads
	context.t_cost = 1;   // Iterations
	
    argon2_ctx(&context, Argon2_d);
}
