#include <fstream>
#include <iostream>
#include <stdio.h>
#include <string>
#include <cstring>
#include <openssl/aes.h>

int main()
{
    unsigned char inbuffer[1024];
    unsigned char encryptedbuffer[1024];
    unsigned char outbuffer[1024];

    unsigned char oneKey[] = "hellonearth";
    AES_KEY key;

    AES_set_encrypt_key(oneKey,256,&key);

    std::string straa = "hello world\n";
    memcpy((char*)inbuffer,straa.c_str(),13);

    AES_encrypt(inbuffer,encryptedbuffer,&key);

    AES_set_decrypt_key(oneKey,256,&key);

    AES_decrypt(encryptedbuffer,outbuffer,&key);

    if ((char*)outbuffer == straa)
    {
        std::cout << "AES-256 test ok" << std::endl;
    }

    getchar();

}
