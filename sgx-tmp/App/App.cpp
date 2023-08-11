#include <cstdio>
#include <cstring>
#include <iostream>
#include "Enclave_u.h"
#include <sgx_urts.h>
#include "error_print.hpp"
#include <openssl/bio.h>

sgx_enclave_id_t eid = 0;

void ocall_print(const char* str)
 {
     std::cout << "Output from OCALL: " << std::endl;
     std::cout << str << std::endl;
     return;
 }

/* Enclave initialization function */
int initialize_enclave()
{
    //0埋めしたダミーの起動トークンでEnclaveを作成する
	sgx_launch_token_t token = {0}; 

	int update = 0;

	std::string enclave_image_name = "enclave.signed.so";

	sgx_status_t status;

	status = sgx_create_enclave(enclave_image_name.c_str(), SGX_DEBUG_FLAG, &token, &update, &eid, NULL);

	if (status != SGX_SUCCESS) {
		printf("App: error %#x, failed to create enclave.\n", status);
		return -1;
	}

	return 0;
}

int main(){
	if(initialize_enclave() < 0)
	{
		std::cerr << "App: file error" << std::endl;
	}


	int retval = 0;
	const char *message = "MESSAGE";
	size_t message_len = strlen(message);
	sgx_status_t status = ecall_tmp(eid, &retval, message, message_len);
	
	print_sgx_status(status);

	std::cout << retval << std::endl;

	sgx_destroy_enclave(eid);
	return 0;
}

	/* 以下の処理を実装する：
	 * - Enclaveの作成（初期化）
	 * - ECALL関数の呼び出し
	 * - ECALL結果のSGXステータス及び戻り値の出力
	 */
	

