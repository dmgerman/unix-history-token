begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1994  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)maskbits.h	8.2 (Berkeley) 3/21/94  */
end_comment

begin_comment
comment|/*  * Derived from X11R4  */
end_comment

begin_comment
comment|/* the following notes use the following conventions: SCREEN LEFT				SCREEN RIGHT in this file and maskbits.c, left and right refer to screen coordinates, NOT bit numbering in registers.  starttab[n] 	bits[0,n-1] = 0	bits[n,31] = 1 endtab[n] = 	bits[0,n-1] = 1	bits[n,31] = 0  maskbits(x, w, startmask, endmask, nlw) 	for a span of width w starting at position x, returns a mask for ragged bits at start, mask for ragged bits at end, and the number of whole longwords between the ends.  */
end_comment

begin_define
define|#
directive|define
name|maskbits
parameter_list|(
name|x
parameter_list|,
name|w
parameter_list|,
name|startmask
parameter_list|,
name|endmask
parameter_list|,
name|nlw
parameter_list|)
define|\
value|startmask = starttab[(x)&0x1f]; \     endmask = endtab[((x)+(w))& 0x1f]; \     if (startmask) \ 	nlw = (((w) - (32 - ((x)&0x1f)))>> 5); \     else \ 	nlw = (w)>> 5;
end_define

begin_define
define|#
directive|define
name|FASTGETBITS
parameter_list|(
name|psrc
parameter_list|,
name|x
parameter_list|,
name|w
parameter_list|,
name|dst
parameter_list|)
define|\
value|asm ("bfextu %3{%1:%2},%0" \     : "=d" (dst) : "di" (x), "di" (w), "o" (*(char *)(psrc)))
end_define

begin_define
define|#
directive|define
name|FASTPUTBITS
parameter_list|(
name|src
parameter_list|,
name|x
parameter_list|,
name|w
parameter_list|,
name|pdst
parameter_list|)
define|\
value|asm ("bfins %3,%0{%1:%2}" \ 	 : "=o" (*(char *)(pdst)) \ 	 : "di" (x), "di" (w), "d" (src), "0" (*(char *) (pdst)))
end_define

begin_define
define|#
directive|define
name|getandputrop
parameter_list|(
name|psrc
parameter_list|,
name|srcbit
parameter_list|,
name|dstbit
parameter_list|,
name|width
parameter_list|,
name|pdst
parameter_list|,
name|rop
parameter_list|)
define|\
value|{ \   register unsigned int _tmpsrc, _tmpdst; \   FASTGETBITS(pdst, dstbit, width, _tmpdst); \   FASTGETBITS(psrc, srcbit, width, _tmpsrc); \   DoRop(_tmpdst, rop, _tmpsrc, _tmpdst); \   FASTPUTBITS(_tmpdst, dstbit, width, pdst); \ }
end_define

begin_define
define|#
directive|define
name|getandputrop0
parameter_list|(
name|psrc
parameter_list|,
name|srcbit
parameter_list|,
name|width
parameter_list|,
name|pdst
parameter_list|,
name|rop
parameter_list|)
define|\
value|getandputrop(psrc, srcbit, 0, width, pdst, rop)
end_define

begin_define
define|#
directive|define
name|getunalignedword
parameter_list|(
name|psrc
parameter_list|,
name|x
parameter_list|,
name|dst
parameter_list|)
value|{ \         register int _tmp; \         FASTGETBITS(psrc, x, 32, _tmp); \         dst = _tmp; \ }
end_define

begin_define
define|#
directive|define
name|fnCLEAR
parameter_list|(
name|src
parameter_list|,
name|dst
parameter_list|)
value|(0)
end_define

begin_define
define|#
directive|define
name|fnCOPY
parameter_list|(
name|src
parameter_list|,
name|dst
parameter_list|)
value|(src)
end_define

begin_define
define|#
directive|define
name|fnXOR
parameter_list|(
name|src
parameter_list|,
name|dst
parameter_list|)
value|(src ^ dst)
end_define

begin_define
define|#
directive|define
name|fnCOPYINVERTED
parameter_list|(
name|src
parameter_list|,
name|dst
parameter_list|)
value|(~src)
end_define

begin_define
define|#
directive|define
name|DoRop
parameter_list|(
name|result
parameter_list|,
name|alu
parameter_list|,
name|src
parameter_list|,
name|dst
parameter_list|)
define|\
value|{ \     if (alu == RR_COPY) \         result = fnCOPY (src, dst); \     else \         switch (alu) \         { \           case RR_CLEAR: \             result = fnCLEAR (src, dst); \             break; \           case RR_XOR: \             result = fnXOR (src, dst); \             break; \           case RR_COPYINVERTED: \             result = fnCOPYINVERTED (src, dst); \             break; \         } \ }
end_define

end_unit

