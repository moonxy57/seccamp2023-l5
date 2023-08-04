#include <cstdio>
#include <cstring>
#include <iostream>
#include "Enclave_u.h"
#include <sgx_urts.h>
#include "error_print.hpp"
#include <openssl/bio.h>

sgx_enclave_id_t global_eid = 0;


/* display bytes of the secret buffer for debug */
void ocall_debug_print(uint8_t *buf, size_t sz)
{
	//デバック標準出力用OCALL関数を定義
}


/* Enclave initialization function */
int initialize_enclave()
{
    //0埋めしたダミーの起動トークンでEnclaveを作成する
}


int main()
{
	/* 以下の処理を実装する：
	 * - Enclaveの作成（初期化）
	 * - ECALL関数の呼び出し
	 * - ECALL結果のSGXステータス及び戻り値の出力
	 */
}
