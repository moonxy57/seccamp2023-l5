#include "Enclave_t.h"
#include <sgx_trts.h>

int ecall_tmp(const char *message,size_t message_len)
{
 ocall_print(message);
 return 5;
}
