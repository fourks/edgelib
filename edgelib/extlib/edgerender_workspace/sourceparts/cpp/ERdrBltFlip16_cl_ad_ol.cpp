#include "defs.h"

bool ERdrBltFlip16_cl_ad_ol(BLTFLIP_PARAMS)
{
	EINT32 xctr;
	unsigned EINT32 sc;
	unsigned short *pdd = (unsigned short *)dst;
	unsigned short *psd = (unsigned short *)src;
		unsigned char opshl = 0;
		unsigned EINT32 opand = 0;
		if (opacity == 64)      opshl = 2;
		else if (opacity == 32) opshl = 3;
		else if (opacity == 16) opshl = 4;
		if (opacity == 64)      opand = 14823;
		else if (opacity == 32) opand = 6371;
		else if (opacity == 16) opand = 2145;
		unsigned EINT32 opdbland = opand | (opand << 16);
	while (h)
	{
		for (xctr = 0; xctr < w; xctr++)
		{
			sc = *psd;
					EBCODE_MACRO_COLORIZE(sc, sc, 31, 2016, 63488, 0, 6, 11, 5, colorize, unsigned short)
						sc = EBCODE_MACRO_HPACITY_O2(sc, 0, opshl, opand);
						sc = EBCODE_MACRO_ADDALPHA(*pdd, sc, 31, 2016, 63488, 32, 2048, 65536);
				*pdd = (unsigned short)sc;
			pdd++; psd += xadd;
		}
		pdd += dstpitch / 2 - w; psd += yadd - w * xadd;
		h--;
	}
	return(true);
}

