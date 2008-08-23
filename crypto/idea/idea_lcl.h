begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* crypto/idea/idea_lcl.h */
end_comment

begin_comment
comment|/* Copyright (C) 1995-1998 Eric Young (eay@cryptsoft.com)  * All rights reserved.  *  * This package is an SSL implementation written  * by Eric Young (eay@cryptsoft.com).  * The implementation was written so as to conform with Netscapes SSL.  *   * This library is free for commercial and non-commercial use as long as  * the following conditions are aheared to.  The following conditions  * apply to all code found in this distribution, be it the RC4, RSA,  * lhash, DES, etc., code; not just the SSL code.  The SSL documentation  * included with this distribution is covered by the same copyright terms  * except that the holder is Tim Hudson (tjh@cryptsoft.com).  *   * Copyright remains Eric Young's, and as such any Copyright notices in  * the code are not to be removed.  * If this package is used in a product, Eric Young should be given attribution  * as the author of the parts of the library used.  * This can be in the form of a textual message at program startup or  * in documentation (online or textual) provided with the package.  *   * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *    "This product includes cryptographic software written by  *     Eric Young (eay@cryptsoft.com)"  *    The word 'cryptographic' can be left out if the rouines from the library  *    being used are not cryptographic related :-).  * 4. If you include any Windows specific code (or a derivative thereof) from   *    the apps directory (application code) you must include an acknowledgement:  *    "This product includes software written by Tim Hudson (tjh@cryptsoft.com)"  *   * THIS SOFTWARE IS PROVIDED BY ERIC YOUNG ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *   * The licence and distribution terms for any publically available version or  * derivative of this code cannot be changed.  i.e. this code cannot simply be  * copied and put under another distribution licence  * [including the GNU Public Licence.]  */
end_comment

begin_comment
comment|/* The new form of this macro (check if the a*b == 0) was suggested by   * Colin Plumb<colin@nyx10.cs.du.edu> */
end_comment

begin_comment
comment|/* Removal of the inner if from from Wei Dai 24/4/96 */
end_comment

begin_define
define|#
directive|define
name|idea_mul
parameter_list|(
name|r
parameter_list|,
name|a
parameter_list|,
name|b
parameter_list|,
name|ul
parameter_list|)
define|\
value|ul=(unsigned long)a*b; \ if (ul != 0) \ 	{ \ 	r=(ul&0xffff)-(ul>>16); \ 	r-=((r)>>16); \ 	} \ else \ 	r=(-(int)a-b+1);
end_define

begin_comment
comment|/* assuming a or b is 0 and in range */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|undef
end_ifdef

begin_define
define|#
directive|define
name|idea_mul
parameter_list|(
name|r
parameter_list|,
name|a
parameter_list|,
name|b
parameter_list|,
name|ul
parameter_list|,
name|sl
parameter_list|)
define|\
value|if (a == 0) r=(0x10001-b)&0xffff; \ else if (b == 0) r=(0x10001-a)&0xffff; \ else	{ \ 	ul=(unsigned long)a*b; \ 	sl=(ul&0xffff)-(ul>>16); \ 	if (sl<= 0) sl+=0x10001; \ 	r=sl; \ 	}
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  7/12/95 - Many thanks to Rhys Weatherley<rweather@us.oracle.com>  * for pointing out that I was assuming little endian  * byte order for all quantities what idea  * actually used bigendian.  No where in the spec does it mention  * this, it is all in terms of 16 bit numbers and even the example  * does not use byte streams for the input example :-(.  * If you byte swap each pair of input, keys and iv, the functions  * would produce the output as the old version :-(.  */
end_comment

begin_comment
comment|/* NOTE - c is not incremented as per n2l */
end_comment

begin_define
define|#
directive|define
name|n2ln
parameter_list|(
name|c
parameter_list|,
name|l1
parameter_list|,
name|l2
parameter_list|,
name|n
parameter_list|)
value|{ \ 			c+=n; \ 			l1=l2=0; \ 			switch (n) { \ 			case 8: l2 =((unsigned long)(*(--(c))))    ; \ 			case 7: l2|=((unsigned long)(*(--(c))))<< 8; \ 			case 6: l2|=((unsigned long)(*(--(c))))<<16; \ 			case 5: l2|=((unsigned long)(*(--(c))))<<24; \ 			case 4: l1 =((unsigned long)(*(--(c))))    ; \ 			case 3: l1|=((unsigned long)(*(--(c))))<< 8; \ 			case 2: l1|=((unsigned long)(*(--(c))))<<16; \ 			case 1: l1|=((unsigned long)(*(--(c))))<<24; \ 				} \ 			}
end_define

begin_comment
comment|/* NOTE - c is not incremented as per l2n */
end_comment

begin_define
define|#
directive|define
name|l2nn
parameter_list|(
name|l1
parameter_list|,
name|l2
parameter_list|,
name|c
parameter_list|,
name|n
parameter_list|)
value|{ \ 			c+=n; \ 			switch (n) { \ 			case 8: *(--(c))=(unsigned char)(((l2)    )&0xff); \ 			case 7: *(--(c))=(unsigned char)(((l2)>> 8)&0xff); \ 			case 6: *(--(c))=(unsigned char)(((l2)>>16)&0xff); \ 			case 5: *(--(c))=(unsigned char)(((l2)>>24)&0xff); \ 			case 4: *(--(c))=(unsigned char)(((l1)    )&0xff); \ 			case 3: *(--(c))=(unsigned char)(((l1)>> 8)&0xff); \ 			case 2: *(--(c))=(unsigned char)(((l1)>>16)&0xff); \ 			case 1: *(--(c))=(unsigned char)(((l1)>>24)&0xff); \ 				} \ 			}
end_define

begin_undef
undef|#
directive|undef
name|n2l
end_undef

begin_define
define|#
directive|define
name|n2l
parameter_list|(
name|c
parameter_list|,
name|l
parameter_list|)
value|(l =((unsigned long)(*((c)++)))<<24L, \                          l|=((unsigned long)(*((c)++)))<<16L, \                          l|=((unsigned long)(*((c)++)))<< 8L, \                          l|=((unsigned long)(*((c)++))))
end_define

begin_undef
undef|#
directive|undef
name|l2n
end_undef

begin_define
define|#
directive|define
name|l2n
parameter_list|(
name|l
parameter_list|,
name|c
parameter_list|)
value|(*((c)++)=(unsigned char)(((l)>>24L)&0xff), \                          *((c)++)=(unsigned char)(((l)>>16L)&0xff), \                          *((c)++)=(unsigned char)(((l)>> 8L)&0xff), \                          *((c)++)=(unsigned char)(((l)     )&0xff))
end_define

begin_undef
undef|#
directive|undef
name|s2n
end_undef

begin_define
define|#
directive|define
name|s2n
parameter_list|(
name|l
parameter_list|,
name|c
parameter_list|)
value|(*((c)++)=(unsigned char)(((l)     )&0xff), \ 			 *((c)++)=(unsigned char)(((l)>> 8L)&0xff))
end_define

begin_undef
undef|#
directive|undef
name|n2s
end_undef

begin_define
define|#
directive|define
name|n2s
parameter_list|(
name|c
parameter_list|,
name|l
parameter_list|)
value|(l =((IDEA_INT)(*((c)++)))<< 8L, \ 			 l|=((IDEA_INT)(*((c)++)))      )
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|undef
end_ifdef

begin_comment
comment|/* NOTE - c is not incremented as per c2l */
end_comment

begin_define
define|#
directive|define
name|c2ln
parameter_list|(
name|c
parameter_list|,
name|l1
parameter_list|,
name|l2
parameter_list|,
name|n
parameter_list|)
value|{ \ 			c+=n; \ 			l1=l2=0; \ 			switch (n) { \ 			case 8: l2 =((unsigned long)(*(--(c))))<<24; \ 			case 7: l2|=((unsigned long)(*(--(c))))<<16; \ 			case 6: l2|=((unsigned long)(*(--(c))))<< 8; \ 			case 5: l2|=((unsigned long)(*(--(c))));     \ 			case 4: l1 =((unsigned long)(*(--(c))))<<24; \ 			case 3: l1|=((unsigned long)(*(--(c))))<<16; \ 			case 2: l1|=((unsigned long)(*(--(c))))<< 8; \ 			case 1: l1|=((unsigned long)(*(--(c))));     \ 				} \ 			}
end_define

begin_comment
comment|/* NOTE - c is not incremented as per l2c */
end_comment

begin_define
define|#
directive|define
name|l2cn
parameter_list|(
name|l1
parameter_list|,
name|l2
parameter_list|,
name|c
parameter_list|,
name|n
parameter_list|)
value|{ \ 			c+=n; \ 			switch (n) { \ 			case 8: *(--(c))=(unsigned char)(((l2)>>24)&0xff); \ 			case 7: *(--(c))=(unsigned char)(((l2)>>16)&0xff); \ 			case 6: *(--(c))=(unsigned char)(((l2)>> 8)&0xff); \ 			case 5: *(--(c))=(unsigned char)(((l2)    )&0xff); \ 			case 4: *(--(c))=(unsigned char)(((l1)>>24)&0xff); \ 			case 3: *(--(c))=(unsigned char)(((l1)>>16)&0xff); \ 			case 2: *(--(c))=(unsigned char)(((l1)>> 8)&0xff); \ 			case 1: *(--(c))=(unsigned char)(((l1)    )&0xff); \ 				} \ 			}
end_define

begin_undef
undef|#
directive|undef
name|c2s
end_undef

begin_define
define|#
directive|define
name|c2s
parameter_list|(
name|c
parameter_list|,
name|l
parameter_list|)
value|(l =((unsigned long)(*((c)++)))    , \ 			 l|=((unsigned long)(*((c)++)))<< 8L)
end_define

begin_undef
undef|#
directive|undef
name|s2c
end_undef

begin_define
define|#
directive|define
name|s2c
parameter_list|(
name|l
parameter_list|,
name|c
parameter_list|)
value|(*((c)++)=(unsigned char)(((l)     )&0xff), \ 			 *((c)++)=(unsigned char)(((l)>> 8L)&0xff))
end_define

begin_undef
undef|#
directive|undef
name|c2l
end_undef

begin_define
define|#
directive|define
name|c2l
parameter_list|(
name|c
parameter_list|,
name|l
parameter_list|)
value|(l =((unsigned long)(*((c)++)))     , \ 			 l|=((unsigned long)(*((c)++)))<< 8L, \ 			 l|=((unsigned long)(*((c)++)))<<16L, \ 			 l|=((unsigned long)(*((c)++)))<<24L)
end_define

begin_undef
undef|#
directive|undef
name|l2c
end_undef

begin_define
define|#
directive|define
name|l2c
parameter_list|(
name|l
parameter_list|,
name|c
parameter_list|)
value|(*((c)++)=(unsigned char)(((l)     )&0xff), \ 			 *((c)++)=(unsigned char)(((l)>> 8L)&0xff), \ 			 *((c)++)=(unsigned char)(((l)>>16L)&0xff), \ 			 *((c)++)=(unsigned char)(((l)>>24L)&0xff))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|E_IDEA
parameter_list|(
name|num
parameter_list|)
define|\
value|x1&=0xffff; \ 	idea_mul(x1,x1,*p,ul); p++; \ 	x2+= *(p++); \ 	x3+= *(p++); \ 	x4&=0xffff; \ 	idea_mul(x4,x4,*p,ul); p++; \ 	t0=(x1^x3)&0xffff; \ 	idea_mul(t0,t0,*p,ul); p++; \ 	t1=(t0+(x2^x4))&0xffff; \ 	idea_mul(t1,t1,*p,ul); p++; \ 	t0+=t1; \ 	x1^=t1; \ 	x4^=t0; \ 	ul=x2^t0;
comment|/* do the swap to x3 */
value|\ 	x2=x3^t1; \ 	x3=ul;
end_define

end_unit

