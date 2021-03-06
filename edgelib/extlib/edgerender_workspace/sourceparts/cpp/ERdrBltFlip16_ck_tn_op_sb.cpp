#include "defs.h"

bool ERdrBltFlip16_ck_tn_op_sb(BLTFLIP_PARAMS)
{
	EINT32 xctr;
	unsigned EINT32 sc;
	unsigned short *pdd = (unsigned short *)dst;
	unsigned short *psd = (unsigned short *)src;
		opacity >>= 3;
	while (h)
	{
		for (xctr = 0; xctr < w; xctr++)
		{
			sc = *psd;
			if (sc != colorkey)
			{
					sc = EBCODE_MACRO_TINT(sc, 31727, colorize);
						sc = EBCODE_MACRO_HPACITY(sc, 0, 63519, 2016, 5, opacity);
						sc = EBCODE_MACRO_SUBALPHA(*pdd, sc, 31, 2016, 63488);
				*pdd = (unsigned short)sc;
			}
			pdd++; psd += xadd;
		}
		pdd += dstpitch / 2 - w; psd += yadd - w * xadd;
		h--;
	}
	return(true);
}

