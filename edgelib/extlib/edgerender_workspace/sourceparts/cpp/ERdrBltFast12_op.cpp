#include "defs.h"

bool ERdrBltFast12_op(BLTFAST_PARAMS)
{
	EINT32 xctr;
	unsigned short *pdd = (unsigned short *)dst;
	unsigned short *psd = (unsigned short *)src;
	unsigned EINT32 *pdd32, *psd32;
	if ((EINTPTR)(pdd) & 2)
		pdd32 = (unsigned EINT32 *)&pdd[1];
	else
		pdd32 = (unsigned EINT32 *)pdd;
	if ((EINTPTR)(psd) & 2)
		psd32 = (unsigned EINT32 *)&psd[1];
	else
		psd32 = (unsigned EINT32 *)psd;
	EINT32 yctr;
	unsigned EINT32 sc;
	unsigned short *orgpdd, *orgpsd;
		opacity >>= 4;
	if (w)
	{
		if ((EINTPTR)(psd) & 2)
		{
			orgpdd = pdd, orgpsd = psd;
			for (yctr = 0; yctr < h; yctr++)
			{
				sc = *psd;
						sc = EBCODE_MACRO_OPACITY(*pdd, sc, 3855, 240, 4, (16 - opacity), opacity);
					*pdd = (unsigned short)sc;
				pdd += dstpitch / 2; psd += srcpitch / 2;
			}
			pdd = orgpdd + 1; psd = orgpsd + 1; w--;
		}
		if (((EINTPTR)(psd) + w * 2) & 2)
		{
			orgpdd = pdd, orgpsd = psd;
			pdd += w - 1; psd += w - 1;
			for (yctr = 0; yctr < h; yctr++)
			{
				sc = *psd;
						sc = EBCODE_MACRO_OPACITY(*pdd, sc, 3855, 240, 4, (16 - opacity), opacity);
					*pdd = (unsigned short)sc;
				pdd += dstpitch / 2; psd += srcpitch / 2;
			}
			pdd = orgpdd; psd = orgpsd; w--;
		}
		w /= 2;
	}
	colorize |= (colorize << 16);
	if ((EINTPTR)(pdd) & 2)
	{
		while (h)
		{
			for (xctr = 0; xctr < w; xctr++)
			{
				sc = *psd32;
						sc = EBCODE_MACRO_OPACITY_DBL(((pdd[1] << 16) + pdd[0]), sc, 0x0F0F00F0, 0x00F00F0F, 4, (16 - opacity), opacity);
						*pdd++ = (unsigned short)sc;
						*pdd++ = (unsigned short)(sc >> 16);
				psd32++;
			}
			pdd += dstpitch / 2 - w * 2; psd32 += srcpitch / 4 - w;
			h--;
		}
	}
	else
	{
		while (h)
		{
			for (xctr = 0; xctr < w; xctr++)
			{
				sc = *psd32;
						sc = EBCODE_MACRO_OPACITY_DBL(*pdd32, sc, 0x0F0F00F0, 0x00F00F0F, 4, (16 - opacity), opacity);
						*pdd32 = sc;
				pdd32++; psd32++;
			}
			pdd32 += dstpitch / 4 - w; psd32 += srcpitch / 4 - w;
			h--;
		}
	}
	return(true);
}

