#include <stdio.h>

const unsigned short usC1 = 52845, usC2 = 11719;

void Encrypt(unsigned char *pucPlaintext, unsigned long ulLength, unsigned short usKey)
{
    for(unsigned long i = 0; i < ulLength; ++i)
    {
        pucPlaintext[i] ^= usKey >> 8;

        usKey = (pucPlaintext[i] + usKey) * usC1 + usC2;
    }
}

void Decrypt(unsigned char *pucCiphertext, unsigned long ulLength, unsigned short usKey)
{
    for(unsigned long i = 0; i < ulLength; ++i)
    {
    	unsigned char ucCiphertext = pucCiphertext[i];

        pucCiphertext[i] = ucCiphertext ^ usKey >> 8;

        usKey = (ucCiphertext + usKey) * usC1 + usC2;
    }
}

int main(void)
{
/*    for(unsigned long n = 1; n < 100; ++n)
    {
        for(unsigned long f = 0; f < 100; ++f)
		{
    	    for(unsigned long y = 0; y < 49; ++y)
			{
    		    if(98 * f - 199 * y == n)
				{
    			    printf("n=%lu %lu.%lu\n", n, y, f);

    			    goto EXIT;
			    }
		    }
	    }

	    printf("n=%lu No Solution\n", n);
EXIT:;
}*/

    unsigned char aucPlaintextOrCiphertext[]{'a', '2', 'b', '3', 'c', '5', 'd', '7'};

    Encrypt(aucPlaintextOrCiphertext, 8, 0x2357);

    for(unsigned long j = 0; j < 8; ++j) printf("%c", aucPlaintextOrCiphertext[j]);

    putchar(10);

    Decrypt(aucPlaintextOrCiphertext, 8, 0x2357);

    for(unsigned long j = 0; j < 8; ++j) printf("%c", aucPlaintextOrCiphertext[j]);

    return 0;
}
