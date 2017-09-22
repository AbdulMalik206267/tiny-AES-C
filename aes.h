#ifndef _AES_H_
#define _AES_H_

#include <stdint.h>

// #define the macros below to 1/0 to enable/disable the mode of operation
//
// CBC enables AES encryption in CBC-mode of operation.
// ECB enables the basic ECB 16-byte block algorithm. Both can be enabled simultaneously.
// CFB enables AES encryption in CFB-mode of operation

// AESNI enables hardware accelerated operations in supported platforms - see
// https://software.intel.com/en-us/articles/intel-advanced-encryption-standard-instructions-aes-ni

// The #ifndef-guard allows it to be configured before #include'ing or at compile time.

#define AESNI

#ifdef AESNI
#include "AES-NI/include/iaesni.h"
#include "AES-NI/include/iaes_asm_interface.h"
#endif

#ifndef CBC
  #define CBC 1
#endif

#ifndef ECB
  #define ECB 1
#endif

#ifndef CFB
  #define CFB 1
#endif

#define AES128

#if defined(ECB) && ECB

void AES_ECB_encrypt( const uint8_t* input, const uint8_t* key, uint8_t *output, const uint32_t length);
void AES_ECB_decrypt(const uint8_t* input, const uint8_t* key, uint8_t *output, const uint32_t length);

#endif // #if defined(ECB) && ECB


#if defined(CBC) && CBC

void AES_CBC_encrypt_buffer(uint8_t* output, uint8_t* input, uint32_t length, const uint8_t* key, const uint8_t* iv);
void AES_CBC_decrypt_buffer(uint8_t* output, uint8_t* input, uint32_t length, const uint8_t* key, const uint8_t* iv);

#endif // #if defined(CBC) && CBC

#if defined(CFB) && CFB

void AES_CFB_encrypt_buffer(uint8_t* output, uint8_t* input, uint32_t length, const uint8_t* key, const uint8_t* iv);
void AES_CFB_decrypt_buffer(uint8_t* output, uint8_t* input, uint32_t length, const uint8_t* key, const uint8_t* iv);

#endif // #if defined(CFB) && CFB


#endif //_AES_H_
