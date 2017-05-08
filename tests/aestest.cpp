#include <fstream>
#include <iostream>
#include <stdio.h>
#include <string>
#include <cstring>
#include <openssl/aes.h>

typedef unsigned char buffer;

char* encrypt_aes(const unsigned char oneKey[])
{
    buffer in[1024];
    buffer encryptedbuffer[1024];
    std::string straa = "hellonearth\n";

    AES_KEY key;

    AES_set_encrypt_key(oneKey,256,&key);

    memcpy((char*)in,straa.c_str(),13);

    AES_encrypt(in,encryptedbuffer,&key);
    return (char*)encryptedbuffer;
}

char* decrypt_aes(buffer enc[1024], const unsigned char oneKey[])
{
    buffer temp[1024];

    AES_KEY key;

    AES_set_decrypt_key(oneKey,256,&key);

    AES_decrypt(enc,temp,&key);
    return temp;
}

int main()
{
    //buffer inbuffer[1024];
    //buffer encryptedbuffer[1024];
    buffer outbuffer[1024];

    const unsigned char oneKey[] = {};

    AES_KEY key;

    AES_set_decrypt_key(oneKey,256,&key);

    AES_decrypt(encrypt_aes("Data\n"),outbuffer,&key);

    /*if ((char*)outbuffer == straa)
    {
        std::cout << "AES-256 test ok" << std::endl;
    }*/

    getchar();

}
